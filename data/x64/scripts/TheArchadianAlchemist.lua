-- Made By FehDead
-- =====================
-- THE ARCHADIAN ALCHEMIST 3 - ORCHESTRATOR
-- =====================
-- =====================
-- CACHE DE FUNÇÕES GLOBAIS
-- =====================
local pairs = pairs
local ipairs = ipairs
local tonumber = tonumber
local type = type
local stringFormat = string.format
local collectgarbage = collectgarbage
local setmetatable = setmetatable
local loadfile = loadfile
local pcall = pcall

-- =====================
-- PATH CONFIGURATION
-- =====================
local paths = {
    core = {
        mappings = "scripts/TheArchadianAlchemist/mappings.lua",
        helpers = "scripts/TheArchadianAlchemist/helpers.lua",
        memory = "scripts/TheArchadianAlchemist/memory.lua",
        config = "scripts/TheArchadianAlchemist/config.lua",
        equipment = "scripts/TheArchadianAlchemist/equipment.lua",
        element = "scripts/TheArchadianAlchemist/element.lua",
        attribute = "scripts/TheArchadianAlchemist/attribute.lua",
        unlock = "scripts/TheArchadianAlchemist/unlock.lua",
        loader = "scripts/TheArchadianAlchemist/loader.lua",
        flow = "scripts/TheArchadianAlchemist/flow.lua",
        controller = "scripts/TheArchadianAlchemist/controller.lua"
    },
    config = {
        directory = "scripts/config/TheArchadianAlchemist/*.lua",
        equipment = "scripts/config/TheArchadianAlchemist/equipments.lua",
        element = "scripts/config/TheArchadianAlchemist/elements.lua",
        questline = "scripts/config/TheArchadianAlchemist/questline.lua",
        attribute = {
            [1] = "scripts/config/TheArchadianAlchemist/attributes/weapons/sword.lua",
            [2] = "scripts/config/TheArchadianAlchemist/attributes/weapons/greatSword.lua",
            [3] = "scripts/config/TheArchadianAlchemist/attributes/weapons/katana.lua",
            [4] = "scripts/config/TheArchadianAlchemist/attributes/weapons/ninjaSword.lua",
            [5] = "scripts/config/TheArchadianAlchemist/attributes/weapons/spear.lua",
            [6] = "scripts/config/TheArchadianAlchemist/attributes/weapons/pole.lua",
            [7] = "scripts/config/TheArchadianAlchemist/attributes/weapons/bow.lua",
            [8] = "scripts/config/TheArchadianAlchemist/attributes/weapons/crossBow.lua",
            [9] = "scripts/config/TheArchadianAlchemist/attributes/weapons/gun.lua",
            [10] = "scripts/config/TheArchadianAlchemist/attributes/weapons/dagger.lua",
            [11] = "scripts/config/TheArchadianAlchemist/attributes/weapons/rod.lua",
            [12] = "scripts/config/TheArchadianAlchemist/attributes/weapons/staff.lua",
            [13] = "scripts/config/TheArchadianAlchemist/attributes/weapons/mace.lua",
            [14] = "scripts/config/TheArchadianAlchemist/attributes/weapons/axe.lua",
            [15] = "scripts/config/TheArchadianAlchemist/attributes/weapons/hammer.lua",
            [16] = "scripts/config/TheArchadianAlchemist/attributes/weapons/handBomb.lua",
            [17] = "scripts/config/TheArchadianAlchemist/attributes/weapons/measure.lua",
            [18] = "scripts/config/TheArchadianAlchemist/attributes/armors/heavyArmor.lua",
            [19] = "scripts/config/TheArchadianAlchemist/attributes/armors/lightArmor.lua",
            [20] = "scripts/config/TheArchadianAlchemist/attributes/armors/mysticArmor.lua",
            [21] = "scripts/config/TheArchadianAlchemist/attributes/helms/heavyHelm.lua",
            [22] = "scripts/config/TheArchadianAlchemist/attributes/helms/lightHelm.lua",
            [23] = "scripts/config/TheArchadianAlchemist/attributes/helms/mysticHelm.lua",
            [24] = "scripts/config/TheArchadianAlchemist/attributes/accessories/belt.lua",
            [25] = "scripts/config/TheArchadianAlchemist/attributes/accessories/boot.lua",
            [26] = "scripts/config/TheArchadianAlchemist/attributes/accessories/bracelet.lua",
            [27] = "scripts/config/TheArchadianAlchemist/attributes/accessories/collar.lua",
            [28] = "scripts/config/TheArchadianAlchemist/attributes/accessories/crown.lua",
            [29] = "scripts/config/TheArchadianAlchemist/attributes/accessories/glove.lua",
            [30] = "scripts/config/TheArchadianAlchemist/attributes/accessories/pendant.lua",
            [31] = "scripts/config/TheArchadianAlchemist/attributes/accessories/ring.lua",
            [32] = "scripts/config/TheArchadianAlchemist/attributes/ammunition/arrow.lua",
            [33] = "scripts/config/TheArchadianAlchemist/attributes/ammunition/bolt.lua",
            [34] = "scripts/config/TheArchadianAlchemist/attributes/ammunition/bomb.lua",
            [35] = "scripts/config/TheArchadianAlchemist/attributes/ammunition/shot.lua",
            [36] = "scripts/config/TheArchadianAlchemist/attributes/shields/shield.lua"
        }
    }
}

