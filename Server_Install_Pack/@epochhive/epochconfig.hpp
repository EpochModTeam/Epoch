serverRestart         = "false"; // true sends #shutdown command to server after the time specified in ForceRestartTime
forceRestartTime      = 14400; // 4 hour restarts

StorageSlotsLimit = 1500; // Max storage slots allowed. Warning! Higher the number lower performance.
BuildingSlotsLimit = 1500; // Max building slots allowed. Warning! Higher the number lower performance.

// Time based
StaticDateTime[] = {}; // {0,0,0,8,0} would forces the server to start at 8am each time it is started while allowing the year, month and day to stay real time. Any values left at 0 will result in no change.
timeDifference = 0; // Server uses real time this will allow you to offset just the hour.
timeMultiplier = 4; // Sets a time multiplier for in-game time. The command range is now capped at 0.1 - 120 to avoid performance problems.
lootMultiplier = 0.5; // 1 = max loot bias. This controls how much loot can payout per Epoch loot container.
// Events
WeatherStaticForecast[] = {}; // Default: {75.5,0,{0,0,0},0,{1,1}}; // Clear day; {19,1,{1,1,40},1,{5,5}}; // Cold Foggy Rainy Overcast Windy; Format: {temp <scalar>,rain <scalar>,fog <array>,overcast <scalar>,wind <array>}
events[] = {
    { 3600, "CarnivalSpawner", 0 , 1}, // SECOND <scalar>, EVENT <string>, INIT <scalar> 1 = run script at startup, 0 normal delay, PREPOSTFIX <scalar> 1 = use pre/postfix path (inside epoch settings pbo) 0 = use full file path
    // { 1800, "PaydayEvent", 0, 1},
    // { 1200, "MessageServer", 0, 1},
    { 2700, "AirDrop", 0 , 1},
    { 2400, "EarthQuake", 0 , 1},
    { 900, "ChangeWeather", 1 , 1},
    { 1200, "ContainerSpawner", 0 , 1},
    { 300, "PlantSpawner", 0 , 1} //No comma on last Entry
};

// Antagonists
antagonistChanceTrash = 0.09; //9% chance when player loot a trash object
antagonistChancePDeath = 0.33; //33% chance when player was killed from a other player (selfkill doesn't count)
antagonistChanceLoot = 0.09; //9% chance when player click "SEARCH" on a loot object

// Player Related
cloneCost = 100; 					// debt incurred on player death
MaxBankDebitforTrade = -50000;		// If Player has less money on Bank, Crypto from Trade goes directly to Bank instead to Player

// vehicles - Max vehicle slots is calculated from per vehicle limits below. Warning! Higher the number lower the performance.
simulationHandlerOld = "false"; // When enabled this feature disables simulation on vehicles that are not nea players. Can help improve client fps at the cost of server fps.
vehicleLockTime = 1800; // Controls how many seconds it takes to allow another person/group to unlock vehicle.
removevehweapons[] = {			// remove these Weapons from spawned Vehicles
	"missiles_DAR","gatling_30mm","gatling_20mm","missiles_DAGR","cannon_30mm_Plane_CAS_02_F","Missile_AA_03_Plane_CAS_02_F","Missile_AGM_01_Plane_CAS_02_F","Rocket_03_HE_Plane_CAS_02_F",
	"Rocket_03_AP_Plane_CAS_02_F","Bomb_03_Plane_CAS_02_F","Bomb_04_Plane_CAS_01_F","Rocket_04_AP_Plane_CAS_01_F","Rocket_04_HE_Plane_CAS_01_F","Missile_AGM_02_Plane_CAS_01_F","Missile_AA_04_Plane_CAS_01_F",
	"Gatling_30mm_Plane_CAS_01_F","GBU12BombLauncher_Plane_Fighter_03_F","missiles_ASRAAM","missiles_SCALPEL","Twin_Cannon_20mm","missiles_Zephyr","rockets_skyfire","gatling_30mm_vtol_02"
};
removevehmagazinesturret[] = {	// Remove these Magazines from the given Turret from spawned Vehicles
	{"24Rnd_missiles",{-1}},
	{"200Rnd_40mm_G_belt",{0}}
};

// BaseBuilding
UseIndestructible = "false";			// Enable / Disable Indestructible BaseObjects
IndestructibleBaseObjects[] =	{	// Can be Names or Classes
									"Constructions_static_F",
									"Buildable_Storage",
									"PlotPole_EPOCH",
									"LockBox_EPOCH",
									"Safe_EPOCH"
								};
ExceptedBaseObjects[] = 		{	// Not Indestructible, also if in a Class of IndestructibleBaseObjects
									"CinderWallGarage_EPOCH",
									"WoodLargeWallDoorL_EPOCH",
									"WoodLargeWallDoor_EPOCH",
									"WoodWall4_EPOCH"
								};

// Traders
taxRate = 0.1; // controls the price increase for purchases
starterTraderItems[] = { { "ItemSodaBurst", "meatballs_epoch", "MortarBucket", "CinderBlocks", "VehicleRepair", "CircuitParts", "ItemCorrugated", "PartPlankPack", "ItemRock", "ItemRope", "ItemStick" }, { 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5 } }; // Starter Items for fresh spawned trader first array is classnames second is quantity.
NPCSlotsLimit = 30; // Max number of traders static or dynamic. Warning! Higher the number lower performance.
forceStaticTraders = "true"; // disables traders moving from work to home

forcedVehicleSpawnTable = ""; // leave blank for default. Options: "allowedVehiclesList","allowedVehiclesList_CUP","allowedVehiclesList_MAD","allowedVehiclesList_MADCUP"
forcedLootSpawnTable = ""; // leave blank for default. Options: "CfgLootTable","CfgLootTable_CUP","CfgLootTable_MAD","CfgLootTable_MADCUP"

// Markers
showEarthQuakes = "true"; // show mineral viens caused by earthquakes
showShippingContainers = "true"; // Show location of events based loots (plants, shipping container, Carnival)
SHOW_TRADERS = "true"; // Show locations of traders
SHOW_JAMMERS = "false"; // Shows location of base jammers
SHOW_BOATLOOT = "true"; // Shows the location of shipwreck loot
DEBUG_VEH = "false"; // DEBUG ONLY used to debug spawing of vehicles

// Hive Related
expiresBuilding = "604800";  // expiration date in seconds for buildings
expiresPlayer = "2592000";  // expiration date in seconds for players
expiresBank = "7776000";  // expiration date in seconds for players bank
expiresVehicle = "604800";  // expiration date in seconds for vehicles
expiresAIdata = "604800";  // expiration date in seconds for NPC Trader inventory

// Admin Features
hiveAdminCmdExec = "false"; // true = enables extra (To Be Released) feature to allow execution of code via hive.
hiveAdminSavePlayerList = "true"; // true = enables saving of playerUID array to hive value PLAYERS:#InstanceID.
hiveAdminCmdTime = 5; // how many seconds between each command queue call.

// DEBUG
useOldLoadVehicles = "false";
enableUnitTestOnStart = 1; // enable extra debug for database calls. 1 = enabled.
