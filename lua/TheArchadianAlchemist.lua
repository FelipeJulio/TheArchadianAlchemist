-- Made by FehDead
-- =================
-- addresses
-- =================
local addresses = {
    base = 0x02099DF0,
    locationId = 0x021654C4,
    storyProgress = 0x2164480,
    flow = {
        status = 0x50,
        selected = 0x51,
        success = 0x52,
        reset = 0x53,
        loadEquipment = 0x54,
        checkElement = 0x4E,
        checkAttribute = 0x4B,
        pollMode = 0x4A,
        mainQuesGill = 0x33,
        mainQuestStatus = 0x37,
        unlockedElements = 0x36,
        unlockedAttributes = 0x38,
        unlockedTiers = 0x49
    },
    selected = {
        category = 0x55,
        subcategory = 0x56,
        equipmentId = 0x57,
        tier = 0x5A
    },
    obtained = {
        initial = 0x5B,
        extra = 0x5D,
        total = 0x5F,
        tier1 = 0x61,
        tier2 = 0x63,
        tier3 = 0x65,
        currentElement = 0x4F,
        currentAttribute = 0x4C
    },
    equipments = {
        upgrades = 0x67,
        list = 0x76
    }
}

-- =================
-- definitions
-- =================

local definitions = {
    equipment = {
        [1] = {"sword"},
        [2] = {"greatSword"},
        [3] = {"katana"},
        [4] = {"ninjaSword"},
        [5] = {"spear"},
        [6] = {"pole"},
        [7] = {"bow"},
        [8] = {"crossBow"},
        [9] = {"gun"},
        [10] = {"dagger"},
        [11] = {"rod"},
        [12] = {"staff"},
        [13] = {"mace"},
        [14] = {"axe"},
        [15] = {"hammer"},
        [16] = {"handBomb"},
        [17] = {"measure"},
        [18] = {"heavyArmor"},
        [19] = {"lightArmor"},
        [20] = {"mysticArmor"},
        [21] = {"heavyHelm"},
        [22] = {"lightHelm"},
        [23] = {"mysticHelm"},
        [24] = {"belt"},
        [25] = {"boot"},
        [26] = {"bracelet"},
        [27] = {"collar"},
        [28] = {"crown"},
        [29] = {"glove"},
        [30] = {"pendant"},
        [31] = {"ring"},
        [32] = {"arrow"},
        [33] = {"bolt"},
        [34] = {"bomb"},
        [35] = {"shot"},
        [36] = {"shield"}
    },
    attribute = {
        [10] = {"range", "direct"},
        [11] = {"chargeTime", "direct"},
        [12] = {"attackPower", "direct"},
        [13] = {"onHitRate", "direct"},
        [14] = {"knockbackChance", "direct"},
        [15] = {"comboOrCriticalChance", "direct"},
        [16] = {"evadeWeapon", "direct"},
        [17] = {"evadeShield", "direct"},
        [18] = {"magickEvadeShield", "direct"},
        [19] = {"defense", "direct"},
        [20] = {"magickResist", "direct"},
        [21] = {"maxHp", "linked", 0x00},
        [22] = {"maxMp", "linked", 0x02},
        [23] = {"strength", "linked", 0x04},
        [24] = {"magickPower", "linked", 0x05},
        [25] = {"vitality", "linked", 0x06},
        [26] = {"speed", "linked", 0x07}
    },
    element = {
        [1] = "fire",
        [2] = "lightning",
        [3] = "ice",
        [4] = "earth",
        [5] = "water",
        [6] = "wind",
        [7] = "holy",
        [8] = "dark"
    }
}

-- =================
-- constants
-- =================

local constants = {
    targetLocation = 632,
    equipmentBaseId = 4096,
    flowEvents = {
        talk = "talk",
        reset = "reset",
        result = "result",
        loadEquipment = "loadEquipment",
        equipmentSelected = "equipmentSelected",
        checkElement = "checkElement",
        checkAttribute = "checkAttribute",
        element = "element",
        attribute = "attribute"
    },
    flowIntervals = {
        idle = 2000,
        talk = 200,
        sync = 20
    },
    configPaths = {
        equipment = "scripts/config/TheArchadianAlchemist/equipments.lua",
        attribute = "scripts/config/TheArchadianAlchemist/attributes.lua",
        element = "scripts/config/TheArchadianAlchemist/elements.lua",
        questline = "scripts/config/TheArchadianAlchemist/questline.lua",
        directory = "scripts/config/TheArchadianAlchemist/*.lua"
    },
    symbols = {"TAA_QuestStatus", "TAA_ElementStatus", "TAA_AttributeStatus"}
}

-- =================
-- modules
-- =================

local helpers = {}
local mem = {}
local flags = {}
local config = {
    data = {},
    paths = constants.configPaths,
    lookupCache = {}
}
local equipment = {
    state = {}
}
local attribute = {
    names = definitions.attribute
}
local element = {
    definitions = definitions.element
}
local unlock = {}
local loader = {}
local flow = {
    lastPollMode = -1
}
local controller = {
    targetLocation = constants.targetLocation,
    locationId = -1,
    valid = false,
    running = false,
    pollId = 0
}
local symbols = {}
local handlers = {}

