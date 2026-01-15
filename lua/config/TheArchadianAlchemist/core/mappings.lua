-- Made By FehDead
-- =====================
-- MAPPINGS MODULE
-- =====================
-- Addresses, definitions, and constants for TheArchadianAlchemist
local mappings = {}

-- =====================
-- MEMORY ADDRESSES
-- =====================

mappings.addresses = {
    base = 0x02099DF0,
    locationId = 0x021654C4,
    storyProgress = 0x2164480, -- 6110

    flow = {
        status = 0x50,
        selected = 0x51,
        success = 0x52,
        reset = 0x53,
        loadEquipment = 0x54,
        checkElement = 0x4E,
        checkAttribute = 0x4B,
        pollMode = 0x4A,
        unlockedTiers = 0x49,

        -- Quest system
        showPopup = 0x29,
        supplyNotification = 0x2A,
        mainQuestGill = 0x2B,
        mainQuestStatus = 0x2F,
        unlockedElements = 0x30, -- 8 bytes: 0x30-0x37
        unlockedAttributes = 0x38 -- 17 bytes: 0x38-0x48
    },

    pollMode = 0x4A,

    selected = {
        category = 0x55,
        subcategory = 0x56,
        equipmentId = 0x57,
        tier = 0x5A
    },

    obtained = {
        initial = 0x5B,
        extra = 0x5D,
        total = 0x5F,
        tier1 = 0x61,
        tier2 = 0x63,
        tier3 = 0x65,
        currentElement = 0x4F,
        currentAttribute = 0x4C
    },

    equipments = {
        upgrades = 0x67,
        list = 0x76
    }
}

-- =====================
-- EQUIPMENT DEFINITIONS
-- =====================

mappings.equipment = {
    [1] = "sword",
    [2] = "greatSword",
    [3] = "katana",
    [4] = "ninjaSword",
    [5] = "spear",
    [6] = "pole",
    [7] = "bow",
    [8] = "crossBow",
    [9] = "gun",
    [10] = "dagger",
    [11] = "rod",
    [12] = "staff",
    [13] = "mace",
    [14] = "axe",
    [15] = "hammer",
    [16] = "handBomb",
    [17] = "measure",
    [18] = "heavyArmor",
    [19] = "lightArmor",
    [20] = "mysticArmor",
    [21] = "heavyHelm",
    [22] = "lightHelm",
    [23] = "mysticHelm",
    [24] = "belt",
    [25] = "boot",
    [26] = "bracelet",
    [27] = "collar",
    [28] = "crown",
    [29] = "glove",
    [30] = "pendant",
    [31] = "ring",
    [32] = "arrow",
    [33] = "bolt",
    [34] = "bomb",
    [35] = "shot",
    [36] = "shield"
}

-- =====================
-- ATTRIBUTE DEFINITIONS
-- =====================
--[[
    Format: [id] = {name, accessType, offset}
    accessType: "direct" = read from bpack directly
                "linked" = read from attributePointer + offset
]]

mappings.attribute = {
    [10] = {
        "range",
        "direct"
    },
    [11] = {
        "chargeTime",
        "direct"
    },
    [12] = {
        "attackPower",
        "direct"
    },
    [13] = {
        "onHitRate",
        "direct"
    },
    [14] = {
        "knockbackChance",
        "direct"
    },
    [15] = {
        "comboOrCriticalChance",
        "direct"
    },
    [16] = {
        "evadeWeapon",
        "direct"
    },
    [17] = {
        "evadeShield",
        "direct"
    },
    [18] = {
        "magickEvadeShield",
        "direct"
    },
    [19] = {
        "defense",
        "direct"
    },
    [20] = {
        "magickResist",
        "direct"
    },
    [21] = {
        "maxHp",
        "linked",
        0x00
    },
    [22] = {
        "maxMp",
        "linked",
        0x02
    },
    [23] = {
        "strength",
        "linked",
        0x04
    },
    [24] = {
        "magickPower",
        "linked",
        0x05
    },
    [25] = {
        "vitality",
        "linked",
        0x06
    },
    [26] = {
        "speed",
        "linked",
        0x07
    }
}

-- =====================
-- ELEMENT DEFINITIONS
-- =====================

mappings.element = {
    [1] = "fire",
    [2] = "lightning",
    [3] = "ice",
    [4] = "earth",
    [5] = "water",
    [6] = "wind",
    [7] = "holy",
    [8] = "dark"
}

-- =====================
-- CONSTANTS
-- =====================

mappings.constants = {
    targetLocation = 632,
    equipmentBaseId = 4096,

    -- Attribute ID ranges
    attributeMin = 10,
    attributeMax = 26,

    -- Element ID ranges
    elementMin = 1,
    elementMax = 8,

    -- Tier ranges
    tierMin = 1,
    tierMax = 3,

    -- Special IDs
    removeId = 9,

    -- MainQuest status values
    mainQuestStatus = {
        notStarted = 0,
        canStart = 1,
        waitingProgress = 2,
        canFinish = 3,
        completed = 4
    }
}

-- =====================
-- FLOW EVENTS
-- =====================

mappings.flowEvents = {
    talk = "talk",
    reset = "reset",
    result = "result",
    loadEquipment = "loadEquipment",
    equipmentSelected = "equipmentSelected",
    checkElement = "checkElement",
    checkAttribute = "checkAttribute",
    element = "element",
    attribute = "attribute"
}

-- =====================
-- FLOW INTERVALS (ms)
-- =====================

mappings.flowIntervals = {
    idle = 2000,
    talk = 200,
    sync = 20
}

-- =====================
-- SYMBOLS
-- =====================

mappings.symbols = {
    taa = {
        "TAA_QuestStatus",
        "TAA_ElementStatus",
        "TAA_AttributeStatus"
    },
    dd = "dd_refresh",

    -- Symbol name mapping for getValue
    main = "TAA_QuestStart",
    element = "TAA_ElementStatus",
    attribute = "TAA_AttributeStatus"
}

return mappings
