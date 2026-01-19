-- Made By FehDead
local helpers = {}

function helpers.isTable(value)
    return type(value) == "table"
end

function helpers.isNumber(value)
    return type(value) == "number"
end

function helpers.isString(value)
    return type(value) == "string"
end

function helpers.toBool(value)
    return (value or 0) > 0 and 1 or 0
end

function helpers.toNumber(value, default)
    return tonumber(value) or default or 0
end

function helpers.hasAddresses(addresses)
    return addresses and addresses.selected ~= nil
end

function helpers.hasConfig(config, key)
    return config and config[key] ~= nil
end

function helpers.validateSize(size)
    return size == 1 or size == 2 or size == 4
end

function helpers.validateEquipmentIndex(id)
    return id and id >= 0 and id <= 31
end

function helpers.validatePositiveId(id)
    return id and id > 0
end

function helpers.validateRange(id, min, max)
    return id and id >= min and id <= max
end

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

function helpers.getItemId(item)
    if not item then
        return nil
    end
    return item[1] or item.id
end

function helpers.getItemQty(item)
    if not item then
        return nil
    end
    return item[2] or item.qtt or item.qty
end

function helpers.getNestedValue(tbl, ...)
    local current = tbl

    for i = 1, select("#", ...) do
        local key = select(i, ...)
        if type(current) ~= "table" then
            return nil
        end
        current = current[key]
        if current == nil then
            return nil
        end
    end

    return current
end

function helpers.tableCount(tbl)
    if not tbl then
        return 0
    end

    local count = 0
    for _ in pairs(tbl) do
        count = count + 1
    end
    return count
end

return helpers
