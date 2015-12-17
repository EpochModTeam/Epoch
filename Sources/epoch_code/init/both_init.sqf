/*
	Author: Aaron Clark - EpochMod.com

    Contributors:

	Description:
	Initalize variables used client side and server side

    Licence:
    Arma Public License Share Alike (APL-SA) - https://www.bistudio.com/community/licenses/arma-public-license-share-alike

    Github:
    https://github.com/EpochModTeam/Epoch/tree/master/Sources/epoch_code/init/both_init.sqf
*/

// Init Custom vars
EPOCH_customVars = [];
EPOCH_defaultVars = [];
EPOCH_customVarsDefaults = [
	["Temp",98.6],
	["Hunger",5000],
	["Thirst",2500],
	["AliveTime",0],
	["Energy",0],
	["Wet",0],
	["Soiled",0],
	["Immunity",0],
	["Toxicity",0],
	["Stamina",100],
	["Crypto",0],
	["HitPoints",[0,0,0,0]],
	["BloodP",100],
	["SpawnArray",[]],
	["Karma",0],
	["Alcohol",0],
	["Radiation",0]
];
_customVarsInit = ["CfgEpochClient", "customVarsDefaults", EPOCH_customVarsDefaults] call EPOCH_fnc_returnConfigEntryV2;
{
	EPOCH_customVars pushBack (_x select 0);
	EPOCH_defaultVars pushBack (_x select 1);
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
	["B_Heli_Transport_01_F",1]
];
_spawnLimits = ["CfgEpochClient", "antagonistSpawnIndex", _antagonistSpawnDefaults] call EPOCH_fnc_returnConfigEntryV2;
{
	EPOCH_spawnIndex pushBack (_x select 0);
	EPOCH_spawnLimits pushBack (_x select 1);
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

// default loot classes var
EPOCH_lootClasses = [
	["shelfPos", "Shelf_EPOCH", true],
	["fridgePos", "Fridge_EPOCH", true],
	["bedPos", "Bed_EPOCH", false],
	["couchPos", "Couch_EPOCH", false],
	["wardrobePos", "wardrobe_epoch", false],
	["cookerPos", "cooker_epoch", false],
	["chairPos", ["Chair_EPOCH", "ChairRed_EPOCH"], true],
	["filingPos", "Filing_epoch", true],
	["pelicanPos", "Pelican_EPOCH", false],
	["tablePos", "Table_EPOCH", false],
	["lockerPos", "Locker_EPOCH", false],
	["toolRackPos", "ToolRack_EPOCH", false],
	["shoeboxPos", "Shoebox_EPOCH", false],
	["palletPos", "Tarp_EPOCH", false],
	["freezerPos", "Freezer_EPOCH", false],
	["cabinetPos", "Cabinet_EPOCH", false]
];
