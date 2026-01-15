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
        mappings = "scripts/config/TheArchadianAlchemist3/core/mappings.lua",
        helpers = "scripts/config/TheArchadianAlchemist3/core/helpers.lua",
        memory = "scripts/config/TheArchadianAlchemist3/core/memory.lua",
        config = "scripts/config/TheArchadianAlchemist3/core/config.lua",
        equipment = "scripts/config/TheArchadianAlchemist3/core/equipment.lua",
        element = "scripts/config/TheArchadianAlchemist3/core/element.lua",
        attribute = "scripts/config/TheArchadianAlchemist3/core/attribute.lua",
        unlock = "scripts/config/TheArchadianAlchemist3/core/unlock.lua",
        loader = "scripts/config/TheArchadianAlchemist3/core/loader.lua",
        flow = "scripts/config/TheArchadianAlchemist3/core/flow.lua",
        controller = "scripts/config/TheArchadianAlchemist3/core/controller.lua"
    },
    config = {
        directory = "scripts/config/TheArchadianAlchemist3/*.lua",
        equipment = "scripts/config/TheArchadianAlchemist3/config/equipments.lua",
        element = "scripts/config/TheArchadianAlchemist3/config/elements.lua",
        questline = "scripts/config/TheArchadianAlchemist3/config/questline.lua",
        attribute = {
            [1] = "scripts/config/TheArchadianAlchemist3/config/attributes/weapons/sword.lua",
            [2] = "scripts/config/TheArchadianAlchemist3/config/attributes/weapons/greatSword.lua",
            [3] = "scripts/config/TheArchadianAlchemist3/config/attributes/weapons/katana.lua",
            [4] = "scripts/config/TheArchadianAlchemist3/config/attributes/weapons/ninjaSword.lua",
            [5] = "scripts/config/TheArchadianAlchemist3/config/attributes/weapons/spear.lua",
            [6] = "scripts/config/TheArchadianAlchemist3/config/attributes/weapons/pole.lua",
            [7] = "scripts/config/TheArchadianAlchemist3/config/attributes/weapons/bow.lua",
            [8] = "scripts/config/TheArchadianAlchemist3/config/attributes/weapons/crossBow.lua",
            [9] = "scripts/config/TheArchadianAlchemist3/config/attributes/weapons/gun.lua",
            [10] = "scripts/config/TheArchadianAlchemist3/config/attributes/weapons/dagger.lua",
            [11] = "scripts/config/TheArchadianAlchemist3/config/attributes/weapons/rod.lua",
            [12] = "scripts/config/TheArchadianAlchemist3/config/attributes/weapons/staff.lua",
            [13] = "scripts/config/TheArchadianAlchemist3/config/attributes/weapons/mace.lua",
            [14] = "scripts/config/TheArchadianAlchemist3/config/attributes/weapons/axe.lua",
            [15] = "scripts/config/TheArchadianAlchemist3/config/attributes/weapons/hammer.lua",
            [16] = "scripts/config/TheArchadianAlchemist3/config/attributes/weapons/handBomb.lua",
            [17] = "scripts/config/TheArchadianAlchemist3/config/attributes/weapons/measure.lua",
            [18] = "scripts/config/TheArchadianAlchemist3/config/attributes/armors/heavyArmor.lua",
            [19] = "scripts/config/TheArchadianAlchemist3/config/attributes/armors/lightArmor.lua",
            [20] = "scripts/config/TheArchadianAlchemist3/config/attributes/armors/mysticArmor.lua",
            [21] = "scripts/config/TheArchadianAlchemist3/config/attributes/helms/heavyHelm.lua",
            [22] = "scripts/config/TheArchadianAlchemist3/config/attributes/helms/lightHelm.lua",
            [23] = "scripts/config/TheArchadianAlchemist3/config/attributes/helms/mysticHelm.lua",
            [24] = "scripts/config/TheArchadianAlchemist3/config/attributes/accessories/belt.lua",
            [25] = "scripts/config/TheArchadianAlchemist3/config/attributes/accessories/boot.lua",
            [26] = "scripts/config/TheArchadianAlchemist3/config/attributes/accessories/bracelet.lua",
            [27] = "scripts/config/TheArchadianAlchemist3/config/attributes/accessories/collar.lua",
            [28] = "scripts/config/TheArchadianAlchemist3/config/attributes/accessories/crown.lua",
            [29] = "scripts/config/TheArchadianAlchemist3/config/attributes/accessories/glove.lua",
            [30] = "scripts/config/TheArchadianAlchemist3/config/attributes/accessories/pendant.lua",
            [31] = "scripts/config/TheArchadianAlchemist3/config/attributes/accessories/ring.lua",
            [32] = "scripts/config/TheArchadianAlchemist3/config/attributes/ammunition/arrow.lua",
            [33] = "scripts/config/TheArchadianAlchemist3/config/attributes/ammunition/bolt.lua",
            [34] = "scripts/config/TheArchadianAlchemist3/config/attributes/ammunition/bomb.lua",
            [35] = "scripts/config/TheArchadianAlchemist3/config/attributes/ammunition/shot.lua",
            [36] = "scripts/config/TheArchadianAlchemist3/config/attributes/shields/shield.lua"
        }
    }
}

