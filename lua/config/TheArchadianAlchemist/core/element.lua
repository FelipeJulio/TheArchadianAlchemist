-- Made By FehDead
-- =====================
-- EQUIPMENT MODULE
-- =====================
-- Equipment read/write operations and state management
local equipment = {}

-- =====================
-- CACHE DE FUNÇÕES GLOBAIS
-- =====================
local pairs = pairs

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
-- STATE
-- =====================
-- Stores modifications made to equipment (elements, attributes)
equipment.state = {}

-- =====================
-- CACHED REFERENCES
-- =====================
local elementNames
local attributeDefs
local constants

-- =====================
-- CORE OPERATIONS
-- =====================

-- @description: get equipment from bpack by id
-- @params: id (equipment id, e.g., 4097)
-- @returns: equipment object or nil
function equipment.get(id)
    if not equipment.validateId(id) then
        return nil
    end

    local idx = id - constants.equipmentBaseId
    return bpack.section13[idx]
end

-- @description: validate equipment id
-- @returns: boolean
function equipment.validateId(id)
    return id and id > 0
end

-- =====================
-- READ OPERATIONS
-- =====================

-- @description: read element value from equipment
-- @params: eq (equipment object), elementId (1-8)
-- @returns: number (0 or 1)
function equipment._readElement(eq, elementId)
    if not (elementId and elementId >= 1 and elementId <= 8) then
        return nil
    end

    local name = elementNames[elementId]
    if not name then
        return nil
    end

    local elements = eq and eq.elements
    return (elements and elements[name]) or 0
end

-- @description: read attribute value from equipment
-- @params: eq (equipment object), attributeId (10-26)
-- @returns: number or nil
function equipment._readAttribute(eq, attributeId)
    if not (attributeId and attributeId >= 10 and attributeId <= 26) then
        return nil
    end

    local attr = attributeDefs[attributeId]
    if not attr then
        return nil
    end

    local name, typ, offset = attr[1], attr[2], attr[3]

    if typ == "direct" then
        return eq[name] or 0
    elseif typ == "linked" then
        if not eq.attributePointer then
            return nil
        end

        local addr = eq.attributePointer + offset
        if name == "maxHp" or name == "maxMp" then
            return mem.readU16(addr, nil)
        else
            return mem.readU8(addr, nil)
        end
    end

    return nil
end

-- @description: read value from equipment (element or attribute)
-- @params: id (equipment id), key ("element" or "attribute"), subid (element/attribute id)
-- @returns: number or nil
function equipment.read(id, key, subid)
    local eq = equipment.get(id)
    if not eq then
        return nil
    end

    if key == "element" then
        return equipment._readElement(eq, subid)
    elseif key == "attribute" then
        return equipment._readAttribute(eq, subid)
    end

    return nil
end

-- =====================
-- WRITE OPERATIONS
-- =====================

-- @description: apply element to equipment object
-- @params: eq (equipment object), elementId (1-8), value (0 or 1)
-- @returns: boolean
function equipment.applyElement(eq, elementId, value)
    local name = elementNames[elementId]
    if not name then
        return false
    end

    if not eq.elements then
        eq.elements = {}
    end

    eq.elements[name] = value
    return true
end

-- @description: apply attribute to equipment object
-- @params: eq (equipment object), attributeId (10-26), value
-- @returns: boolean
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

-- @description: write value to equipment (element or attribute)
-- @params: id (equipment id), key ("element" or "attribute"), subid, value
-- @returns: boolean
function equipment.write(id, key, subid, value)
    local eq = equipment.get(id)
    if not eq then
        return false
    end

    if key == "element" then
        if not (subid and subid >= 1 and subid <= 8) then
            return false
        end
        return equipment.applyElement(eq, subid, value)
    elseif key == "attribute" then
        if not (subid and subid >= 10 and subid <= 26) then
            return false
        end
        return equipment.applyAttribute(eq, subid, value)
    end

    return false
end

-- =====================
-- STATE MANAGEMENT
-- =====================

-- @description: update equipment state
-- @params: id (equipment id), key (state key), value (nil to remove)
function equipment.update(id, key, value)
    if not equipment.validateId(id) then
        return
    end

    if not equipment.state[id] then
        equipment.state[id] = {}
    end

    if value == nil then
        equipment.state[id][key] = nil
    else
        equipment.state[id][key] = value
    end
end

-- @description: get equipment state
-- @params: id (equipment id)
-- @returns: state table or nil
function equipment.getState(id)
    if not equipment.validateId(id) then
        return nil
    end
    return equipment.state[id]
end

-- @description: clear all elements from equipment
-- @params: id (equipment id)
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

-- @description: clear entire equipment state
function equipment.clearState()
    equipment.state = {}
end

-- @description: set entire equipment state (for loading)
-- @params: state (table)
function equipment.setState(state)
    equipment.state = state or {}
end

-- =====================
-- INICIALIZAÇÃO
-- =====================

function equipment.initialize(deps)
    if not deps then
        print("ERROR [TAA EQUIPMENT] Dependencies not provided")
        return false
    end

    if not deps.memory then
        print("ERROR [TAA EQUIPMENT] Memory not provided")
        return false
    end

    if not deps.mappings then
        print("ERROR [TAA EQUIPMENT] Mappings not provided")
        return false
    end

    mem = deps.memory
    mappings = deps.mappings

    -- Cache frequently used references
    elementNames = mappings.element
    attributeDefs = mappings.attribute
    constants = mappings.constants

    isInitialized = true
    print("[TAA EQUIPMENT] Module initialized")
    return true
end

-- =====================
-- DEBUG HELPERS
-- =====================

function equipment.isReady()
    return isInitialized
end

function equipment.getStatus()
    local stateCount = 0
    for _ in pairs(equipment.state) do
        stateCount = stateCount + 1
    end

    return {
        initialized = isInitialized,
        hasMemory = mem ~= nil,
        hasMappings = mappings ~= nil,
        stateCount = stateCount
    }
end

return equipment
