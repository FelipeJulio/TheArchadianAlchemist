-- Made By FehDead
local flow = {}

local mem
local flowEvents
local flowIntervals

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

    if mem.flags.get(base, addrs.flow.resetFlow) == 1 then
        mem.flags.clear(base, addrs.flow.resetFlow)
        mem.flags.set(base, addrs.flow.pollMode, 2)
        return flowEvents.reset
    end

    if mem.flags.get(base, addrs.flow.confirmedIntention) ~= 0 then
        mem.flags.set(base, addrs.flow.pollMode, 1)
        return flowEvents.result
    end

    if mem.flags.get(base, addrs.flow.loadEquipment) == 1 then
        mem.flags.set(base, addrs.flow.pollMode, 2)
        return flowEvents.loadEquipment
    end

    if mem.flags.get(base, addrs.flow.selectedIntention) == 1 then
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

    local status = mem.flags.get(base, addrs.flow.talkStatus)

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
    mem.flags.clear(base, addrs.flow.talkStatus)
    mem.flags.clear(base, addrs.flow.selectedIntention)
    mem.flags.clear(base, addrs.flow.confirmedIntention)
    mem.flags.clear(base, addrs.flow.resetFlow)
    mem.flags.clear(base, addrs.flow.loadEquipment)
    mem.flags.clear(base, addrs.flow.checkElement)
    mem.flags.clear(base, addrs.flow.checkAttribute)
    mem.flags.clear(base, addrs.selected.selectedCategory)
    mem.flags.clear(base, addrs.selected.selectedSubcategory)
    mem.flags.clear(base, addrs.selected.selectedTier)
    mem.writeU16(base, addrs.selected.selectedEquipmentId, 0)
    mem.flags.set(base, addrs.flow.pollMode, 0)
end

function flow.initialize(deps)
    mem = deps.memory
    flowEvents = deps.mappings.flowEvents
    flowIntervals = deps.mappings.flowIntervals
    return true
end

return flow
