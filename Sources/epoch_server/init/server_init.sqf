/*
	Author: Aaron Clark - EpochMod.com

    Contributors:

	Description:
    Starts main functions

    Licence:
    Arma Public License Share Alike (APL-SA) - https://www.bistudio.com/community/licenses/arma-public-license-share-alike

    Github:
    https://github.com/EpochModTeam/Epoch/tree/release/Sources/epoch_server/init/server_init.sqf
*/
//[[[cog import generate_private_arrays ]]]
private ["_ReservedSlots","_SideHQ1","_SideHQ2","_SideHQ3","_abortAndError","_allowedVehicleIndex","_allowedVehicleListName","_allowedVehiclesList","_allowedVehiclesListArray","_cfgServerVersion","_channelColor","_channelNumber","_channelTXT","_clientVersion","_config","_configSize","_configVersion","_date","_dateChanged","_epochConfig","_epochWorldPath","_existingStock","_hiveVersion","_index","_indexStock","_instanceID","_marker","_markercolor","_markertxt","_markertype","_pos","_radio","_response","_sapper","_serverConfig","_serverSettingsConfig","_servicepoints","_startTime","_staticDateTime","_timeDifference","_vehicleCount","_vehicleSlotLimit","_worldSize"];
//[[[end]]]
_startTime = diag_tickTime;
missionNamespace setVariable ['Epoch_ServerVersion', getText(configFile >> "CfgMods" >> "Epoch" >> "version"), true];
diag_log format["Epoch: Starting ArmA3 Epoch Server, Version %1",Epoch_ServerVersion];

_abortAndError = {
    // kick all players with reverse BE kicks
    true remoteExec ['EPOCH_client_rejectPlayer',-2, true];
    // flood server rpt with reason
    for "_i" from 0 to 15 do {
        diag_log _this;
    };
};

_cfgServerVersion = configFile >> "CfgServerVersion";
_serverSettingsConfig = configFile >> "CfgEpochServer";
_epochConfig = configFile >> "CfgEpoch";

_clientVersion = getText(_cfgServerVersion >> "client");
_configVersion = getText(_cfgServerVersion >> "config");
_hiveVersion = getText(_cfgServerVersion >> "hive");

if (_clientVersion != Epoch_ServerVersion) exitWith{
    format["Epoch: Version mismatch! Current: %2 Needed: %1", _clientVersion, Epoch_ServerVersion] call _abortAndError;
};
if (_configVersion != getText(configFile >> "CfgPatches" >> "A3_server_settings" >> "epochVersion")) exitWith {
    format["Epoch: Config file needs updated! Current: %1 Needed: %2", _configVersion, getText(configFile >> "CfgPatches" >> "A3_server_settings" >> "epochVersion")] call _abortAndError;
};
if (isClass(getMissionConfig "CfgEpochClient") && _configVersion != getText(getMissionConfig "CfgEpochClient" >> "epochVersion")) exitWith{
	format["Epoch: Mission Config file needs updated! Current: %1 Needed: %2", _configVersion, getText(getMissionConfig "CfgEpochClient" >> "epochVersion")] call _abortAndError;
};
if (("epochserver" callExtension "") != _hiveVersion) exitWith {
    format["Epoch: Server DLL mismatch! Current: %1 Needed: %2", "epochserver" callExtension "",_hiveVersion] call _abortAndError;
};

_serverConfig = call compile ("epochserver" callExtension "000");
EPOCH_fn_InstanceID = compileFinal (str (_serverConfig select 0));
_instanceID = call EPOCH_fn_InstanceID;
if (isNil "_instanceID") exitWith{
    "Epoch: InstanceID missing!" call _abortAndError;
};

EPOCH_modCUPWeaponsEnabled = (getNumber (configFile >> "CfgPatches" >> "CUP_Weapons_WeaponsCore" >> "requiredVersion") > 0);
EPOCH_modCUPVehiclesEnabled = (getNumber (configFile >> "CfgPatches" >> "CUP_WheeledVehicles_Core" >> "requiredVersion") > 0);
if (EPOCH_modCUPWeaponsEnabled) then {
    diag_log "Epoch: CUP Weapons detected";
};
if (EPOCH_modCUPVehiclesEnabled) then {
    diag_log "Epoch: CUP Vehicles detected";
};

diag_log "Epoch: Init Variables";
call compile preprocessFileLineNumbers "\epoch_server\init\server_variables.sqf";
call compile preprocessFileLineNumbers "\epoch_server\init\server_securityfunctions.sqf";


