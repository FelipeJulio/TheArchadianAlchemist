-- Made By FehDead
-- =====================
-- ATTRIBUTE MODULE
-- =====================
-- Attribute refinement system
local attribute = {}

-- =====================
-- DEPENDÊNCIAS
-- =====================
local mem
local equipment
local helpers
local mappings
local loader -- Will be set after loader initializes (circular dependency)

-- =====================
-- FLAG DE INICIALIZAÇÃO
-- =====================
local isInitialized = false

-- =====================
-- CACHED REFERENCES
-- =====================
local addresses
local attributeDefs
local constants

-- =====================
-- READ OPERATIONS
-- =====================

-- @description: get current attribute refinement from equipment state
-- @params: base (memory base), addrs (addresses table)
-- @returns: refinement table or nil
function attribute.get(base, addrs)
    local equipmentId = mem.readU16(base, addrs.selected.equipmentId)

    if not (equipmentId and equipmentId > 0) then
        return nil
    end

    local state = equipment.getState(equipmentId)

    if state and state.attributes then
        return state.attributes
    end

    return nil
end

-- =====================
-- SET OPERATIONS
-- =====================

-- @description: apply attribute upgrade to equipment
-- @params: base (memory base), addrs (addresses table), tier (1-3), config
-- @returns: boolean
function attribute.set(base, addrs, tier, config)
    if not helpers.hasAddresses(addrs) then
        return false
    end

    local attributeId = mem.flags.get(base, addrs.selected.subcategory)
    local equipmentId = mem.readU16(base, addrs.selected.equipmentId)
    local categoryId = mem.flags.get(base, addrs.selected.category)

    -- Validate inputs
    if not (equipmentId and equipmentId > 0) then
        return false
    end
    if not helpers.validateRange(attributeId, constants.attributeMin, constants.attributeMax) then
        return false
    end
    if not helpers.validateRange(tier, constants.tierMin, constants.tierMax) then
        return false
    end

    -- Get config data
    local categoryData = helpers.getNestedValue(config, "attributes", categoryId)
    local attrData = categoryData and categoryData[attributeId]

    if not attrData then
        return false
    end

    local tierData = attrData[tier]
    if not tierData then
        return false
    end

    local extraValue = tierData.value or 0

    -- Check if different attribute was already applied
    local state = equipment.getState(equipmentId)
    local stateAttributes = state and state.attributes

    if stateAttributes and stateAttributes.id and stateAttributes.id ~= attributeId then
        -- Restore previous attribute to initial value
        local existingAttrId = stateAttributes.id
        local existingInitial = stateAttributes.initial
        equipment.write(equipmentId, "attribute", existingAttrId, existingInitial)
    end

    -- Get initial value
    local initial = 0
    if stateAttributes and stateAttributes.id == attributeId then
        initial = stateAttributes.initial
    else
        initial = equipment.read(equipmentId, "attribute", attributeId) or 0
    end

    -- Calculate total (chargeTime is subtracted, others are added)
    local total
    if attributeId == 11 then -- chargeTime
        total = initial - extraValue
    else
        total = initial + extraValue
    end

    -- Apply to equipment
    equipment.write(equipmentId, "attribute", attributeId, total)

    -- Update state
    local refinementData = {
        id = attributeId,
        initial = initial,
        extra = extraValue,
        total = total,
        tier = tier
    }
    equipment.update(equipmentId, "attributes", refinementData)

    return true
end

-- =====================
-- REMOVE OPERATIONS
-- =====================

-- @description: remove attribute refinement, restore original value
-- @params: base (memory base), addrs (addresses table)
-- @returns: boolean
function attribute.remove(base, addrs)
    local equipmentId = mem.readU16(base, addrs.selected.equipmentId)

    if not (equipmentId and equipmentId > 0) then
        return false
    end

    local state = equipment.getState(equipmentId)
    if not state or not state.attributes then
        return true -- Nothing to remove
    end

    local initial = state.attributes.initial
    local existingAttrId = state.attributes.id
    local attrDef = attributeDefs[existingAttrId]

    if attrDef and initial ~= nil then
        equipment.write(equipmentId, "attribute", existingAttrId, initial)
    end

    equipment.update(equipmentId, "attributes", nil)

    return true
end

-- =====================
-- APPLY OPERATIONS
-- =====================

-- @description: apply or remove attribute based on subcategory flag
-- @params: base (memory base), addrs (addresses table), config, loaderModule
-- @returns: boolean
function attribute.apply(base, addrs, config, loaderModule)
    local success = mem.flags.get(base, addrs.flow.success)
    local subcategory = mem.flags.get(base, addrs.selected.subcategory)
    local tier = mem.flags.get(base, addrs.selected.tier)
    local equipmentId = mem.readU16(base, addrs.selected.equipmentId)

    if success ~= 1 then
        return false
    end

    if subcategory == constants.removeId then
        attribute.remove(base, addrs)
    else
        if helpers.validateRange(tier, constants.tierMin, constants.tierMax) then
            attribute.set(base, addrs, tier, config)

            -- Load results using loader module
            local refinement = attribute.get(base, addrs)
            if loaderModule and loaderModule.results then
                loaderModule.results(base, addrs.obtained, refinement)
            end
        end
    end

    mem.flags.set(base, addrs.flow.success, 0)
    return true
end

-- =====================
-- ACCESS VALIDATION
-- =====================

-- @description: get attribute access type (direct or linked)
-- @params: subid (attribute id), key (unused, for compatibility)
-- @returns: string ("direct" or "linked") or nil
function attribute.getAccess(subid, key)
    if not helpers.validateRange(subid, constants.attributeMin, constants.attributeMax) then
        return nil
    end

    local attr = attributeDefs[subid]
    if not attr then
        return nil
    end

    return attr[2]
end

-- @description: validate attribute access
-- @returns: boolean
function attribute.validateAccess(subid, key)
    return attribute.getAccess(subid, key) ~= nil
end

-- =====================
-- INICIALIZAÇÃO
-- =====================

function attribute.initialize(deps)
    if not deps then
        print("ERROR [TAA ATTRIBUTE] Dependencies not provided")
        return false
    end

    if not deps.memory then
        print("ERROR [TAA ATTRIBUTE] Memory not provided")
        return false
    end

    if not deps.equipment then
        print("ERROR [TAA ATTRIBUTE] Equipment not provided")
        return false
    end

    if not deps.helpers then
        print("ERROR [TAA ATTRIBUTE] Helpers not provided")
        return false
    end

    if not deps.mappings then
        print("ERROR [TAA ATTRIBUTE] Mappings not provided")
        return false
    end

    mem = deps.memory
    equipment = deps.equipment
    helpers = deps.helpers
    mappings = deps.mappings

    -- Cache frequently used references
    addresses = mappings.addresses
    attributeDefs = mappings.attribute
    constants = mappings.constants

    isInitialized = true
    print("[TAA ATTRIBUTE] Module initialized")
    return true
end

-- =====================
-- DEBUG HELPERS
-- =====================

function attribute.isReady()
    return isInitialized
end

function attribute.getStatus()
    return {
        initialized = isInitialized,
        hasMemory = mem ~= nil,
        hasEquipment = equipment ~= nil,
        hasHelpers = helpers ~= nil,
        hasMappings = mappings ~= nil
    }
end

return attribute
