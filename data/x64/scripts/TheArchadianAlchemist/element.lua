-- Made By FehDead
local element = {}

local mem
local equipment
local elementNames
local constants

function element.get(base, addrs)
    local equipmentId = mem.readU16(base, addrs.selected.selectedEquipmentId)
    if equipmentId <= 0 then
        return 0
    end

    local eq = equipment.get(equipmentId)
    if not eq or not eq.elements then
        return 0
    end

    for id = 1, 8 do
        local name = elementNames[id]
        if name and eq.elements[name] == 1 then
            return id
        end
    end

    return 0
end

function element.write(base, addrs, elementId)
    mem.flags.set(base, addrs.current.currentElement, elementId or 0)
end

local function clearElements(eq)
    for id = 1, 8 do
        equipment.applyElement(eq, id, 0)
    end
end

function element.set(base, addrs, elementId)
    if elementId < 1 or elementId > 8 then
        return false
    end

    local equipmentId = mem.readU16(base, addrs.selected.selectedEquipmentId)
    if equipmentId <= 0 then
        return false
    end

    local eq = equipment.get(equipmentId)
    if not eq then
        return false
    end

    clearElements(eq)
    equipment.applyElement(eq, elementId, 1)
    equipment.update(equipmentId, "element", {
        id = elementId
    })

    return true
end

function element.remove(base, addrs)
    local equipmentId = mem.readU16(base, addrs.selected.selectedEquipmentId)
    if equipmentId <= 0 then
        return false
    end

    local eq = equipment.get(equipmentId)
    if not eq then
        return false
    end

    clearElements(eq)
    equipment.update(equipmentId, "element", nil)

    return true
end

function element.apply(base, addrs)
    if mem.flags.get(base, addrs.flow.confirmedIntention) ~= 1 then
        return false
    end

    local subcategory = mem.flags.get(base, addrs.selected.selectedSubcategory)
    if subcategory == constants.removeId then
        element.remove(base, addrs)
    else
        element.set(base, addrs, subcategory)
    end

    mem.flags.set(base, addrs.flow.confirmedIntention, 0)
    return true
end

function element.clearAll(equipmentId)
    if equipmentId <= 0 then
        return
    end

    for id = 1, 8 do
        equipment.write(equipmentId, "element", id, 0)
    end
end

function element.initialize(deps)
    mem = deps.memory
    equipment = deps.equipment
    elementNames = deps.mappings.element
    constants = deps.mappings.constants
    return true
end

return element
