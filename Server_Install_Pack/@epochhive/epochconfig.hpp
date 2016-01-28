serverRestart         = false; // true sends #shutdown command to server after the time specified in ForceRestartTime
forceRestartTime      = 14400; // 4 hour restarts

StorageSlotsLimit = 1500; // Max storage slots allowed. Warning! Higher the number lower performance.
BuildingSlotsLimit = 1500; // Max building slots allowed. Warning! Higher the number lower performance.

// Time based
StaticDateTime[] = {}; // {0,0,0,8,0} would forces the server to start at 8am each time it is started while allowing the year, month and day to stay real time. Any values left at 0 will result in no change.
timeDifference = 0; // Server uses real time this will allow you to offset just the hour.
timeMultiplier = 4; // Sets a time multiplier for in-game time. The command range is now capped at 0.1 - 120 to avoid performance problems.
lootMultiplier = 0.5; // 1 = max loot bias. This controls how much loot can payout per Epoch loot container.
// Events
WeatherChangeTime = 1200; // This controls how fast the weather changes as well as how fast shipping containers and earthquakes happen.
WeatherStaticForecast[] = {}; // Default: {75.5,0,{0,0,0},0,{1,1}}; // Clear day; {19,1,{1,1,40},1,{5,5}}; // Cold Foggy Rainy Overcast Windy; Format: {temp <scalar>,rain <scalar>,fog <array>,overcast <scalar>,wind <array>}
events[] = {
    { 3600, "CarnivalSpawner" }, // SECOND <scalar>, EVENT <string>
    { 2400, "EarthQuake" },
    { 1800, "ChangeWeather" },
    { 1200, "ContainerSpawner" },
    { 300, "PlantSpawner" } //No comma on last Entry
};

// Antagonists
antagonistChanceTrash = 0.09; //9% chance when player loot a trash object
antagonistChancePDeath = 0.33; //33% chance when player was killed from a other player (selfkill doesn't count)
antagonistChanceLoot = 0.09; //9% chance when player click "SEARCH" on a loot object

// Player Related
cloneCost = 100; // debt incurred on player death

// vehicles - Max vehicle slots is calculated from per vehicle limits below. Warning! Higher the number lower the performance.
simulationHandler = false; // When enabled this feature disables simulation on vehicles that are not near players. Can help improve client fps at the cost of server fps. (This is disabled by default now that Arma has fixed the original issue)
vehicleLockTime = 1800; // Controls how many seconds it takes to allow another person/group to unlock vehicle.
allowedVehiclesList[] = {
    {"C_Offroad_01_EPOCH",8},
    {"C_Quadbike_01_EPOCH",8},
    {"C_Hatchback_01_EPOCH",10},
    {"C_Hatchback_02_EPOCH",10},
    {"C_SUV_01_EPOCH",10},
    {"C_Rubberboat_EPOCH",5},
    {"C_Rubberboat_02_EPOCH",5},
    {"C_Rubberboat_03_EPOCH",5},
    {"C_Rubberboat_04_EPOCH",5},
    {"C_Van_01_box_EPOCH",8},
    {"C_Van_01_transport_EPOCH",9},
    {"C_Boat_Civil_01_EPOCH",5},
    {"C_Boat_Civil_01_police_EPOCH",5},
    {"C_Boat_Civil_01_rescue_EPOCH",5},
    {"B_Heli_Light_01_EPOCH",2},
    {"B_SDV_01_EPOCH",2},
    {"B_MRAP_01_EPOCH",3},
	{"I_MRAP_03_EPOCH", 3},	
    {"B_Truck_01_transport_EPOCH",1},
    {"B_Truck_01_covered_EPOCH",2},
    {"B_Truck_01_mover_EPOCH",1},
    {"B_Truck_01_box_EPOCH",1},
    {"O_Truck_02_covered_EPOCH",2},
    {"O_Truck_02_transport_EPOCH",1},
    {"O_Truck_03_covered_EPOCH",1},
    {"O_Truck_02_box_EPOCH",1},
    {"I_Heli_light_03_unarmed_EPOCH",1},
    {"O_Heli_Light_02_unarmed_EPOCH",1},
    {"I_Heli_Transport_02_EPOCH",1},
    {"O_Heli_Transport_04_EPOCH",1},
    {"O_Heli_Transport_04_bench_EPOCH",1},
    {"O_Heli_Transport_04_box_EPOCH",1},
    {"O_Heli_Transport_04_covered_EPOCH",1},
    {"B_Heli_Transport_03_unarmed_EPOCH",1},
    {"jetski_epoch",7},
    {"K01",2},
    {"K02",2},
    {"K03",2},
    {"K04",2},
    {"ebike_epoch",7},
    {"mosquito_epoch",5},
	{"C_Heli_Light_01_civil_EPOCH",5}
};

// Traders
taxRate = 0.1; // controls the price increase for purchases
starterTraderItems[] = { { "ItemSodaBurst", "meatballs_epoch", "MortarBucket", "CinderBlocks", "VehicleRepair", "CircuitParts", "ItemCorrugated", "PartPlankPack", "ItemRock", "ItemRope", "ItemStick" }, { 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5 } }; // Starter Items for fresh spawned trader first array is classnames second is quantity.
NPCSlotsLimit = 50; // Max number of traders static or dynamic. Warning! Higher the number lower performance.
forceStaticTraders = true; // disables traders moving from work to home

// Markers
showEarthQuakes = true; // show mineral viens caused by earthquakes
showShippingContainers = true; // Show location of events based loots (plants, shipping container, Carnival)
SHOW_TRADERS = true; // Show locations of traders
SHOW_JAMMERS = false; // Shows location of base jammers
SHOW_BOATLOOT = true; // Shows the location of shipwreck loot
DEBUG_VEH = false; // DEBUG ONLY used to debug spawing of vehicles

// Hive Related
expiresBuilding = "604800";  // expiration date in seconds for buildings
expiresPlayer = "2592000";  // expiration date in seconds for players
expiresBank = "7776000";  // expiration date in seconds for players bank
expiresVehicle = "604800";  // expiration date in seconds for vehicles
expiresAIdata = "604800";  // expiration date in seconds for NPC Trader inventory
hiveAsync = true; // true = asynchronous hive calls (non blocking), false = synchronous hive calls (blocking)

// Admin Features
hiveAdminCmdExec = false; // true = enables extra (To Be Released) feature to allow execution of code via hive.
hiveAdminSavePlayerList = true; // true = enables saving of playerUID array to hive value PLAYERS:#InstanceID.
hiveAdminCmdTime = 5; // how many seconds between each command queue call.
