-- Made By FehDead
local loader = {}

local mem
local helpers
local mappings
local addresses
local constants

local UPGRADE_OFFSETS = {
    id = {0, 2, 4},
    qty = {6, 7, 8},
    gil = {9, 11, 13}
}

function loader.dispatch(base, addrs, config)
    if not config then
        return false
    end

    local flowStatus = mem.flags.get(base, addrs.flow.talkStatus)
    local categoryId = mem.flags.get(base, addrs.selected.selectedCategory)
    local subcategoryId = mem.flags.get(base, addrs.selected.selectedSubcategory)
    local tierId = mem.flags.get(base, addrs.selected.selectedTier)

    if flowStatus == 3 then
        mem.writeU16(base, addrs.refinement.tier1AttributeValue, 0)
        mem.writeU16(base, addrs.refinement.tier2AttributeValue, 0)
        mem.writeU16(base, addrs.refinement.tier3AttributeValue, 0)
    end

    if categoryId and categoryId ~= 0 then
        loader.equipment(base, addrs.load.equipmentList, categoryId, config)
    end

    if flowStatus == 3 then
        if helpers.validateRange(tierId, constants.tierMin, constants.tierMax) then
            loader.upgrade(base, addrs.load.upgradeList, subcategoryId, tierId, categoryId, config, flowStatus)
        elseif subcategoryId then
            if subcategoryId == constants.removeId then
                loader.upgrade(base, addrs.load.upgradeList, subcategoryId, nil, categoryId, config, flowStatus)
            elseif helpers.validateRange(subcategoryId, constants.attributeMin, constants.attributeMax) then
                loader.tier(base, addrs, subcategoryId, categoryId, config)
            end
        end
    elseif flowStatus == 2 then

        if subcategoryId then
            if helpers.validateRange(subcategoryId, constants.elementMin, constants.elementMax) or subcategoryId ==
                constants.removeId then
                loader.upgrade(base, addrs.load.upgradeList, subcategoryId, nil, categoryId, config, flowStatus)
            end
        end
    end

    return true
end

function loader.equipment(base, offset, categoryId, config)
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

function loader.upgrade(base, offset, subcategoryId, tierId, categoryId, config, flowStatus)
    if flowStatus == 3 and (not categoryId or categoryId == 0) then
        return false
    end

    local upgrades, gilValue = loader._getUpgradeData(subcategoryId, tierId, categoryId, config, flowStatus)
    if not upgrades or not loader.validateUpgrades(upgrades) then
        return false
    end

    mem.clear(base, offset, 15)

    local baseAddr = base + offset

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

function loader._getUpgradeData(subcategoryId, tierId, categoryId, config, flowStatus)
    local upgrades = nil
    local gilValue = 0

    if subcategoryId == constants.removeId then

        if flowStatus == 2 then
            local elemData = helpers.getNestedValue(config, "elements", 9)

            if elemData then
                upgrades = elemData.items
                gilValue = elemData.gil or 0
            end
        elseif flowStatus == 3 then
            local attrData = helpers.getNestedValue(config, "attributes", categoryId, 9)

            if attrData then
                upgrades = attrData.items
                gilValue = attrData.gil or 0
            end
        end
    elseif helpers.validateRange(tierId, constants.tierMin, constants.tierMax) and
        helpers.validateRange(subcategoryId, constants.attributeMin, constants.attributeMax) then
        local tierData = helpers.getNestedValue(config, "attributes", categoryId, subcategoryId, tierId)

        if tierData then
            upgrades = tierData.items
            gilValue = tierData.gil or 0
        end
    elseif helpers.validateRange(subcategoryId, constants.elementMin, constants.elementMax) then
        local elemData = helpers.getNestedValue(config, "elements", subcategoryId)

        if elemData then
            upgrades = elemData.items
            gilValue = elemData.gil or 0
        end
    end

    return upgrades, gilValue
end

function loader.tier(base, addrs, attributeId, categoryId, config)
    local attr = helpers.getNestedValue(config, "attributes", categoryId, attributeId)
    if not attr then
        return false
    end

    local tier1 = loader.getTierValue(attr, 1)
    local tier2 = loader.getTierValue(attr, 2)
    local tier3 = loader.getTierValue(attr, 3)

    mem.writeU16(base, addrs.refinement.tier1AttributeValue, tier1)
    mem.writeU16(base, addrs.refinement.tier2AttributeValue, tier2)
    mem.writeU16(base, addrs.refinement.tier3AttributeValue, tier3)

    return true
end

function loader.results(base, addrs, refinement)
    if refinement then
        mem.writeU8(base, addrs.current.currentAttribute, refinement.id)
        mem.writeU16(base, addrs.refinement.defaultAttributeValue, refinement.initial)
        mem.writeU16(base, addrs.refinement.extraAttributeValue, refinement.extra or 0)
        mem.writeU16(base, addrs.refinement.totalAttributeValue, refinement.total)
    else
        mem.writeU8(base, addrs.current.currentAttribute, 0)
        mem.writeU16(base, addrs.refinement.defaultAttributeValue, 0)
        mem.writeU16(base, addrs.refinement.extraAttributeValue, 0)
        mem.writeU16(base, addrs.refinement.totalAttributeValue, 0)
    end
end

function loader.getTierValue(attr, tier)
    if not attr then
        return 0
    end

    local tierData = attr[tier]
    if tierData then
        return tierData.value or 0
    end

    return 0
end

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

function loader.initialize(deps)
    mem = deps.memory
    helpers = deps.helpers
    mappings = deps.mappings
    addresses = mappings.addresses
    constants = mappings.constants

    return true
end

return loader
