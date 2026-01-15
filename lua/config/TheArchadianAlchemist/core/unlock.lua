-- Made By FehDead
-- =====================
-- UNLOCK MODULE
-- =====================
-- Quest progression and content unlocking system
local unlock = {}

-- =====================
-- DEPENDÊNCIAS
-- =====================
local mem
local helpers
local mappings

-- =====================
-- CACHE DE FUNÇÕES GLOBAIS
-- =====================
local mathMin = math.min

-- =====================
-- FLAG DE INICIALIZAÇÃO
-- =====================
local isInitialized = false

-- =====================
-- CACHED REFERENCES
-- =====================
local addresses
local constants
local mainQuestStatusValues

-- =====================
-- QUEST STATUS STATE
-- =====================
--[[
    State structure (saved to save game):
    {
        mainQuestStatus = 0,      -- 0-4
        unlockedElements = 0,     -- 0-3 (tier)
        unlockedAttributes = 0,   -- 0-3 (tier)
        lastTierLevel = 0,        -- 0-6 (last sum of element + attribute tiers)
        lastMessageLevel = 0      -- 0-3 (last supply notification level shown)
    }
]]
unlock.questStatus = {
    mainQuestStatus = 0,
    unlockedElements = 0,
    unlockedAttributes = 0,
    lastTierLevel = 0,
    lastMessageLevel = 0
}

-- =====================
-- MAIN QUEST LOGIC
-- =====================

--[[
    MainQuest Status Flow (Normal Mode - overrideEvents = false):
    0 = storyProgress < startQuest.id (not started)
    1 = storyProgress >= startQuest.id (can start) - Lua writes
    2 = Player paid gill (waiting progress) - EBP writes
    3 = storyProgress >= finishQuest.id AND current == 2 (can finish) - Lua writes
    4 = EBP finalized (completed) - EBP writes

    MainQuest Status Flow (Override Mode - overrideEvents = true):
    Modder sends TAA_QuestStart = 1 (can start) or 3 (can finish)
    EBP still handles transitions: 1 -> 2 (player pays) and 3 -> 4 (player finishes)
    Lua just syncs the symbol value when in states 0, 1, or 3
]]

