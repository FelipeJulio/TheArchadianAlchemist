-- Made By FehDead
-- =====================
-- CONFIG MODULE
-- =====================
-- Config parsing and lookup functions
-- Note: Actual file loading is done in orchestrator.lua
local config = {}

-- =====================
-- CACHE DE FUNÇÕES GLOBAIS
-- =====================
local pairs = pairs
local ipairs = ipairs
local type = type
local tableInsert = table.insert

-- =====================
-- DEPENDÊNCIAS
-- =====================
local helpers
local mappings

-- =====================
-- FLAG DE INICIALIZAÇÃO
-- =====================
local isInitialized = false

-- =====================
-- LOOKUP CACHE
-- =====================
local lookupCache = {
    categoryNameToId = nil,
    attributeNameToId = nil,
    elementNameToId = nil
}

-- =====================
-- LOOKUP BUILDERS (PRIVADO)
-- =====================

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

-- =====================
-- LOOKUP API
-- =====================

-- @description: build and cache lookup tables for name to id conversion
-- @returns: categoryNameToId, attributeNameToId, elementNameToId
function config.lookup()
    if lookupCache.categoryNameToId then
        return lookupCache.categoryNameToId, lookupCache.attributeNameToId, lookupCache.elementNameToId
    end

    lookupCache.categoryNameToId = config._buildCategoryLookup()
    lookupCache.attributeNameToId = config._buildAttributeLookup()
    lookupCache.elementNameToId = config._buildElementLookup()

    return lookupCache.categoryNameToId, lookupCache.attributeNameToId, lookupCache.elementNameToId
end

-- @description: clear lookup cache (for hot reload)
function config.clearLookupCache()
    lookupCache.categoryNameToId = nil
    lookupCache.attributeNameToId = nil
    lookupCache.elementNameToId = nil
end

-- =====================
-- EQUIPMENT PARSER
-- =====================

-- @description: parse equipment config by category name to id
-- @params: rawEquipment (table), categoryNameToId (lookup table)
-- @returns: parsed table indexed by category id
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

-- =====================
-- ELEMENT PARSER
-- =====================

-- @description: parse element config by element name to id
-- @params: rawElements (table), elementNameToId (lookup table)
-- @returns: parsed table indexed by element id
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
            -- Special case: remove uses id 9
            parsed[9] = {
                gil = elementData.gil,
                items = elementData.items
            }
        end
    end

    return parsed
end

-- =====================
-- ATTRIBUTE PARSER
-- =====================

-- @description: parse attribute config by attribute name to id
-- @params: rawAttributesByCategory (table), attributeNameToId (lookup table)
-- @returns: parsed table indexed by [categoryId][attributeId]
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
                -- Parse remove: items array with optional gil at end
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

                -- ID 9 used for 'remove' internally
                parsed[categoryId][9] = {
                    items = items,
                    gil = gil
                }
            end
        end
    end

    return parsed
end

-- =====================
-- QUESTLINE PARSER (PRIVADO)
-- =====================

-- @description: parse questline section (elementalExchange or attributeRefinement)
-- @params: section (table), nameToId (lookup table)
-- @returns: parsed table with ids array and contents
function config._parseQuestlineSection(section, nameToId)
    if not section then
        return nil
    end

    local parsed = {
        ids = {},
        contents = {}
    }

    -- Parse tiers [1], [2], [3]
    for tier = 1, 3 do
        local tierData = section[tier]
        if tierData then
            parsed.ids[tier] = tierData.id

            -- Convert unlock names to IDs
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

-- =====================
-- QUESTLINE PARSER
-- =====================

-- @description: parse questline config by converting names to ids
-- @params: rawQuestline (table), elementNameToId, attributeNameToId (lookup tables)
-- @returns: parsed questline table
function config.questline(rawQuestline, elementNameToId, attributeNameToId)
    local parsed = {
        overrideEvents = rawQuestline.overrideEvents or false
    }

    -- Parse mainQuest (new structure with startQuest and finishQuest)
    if rawQuestline.mainQuest then
        parsed.mainQuest = {}

        -- Parse startQuest
        if rawQuestline.mainQuest.startQuest then
            parsed.mainQuest.startQuest = {
                id = rawQuestline.mainQuest.startQuest.id,
                gill = rawQuestline.mainQuest.startQuest.gill or rawQuestline.mainQuest.startQuest.gil or 0
            }
        end

        -- Parse finishQuest
        if rawQuestline.mainQuest.finishQuest then
            parsed.mainQuest.finishQuest = {
                id = rawQuestline.mainQuest.finishQuest.id
            }
        end
    end

    -- Parse elementalExchange
    if rawQuestline.elementalExchange then
        parsed.elementalExchange = config._parseQuestlineSection(rawQuestline.elementalExchange, elementNameToId)
    end

    -- Parse attributeRefinement
    if rawQuestline.attributeRefinement then
        parsed.attributeRefinement = config._parseQuestlineSection(rawQuestline.attributeRefinement, attributeNameToId)
    end

    return parsed
end

-- =====================
-- MAIN PARSER
-- =====================

-- @description: parse all config data and convert names to ids
-- @params: rawConfig (table with equipment, attributes, elements, questline)
-- @returns: fully parsed config table
function config.parse(rawConfig)
    local categoryNameToId, attributeNameToId, elementNameToId = config.lookup()

    return {
        equipment = config.equipment(rawConfig.equipment, categoryNameToId),
        attributes = config.attribute(rawConfig.attributes, attributeNameToId),
        elements = config.element(rawConfig.elements, elementNameToId),
        questline = config.questline(rawConfig.questline, elementNameToId, attributeNameToId)
    }
end

-- =====================
-- INICIALIZAÇÃO
-- =====================

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

    -- Clear cache on reinitialize (hot reload support)
    config.clearLookupCache()

    isInitialized = true
    print("[TAA CONFIG] Module initialized")
    return true
end

-- =====================
-- DEBUG HELPERS
-- =====================

function config.isReady()
    return isInitialized
end

function config.getStatus()
    return {
        initialized = isInitialized,
        hasHelpers = helpers ~= nil,
        hasMappings = mappings ~= nil,
        hasCategoryLookup = lookupCache.categoryNameToId ~= nil,
        hasAttributeLookup = lookupCache.attributeNameToId ~= nil,
        hasElementLookup = lookupCache.elementNameToId ~= nil
    }
end

return config
