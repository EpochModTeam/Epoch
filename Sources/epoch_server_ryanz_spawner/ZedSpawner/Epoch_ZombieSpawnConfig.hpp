class Epoch_ZedSpawner {
	Ryanzombiesdamage = 0.018;					// How much damage should one hit by a Zombie do on a Player - default = 0.1
	Ryanzombieshealth = 0.95;					// Health (Damage) of Zombies on Spawn - Make them easy to kill -> 0.9
	ryanzombiesinfectedchance = 0;				// Not used here - Default = 50
	ryanzombiesinfectedrate = 0;				// Not used here - Default = 0.1
	ryanzombiesinfectedsymptoms = 0;			// Not used here - Default = 1
	ryanzombiesinfecteddeath = 0;				// Not used here - Default = 1
	ryanzombiesantivirusduration = 0;			// Not used here - Default = 300
	ryanzombiesglow = 1;						// Enable / Disable Glowing Eyes for Zombies
	Ryanzombieslimit = 200;						// Internal check distance for RyanScripts (to engage with Players). Reduced for performance - default = 5000

	NoZedAreas[] = {							// Array of coords, where no Zeds can Spawn
		
	};					
	MaxOverallZeds = 50;						// Limit for Overall Zeds on the Map
	DeleteDistance = 200;						// If no Player is within x meters, the Zed will get deleted
	StuckOrDeadCheckTime = 180;					// Stucked or Dead Zeds will be deleted after about x seconds

	BlackListedVehicles[] = {					// Players inside these VehicleTypes will not spawn any Zeds. Can be ["Landvehicle","SHIP","AIR","TANK"]
		"SHIP",
		"AIR"
	};
	ZedCheckTimer = 50;							// Timer, how often the script should check for a ZombieSpawn
	ZedSpawnArr[] = {
	//	[HousesInRange,	SpawnChance,	MinSpawn, 	MaxSpawn, 	MaxZedsInRange]
		{0,				15,				0,			2,			3			},
		{2,				15,				1,			2,			4			},
		{4,				20,				1,			3,			5 			},
		{6,				20,				2,			4,			6			},
		{8,				25,				2,			4,			7			},
		{10,			25,				3,			5,			8			},
		{15,			30,				3,			6,			10			},
		{20,			30,				4,			7,			10			},
		{25,			35,				5,			7,			15			}
	};
	ZedClasses[] = {
		// Fast RyanZ CIV
		/*
		"RyanZombieC_man_1","RyanZombieC_man_polo_1_F","RyanZombieC_man_polo_2_F","RyanZombieC_man_polo_4_F","RyanZombieC_man_polo_5_F","RyanZombieC_man_polo_6_F","RyanZombieC_man_p_fugitive_F","RyanZombieC_man_w_worker_F",
		"RyanZombieC_scientist_F","RyanZombieC_man_hunter_1_F","RyanZombieC_man_pilot_F","RyanZombieC_journalist_F","RyanZombieC_Orestes","RyanZombieC_Nikos","RyanZombie15","RyanZombie16","RyanZombie17","RyanZombie18",
		"RyanZombie19","RyanZombie20","RyanZombie21","RyanZombie22","RyanZombie23","RyanZombie24","RyanZombie25","RyanZombie26","RyanZombie27","RyanZombie28","RyanZombie29","RyanZombie30","RyanZombie31","RyanZombie32",
*/

		// Mid RyanZ CIV
/*
		"RyanZombieC_man_1medium","RyanZombieC_man_polo_1_Fmedium","RyanZombieC_man_polo_2_Fmedium","RyanZombieC_man_polo_4_Fmedium","RyanZombieC_man_polo_5_Fmedium","RyanZombieC_man_polo_6_Fmedium","RyanZombieC_man_p_fugitive_Fmedium",
		"RyanZombieC_man_w_worker_Fmedium","RyanZombieC_scientist_Fmedium","RyanZombieC_man_hunter_1_Fmedium","RyanZombieC_man_pilot_Fmedium","RyanZombieC_journalist_Fmedium","RyanZombieC_Orestesmedium","RyanZombieC_Nikosmedium",
		"RyanZombie15medium","RyanZombie16medium","RyanZombie17medium","RyanZombie18medium","RyanZombie19medium","RyanZombie20medium","RyanZombie21medium","RyanZombie22medium","RyanZombie23medium","RyanZombie24medium",
		"RyanZombie25medium","RyanZombie26medium","RyanZombie27medium","RyanZombie28medium","RyanZombie29medium","RyanZombie30medium","RyanZombie31medium","RyanZombie32medium",
*/

		// Slow RyanZ CIV
		"RyanZombieC_man_1slow","RyanZombieC_man_polo_1_Fslow","RyanZombieC_man_polo_2_Fslow","RyanZombieC_man_polo_4_Fslow","RyanZombieC_man_polo_5_Fslow","RyanZombieC_man_polo_6_Fslow","RyanZombieC_man_p_fugitive_Fslow",
		"RyanZombieC_man_w_worker_Fslow","RyanZombieC_scientist_Fslow","RyanZombieC_man_hunter_1_Fslow","RyanZombieC_man_pilot_Fslow","RyanZombieC_journalist_Fslow","RyanZombieC_Orestesslow","RyanZombieC_Nikosslow",
		"RyanZombie15slow","RyanZombie16slow","RyanZombie17slow","RyanZombie18slow","RyanZombie19slow","RyanZombie20slow","RyanZombie21slow","RyanZombie22slow","RyanZombie23slow","RyanZombie24slow",
		"RyanZombie25slow","RyanZombie26slow","RyanZombie27slow","RyanZombie28slow","RyanZombie29slow","RyanZombie30slow","RyanZombie31slow","RyanZombie32slow",

		// Walker RyanZ CIV
		"RyanZombieC_man_1Walker","RyanZombieC_man_polo_1_FWalker","RyanZombieC_man_polo_2_FWalker","RyanZombieC_man_polo_4_FWalker","RyanZombieC_man_polo_5_FWalker","RyanZombieC_man_polo_6_FWalker",
		"RyanZombieC_man_p_fugitive_FWalker","RyanZombieC_man_w_worker_FWalker","RyanZombieC_scientist_FWalker","RyanZombieC_man_hunter_1_FWalker","RyanZombieC_man_pilot_FWalker","RyanZombieC_journalist_FWalker",
		"RyanZombieC_OrestesWalker","RyanZombieC_NikosWalker","RyanZombie15walker","RyanZombie16walker","RyanZombie17walker","RyanZombie18walker","RyanZombie19walker","RyanZombie20walker","RyanZombie21walker",
		"RyanZombie22walker","RyanZombie23walker","RyanZombie24walker","RyanZombie25walker","RyanZombie26walker","RyanZombie27walker","RyanZombie28walker","RyanZombie29walker","RyanZombie30walker","RyanZombie31walker",
		"RyanZombie32walker",
		
		// Spider RyanZ CIV
		"RyanZombieSpider1","RyanZombieSpider2","RyanZombieSpider3","RyanZombieSpider4","RyanZombieSpider5","RyanZombieSpider6","RyanZombieSpider7","RyanZombieSpider8","RyanZombieSpider9","RyanZombieSpider10",
		"RyanZombieSpider11","RyanZombieSpider12","RyanZombieSpider13","RyanZombieSpider14","RyanZombieSpider15","RyanZombieSpider16","RyanZombieSpider17","RyanZombieSpider18","RyanZombieSpider19","RyanZombieSpider20",
		"RyanZombieSpider21","RyanZombieSpider22","RyanZombieSpider23","RyanZombieSpider24","RyanZombieSpider25","RyanZombieSpider26","RyanZombieSpider27","RyanZombieSpider28","RyanZombieSpider29","RyanZombieSpider30",
		"RyanZombieSpider31","RyanZombieSpider32",
		
		// Crawler RyanZ CIV
		"RyanZombieCrawler1","RyanZombieCrawler2","RyanZombieCrawler3","RyanZombieCrawler4","RyanZombieCrawler5","RyanZombieCrawler6","RyanZombieCrawler7","RyanZombieCrawler8","RyanZombieCrawler9","RyanZombieCrawler10",
		"RyanZombieCrawler11","RyanZombieCrawler12","RyanZombieCrawler13","RyanZombieCrawler14","RyanZombieCrawler15","RyanZombieCrawler16","RyanZombieCrawler17","RyanZombieCrawler18","RyanZombieCrawler19","RyanZombieCrawler20",
		"RyanZombieCrawler21","RyanZombieCrawler22","RyanZombieCrawler23","RyanZombieCrawler24","RyanZombieCrawler25","RyanZombieCrawler26","RyanZombieCrawler27","RyanZombieCrawler28","RyanZombieCrawler29","RyanZombieCrawler30",
		"RyanZombieCrawler31","RyanZombieCrawler32",

		// Epoch RyanZ
/*
		"EPOCH_RyanZombie_1","EPOCH_RyanZombie_2","EPOCH_RyanZombie_3","EPOCH_RyanZombie_4","EPOCH_RyanZombie_5",
		"EPOCH_RyanZombie_1_C","EPOCH_RyanZombie_2_C","EPOCH_RyanZombie_3_C","EPOCH_RyanZombie_4_C","EPOCH_RyanZombie_5_C",
		"EPOCH_RyanZombie_1_Sp","EPOCH_RyanZombie_2_Sp","EPOCH_RyanZombie_3_Sp","EPOCH_RyanZombie_4_Sp","EPOCH_RyanZombie_5_Sp",
		"EPOCH_RyanZombie_1_B","EPOCH_RyanZombie_2_B","EPOCH_RyanZombie_3_B","EPOCH_RyanZombie_4_B","EPOCH_RyanZombie_5_B",
		"EPOCH_RyanZombie_1_W","EPOCH_RyanZombie_2_W","EPOCH_RyanZombie_3_W","EPOCH_RyanZombie_4_W","EPOCH_RyanZombie_5_W",
		"EPOCH_RyanZombie_1_S","EPOCH_RyanZombie_2_S","EPOCH_RyanZombie_3_S","EPOCH_RyanZombie_4_S","EPOCH_RyanZombie_5_S",
		"EPOCH_RyanZombie_1_M","EPOCH_RyanZombie_2_M","EPOCH_RyanZombie_3_M","EPOCH_RyanZombie_4_M","EPOCH_RyanZombie_5_M",
		"EPOCH_RyanZombie_1","EPOCH_RyanZombie_2","EPOCH_RyanZombie_3","EPOCH_RyanZombie_4","EPOCH_RyanZombie_5",
		"EPOCH_RyanZombie_1_C","EPOCH_RyanZombie_2_C","EPOCH_RyanZombie_3_C","EPOCH_RyanZombie_4_C","EPOCH_RyanZombie_5_C",
		"EPOCH_RyanZombie_1_Sp","EPOCH_RyanZombie_2_Sp","EPOCH_RyanZombie_3_Sp","EPOCH_RyanZombie_4_Sp","EPOCH_RyanZombie_5_Sp",
		"EPOCH_RyanZombie_1_W","EPOCH_RyanZombie_2_W","EPOCH_RyanZombie_3_W","EPOCH_RyanZombie_4_W","EPOCH_RyanZombie_5_W",
		"EPOCH_RyanZombie_1_S","EPOCH_RyanZombie_2_S","EPOCH_RyanZombie_3_S","EPOCH_RyanZombie_4_S","EPOCH_RyanZombie_5_S"
*/
	};
};