-- @description: Update main quest status based on story progress or symbol
-- @params: base, addrs, questline, symbolsModule
function unlock.mainQuest(base, addrs, questline, symbolsModule)
    if not questline or not questline.mainQuest then
        return
    end

    local override = questline.overrideEvents
    local currentStatus = mem.flags.get(base, addrs.flow.mainQuestStatus)

    if override then
        -- Override mode: passive to symbols
        -- Modder controls when quest can start (1) or finish (3)
        -- EBP handles transitions 1->2 and 3->4

        if symbolsModule then
            local symbolValue = symbolsModule.getValue(mappings.symbols.main)

            -- Only update if EBP hasn't already progressed past the symbol value
            -- EBP sets 2 (after payment) and 4 (after completion)
            if currentStatus == 0 and symbolValue >= 1 then
                -- Modder enabled quest start
                mem.flags.set(base, addrs.flow.mainQuestStatus, 1)
                local startQuestGill = helpers.getNestedValue(questline, "mainQuest", "startQuest", "gill") or 0
                mem.writeU32(base, addrs.flow.mainQuestGill, startQuestGill)
                unlock.questStatus.mainQuestStatus = 1

            elseif currentStatus == 1 then
                -- Waiting for EBP to set 2 (player pays)
                local startQuestGill = helpers.getNestedValue(questline, "mainQuest", "startQuest", "gill") or 0
                mem.writeU32(base, addrs.flow.mainQuestGill, startQuestGill)

            elseif currentStatus == 2 and symbolValue >= 3 then
                -- Modder enabled quest finish
                mem.flags.set(base, addrs.flow.mainQuestStatus, 3)
                unlock.questStatus.mainQuestStatus = 3

            elseif currentStatus == 3 then
                -- Waiting for EBP to set 4 (player finishes dialog)
                -- Just sync state
                unlock.questStatus.mainQuestStatus = 3

            elseif currentStatus == 4 then
                -- Completed
                unlock.questStatus.mainQuestStatus = 4
            end
        end

        -- Always sync current status to state
        local finalStatus = mem.flags.get(base, addrs.flow.mainQuestStatus)
        unlock.questStatus.mainQuestStatus = finalStatus
        return
    end

    -- Normal mode: based on story progress
    local progress = mem.readU16(addrs.storyProgress, nil)

    -- Get quest IDs from config
    local startQuestId = helpers.getNestedValue(questline, "mainQuest", "startQuest", "id")
    local startQuestGill = helpers.getNestedValue(questline, "mainQuest", "startQuest", "gill") or 0
    local finishQuestId = helpers.getNestedValue(questline, "mainQuest", "finishQuest", "id")

    -- Restore from saved state first (if not already set by EBP)
    if currentStatus == 0 and unlock.questStatus.mainQuestStatus > 0 then
        currentStatus = unlock.questStatus.mainQuestStatus
        mem.flags.set(base, addrs.flow.mainQuestStatus, currentStatus)
    end

    -- State machine logic
    if currentStatus == 0 then
        -- Check if can start
        if startQuestId and progress >= startQuestId then
            mem.flags.set(base, addrs.flow.mainQuestStatus, 1)
            mem.writeU32(base, addrs.flow.mainQuestGill, startQuestGill)
            unlock.questStatus.mainQuestStatus = 1
        end

    elseif currentStatus == 1 then
        -- Write gill value (in case it wasn't written)
        mem.writeU32(base, addrs.flow.mainQuestGill, startQuestGill)
        -- Status 1 -> 2 is handled by EBP when player pays

    elseif currentStatus == 2 then
        -- Check if can finish
        if finishQuestId and progress >= finishQuestId then
            mem.flags.set(base, addrs.flow.mainQuestStatus, 3)
            unlock.questStatus.mainQuestStatus = 3
        end

    elseif currentStatus == 3 then
        -- Status 3 -> 4 is handled by EBP when player finishes dialog
        -- Just sync state
        unlock.questStatus.mainQuestStatus = 3

    elseif currentStatus == 4 then
        -- Completed, sync state
        unlock.questStatus.mainQuestStatus = 4
    end

    -- Always sync current status to state (EBP may have changed it)
    local finalStatus = mem.flags.get(base, addrs.flow.mainQuestStatus)
    unlock.questStatus.mainQuestStatus = finalStatus
end

-- =====================
-- TIER CALCULATION
-- =====================

-- @description: Calculate tier based on story progress and tier IDs
-- @params: progress, tierData (parsed structure with .ids array)
-- @returns: tier (0-3)
function unlock._calculateTier(progress, tierData)
    if not tierData or not tierData.ids then
        return 0
    end

    -- Check from highest to lowest
    for tier = 3, 1, -1 do
        local tierId = tierData.ids[tier]
        if tierId and progress >= tierId then
            return tier
        end
    end

    return 0
end

-- =====================
-- ELEMENTS UNLOCK
-- =====================

-- @description: Update unlocked elements (8 individual flags)
-- @params: base, addrs, questline, symbolsModule
function unlock.elements(base, addrs, questline, symbolsModule)
    if not questline then
        return
    end

    local override = questline.overrideEvents
    local mainStatus = unlock.questStatus.mainQuestStatus

    -- Only unlock if main quest is completed (status >= 4)
    if mainStatus < 4 then
        -- Clear all 8 element flags
        for i = 0, 7 do
            mem.writeU8(base + addrs.flow.unlockedElements + i, nil, 0)
        end
        unlock.questStatus.unlockedElements = 0
        return
    end

    local elementTier = 0

    if override and symbolsModule then
        -- Override mode: get tier from symbol
        elementTier = symbolsModule.getValue(mappings.symbols.element)
    else
        -- Normal mode: calculate from story progress
        local progress = mem.readU16(addrs.storyProgress, nil)
        elementTier = unlock._calculateTier(progress, questline.elementalExchange)
    end

    -- Get unlocks for current tier from questline config
    local unlocks = nil
    if elementTier > 0 and questline.elementalExchange then
        local tierData = questline.elementalExchange
        if tierData.contents and tierData.contents[elementTier] then
            unlocks = tierData.contents[elementTier]
        end
    end

    -- Write 8 individual element flags (fire=0, lightning=1, ice=2, earth=3, water=4, wind=5, holy=6, dark=7)
    for i = 0, 7 do
        local elementId = i + 1 -- element IDs are 1-8
        local value = 0
        if unlocks and unlocks[elementId] and unlocks[elementId] > 0 then
            value = 1
        end
        mem.writeU8(base + addrs.flow.unlockedElements + i, nil, value)
    end

    unlock.questStatus.unlockedElements = elementTier
end

-- =====================
-- ATTRIBUTES UNLOCK
-- =====================

-- @description: Update unlocked attributes (17 individual flags)
-- @params: base, addrs, questline, symbolsModule
function unlock.attributes(base, addrs, questline, symbolsModule)
    if not questline then
        return
    end

    local override = questline.overrideEvents
    local mainStatus = unlock.questStatus.mainQuestStatus

    -- Only unlock if main quest is completed (status >= 4)
    if mainStatus < 4 then
        -- Clear all 17 attribute flags
        for i = 0, 16 do
            mem.writeU8(base + addrs.flow.unlockedAttributes + i, nil, 0)
        end
        unlock.questStatus.unlockedAttributes = 0
        return
    end

    local attrTier = 0

    if override and symbolsModule then
        -- Override mode: get tier from symbol
        attrTier = symbolsModule.getValue(mappings.symbols.attribute)
    else
        -- Normal mode: calculate from story progress
        local progress = mem.readU16(addrs.storyProgress, nil)
        attrTier = unlock._calculateTier(progress, questline.attributeRefinement)
    end

    -- Get unlocks for current tier from questline config
    local unlocks = nil
    if attrTier > 0 and questline.attributeRefinement then
        local tierData = questline.attributeRefinement
        if tierData.contents and tierData.contents[attrTier] then
            unlocks = tierData.contents[attrTier]
        end
    end

    -- Write 17 individual attribute flags
    -- Attribute IDs are 10-26, array index is 0-16
    for i = 0, 16 do
        local attrId = i + 10 -- attribute IDs are 10-26
        local value = 0
        if unlocks and unlocks[attrId] and unlocks[attrId] > 0 then
            value = 1
        end
        mem.writeU8(base + addrs.flow.unlockedAttributes + i, nil, value)
    end

    unlock.questStatus.unlockedAttributes = attrTier
end

-- =====================
-- TIERS UNLOCK
-- =====================

-- @description: Update unlocked tiers (max of elements and attributes)
-- @params: base, addrs
function unlock.tiers(base, addrs)
    local elementTier = unlock.questStatus.unlockedElements
    local attrTier = unlock.questStatus.unlockedAttributes

    -- Use the higher of the two
    local maxTier = (elementTier > attrTier) and elementTier or attrTier

    -- Default to 1 if any unlocks exist
    if maxTier == 0 and unlock.questStatus.mainQuestStatus >= 4 then
        maxTier = 1
    end

    mem.flags.set(base, addrs.flow.unlockedTiers, maxTier)
end

-- =====================
-- NOTIFICATION SYSTEM
-- =====================

-- @description: Update notification flags based on tier changes
-- @params: base, addrs
function unlock.notification(base, addrs)
    -- Check if there's already a pending notification (EBP hasn't shown it yet)
    local pendingPopup = mem.flags.get(base, addrs.flow.showPopup)
    local pendingSupply = mem.flags.get(base, addrs.flow.supplyNotification)

    -- Don't process if there's a pending notification
    if pendingPopup == 1 or pendingSupply > 0 then
        return
    end

    -- Calculate actual levels
    local actualTierLevel = unlock.questStatus.unlockedElements + unlock.questStatus.unlockedAttributes
    local actualMessageLevel = mathMin(unlock.questStatus.unlockedElements, unlock.questStatus.unlockedAttributes)

    -- Get last levels from state
    local lastTierLevel = unlock.questStatus.lastTierLevel
    local lastMessageLevel = unlock.questStatus.lastMessageLevel

    -- Check if we need to show popup (any tier increase)
    if actualTierLevel > lastTierLevel then
        mem.flags.set(base, addrs.flow.showPopup, 1)
        unlock.questStatus.lastTierLevel = actualTierLevel
    end

    -- Check if we need to show supply notification (both reached same tier)
    if actualMessageLevel > lastMessageLevel then
        mem.flags.set(base, addrs.flow.supplyNotification, actualMessageLevel)
        unlock.questStatus.lastMessageLevel = actualMessageLevel
    end