-- =================
-- helpers
-- =================

-- @description: convert numeric value to boolean (0 or 1), returns number
function helpers.toBool(value)
    return (value or 0) > 0 and 1 or 0
end

-- @description: check if addresses object has 'selected' field, returns boolean
function helpers.hasAddresses(addresses)
    return addresses and addresses.selected
end

-- @description: check if config table contains given key, returns boolean
function helpers.hasConfig(config, key)
    return config and config[key]
end

-- @description: calculate tier index based on progress and tier ids, returns 1-3
function helpers.getTierIndex(progress, ids)
    if not ids or #ids < 2 then
        return 1
    end
    if #ids >= 3 and progress >= ids[3] then
        return 3
    elseif progress >= ids[2] then
        return 2
    end
    return 1
end

-- @description: validate memory size (1, 2, or 4 bytes), returns boolean
function helpers.validateSize(size)
    return size == 1 or size == 2 or size == 4
end

-- @description: validate equipment index (0 to maxEquipmentList), returns boolean
function helpers.validateEquipmentIndex(id)
    return id and id >= 0 and id <= 31
end

-- @description: check if value is a table, returns boolean
function helpers.isTable(value)
    return type(value) == "table"
end

-- @description: get item id from item (supports array/object format), returns number or nil
function helpers.getItemId(item)
    return item[1] or item.id
end

-- @description: get item quantity from item (supports array/object format), returns number or nil
function helpers.getItemQty(item)
    return item[2] or item.qtt or item.qty
end

-- =================
-- memory
-- =================

-- @description: read 8-bit value from memory, returns number
function mem.readU8(base, offset)
    local address = (offset == nil) and base or (base + offset)
    return memory.u8[address] or 0
end

-- @description: read 16-bit value from memory, returns number
function mem.readU16(base, offset)
    local address = (offset == nil) and base or (base + offset)
    return memory.u16[address] or 0
end

-- @description: read 32-bit value from memory, returns number
function mem.readU32(base, offset)
    local address = (offset == nil) and base or (base + offset)
    return memory.u32[address] or 0
end

-- @description: write 8-bit value to memory
function mem.writeU8(base, offset, value)
    local address = (offset == nil) and base or (base + offset)
    memory.u8[address] = value
end

-- @description: write 16-bit value to memory
function mem.writeU16(base, offset, value)
    local address = (offset == nil) and base or (base + offset)
    memory.u16[address] = value
end

-- @description: write 32-bit value to memory
function mem.writeU32(base, offset, value)
    local address = (offset == nil) and base or (base + offset)
    memory.u32[address] = value
end

-- @description: clear memory region
function mem.clear(base, offset, length)
    if length == nil or length <= 0 then
        return
    end

    local startAddr = (offset == nil) and base or (base + offset)
    for i = 0, length - 1 do
        memory.u8[startAddr + i] = 0
    end
end

-- =================
-- flags
-- =================

-- @description: get flag value (1 byte), returns 0-255
function flags.get(base, offset)
    return mem.readU8(base, offset)
end

-- @description: set flag value (1 byte, 0-255)
function flags.set(base, offset, value)
    mem.writeU8(base, offset, value)
end

-- @description: clear flag (set to 0)
function flags.clear(base, offset)
    mem.writeU8(base, offset, 0)
end

-- =================
-- config
-- =================

-- @description: load external config file, returns table or nil
function config.external(path, name)
    local chunk, err = loadfile(path, "t", setmetatable({}, {
        __index = _G
    }))

    if not chunk then
        return nil
    end

    local ok, result = pcall(chunk)
    if not ok then
        return nil
    end

    return result
end

-- @description: build lookup tables for name to id conversion, returns 3 tables
function config.lookup()
    if config.lookupCache.categoryNameToId then
        return config.lookupCache.categoryNameToId, config.lookupCache.attributeNameToId, config.lookupCache.elementNameToId
    end

    local categoryNameToId = {}
    for categoryId, categoryNames in pairs(definitions.equipment) do
        categoryNameToId[categoryNames[1]] = categoryId
    end

    local attributeNameToId = {}
    for attributeId, attrData in pairs(definitions.attribute) do
        attributeNameToId[attrData[1]] = attributeId
    end

    local elementNameToId = {}
    for elementId, elementName in pairs(definitions.element) do
        elementNameToId[elementName] = elementId
    end

    -- cache lookup tables
    config.lookupCache.categoryNameToId = categoryNameToId
    config.lookupCache.attributeNameToId = attributeNameToId
    config.lookupCache.elementNameToId = elementNameToId

    return categoryNameToId, attributeNameToId, elementNameToId
end

-- @description: parse equipment config by category name to id, returns parsed table
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

-- @description: parse element config by element name to id, returns parsed table
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

