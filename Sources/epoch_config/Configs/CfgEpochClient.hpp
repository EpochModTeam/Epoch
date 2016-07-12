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
class CfgEpochClient
{
	epochVersion = "0.3.9.0";
	sapperRngChance = 100; // increase number to reduce chances and reduce to increase. Default 100 = 1% - 55% if soiled (+ 2% if in city) chance to spawn sapper
	droneRngChance = 100; // increase number to reduce chances and reduce to increase. Default 100 = // 2% chance (+ 4% chance if in city) (1% - 2% Half if using silencer) to spawn drone if shot fired
	buildingNearbyMilitary = 0; //1 to allow building nearby
	buildingNearbyMilitaryRange = 300; //Define radius of blocked area
	buildingRequireJammer = 0; // 1 = to allow building without a jammer
	buildingCountLimit = 200; // how many objects can be built within range of a jammer
	buildingJammerRange = 75; // jammer range in meters
	JammerPerGroup = 1;		// Max Jammer count per Group
	minJammerDistance = 650;	// min distance to next Jammer
	maxBuildingHeigh = 33;		// Max heigh, building is allowed
	buildingCountLeader = 125;	// Building count limit if Player has no group
	buildingCountPerMember = 5;	// Additional building counts per group member
	storagecountLeader	= 10;	// Storage count limit if Player has no group
	storagecountPerMember	= 5;	// Additional Storage counts per group member
	maxdoors = 8;			// Max allowed doors per Group
	maxgates = 5;			// Max allowed Gates per Group
	disableRemoteSensors = true; // disableRemoteSensors true
	EPOCH_news[] = {"Word is that Sappers have a new boss.","Dogs will often lure them monsters away.","My dog was blown up. I miss him.."};
	deathMorphClass[] = {"Epoch_Sapper_F","Epoch_SapperB_F","I_UAV_01_F","Epoch_Cloak_F"};//Random selection of these classes when player morphs after death. Currently available: Epoch_Cloak_F, Epoch_SapperB_F, Epoch_Sapper_F, I_UAV_01_F
	niteLight[] = {1.88,22};//Set ambient lighting at night: {Brightness of light,Height of light}. Default (Low Ambient): {1.88,22} | Twilight: {7.2,88} | Distant: {12.8,142}
	ryanZombiesEnabled = true; // enabled by default, false to disable
	antagonistSpawnIndex[] = {
		{"Epoch_Cloak_F", 1}, // {"type", limit}
		{"GreatWhite_F", 2},
		{"Epoch_Sapper_F",2},
		{"Epoch_SapperB_F",1},
		{"I_UAV_01_F",2},
		{"PHANTOM",1},
		{"B_Heli_Transport_01_F",1},
		{"EPOCH_RyanZombie_1",12}
	};
	customVarsDefaults[] = {
		// EPOCH_player + varName, default value, {max,min}
		{"Temp",98.6,{106.7,95}},
		{"Hunger",5000,{5000,0}},
		{"Thirst",2500,{2500,0}},
		{"AliveTime",0,{-2,0}},
		{"Energy",0,{2500,0}},
		{"Wet",0,{100,0}},
		{"Soiled",0,{100,0}},
		{"Immunity",0,{100,0}},
		{"Toxicity",0,{100,0}},
		{"Stamina",100,{"EPOCH_playerStaminaMax",0}},
		{"Crypto",0,{250000,0}},
		{"HitPoints",{0,0,0,0},{1,1,1,1}},
		{"BloodP",100,{190,0}},
		{"SpawnArray",{},{}},
		{"Karma",0,{50000,-50000}},
		{"Alcohol",0,{100,0}},
		{"Radiation",0,{100,0}},
		{"Nuisance",0,{100,0}},
		{"MissionArray",{},{}}
	};
	// controls max group limit and cost
	group_upgrade_lvl[] = {4,"100",6,"300",8,"500",10,"1000",12,"1500",13,"1750",14,"2000",15,"3000",16,"5000"};

