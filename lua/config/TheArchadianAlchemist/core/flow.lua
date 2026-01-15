-- Made By FehDead
-- =====================
-- FLOW MODULE
-- =====================
-- State machine for flow control
local flow = {}

-- =====================
-- DEPENDÊNCIAS
-- =====================
local mem
local mappings

-- =====================
-- FLAG DE INICIALIZAÇÃO
-- =====================
local isInitialized = false

-- =====================
-- CACHED REFERENCES
-- =====================
local addresses
local flowEvents
local flowIntervals

-- =====================
-- STATE
-- =====================
flow.lastPollMode = -1

-- =====================
-- INTERVAL RESOLUTION
-- =====================

-- @description: resolve polling interval based on pollMode flag
-- @params: base (memory base), addrs (addresses table)
-- @returns: milliseconds
function flow.interval(base, addrs)
    local mode = mem.flags.get(base, addrs.flow.pollMode)

    if mode == 2 then
        return flowIntervals.sync
    elseif mode == 1 then
        return flowIntervals.talk
    end

    return flowIntervals.idle
end

-- =====================
-- POLLING
-- =====================

-- @description: poll flow flags and decide current logical event
-- @params: base (memory base), addrs (addresses table)
-- @returns: event string or nil
function flow.poll(base, addrs)
    -- Check reset flag
    if mem.flags.get(base, addrs.flow.reset) == 1 then
        mem.flags.clear(base, addrs.flow.reset)
        mem.flags.set(base, addrs.flow.pollMode, 2)
        return flowEvents.reset
    end

    -- Check success flag
    if mem.flags.get(base, addrs.flow.success) ~= 0 then
        mem.flags.set(base, addrs.flow.pollMode, 1)
        return flowEvents.result
    end

    -- Check load equipment flag
    if mem.flags.get(base, addrs.flow.loadEquipment) == 1 then
        mem.flags.set(base, addrs.flow.pollMode, 2)
        return flowEvents.loadEquipment
    end

    -- Check selected flag
    if mem.flags.get(base, addrs.flow.selected) == 1 then
        mem.flags.set(base, addrs.flow.pollMode, 2)
        return flowEvents.equipmentSelected
    end

    -- Check element flag
    if mem.flags.get(base, addrs.flow.checkElement) == 1 then
        mem.flags.set(base, addrs.flow.pollMode, 2)
        return flowEvents.checkElement
    end

    -- Check attribute flag
    if mem.flags.get(base, addrs.flow.checkAttribute) == 1 then
        mem.flags.set(base, addrs.flow.pollMode, 2)
        return flowEvents.checkAttribute
    end

    -- Check status
    local status = mem.flags.get(base, addrs.flow.status)

    if status == 1 then
        mem.flags.set(base, addrs.flow.pollMode, 1)
        return flowEvents.talk
    elseif status == 2 then
        mem.flags.set(base, addrs.flow.pollMode, 2)
        return flowEvents.element
    elseif status == 3 then
        mem.flags.set(base, addrs.flow.pollMode, 2)
        return flowEvents.attribute
    end

    -- Idle state
    mem.flags.set(base, addrs.flow.pollMode, 0)
    return nil
end

-- =====================
-- FLOW STATE MANAGEMENT
-- =====================

-- @description: initialize/reset flow state
-- @params: base (memory base), addrs (addresses table)
function flow.load(base, addrs)
    -- Clear flow flags
    mem.flags.clear(base, addrs.flow.status)
    mem.flags.clear(base, addrs.flow.selected)
    mem.flags.clear(base, addrs.flow.success)
    mem.flags.clear(base, addrs.flow.reset)
    mem.flags.clear(base, addrs.flow.loadEquipment)
    mem.flags.clear(base, addrs.flow.checkElement)
    mem.flags.clear(base, addrs.flow.checkAttribute)

    -- Clear selection
    mem.flags.clear(base, addrs.selected.category)
    mem.flags.clear(base, addrs.selected.subcategory)
    mem.flags.clear(base, addrs.selected.tier)
    mem.writeU16(base, addrs.selected.equipmentId, 0)

    -- Reset poll mode
    mem.flags.set(base, addrs.flow.pollMode, 0)
end

-- @description: reset flow state (alias for load)
-- @params: base (memory base), addrs (addresses table)
function flow.reset(base, addrs)
    flow.load(base, addrs)
end

-- =====================
-- INICIALIZAÇÃO
-- =====================

function flow.initialize(deps)
    if not deps then
        print("ERROR [TAA FLOW] Dependencies not provided")
        return false
    end

    if not deps.memory then
        print("ERROR [TAA FLOW] Memory not provided")
        return false
    end

    if not deps.mappings then
        print("ERROR [TAA FLOW] Mappings not provided")
        return false
    end

    mem = deps.memory
    mappings = deps.mappings

    -- Cache frequently used references
    addresses = mappings.addresses
    flowEvents = mappings.flowEvents
    flowIntervals = mappings.flowIntervals

    isInitialized = true
    print("[TAA FLOW] Module initialized")
    return true
end

-- =====================
-- DEBUG HELPERS
-- =====================

function flow.isReady()
    return isInitialized
end

function flow.getStatus()
    return {
        initialized = isInitialized,
        hasMemory = mem ~= nil,
        hasMappings = mappings ~= nil,
        lastPollMode = flow.lastPollMode
    }
end

return flow
