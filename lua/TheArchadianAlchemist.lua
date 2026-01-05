-- Made by FehDead
local addresses = {

    -- @description: scrach1 base address
    base = 0x02099DF0,

    -- @description: current location
    locationId = 0x021654C4,

    flow = {

        -- @description: conversation state
        -- @values: 1 started conversation, 2 element, 3 attribute
        status = 0x50,

        -- @description: equipment selection state
        -- @values: 0 nothing, 1 selected
        selected = 0x51,

        -- @description: result state
        -- @values: 0 nothing, 1 success, 2 insufficient materials, 3 upgrade already applied
        success = 0x52,

        -- @description: request flow reset
        -- @values: 0 nothing, 1 reset flow state
        reset = 0x53,

        -- @description: request for lua load equipment list
        -- @values: 0 nothing, 1 load equipment list into 0x67
        loadEquipment = 0x54,

        -- @description: request for lua  check current element at bpack
        -- @values: 0 nothing, 1 check
        checkElement = 0x4E,

        -- @description: request for lua  check current attribute at bpack
        -- @values: 0 nothing, 1 check
        checkAttribute = 0x4B,

        -- @description: poll mode
        -- @values: 0 idle, 1 talk , 2 sync
        pollMode = 0x4A
    },

    selected = {

        -- @description: selected equipment category
        -- @values: 0 nothing, ids from equipment.definitions
        category = 0x55,

        -- @description: selected element or attribute id
        -- @values: if 0x50 == 2 : 0=not initialized, 1 to 8 element ids, 9 remove
        -- @values: if 0x50 == 3 : 0=not initialized, 10 to 26 attribute ids, 9 remove
        subcategory = 0x56,

        -- @description: selected equipment id
        -- @values: 0 nothing, equipment id (2 bytes)
        equipmentId = 0x57,

        -- @description: selected upgrade tier
        -- @values: 0 nothing, 1-3 tier levels
        tier = 0x5A
    },

    obtained = {

        -- @description: default attribute value before upgrade
        -- @values: 0 nothing, value (2 bytes)
        initial = 0x5B,

        -- @description: extra value provided by upgrade
        --- @values: 0 nothing, value (2 bytes)
        extra = 0x5D,

        -- @description: total calculated value ( (initial + extra) or (initial - extra))
        --- @values: 0 nothing, value (2 bytes)
        total = 0x5F,

        -- @description: tier 1 upgrade value
        -- @values: value (2 bytes)
        tier1 = 0x61,

        -- @description: tier 2 upgrade value
        -- @values: value (2 bytes)
        tier2 = 0x63,

        -- @description: tier 3 upgrade value
        -- @values: value (2 bytes)
        tier3 = 0x65,

        -- @description: current element on equipment
        -- @values: 0 nothing, 1 to 8 element ids
        currentElement = 0x4F,

        -- @description: Current attribute on equipment
        -- @values: 0 nothing, 10 to 26 attribute ids
        currentAttribute = 0x4C
    },

    equipments = {

        -- @description: upgrades materials
        -- @values: 0 nothing, 3 item ids (2 bytes each), 3 qty (1 byte each), 3 gil values (2 bytes each)
        upgrades = 0x67,

        -- @description: equipment list
        -- @values: 0 nothing, 31 ids (2 bytes each)
        list = 0x76
    }
}

