local questline = {
    overrideEvents = true,
    mainQuest = {
        id = 1000,
        gill = 100000
    },
    elementalExchange = {
        [1] = {
            id = 1240,
            unlocks = {
                fire = 1,
                lightning = 1,
                ice = 1,
                earth = 0,
                water = 0,
                wind = 0,
                holy = 0,
                dark = 0
            }
        },
        [2] = {
            id = 1580,
            unlocks = {
                fire = 1,
                lightning = 1,
                ice = 1,
                earth = 1,
                water = 1,
                wind = 1,
                holy = 0,
                dark = 0
            }
        },
        [3] = {
            id = 4150,
            unlocks = {
                fire = 1,
                lightning = 1,
                ice = 1,
                earth = 1,
                water = 1,
                wind = 1,
                holy = 1,
                dark = 1
            }
        }
    },
    attributeRefinement = {
        [1] = {
            id = 1300,
            unlocks = {
                range = 0,
                chargeTime = 0,
                attackPower = 0,
                onHitRate = 0,
                knockbackChance = 0,
                comboOrCriticalChance = 0,
                evadeWeapon = 0,
                evadeShield = 0,
                magickEvadeShield = 0,
                defense = 1,
                magickResist = 1,
                maxHp = 1,
                maxMp = 1,
                strength = 0,
                magickPower = 0,
                vitality = 1,
                speed = 0
            }
        },
        [2] = {
            id = 2050,
            unlocks = {
                range = 0,
                chargeTime = 0,
                attackPower = 1,
                onHitRate = 0,
                knockbackChance = 0,
                comboOrCriticalChance = 0,
                evadeWeapon = 1,
                evadeShield = 1,
                magickEvadeShield = 1,
                defense = 1,
                magickResist = 1,
                maxHp = 1,
                maxMp = 1,
                strength = 1,
                magickPower = 1,
                vitality = 1,
                speed = 0
            }
        },
        [3] = {
            id = 4450,
            unlocks = {
                range = 1,
                chargeTime = 1,
                attackPower = 1,
                onHitRate = 1,
                knockbackChance = 1,
                comboOrCriticalChance = 1,
                evadeWeapon = 1,
                evadeShield = 1,
                magickEvadeShield = 1,
                defense = 1,
                magickResist = 1,
                maxHp = 1,
                maxMp = 1,
                strength = 1,
                magickPower = 1,
                vitality = 1,
                speed = 1
            }
        }
    }
}

return questline