	// Event handler code
	displayAddEventHandler[] = {"keyDown","keyUp"};
	keyDown = "(_this call EPOCH_KeyDown)";
	keyUp   = "(_this call EPOCH_KeyUp)";
	addEventHandler[] = {"Respawn","Put","Take","InventoryClosed","InventoryOpened","Fired","Killed","HandleRating","GetInMan","GetOutMan"};
	Respawn = "(_this select 0) call EPOCH_clientRespawn";
	Put = "(_this select 1) call EPOCH_interact;_this call EPOCH_PutHandler";
	Take = "(_this select 1) call EPOCH_interact;_this call EPOCH_UnisexCheck";
	Fired           = "_this call EPOCH_fnc_playerFired;";
	InventoryClosed = "if !(EPOCH_arr_interactedObjs isEqualTo[]) then {[EPOCH_arr_interactedObjs] remoteExec['EPOCH_server_save_vehicles', 2]; EPOCH_arr_interactedObjs = [];};";
	InventoryOpened = "_this spawn EPOCH_initUI;_container = _this select 1;_lockedNear = false;if (_container isKindOf 'GroundWeaponHolder' || _container isKindOf 'WeaponHolderSimulated') then {{if (locked _x in [2, 3] ||_x getVariable['EPOCH_Locked', false]) exitWith {_lockedNear = true}} forEach (player nearSupplies 10);};if (locked _container in [2, 3] || _container getVariable['EPOCH_Locked', false] || _lockedNear) then {[] spawn {disableSerialization;waitUntil {!isNull findDisplay 602};_display = findDisplay 602;_ctrl_cargo = _display displayCtrl 6401;_ctrl_ground = _display displayCtrl 6321;_ctrl_cargo ctrlEnable  false;ctrlSetFocus _ctrl_ground;ctrlActivate _ctrl_ground;};};";
	Killed          = "_this call EPOCH_fnc_playerDeath;";
	HandleRating    = "EPOCH_playerKarma = EPOCH_playerKarma + (_this select 1);0";
	HandleDamage    = "";
	HandleHeal      = "";
	Dammaged        = "";
	Hit             = "";
	HitPart         = "";
	GetInMan        = "";
	GetOutMan       = "_this call EPOCH_antiWall;";

	// suppress these units from spawning near Jammer or Traders
	nonJammerAI[] = {"B_Heli_Transport_01_F","PHANTOM","EPOCH_Sapper_F","Epoch_SapperB_F","I_UAV_01_F","EPOCH_RyanZombie_1"};
	nonTraderAI[] = {"B_Heli_Transport_01_F","PHANTOM","EPOCH_Sapper_F","Epoch_SapperB_F","I_UAV_01_F","Epoch_Cloak_F","GreatWhite_F","EPOCH_RyanZombie_1"};
	nonTraderAIRange = 50;

	// Fishing loots
	fishLoots[] = {"ItemTuna","ItemSeaBass","ItemSeaBass","ItemSeaBass","ItemTrout","ItemTrout","ItemTrout","ItemTrout","ItemTrout","ItemTrout"};

	// Player specific configs
	playerDeathScreen = "TapOut";
	playerKilledScreen = "TapOut2";
	playerDisableRevenge = 0; // 0 = invoke playerKilledScreen when killed by another player, 1 = disable.
	playerRevengeMinAliveTime = 900; // time in seconds player must be alive before Revenge option is available.

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
	#include "CfgEpochClient\WorldInteractions.hpp"
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
	unitTypes[] = {"I_Soldier_EPOCH", "I_Soldier2_EPOCH", "I_Soldier3_EPOCH"};//Selects from randomly
	maxUnitNum = 2; //Maximum number of units spawned when UAV spots target.
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
class CfgEpochAirDrop
{
	AirDropFreq = 1200; //AirDropChance, to decide if Air drop occurs, will only be checked once per AirDropFreq time period, for each player. Min value = 120.
	AirDropChance = 6; //Percentage chance of air drop, for current player. Checked every AirDropFreq and upon antagonists spawn trigger. -1 To disable.
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
	// maxNumber = 12; //Maximum number of zombies within range,
	disposeRange = 800; // distance before zombie is disposed
	smell[] = {38,0.42}; //Distance in metres up to which the zombie can smell a target. | Skill (0 - 1). 0 - Disable
	sight[] = {28,0.72}; //Zombie sight distance | Skill (0 - 1).
	hearing[] = {108,0.68}; //Zombie hearing distance / Skill. Max FiredNear EH Limit ?
	memory[] = {480,0.8}; //Memory time. / Weighting. WIP - Not Used
	reflexSpeed = 0.25; //Zombie brain will pause for this time when checking for new stimulus during each thought process. Lower number equals a more reactive zombie. (Guide Min 0.25 - Max 2.5).
	moans[] = {"ryanzombiesmoan1","ryanzombiesmoan2","ryanzombiesmoan3","ryanzombiesmoan4"};
	screams[] = {"ryanzombiesscream1", "ryanzombiesscream2", "ryanzombiesscream3", "ryanzombiesscream4", "ryanzombiesscream5", "ryanzombiesscream6", "ryanzombiesscream7", "ryanzombiesscream8", "ryanzombiesscream9"};
};
