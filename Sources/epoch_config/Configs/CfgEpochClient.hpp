/*
    Author: Aaron Clark - EpochMod.com
    Contributors: Andrew Gregory

    Description:
    Main Client side configs for the Epoch gamemode

    Licence:
    Arma Public License Share Alike (APL-SA) - https://www.bistudio.com/community/licenses/arma-public-license-share-alike

    Github:
    https://github.com/EpochModTeam/Epoch/tree/release/Sources/epoch_config/Configs/CfgEpochClient.hpp
*/
/*[[[cog from arma_config_tools import *; json_to_arma()]]]*/
class CfgEpochClient
{
    epochVersion = "1.0.0";
    ArmAVersion = 168;
    sapperRngChance = 100; // increase number to reduce chances and reduce to increase. Default 100
    droneRngChance = 100; // increase number to reduce chances and reduce to increase. Default 100
    zombieRngChance = 50; // increase number to reduce chances and reduce to increase. Default 50

    baseHungerLoss = 2; // increase number to speed up rate of Hunger loss
    baseThirstLoss = 2; // increase number to speed up rate of Thirst loss

    buildingNearbyMilitary = 0; //1 to allow building nearby
    buildingNearbyMilitaryRange = 300; //Define radius of blocked area
    buildingNearbyMilitaryClasses[] = {"Cargo_Tower_base_F","Cargo_HQ_base_F","Cargo_Patrol_base_F","Cargo_House_base_F"};
    restrictedLocations[] = {"NameCityCapital"};
    restrictedLocationsRange = 300;
    buildingRequireJammer = 1;		//1 = require jammer to build
    buildingJammerRange = 75; 		// jammer range in meters
    jammerPerGroup = 1;				// allowed number of jammers per group.
    jammerGLOnly = 1;               // allow only group leader to place Jammer
    minJammerDistance = 650;		// min distance to next Jammer
    maxBuildingHeight = 33;			// Max Height, building is allowed.
    buildingCountLimit = 200;		//overall building limit in range of jammer (overridden if "useGroupCountLimits=1")
    storageCountLimit = 100;		//overall storage limit in range of jammer (triggers only if "splitCountLimits=1" & "useGroupCountLimits=0")
    splitCountLimits = 0;			//1 = distinguish buildingCountLimit from storageCountLimit (ex.: buildingCountLimit=100, storageCountLimit=100 >> you can build 100 baseparts AND additional 100 storage objects like safes, lockboxes...)
    useGroupCountLimits = 1;		//1 = enable leader and member counts (doesn´t affect "splitCountLimits")
    buildingCountLeader = 125;		//ignore if "useGroupCountLimits=0"
    buildingCountPerMember = 5;		//ignore if "useGroupCountLimits=0"
    storageCountLeader = 10;		//ignore if "splitCountLimits=0" & "useGroupCountLimits=0"
    storageCountPerMember = 5;		//ignore if "splitCountLimits=0" & "useGroupCountLimits=0"
    maxdoors = 8;					// Max allowed doors per Group
    maxgates = 5;					// Max allowed Gates per Group

    disableRemoteSensors = "true";  // disableRemoteSensors true/false

    epochMessageBackgroundCol[] = {0,0,0,0.2};  //Epoch_message background color (format: {R,G,B,A})
    epochMessageTextCol[] = {1,1,1,0.95};       //Epoch_message text color (format: {R,G,B,A})
                                                //to use different colored messages in scripts, just call it this way: ["the message", 6, [[0,0,0,0.2],[1,1,1,0.95]]] call Epoch_message;