end

-- =====================
-- MAIN UPDATE FUNCTION
-- =====================

-- @description: Run all unlock checks (called from controller.poll)
-- @params: base, addrs, questline, symbolsModule
function unlock.update(base, addrs, questline, symbolsModule)
    if not questline then
        return
    end

    -- 1. Update main quest status
    unlock.mainQuest(base, addrs, questline, symbolsModule)

    -- 2. Update element unlocks
    unlock.elements(base, addrs, questline, symbolsModule)

    -- 3. Update attribute unlocks
    unlock.attributes(base, addrs, questline, symbolsModule)

    -- 4. Update tiers
    unlock.tiers(base, addrs)

    -- 5. Update notification
    unlock.notification(base, addrs)
end

-- =====================
-- STATE MANAGEMENT
-- =====================

-- @description: Get quest status for saving
-- @returns: questStatus table
function unlock.getQuestStatus()
    return {
        mainQuestStatus = unlock.questStatus.mainQuestStatus,
        unlockedElements = unlock.questStatus.unlockedElements,
        unlockedAttributes = unlock.questStatus.unlockedAttributes,
        lastTierLevel = unlock.questStatus.lastTierLevel,
        lastMessageLevel = unlock.questStatus.lastMessageLevel
    }
end

-- @description: Set quest status from loaded save
-- @params: savedStatus (table)
function unlock.setQuestStatus(savedStatus)
    if not savedStatus then
        return
    end

    unlock.questStatus.mainQuestStatus = savedStatus.mainQuestStatus or 0
    unlock.questStatus.unlockedElements = savedStatus.unlockedElements or 0
    unlock.questStatus.unlockedAttributes = savedStatus.unlockedAttributes or 0
    unlock.questStatus.lastTierLevel = savedStatus.lastTierLevel or 0
    unlock.questStatus.lastMessageLevel = savedStatus.lastMessageLevel or 0
