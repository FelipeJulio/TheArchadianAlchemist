local upgrades = {
    attackPower = { -- {item, quantity}, gil
    {{8329, 1}, {8330, 1}, {8331, 1}, 900}, -- tier 1
    {{8288, 2}, {8297, 2}, {8298, 2}, 8200}, -- tier 2
    {{8299, 3}, {8300, 3}, {8274, 3}, 21500} -- tier 3
    },
    evadeWeapon = { -- {item, quantity}, gil
    {{8275, 1}, {8301, 1}, {8302, 1}, 1350}, -- tier 1
    {{8303, 2}, {8304, 2}, {8335, 2}, 5400}, -- tier 2
    {{8310, 3}, {8311, 3}, {8313, 3}, 16800} -- tier 3
    },
    onHitRate = { -- {item, quantity}, gil
    {{8368, 1}, {8401, 1}, {8402, 1}, 750}, -- tier 1
    {{8290, 2}, {8291, 2}, {8292, 2}, 9100}, -- tier 2
    {{8293, 3}, {8270, 3}, {8271, 3}, 19800} -- tier 3
    },
    maxHp = { -- {item, quantity}, gil
    {{8272, 1}, {8340, 1}, {8334, 1}, 500}, -- tier 1
    {{8388, 2}, {8320, 2}, {8321, 2}, 1800}, -- tier 2
    {{8372, 3}, {8373, 3}, {8344, 3}, 6200} -- tier 3
    },
    maxMp = { -- {item, quantity}, gil
    {{8345, 1}, {8346, 1}, {8314, 1}, 550}, -- tier 1
    {{8315, 2}, {8318, 2}, {8329, 2}, 2100}, -- tier 2
    {{8330, 3}, {8331, 3}, {8288, 3}, 7300} -- tier 3
    },
    strength = { -- {item, quantity}, gil
    {{8297, 1}, {8298, 1}, {8299, 1}, 1850}, -- tier 1
    {{8300, 2}, {8274, 2}, {8275, 2}, 14200}, -- tier 2
    {{8301, 3}, {8302, 3}, {8303, 3}, 29500} -- tier 3
    },
    magickPower = { -- {item, quantity}, gil
    {{8304, 1}, {8335, 1}, {8310, 1}, 1650}, -- tier 1
    {{8311, 2}, {8313, 2}, {8368, 2}, 15800}, -- tier 2
    {{8401, 3}, {8402, 3}, {8290, 3}, 28750} -- tier 3
    },
    vitality = { -- {item, quantity}, gil
    {{8291, 1}, {8292, 1}, {8293, 1}, 1750}, -- tier 1
    {{8270, 2}, {8271, 2}, {8272, 2}, 13100}, -- tier 2
    {{8340, 3}, {8334, 3}, {8388, 3}, 26250} -- tier 3
    },
    speed = { -- {item, quantity}, gil
    {{8320, 1}, {8321, 1}, {8372, 1}, 800}, -- tier 1
    {{8373, 2}, {8344, 2}, {8345, 2}, 4800}, -- tier 2
    {{8346, 3}, {8314, 3}, {8315, 3}, 14350} -- tier 3
    },
    defense = { -- {item, quantity}, gil
    {{8318, 1}, {8329, 1}, {8330, 1}, 950}, -- tier 1
    {{8331, 2}, {8288, 2}, {8297, 2}, 7100}, -- tier 2
    {{8298, 3}, {8299, 3}, {8300, 3}, 18650} -- tier 3
    },
    magickResist = { -- {item, quantity}, gil
    {{8274, 1}, {8275, 1}, {8301, 1}, 1050}, -- tier 1
    {{8302, 2}, {8303, 2}, {8304, 2}, 5900}, -- tier 2
    {{8335, 3}, {8310, 3}, {8311, 3}, 17600} -- tier 3
    },
    evadeShield = { -- {item, quantity}, gil
    {{8313, 1}, {8368, 1}, {8401, 1}, 700}, -- tier 1
    {{8402, 2}, {8290, 2}, {8291, 2}, 5200}, -- tier 2
    {{8292, 3}, {8293, 3}, {8270, 3}, 15850} -- tier 3
    },
    magickEvadeShield = { -- {item, quantity}, gil
    {{8271, 1}, {8272, 1}, {8340, 1}, 850}, -- tier 1
    {{8334, 2}, {8388, 2}, {8320, 2}, 6400}, -- tier 2
    {{8321, 3}, {8372, 3}, {8373, 3}, 16750} -- tier 3
    },
    knockbackChance = { -- {item, quantity}, gil
    {{8344, 1}, {8345, 1}, {8346, 1}, 1200}, -- tier 1
    {{8314, 2}, {8315, 2}, {8318, 2}, 8900}, -- tier 2
    {{8329, 3}, {8330, 3}, {8331, 3}, 20450} -- tier 3
    },
    comboOrCriticalChance = { -- {item, quantity}, gil
    {{8288, 1}, {8297, 1}, {8298, 1}, 1950}, -- tier 1
    {{8299, 2}, {8300, 2}, {8274, 2}, 14950}, -- tier 2
    {{8275, 3}, {8301, 3}, {8302, 3}, 30750} -- tier 3
    },
    range = { -- {item, quantity}, gil
    {{8303, 1}, {8304, 1}, {8335, 1}, 650}, -- tier 1
    {{8310, 2}, {8311, 2}, {8313, 2}, 5600}, -- tier 2
    {{8368, 3}, {8401, 3}, {8402, 3}, 17400} -- tier 3
    },
    chargeTime = { -- {item, quantity}, gil
    {{8290, 1}, {8291, 1}, {8292, 1}, 2050}, -- tier 1
    {{8293, 2}, {8270, 2}, {8271, 2}, 16200}, -- tier 2
    {{8272, 3}, {8340, 3}, {8334, 3}, 31500} -- tier 3
    },
    remove = { -- {item, quantity}, gil
    {{8388, 1}, {8320, 1}, {8321, 1}, 500}, -- tier 1
    {{8372, 2}, {8373, 2}, {8344, 2}, 4500}, -- tier 2
    {{8345, 3}, {8346, 3}, {8314, 3}, 15500} -- tier 3
    }
}

