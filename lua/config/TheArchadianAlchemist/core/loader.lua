-- Made By FehDead
-- =====================
-- LOADER MODULE
-- =====================
-- Load data into game memory buffers
local loader = {}

-- =====================
-- CACHE DE FUNÇÕES GLOBAIS
-- =====================
local mathMin = math.min
local ipairs = ipairs

-- =====================
-- DEPENDÊNCIAS
-- =====================
local mem
local helpers
local mappings

-- =====================
-- FLAG DE INICIALIZAÇÃO
-- =====================
local isInitialized = false

-- =====================
-- CACHED REFERENCES
-- =====================
local addresses
local constants

-- =====================
-- UPGRADE MEMORY LAYOUT
-- =====================
--[[
    Memory layout for upgrades (15 bytes total):
    Offset 0-1:   Item 1 ID (u16)
    Offset 2-3:   Item 2 ID (u16)
    Offset 4-5:   Item 3 ID (u16)
    Offset 6:     Item 1 Qty (u8)
    Offset 7:     Item 2 Qty (u8)
    Offset 8:     Item 3 Qty (u8)
    Offset 9-10:  Gil value 1 (u16)
    Offset 11-12: Gil value 2 (u16)
    Offset 13-14: Gil value 3 (u16)
]]

local UPGRADE_OFFSETS = {
    id = {0, 2, 4},
    qty = {6, 7, 8},
    gil = {9, 11, 13}
}

-- =====================
-- DISPATCH
-- =====================

-- @description: coordinate loading of equipment, upgrades, or tier values
-- @params: base, addrs, config
-- @returns: boolean
function loader.dispatch(base, addrs, config)
    if not config then
        return false
    end

    local flowStatus = mem.flags.get(base, addrs.flow.status)
    local categoryId = mem.flags.get(base, addrs.selected.category)
    local subcategoryId = mem.flags.get(base, addrs.selected.subcategory)
    local tierId = mem.flags.get(base, addrs.selected.tier)

    -- Clear tier values for attribute mode
    if flowStatus == 3 then
        mem.writeU16(base, addrs.obtained.tier1, 0)
        mem.writeU16(base, addrs.obtained.tier2, 0)
        mem.writeU16(base, addrs.obtained.tier3, 0)
    end

    -- Load equipment list if category selected
    if categoryId and categoryId ~= 0 then
        loader.equipment(base, addrs.equipments.list, categoryId, config)
    end

    -- Load upgrades or tier values based on flow status
    if flowStatus == 3 then
        -- Attribute mode
        if helpers.validateRange(tierId, constants.tierMin, constants.tierMax) then
            loader.upgrade(base, addrs.equipments.upgrades, subcategoryId, tierId, categoryId, config, flowStatus)
        elseif subcategoryId then
            if subcategoryId == constants.removeId then
                loader.upgrade(base, addrs.equipments.upgrades, subcategoryId, nil, categoryId, config, flowStatus)
            elseif helpers.validateRange(subcategoryId, constants.attributeMin, constants.attributeMax) then
                loader.tier(base, addrs.obtained, subcategoryId, categoryId, config)
            end
        end
    elseif flowStatus == 2 then
        -- Element mode
        if subcategoryId then
            if helpers.validateRange(subcategoryId, constants.elementMin, constants.elementMax) or subcategoryId == constants.removeId then
                loader.upgrade(base, addrs.equipments.upgrades, subcategoryId, nil, categoryId, config, flowStatus)
            end
        end
    end

    return true
end

-- =====================
-- EQUIPMENT LOADING
-- =====================