-- @description: parse attribute config by attribute name to id, returns parsed table
function config.attribute(rawAttributes, attributeNameToId)
    local parsed = {}
    for attributeName, attributeData in pairs(rawAttributes or {}) do
        local attributeId = attributeNameToId[attributeName]
        if attributeId then
            parsed[attributeId] = {}
            -- Aqui está o segredo: ele precisa procurar tanto na raiz quanto
            for tier = 1, 3 do
                local tierData = attributeData[tier]
                if tierData then
                    parsed[attributeId][tier] = {
                        gil = tierData.gil,
                        value = tierData.value,
                        items = tierData.items
                    }
                end
            end
        elseif attributeName == "remove" then
            -- Mantém a lógica de remoção
            local items = {}
            local gil = 0
            if type(attributeData) == "table" then
                for i, item in ipairs(attributeData) do
                    if i == #attributeData and type(item) == "number" then
                        gil = item
                    else
                        table.insert(items, item)
                    end
                end
            end
            parsed[9] = {
                items = items,
                gil = gil
            }
        end
    end
    return parsed
end

-- @description: parse questline section (elementalExchange or attributeRefinement), returns parsed table
function config.parseQuestlineSection(section, nameToId)
    if not section then
        return nil
    end

    local parsed = {
        ids = {},
        contents = {}
    }

    -- parse tiers [1], [2], [3]
    for tier = 1, 3 do
        local tierData = section[tier]
        if tierData then
            -- ids is an array: {id1, id2, id3}
            parsed.ids[tier] = tierData.id

            -- convert unlocks names to IDs
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

    -- convert ids from indexed table to array: {[1]=id1, [2]=id2, [3]=id3} -> {id1, id2, id3}
    local idsArray = {}
    for i = 1, 3 do
        if parsed.ids[i] then
            idsArray[i] = parsed.ids[i]
        end
    end
    parsed.ids = idsArray

    return parsed
end

-- @description: parse questline config by converting names to ids, returns parsed table
function config.questline(rawQuestline, elementNameToId, attributeNameToId)
    local parsed = {}

    -- parse mainQuest
    if rawQuestline.mainQuest then
        local idsArray = {}
        for tier = 1, 3 do
            local tierData = rawQuestline.mainQuest[tier]
            if tierData then
                idsArray[tier] = tierData.id
            end
        end
        parsed.mainQuest = {
            ids = idsArray,
            gill = rawQuestline.mainQuest.gill or 0
        }
    end

    -- parse elementalExchange
    if rawQuestline.elementalExchange then
        parsed.elementalExchange = config.parseQuestlineSection(rawQuestline.elementalExchange, elementNameToId)
    end

    -- parse attributeRefinement
    if rawQuestline.attributeRefinement then
        parsed.attributeRefinement = config.parseQuestlineSection(rawQuestline.attributeRefinement, attributeNameToId)
    end

    return parsed
end

-- @description: parse all config files and convert names to ids, returns parsed table
function config.parse(rawConfig)
    local categoryNameToId, attributeNameToId, elementNameToId = config.lookup()

    return {
        equipment = config.equipment(rawConfig.equipment, categoryNameToId),
        attributes = config.attribute(rawConfig.attributes, attributeNameToId),
        elements = config.element(rawConfig.elements, elementNameToId),
        questline = config.questline(rawConfig.questline, elementNameToId, attributeNameToId)
    }
end

-- @description: load and parse all config files, returns parsed table or nil
function config.load()
    local equipmentConfig = config.external(config.paths.equipment, "equipment") or {}
    local attributeConfig = config.external(config.paths.attribute, "attribute") or {}
    local elementConfig = config.external(config.paths.element, "element") or {}
    local questlineConfig = config.external(config.paths.questline, "questline") or {}

    local rawConfig = {
        equipment = equipmentConfig,
        attributes = attributeConfig,
        elements = elementConfig,
        questline = questlineConfig
    }

    config.data = config.parse(rawConfig)
    return config.data
end

-- =================
-- equipment
-- =================

local elementNames = definitions.element
local attributeDefs = definitions.attribute

-- @description: get equipment from bpack
-- @params: id (number) - equipment id
-- @returns: equipment object or nil
function equipment.get(id)
    if not (id and id > 0) then
        return nil
    end
    local idx = id - constants.equipmentBaseId
    return bpack.section13[idx]
end

-- @description: read value from equipment (element/attribute), returns number or nil
function equipment.read(id, key, subid)
    local eq = equipment.get(id)
    if not eq then
        return nil
    end

    if key == "element" then
        if not (subid and subid >= 1 and subid <= 8) then
            return nil
        end
        local name = elementNames[subid]
        if not name then
            return nil
        end
        local elements = eq and eq.elements
        return (elements and elements[name]) or 0
    elseif key == "attribute" then
        if not (subid and subid >= 10 and subid <= 26) then
            return nil
        end
        local attr = attributeDefs[subid]
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
        elseif typ == "linked" and not eq.attributePointer then
            return nil
        end
    end

    return nil
end

-- @description: apply element to equipment (assumes validated input), returns boolean
function equipment.applyElement(eq, subid, value)
    local name = elementNames[subid]
    if not name then
        return false
    end
    if not eq.elements then
        eq.elements = {}
    end
    eq.elements[name] = value
    return true
end