local values = {
    sword = { -- tier 1, tier 2, tier 3
        range = {2, 5, 7},
        chargeTime = {3, 7, 12},
        attackPower = {10, 25, 40},
        evadeWeapon = {1, 3, 5},
        knockbackChance = {2, 8, 14},
        comboOrCriticalChance = {3, 8, 13},
        onHitRate = {3, 9, 15},
        maxHp = {100, 350, 600},
        maxMp = {50, 160, 300},
        strength = {2, 5, 9},
        magickPower = {1, 4, 8},
        vitality = {3, 6, 9},
        speed = {2, 5, 7}
    },
    greatSword = { -- tier 1, tier 2, tier 3
        range = {2, 5, 7},
        chargeTime = {3, 7, 12},
        attackPower = {10, 25, 40},
        evadeWeapon = {1, 3, 5},
        knockbackChance = {2, 8, 14},
        comboOrCriticalChance = {3, 8, 13},
        onHitRate = {3, 9, 15},
        maxHp = {100, 350, 600},
        maxMp = {50, 160, 300},
        strength = {2, 5, 9},
        magickPower = {1, 4, 8},
        vitality = {3, 6, 9},
        speed = {2, 5, 7}
    },
    katana = { -- tier 1, tier 2, tier 3
        range = {2, 5, 7},
        chargeTime = {3, 7, 12},
        attackPower = {10, 25, 40},
        evadeWeapon = {1, 3, 5},
        knockbackChance = {2, 8, 14},
        comboOrCriticalChance = {3, 8, 13},
        onHitRate = {3, 9, 15},
        maxHp = {100, 350, 600},
        maxMp = {50, 160, 300},
        strength = {2, 5, 9},
        magickPower = {1, 4, 8},
        vitality = {3, 6, 9},
        speed = {2, 5, 7}
    },
    ninjaSword = { -- tier 1, tier 2, tier 3
        range = {2, 5, 7},
        chargeTime = {3, 7, 12},
        attackPower = {10, 25, 40},
        evadeWeapon = {1, 3, 5},
        knockbackChance = {2, 8, 14},
        comboOrCriticalChance = {3, 8, 13},
        onHitRate = {3, 9, 15},
        maxHp = {100, 350, 600},
        maxMp = {50, 160, 300},
        strength = {2, 5, 9},
        magickPower = {1, 4, 8},
        vitality = {3, 6, 9},
        speed = {2, 5, 7}
    },
    spear = { -- tier 1, tier 2, tier 3
        range = {2, 5, 7},
        chargeTime = {3, 7, 12},
        attackPower = {10, 25, 40},
        evadeWeapon = {1, 3, 5},
        knockbackChance = {2, 8, 14},
        comboOrCriticalChance = {3, 8, 13},
        onHitRate = {3, 9, 15},
        maxHp = {100, 350, 600},
        maxMp = {50, 160, 300},
        strength = {2, 5, 9},
        magickPower = {1, 4, 8},
        vitality = {3, 6, 9},
        speed = {2, 5, 7}
    },
    pole = { -- tier 1, tier 2, tier 3
        range = {2, 5, 7},
        chargeTime = {3, 7, 12},
        attackPower = {10, 25, 40},
        evadeWeapon = {1, 3, 5},
        knockbackChance = {2, 8, 14},
        comboOrCriticalChance = {3, 8, 13},
        onHitRate = {3, 9, 15},
        maxHp = {100, 350, 600},
        maxMp = {50, 160, 300},
        strength = {2, 5, 9},
        magickPower = {1, 4, 8},
        vitality = {3, 6, 9},
        speed = {2, 5, 7}
    },
    bow = { -- tier 1, tier 2, tier 3
        range = {2, 5, 7},
        chargeTime = {3, 7, 12},
        attackPower = {10, 25, 40},
        evadeWeapon = {1, 3, 5},
        knockbackChance = {2, 8, 14},
        comboOrCriticalChance = {3, 8, 13},
        onHitRate = {3, 9, 15},
        maxHp = {100, 350, 600},
        maxMp = {50, 160, 300},
        strength = {2, 5, 9},
        magickPower = {1, 4, 8},
        vitality = {3, 6, 9},
        speed = {2, 5, 7}
    },
    crossBow = { -- tier 1, tier 2, tier 3
        range = {2, 5, 7},
        chargeTime = {3, 7, 12},
        attackPower = {10, 25, 40},
        evadeWeapon = {1, 3, 5},
        knockbackChance = {2, 8, 14},
        comboOrCriticalChance = {3, 8, 13},
        onHitRate = {3, 9, 15},
        maxHp = {100, 350, 600},
        maxMp = {50, 160, 300},
        strength = {2, 5, 9},
        magickPower = {1, 4, 8},
        vitality = {3, 6, 9},
        speed = {2, 5, 7}
    },
    gun = { -- tier 1, tier 2, tier 3
        range = {2, 5, 7},
        chargeTime = {3, 7, 12},
        attackPower = {10, 25, 40},
        evadeWeapon = {1, 3, 5},
        knockbackChance = {2, 8, 14},
        comboOrCriticalChance = {3, 8, 13},
        onHitRate = {3, 9, 15},
        maxHp = {100, 350, 600},
        maxMp = {50, 160, 300},
        strength = {2, 5, 9},
        magickPower = {1, 4, 8},
        vitality = {3, 6, 9},
        speed = {2, 5, 7}
    },
    dagger = { -- tier 1, tier 2, tier 3
        range = {2, 5, 7},
        chargeTime = {3, 7, 12},
        attackPower = {10, 25, 40},
        evadeWeapon = {1, 3, 5},
        knockbackChance = {2, 8, 14},
        comboOrCriticalChance = {3, 8, 13},
        onHitRate = {3, 9, 15},
        maxHp = {100, 350, 600},
        maxMp = {50, 160, 300},
        strength = {2, 5, 9},
        magickPower = {1, 4, 8},
        vitality = {3, 6, 9},
        speed = {2, 5, 7}
    },
    rod = { -- tier 1, tier 2, tier 3
        range = {2, 5, 7},
        chargeTime = {3, 7, 12},
        attackPower = {10, 25, 40},
        evadeWeapon = {1, 3, 5},
        knockbackChance = {2, 8, 14},
        comboOrCriticalChance = {3, 8, 13},
        onHitRate = {3, 9, 15},
        maxHp = {100, 350, 600},
        maxMp = {50, 160, 300},
        strength = {2, 5, 9},
        magickPower = {1, 4, 8},
        vitality = {3, 6, 9},
        speed = {2, 5, 7}
    },
    staff = { -- tier 1, tier 2, tier 3
        range = {2, 5, 7},
        chargeTime = {3, 7, 12},
        attackPower = {10, 25, 40},
        evadeWeapon = {1, 3, 5},
        knockbackChance = {2, 8, 14},
        comboOrCriticalChance = {3, 8, 13},
        onHitRate = {3, 9, 15},
        maxHp = {100, 350, 600},
        maxMp = {50, 160, 300},
        strength = {2, 5, 9},
        magickPower = {1, 4, 8},
        vitality = {3, 6, 9},
        speed = {2, 5, 7}
    },
    mace = { -- tier 1, tier 2, tier 3
        range = {2, 5, 7},
        chargeTime = {3, 7, 12},
        attackPower = {10, 25, 40},
        evadeWeapon = {1, 3, 5},
        knockbackChance = {2, 8, 14},
        comboOrCriticalChance = {3, 8, 13},
        onHitRate = {3, 9, 15},
        maxHp = {100, 350, 600},
        maxMp = {50, 160, 300},
        strength = {2, 5, 9},
        magickPower = {1, 4, 8},
        vitality = {3, 6, 9},
        speed = {2, 5, 7}
    },
    axe = { -- tier 1, tier 2, tier 3
        range = {2, 5, 7},
        chargeTime = {3, 7, 12},
        attackPower = {10, 25, 40},
        evadeWeapon = {1, 3, 5},
        knockbackChance = {2, 8, 14},
        comboOrCriticalChance = {3, 8, 13},
        onHitRate = {3, 9, 15},
        maxHp = {100, 350, 600},
        maxMp = {50, 160, 300},
        strength = {2, 5, 9},
        magickPower = {1, 4, 8},
        vitality = {3, 6, 9},
        speed = {2, 5, 7}
    },
    hammer = { -- tier 1, tier 2, tier 3
        range = {2, 5, 7},
        chargeTime = {3, 7, 12},
        attackPower = {10, 25, 40},
        evadeWeapon = {1, 3, 5},
        knockbackChance = {2, 8, 14},
        comboOrCriticalChance = {3, 8, 13},
        onHitRate = {3, 9, 15},
        maxHp = {100, 350, 600},
        maxMp = {50, 160, 300},
        strength = {2, 5, 9},
        magickPower = {1, 4, 8},
        vitality = {3, 6, 9},
        speed = {2, 5, 7}
    },
    handBomb = { -- tier 1, tier 2, tier 3
        range = {2, 5, 7},
        chargeTime = {3, 7, 12},
        attackPower = {10, 25, 40},
        evadeWeapon = {1, 3, 5},
        knockbackChance = {2, 8, 14},
        comboOrCriticalChance = {3, 8, 13},
        onHitRate = {3, 9, 15},
        maxHp = {100, 350, 600},
        maxMp = {50, 160, 300},
        strength = {2, 5, 9},
        magickPower = {1, 4, 8},
        vitality = {3, 6, 9},
        speed = {2, 5, 7}
    },
    measure = { -- tier 1, tier 2, tier 3
        range = {2, 5, 7},
        chargeTime = {3, 7, 12},
        attackPower = {10, 25, 40},
        evadeWeapon = {1, 3, 5},
        knockbackChance = {2, 8, 14},
        comboOrCriticalChance = {3, 8, 13},
        onHitRate = {3, 9, 15},
        maxHp = {100, 350, 600},
        maxMp = {50, 160, 300},
        strength = {2, 5, 9},
        magickPower = {1, 4, 8},
        vitality = {3, 6, 9},
        speed = {2, 5, 7}
    },
    heavyArmor = { -- tier 1, tier 2, tier 3
        defense = {3, 7, 11},
        magickResist = {3, 8, 14},
        maxHp = {100, 350, 600},
        maxMp = {50, 160, 300},
        strength = {2, 5, 9},
        magickPower = {1, 4, 8},
        vitality = {3, 6, 9},
        speed = {2, 5, 7}
    },
    lightArmor = { -- tier 1, tier 2, tier 3
        defense = {3, 7, 11},
        magickResist = {3, 8, 14},
        maxHp = {100, 350, 600},
        maxMp = {50, 160, 300},
        strength = {2, 5, 9},
        magickPower = {1, 4, 8},
        vitality = {3, 6, 9},
        speed = {2, 5, 7}
    },
    mysticArmor = { -- tier 1, tier 2, tier 3
        defense = {3, 7, 11},
        magickResist = {3, 8, 14},
        maxHp = {100, 350, 600},
        maxMp = {50, 160, 300},
        strength = {2, 5, 9},
        magickPower = {1, 4, 8},
        vitality = {3, 6, 9},
        speed = {2, 5, 7}
    },
    heavyHelm = { -- tier 1, tier 2, tier 3
        defense = {3, 7, 11},
        magickResist = {3, 8, 14},
        maxHp = {100, 350, 600},
        maxMp = {50, 160, 300},
        strength = {2, 5, 9},
        magickPower = {1, 4, 8},
        vitality = {3, 6, 9},
        speed = {2, 5, 7}
    },
    lightHelm = { -- tier 1, tier 2, tier 3
        defense = {3, 7, 11},
        magickResist = {3, 8, 14},
        maxHp = {100, 350, 600},
        maxMp = {50, 160, 300},
        strength = {2, 5, 9},
        magickPower = {1, 4, 8},
        vitality = {3, 6, 9},
        speed = {2, 5, 7}
    },
    mysticHelm = { -- tier 1, tier 2, tier 3
        defense = {3, 7, 11},
        magickResist = {3, 8, 14},
        maxHp = {100, 350, 600},
        maxMp = {50, 160, 300},
        strength = {2, 5, 9},
        magickPower = {1, 4, 8},
        vitality = {3, 6, 9},
        speed = {2, 5, 7}
    },
    belt = { -- tier 1, tier 2, tier 3
        defense = {3, 7, 11},
        magickResist = {3, 8, 14},
        maxHp = {100, 350, 600},
        maxMp = {50, 160, 300},
        strength = {2, 5, 9},
        magickPower = {1, 4, 8},
        vitality = {3, 6, 9},
        speed = {2, 5, 7}
    },
    boot = { -- tier 1, tier 2, tier 3
        defense = {3, 7, 11},
        magickResist = {3, 8, 14},
        maxHp = {100, 350, 600},
        maxMp = {50, 160, 300},
        strength = {2, 5, 9},
        magickPower = {1, 4, 8},
        vitality = {3, 6, 9},
        speed = {2, 5, 7}
    },
    bracelet = { -- tier 1, tier 2, tier 3
        defense = {3, 7, 11},
        magickResist = {3, 8, 14},
        maxHp = {100, 350, 600},
        maxMp = {50, 160, 300},
        strength = {2, 5, 9},
        magickPower = {1, 4, 8},
        vitality = {3, 6, 9},
        speed = {2, 5, 7}
    },
    collar = { -- tier 1, tier 2, tier 3
        defense = {3, 7, 11},
        magickResist = {3, 8, 14},
        maxHp = {100, 350, 600},
        maxMp = {50, 160, 300},
        strength = {2, 5, 9},
        magickPower = {1, 4, 8},
        vitality = {3, 6, 9},
        speed = {2, 5, 7}
    },
    crown = { -- tier 1, tier 2, tier 3
        defense = {3, 7, 11},
        magickResist = {3, 8, 14},
        maxHp = {100, 350, 600},
        maxMp = {50, 160, 300},
        strength = {2, 5, 9},
        magickPower = {1, 4, 8},
        vitality = {3, 6, 9},
        speed = {2, 5, 7}
    },
    glove = { -- tier 1, tier 2, tier 3
        defense = {3, 7, 11},
        magickResist = {3, 8, 14},
        maxHp = {100, 350, 600},
        maxMp = {50, 160, 300},
        strength = {2, 5, 9},
        magickPower = {1, 4, 8},
        vitality = {3, 6, 9},
        speed = {2, 5, 7}
    },
    pendant = { -- tier 1, tier 2, tier 3
        defense = {3, 7, 11},
        magickResist = {3, 8, 14},
        maxHp = {100, 350, 600},
        maxMp = {50, 160, 300},
        strength = {2, 5, 9},
        magickPower = {1, 4, 8},
        vitality = {3, 6, 9},
        speed = {2, 5, 7}
    },
    ring = { -- tier 1, tier 2, tier 3
        defense = {3, 7, 11},
        magickResist = {3, 8, 14},
        maxHp = {100, 350, 600},
        maxMp = {50, 160, 300},
        strength = {2, 5, 9},
        magickPower = {1, 4, 8},
        vitality = {3, 6, 9},
        speed = {2, 5, 7}
    },
    arrow = { -- tier 1, tier 2, tier 3
        attackPower = {1, 2, 3},
        evadeWeapon = {1, 3, 5},
        onHitRate = {3, 9, 15},
        maxHp = {100, 350, 600},
        maxMp = {50, 160, 300},
        strength = {2, 5, 9},
        magickPower = {1, 4, 8},
        vitality = {3, 6, 9},
        speed = {2, 5, 7}
    },
    bolt = { -- tier 1, tier 2, tier 3
        attackPower = {2, 3, 4},
        evadeWeapon = {1, 3, 5},
        onHitRate = {3, 9, 15},
        maxHp = {100, 350, 600},
        maxMp = {50, 160, 300},
        strength = {2, 5, 9},
        magickPower = {1, 4, 8},
        vitality = {3, 6, 9},
        speed = {2, 5, 7}
    },
    bomb = { -- tier 1, tier 2, tier 3
        attackPower = {3, 4, 5},
        evadeWeapon = {1, 3, 5},
        onHitRate = {3, 9, 15},
        maxHp = {100, 350, 600},
        maxMp = {50, 160, 300},
        strength = {2, 5, 9},
        magickPower = {1, 4, 8},
        vitality = {3, 6, 9},
        speed = {2, 5, 7}
    },
    shot = { -- tier 1, tier 2, tier 3
        attackPower = {1, 2, 3},
        evadeWeapon = {1, 3, 5},
        onHitRate = {3, 9, 15},
        maxHp = {100, 350, 600},
        maxMp = {50, 160, 300},
        strength = {2, 5, 9},
        magickPower = {1, 4, 8},
        vitality = {3, 6, 9},
        speed = {2, 5, 7}
    },
    shield = { -- tier 1, tier 2, tier 3
        evadeShield = {2, 5, 8},
        magickEvadeShield = {3, 6, 10},
        maxHp = {100, 350, 600},
        maxMp = {50, 160, 300},
        strength = {2, 5, 9},
        magickPower = {1, 4, 8},
        vitality = {3, 6, 9},
        speed = {2, 5, 7}
    }
}

return {
    upgrades = upgrades,
    values = values
}