-- =====================
-- MODULES
-- =====================
local mappings, helpers, mem, config, equipment, element, attribute, unlock, loader, flow, controller
local configData = {}
local isInitialized = false

-- =====================
-- SYMBOLS
-- =====================
local symbols = {}
local symbolAddresses = {}

function symbols.register()
    if not memory or not memory.alloc or not memory.registerGlobalSymbol then
        print("WARN [TAA SYMBOLS] Memory API not available")
        return false
    end

    local symbolNames = mappings.symbols.taa

    for i = 1, #symbolNames do
        local addr = memory.alloc(1, true)
        memory.registerGlobalSymbol(symbolNames[i], addr)
        symbolAddresses[symbolNames[i]] = addr
    end

    print("[TAA SYMBOLS] Registered:", #symbolNames, "symbols")
    return true
end

function symbols.getValue(name)
    local addr = symbolAddresses[name]
    if not addr then
        addr = memory.getSymbol(name)
        symbolAddresses[name] = addr
    end

    if addr and addr ~= 0 then
        return memory.u8[addr] or 0
    end
    return 0
end

function symbols.triggerRefresh(name)
    local addr = memory.getSymbol("dd_refresh")

    if addr and addr ~= 0 then
        memory.u8[addr] = 1
        print("[TAA] dd_refresh triggered")
    end
end

-- =====================
-- HANDLERS
-- =====================
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
        -- Load equipment state
        if savedData.equipments then
            handlers._loadEquipmentState(savedData.equipments)
            handlers._restoreEquipmentState()
        elseif not savedData.questStatus then
            -- Legacy format (just equipment state at root)
            handlers._loadEquipmentState(savedData)
            handlers._restoreEquipmentState()
        end

        -- Load quest status
        if savedData.questStatus then
            unlock.setQuestStatus(savedData.questStatus)
        end

        symbols.triggerRefresh(mappings.symbols.dd)
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

-- =====================
-- CONFIG LOADING
-- =====================

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

    print("[TAA] Config loaded successfully")
    return configData
end

-- =====================
-- MODULE LOADER
-- =====================

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

    print("[TAA] All modules loaded")
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
        mappings = mappings
    }) then
        print("ERROR [TAA] Controller initialization failed")
        return false
    end

    controller.setSymbols(symbols)

    print("[TAA] All modules initialized")
    return true
end

-- =====================
-- MAIN INITIALIZATION
-- =====================

local function initialize()
    print("[TAA] Starting The Archadian Alchemist 3...")

    if not loadAllModules() then
        print("ERROR [TAA] Failed to load modules")
        return false
    end

    symbols.register()

    if not initializeModules() then
        print("ERROR [TAA] Failed to initialize modules")
        return false
    end

    handlers.loadConfig()

    isInitialized = true
    print("[TAA] Initialization complete!")
    return true
end

-- =====================
-- EVENT REGISTRATION
-- =====================

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
