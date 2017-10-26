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
private ["_cfgDynamicSimulation","_communityStatsInit","_customVarsInit","_dynSimToggle"];
//[[[end]]]

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
	["NotUsed",0,[50000,-50000]],
	["Alcohol",0,[100,0]],
	["Radiation",0,[100,0]],
	["Nuisance",0,[100,0]],
	["MissionArray",[],[]]
];
_customVarsInit = ["CfgEpochClient", "customVarsDefaults", EPOCH_customVarsDefaults] call EPOCH_fnc_returnConfigEntryV2;
EPOCH_customVars = _customVarsInit apply {_x param [0,""]};
EPOCH_defaultVars = _customVarsInit apply {_x param [1,0]};
EPOCH_customVarLimits = _customVarsInit apply {_x param [2,[]]};
EPOCH_customVarCount = count EPOCH_customVars;

// Init Community Stats
EPOCH_communityStats = [];
EPOCH_defaultStatVars = [];
EPOCH_communityStatsLimits = [];
_communityStatsInit = ["CfgEpochClient", "defineCommunityStats", []] call EPOCH_fnc_returnConfigEntryV2;
EPOCH_communityStats = _communityStatsInit apply {_x param [0,""]};
EPOCH_defaultStatVars = _communityStatsInit apply {_x param [1,0]};
EPOCH_communityStatsLimits = _communityStatsInit apply {_x param [2,[]]};
EPOCH_communityStatsCount = count EPOCH_communityStats;

//GroupSize (number) // Price (String)
EPOCH_group_upgrade_lvl = ["CfgEpochClient", "group_upgrade_lvl", [4,"100",6,"300",8,"500",10,"1000",12,"1500",13,"1750",14,"2000",15,"3000",16,"5000"]] call EPOCH_fnc_returnConfigEntryV2;

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
