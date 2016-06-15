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
private ["_customVarsInit","_antagonistSpawnDefaults","_spawnLimits","_say3dsounds"];

// detect if Ryan's Zombies and Deamons mod is present
EPOCH_mod_Ryanzombies_Enabled = (parseNumber (getText (configFile >> "CfgPatches" >> "Ryanzombies" >> "version")) >= 4.2);
if (EPOCH_mod_Ryanzombies_Enabled) then {
    diag_log "Epoch: Ryanzombies detected";
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
	["Nuisance",0,[100,0]]
];
_customVarsInit = ["CfgEpochClient", "customVarsDefaults", EPOCH_customVarsDefaults] call EPOCH_fnc_returnConfigEntryV2;
{
	EPOCH_customVars pushBack (_x select 0);
	EPOCH_defaultVars pushBack (_x select 1);
	EPOCH_customVarLimits pushBack (_x param [2,[]]);
} forEach _customVarsInit;
EPOCH_customVarCount = count EPOCH_customVars;

// Init antagonist spawn limits
EPOCH_spawnIndex = [];
EPOCH_spawnLimits = [];
_antagonistSpawnDefaults = [
	["Epoch_Cloak_F", 1],
	["GreatWhite_F", 2],
	["Epoch_Sapper_F",2],
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
EPOCH_soundsDistance = [];
_say3dsounds = "isClass _x" configClasses (configFile >> "CfgSay3Dhandler");
{
	EPOCH_sounds pushBack (configName _x);
	EPOCH_soundsDistance pushBack getNumber(_x >> "distance");
} forEach _say3dsounds;

// disable remote sensors on server and client as all Epoch AI is local to the side controlling it.
disableRemoteSensors (["CfgEpochClient", "disableRemoteSensors", true] call EPOCH_fnc_returnConfigEntryV2);
