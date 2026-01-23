-- Made By FehDead
local config = {}

local helpers
local mappings

local lookupCache = {}

local function buildLookup(source, keyExtractor)
	local lookup = {}
	for id, data in pairs(source) do
		local key = keyExtractor and keyExtractor(data) or data
		lookup[key] = id
	end
	return lookup
end

local function parseQuestlineSection(section, nameToId)
	if not section then return nil end

	local parsed = {
		ids = {},
		contents = {}
	}

	for tier = 1, 3 do
		local tierData = section[tier]
		if tierData then
			parsed.ids[tier] = tierData.id
			if tierData.unlocks then
				parsed.contents[tier] = {}
				for name, flag in pairs(tierData.unlocks) do
					local id = nameToId[name]
					if id then parsed.contents[tier][id] = helpers.toBool(flag) end
				end
			end
		end
	end

	return parsed
end

function config.lookup()
	if lookupCache.category then return lookupCache.category, lookupCache.attribute, lookupCache.element end

	lookupCache.category = buildLookup(mappings.equipment)
	lookupCache.attribute = buildLookup(mappings.attribute, function(d) return d[1] end)
	lookupCache.element = buildLookup(mappings.element)

	return lookupCache.category, lookupCache.attribute, lookupCache.element
end

function config.clearLookupCache() lookupCache = {} end

function config.equipment(rawEquipment, categoryNameToId)
	local parsed = {}

	for categoryName, equipmentList in pairs(rawEquipment or {}) do
		local categoryId = categoryNameToId[categoryName]
		if categoryId then parsed[categoryId] = equipmentList end
	end

	return parsed
end

function config.element(rawElements, elementNameToId)
	local parsed = {}

	for elementName, elementData in pairs(rawElements or {}) do
		local elementId = elementNameToId[elementName] or (elementName == "remove" and 9)
		if elementId then
			parsed[elementId] = {
				gil = elementData.gil,
				items = elementData.items
			}
		end
	end

	return parsed
end

function config.attribute(rawAttributesByCategory, attributeNameToId)
	local parsed = {}

	for categoryId, attributesData in pairs(rawAttributesByCategory or {}) do
		parsed[categoryId] = {}

		for attributeName, attributeData in pairs(attributesData) do
			local attributeId = attributeNameToId[attributeName]

			if attributeId then
				parsed[categoryId][attributeId] = {}
				for tier = 1, 3 do
					local tierData = attributeData[tier]
					if tierData then
						parsed[categoryId][attributeId][tier] = {
							gil = tierData.gil,
							value = tierData.value,
							items = tierData.items
						}
					end
				end
			elseif attributeName == "remove" and type(attributeData) == "table" then
				local items, gil = {}, 0
				for i, item in ipairs(attributeData) do
					if i == #attributeData and type(item) == "number" then
						gil = item
					else
						table.insert(items, item)
					end
				end
				parsed[categoryId][9] = {
					items = items,
					gil = gil
				}
			end
		end
	end

	return parsed
end

function config.questline(rawQuestline, elementNameToId, attributeNameToId)
	local parsed = {
		overrideEvents = rawQuestline.overrideEvents or false
	}
	local mainQuest = rawQuestline.mainQuest

	if mainQuest then
		parsed.mainQuest = {}
		if mainQuest.startQuest then
			parsed.mainQuest.startQuest = {
				id = mainQuest.startQuest.id,
				gil = mainQuest.startQuest.gil or 0
			}
		end
		if mainQuest.finishQuest then
			parsed.mainQuest.finishQuest = {
				id = mainQuest.finishQuest.id
			}
		end
	end

	if rawQuestline.elementalExchange then
		parsed.elementalExchange = parseQuestlineSection(rawQuestline.elementalExchange, elementNameToId)
	end
	if rawQuestline.attributeRefinement then
		parsed.attributeRefinement = parseQuestlineSection(rawQuestline.attributeRefinement, attributeNameToId)
	end

	return parsed
end

function config.parse(rawConfig)
	local categoryNameToId, attributeNameToId, elementNameToId = config.lookup()

	return {
		equipment = config.equipment(rawConfig.equipment, categoryNameToId),
		attributes = config.attribute(rawConfig.attributes, attributeNameToId),
		elements = config.element(rawConfig.elements, elementNameToId),
		questline = config.questline(rawConfig.questline, elementNameToId, attributeNameToId)
	}
end

function config.initialize(deps)
	helpers = deps.helpers
	mappings = deps.mappings

	config.clearLookupCache()

	return true
end

return config
