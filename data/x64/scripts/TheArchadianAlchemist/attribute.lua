-- Made By FehDead
local attribute = {}

local mem
local equipment
local helpers
local mappings
local loader

local addresses
local attributeDefs
local constants

function attribute.get(base, addrs)
    local equipmentId = mem.readU16(base, addrs.selected.selectedEquipmentId)

    if not (equipmentId > 0) then
        return nil
    end

    local state = equipment.getState(equipmentId)

    if state and state.attributes then
        return state.attributes
    end

    return nil
end

function attribute.set(base, addrs, tier, config)
    if not helpers.hasAddresses(addrs) then
        return false
    end

    local attributeId = mem.flags.get(base, addrs.selected.selectedSubcategory)
    local equipmentId = mem.readU16(base, addrs.selected.selectedEquipmentId)
    local categoryId = mem.flags.get(base, addrs.selected.selectedCategory)

    if not (equipmentId > 0) then
        return false
    end

    if not helpers.validateRange(attributeId, constants.attributeMin, constants.attributeMax) then
        return false
    end

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

    local state = equipment.getState(equipmentId)
    local stateAttributes = state and state.attributes

    if stateAttributes and stateAttributes.id and stateAttributes.id ~= attributeId then

        local existingAttrId = stateAttributes.id
        local existingInitial = stateAttributes.initial
        equipment.write(equipmentId, "attribute", existingAttrId, existingInitial)
    end

    local initial = 0
    if stateAttributes and stateAttributes.id == attributeId then
        initial = stateAttributes.initial
    else
        initial = equipment.read(equipmentId, "attribute", attributeId) or 0
    end

    local total
    if attributeId == 11 then
        total = initial - extraValue
    else
        total = initial + extraValue
    end

    equipment.write(equipmentId, "attribute", attributeId, total)

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

function attribute.remove(base, addrs)
    local equipmentId = mem.readU16(base, addrs.selected.selectedEquipmentId)

    if not (equipmentId > 0) then
        return false
    end

    local state = equipment.getState(equipmentId)
    if not state or not state.attributes then
        return true
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

function attribute.apply(base, addrs, config, loaderModule)
    local confirmedIntention = mem.flags.get(base, addrs.flow.confirmedIntention)
    local subcategory = mem.flags.get(base, addrs.selected.selectedSubcategory)
    local tier = mem.flags.get(base, addrs.selected.selectedTier)
    local equipmentId = mem.readU16(base, addrs.selected.selectedEquipmentId)

    if confirmedIntention ~= 1 then
        return false
    end

    if subcategory == constants.removeId then
        attribute.remove(base, addrs)
    else
        if helpers.validateRange(tier, constants.tierMin, constants.tierMax) then
            attribute.set(base, addrs, tier, config)

            local refinement = attribute.get(base, addrs)
            if loaderModule and loaderModule.results then
                loaderModule.results(base, addrs, refinement)
            end
        end
    end

    mem.flags.set(base, addrs.flow.confirmedIntention, 0)
    return true
end

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

function attribute.validateAccess(subid, key)
    return attribute.getAccess(subid, key) ~= nil
end

function attribute.initialize(deps)
    mem = deps.memory
    equipment = deps.equipment
    helpers = deps.helpers
    mappings = deps.mappings
    addresses = mappings.addresses
    attributeDefs = mappings.attribute
    constants = mappings.constants

    return true
end

return attribute