    EPOCH_news[] = {"Word is that Sappers have a new boss.","Dogs will often lure them monsters away.","My dog was blown up. I miss him.."};
    deathMorphClass[] = {"Epoch_Sapper_F","Epoch_SapperG_F","Epoch_SapperB_F","I_UAV_01_F","Epoch_Cloak_F"}; //Random selection of these classes when player morphs after death. Currently available: Epoch_Cloak_F, Epoch_SapperB_F, Epoch_Sapper_F, I_UAV_01_F
    niteLight[] = {1,1.88,22}; //Set ambient lighting at night: {Brightness of light,Height of light}. Default (Low Ambient): {1.88,22} | Twilight: {7.2,88} | Distant: {12.8,142}
    ryanZombiesEnabled = "true";
    antagonistSpawnIndex[] = {{"Epoch_Cloak_F",1},{"GreatWhite_F",2},{"Epoch_Sapper_F",2},{"Epoch_SapperG_F",1},{"Epoch_SapperB_F",1},{"I_UAV_01_F",2},{"PHANTOM",1},{"B_Heli_Transport_01_F",1},{"EPOCH_RyanZombie_1",12},{"I_Soldier_EPOCH",1}}; // {"type", limit}
    customVarsDefaults[] = {{"Temp",98.6,{106.7,95,102,105,96,95}},{"Hunger",1500,{5000,0,5001,5001,1250,0}},{"Thirst",750,{2500,0,2501,2501,625,0}},{"AliveTime",0,{-2,0}},{"Energy",0,{2500,0}},{"Wet",0,{100,0,35,55,-1,-1}},{"Soiled",0,{100,0,35,55,-1,-1}},{"Immunity",0,{100,0}},{"Toxicity",0,{100,0,35,55,-1,-1}},{"Stamina",100,{"EPOCH_playerStaminaMax",0}},{"Crypto",0,{250000,0}},{"HitPoints",{0,0,0,0},{1,0,0.5,1,-1,-1}},{"BloodP",100,{190,0,120,140,70,50}},{"SpawnArray",{},{}},{"Karma",0,{50000,-50000}},{"Alcohol",0,{100,0,35,55,-1,-1}},{"Radiation",0,{100,0,35,55,-1,-1}},{"Nuisance",0,{100,0}},{"MissionArray",{},{}}}; // EPOCH_player + varName, default value, {max,min,high-warn,high-critical,low-warn,low-critical}
	// add any stats and their starting number here for better community integration and neat stats tracking too!
	defineCommunityStats[]  = {{"Murders",0},{"Deaths",0},{"Suicides",0},{"Revives",0},{"TraderMissions",0},{"AIKills",0},{"AntagonistKills",0},{"ZombieKills",0}};
    hudConfigs[] = {{{"BloodP","","",{"getPlayerDamage",">=",0.7}},"topRight","x\addons\a3_epoch_code\Data\UI\bleeding_ca.paa",{"forceUpdate"}},{{"Oxygen","getPlayerOxygenRemaining","",{},{1,0,2,2,1,0.55}},"topRight","x\addons\a3_epoch_code\Data\UI\oxygen_ca.paa"},{"Hunger","topRight","x\addons\a3_epoch_code\Data\UI\hunger_ca.paa",{"forceBloodRise"}},{"Thirst","topRight","x\addons\a3_epoch_code\Data\UI\thirst_ca.paa",{"forceBloodRise"}},{"Temp","topRight",{"x\addons\a3_epoch_code\Data\UI\hot_ca.paa","x\addons\a3_epoch_code\Data\UI\cold_ca.paa"},{"forceFatigue"}},{"Toxicity","topRight","x\addons\a3_epoch_code\Data\UI\hazzard_ca.paa"},{"Alcohol","topRight","x\addons\a3_epoch_code\Data\UI\drunk_ca.paa"},{"Soiled","topRight","x\addons\a3_epoch_code\Data\UI\soiled_ca.paa"},{"Radiation","topRight","x\addons\a3_epoch_code\Data\UI\rads_ca.paa"},{{"HitPoints","getPlayerHitPointDamage","HitLegs"},"topRight","x\addons\a3_epoch_code\Data\UI\broken_ca.paa"}};
    group_upgrade_lvl[] = {4,"1000",6,"1500",8,"2000",10,"2500",12,"3000",14,"3500",16,"4000",32,"8000",64,"16000"}; // controls max group limit and cost
    // Event handler code
    displayAddEventHandler[] = {"keyDown","keyUp"};
    keyDown = "(_this call EPOCH_KeyDown)";
    keyUp = "(_this call EPOCH_KeyUp)";
    addEventHandler[] = {"Respawn","Put","Take","InventoryClosed","InventoryOpened","FiredMan","Killed","HandleRating","GetInMan","GetOutMan"};
    Respawn = "(_this select 0) call EPOCH_clientRespawn";
    Put = "(_this select 1) call EPOCH_interact;_this call EPOCH_PutHandler;_this call Epoch_custom_EH_Put";
    Take = "(_this select 1) call EPOCH_interact;_this call EPOCH_UnisexCheck;_this call Epoch_custom_EH_Take";
    FiredMan = "_this call EPOCH_fnc_playerFired;_this call Epoch_custom_EH_FiredMan";
    InventoryClosed = "_this call EPOCH_InventoryClosed;_this call EPOCH_custom_EH_InventoryClosed";
    InventoryOpened = "_this call EPOCH_InventoryOpened||_this call EPOCH_custom_EH_InventoryOpened"; // the || here allows either function to block opening of inventory by returning true.
    Killed = "_this call EPOCH_fnc_playerDeath;_this call Epoch_custom_EH_Killed";
    HandleRating = "EPOCH_playerKarma = EPOCH_playerKarma + (_this select 1);0";
    HandleDamage = "";
    HandleHeal = "";
    Dammaged = "";
    Hit = "";
    HitPart = "";
    GetInMan = "_this call EPOCH_getInMan;_this call Epoch_custom_EH_GetInMan";
    GetOutMan = "_this call EPOCH_getOutMan;_this call Epoch_custom_EH_GetOutMan";
    // suppress these units from spawning near Jammer or Traders
    nonJammerAI[] = {"B_Heli_Transport_01_F","PHANTOM","EPOCH_Sapper_F","Epoch_SapperG_F","Epoch_SapperB_F","I_UAV_01_F","EPOCH_RyanZombie_1"};
    nonTraderAI[] = {"B_Heli_Transport_01_F","PHANTOM","EPOCH_Sapper_F","Epoch_SapperG_F","Epoch_SapperB_F","I_UAV_01_F","Epoch_Cloak_F","GreatWhite_F","EPOCH_RyanZombie_1"};
    nonTraderAIRange = 50;
    fishLoots[] = {"ItemTuna","ItemSeaBass","ItemSeaBass","ItemSeaBass","ItemTrout","ItemTrout","ItemTrout","ItemTrout","ItemTrout","ItemTrout"}; // Fishing loots
    animalAiTables[] = {"Sheep_random_EPOCH","Sheep_random_EPOCH","Goat_random_EPOCH","Goat_random_EPOCH","Goat_random_EPOCH",{"Cock_random_EPOCH","Hen_random_EPOCH"},{"Cock_random_EPOCH","Hen_random_EPOCH"},"Rabbit_EPOCH","Rabbit_EPOCH","Rabbit_EPOCH","Snake_random_EPOCH","Snake2_random_EPOCH",{"Fin_random_EPOCH","Alsatian_Random_EPOCH"}}; // Animal spawn table
    playerDeathScreen = "TapOut";
    playerKilledScreen = "TapOut2";
    playerDisableRevenge = 0;
    playerRevengeMinAliveTime = 900;
    bankTransferTime[] = {0.0006,1.2,0.06};
	