-- @description: load equipment list into memory buffer
-- @params: base, offset, categoryId, config
-- @returns: boolean
function loader.equipment(base, offset, categoryId, config)
    if not helpers.hasConfig(config, "equipment") then
        return false
    end

    local equipmentList = config.equipment[categoryId]
    if not equipmentList then
        return false
    end

    local baseAddr = base + offset

    -- Clear buffer (62 bytes = 31 equipment slots * 2 bytes)
    mem.clear(base, offset, 62)

    -- Write equipment IDs
    local maxItems = mathMin(#equipmentList, 31)
    for i = 1, maxItems do
        mem.writeU16(baseAddr + ((i - 1) * 2), nil, equipmentList[i])
    end

    return true
end

-- =====================
-- UPGRADE LOADING
-- =====================

-- @description: load upgrade materials into memory buffer
-- @params: base, offset, subcategoryId, tierId, categoryId, config, flowStatus
-- @returns: boolean
function loader.upgrade(base, offset, subcategoryId, tierId, categoryId, config, flowStatus)
    if not config then
        return false
    end

    -- Validate category for attribute mode
    if flowStatus == 3 and (not categoryId or categoryId == 0) then
        return false
    end

    local upgrades, gilValue = loader._getUpgradeData(subcategoryId, tierId, categoryId, config, flowStatus)

    if not upgrades or not loader.validateUpgrades(upgrades) then
        return false
    end

    -- Clear buffer
    mem.clear(base, offset, 15)

    local baseAddr = base + offset

    -- Write upgrade data
    for i = 1, 3 do
        local item = upgrades[i]
        if item then
            mem.writeU16(baseAddr + UPGRADE_OFFSETS.id[i], nil, helpers.getItemId(item))
            mem.writeU8(baseAddr + UPGRADE_OFFSETS.qty[i], nil, helpers.getItemQty(item))
        end
        mem.writeU16(baseAddr + UPGRADE_OFFSETS.gil[i], nil, gilValue)
    end

    return true
end

-- @description: get upgrade data based on parameters (private)
-- @returns: upgrades (table), gilValue (number)
function loader._getUpgradeData(subcategoryId, tierId, categoryId, config, flowStatus)
    local upgrades = nil
    local gilValue = 0

    if subcategoryId == constants.removeId then
        -- Remove operation
        if flowStatus == 2 then
            -- Element remove (global)
            local elemData = helpers.getNestedValue(config, "elements", 9)
            if elemData then
                upgrades = elemData.items
                gilValue = elemData.gil or 0
            end
        elseif flowStatus == 3 then
            -- Attribute remove (per category)
            local attrData = helpers.getNestedValue(config, "attributes", categoryId, 9)
            if attrData then
                upgrades = attrData.items
                gilValue = attrData.gil or 0
            end
        end
    elseif helpers.validateRange(tierId, constants.tierMin, constants.tierMax) and
        helpers.validateRange(subcategoryId, constants.attributeMin, constants.attributeMax) then
        -- Attribute upgrade
        local tierData = helpers.getNestedValue(config, "attributes", categoryId, subcategoryId, tierId)
        if tierData then
            upgrades = tierData.items
            gilValue = tierData.gil or 0
        end
    elseif helpers.validateRange(subcategoryId, constants.elementMin, constants.elementMax) then
        -- Element upgrade
        local elemData = helpers.getNestedValue(config, "elements", subcategoryId)
        if elemData then
            upgrades = elemData.items
            gilValue = elemData.gil or 0
        end
    end

    return upgrades, gilValue
end

-- =====================
-- TIER LOADING
-- =====================

-- @description: load tier values into flags
-- @params: base, addrs (obtained addresses), attributeId, categoryId, config
-- @returns: boolean
function loader.tier(base, addrs, attributeId, categoryId, config)
    if not helpers.hasConfig(config, "attributes") then
        return false
    end

    local attr = helpers.getNestedValue(config, "attributes", categoryId, attributeId)
    if not attr then
        return false
    end

    local tier1 = loader.getTierValue(attr, 1)
    local tier2 = loader.getTierValue(attr, 2)
    local tier3 = loader.getTierValue(attr, 3)

    mem.writeU16(base, addrs.tier1, tier1)
    mem.writeU16(base, addrs.tier2, tier2)
    mem.writeU16(base, addrs.tier3, tier3)

    return true
end

-- =====================
-- RESULTS LOADING
-- =====================

-- @description: load attribute refinement results into obtained flags
-- @params: base, addrs (obtained addresses), refinement
function loader.results(base, addrs, refinement)
    if refinement then
        mem.writeU8(base, addrs.currentAttribute, refinement.id)
        mem.writeU16(base, addrs.initial, refinement.initial)
        mem.writeU16(base, addrs.extra, refinement.extra or 0)
        mem.writeU16(base, addrs.total, refinement.total)
    else
        mem.writeU8(base, addrs.currentAttribute, 0)
        mem.writeU16(base, addrs.initial, 0)
        mem.writeU16(base, addrs.extra, 0)
        mem.writeU16(base, addrs.total, 0)
    end
end

-- =====================
-- HELPERS
-- =====================

-- @description: get tier value from attribute data
-- @params: attr (attribute data), tier (1-3)
-- @returns: number
function loader.getTierValue(attr, tier)
    if not attr or not helpers.validateRange(tier, constants.tierMin, constants.tierMax) then
        return 0
    end

    local tierData = attr[tier]
    if tierData then
        return tierData.value or 0
    end

    return 0
end

-- @description: validate upgrades array
-- @returns: boolean
function loader.validateUpgrades(upgrades)
    if not helpers.isTable(upgrades) then
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

-- =====================
-- INICIALIZAÇÃO
-- =====================

function loader.initialize(deps)
    if not deps then
        print("ERROR [TAA LOADER] Dependencies not provided")
        return false
    end

    if not deps.memory then
        print("ERROR [TAA LOADER] Memory not provided")
        return false
    end

    if not deps.helpers then
        print("ERROR [TAA LOADER] Helpers not provided")
        return false
    end

    if not deps.mappings then
        print("ERROR [TAA LOADER] Mappings not provided")
        return false
    end

    mem = deps.memory
    helpers = deps.helpers
    mappings = deps.mappings

    -- Cache frequently used references
    addresses = mappings.addresses
    constants = mappings.constants

    isInitialized = true
    print("[TAA LOADER] Module initialized")
    return true
end

-- =====================
-- DEBUG HELPERS
-- =====================

function loader.isReady()
    return isInitialized
end

function loader.getStatus()
    return {
        initialized = isInitialized,
        hasMemory = mem ~= nil,
        hasHelpers = helpers ~= nil,
        hasMappings = mappings ~= nil
    }
end

return loader