end

-- @description: Reset quest status to initial state
function unlock.resetQuestStatus()
    unlock.questStatus = {
        mainQuestStatus = 0,
        unlockedElements = 0,
        unlockedAttributes = 0,
        lastTierLevel = 0,
        lastMessageLevel = 0
    }
end

-- @description: Sync memory with current state (on map enter)
-- @params: base, addrs
function unlock.syncToMemory(base, addrs)
    -- Only sync mainQuestStatus here
    -- Elements and attributes arrays will be written by elements() and attributes() in update()
    mem.flags.set(base, addrs.flow.mainQuestStatus, unlock.questStatus.mainQuestStatus)
end

-- =====================
-- INICIALIZAÇÃO
-- =====================

function unlock.initialize(deps)
    if not deps then
        print("ERROR [TAA UNLOCK] Dependencies not provided")
        return false
    end

    if not deps.memory then
        print("ERROR [TAA UNLOCK] Memory not provided")
        return false
    end

    if not deps.helpers then
        print("ERROR [TAA UNLOCK] Helpers not provided")
        return false
    end

    if not deps.mappings then
        print("ERROR [TAA UNLOCK] Mappings not provided")
        return false
    end

    mem = deps.memory
    helpers = deps.helpers
    mappings = deps.mappings

    -- Cache frequently used references
    addresses = mappings.addresses
    constants = mappings.constants
    mainQuestStatusValues = constants.mainQuestStatus

    isInitialized = true
    print("[TAA UNLOCK] Module initialized")
    return true
end

-- =====================
-- DEBUG HELPERS
-- =====================

function unlock.isReady()
    return isInitialized
end

function unlock.getStatus()
    return {
        initialized = isInitialized,
        hasMemory = mem ~= nil,
        hasHelpers = helpers ~= nil,
        hasMappings = mappings ~= nil,
        questStatus = unlock.questStatus
    }
end

return unlock
