-- Made By FehDead
local mem = {}

local memoryU8, memoryU16, memoryU32

local function addr(base, offset) return offset and (base + offset) or base end

function mem.readU8(base, offset) return memoryU8[addr(base, offset)] or 0 end

function mem.readU16(base, offset) return memoryU16[addr(base, offset)] or 0 end

function mem.readU32(base, offset) return memoryU32[addr(base, offset)] or 0 end

function mem.writeU8(base, offset, value) memoryU8[addr(base, offset)] = value or offset end

function mem.writeU16(base, offset, value) memoryU16[addr(base, offset)] = value or offset end

function mem.writeU32(base, offset, value) memoryU32[addr(base, offset)] = value or offset end

function mem.clear(base, offset, length)
	if not length or length <= 0 then return end

	local startAddr = addr(base, offset)
	for i = 0, length - 1 do memoryU8[startAddr + i] = 0 end
end

local flags = {}

function flags.get(base, offset) return mem.readU8(base, offset) end

function flags.set(base, offset, value) mem.writeU8(base, offset, value) end

function flags.clear(base, offset) mem.writeU8(base, offset, 0) end

mem.flags = flags

function mem.initialize()
	memoryU8 = memory.u8
	memoryU16 = memory.u16
	memoryU32 = memory.u32
	return true
end

return mem