["I", _instanceID, "86400", ["CONTINUE"]] call EPOCH_fnc_server_hiveSETEX;
diag_log format["Epoch: Start Hive, Instance ID: '%1'", _instanceID];

diag_log "Epoch: Init Connect/Disconnect handlers";

onPlayerConnected {}; // seems this is needed or addMissionEventHandler "PlayerConnected" does not work. as of A3 1.60
addMissionEventHandler ["PlayerConnected", {
    params ["_id","_uid","_name","_jip","_owner"];
    // TODO: diabled STEAMAPI - Vac ban check needs reworked.
    // "epochserver" callExtension format["001|%1", _uid];
    // diag_log format["playerConnected:%1", _this];
    ["PlayerData", _uid, EPOCH_expiresPlayer, [_name]] call EPOCH_fnc_server_hiveSETEX;
    ['Connected', [_uid, _name]] call EPOCH_fnc_server_hiveLog;
}];

addMissionEventHandler ["HandleDisconnect", {_this call EPOCH_server_onPlayerDisconnect}];

diag_log "Epoch: Setup Side Settings";
//set side status
_SideHQ1 = createCenter resistance;
_SideHQ2 = createCenter east;
_SideHQ3 = createCenter west;
RESISTANCE setFriend [WEST, 0];
WEST setFriend [RESISTANCE, 0];
RESISTANCE setFriend [EAST, 0];
EAST setFriend [RESISTANCE, 0];
// friendly
EAST setFriend[WEST, 1];
WEST setFriend[EAST, 1];

diag_log format["Epoch: Setup World Settings for %1",worldName];
//World Settings
_worldSize = worldSize;
_epochWorldPath = _epochConfig >> worldName;
if (isClass _epochWorldPath) then {
    _configSize = getNumber(_epochWorldPath >> "worldSize");
    if (_configSize > 0) then {
      _worldSize = _configSize;
    };
};
epoch_centerMarkerPosition = getMarkerPos "center";
if (epoch_centerMarkerPosition isEqualTo [0,0,0]) then {
    diag_log "Epoch: Error cannot find center marker!";
};
EPOCH_dynamicVehicleArea = _worldSize / 2;

// custom radio channels
EPOCH_customChannels = [];
for "_i" from 0 to 9 do {
    _radio = configfile >> "CfgWeapons" >> format["EpochRadio%1", _i];
    _channelTXT = getText(_radio >> "displayName");
    // _channelNumber = getNumber(_radio >> "channelID");
    _channelColor = getArray(_radio >> "channelColor");
    _index = radioChannelCreate[_channelColor, _channelTXT, "%UNIT_NAME", []];
    EPOCH_customChannels pushBack _index;
};

//Execute Server Functions
diag_log "Epoch: Loading buildings";
EPOCH_BuildingSlotsLimit call EPOCH_server_loadBuildings;

diag_log "Epoch: Loading teleports and static props";
call EPOCH_server_createTeleport;

diag_log "Epoch: Loading NPC traders";
EPOCH_NPCSlotsLimit call EPOCH_server_loadTraders;

diag_log "Epoch: Spawning NPC traders";
call EPOCH_server_spawnTraders;

diag_log "Epoch: Loading vehicles";
// Vehicle slot limit set to total of all allowed limits
_allowedVehicleIndex = if (EPOCH_modCUPVehiclesEnabled) then {if (EPOCH_mod_madArma_Enabled) then {3} else {1}} else {if (EPOCH_mod_madArma_Enabled) then {2} else {0}};
_allowedVehicleListName = ["allowedVehiclesList","allowedVehiclesList_CUP","allowedVehiclesList_MAD","allowedVehiclesList_MADCUP"] select _allowedVehicleIndex;
if !(EPOCH_forcedVehicleSpawnTable isEqualTo "") then {
    _allowedVehicleListName = EPOCH_forcedVehicleSpawnTable;
};
// do something here

