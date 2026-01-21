-- Made By FehDead
local MODULE_BASE = "scripts/TheArchadianAlchemist"
local CONFIG_BASE = "scripts/config/TheArchadianAlchemist"

local paths = {
    core = {
        mappings = MODULE_BASE .. "/mappings.lua",
        helpers = MODULE_BASE .. "/helpers.lua",
        memory = MODULE_BASE .. "/memory.lua",
        config = MODULE_BASE .. "/config.lua",
        equipment = MODULE_BASE .. "/equipment.lua",
        element = MODULE_BASE .. "/element.lua",
        attribute = MODULE_BASE .. "/attribute.lua",
        unlock = MODULE_BASE .. "/unlock.lua",
        writer = MODULE_BASE .. "/writer.lua",
        flow = MODULE_BASE .. "/flow.lua",
        controller = MODULE_BASE .. "/controller.lua"
    },
    config = {
        equipment = CONFIG_BASE .. "/equipments.lua",
        element = CONFIG_BASE .. "/elements.lua",
        questline = CONFIG_BASE .. "/questline.lua",
        attribute = {
            [1] = CONFIG_BASE .. "/attributes/sword.lua",
            [2] = CONFIG_BASE .. "/attributes/greatSword.lua",
            [3] = CONFIG_BASE .. "/attributes/katana.lua",
            [4] = CONFIG_BASE .. "/attributes/ninjaSword.lua",
            [5] = CONFIG_BASE .. "/attributes/spear.lua",
            [6] = CONFIG_BASE .. "/attributes/pole.lua",
            [7] = CONFIG_BASE .. "/attributes/bow.lua",
            [8] = CONFIG_BASE .. "/attributes/crossBow.lua",
            [9] = CONFIG_BASE .. "/attributes/gun.lua",
            [10] = CONFIG_BASE .. "/attributes/dagger.lua",
            [11] = CONFIG_BASE .. "/attributes/rod.lua",
            [12] = CONFIG_BASE .. "/attributes/staff.lua",
            [13] = CONFIG_BASE .. "/attributes/mace.lua",
            [14] = CONFIG_BASE .. "/attributes/axe.lua",
            [15] = CONFIG_BASE .. "/attributes/hammer.lua",
            [16] = CONFIG_BASE .. "/attributes/handBomb.lua",
            [17] = CONFIG_BASE .. "/attributes/measure.lua",
            [18] = CONFIG_BASE .. "/attributes/heavyArmor.lua",
            [19] = CONFIG_BASE .. "/attributes/lightArmor.lua",
            [20] = CONFIG_BASE .. "/attributes/mysticArmor.lua",
            [21] = CONFIG_BASE .. "/attributes/heavyHelm.lua",
            [22] = CONFIG_BASE .. "/attributes/lightHelm.lua",
            [23] = CONFIG_BASE .. "/attributes/mysticHelm.lua",
            [24] = CONFIG_BASE .. "/attributes/belt.lua",
            [25] = CONFIG_BASE .. "/attributes/boot.lua",
            [26] = CONFIG_BASE .. "/attributes/bracelet.lua",
            [27] = CONFIG_BASE .. "/attributes/collar.lua",
            [28] = CONFIG_BASE .. "/attributes/crown.lua",
            [29] = CONFIG_BASE .. "/attributes/glove.lua",
            [30] = CONFIG_BASE .. "/attributes/pendant.lua",
            [31] = CONFIG_BASE .. "/attributes/ring.lua",
            [32] = CONFIG_BASE .. "/attributes/arrow.lua",
            [33] = CONFIG_BASE .. "/attributes/bolt.lua",
            [34] = CONFIG_BASE .. "/attributes/bomb.lua",
            [35] = CONFIG_BASE .. "/attributes/shot.lua",
            [36] = CONFIG_BASE .. "/attributes/shield.lua"
        }
    },
    watch = CONFIG_BASE .. "/*.lua"
}

local mappings, helpers, mem, config, equipment, element, attribute, unlock, writer, flow, controller
local loader, handlers, configData = {}, {}, {}

local symbols = {
    taa = {"TAA_QuestStatus", "TAA_ElementStatus", "TAA_AttributeStatus"},
    dd = "dd_refresh",
    addresses = {}
}

function symbols.register()
    for i = 1, #symbols.taa do
        local name = symbols.taa[i]
        symbols.addresses[name] = memory.alloc(1)
        memory.registerGlobalSymbol(name, symbols.addresses[name])
    end
end

function symbols.get(name)
    local addr = symbols.addresses[name]
    if not addr then
        addr = memory.getSymbol(name)
        symbols.addresses[name] = addr
    end
    return addr and memory.u8[addr] or 0
end

function symbols.refresh()
    local addr = memory.getSymbol(symbols.dd)
    if addr then
        memory.u8[addr] = 1
    end
end

function handlers.onFileChange(filepath, stats, created, deleted)
    if deleted then
        return
    end

    print("[TAA] Config file changed, reloading...")
    loader.config()
end

function handlers.onSave()
    return {
        equipments = equipment.state,
        questStatus = unlock.getQuestStatus()
    }
end

