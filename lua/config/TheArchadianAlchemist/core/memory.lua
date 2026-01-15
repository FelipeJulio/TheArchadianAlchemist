-- Made By FehDead
-- =====================
-- MEMORY MODULE
-- =====================
-- Memory read/write operations and flag management
local mem = {}

-- =====================
-- CACHE DE FUNÇÕES GLOBAIS
-- =====================
local memoryU8, memoryU16, memoryU32

-- =====================
-- FLAG DE INICIALIZAÇÃO
-- =====================
local isInitialized = false

-- =====================
-- READ OPERATIONS
-- =====================

-- @description: read 8-bit value from memory
-- @params: base (address), offset (optional)
-- @returns: number
function mem.readU8(base, offset)
    local address = (offset == nil) and base or (base + offset)
    return memoryU8[address] or 0
end

-- @description: read 16-bit value from memory
-- @params: base (address), offset (optional)
-- @returns: number
function mem.readU16(base, offset)
    local address = (offset == nil) and base or (base + offset)
    return memoryU16[address] or 0
end

-- @description: read 32-bit value from memory
-- @params: base (address), offset (optional)
-- @returns: number
function mem.readU32(base, offset)
    local address = (offset == nil) and base or (base + offset)
    return memoryU32[address] or 0
end

-- =====================
-- WRITE OPERATIONS
-- =====================

-- @description: write 8-bit value to memory
-- @params: base (address), offset (optional or value), value (optional)
function mem.writeU8(base, offset, value)
    local address = (offset == nil) and base or (base + offset)
    local val = (value == nil) and offset or value
    memoryU8[address] = val
end

-- @description: write 16-bit value to memory
-- @params: base (address), offset (optional or value), value (optional)
function mem.writeU16(base, offset, value)
    local address = (offset == nil) and base or (base + offset)
    local val = (value == nil) and offset or value
    memoryU16[address] = val
end

-- @description: write 32-bit value to memory
-- @params: base (address), offset (optional or value), value (optional)
function mem.writeU32(base, offset, value)
    local address = (offset == nil) and base or (base + offset)
    local val = (value == nil) and offset or value
    memoryU32[address] = val
end

-- =====================
-- UTILITY OPERATIONS
-- =====================

-- @description: clear memory region (set to 0)
-- @params: base (address), offset (start offset), length (bytes to clear)
function mem.clear(base, offset, length)
    if length == nil or length <= 0 then
        return
    end

    local startAddr = (offset == nil) and base or (base + offset)
    for i = 0, length - 1 do
        memoryU8[startAddr + i] = 0
    end
end

-- =====================
-- FLAG OPERATIONS
-- =====================
-- Convenience wrappers for 1-byte flag operations

local flags = {}

-- @description: get flag value (1 byte)
-- @returns: 0-255
function flags.get(base, offset)
    return mem.readU8(base, offset)
end

-- @description: set flag value (1 byte)
function flags.set(base, offset, value)
    mem.writeU8(base, offset, value)
end

-- @description: clear flag (set to 0)
function flags.clear(base, offset)
    mem.writeU8(base, offset, 0)
end

-- Export flags as sub-module
mem.flags = flags

-- =====================
-- INICIALIZAÇÃO
-- =====================

function mem.initialize()
    if isInitialized then
        return true
    end

    -- Cache memory API references
    if not memory then
        print("ERROR [TAA MEMORY] Memory API not available")
        return false
    end

    memoryU8 = memory.u8
    memoryU16 = memory.u16
    memoryU32 = memory.u32

    if not memoryU8 or not memoryU16 or not memoryU32 then
        print("ERROR [TAA MEMORY] Memory arrays not available")
        return false
    end

    isInitialized = true
    print("[TAA MEMORY] Module initialized")
    return true
end

-- =====================
-- DEBUG HELPERS
-- =====================

function mem.isReady()
    return isInitialized
end

function mem.getStatus()
    return {
        initialized = isInitialized,
        hasMemoryApi = memory ~= nil,
        hasU8 = memoryU8 ~= nil,
        hasU16 = memoryU16 ~= nil,
        hasU32 = memoryU32 ~= nil
    }
end

return mem