	// Favorite Bar
	Fav_enableFavoriteBar = "true";			// If disabled, players will not be able to use favorite bar
	Fav_DropIfOverflow = "false";			// If enabled and inventory full, equipped weapon will be dropped on ground in favor for the new selected weapon, otherwise action will fail with message and weapon will not be equipped
	Fav_FastWeaponSwitching = "false";		// If enabled, same slot weapons from favorites bar are equipped instantly, otherwise reload action is played (recommended for immersion)
	Fav_BannedItems[] = {"FAK"};				// Items that users are not allowed to pin
	
	// Advanced Vehicle Repair
	UseAdvancedVehicleRepair = "true";									// Switch On / Off Advanced Vehicle Repair (Does not effect SuppressedCraftingItems !)
	DisallowSellOnDamage = "false";										// Prevent from selling Vehicles with one or more fully damaged wheel or engine
	SuppressedCraftingItems[] = {"VehicleRepairLg"};					// These Items can not be crafted (but can be used in recipe) - for usage of "Advanced Vehicle Repair"
	VehicleRepairs[] = {												// {Hitpoint, dmg to repair, dmg to replace, mat to repair, mat to replace}
		{"HitHull",0.33,0.66,"ItemScraps","ItemCorrugated"},
		{"HitBody",0.33,1,"ItemScraps","ItemCorrugated"},
		{"HitLFWheel",0.33,1,"VehicleRepair","SpareTire"},
		{"HitLF2Wheel",0.33,1,"VehicleRepair","SpareTire"},
		{"HitLMWheel",0.33,1,"VehicleRepair","SpareTire"},
		{"HitLBWheel",0.33,1,"VehicleRepair","SpareTire"},
		{"HitRFWheel",0.33,1,"VehicleRepair","SpareTire"},
		{"HitRF2Wheel",0.33,1,"VehicleRepair","SpareTire"},
		{"HitRMWheel",0.33,1,"VehicleRepair","SpareTire"},
		{"HitRBWheel",0.33,1,"VehicleRepair","SpareTire"},
		{"HitEngine",0.33,0.91,"EngineParts","EngineBlock"},
		{"glass",0.33,1,"ItemGlass","ItemGlass"},
		{"HitFuel",0.1,0.66,"ItemDuctTape","FuelTank"},
		{"HitHRotor",0.33,1,"ItemCorrugated","ItemRotor"},
		{"HitVRotor",0.33,1,"ItemCorrugated","ItemRotor"},
		{"HitWinch",0.33,0.91,"ItemCables","ItemCables"},
		{"HitAvionics",0.33,0.91,"CircuitParts","CircuitParts"}
	};
	