local mappings, helpers, mem, config, equipment, element, attribute, unlock, loader, flow, controller
local configData = {}

local symbols = {
    taa = {"TAA_QuestStatus", "TAA_ElementStatus", "TAA_AttributeStatus"},
    dd = "dd_refresh",
    addresses = {}
}

function symbols.register()
    if not memory or not memory.alloc or not memory.registerGlobalSymbol then
        print("WARN [TAA SYMBOLS] Memory API not available")
        return false
    end

    for i = 1, #symbols.taa do
        local symbolName = symbols.taa[i]
        local addr = memory.alloc(1, true)
        memory.registerGlobalSymbol(symbolName, addr)
        symbols.addresses[symbolName] = addr
    end

    return true
end

function symbols.getValue(name)
    local addr = symbols.addresses[name]
    if not addr then
        addr = memory.getSymbol(name)
        symbols.addresses[name] = addr
    end

    if addr and addr ~= 0 then
        return memory.u8[addr] or 0
    end
    return 0
end

function symbols.triggerRefresh()
    local addr = memory.getSymbol(symbols.dd)

    if addr and addr ~= 0 then
        memory.u8[addr] = 1
    end
end

local handlers = {}

function handlers.onFileChange(filepath, stats, created, deleted)
    if deleted then
        return
    end

    print("[TAA] Config file changed, reloading...")
    handlers.loadConfig()
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

        symbols.triggerRefresh(symbols.dd)
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

function handlers.onExit()
    memory.unregisterAllSymbols()
    collectgarbage()
end

function handlers.onLocation(locationId)
    controller.location(locationId)
end

function handlers.loadExternal(path)
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

function handlers.loadConfig()
    local equipmentConfig = handlers.loadExternal(paths.config.equipment) or {}
    local elementConfig = handlers.loadExternal(paths.config.element) or {}
    local questlineConfig = handlers.loadExternal(paths.config.questline) or {}

    local attributeConfigs = {}
    for id, path in pairs(paths.config.attribute) do
        local attrData = handlers.loadExternal(path)
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

local function loadModule(path)
    local chunk, err = loadfile(path, "t", setmetatable({}, {
        __index = _G
    }))

    if not chunk then
        print("[TAA LOAD ERROR] loadfile failed:", path)
        print("[TAA LOAD ERROR] reason:", tostring(err))
        return nil
    end

    local ok, result = pcall(chunk)
    if not ok then
        print("[TAA LOAD ERROR] pcall failed:", path)
        print("[TAA LOAD ERROR] reason:", tostring(result))
        return nil
    end

    return result
