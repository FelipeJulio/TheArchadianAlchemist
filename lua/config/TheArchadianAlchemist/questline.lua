-- @description: define the content to be unlocked based on in-game events.
local questline = {
    mainQuest = {
        -- @description: todo
        ids = {1000}
    },
    elementalExchange = {
        -- @description: story point ids to unlock each tier
        ids = {1240, 1580, 4150},
        -- @description: elements unlocked in each tier; when set to 0, the option becomes hidden
        contents = {{ -- tier 1
            fire = 1,
            lightning = 1,
            ice = 1,
            earth = 0,
            water = 0,
            wind = 0,
            holy = 0,
            dark = 0
        }, { -- tier 2
            fire = 1,
            lightning = 1,
            ice = 1,
            earth = 1,
            water = 1,
            wind = 1,
            holy = 0,
            dark = 0
        }, { -- tier 3
            fire = 1,
            lightning = 1,
            ice = 1,
            earth = 1,
            water = 1,
            wind = 1,
            holy = 1,
            dark = 1
        }}
    },
    attributeRefinement = {
        -- @description: story point ids to unlock each tier
        ids = {1300, 2050, 4450},
        -- @description: elements unlocked in each tier; when set to 0, the option becomes hidde
        contents = {{ -- tier 1
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
        }, { -- tier 2
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
        }, { -- tier 3
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
        }}
    }
}

return questline
