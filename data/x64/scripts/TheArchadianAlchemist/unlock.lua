-- Made By FehDead
local unlock = {}

local mem
local helpers
local mappings
local mathMin = math.min
local addresses
local constants
local mainQuestStatusValues

unlock.questStatus = {
    mainQuestStatus = 0,
    unlockedElements = 0,
    unlockedAttributes = 0,
    lastTierLevel = 0,
    lastMessageLevel = 0
}

function unlock.mainQuest(base, addrs, questline, symbolsModule)
    if not questline or not questline.mainQuest then
        return
    end

    local override = questline.overrideEvents
    local currentStatus = mem.flags.get(base, addrs.flow.mainQuestStatus)

    if override then
        if symbolsModule then
            local symbolValue = symbolsModule.getValue(mappings.symbols.main)

            if currentStatus == 0 and symbolValue >= 1 then
                mem.flags.set(base, addrs.flow.mainQuestStatus, 1)
                local startQuestGill = helpers.getNestedValue(questline, "mainQuest", "startQuest", "gill") or 0
                mem.writeU32(base, addrs.flow.mainQuestGill, startQuestGill)
                unlock.questStatus.mainQuestStatus = 1
            elseif currentStatus == 1 then
                local startQuestGill = helpers.getNestedValue(questline, "mainQuest", "startQuest", "gill") or 0
                mem.writeU32(base, addrs.flow.mainQuestGill, startQuestGill)
            elseif currentStatus == 2 and symbolValue >= 3 then
                mem.flags.set(base, addrs.flow.mainQuestStatus, 3)
                unlock.questStatus.mainQuestStatus = 3
            elseif currentStatus == 3 then
                unlock.questStatus.mainQuestStatus = 3
            elseif currentStatus == 4 then
                unlock.questStatus.mainQuestStatus = 4
            end
        end

        local finalStatus = mem.flags.get(base, addrs.flow.mainQuestStatus)
        unlock.questStatus.mainQuestStatus = finalStatus
        return
    end

    local progress = mem.readU16(addrs.storyProgress, nil)

    local startQuestId = helpers.getNestedValue(questline, "mainQuest", "startQuest", "id")
    local startQuestGill = helpers.getNestedValue(questline, "mainQuest", "startQuest", "gill") or 0
    local finishQuestId = helpers.getNestedValue(questline, "mainQuest", "finishQuest", "id")

    if currentStatus == 0 and unlock.questStatus.mainQuestStatus > 0 then
        currentStatus = unlock.questStatus.mainQuestStatus
        mem.flags.set(base, addrs.flow.mainQuestStatus, currentStatus)
    end

    if currentStatus == 0 then
        if startQuestId and progress >= startQuestId then
            mem.flags.set(base, addrs.flow.mainQuestStatus, 1)
            mem.writeU32(base, addrs.flow.mainQuestGill, startQuestGill)
            unlock.questStatus.mainQuestStatus = 1
        end
    elseif currentStatus == 1 then
        mem.writeU32(base, addrs.flow.mainQuestGill, startQuestGill)
    elseif currentStatus == 2 then
        if finishQuestId and progress >= finishQuestId then
            mem.flags.set(base, addrs.flow.mainQuestStatus, 3)
            unlock.questStatus.mainQuestStatus = 3
        end
    elseif currentStatus == 3 then
        unlock.questStatus.mainQuestStatus = 3
    elseif currentStatus == 4 then
        unlock.questStatus.mainQuestStatus = 4
    end

    local finalStatus = mem.flags.get(base, addrs.flow.mainQuestStatus)
    unlock.questStatus.mainQuestStatus = finalStatus
end

function unlock._calculateTier(progress, tierData)
    if not tierData or not tierData.ids then
        return 0
    end

    for tier = 3, 1, -1 do
        local tierId = tierData.ids[tier]
        if tierId and progress >= tierId then
            return tier
        end
    end

    return 0
end

function unlock.elements(base, addrs, questline, symbolsModule)
    if not questline then
        return
    end

    local override = questline.overrideEvents
    local mainStatus = unlock.questStatus.mainQuestStatus

    if mainStatus < 4 then

        for i = 0, 7 do
            mem.writeU8(base + addrs.flow.unlockedElements + i, nil, 0)
        end
        unlock.questStatus.unlockedElements = 0
        return
    end

    local elementTier = 0

    if override and symbolsModule then
        elementTier = symbolsModule.getValue(mappings.symbols.element)
    else
        local progress = mem.readU16(addrs.storyProgress, nil)
        elementTier = unlock._calculateTier(progress, questline.elementalExchange)
    end

    local unlocks = nil
    if elementTier > 0 and questline.elementalExchange then
        local tierData = questline.elementalExchange
        if tierData.contents and tierData.contents[elementTier] then
            unlocks = tierData.contents[elementTier]
        end
    end

    for i = 0, 7 do
        local elementId = i + 1
        local value = 0
        if unlocks and unlocks[elementId] and unlocks[elementId] > 0 then
            value = 1
        end
        mem.writeU8(base + addrs.flow.unlockedElements + i, nil, value)
    end

    unlock.questStatus.unlockedElements = elementTier
