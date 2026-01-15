-- Made By FehDead
-- =====================
-- CONTROLLER MODULE
-- =====================
-- Main controller for TheArchadianAlchemist
local controller = {}

-- =====================
-- DEPENDÊNCIAS
-- =====================
local mem
local flow
local loader
local element
local attribute
local unlock
local mappings

-- Injected from orchestrator
local symbols
local configData

-- =====================
-- FLAG DE INICIALIZAÇÃO
-- =====================
local isInitialized = false

-- =====================
-- CACHED REFERENCES
-- =====================
local addresses
local flowEvents
local constants

-- =====================
-- STATE
-- =====================
controller.targetLocation = nil
controller.locationId = -1
controller.valid = false
controller.running = false
controller.pollId = 0

-- =====================
-- LIFECYCLE
-- =====================

-- @description: start controller execution
function controller.start()
    if controller.running then
        return
    end

    controller.running = true
    controller.pollId = controller.pollId + 1
    local currentPoll = controller.pollId

    flow.load(addresses.base, addresses)

    -- Sync quest status to memory on map enter
    unlock.syncToMemory(addresses.base, addresses)

    controller.schedule(currentPoll)
end

-- @description: stop controller execution
function controller.stop()
    if not controller.running then
        return
    end

    controller.running = false
    controller.pollId = controller.pollId + 1

    flow.load(addresses.base, addresses)
end

-- =====================
-- POLLING
-- =====================

-- @description: schedule next poll based on flow interval
-- @params: pollId (current poll identifier)
function controller.schedule(pollId)
    if pollId ~= controller.pollId then
        return
    end

    local interval = flow.interval(addresses.base, addresses)

    event.executeAfterMs(interval, function()
        controller.poll(pollId)
    end)
end

-- @description: single poll execution
-- @params: pollId (current poll identifier)
function controller.poll(pollId)
    if pollId ~= controller.pollId then
        return
    end

    if not controller.running or not controller.valid then
        return
    end

    -- Process unlocks (all in one function now)
    if configData and configData.questline then
        unlock.update(addresses.base, addresses, configData.questline, symbols)
    end

    -- Process flow events
    local flowEvent = flow.poll(addresses.base, addresses)
    if flowEvent then
        controller.dispatch(flowEvent, addresses.base, addresses, configData)
    end

    -- Schedule next poll
    controller.schedule(pollId)
end

-- =====================
-- EVENT DISPATCH
-- =====================

-- @description: dispatch actions based on flow event
-- @params: flowEvent, base, addrs, config
function controller.dispatch(flowEvent, base, addrs, config)
    if flowEvent == flowEvents.reset then
        controller.reset(base, addrs)
        return
    end

    if flowEvent == flowEvents.loadEquipment then
        loader.dispatch(base, addrs, config)
        mem.flags.clear(base, addrs.flow.loadEquipment)
        mem.flags.set(base, addrs.flow.pollMode, 1)
        return
    end

    if flowEvent == flowEvents.equipmentSelected then
        mem.flags.clear(base, addrs.flow.selected)
        return
    end

    if flowEvent == flowEvents.checkElement then
        local current = element.get(base, addrs)
        element.write(base, addrs, current)
        mem.flags.clear(base, addrs.flow.checkElement)
        return
    end

    if flowEvent == flowEvents.checkAttribute then
        local refinement = attribute.get(base, addrs)
        loader.results(base, addrs.obtained, refinement)
        mem.flags.clear(base, addrs.flow.checkAttribute)
        return
    end

    if flowEvent == flowEvents.result then
        local flowStatus = mem.flags.get(base, addrs.flow.status)

        if flowStatus == 2 then
            element.apply(base, addrs)
        elseif flowStatus == 3 then
            attribute.apply(base, addrs, config, loader)
        end

        -- Trigger DD refresh
        if symbols and symbols.triggerRefresh then
            symbols.triggerRefresh(mappings.symbols.dd)
        end

        return
    end
end

-- =====================
-- RESET
-- =====================

-- @description: reset flow and internal state
-- @params: base, addrs
function controller.reset(base, addrs)
    flow.load(base, addrs)
end

-- =====================
-- LOCATION HANDLING
-- =====================

-- @description: handle location change and enable/disable the mod
-- @params: locationId
function controller.location(locationId)
    controller.locationId = locationId

    if controller.validateLocation(locationId) then
        print("[TAA] Location valid:", locationId)
        controller.valid = true
        controller.start()
    else
        print("[TAA] Location invalid:", locationId)
        controller.valid = false
        controller.stop()
    end
end

-- @description: validate location id
-- @returns: boolean
function controller.validateLocation(locationId)
    return locationId == controller.targetLocation
end

-- =====================
-- DEPENDENCY INJECTION
-- =====================

-- @description: set symbols module (called from orchestrator)
-- @params: symbolsModule
function controller.setSymbols(symbolsModule)
    symbols = symbolsModule
end

-- @description: set config data (called from orchestrator)
-- @params: config
function controller.setConfig(config)
    configData = config
end

-- =====================
-- INICIALIZAÇÃO
-- =====================

function controller.initialize(deps)
    if not deps then
        print("ERROR [TAA CONTROLLER] Dependencies not provided")
        return false
    end

    if not deps.memory then
        print("ERROR [TAA CONTROLLER] Memory not provided")
        return false
    end

    if not deps.flow then
        print("ERROR [TAA CONTROLLER] Flow not provided")
        return false
    end

    if not deps.loader then
        print("ERROR [TAA CONTROLLER] Loader not provided")
        return false
    end

    if not deps.element then
        print("ERROR [TAA CONTROLLER] Element not provided")
        return false
    end

    if not deps.attribute then
        print("ERROR [TAA CONTROLLER] Attribute not provided")
        return false
    end

    if not deps.unlock then
        print("ERROR [TAA CONTROLLER] Unlock not provided")
        return false
    end

    if not deps.mappings then
        print("ERROR [TAA CONTROLLER] Mappings not provided")
        return false
    end

    mem = deps.memory
    flow = deps.flow
    loader = deps.loader
    element = deps.element
    attribute = deps.attribute
    unlock = deps.unlock
    mappings = deps.mappings

    -- Cache frequently used references
    addresses = mappings.addresses
    flowEvents = mappings.flowEvents
    constants = mappings.constants

    -- Set target location
    controller.targetLocation = constants.targetLocation

    isInitialized = true
    print("[TAA CONTROLLER] Module initialized")
    return true
end

-- =====================
-- DEBUG HELPERS
-- =====================

function controller.isReady()
    return isInitialized
end

function controller.getStatus()
    return {
        initialized = isInitialized,
        hasMemory = mem ~= nil,
        hasFlow = flow ~= nil,
        hasLoader = loader ~= nil,
        hasElement = element ~= nil,
        hasAttribute = attribute ~= nil,
        hasUnlock = unlock ~= nil,
        hasMappings = mappings ~= nil,
        hasSymbols = symbols ~= nil,
        hasConfigData = configData ~= nil,
        targetLocation = controller.targetLocation,
        locationId = controller.locationId,
        valid = controller.valid,
        running = controller.running,
        pollId = controller.pollId
    }
end

return controller
