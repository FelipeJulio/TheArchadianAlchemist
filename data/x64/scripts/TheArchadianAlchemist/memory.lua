-- Made By FehDead
local mem = {}

local memoryU8, memoryU16, memoryU32

function mem.readU8(base, offset)
    local address = (offset == nil) and base or (base + offset)
    return memoryU8[address] or 0
end

function mem.readU16(base, offset)
    local address = (offset == nil) and base or (base + offset)
    return memoryU16[address] or 0
end

function mem.readU32(base, offset)
    local address = (offset == nil) and base or (base + offset)
    return memoryU32[address] or 0
end

function mem.writeU8(base, offset, value)
    local address = (offset == nil) and base or (base + offset)
    local val = (value == nil) and offset or value
    memoryU8[address] = val
end

function mem.writeU16(base, offset, value)
    local address = (offset == nil) and base or (base + offset)
    local val = (value == nil) and offset or value
    memoryU16[address] = val
end

function mem.writeU32(base, offset, value)
    local address = (offset == nil) and base or (base + offset)
    local val = (value == nil) and offset or value
    memoryU32[address] = val
end

function mem.clear(base, offset, length)
    if length == nil or length <= 0 then
        return
    end

    local startAddr = (offset == nil) and base or (base + offset)
    for i = 0, length - 1 do
        memoryU8[startAddr + i] = 0
    end
end

local flags = {}

function flags.get(base, offset)
    return mem.readU8(base, offset)
end

function flags.set(base, offset, value)
    mem.writeU8(base, offset, value)
end

function flags.clear(base, offset)
    mem.writeU8(base, offset, 0)
end

mem.flags = flags

function mem.initialize()
    if isInitialized then
        return true
    end

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

    return true
end

return mem