    // include configs
    #include "CfgEpochClient\Altis.hpp"
    #include "CfgEpochClient\australia.hpp"
    #include "CfgEpochClient\Bornholm.hpp"
    #include "CfgEpochClient\Chernarus_Summer.hpp"
    #include "CfgEpochClient\Chernarus.hpp"
    #include "CfgEpochClient\Esseker.hpp"
    #include "CfgEpochClient\ProvingGrounds_PMC.hpp"
    #include "CfgEpochClient\Sara_dbe1.hpp"
    #include "CfgEpochClient\Sara.hpp"
    #include "CfgEpochClient\SaraLite.hpp"
    #include "CfgEpochClient\Stratis.hpp"
    #include "CfgEpochClient\takistan.hpp"
    #include "CfgEpochClient\utes.hpp"
    #include "CfgEpochClient\vr.hpp"
    #include "CfgEpochClient\Zargabad.hpp"
    #include "CfgEpochClient\Tanoa.hpp"
    #include "CfgEpochClient\Malden.hpp"
    #include "CfgEpochClient\WorldInteractions.hpp"
};
class CfgEpochSoldier
{
    unitTypes[] = {"I_Soldier_EPOCH", "I_Soldier2_EPOCH", "I_Soldier3_EPOCH"};//Selects from randomly
    minAISkill = 0.2; //Minumum AI Skill. Skills are chosen randomly between this minimum overall AI skill value and the following max AI skill values, for each of the next skills:
    maxAimingAccuracy = 0.7;
    maxAimingShake = 0.9;
    maxAimingSpeed = 0.6;
    maxEndurance = 0.4;
    maxSpotDistance = 0.4;
    maxSpotTime = 0.3;
    maxCourage = 0.3;
    maxReloadSpeed = 0.5;
    maxCommanding = 0.4;
    maxGeneral = 0.4;
};
class CfgEpochSapper
{
    detonateDistMax = 8; //Random distance between 3m and this number at which sapper detonates. Min value = 4
    groanTrig = 16; //Percentage chance of a groan. Min value = 4
    sRange = 300; //Distance from target over which sapper will dispose. Range within which sapper code will be aware of targets. Distance up to which sapper will attempt to find a spot to hide in. Min Value = 150.
    smellDist = 24; //Distance up to which sapper can smell. Used to decide if sapper can see target when deciding to charge and influences target selection. Is influenced by wind direction. Min Value = 8.
    reflexSpeed = 0.25; //Sapper brain will pause for this time when checking for new stimulus during each thought process. Lower number equals a more reactive sapper. (Guide Min 0.25 - Max 2.5).
    nestChance = 2; //Every time a sapper spawns apply this percentage chance that sapper will create a nest.
    hideLevel = 72; //(Emotion) Sapper fear increases by several factors, higher number of armed player(s) in area / being shot at. Set fear level (out of 100) at which he will go into a 'hide / evade mode'.. temporarily.
    chargeLevel = 52; //(Emotion) Sapper anger increases by smelling / sensing players, being shot at / hit, too many players on his turf. Set level (Out of 100) at which he is triggered to charge on the current target.
};
class CfgEpochUAV
{
    UAVMinDist = 48; //Minimum distance to choose next position when roaming. Min Value = 8.
    UAVMaxDist = 180; //Maximum distance to choose next position when roaming. Min Value = 42 / Max Value = 400.
    UAVHeight = 100; //Set height when roaming, slight randomness is applied to this value. UAV will choose own height when locked onto target. Min Value = 42 / Max Value = 280. UAV can still spot targets from height !
};
class CfgEpochUAVSupport
{
	unitTypes[] = {"I_Soldier_EPOCH"}; //Selects from randomly (e.g. {"I_Soldier_EPOCH","Epoch_Sapper_F","Epoch_SapperB_F","Epoch_SapperG_F"};)
	minUnitNum = 2; //Maximum number of units spawned when UAV spots target.
	maxUnitNum = 4; //Maximum number of units spawned when UAV spots target.
};
class CfgEpochCloak
{
    cRange = 300; //Distance, from target, at which Cloak will dispose. Cloak is also aware of players within this range. (Min: 60 / Max: 600)
    cAggression = 75; //Percentage chance of attack, currently a psychological attack (Cultist spooky voice). (Min: 1 / Max: 100)
    attackFrequency = 120; //One attack only per this period. (Min: 120)
    attackDistance = 38; // Distance, from target, up to which Cloak will attack. Lower for less vocals. (Min: 16)
    targetChangeFrequency = 42; //Cloak will only attempt to change target once per this period. Make Higher to stick to first target player. (Min: 42)
    teleportChance = 66; //Chance for cloak to teleport. (Min: 1)
    hoverFrequency = 1280; //Cloak has new hover attack. When player is above cloak, and at a distance, cloak will float to player and teleport attack. Only perform one of these moves per this period. (Min: 240)
};
class CfgEpochRyanZombie
{
    zeds[] = {"EPOCH_RyanZombie_1","EPOCH_RyanZombie_2","EPOCH_RyanZombie_3","EPOCH_RyanZombie_4","EPOCH_RyanZombie_5"};
    attackDist = 1.6; //Attack Distance.
    range = 45; //Range at which to dispose old zombies and spawn new ones within.
    disposeRange = 800; // distance before zombie is disposed
    smell[] = {38,0.42}; //Distance in metres up to which the zombie can smell a target. | Skill (0 - 1). 0 - Disable
    sight[] = {28,0.72}; //Zombie sight distance | Skill (0 - 1).
    hearing[] = {108,0.68}; //Zombie hearing distance / Skill. Max FiredNear EH Limit ?
    memory[] = {480,0.8}; //Memory time. / Weighting. WIP - Not Used
    reflexSpeed = 0.25; //Zombie brain will pause for this time when checking for new stimulus during each thought process. Lower number equals a more reactive zombie. (Guide Min 0.25 - Max 2.5).
    moans[] = {"ryanzombiesmoan1","ryanzombiesmoan2","ryanzombiesmoan3","ryanzombiesmoan4"};
    screams[] = {"ryanzombiesscream1","ryanzombiesscream2","ryanzombiesscream3","ryanzombiesscream4","ryanzombiesscream5","ryanzombiesscream6","ryanzombiesscream7","ryanzombiesscream8","ryanzombiesscream9"};
};
/*[[[end]]]*/