-- =================
-- modules
-- =================
local config = {
    paths = {
        equipment = "scripts/config/TheArchadianAlchemist/equipment.lua",
        attribute = "scripts/config/TheArchadianAlchemist/attribute.lua",
        element = "scripts/config/TheArchadianAlchemist/element.lua",
        directory = "scripts/config/TheArchadianAlchemist/*.lua"
    }
}
local valid = {}
local mem = {}
local flags = {}
local equipment = {
    state = {},
    definitions = {
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
    }
}
local attribute = {
    definitions = {
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
    }
}
local element = {
    definitions = {
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
local flow = {
    events = {
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
    intervals = {
        idle = 3000,
        talk = 300,
        sync = 16
    }
}
local controller = {
    targetLocation = 642,
    locationId = -1,
    valid = false,
    running = false,
    pollId = 0
}
local loader = {}
local handlers = {}

-- =================
-- valid
-- =================

-- @description: validate equipment id
function valid:equipment(id)
    return id and id > 0
end

-- @description: validate attribute id
function valid:attribute(id)
    return id and id >= 10 and id <= 26
end

-- @description: validade element id
function valid:element(id)
    return id and id >= 1 and id <= 8
end

-- @description: validade tier id
function valid:tier(id)
    return id and id >= 1 and id <= 3
end

-- @description: validate category id
function valid:category(id)
    return id and id ~= 0
end

-- @description: check if subcategory id is removal
function valid:removal(id)
    return id == 9
end

-- @description: validate addresses object has selected
-- @params: addr table
function valid:addresses(addresses)
    return addresses and addresses.selected
end

-- @description: validate config specific key
-- @params: table, key string
function valid:config(config, key)
    return config and config[key]
end

-- =================
-- config
-- =================

-- @description: load external config file
-- @params: path, file name
function config:external(path, name)
    local chunk, err = loadfile(path, "t", setmetatable({}, {
        __index = _G
    }))

    if not chunk then
        print(string.format("TheArchadianAlchemist: Failed to load %s: %s", name, err))
        return nil
    end

    local ok, result = pcall(chunk)
    if not ok then
        print(string.format("TheArchadianAlchemist: Failed to execute %s: %s", name, result))
        return nil
    end

    return result
end

-- @description: build lookup tables for name to id conversion
function config:lookup()
    local categoryNameToId = {}
    for categoryId, categoryNames in pairs(equipment.definitions) do
        categoryNameToId[categoryNames[1]] = categoryId
    end

    local attributeNameToId = {}
    for attributeId, attrData in pairs(attribute.definitions) do
        attributeNameToId[attrData[1]] = attributeId
    end

    local elementNameToId = {}
    for elementId, elementName in pairs(element.definitions) do
        elementNameToId[elementName] = elementId
    end

    return categoryNameToId, attributeNameToId, elementNameToId
end

-- @description: parse equipment config by category name to id
function config:equipment(rawEquipment, categoryNameToId)
    local parsed = {}
    for categoryName, equipmentList in pairs(rawEquipment or {}) do
        local categoryId = categoryNameToId[categoryName]
        if categoryId then
            parsed[categoryId] = equipmentList
        end
    end
    return parsed
end

-- @description: parse element config by element name to id
function config:element(rawElements, elementNameToId)
    local parsed = {}
    for elementName, upgrades in pairs(rawElements.upgrades or {}) do
        local elementId = elementNameToId[elementName]
        if elementId then
            parsed[elementId] = {
                upgrades = upgrades
            }
        elseif elementName == "remove" then
            parsed[9] = {
                upgrades = upgrades
            }
        end
    end
    return parsed
end

-- @description: parse attribute upgrades config by attribute name to id
function config:attribute(rawUpgrades, attributeNameToId)
    local parsed = {}
    for attributeName, upgrades in pairs(rawUpgrades or {}) do
        local attributeId = attributeNameToId[attributeName]
        if attributeId then
            parsed[attributeId] = parsed[attributeId] or {}
            parsed[attributeId].upgrades = upgrades
        elseif attributeName == "remove" then
            parsed[9] = parsed[9] or {}
            parsed[9].upgrades = upgrades
        end
    end
    return parsed
end

-- @description: parse attribute tier values by category and attribute name to id
function config:value(rawValues, categoryNameToId, attributeNameToId, rawUpgrades)
    local parsed = {}
    for categoryName, categoryAttributes in pairs(rawValues or {}) do
        local categoryId = categoryNameToId[categoryName]
        if categoryId then
            for attributeName, tierValues in pairs(categoryAttributes) do
                local attributeId = attributeNameToId[attributeName]
                if attributeId then
                    parsed[attributeId] = parsed[attributeId] or {}
                    parsed[attributeId][categoryId] = {}
                    for tier = 1, 3 do
                        if tierValues[tier] then
                            parsed[attributeId][categoryId][tier] = {
                                value = tierValues[tier],
                                upgrades = rawUpgrades and rawUpgrades[attributeName] and rawUpgrades[attributeName][tier]
                            }
                        end
                    end
                    -- fallback to global tier values if no category-specific values
                    if not parsed[attributeId][1] then
                        for tier = 1, 3 do
                            if tierValues[tier] then
                                parsed[attributeId][tier] = {
                                    value = tierValues[tier],
                                    upgrades = rawUpgrades and rawUpgrades[attributeName] and rawUpgrades[attributeName][tier]
                                }
                            end
                        end
                    end
                end
            end
        end
    end
    return parsed
end

-- @description: parse all config files and convert names to ids
function config:parse(rawConfig)
    local categoryNameToId, attributeNameToId, elementNameToId = self:lookup()

    local parsedAttributes = self:attribute(rawConfig.attributes.upgrades, attributeNameToId)
    local attributeValues = self:value(rawConfig.attributes.values, categoryNameToId, attributeNameToId, rawConfig.attributes.upgrades)

    -- merge attribute values into parsed attributes
    for attributeId, values in pairs(attributeValues) do
        parsedAttributes[attributeId] = parsedAttributes[attributeId] or {}
        for key, val in pairs(values) do
            parsedAttributes[attributeId][key] = val
        end
    end

    return {
        equipment = self:equipment(rawConfig.equipment, categoryNameToId),
        attributes = parsedAttributes,
        elements = self:element(rawConfig.elements, elementNameToId)
    }
end

-- @description: load and parse all config files
function config:load()
    local equipmentConfig = self:external(self.paths.equipment, "equipment") or {}
    local attributeConfig = self:external(self.paths.attribute, "attribute") or {}
    local elementConfig = self:external(self.paths.element, "element") or {}

    local rawConfig = {
        equipment = equipmentConfig,
        attributes = attributeConfig,
        elements = elementConfig
    }

    self.data = self:parse(rawConfig)
end

-- =================
-- memory
-- =================

function mem:read(base, offset, size)
    local address = base + offset

    if size == 1 then
        return memory.u8[address]
    elseif size == 2 then
        return memory.u16[address]
    elseif size == 4 then
        return memory.u32[address]
    end
end

function mem:write(base, offset, value, size)
    local address = base + offset

    if size == 1 then
        memory.u8[address] = value
    elseif size == 2 then
        memory.u16[address] = value
    elseif size == 4 then
        memory.u32[address] = value
    end
end

function mem:clear(base, offset, length)
    for i = 0, length - 1 do
        self:write(base, offset + i, 0, 1)
    end
end

-- =================
-- flags
-- =================

-- @description: get flag value
-- @params: base addr, offset
function flags:get(base, offset)
    return mem:read(base, offset, 1)
end

-- @description: set flag value
-- @params: base addr, offset, value
function flags:set(base, offset, value)
    mem:write(base, offset, value, 1)
end

-- @description: clear flag
-- @params: base addr, offset
function flags:clear(base, offset)
    mem:write(base, offset, 0, 1)
end

-- =================
-- equipment
-- =================

-- @description: get equipment from bpack
function equipment:get(id)
    local idx = id - 4096
    return bpack.section13[idx]
end

-- @description: read value from equipment
-- @params: equipment id, key "element" or "attribute", 1 to 8 element ids or 10 to 26 attribute ids
function equipment:read(id, key, subid)
    local eq = self:get(id)
    if not eq then
        return nil
    end

    -- read element from equipment
    if key == "element" then
        local name = element.definitions[subid]
        if not name then
            return nil
        end
        return eq.elements and eq.elements[name] or 0
        -- read attribute from equipment
    elseif key == "attribute" then
        local attr = attribute.definitions[subid]
        if not attr then
            return nil
        end
        local name, typ, offset = attr[1], attr[2], attr[3]

        -- check for attribute type
        if typ == "direct" then
            return eq[name] or 0
        elseif typ == "linked" and eq.attributePointer then
            local addr = eq.attributePointer + offset
            if name == "maxHp" or name == "maxMp" then
                return memory.u16[addr] or 0
            else
                return memory.u8[addr] or 0
            end
        elseif typ == "linked" and not eq.attributePointer then
            return nil
        end
    end

    return nil
end

-- @description: write value to equipment
-- @params: equipment id, key "element" or "attribute", 1 to 8 element ids or 10 to 26 attribute ids, value
function equipment:write(id, key, subid, value)
    local eq = self:get(id)
    if not eq then
        return false
    end

    -- write element to equipment
    if key == "element" then
        local name = element.definitions[subid]
        if not name then
            return false
        end
        eq.elements[name] = value
        return true
        -- write attribute to equipment
    elseif key == "attribute" then
        local attr = attribute.definitions[subid]
        if not attr then
            return false
        end
        local name, typ, offset = attr[1], attr[2], attr[3]
        -- check for attribute type
        if typ == "direct" then
            eq[name] = value
        elseif typ == "linked" and eq.attributePointer then
            local addr = eq.attributePointer + offset
            if name == "maxHp" or name == "maxMp" then
                memory.u16[addr] = value
            else
                memory.u8[addr] = value
            end
        end
        return true
    end
end

-- @description: update equipment state
-- @params: equipment id, key "element" or "attributes", value
function equipment:update(id, key, value)
    if not self.state[id] then
        self.state[id] = {}
    end

    if value == nil then
        self.state[id][key] = nil
    else
        self.state[id][key] = value
    end
end

-- =================
-- attribute
-- =================

-- @description: get current attribute refinement from equipment.state
-- @params: base addr, addresses table
function attribute:get(base, addresses)
    local equipmentId = mem:read(base, addresses.selected.equipmentId, 2)

    if not valid:equipment(equipmentId) then
        return nil
    end

    -- get attribute refinement from equipment state
    local state = equipment.state[equipmentId]

    if state and state.attributes then
        return state.attributes
    end

    return nil
end

-- @description: apply attribute upgrade to equipment
-- @params: base addr, addresses table, tier id, config table
function attribute:set(base, addresses, tier, config)
    if not valid:addresses(addresses) then
        return false
    end

    local attributeId = flags:get(base, addresses.selected.subcategory)
    local equipmentId = mem:read(base, addresses.selected.equipmentId, 2)
    local categoryId = flags:get(base, addresses.selected.category)

    if not valid:equipment(equipmentId) then
        return false
    end

    if not valid:attribute(attributeId) then
        return false
    end

    if not valid:tier(tier) then
        return false
    end

    -- get attribute data from config
    local attrData = config and config.attributes and config.attributes[attributeId]
    if not attrData then
        return false
    end

    -- get tier data from category
    local categoryData = categoryId and attrData[categoryId]
    local tierData = nil

    if categoryData then
        tierData = categoryData[tier]
    else
        tierData = attrData[tier]
    end

    if not tierData then
        return false
    end

    local extraValue = tierData.value or 0

    local state = equipment.state[equipmentId]
    local stateAttributes = state and state.attributes or nil

    -- restore previous attribute if different from current
    if stateAttributes and stateAttributes.id and stateAttributes.id ~= attributeId then
        local existingAttrId = stateAttributes.id
        local existingInitial = stateAttributes.initial
        equipment:write(equipmentId, "attribute", existingAttrId, existingInitial)
    end

    -- get initial value from state or equipment
    local initial = 0
    if stateAttributes and stateAttributes.id == attributeId then
        initial = stateAttributes.initial
    else
        initial = equipment:read(equipmentId, "attribute", attributeId) or 0
    end

    -- calculate total
    local total = 0
    if attributeId == 11 then
        -- if chargeTime, subtract extra value
        total = initial - extraValue
    else
        -- all other, sum extra value
        total = initial + extraValue
    end

    -- apply attribute to equipment
    equipment:write(equipmentId, "attribute", attributeId, total)

    -- update attribute state
    local refinementData = {
        id = attributeId,
        initial = initial,
        extra = extraValue,
        total = total,
        tier = tier
    }
    equipment:update(equipmentId, "attributes", refinementData)

    return true
end

-- @description: remove attribute refinement from equipment, restore original value
-- @params: base addr, addresses table
function attribute:remove(base, addresses)
    local equipmentId = mem:read(base, addresses.selected.equipmentId, 2)
    if not valid:equipment(equipmentId) then
        return false
    end

    local state = equipment.state[equipmentId]
    if not state or not state.attributes then
        return true
    end

    -- restore original attribute value from state
    local initial = state.attributes.initial
    local existingAttrId = state.attributes.id
    local attrDef = attribute.definitions[existingAttrId]

    if attrDef and initial ~= nil then
        equipment:write(equipmentId, "attribute", existingAttrId, initial)
    end

    -- clear attribute state
    equipment:update(equipmentId, "attributes", nil)

    return true
end

-- @description: apply or remove attribute based on subcategory flag
-- @params: base addr, addresses table, config table
function attribute:apply(base, addresses, config)
    local selected = {
        success = flags:get(base, addresses.flow.success),
        subcategory = flags:get(base, addresses.selected.subcategory),
        tier = flags:get(base, addresses.selected.tier),
        equipmentId = mem:read(base, addresses.selected.equipmentId, 2)
    }

    -- ignore if not success
    if selected.success ~= 1 then
        return false
    end

    -- remove attribute or apply attribute based on subcategory
    if valid:removal(selected.subcategory) then
        attribute:remove(base, addresses)
    else
        if valid:tier(selected.tier) then
            attribute:set(base, addresses, selected.tier, config)

            -- write refinement results to flags
            local refinement = attribute:get(base, addresses)
            loader:results(base, addresses.obtained, refinement)
        end
    end

    -- clear success flag
    flags:set(base, addresses.flow.success, 0)
    return true
end

-- =================
-- element
-- =================

-- @description: get current active element from equipment
-- @params: base addr, addresses table
function element:get(base, addresses)
    local equipmentId = mem:read(base, addresses.selected.equipmentId, 2)
    if not valid:equipment(equipmentId) then
        return 0
    end

    -- check which element is active
    local eq = equipment:get(equipmentId)
    if eq and eq.elements then
        for id = 1, 8 do
            local name = element.definitions[id]
            if eq.elements[name] == 1 then
                return id
            end
        end
    end

    return 0
end

-- @description: write element id into obtained flag
-- @params: base addr, addresses table, element id
function element:write(base, addresses, elementId)
    flags:set(base, addresses.currentElement, elementId or 0)
end

-- @description: apply element to equipment, clear all elements first
-- @params: base addr, addresses table, element id
function element:set(base, addresses, elementId)
    if not valid:element(elementId) then
        return false
    end

    local equipmentId = mem:read(base, addresses.selected.equipmentId, 2)
    if not valid:equipment(equipmentId) then
        return false
    end

    -- clear all elements first
    for id = 1, 8 do
        equipment:write(equipmentId, "element", id, 0)
    end

    -- apply selected element
    equipment:write(equipmentId, "element", elementId, 1)

    -- update element state
    equipment:update(equipmentId, "element", {
        id = elementId
    })

    return true
end

-- @description: remove element from equipment, clear all elements
-- @params: base addr, addresses table
function element:remove(base, addresses)
    local equipmentId = mem:read(base, addresses.selected.equipmentId, 2)
    if not valid:equipment(equipmentId) then
        return false
    end

    -- clear all elements from equipment
    for id = 1, 8 do
        equipment:write(equipmentId, "element", id, 0)
    end

    -- clear element state
    equipment:update(equipmentId, "element", nil)

    return true
end

-- @description: apply or remove element based on subcategory flag
-- @params: base addr, addresses table
function element:apply(base, addresses)
    local selected = {
        success = flags:get(base, addresses.flow.success),
        subcategory = flags:get(base, addresses.selected.subcategory),
        equipmentId = mem:read(base, addresses.selected.equipmentId, 2)
    }

    -- ignore if not success
    if selected.success ~= 1 then
        return false
    end

    -- remove element or apply element based on subcategory
    if valid:removal(selected.subcategory) then
        element:remove(base, addresses)
    else
        element:set(base, addresses, selected.subcategory)
    end

    -- clear success flag
    flags:set(base, addresses.flow.success, 0)
    return true
end

-- =================
-- flow
-- =================

-- @description: resolve polling interval based on pollMode flag
-- @params: base addr, addresses table

flow.lastPollMode = flow.lastPollMode or -1

function flow:interval(base, addresses)
    local mode = flags:get(base, addresses.flow.pollMode)

    -- @debug
    if mode ~= self.lastPollMode then
        if mode == 2 then
            print(string.format("[flow:interval] sync %d", self.intervals.sync))
        elseif mode == 1 then
            print(string.format("[flow:interval] talk %d", self.intervals.talk))
        else
            print(string.format("[flow:interval] idle %d", self.intervals.idle))
        end

        self.lastPollMode = mode
    end

    -- sync interval (get lists from memory)
    if mode == 2 then
        return self.intervals.sync
    end

    -- talk interval
    if mode == 1 then
        return self.intervals.talk
    end

    -- idle interval
    return self.intervals.idle
end

-- @description: poll flow flags and decide current logical event
-- @params: base addr, addresses table
function flow:poll(base, addresses)
    -- reset flow state
    if flags:get(base, addresses.flow.reset) == 1 then
        flags:clear(base, addresses.flow.reset)
        flags:set(base, addresses.flow.pollMode, 2)
        return self.events.reset
    end

    -- result event (success, insufficient materials, etc)
    if flags:get(base, addresses.flow.success) ~= 0 then
        flags:set(base, addresses.flow.pollMode, 1)
        return self.events.result
    end

    -- load equipment list
    if flags:get(base, addresses.flow.loadEquipment) == 1 then
        flags:set(base, addresses.flow.pollMode, 2)
        return self.events.loadEquipment
    end

    -- equipment selected
    if flags:get(base, addresses.flow.selected) == 1 then
        flags:set(base, addresses.flow.pollMode, 2)
        return self.events.equipmentSelected
    end

    -- check current element
    if flags:get(base, addresses.flow.checkElement) == 1 then
        flags:set(base, addresses.flow.pollMode, 2)
        return self.events.checkElement
    end

    -- check current attribute
    if flags:get(base, addresses.flow.checkAttribute) == 1 then
        flags:set(base, addresses.flow.pollMode, 2)
        return self.events.checkAttribute
    end

    local status = flags:get(base, addresses.flow.status)

    -- conversation started
    if status == 1 then
        flags:set(base, addresses.flow.pollMode, 1)
        return self.events.talk
    end

    -- element flow
    if status == 2 then
        flags:set(base, addresses.flow.pollMode, 2)
        return self.events.element
    end

    -- attribute flow
    if status == 3 then
        flags:set(base, addresses.flow.pollMode, 2)
        return self.events.attribute
    end

    -- get current poll mode
    flags:set(base, addresses.flow.pollMode, 0)
    return nil
end

-- @description: initialize flow state when controller starts
-- @params: base addr, addresses table
function flow:load(base, addresses)
    -- clear flow flags
    flags:clear(base, addresses.flow.status)
    flags:clear(base, addresses.flow.selected)
    flags:clear(base, addresses.flow.success)
    flags:clear(base, addresses.flow.reset)
    flags:clear(base, addresses.flow.loadEquipment)
    flags:clear(base, addresses.flow.checkElement)
    flags:clear(base, addresses.flow.checkAttribute)

    -- clear selection flags
    flags:clear(base, addresses.selected.category)
    flags:clear(base, addresses.selected.subcategory)
    flags:clear(base, addresses.selected.tier)
    mem:write(base, addresses.selected.equipmentId, 0, 2)

    -- set poll to idle
    flags:set(base, addresses.flow.pollMode, 0)
end

-- =================
-- controller
-- =================

-- @description: start controller execution
function controller:start()
    -- ignore if running
    if self.running then
        return
    end

    -- start controller and create new poll
    self.running = true
    self.pollId = self.pollId + 1
    local currentPoll = self.pollId

    -- initialize flow
    flow:load(addresses.base, addresses)

    -- schedule poll
    self:schedule(currentPoll)
end

-- @description: stop controller execution
function controller:stop()
    -- ignore if stopped
    if not self.running then
        return
    end

    -- stop controller and cancel current poll
    self.running = false
    self.pollId = self.pollId + 1

    -- reset flow
    flow:load(addresses.base, addresses)
end

-- @description: schedule next poll based on flow interval
-- @params: poll id
function controller:schedule(pollId)
    -- ignore if poll id doesnt match
    if pollId ~= self.pollId then
        return
    end

    -- get polling interval based on current flow
    local interval = flow:interval(addresses.base, addresses)

    -- define polling interval and schedule next poll
    event.executeAfterMs(interval, function()
        self:poll(pollId)
    end)
end

-- @description: single poll execution
-- @params: poll id
function controller:poll(pollId)
    -- ignore if poll id doesnt match
    if pollId ~= self.pollId then
        return
    end

    -- ignore if controller not running or invalid location
    if not self.running or not self.valid then
        return
    end

    -- poll flow flags and dispatch event if any
    local event = flow:poll(addresses.base, addresses)
    if event then
        self:dispatch(event, addresses.base, addresses, config)
    end

    -- schedule next poll
    self:schedule(pollId)
end

-- @description: dispatch actions based on flow event
-- @params: event string, base addr, addresses table, config table
function controller:dispatch(event, base, addresses, config)

    -- reset flow state
    if event == flow.events.reset then
        self:reset(base, addresses)
        return
    end

    -- load equipment list into memory
    if event == flow.events.loadEquipment then
        loader:dispatch(base, addresses, config.data)
        flags:clear(base, addresses.flow.loadEquipment)
        flags:set(base, addresses.flow.pollMode, 1)
        return
    end

    -- clear equipment selection flag
    if event == flow.events.equipmentSelected then
        flags:clear(base, addresses.flow.selected)
        return
    end

    -- check current element and write to obtained flag
    if event == flow.events.checkElement then
        local current = element:get(base, addresses)
        element:write(base, addresses.obtained, current)
        flags:clear(base, addresses.flow.checkElement)
        return
    end

    -- check current attribute and write to obtained flags
    if event == flow.events.checkAttribute then
        local refinement = attribute:get(base, addresses)
        loader:results(base, addresses.obtained, refinement)
        flags:clear(base, addresses.flow.checkAttribute)
        return
    end

    -- apply element or attribute based on flow status
    if event == flow.events.result then
        local flowStatus = flags:get(base, addresses.flow.status)

        if flowStatus == 2 then
            element:apply(base, addresses)
        elseif flowStatus == 3 then
            attribute:apply(base, addresses, config.data)
        end

        return
    end
end

-- @description: reset flow and internal state
-- @params: base addr, addresses table
function controller:reset(base, addresses)
    flow:load(base, addresses)
end

-- @description: handle location change and enable or disable the mod
-- @params: location id
function controller:location(locationId)
    self.locationId = locationId

    if locationId == controller.targetLocation then
        print(string.format("[controller:location] valid %d", locationId))
        self.valid = true
        self:start()
    else
        print(string.format("[controller:location] invalid %d", locationId))
        self.valid = false
        self:stop()
    end
end

-- =================
-- loader
-- =================

-- @description: coordinate loading of equipment, upgrades, or tier values
-- @params: base addr, addresses table, config table
function loader:dispatch(base, addresses, config)
    local flowStatus = flags:get(base, addresses.flow.status)
    local categoryId = flags:get(base, addresses.selected.category)
    local subcategoryId = flags:get(base, addresses.selected.subcategory)
    local tierId = flags:get(base, addresses.selected.tier)

    -- load upgrade materials for attribute tier selection
    if flowStatus == 3 and valid:tier(tierId) then
        loader:upgrade(base, addresses.equipments.upgrades, subcategoryId, tierId, categoryId, config, flowStatus)

        -- load tier values for attribute selection, skip if removal
    elseif flowStatus == 3 and subcategoryId and (valid:removal(subcategoryId) or valid:attribute(subcategoryId)) then
        if valid:removal(subcategoryId) then
            -- load upgrade materials for attribute removal
            loader:upgrade(base, addresses.equipments.upgrades, subcategoryId, nil, categoryId, config, flowStatus)
        else
            loader:tier(base, addresses.obtained, subcategoryId, categoryId, config)
        end

        -- load upgrade materials for element selection
    elseif flowStatus == 2 and subcategoryId and (valid:element(subcategoryId) or valid:removal(subcategoryId)) then
        loader:upgrade(base, addresses.equipments.upgrades, subcategoryId, nil, categoryId, config, flowStatus)

        -- load equipment list for category selection
    elseif valid:category(categoryId) then
        loader:equipment(base, addresses.equipments.list, categoryId, config)
    end

    return true
end

-- @description: load equipment list into memory buffer
-- @params: base addr, offset, category id, config table
function loader:equipment(base, offset, categoryId, config)
    if not valid:config(config, "equipment") then
        return false
    end

    print(string.format("[loader:equipment] categoryId %d", categoryId))

    local equipmentList = config.equipment[categoryId]
    if not equipmentList then
        return false
    end

    -- clear memory
    mem:clear(base, offset, 62)

    -- write equipment ids to memory
    local memOffset = 0
    for i, equipmentId in ipairs(equipmentList) do
        if i > 31 then
            break
        end
        mem:write(base, offset + memOffset, equipmentId, 2)
        memOffset = memOffset + 2
    end

    return true
end

-- @description: load upgrade materials into memory buffer
-- @params: base addr, offset, subcategory id, tier id, category id, config table, flowStatus (optional)
function loader:upgrade(base, offset, subcategoryId, tierId, categoryId, config, flowStatus)
    if not config then
        return false
    end

    print(string.format("[loader:upgrade] subcategoryId %d, tierId %d, categoryId %d, flowStatus %d", subcategoryId, tierId or 0,
        categoryId or 0, flowStatus or 0))

    local upgrades = nil
    if subcategoryId == 9 then
        -- get upgrades for removal (differentiate between element and attribute removal by flowStatus)
        if flowStatus == 2 then
            -- element removal
            local elemData = config.elements and config.elements[9]
            upgrades = elemData and elemData.upgrades
        elseif flowStatus == 3 then
            -- attribute removal
            local attrData = config.attributes and config.attributes[9]
            upgrades = attrData and (attrData[categoryId] and attrData[categoryId].upgrades or attrData.upgrades)
        end
    elseif valid:tier(tierId) and categoryId then
        -- get upgrades for attribute tier
        local attrData = config.attributes and config.attributes[subcategoryId]
        upgrades = attrData and ((attrData[categoryId] and attrData[categoryId][tierId] or attrData[tierId]) and
                       (attrData[categoryId] and attrData[categoryId][tierId] or attrData[tierId]).upgrades)
    else
        -- get upgrades for element
        upgrades = config.elements and config.elements[subcategoryId] and config.elements[subcategoryId].upgrades
    end

    if not upgrades then
        return false
    end

    -- clear memory
    mem:clear(base, offset, 15)

    -- write item ids and quantities and gil to memory
    local idOffset, qtyOffset, gilOffset = 0, 6, 9
    local gilValue = upgrades[4] or 0
    for i = 1, 3 do
        local item = upgrades[i]
        if item then
            mem:write(base, offset + idOffset, item[1] or item.id, 2)
            mem:write(base, offset + qtyOffset, item[2] or item.qtt, 1)
        end
        mem:write(base, offset + gilOffset, gilValue, 2)
        idOffset = idOffset + 2
        qtyOffset = qtyOffset + 1
        gilOffset = gilOffset + 2
    end

    return true
end

-- @description: load tier values into flags
-- @params: base addr, addresses table, attribute id, category id, config table
function loader:tier(base, addresses, attributeId, categoryId, config)
    if not valid:config(config, "attributes") then
        return false
    end

    print(string.format("[loader:tier] attributeId %d, categoryId %d", attributeId, categoryId))

    local attr = config.attributes[attributeId]
    if not attr then
        return false
    end

    local categoryData = categoryId and attr[categoryId]
    local tier1, tier2, tier3 = 0, 0, 0

    -- get tier values from category
    if categoryData then
        tier1 = categoryData[1] and categoryData[1].value or 0
        tier2 = categoryData[2] and categoryData[2].value or 0
        tier3 = categoryData[3] and categoryData[3].value or 0
    else
        tier1 = attr[1] and attr[1].value or 0
        tier2 = attr[2] and attr[2].value or 0
        tier3 = attr[3] and attr[3].value or 0
    end

    -- write tier values to flags
    mem:write(base, addresses.tier1, tier1, 2)
    mem:write(base, addresses.tier2, tier2, 2)
    mem:write(base, addresses.tier3, tier3, 2)

    return true
end

-- @description: load attribute refinement results into obtained flags
-- @params: base addr, addresses table, refinement table
function loader:results(base, addresses, refinement)
    -- write refinement values to flags
    if refinement then
        mem:write(base, addresses.currentAttribute, refinement.id, 1)
        mem:write(base, addresses.initial, refinement.initial, 2)
        mem:write(base, addresses.extra, refinement.extra or 0, 2)
        mem:write(base, addresses.total, refinement.total, 2)
        -- clear flags if no refinement
    else
        mem:write(base, addresses.currentAttribute, 0, 1)
        mem:write(base, addresses.initial, 0, 2)
        mem:write(base, addresses.extra, 0, 2)
        mem:write(base, addresses.total, 0, 2)
    end
end

-- =================
-- handlers
-- =================

function handlers:onFileChange(filepath, stats, created, deleted)
    if deleted then
        return
    end

    print(string.format("[handlers:onFileChange] file reloaded %s", filepath))

    config:load()
end

function handlers:onSave()
    return equipment.state
end

function handlers:onLoad(filepath, savedData)
    equipment.state = equipment.state or {}

    if savedData and type(savedData) == "table" then
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

        for equipmentId, state in pairs(equipment.state) do
            if state.element and state.element.id then
                local elementId = state.element.id
                if valid:element(elementId) then
                    for id = 1, 8 do
                        equipment:write(equipmentId, "element", id, 0)
                    end
                    equipment:write(equipmentId, "element", elementId, 1)
                end
            end

            if state.attributes and state.attributes.id then
                local attributeId = state.attributes.id
                local total = state.attributes.total
                if valid:attribute(attributeId) and total then
                    equipment:write(equipmentId, "attribute", attributeId, total)
                end
            end
        end
    end
end

-- =================
-- initialize
-- =================

event.registerEventAsync("onInitDone", function()
    config:load()
end)

event.registerFileChangeHandler(config.paths.directory, function(filepath, stats, created, deleted)
    handlers:onFileChange(filepath, stats, created, deleted)
end)

event.registerSaveHandler("TheArchadianAlchemist", function(filepath)
    return handlers:onSave()
end)

event.registerLoadHandler("TheArchadianAlchemist", function(filepath, savedData)
    handlers:onLoad(filepath, savedData)
end)

event.registerEventAsync("onSaveLoad", function()
    local locationId = mem:read(0, addresses.locationId, 4)
    controller:location(locationId)
end)

event.registerEventAsync("onMapJump", function(locationId)
    controller:location(locationId)
end)
