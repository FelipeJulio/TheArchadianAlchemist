-- Made By FehDead
local mappings = {}

mappings.addresses = {
	base = 0x02099DF0,
	locationId = 0x021654C4,
	storyProgress = 0x2164480,
	flow = {
		pollMode = 0x64,
		checkAttribute = 0x65,
		checkElement = 0x66,
		talkStatus = 0x67,
		selectedIntention = 0x68,
		confirmedIntention = 0x69,
		resetFlow = 0x6A,
		loadEquipment = 0x6B
	},
	notification = {
		showTierMessage = 0x6C,
		showSupplyMessage = 0x6D
	},
	quest = {
		unlockedTiers = 0x6E,
		mainQuestStatus = 0x6F,
		unlockedElements = 0x70,
		unlockedAttributes = 0x78,
		mainQuestGil = 0x90
	},
	selected = {
		selectedCategory = 0x89,
		selectedSubcategory = 0x8A,
		selectedTier = 0x8B,
		selectedEquipmentId = 0x8E
	},
	refinement = {
		defaultAttributeValue = 0x94,
		extraAttributeValue = 0x96,
		totalAttributeValue = 0x98,
		tier1AttributeValue = 0x9A,
		tier2AttributeValue = 0x9C,
		tier3AttributeValue = 0x9E
	},
	current = {
		currentElement = 0x8C,
		currentAttribute = 0x8D
	},
	load = {
		upgradeList = 0xA0,
		blockList = 0xB0
	}
}

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
	[10] = "axe",
	[11] = "hammer",
	[12] = "dagger",
	[13] = "rod",
	[14] = "staff",
	[15] = "mace",
	[16] = "measure",
	[17] = "handBomb",
	[18] = "shield",
	[19] = "lightHelm",
	[20] = "mysticHelm",
	[21] = "heavyHelm",
	[22] = "lightArmor",
	[23] = "mysticArmor",
	[24] = "heavyArmor",
	[25] = "ring",
	[26] = "bracelet",
	[27] = "glove",
	[28] = "collar",
	[29] = "pendant",
	[30] = "belt",
	[31] = "boot",
	[32] = "crown",
	[33] = "arrow",
	[34] = "bolt",
	[35] = "shot",
	[36] = "bomb"
}

mappings.attribute = {
	[10] = {"range", "direct"},
	[11] = {"chargeTime", "direct"},
	[12] = {"attackPower", "direct"},
	[13] = {"onHitRate", "direct"},
	[14] = {"knockbackChance", "direct"},
	[15] = {"comboOrCriticalChance", "direct"},
	[16] = {"evadeWeapon", "direct"},
	[17] = {"evadeShield", "direct"},
	[18] = {"magickEvadeShield", "direct"},
	[19] = {"defense", "direct"},
	[20] = {"magickResist", "direct"},
	[21] = {"maxHp", "linked", 0x00},
	[22] = {"maxMp", "linked", 0x02},
	[23] = {"strength", "linked", 0x04},
	[24] = {"magickPower", "linked", 0x05},
	[25] = {"vitality", "linked", 0x06},
	[26] = {"speed", "linked", 0x07}
}

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

mappings.constants = {
	targetLocation = 632,
	equipmentBaseId = 4096,
	attributeMin = 10,
	attributeMax = 26,
	elementMin = 1,
	elementMax = 8,
	tierMin = 1,
	tierMax = 3,
	removeId = 9,
	mainQuestStatus = {
		notStarted = 0,
		canStart = 1,
		waitingProgress = 2,
		canFinish = 3,
		completed = 4
	}
}

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

mappings.flowIntervals = {
	idle = 2000,
	talk = 200,
	sync = 20
}

return mappings
