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
    ["WeatherChances", [0.1,0.1,0.1,0.1]],
    ["showEarthQuakes", true],
	["showSatellites", true],
    ["showShippingContainers", true],
    ["cloneCost", 100],
    ["vehicleLockTime", "1800"],
    ["antagonistChancePDeath", 0.33],
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
    ["expiresCommunityStats", "7776000"],
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

// Convert Starter Trader items from alternative syntax
if (count EPOCH_starterTraderItems == 0) then {
	EPOCH_starterTraderItems = [[],[]];
};
if ((EPOCH_starterTraderItems select 0) isEqualTypeArray ["",0]) then {
	private _EPOCH_starterTraderItems = [[],[]];
	{
		if (_x isEqualTypeArray ["",0]) then {
			(_EPOCH_starterTraderItems select 0) pushback (_x select 0);
			(_EPOCH_starterTraderItems select 1) pushback (_x select 1);
		};
	} foreach EPOCH_starterTraderItems;
	EPOCH_starterTraderItems = _EPOCH_starterTraderItems;
};

// Convert Starter Trader Magazines from mags to rounds
{
	_maxrnd = 1;
	if ([_x,"cfgMagazines"] call Epoch_fnc_isAny) then {
		_maxrnd = getnumber (configfile >> "cfgMagazines" >> _x >> "count");
	};
	if (_maxrnd > 1) then {
		_currentStock = (EPOCH_starterTraderItems select 1 select _foreachindex)*_maxrnd; 
		(EPOCH_starterTraderItems select 1) set [_foreachindex, _currentStock];
	};
} foreach (EPOCH_starterTraderItems select 0);

// Load / Build Top-Statistics
_TopStatsVarsDb = (['CommunityStats', '0_TopStatsVars'] call EPOCH_fnc_server_hiveGETRANGE) param [1,[]];
_TopStatsDb = (['CommunityStats', '0_TopStats'] call EPOCH_fnc_server_hiveGETRANGE) param [1,[]];
EPOCH_TopStatsVars = (["CfgEpochClient", "TopStatsDialogEntries", []] call EPOCH_fnc_returnConfigEntryV2) apply {_x param [0,""]};
EPOCH_TopStats = [];
{
	_added1 = false;
	if (count _TopStatsVarsDb >= _foreachindex) then {
		if (_x isEqualTo (_TopStatsVarsDb select _foreachindex)) then {
			if (count _TopStatsDb >= _foreachindex) then {
				_newstats2 = [];
				{
					_x params ["_value","_UID","_name"];
					_communityStats = ((["CommunityStats", _UID] call EPOCH_fnc_server_hiveGETRANGE) param [1,[]]) param [0,[]];
					if !(_communityStats isequalto []) then {
						_name = "Unknown";
						_array = (['PlayerData', _UID] call EPOCH_fnc_server_hiveGETRANGE) param [1,[]];
						if !(_array isequalto []) then {
							_name = _array select 0;
						};
						_newstats2 pushback [_value,_UID,_name];
					};
				} foreach (_TopStatsDb select _foreachindex);
				EPOCH_TopStats pushback _newstats2;
				_added1 = true;
			};
		};
	};
	if (!_added1) then {
		EPOCH_TopStats pushback [];
	};
} foreach EPOCH_TopStatsVars;
if !(EPOCH_TopStatsVars isEqualTo _TopStatsVarsDb) then {
	["CommunityStats", "0_TopStatsVars", EPOCH_expiresCommunityStats, EPOCH_TopStatsVars] call EPOCH_fnc_server_hiveSETEX;
};
publicvariable "EPOCH_TopStats";
publicvariable "EPOCH_TopStatsVars";
