-- Made By FehDead
local equipment = {}

local mem
local elementNames
local attributeDefs
local constants

equipment.state = {}

function equipment.get(id)
    if not equipment.validateId(id) then
        return nil
    end

    local idx = id - constants.equipmentBaseId
    return bpack.section13[idx]
end

function equipment.validateId(id)
    return id and id > 0
end

function equipment._readElement(eq, elementId)
    if elementId < 1 or elementId > 8 then
        return nil
    end

    local name = elementNames[elementId]
    if not name then
        return nil
    end

    return (eq and eq.elements and eq.elements[name]) or 0
end

function equipment._readAttribute(eq, attributeId)
    if attributeId < 10 or attributeId > 26 then
        return nil
    end

    local attr = attributeDefs[attributeId]
    if not attr then
        return nil
    end

    local name, typ, offset = attr[1], attr[2], attr[3]

    if typ == "direct" then
        return eq[name] or 0
    elseif typ == "linked" and eq.attributePointer then
        local addr = eq.attributePointer + offset
        if name == "maxHp" or name == "maxMp" then
            return mem.readU16(addr, nil)
        else
            return mem.readU8(addr, nil)
        end
    end

    return nil
end

function equipment.read(id, key, subid)
    local eq = equipment.get(id)
    if not eq then
        return nil
    end

    if key == "element" then
        return equipment._readElement(eq, subid)
    end
    if key == "attribute" then
        return equipment._readAttribute(eq, subid)
    end

    return nil
end

function equipment.applyElement(eq, elementId, value)
    local name = elementNames[elementId]
    if not name then
        return false
    end

    eq.elements = eq.elements or {}
    eq.elements[name] = value
    return true
end

function equipment.applyAttribute(eq, attributeId, value)
    local attr = attributeDefs[attributeId]
    if not attr then
        return false
    end

    local name, typ, offset = attr[1], attr[2], attr[3]

    if typ == "direct" then
        eq[name] = value
    elseif typ == "linked" and eq.attributePointer then
        local addr = eq.attributePointer + offset
        if name == "maxHp" or name == "maxMp" then
            mem.writeU16(addr, nil, value)
        else
            mem.writeU8(addr, nil, value)
        end
    end

    return true
end

function equipment.write(id, key, subid, value)
    local eq = equipment.get(id)
    if not eq then
        return false
    end

    if key == "element" then
        if subid < 1 or subid > 8 then
            return false
        end
        return equipment.applyElement(eq, subid, value)
    elseif key == "attribute" then
        if subid < 10 or subid > 26 then
            return false
        end
        return equipment.applyAttribute(eq, subid, value)
    end

    return false
end

function equipment.update(id, key, value)
    if not equipment.validateId(id) then
        return
    end

    equipment.state[id] = equipment.state[id] or {}
    equipment.state[id][key] = value
end

function equipment.getState(id)
    if not equipment.validateId(id) then
        return nil
    end
    return equipment.state[id]
end

function equipment.clearAllElements(id)
    local eq = equipment.get(id)
    if not eq or not eq.elements then
        return
    end

    for elementId = 1, 8 do
        local name = elementNames[elementId]
        if name then
            eq.elements[name] = 0
        end
    end
end

function equipment.clearState()
    equipment.state = {}
end

function equipment.setState(state)
    equipment.state = state or {}
end

function equipment.initialize(deps)
    mem = deps.memory
    elementNames = deps.mappings.element
    attributeDefs = deps.mappings.attribute
    constants = deps.mappings.constants
    return true
end

return equipment