-- @description: apply attribute to equipment (assumes validated input), returns boolean
function equipment.applyAttribute(eq, subid, value)
    local attr = attributeDefs[subid]
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

-- @description: write value to equipment (element/attribute), returns boolean
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

-- @description: update equipment state
function equipment.update(id, key, value)
    if not (id and id > 0) then
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

-- @description: clear all elements from equipment
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

-- @description: validate equipment id, returns boolean
function equipment.validateId(id)
    return id and id > 0
end

-- =================
-- attribute
-- =================

-- @description: get current attribute refinement from equipment.state, returns table or nil
function attribute.get(base, addresses)
    local equipmentId = mem.readU16(base, addresses.selected.equipmentId)

    if not (equipmentId and equipmentId > 0) then
        return nil
    end

    local state = equipment.state[equipmentId]

    if state and state.attributes then
        return state.attributes
    end

    return nil
end

-- @description: apply attribute upgrade to equipment, returns boolean
function attribute.set(base, addresses, tier, config)
    if not helpers.hasAddresses(addresses) then
        return false
    end

    local attributeId = flags.get(base, addresses.selected.subcategory)
    local equipmentId = mem.readU16(base, addresses.selected.equipmentId)
    local categoryId = flags.get(base, addresses.selected.category)

    if not (equipmentId and equipmentId > 0) then
        return false
    end

    if not (attributeId and attributeId >= 10 and attributeId <= 26) then
        return false
    end

    if not (tier and tier >= 1 and tier <= 3) then
        return false
    end

    local attrData = config and config.attributes and config.attributes[attributeId]
    if not attrData then
        return false
    end

    local tierData = attrData[tier]
    if not tierData then
        return false
    end

    local extraValue = tierData.value or 0

    local state = equipment.state[equipmentId]
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

    local total = 0
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

-- @description: remove attribute refinement from equipment, restore original value, returns boolean
function attribute.remove(base, addresses)
    local equipmentId = mem.readU16(base, addresses.selected.equipmentId)
    if not (equipmentId and equipmentId > 0) then
        return false
    end

    local state = equipment.state[equipmentId]
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

-- @description: apply or remove attribute based on subcategory flag, returns boolean
function attribute.apply(base, addresses, config)
    local selected = {
        success = flags.get(base, addresses.flow.success),
        subcategory = flags.get(base, addresses.selected.subcategory),
        tier = flags.get(base, addresses.selected.tier),
        equipmentId = mem.readU16(base, addresses.selected.equipmentId)
    }

    if selected.success ~= 1 then
        return false
    end

    if selected.subcategory == 9 then
        attribute.remove(base, addresses)
    else
        if selected.tier and selected.tier >= 1 and selected.tier <= 3 then
            attribute.set(base, addresses, selected.tier, config)
            local refinement = attribute.get(base, addresses)
            loader.results(base, addresses.obtained, refinement)
        end
    end

    flags.set(base, addresses.flow.success, 0)
    return true
end

-- @description: get attribute access type (direct or linked), returns string or nil
function attribute.getAccess(subid, key)
    if not (subid and subid >= 10 and subid <= 26) then
        return nil
    end
    local attr = attributeDefs[subid]
    if not attr then
        return nil
    end
    return attr[2] -- "direct" or "linked"
end

-- @description: validate attribute access, returns boolean
function attribute.validateAccess(subid, key)
    return attribute.getAccess(subid, key) ~= nil
end

-- =================
-- element
-- =================

-- @description: get current active element from equipment, returns 1-8 or 0
function element.get(base, addresses)
    local equipmentId = mem.readU16(base, addresses.selected.equipmentId)
    if not (equipmentId and equipmentId > 0) then
        return 0
    end

    local eq = equipment.get(equipmentId)
    if eq and eq.elements then
        for id = 1, 8 do
            local name = elementNames[id]
            if name and eq.elements[name] == 1 then
                return id
            end
        end
    end

    return 0
end

-- @description: write element id into obtained flag
function element.write(base, addresses, elementId)
    flags.set(base, addresses.obtained.currentElement, elementId or 0)
end

-- @description: apply element to equipment, clear all elements first, returns boolean
function element.set(base, addresses, elementId)
    if not (elementId and elementId >= 1 and elementId <= 8) then
        return false
    end

    local equipmentId = mem.readU16(base, addresses.selected.equipmentId)
    if not (equipmentId and equipmentId > 0) then
        return false
    end

    local eq = equipment.get(equipmentId)
    if not eq then
        return false
    end

    for id = 1, 8 do
        equipment.applyElement(eq, id, 0)
    end

    equipment.applyElement(eq, elementId, 1)

    equipment.update(equipmentId, "element", {
        id = elementId
    })

    return true
end

-- @description: remove element from equipment, clear all elements, returns boolean
function element.remove(base, addresses)
    local equipmentId = mem.readU16(base, addresses.selected.equipmentId)
    if not (equipmentId and equipmentId > 0) then
        return false
    end

    local eq = equipment.get(equipmentId)
    if not eq then
        return false
    end

    for id = 1, 8 do
        equipment.applyElement(eq, id, 0)
    end

    equipment.update(equipmentId, "element", nil)

    return true