end

function unlock.attributes(base, addrs, questline, symbolsModule)
    if not questline then
        return
    end

    local override = questline.overrideEvents
    local mainStatus = unlock.questStatus.mainQuestStatus

    if mainStatus < 4 then
        for i = 0, 16 do
            mem.writeU8(base + addrs.flow.unlockedAttributes + i, nil, 0)
        end
        unlock.questStatus.unlockedAttributes = 0
        return
    end

    local attrTier = 0

    if override and symbolsModule then
        attrTier = symbolsModule.getValue(mappings.symbols.attribute)
    else

        local progress = mem.readU16(addrs.storyProgress, nil)
        attrTier = unlock._calculateTier(progress, questline.attributeRefinement)
    end

    local unlocks = nil
    if attrTier > 0 and questline.attributeRefinement then
        local tierData = questline.attributeRefinement
        if tierData.contents and tierData.contents[attrTier] then
            unlocks = tierData.contents[attrTier]
        end
    end

    for i = 0, 16 do
        local attrId = i + 10
        local value = 0
        if unlocks and unlocks[attrId] and unlocks[attrId] > 0 then
            value = 1
        end
        mem.writeU8(base + addrs.flow.unlockedAttributes + i, nil, value)
    end

    unlock.questStatus.unlockedAttributes = attrTier
end

function unlock.tiers(base, addrs)
    local elementTier = unlock.questStatus.unlockedElements
    local attrTier = unlock.questStatus.unlockedAttributes

    local maxTier = (elementTier > attrTier) and elementTier or attrTier

    if maxTier == 0 and unlock.questStatus.mainQuestStatus >= 4 then
        maxTier = 1
    end

    mem.flags.set(base, addrs.flow.unlockedTiers, maxTier)
end

function unlock.notification(base, addrs)

    local pendingPopup = mem.flags.get(base, addrs.flow.showPopup)
    local pendingSupply = mem.flags.get(base, addrs.flow.supplyNotification)

    if pendingPopup == 1 or pendingSupply > 0 then
        return
    end

    local actualTierLevel = unlock.questStatus.unlockedElements + unlock.questStatus.unlockedAttributes
    local actualMessageLevel = mathMin(unlock.questStatus.unlockedElements, unlock.questStatus.unlockedAttributes)

    local lastTierLevel = unlock.questStatus.lastTierLevel
    local lastMessageLevel = unlock.questStatus.lastMessageLevel

    if actualTierLevel > lastTierLevel then
        mem.flags.set(base, addrs.flow.showPopup, 1)
        unlock.questStatus.lastTierLevel = actualTierLevel
    end

    if actualMessageLevel > lastMessageLevel then
        mem.flags.set(base, addrs.flow.supplyNotification, actualMessageLevel)
        unlock.questStatus.lastMessageLevel = actualMessageLevel
    end
end

function unlock.update(base, addrs, questline, symbolsModule)
    if not questline then
        return
    end

    unlock.mainQuest(base, addrs, questline, symbolsModule)
    unlock.elements(base, addrs, questline, symbolsModule)
    unlock.attributes(base, addrs, questline, symbolsModule)
    unlock.tiers(base, addrs)
    unlock.notification(base, addrs)
end

function unlock.getQuestStatus()
    return {
        mainQuestStatus = unlock.questStatus.mainQuestStatus,
        unlockedElements = unlock.questStatus.unlockedElements,
        unlockedAttributes = unlock.questStatus.unlockedAttributes,
        lastTierLevel = unlock.questStatus.lastTierLevel,
        lastMessageLevel = unlock.questStatus.lastMessageLevel
    }
end

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

function unlock.resetQuestStatus()
    unlock.questStatus = {
        mainQuestStatus = 0,
        unlockedElements = 0,
        unlockedAttributes = 0,
        lastTierLevel = 0,
        lastMessageLevel = 0
    }
end

function unlock.syncToMemory(base, addrs)

    mem.flags.set(base, addrs.flow.mainQuestStatus, unlock.questStatus.mainQuestStatus)
end

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
    addresses = mappings.addresses
    constants = mappings.constants
    mainQuestStatusValues = constants.mainQuestStatus

    return true
end

return unlock
