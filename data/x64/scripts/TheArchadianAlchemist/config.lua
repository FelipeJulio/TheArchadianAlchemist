-- Made By FehDead
local config = {}

local pairs = pairs
local ipairs = ipairs
local type = type
local tableInsert = table.insert

local helpers
local mappings

local lookupCache = {
    categoryNameToId = nil,
    attributeNameToId = nil,
    elementNameToId = nil
}

function config._buildCategoryLookup()
    local lookup = {}
    for categoryId, categoryName in pairs(mappings.equipment) do
        lookup[categoryName] = categoryId
    end
    return lookup
end

function config._buildAttributeLookup()
    local lookup = {}
    for attributeId, attrData in pairs(mappings.attribute) do
        lookup[attrData[1]] = attributeId
    end
    return lookup
end

function config._buildElementLookup()
    local lookup = {}
    for elementId, elementName in pairs(mappings.element) do
        lookup[elementName] = elementId
    end
    return lookup
end

function config.lookup()
    if lookupCache.categoryNameToId then
        return lookupCache.categoryNameToId, lookupCache.attributeNameToId, lookupCache.elementNameToId
    end

    lookupCache.categoryNameToId = config._buildCategoryLookup()
    lookupCache.attributeNameToId = config._buildAttributeLookup()
    lookupCache.elementNameToId = config._buildElementLookup()

    return lookupCache.categoryNameToId, lookupCache.attributeNameToId, lookupCache.elementNameToId
end

function config.clearLookupCache()
    lookupCache.categoryNameToId = nil
    lookupCache.attributeNameToId = nil
    lookupCache.elementNameToId = nil
end

function config.equipment(rawEquipment, categoryNameToId)
    local parsed = {}

    for categoryName, equipmentList in pairs(rawEquipment or {}) do
        local categoryId = categoryNameToId[categoryName]
        if categoryId then
            parsed[categoryId] = equipmentList
        end
    end

    return parsed
end

function config.element(rawElements, elementNameToId)
    local parsed = {}

    for elementName, elementData in pairs(rawElements or {}) do
        local elementId = elementNameToId[elementName]

        if elementId then
            parsed[elementId] = {
                gil = elementData.gil,
                items = elementData.items
            }
        elseif elementName == "remove" then

            parsed[9] = {
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
            elseif attributeName == "remove" then
                local items = {}
                local gil = 0

                if type(attributeData) == "table" then
                    for i, item in ipairs(attributeData) do
                        if i == #attributeData and type(item) == "number" then
                            gil = item
                        else
                            tableInsert(items, item)
                        end
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

function config._parseQuestlineSection(section, nameToId)
    if not section then
        return nil
    end

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
                    if id then
                        parsed.contents[tier][id] = helpers.toBool(flag)
                    end
                end
            end
        end
    end

    return parsed
end

function config.questline(rawQuestline, elementNameToId, attributeNameToId)
    local parsed = {
        overrideEvents = rawQuestline.overrideEvents or false
    }

    if rawQuestline.mainQuest then
        parsed.mainQuest = {}

        if rawQuestline.mainQuest.startQuest then
            parsed.mainQuest.startQuest = {
                id = rawQuestline.mainQuest.startQuest.id,
                gill = rawQuestline.mainQuest.startQuest.gill or rawQuestline.mainQuest.startQuest.gil or 0
            }
        end

        if rawQuestline.mainQuest.finishQuest then
            parsed.mainQuest.finishQuest = {
                id = rawQuestline.mainQuest.finishQuest.id
            }
        end
    end

    if rawQuestline.elementalExchange then
        parsed.elementalExchange = config._parseQuestlineSection(rawQuestline.elementalExchange, elementNameToId)
    end

    if rawQuestline.attributeRefinement then
        parsed.attributeRefinement = config._parseQuestlineSection(rawQuestline.attributeRefinement, attributeNameToId)
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
    if not deps then
        print("ERROR [TAA CONFIG] Dependencies not provided")
        return false
    end

    if not deps.helpers then
        print("ERROR [TAA CONFIG] Helpers not provided")
        return false
    end

    if not deps.mappings then
        print("ERROR [TAA CONFIG] Mappings not provided")
        return false
    end

    helpers = deps.helpers
    mappings = deps.mappings

    config.clearLookupCache()

    return true
end

return config