_allowedVehiclesList = getArray(_epochConfig >> worldName >> _allowedVehicleListName);
_vehicleSlotLimit = 0;
{_vehicleSlotLimit = _vehicleSlotLimit + (_x select 1)} forEach _allowedVehiclesList;
_ReservedSlots = 50;
_vehicleSlotLimit = _vehicleSlotLimit + _ReservedSlots;
if (EPOCH_useOldLoadVehicles) then {
    _vehicleSlotLimit call EPOCH_load_vehicles_old;
} else {
    _vehicleSlotLimit call EPOCH_load_vehicles;
};
diag_log "Epoch: Spawning vehicles";
_allowedVehiclesListArray = [];
{
    _x params ["_vehClass","_velimit"];
    _vehicleCount = {typeOf _x == _vehClass} count vehicles;

    // Load how many of this vehicle are in stock at any trader.
    _indexStock = EPOCH_traderStoredVehicles find _vehClass;
    if (_indexStock != -1) then {
        _existingStock = EPOCH_traderStoredVehiclesCnt select _indexStock;
        _vehicleCount = _vehicleCount + _existingStock;
    };

    for "_i" from 1 to (_velimit-_vehicleCount) do {
        _allowedVehiclesListArray pushBack _vehClass;
    };
} forEach _allowedVehiclesList;
[_allowedVehiclesListArray] call EPOCH_spawn_vehicles;

diag_log "Epoch: Loading storage";
EPOCH_StorageSlotsLimit call EPOCH_load_storage;

diag_log "Epoch: Loading static loot";
call EPOCH_server_spawnBoatLoot;

[] execFSM "\epoch_server\system\server_monitor.fsm";

// Setting Server Date and Time
_dateChanged = false;
_date = date;

_staticDateTime = [_serverSettingsConfig, "StaticDateTime", []] call EPOCH_fnc_returnConfigEntry;
_timeDifference = [_serverSettingsConfig, "timeDifference", 0] call EPOCH_fnc_returnConfigEntry;

if (_staticDateTime isEqualto []) then {
    _response = "epochserver" callExtension "510";
    if (_response != "") then {
        diag_log format ["Epoch: Set Real Time: %1", _response];
        _date = call compile _response;
        _date resize 5;
        _date set[0, (_date select 0) + 21];
        _date set[3, (_date select 3) + _timeDifference];
        _dateChanged = true;
    };
} else {
    {
        if (_x != 0) then {
            _date set [_forEachIndex, _x];
            _dateChanged = true;
        };
    }forEach _staticDateTime;
};
if (_dateChanged) then {
    setDate _date;
    //add 1 min to be 100% correct
    _date set [4, (_date select 4) + 1];
    _date spawn {
        uiSleep 60;
        setDate _this;
    };
};

_config = 'CfgServicePoint' call EPOCH_returnConfig;
_servicepoints = getArray (_config >> worldname >> 'ServicePoints');
{
	_pos = _x;
	_markertype = "mil_dot";
	_markercolor = "ColorBlack";
	_markertxt = "Service Point";
	if (count _x > 3) then {
		_pos = _x select 0;
		if ((_x select 3) isequaltype "") then {
			_markertype = _x select 3;
		};
		if (count _x > 4) then {
			if ((_x select 4) isequaltype "") then {
				_markercolor = _x select 4;
			};
		};
		if (count _x > 5) then {
			if ((_x select 5) isequaltype "") then {
				_markertxt = _x select 5;
			};
		};
	};
	if !(_markertype isequalto "") then {
		_marker = createMarker [('ServicePointMarker'+(str _foreachindex)), _pos];
		_marker setmarkertype _markertype;
		if !(_markercolor isequalto "") then {
			_marker setmarkercolor _markercolor;
		};
		if !(_markertxt isequalto "") then {
			_marker setMarkerText _markertxt;
		};
		if !(surfaceiswater _pos) then {
			"Land_HelipadCircle_F" createvehicle _pos;
		};
	};
} forEach _ServicePoints;

// Remove Auto-Refuel from all maps
{_x setFuelCargo 0;} foreach ((epoch_centerMarkerPosition nearObjects ['Building',EPOCH_dynamicVehicleArea]) select {getFuelCargo _x > 0});

// set time multiplier
setTimeMultiplier ([_serverSettingsConfig, "timeMultiplier", 1] call EPOCH_fnc_returnConfigEntry);

// globalize tax rate
missionNamespace setVariable ["EPOCH_taxRate", [_serverSettingsConfig, "taxRate", 0.1] call EPOCH_fnc_returnConfigEntry, true];

// start accepting logins
missionNamespace setVariable ["EPOCH_SERVER_READY", true, true];

// spawn a single sapper to preload
_sapper = createAgent ["Epoch_Sapper_F", [0,0,0], [], 0, "CAN_COLLIDE"];
_sapper setDamage 1;
_sapper enableSimulationGlobal false;

diag_log format ["Epoch: Server Start Complete: %1 seconds",diag_tickTime-_startTime];

// unit test start
if (EPOCH_enableUnitTestOnStart isEqualTo 1) then {
    call EPOCH_fnc_server_hiveUnitTest;
    EPOCH_enableUnitTestOnStart = nil;
};
