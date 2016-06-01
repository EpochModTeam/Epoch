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
WeatherStaticForecast[] = {}; // Default: {75.5,0,{0,0,0},0,{1,1}}; // Clear day; {19,1,{1,1,40},1,{5,5}}; // Cold Foggy Rainy Overcast Windy; Format: {temp <scalar>,rain <scalar>,fog <array>,overcast <scalar>,wind <array>}
events[] = {
    { 3600, "CarnivalSpawner", 0 , 1}, // SECOND <scalar>, EVENT <string>, INIT <scalar> 1 = run script at startup, 0 normal delay, PREPOSTFIX <scalar> 1 = use pre/postfix path (inside epoch settings pbo) 0 = use full file path
    { 2400, "EarthQuake", 0 , 1},
    { 1800, "ChangeWeather", 1 , 1},
    { 1200, "ContainerSpawner", 0 , 1},
    { 300, "PlantSpawner", 0 , 1} //No comma on last Entry
};

// Antagonists
antagonistChanceTrash = 0.09; //9% chance when player loot a trash object
antagonistChancePDeath = 0.33; //33% chance when player was killed from a other player (selfkill doesn't count)
antagonistChanceLoot = 0.09; //9% chance when player click "SEARCH" on a loot object

// Player Related
cloneCost = 100; // debt incurred on player death

// vehicles - Max vehicle slots is calculated from per vehicle limits below. Warning! Higher the number lower the performance.
simulationHandler = true; // When enabled this feature disables simulation on vehicles that are not nea players. Can help improve client fps at the cost of server fps.
vehicleLockTime = 1800; // Controls how many seconds it takes to allow another person/group to unlock vehicle.

// Traders
taxRate = 0.1; // controls the price increase for purchases
starterTraderItems[] = { { "ItemSodaBurst", "meatballs_epoch", "MortarBucket", "CinderBlocks", "VehicleRepair", "CircuitParts", "ItemCorrugated", "PartPlankPack", "ItemRock", "ItemRope", "ItemStick" }, { 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5 } }; // Starter Items for fresh spawned trader first array is classnames second is quantity.
NPCSlotsLimit = 20; // Max number of traders static or dynamic. Warning! Higher the number lower performance.
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
