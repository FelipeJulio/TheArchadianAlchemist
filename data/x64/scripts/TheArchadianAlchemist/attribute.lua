-- Made By FehDead
local attribute = {}

local mem
local equipment
local helpers
local attributeDefs
local constants

function attribute.get(base, addrs)
	local equipmentId = mem.readU16(base, addrs.selected.selectedEquipmentId)
	if equipmentId <= 0 then return nil end

	local state = equipment.getState(equipmentId)
	return state and state.attributes or nil
end

function attribute.set(base, addrs, tier, config)
	if not helpers.hasAddresses(addrs) then return false end

	local attributeId = mem.flags.get(base, addrs.selected.selectedSubcategory)
	local equipmentId = mem.readU16(base, addrs.selected.selectedEquipmentId)
	local categoryId = mem.flags.get(base, addrs.selected.selectedCategory)

	if equipmentId <= 0 then return false end
	if not helpers.validateRange(attributeId, constants.attributeMin, constants.attributeMax) then return false end

	local categoryData = helpers.getNestedValue(config, "attributes", categoryId)
	local tierData = categoryData and categoryData[attributeId] and categoryData[attributeId][tier]
	if not tierData then return false end

	local extraValue = tierData.value or 0
	local state = equipment.getState(equipmentId)
	local stateAttributes = state and state.attributes

	if stateAttributes and stateAttributes.id and stateAttributes.id ~= attributeId then
		equipment.write(equipmentId, "attribute", stateAttributes.id, stateAttributes.initial)
	end

	local initial = (stateAttributes and stateAttributes.id == attributeId) and stateAttributes.initial or
		                (equipment.read(equipmentId, "attribute", attributeId) or 0)
	local total = attributeId == 11 and (initial - extraValue) or (initial + extraValue)

	equipment.write(equipmentId, "attribute", attributeId, total)
	equipment.update(equipmentId, "attributes", {
		id = attributeId,
		initial = initial,
		extra = extraValue,
		total = total,
		tier = tier
	})

	return true
end

function attribute.remove(base, addrs)
	local equipmentId = mem.readU16(base, addrs.selected.selectedEquipmentId)
	if equipmentId <= 0 then return false end

	local state = equipment.getState(equipmentId)
	if not state or not state.attributes then return true end

	local attrs = state.attributes
	if attributeDefs[attrs.id] and attrs.initial ~= nil then
		equipment.write(equipmentId, "attribute", attrs.id, attrs.initial)
	end

	equipment.update(equipmentId, "attributes", nil)
	return true
end

function attribute.apply(base, addrs, config, loaderModule)
	if mem.flags.get(base, addrs.flow.confirmedIntention) ~= 1 then return false end

	local subcategory = mem.flags.get(base, addrs.selected.selectedSubcategory)
	local tier = mem.flags.get(base, addrs.selected.selectedTier)

	if subcategory == constants.removeId then
		attribute.remove(base, addrs)
	elseif helpers.validateRange(tier, constants.tierMin, constants.tierMax) then
		attribute.set(base, addrs, tier, config)
		if loaderModule and loaderModule.results then loaderModule.results(base, addrs, attribute.get(base, addrs)) end
	end

	mem.flags.set(base, addrs.flow.confirmedIntention, 0)
	return true
end

function attribute.getAccess(subid)
	if not helpers.validateRange(subid, constants.attributeMin, constants.attributeMax) then return nil end
	local attr = attributeDefs[subid]
	return attr and attr[2] or nil
end

function attribute.validateAccess(subid) return attribute.getAccess(subid) ~= nil end

function attribute.initialize(deps)
	mem = deps.memory
	equipment = deps.equipment
	helpers = deps.helpers
	attributeDefs = deps.mappings.attribute
	constants = deps.mappings.constants
	return true
end

return attribute