function handlers.onLoad(filepath, savedData)
    equipment.state = equipment.state or {}

    if savedData and type(savedData) == "table" then
        if savedData.equipments then
            handlers._loadEquipmentState(savedData.equipments)
            handlers._restoreEquipmentState()
        elseif not savedData.questStatus then
            handlers._loadEquipmentState(savedData)
            handlers._restoreEquipmentState()
        end

        if savedData.questStatus then
            unlock.setQuestStatus(savedData.questStatus)
        end

        symbols.refresh()
    end
end

function handlers._loadEquipmentState(savedData)
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

function handlers._restoreEquipmentState()
    for equipmentId, state in pairs(equipment.state) do
        if state.element and state.element.id then
            local elementId = state.element.id
            if elementId >= 1 and elementId <= 8 then
                for id = 1, 8 do
                    equipment.write(equipmentId, "element", id, 0)
                end
                equipment.write(equipmentId, "element", elementId, 1)
            end
        end

        if state.attributes and state.attributes.id then
            local attributeId = state.attributes.id
            local total = state.attributes.total
            if attributeId >= 10 and attributeId <= 26 and total then
                equipment.write(equipmentId, "attribute", attributeId, total)
            end
        end
    end
end

function handlers.onLocation(locationId)
    controller.location(locationId)
end

function loader.file(path)
    if not path then
        return nil
    end

    local chunk, err = loadfile(path, "t", setmetatable({}, {
        __index = _G
    }))

    if not chunk then
        print("ERROR [TAA] Failed to load file: " .. path .. ": " .. tostring(err))
        return nil
    end

    local ok, result = pcall(chunk)
    if not ok then
        print("ERROR [TAA] Failed to execute file: " .. path .. ": " .. tostring(result))
        return nil
    end

    return result
end

function loader.config()
    local equipmentConfig = loader.file(paths.config.equipment) or {}
    local elementConfig = loader.file(paths.config.element) or {}
    local questlineConfig = loader.file(paths.config.questline) or {}

    local attributeConfigs = {}
    for id, path in pairs(paths.config.attribute) do
        local attrData = loader.file(path)
        if attrData then
            attributeConfigs[id] = attrData
        end
    end

    local rawConfig = {
        equipment = equipmentConfig,
        attributes = attributeConfigs,
        elements = elementConfig,
        questline = questlineConfig
    }

    configData = config.parse(rawConfig)

    if controller then
        controller.setConfig(configData)
    end

    return configData
end

function loader.init()
    local modules = {}
    for key, path in pairs(paths.core) do
        local loaded = loader.file(path)
        if not loaded then
            print("ERROR [TAA] Failed to load: " .. key)
            return false
        end
        modules[key] = loaded
    end

    mappings = modules.mappings
    helpers = modules.helpers
    mem = modules.memory
    config = modules.config
    equipment = modules.equipment
    element = modules.element
    attribute = modules.attribute
    unlock = modules.unlock
    writer = modules.writer
    flow = modules.flow
    controller = modules.controller

    mem.initialize()

    config.initialize({
        helpers = helpers,
        mappings = mappings
    })

    equipment.initialize({
        memory = mem,
        mappings = mappings
    })

    element.initialize({
        memory = mem,
        equipment = equipment,
        mappings = mappings
    })

    attribute.initialize({
        memory = mem,
        equipment = equipment,
        helpers = helpers,
        mappings = mappings
    })

    unlock.initialize({
        memory = mem,
        helpers = helpers,
        mappings = mappings
    })

    writer.initialize({
        memory = mem,
        helpers = helpers,
        mappings = mappings
    })

    flow.initialize({
        memory = mem,
        mappings = mappings
    })

    controller.initialize({
        memory = mem,
        flow = flow,
        writer = writer,
        element = element,
        attribute = attribute,
        unlock = unlock,
        symbols = symbols,
        mappings = mappings
    })

    controller.setSymbols(symbols)

    loader.config()

    return true
end

local MIN_VERSION = {1, 7, 1}

print("The Archadian Alchemist: Applying patch.")

if not (checkMinVersion and checkMinVersion(table.unpack(MIN_VERSION))) then
    print(string.format("The Archadian Alchemist: Couldn't apply patch, LUA Loader v%d.%d.%d or higher required.",
        table.unpack(MIN_VERSION)))
    return
end

symbols.register()

event.registerEventAsync("onInitDone", function()
    loader.init()
end)

event.registerFileChangeHandler(paths.watch, function(filepath, stats, created, deleted)
    handlers.onFileChange(filepath, stats, created, deleted)
end, true)

event.registerSaveHandler("TheArchadianAlchemist", function(filepath)
    return handlers.onSave()
end)

event.registerLoadHandler("TheArchadianAlchemist", function(filepath, savedData)
    handlers.onLoad(filepath, savedData)
end)

event.registerEventAsync("onSaveLoad", function()
    local locationId = mem.readU32(mappings.addresses.locationId, nil)
    handlers.onLocation(locationId)
end)

event.registerEventAsync("onMapJump", function(locationId)
    handlers.onLocation(locationId)
end)

event.registerEventAsync("exit", function()
    memory.unregisterAllSymbols()
    collectgarbage()
end)