end

-- @description: apply or remove element based on subcategory flag, returns boolean
function element.apply(base, addresses)
    local selected = {
        success = flags.get(base, addresses.flow.success),
        subcategory = flags.get(base, addresses.selected.subcategory),
        equipmentId = mem.readU16(base, addresses.selected.equipmentId)
    }

    if selected.success ~= 1 then
        return false
    end

    if selected.subcategory == 9 then
        element.remove(base, addresses)
    else
        element.set(base, addresses, selected.subcategory)
    end

    flags.set(base, addresses.flow.success, 0)
    return true
end

-- @description: clear all elements from equipment
function element.clearAll(equipmentId)
    if not (equipmentId and equipmentId > 0) then
        return
    end

    for id = 1, 8 do
        equipment.write(equipmentId, "element", id, 0)
    end
end

-- =================
-- unlock
-- =================

-- @description: unlock tier based on story progression and flow status
function unlock.tier(base, addresses, questline)
    local flowStatus = flags.get(base, addresses.flow.status)
    local override = questline and questline.overrideEvents
    local unlockStatus = 0

    if override then
        -- Pega o valor direto do módulo symbol
        if flowStatus == 2 then
            unlockStatus = symbols.getValue(constants.symbols.element)
        elseif flowStatus == 3 then
            unlockStatus = symbols.getValue(constants.symbols.attribute)
        end
    else
        local progress = mem.readU16(addresses.storyProgress, nil)
        local ids = nil
        if flowStatus == 2 then
            ids = questline and questline.elementalExchange and questline.elementalExchange.ids
        elseif flowStatus == 3 then
            ids = questline and questline.attributeRefinement and questline.attributeRefinement.ids
        end

        if ids then
            unlockStatus = helpers.getTierIndex(progress, ids)
        end
    end

    if unlockStatus and unlockStatus >= 1 and unlockStatus <= 3 then
        flags.set(base, addresses.flow.unlockedTiers, unlockStatus)
    end
end

-- @description: unlock content based on story progression
function unlock.content(base, addresses, questline)
    local flowStatus = flags.get(base, addresses.flow.status)
    local override = questline and questline.overrideEvents

    local contents, ids, startId, endId, targetFlagAddr = nil, nil, nil, nil, nil

    if questline and questline.mainQuest and questline.mainQuest.gill then
        mem.writeU32(base, addresses.flow.mainQuesGill, questline.mainQuest.gill)
    end

    if flowStatus == 2 then
        if not helpers.hasConfig(questline, "elementalExchange") then
            return
        end
        contents = questline.elementalExchange.contents
        ids = questline.elementalExchange.ids
        startId, endId = 1, 8
        targetFlagAddr = addresses.flow.unlockedElements
    elseif flowStatus == 3 then
        if not helpers.hasConfig(questline, "attributeRefinement") then
            return
        end
        contents = questline.attributeRefinement.contents
        ids = questline.attributeRefinement.ids
        startId, endId = 10, 26
        targetFlagAddr = addresses.flow.unlockedAttributes
    end

    if not contents or not targetFlagAddr then
        return
    end

    local levelIndex = 0
    if override then
        -- Passa o valor do symbol para o index de conteúdo
        local symName = (flowStatus == 2) and constants.symbols.element or constants.symbols.attribute
        levelIndex = symbols.getValue(symName)
    else
        local progress = mem.readU16(addresses.storyProgress, nil)
        levelIndex = helpers.getTierIndex(progress, ids)
    end

    local levelContents = contents[levelIndex]
    if levelContents then
        unlock.writeFlags(base, targetFlagAddr, startId, endId, levelContents)
    end

    -- Atualiza MainQuest baseada no símbolo (override) ou progresso
    local mainStatus = 0
    if override then
        mainStatus = symbols.getValue(constants.symbols.main)
    else
        local progress = mem.readU16(addresses.storyProgress, nil)
        local mainIds = questline.mainQuest and questline.mainQuest.ids
        mainStatus = helpers.getTierIndex(progress, mainIds)
    end

    flags.set(base, addresses.flow.mainQuestStatus, mainStatus)
end

-- @description: write unlock flags to memory
function unlock.writeFlags(base, baseOffset, startId, endId, levelContents)
    if not levelContents then
        return
    end

    local baseAddr = base + baseOffset
    for id = startId, endId do
        local value = levelContents[id]
        local flag = (value or 0) > 0 and 1 or 0
        flags.set(base, baseOffset + (id - startId), flag)
    end
end

-- @description: unlock NPC (placeholder for future implementation)
function unlock.npc(base, addresses)
end

-- =================
-- loader
-- =================