end

local function loadAllModules()
    mappings = loadModule(paths.core.mappings)
    if not mappings then
        print("ERROR [TAA] Failed to load: mappings")
        return false
    end

    helpers = loadModule(paths.core.helpers)
    if not helpers then
        print("ERROR [TAA] Failed to load: helpers")
        return false
    end

    mem = loadModule(paths.core.memory)
    if not mem then
        print("ERROR [TAA] Failed to load: memory")
        return false
    end

    config = loadModule(paths.core.config)
    if not config then
        print("ERROR [TAA] Failed to load: config")
        return false
    end

    equipment = loadModule(paths.core.equipment)
    if not equipment then
        print("ERROR [TAA] Failed to load: equipment")
        return false
    end

    element = loadModule(paths.core.element)
    if not element then
        print("ERROR [TAA] Failed to load: element")
        return false
    end

    attribute = loadModule(paths.core.attribute)
    if not attribute then
        print("ERROR [TAA] Failed to load: attribute")
        return false
    end

    unlock = loadModule(paths.core.unlock)
    if not unlock then
        print("ERROR [TAA] Failed to load: unlock")
        return false
    end

    loader = loadModule(paths.core.loader)
    if not loader then
        print("ERROR [TAA] Failed to load: loader")
        return false
    end

    flow = loadModule(paths.core.flow)
    if not flow then
        print("ERROR [TAA] Failed to load: flow")
        return false
    end

    controller = loadModule(paths.core.controller)
    if not controller then
        print("ERROR [TAA] Failed to load: controller")
        return false
    end

    return true
end

local function initializeModules()
    if not mem.initialize() then
        print("ERROR [TAA] Memory initialization failed")
        return false
    end

    if not config.initialize({
        helpers = helpers,
        mappings = mappings
    }) then
        print("ERROR [TAA] Config initialization failed")
        return false
    end

    if not equipment.initialize({
        memory = mem,
        mappings = mappings
    }) then
        print("ERROR [TAA] Equipment initialization failed")
        return false
    end

    if not element.initialize({
        memory = mem,
        equipment = equipment,
        mappings = mappings
    }) then
        print("ERROR [TAA] Element initialization failed")
        return false
    end

    if not attribute.initialize({
        memory = mem,
        equipment = equipment,
        helpers = helpers,
        mappings = mappings
    }) then
        print("ERROR [TAA] Attribute initialization failed")
        return false
    end

    if not unlock.initialize({
        memory = mem,
        helpers = helpers,
        mappings = mappings
    }) then
        print("ERROR [TAA] Unlock initialization failed")
        return false
    end

    if not loader.initialize({
        memory = mem,
        helpers = helpers,
        mappings = mappings
    }) then
        print("ERROR [TAA] Loader initialization failed")
        return false
    end

    if not flow.initialize({
        memory = mem,
        mappings = mappings
    }) then
        print("ERROR [TAA] Flow initialization failed")
        return false
    end

    if not controller.initialize({
        memory = mem,
        flow = flow,
        loader = loader,
        element = element,
        attribute = attribute,
        unlock = unlock,
        symbols = symbols,
        mappings = mappings
    }) then
        print("ERROR [TAA] Controller initialization failed")
        return false
    end

    controller.setSymbols(symbols)

    return true
end

local function initialize()

    if not loadAllModules() then
        print("ERROR [TAA] Failed to load modules")
        return false
    end

    if not initializeModules() then
        print("ERROR [TAA] Failed to initialize modules")
        return false
    end

    handlers.loadConfig()

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
    initialize()
end)

event.registerFileChangeHandler(paths.config.directory, function(filepath, stats, created, deleted)
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
    return handlers.onExit()
end)
