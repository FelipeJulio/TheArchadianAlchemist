-- Made By FehDead
local flow = {}

local mem
local mappings
local addresses
local flowEvents
local flowIntervals

flow.lastPollMode = -1

function flow.interval(base, addrs)
    local mode = mem.flags.get(base, addrs.flow.pollMode)

    if mode == 2 then
        return flowIntervals.sync
    elseif mode == 1 then
        return flowIntervals.talk
    end

    return flowIntervals.idle
end

function flow.poll(base, addrs)

    if mem.flags.get(base, addrs.flow.reset) == 1 then
        mem.flags.clear(base, addrs.flow.reset)
        mem.flags.set(base, addrs.flow.pollMode, 2)
        return flowEvents.reset
    end

    if mem.flags.get(base, addrs.flow.success) ~= 0 then
        mem.flags.set(base, addrs.flow.pollMode, 1)
        return flowEvents.result
    end

    if mem.flags.get(base, addrs.flow.loadEquipment) == 1 then
        mem.flags.set(base, addrs.flow.pollMode, 2)
        return flowEvents.loadEquipment
    end

    if mem.flags.get(base, addrs.flow.selected) == 1 then
        mem.flags.set(base, addrs.flow.pollMode, 2)
        return flowEvents.equipmentSelected
    end

    if mem.flags.get(base, addrs.flow.checkElement) == 1 then
        mem.flags.set(base, addrs.flow.pollMode, 2)
        return flowEvents.checkElement
    end

    if mem.flags.get(base, addrs.flow.checkAttribute) == 1 then
        mem.flags.set(base, addrs.flow.pollMode, 2)
        return flowEvents.checkAttribute
    end

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

    mem.flags.set(base, addrs.flow.pollMode, 0)
    return nil
end

function flow.load(base, addrs)
    mem.flags.clear(base, addrs.flow.status)
    mem.flags.clear(base, addrs.flow.selected)
    mem.flags.clear(base, addrs.flow.success)
    mem.flags.clear(base, addrs.flow.reset)
    mem.flags.clear(base, addrs.flow.loadEquipment)
    mem.flags.clear(base, addrs.flow.checkElement)
    mem.flags.clear(base, addrs.flow.checkAttribute)
    mem.flags.clear(base, addrs.selected.category)
    mem.flags.clear(base, addrs.selected.subcategory)
    mem.flags.clear(base, addrs.selected.tier)
    mem.writeU16(base, addrs.selected.equipmentId, 0)
    mem.flags.set(base, addrs.flow.pollMode, 0)
end

function flow.reset(base, addrs)
    flow.load(base, addrs)
end

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
    addresses = mappings.addresses
    flowEvents = mappings.flowEvents
    flowIntervals = mappings.flowIntervals

    return true
end

return flow
