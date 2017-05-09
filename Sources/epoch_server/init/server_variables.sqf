/*
	Author: Aaron Clark - EpochMod.com

    Contributors:

	Description:
    Init Server Variables

    Licence:
    Arma Public License Share Alike (APL-SA) - https://www.bistudio.com/community/licenses/arma-public-license-share-alike

    Github:
    https://github.com/EpochModTeam/Epoch/tree/release/Sources/epoch_server/init/server_variables.sqf
*/
EPOCH_BuildingSlots = [];
EPOCH_TraderSlots = [];
EPOCH_saveBldQueue = [];
EPOCH_saveVehQueue = [];
EPOCH_saveStorQueue = [];
EPOCH_saveBuildQueue = [];
EPOCH_cleanupQueue = [];
EPOCH_defaultVars_SEPXVar = compileFinal str(EPOCH_defaultVars);
EPOCH_group_upgrade_lvl_SEPXVar = EPOCH_group_upgrade_lvl;
EPOCH_staticTraderLocations = [];
EPOCH_staticNPCTraderPos = [];
EPOCH_traderStoredVehicles = [];
EPOCH_traderStoredVehiclesCnt = [];

private _configArray = [
	["serverRestart", false],
    ["forceRestartTime", 14400],
    ["StorageSlotsLimit",1500],
    ["BuildingSlotsLimit", 1500],
    ["StaticDateTime", []],
    ["timeDifference", 0],
    ["lootMultiplier", 0.5],
    ["WeatherStaticForecast", []],
    ["showEarthQuakes", true],
    ["showShippingContainers", true],
    ["cloneCost", 100],
    ["vehicleLockTime", 1800],
    ["antagonistChanceTrash", 0.09],
    ["antagonistChancePDeath", 0.33],
    ["antagonistChanceLoot", 0.09],
    ["taxRate", 0.1],
    ["starterTraderItems", [[], []]],
    ["SHOW_TRADERS", true],
    ["SHOW_JAMMERS", true],
    ["SHOW_BOATLOOT", true],
    ["NPCSlotsLimit", 50],
    ["forceStaticTraders", true],
    ["expiresBuilding", "604800"],
    ["expiresPlayer", "2592000"],
    ["expiresBank", "7776000"],
    ["expiresVehicle", "604800"],
    ["expiresAIdata", "604800"],
    ["hiveAdminCmdExec", false],
    ["hiveAdminSavePlayerList", true],
    ["hiveAdminCmdTime", 5],
    ["DEBUG_VEH", false],
    ["useOldLoadVehicles", false],
    ["enableUnitTestOnStart", 0],
    ["forcedVehicleSpawnTable",""],
    ["forcedLootSpawnTable",""]
];

EPOCH_fnc_returnConfigEntry = {
    private["_defaultData", "_config", "_varData"];
    _defaultData = _this select 2;
	_varData = _defaultData;
	if (isClass(_this select 0)) then{
		_config = (_this select 0) >> (_this select 1);
		_varData = switch (typeName _defaultData) do {
			case "SCALAR": {if (isNumber (_config)) then { getNumber _config } else {_defaultData} };
			case "BOOL": {if (isText (_config)) then {(getText _config) isEqualTo "true"} else {if (isNumber (_config)) then {(getNumber _config) isEqualTo 1} else {_defaultData}}};
			case "ARRAY": {if (isArray (_config)) then { getArray _config } else {_defaultData} };
			case "STRING": {if (isText (_config)) then { getText _config } else {_defaultData} };
			default {_defaultData};
		};
	};
    _varData
};

// Cast default vars to global vars
// Note: TODO not all of these should be cast to a global var to save memory. If used only once use config lookup.
private _serverSettingsConfig = configFile >> "CfgEpochServer";
{
    private _varData = [_serverSettingsConfig,_x select 0,_x select 1] call EPOCH_fnc_returnConfigEntry;
    missionNamespace setVariable[format["EPOCH_%1", _x select 0], _varData];
}forEach _configArray;
