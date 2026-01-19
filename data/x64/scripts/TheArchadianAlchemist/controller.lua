-- Made By FehDead
local controller = {}

local mem
local flow
local loader
local element
local attribute
local unlock
local mappings
local symbols
local configData
local addresses
local flowEvents
local constants

controller.targetLocation = nil
controller.locationId = -1
controller.valid = false
controller.running = false
controller.pollId = 0

function controller.start()
    if controller.running then
        return
    end

    controller.running = true
    controller.pollId = controller.pollId + 1
    local currentPoll = controller.pollId

    flow.load(addresses.base, addresses)
    unlock.syncToMemory(addresses.base, addresses)
    controller.schedule(currentPoll)
end

function controller.stop()
    if not controller.running then
        return
    end

    controller.running = false
    controller.pollId = controller.pollId + 1

    flow.load(addresses.base, addresses)
end

function controller.schedule(pollId)
    if pollId ~= controller.pollId then
        return
    end

    local interval = flow.interval(addresses.base, addresses)

    event.executeAfterMs(interval, function()
        controller.poll(pollId)
    end)
end

function controller.poll(pollId)
    if pollId ~= controller.pollId then
        return
    end

    if not controller.running or not controller.valid then
        return
    end

    if configData and configData.questline then
        unlock.update(addresses.base, addresses, configData.questline, symbols)
    end

    local flowEvent = flow.poll(addresses.base, addresses)
    if flowEvent then
        controller.dispatch(flowEvent, addresses.base, addresses, configData)
    end

    controller.schedule(pollId)
end

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
        mem.flags.clear(base, addrs.flow.selectedIntention)
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
        loader.results(base, addrs, refinement)
        mem.flags.clear(base, addrs.flow.checkAttribute)
        return
    end

    if flowEvent == flowEvents.result then
        local flowStatus = mem.flags.get(base, addrs.flow.talkStatus)

        if flowStatus == 2 then
            element.apply(base, addrs)
        elseif flowStatus == 3 then
            attribute.apply(base, addrs, config, loader)
        end

        if symbols then
            symbols.triggerRefresh()
        end

        return
    end
end

function controller.reset(base, addrs)
    flow.load(base, addrs)
end

function controller.location(locationId)
    controller.locationId = locationId

    if controller.validateLocation(locationId) then
        controller.valid = true
        controller.start()
    else
        controller.valid = false
        controller.stop()
    end
end

function controller.validateLocation(locationId)
    return locationId == controller.targetLocation
end

function controller.setSymbols(symbolsModule)
    symbols = symbolsModule
end

function controller.setConfig(config)
    configData = config
end

function controller.initialize(deps)
    mem = deps.memory
    flow = deps.flow
    loader = deps.loader
    element = deps.element
    attribute = deps.attribute
    unlock = deps.unlock
    mappings = deps.mappings
    addresses = mappings.addresses
    flowEvents = mappings.flowEvents
    constants = mappings.constants
    controller.targetLocation = constants.targetLocation

    return true
end

return controller
