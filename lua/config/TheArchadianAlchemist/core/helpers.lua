-- Made By FehDead
-- =====================
-- HELPERS MODULE
-- =====================
-- Utility functions for TheArchadianAlchemist
local helpers = {}

-- =====================
-- CACHE DE FUNÇÕES GLOBAIS
-- =====================
local type = type
local tonumber = tonumber
local pairs = pairs
local ipairs = ipairs

-- =====================
-- TYPE VALIDATION
-- =====================

-- @description: check if value is a table
-- @returns: boolean
function helpers.isTable(value)
    return type(value) == "table"
end

-- @description: check if value is a number
-- @returns: boolean
function helpers.isNumber(value)
    return type(value) == "number"
end

-- @description: check if value is a string
-- @returns: boolean
function helpers.isString(value)
    return type(value) == "string"
end

-- =====================
-- VALUE CONVERSION
-- =====================

-- @description: convert numeric value to boolean (0 or 1)
-- @returns: number (0 or 1)
function helpers.toBool(value)
    return (value or 0) > 0 and 1 or 0
end

-- @description: safely convert to number with default
-- @returns: number
function helpers.toNumber(value, default)
    return tonumber(value) or default or 0
end

-- =====================
-- VALIDATION HELPERS
-- =====================

-- @description: check if addresses object has required fields
-- @returns: boolean
function helpers.hasAddresses(addresses)
    return addresses and addresses.selected ~= nil
end

-- @description: check if config table contains given key
-- @returns: boolean
function helpers.hasConfig(config, key)
    return config and config[key] ~= nil
end

-- @description: validate memory size (1, 2, or 4 bytes)
-- @returns: boolean
function helpers.validateSize(size)
    return size == 1 or size == 2 or size == 4
end

-- @description: validate equipment index (0 to 31)
-- @returns: boolean
function helpers.validateEquipmentIndex(id)
    return id and id >= 0 and id <= 31
end

-- @description: validate id is positive
-- @returns: boolean
function helpers.validatePositiveId(id)
    return id and id > 0
end

-- @description: validate id is within range (inclusive)
-- @returns: boolean
function helpers.validateRange(id, min, max)
    return id and id >= min and id <= max
end

-- =====================
-- TIER HELPERS
-- =====================

-- @description: calculate tier index based on progress and tier ids
-- @params: progress (number), ids (array of tier thresholds)
-- @returns: 1, 2, or 3
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

-- =====================
-- ITEM HELPERS
-- =====================

-- @description: get item id from item (supports array/object format)
-- @params: item - {id, qty} or {[1]=id, [2]=qty}
-- @returns: number or nil
function helpers.getItemId(item)
    if not item then
        return nil
    end
    return item[1] or item.id
end

-- @description: get item quantity from item (supports array/object format)
-- @params: item - {id, qty} or {[1]=id, [2]=qty}
-- @returns: number or nil
function helpers.getItemQty(item)
    if not item then
        return nil
    end
    return item[2] or item.qtt or item.qty
end

-- =====================
-- TABLE HELPERS
-- =====================

-- @description: safely get nested value from table
-- @params: tbl (table), ... (keys path)
-- @returns: value or nil
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

-- @description: count table entries (works for non-sequential tables)
-- @returns: number
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