-- @description: coordinate loading of equipment, upgrades, or tier values, returns boolean
function loader.dispatch(base, addresses, config)
    if not config then
        return false
    end

    local flowStatus = flags.get(base, addresses.flow.status)
    local categoryId = flags.get(base, addresses.selected.category)
    local subcategoryId = flags.get(base, addresses.selected.subcategory)
    local tierId = flags.get(base, addresses.selected.tier)

    if flowStatus == 3 then
        mem.writeU16(base, addresses.obtained.tier1, 0)
        mem.writeU16(base, addresses.obtained.tier2, 0)
        mem.writeU16(base, addresses.obtained.tier3, 0)
    end

    if categoryId and categoryId ~= 0 then
        loader.equipment(base, addresses.equipments.list, categoryId, config)
    end

    if flowStatus == 3 and tierId and tierId >= 1 and tierId <= 3 then
        loader.upgrade(base, addresses.equipments.upgrades, subcategoryId, tierId, categoryId, config, flowStatus)
    elseif flowStatus == 3 and subcategoryId then
        if subcategoryId == 9 then
            loader.upgrade(base, addresses.equipments.upgrades, subcategoryId, nil, categoryId, config, flowStatus)
        elseif subcategoryId >= 10 and subcategoryId <= 26 then
            loader.tier(base, addresses.obtained, subcategoryId, categoryId, config)
        end
    elseif flowStatus == 2 and subcategoryId then
        if (subcategoryId >= 1 and subcategoryId <= 8) or subcategoryId == 9 then
            loader.upgrade(base, addresses.equipments.upgrades, subcategoryId, nil, categoryId, config, flowStatus)
        end
    end

    return true
end

