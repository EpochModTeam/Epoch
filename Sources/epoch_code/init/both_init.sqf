/*
	Author: Aaron Clark - EpochMod.com

    Contributors:

	Description:
	Initalize variables used client side and server side

    Licence:
    Arma Public License Share Alike (APL-SA) - https://www.bistudio.com/community/licenses/arma-public-license-share-alike

    Github:
    https://github.com/EpochModTeam/Epoch/tree/release/Sources/epoch_code/init/both_init.sqf
*/
//[[[cog import generate_private_arrays ]]]
private ["_antagonistSpawnDefaults","_customVarsInit","_say3dsounds","_say3dsoundsConfig","_spawnLimits","_communityStatsInit"];
//[[[end]]]

// detect if Ryan's Zombies and Deamons mod is present
if (["CfgEpochClient", "ryanZombiesEnabled", true] call EPOCH_fnc_returnConfigEntryV2) then {
    EPOCH_mod_Ryanzombies_Enabled = (parseNumber (getText (configFile >> "CfgPatches" >> "Ryanzombies" >> "version")) >= 4.5);
    if (EPOCH_mod_Ryanzombies_Enabled) then {
        diag_log "Epoch: Ryanzombies detected";
    };
} else {
    EPOCH_mod_Ryanzombies_Enabled = false;
};

// detect if Mad Arma is present
if (["CfgEpochClient", "madArmaEnabled", true] call EPOCH_fnc_returnConfigEntryV2) then {
    EPOCH_mod_madArma_Enabled = (parseNumber (getText (configFile >> "CfgPatches" >> "bv_wheels" >> "version")) >= 2016);
    if (EPOCH_mod_madArma_Enabled) then {
        diag_log "Epoch: Mad Arma detected";
    };
} else {
    EPOCH_mod_madArma_Enabled = false;
};

// Check if Advanced Vehicle Repair is enabled
if (["CfgEpochClient", "UseAdvancedVehicleRepair", true] call EPOCH_fnc_returnConfigEntryV2) then {
	EPOCH_AdvancedVehicleRepair_Enabled = true;
	diag_log "Epoch: Advanced Vehicle Repair Enabled";
} else {
    EPOCH_AdvancedVehicleRepair_Enabled = false;
};

// Init Custom vars
EPOCH_customVars = [];
EPOCH_defaultVars = [];
EPOCH_customVarLimits = [];
EPOCH_customVarsDefaults = [
	["Temp",98.6,[106.7,95]],
	["Hunger",5000,[5000,0]],
	["Thirst",2500,[2500,0]],
	["AliveTime",0,[0,0]],
	["Energy",0,[2500,0]],
	["Wet",0,[100,0]],
	["Soiled",0,[100,0]],
	["Immunity",0,[100,0]],
	["Toxicity",0,[100,0]],
	["Stamina",100,["EPOCH_playerStaminaMax",0]],
	["Crypto",0,[250000,0]],
	["HitPoints",[0,0,0,0],[1,1,1,1]],
	["BloodP",100,[190,0]],
	["SpawnArray",[],[]],
	["Karma",0,[50000,-50000]],
	["Alcohol",0,[100,0]],
	["Radiation",0,[100,0]],
	["Nuisance",0,[100,0]],
	["MissionArray",[],[]]
];
_customVarsInit = ["CfgEpochClient", "customVarsDefaults", EPOCH_customVarsDefaults] call EPOCH_fnc_returnConfigEntryV2;
{
	EPOCH_customVars pushBack (_x select 0);
	EPOCH_defaultVars pushBack (_x select 1);
	EPOCH_customVarLimits pushBack (_x param [2,[]]);
} forEach _customVarsInit;
EPOCH_customVarCount = count EPOCH_customVars;

// Init Community Stats
EPOCH_communityStats = [];
EPOCH_defaultStatVars = [];
_communityStatsInit = ["CfgEpochClient", "defineCommunityStats", []] call EPOCH_fnc_returnConfigEntryV2;
EPOCH_communityStatsDefaults = _communityStatsInit;
{
	EPOCH_communityStats pushBack (_x select 0);
	EPOCH_defaultStatVars pushBack (_x select 1);
} forEach _communityStatsInit;
EPOCH_communityStatsCount = count EPOCH_communityStats;


// Init antagonist spawn limits
EPOCH_spawnIndex = [];
EPOCH_spawnLimits = [];
_antagonistSpawnDefaults = [
	["Epoch_Cloak_F", 1],
	["GreatWhite_F", 2],
	["Epoch_Sapper_F",2],
    ["Epoch_SapperG_F",1],
	["Epoch_SapperB_F",1],
	["I_UAV_01_F",2],
	["PHANTOM",1],
	["B_Heli_Transport_01_F",1],
	["EPOCH_RyanZombie_1",12]
];
_spawnLimits = ["CfgEpochClient", "antagonistSpawnIndex", _antagonistSpawnDefaults] call EPOCH_fnc_returnConfigEntryV2;
{
	_x params ["_spawnName","_spawnLimit"];
	if (_spawnName isEqualTo "EPOCH_RyanZombie_1") then {
		if (EPOCH_mod_Ryanzombies_Enabled) then {
			EPOCH_spawnIndex pushBack _spawnName;
			EPOCH_spawnLimits pushBack _spawnLimit;
		};
	} else {
		EPOCH_spawnIndex pushBack _spawnName;
		EPOCH_spawnLimits pushBack _spawnLimit;
	};
} forEach _spawnLimits;

//GroupSize (number) // Price (String)
EPOCH_group_upgrade_lvl = ["CfgEpochClient", "group_upgrade_lvl", [4,"100",6,"300",8,"500",10,"1000",12,"1500",13,"1750",14,"2000",15,"3000",16,"5000"]] call EPOCH_fnc_returnConfigEntryV2;

// Init 3d sound handler
EPOCH_sounds = [];
_say3dsoundsConfig = 'CfgSay3Dhandler' call EPOCH_returnConfig;
_say3dsounds = "isClass _x" configClasses (_say3dsoundsConfig);
{
	EPOCH_sounds pushBack (configName _x);
} forEach _say3dsounds;

// disable remote sensors on server and client as all Epoch AI is local to the side controlling it.
disableRemoteSensors (["CfgEpochClient", "disableRemoteSensors", true] call EPOCH_fnc_returnConfigEntryV2);
// Enable Dynamic simulation on both server and clients (maybe only needed server side)
// DynSim is handled locally and yes server and clients will need these configurations
_dynSimToggle = ["CfgDynamicSimulation", "enableDynamicSimulationSystem", true] call EPOCH_fnc_returnConfigEntryV2;
enableDynamicSimulationSystem _dynSimToggle;
if(_dynSimToggle)then
{
	_cfgDynamicSimulation = 'CfgDynamicSimulation' call EPOCH_returnConfig;
	"IsMoving" setDynamicSimulationDistanceCoef getNumber(_cfgDynamicSimulation >> "isMovingCoefValue");
	"Group" setDynamicSimulationDistance getNumber(_cfgDynamicSimulation >> "groupDynSimDistance");
	"Vehicle" setDynamicSimulationDistance getNumber(_cfgDynamicSimulation >> "vehicleDynSimDistance");
	"EmptyVehicle" setDynamicSimulationDistance getNumber(_cfgDynamicSimulation >> "emptyVehicleDynSimDistance");
	"Prop" setDynamicSimulationDistance getNumber(_cfgDynamicSimulation >> "propDynSimDistance");
};