-- @description: load equipment list into memory buffer, returns boolean
function loader.equipment(base, offset, categoryId, config)
    if not config or not config.equipment then
        return false
    end

    local equipmentList = config.equipment[categoryId]
    if not equipmentList then
        return false
    end

    local baseAddr = base + offset
    mem.clear(base, offset, 62)

    local maxItems = math.min(#equipmentList, 31)
    for i = 1, maxItems do
        mem.writeU16(baseAddr + ((i - 1) * 2), nil, equipmentList[i])
    end

    return true
end

-- @description: load upgrade materials into memory buffer, returns boolean
function loader.upgrade(base, offset, subcategoryId, tierId, categoryId, config, flowStatus)
    if not config then
        return false
    end

    local configElements = config.elements
    local configAttributes = config.attributes

    local upgrades = nil
    local gilValue = 0

    if subcategoryId == 9 then
        if flowStatus == 2 then
            local elemData = configElements and configElements[9]
            upgrades = elemData and elemData.items
            gilValue = (elemData and elemData.gil) or 0
        elseif flowStatus == 3 then
            local attrData = configAttributes and configAttributes[9]
            if attrData then
                upgrades = attrData.items
                gilValue = attrData.gil or 0
            end
        end
    elseif tierId and tierId >= 1 and tierId <= 3 and subcategoryId >= 10 and subcategoryId <= 26 then
        local attrData = configAttributes and configAttributes[subcategoryId]
        local tierData = attrData and attrData[tierId]
        if tierData then
            upgrades = tierData.items
            gilValue = tierData.gil or 0
        end
    elseif subcategoryId >= 1 and subcategoryId <= 8 then
        local elemData = configElements and configElements[subcategoryId]
        if elemData then
            upgrades = elemData.items
            gilValue = elemData.gil or 0
        end
    end

    if not upgrades or not loader.validateUpgrades(upgrades) then
        return false
    end

    mem.clear(base, offset, 15)

    local baseAddr = base + offset

    local offsets = {
        id = {0, 2, 4},
        qty = {6, 7, 8},
        gil = {9, 11, 13}
    }

    for i = 1, 3 do
        local item = upgrades[i]
        if item then
            mem.writeU16(baseAddr + offsets.id[i], nil, helpers.getItemId(item))
            mem.writeU8(baseAddr + offsets.qty[i], nil, helpers.getItemQty(item))
        end
        mem.writeU16(baseAddr + offsets.gil[i], nil, gilValue)
    end

    return true
end

-- @description: load tier values into flags, returns boolean
function loader.tier(base, addresses, attributeId, categoryId, config)
    if not helpers.hasConfig(config, "attributes") then
        return false
    end

    local attr = config.attributes[attributeId]
    if not attr then
        return false
    end

    local tier1 = loader.getTierValue(attr, categoryId, 1)
    local tier2 = loader.getTierValue(attr, categoryId, 2)
    local tier3 = loader.getTierValue(attr, categoryId, 3)

    mem.writeU16(base, addresses.tier1, tier1)
    mem.writeU16(base, addresses.tier2, tier2)
    mem.writeU16(base, addresses.tier3, tier3)

    return true
end

-- @description: load attribute refinement results into obtained flags
function loader.results(base, addresses, refinement)
    if refinement then
        mem.writeU8(base, addresses.currentAttribute, refinement.id)
        mem.writeU16(base, addresses.initial, refinement.initial)
        mem.writeU16(base, addresses.extra, refinement.extra or 0)
        mem.writeU16(base, addresses.total, refinement.total)
    else
        mem.writeU8(base, addresses.currentAttribute, 0)
        mem.writeU16(base, addresses.initial, 0)
        mem.writeU16(base, addresses.extra, 0)
        mem.writeU16(base, addresses.total, 0)
    end
end

-- @description: get tier value from attribute data, returns number
function loader.getTierValue(attr, categoryId, tier)
    if not attr or not (tier and tier >= 1 and tier <= 3) then
        return 0
    end

    local tierData = attr[tier]
    if tierData then
        return tierData.value or 0
    end

    return 0
end

-- @description: validate upgrades array, returns boolean
function loader.validateUpgrades(upgrades)
    if not upgrades or not helpers.isTable(upgrades) then
        return false
    end

    if #upgrades == 0 then
        return false
    end

    for i, item in ipairs(upgrades) do
        if i > 3 then
            break
        end
        if not helpers.isTable(item) or not helpers.getItemId(item) then
            return false
        end
    end

    return true
end

-- =================
-- flow
-- =================

-- @description: resolve polling interval based on pollMode flag, returns milliseconds
function flow.interval(base, addresses)
    local mode = flags.get(base, addresses.flow.pollMode)

    if mode == 2 then
        return constants.flowIntervals.sync
    end

    if mode == 1 then
        return constants.flowIntervals.talk
    end

    return constants.flowIntervals.idle
end

-- @description: poll flow flags and decide current logical event, returns string or nil
function flow.poll(base, addresses)
    if flags.get(base, addresses.flow.reset) == 1 then
        flags.clear(base, addresses.flow.reset)
        flags.set(base, addresses.flow.pollMode, 2)
        return constants.flowEvents.reset
    end

    if flags.get(base, addresses.flow.success) ~= 0 then
        flags.set(base, addresses.flow.pollMode, 1)
        return constants.flowEvents.result
    end

    if flags.get(base, addresses.flow.loadEquipment) == 1 then
        flags.set(base, addresses.flow.pollMode, 2)
        return constants.flowEvents.loadEquipment
    end

    if flags.get(base, addresses.flow.selected) == 1 then
        flags.set(base, addresses.flow.pollMode, 2)
        return constants.flowEvents.equipmentSelected
    end

    if flags.get(base, addresses.flow.checkElement) == 1 then
        flags.set(base, addresses.flow.pollMode, 2)
        return constants.flowEvents.checkElement
    end

    if flags.get(base, addresses.flow.checkAttribute) == 1 then
        flags.set(base, addresses.flow.pollMode, 2)
        return constants.flowEvents.checkAttribute
    end

    local status = flags.get(base, addresses.flow.status)

    if status == 1 then
        flags.set(base, addresses.flow.pollMode, 1)
        return constants.flowEvents.talk
    end

    if status == 2 then
        flags.set(base, addresses.flow.pollMode, 2)
        return constants.flowEvents.element
    end

    if status == 3 then
        flags.set(base, addresses.flow.pollMode, 2)
        return constants.flowEvents.attribute
    end

    flags.set(base, addresses.flow.pollMode, 0)
    return nil
end

-- @description: initialize flow state when controller starts
function flow.load(base, addresses)
    flags.clear(base, addresses.flow.status)
    flags.clear(base, addresses.flow.selected)
    flags.clear(base, addresses.flow.success)
    flags.clear(base, addresses.flow.reset)
    flags.clear(base, addresses.flow.loadEquipment)
    flags.clear(base, addresses.flow.checkElement)
    flags.clear(base, addresses.flow.checkAttribute)

    flags.clear(base, addresses.selected.category)
    flags.clear(base, addresses.selected.subcategory)
    flags.clear(base, addresses.selected.tier)
    mem.writeU16(base, addresses.selected.equipmentId, 0)

    flags.set(base, addresses.flow.pollMode, 0)
end

-- @description: reset flow and internal state
function flow.reset(base, addresses)
    flow.load(base, addresses)
end

-- =================
-- controller
-- =================

-- @description: start controller execution
function controller.start()
    if controller.running then
        return
    end

    controller.running = true
    controller.pollId = controller.pollId + 1
    local currentPoll = controller.pollId

    flow.load(addresses.base, addresses)

    controller.schedule(currentPoll)
end

-- @description: stop controller execution
function controller.stop()
    if not controller.running then
        return
    end

    controller.running = false
    controller.pollId = controller.pollId + 1

    flow.load(addresses.base, addresses)
end

-- @description: schedule next poll based on flow interval
function controller.schedule(pollId)
    if pollId ~= controller.pollId then
        return
    end

    local interval = flow.interval(addresses.base, addresses)

    event.executeAfterMs(interval, function()
        controller.poll(pollId)
    end)
end

-- @description: single poll execution
function controller.poll(pollId)
    if pollId ~= controller.pollId then
        return
    end

    if not controller.running or not controller.valid then
        return
    end

    if config.data and config.data.questline then
        unlock.tier(addresses.base, addresses, config.data.questline)
        unlock.content(addresses.base, addresses, config.data.questline)
    end

    local event = flow.poll(addresses.base, addresses)
    if event then
        controller.dispatch(event, addresses.base, addresses, config.data)
    end

    controller.schedule(pollId)
end

-- @description: dispatch actions based on flow event
function controller.dispatch(event, base, addresses, config)
    if event == constants.flowEvents.reset then
        controller.reset(base, addresses)
        return
    end

    if event == constants.flowEvents.loadEquipment then
        loader.dispatch(base, addresses, config)
        flags.clear(base, addresses.flow.loadEquipment)
        flags.set(base, addresses.flow.pollMode, 1)
        return
    end

    if event == constants.flowEvents.equipmentSelected then
        flags.clear(base, addresses.flow.selected)
        return
    end

    if event == constants.flowEvents.checkElement then
        local current = element.get(base, addresses)
        element.write(base, addresses, current)
        flags.clear(base, addresses.flow.checkElement)
        return
    end

    if event == constants.flowEvents.checkAttribute then
        local refinement = attribute.get(base, addresses)
        loader.results(base, addresses.obtained, refinement)
        flags.clear(base, addresses.flow.checkAttribute)
        return
    end

    if event == constants.flowEvents.result then
        local flowStatus = flags.get(base, addresses.flow.status)

        if flowStatus == 2 then
            element.apply(base, addresses)
        elseif flowStatus == 3 then
            attribute.apply(base, addresses, config)
        end

        return
    end
end

-- @description: reset flow and internal state
function controller.reset(base, addresses)
    flow.load(base, addresses)
end

-- @description: handle location change and enable or disable the mod
function controller.location(locationId)
    controller.locationId = locationId

    if controller.validateLocation(locationId) then
        print("Location valid", locationId)

        controller.valid = true
        controller.start()
    else
        print("Location invalid", locationId)
        controller.valid = false
        controller.stop()
    end
end

-- @description: validate location id, returns boolean
function controller.validateLocation(locationId)
    return locationId == controller.targetLocation
end

-- =================
-- handlers
-- =================

-- @description: handle config file change
function handlers.onFileChange(filepath, stats, created, deleted)
    if deleted then
        return
    end

    config.load()
end

-- @description: handle save event, returns equipment state table
function handlers.onSave()
    return equipment.state
end

-- @description: handle load event
function handlers.onLoad(filepath, savedData)
    equipment.state = equipment.state or {}

    if savedData and helpers.isTable(savedData) then
        handlers.loadEquipmentState(savedData)
        handlers.restoreEquipmentState()
    end
end

-- @description: load equipment state from saved data
function handlers.loadEquipmentState(savedData)
    if savedData[1] then
        for _, item in ipairs(savedData) do
            if item.equipmentId then
                equipment.state[item.equipmentId] = {
                    element = item.element,
                    attributes = item.attributes
                }
            end
        end
    else
        for equipmentId, state in pairs(savedData) do
            local id = tonumber(equipmentId)
            if id then
                equipment.state[id] = {
                    element = state.element,
                    attributes = state.attributes
                }
            end
        end
    end
end

-- @description: restore equipment state to game
function handlers.restoreEquipmentState()
    for equipmentId, state in pairs(equipment.state) do
        if state and state.element and state.element.id then
            local elementId = state.element.id
            if elementId and elementId >= 1 and elementId <= 8 then
                for id = 1, 8 do
                    equipment.write(equipmentId, "element", id, 0)
                end
                equipment.write(equipmentId, "element", elementId, 1)
            end
        end

        if state and state.attributes and state.attributes.id then
            local attributeId = state.attributes.id
            local total = state.attributes.total
            if attributeId and attributeId >= 10 and attributeId <= 26 and total then
                equipment.write(equipmentId, "attribute", attributeId, total)
            end
        end
    end
end

-- @description: handle exit event
function handlers.onExit()
    memory.unregisterAllSymbols()
    collectgarbage()
end

-- =================
-- symbols
-- =================

-- @description: Registra os símbolos na memória global (Roda no topo do script)
function symbols.register()
    for i = 1, #constants.symbols do
        local addr = memory.alloc(1, true)
        memory.registerGlobalSymbol(constants.symbols[i], addr)
    end
end

-- @description: Pega o valor u32 de um símbolo pelo nome
function symbols.getValue(name)
    local addr = memory.getSymbol(name)
    if addr ~= 0 then
        return memory.u8[addr]
    end
    return 0
end

-- =================
-- initialize
-- =================

-- @description: register symbols
symbols.register()

-- @description: initialize mod on game init
event.registerEventAsync("onInitDone", function()
    config.load()
end)

-- @description: register file change handler for config files
event.registerFileChangeHandler(config.paths.directory, function(filepath, stats, created, deleted)
    handlers.onFileChange(filepath, stats, created, deleted)
end)

-- @description: register save handler
event.registerSaveHandler("TheArchadianAlchemist", function(filepath)
    return handlers.onSave()
end)

-- @description: register load handler
event.registerLoadHandler("TheArchadianAlchemist", function(filepath, savedData)
    handlers.onLoad(filepath, savedData)
end)

-- @description: handle save/load event - check location and start/stop controller
event.registerEventAsync("onSaveLoad", function()
    local locationId = mem.readU32(addresses.locationId, nil)
    controller.location(locationId)
end)

-- @description: handle map jump event - check location and start/stop controller
event.registerEventAsync("onMapJump", function(locationId)
    controller.location(locationId)
end)

event.registerEventAsync("exit", function()
    return handlers.onExit()
end)
