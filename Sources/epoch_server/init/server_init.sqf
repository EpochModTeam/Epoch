/*
	Author: Aaron Clark - EpochMod.com

    Contributors:

	Description:
    Starts main functions

    Licence:
    Arma Public License Share Alike (APL-SA) - https://www.bistudio.com/community/licenses/arma-public-license-share-alike

    Github:
    https://github.com/EpochModTeam/Epoch/tree/master/Sources/epoch_server/init/server_init.sqf
*/
_startTime = diag_tickTime;
Epoch_ServerVersion = getText(configFile >> "CfgMods" >> "Epoch" >> "version");
EPOCH_SERVER = [];
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

diag_log "Epoch: Init Variables";
call compile preprocessFileLineNumbers "\x\addons\a3_epoch_server\init\server_variables.sqf";
call compile preprocessFileLineNumbers "\x\addons\a3_epoch_server\init\server_securityfunctions.sqf";

["I", _instanceID, "86400", ["CONTINUE"]] call EPOCH_fnc_server_hiveSETEX;
diag_log format["Epoch: Start Hive, Instance ID: '%1'", _instanceID];

diag_log "Epoch: Init Connect/Disconnect handlers";
addMissionEventHandler ["HandleDisconnect", { _this call EPOCH_server_onPlayerDisconnect }];
_onPlayerDisconnected = {
    diag_log format["playerDisconnected:%1:%2", _uid, _name];
    ['Disconnected', [_uid, _name]] call EPOCH_fnc_server_hiveLog;
    _uid call EPOCH_server_disconnect;
};
_onPlayerConnected = {
    "epochserver" callExtension format["001|%1", _uid];
    diag_log format["playerConnected:%1:%2", _uid, _name];
    ['Connected', [_uid, _name]] call EPOCH_fnc_server_hiveLog;
    ["PlayerData", _uid, EPOCH_expiresPlayer, [_name]] call EPOCH_fnc_server_hiveSETEX;
};
if ([_serverSettingsConfig, "CBA_compatibility", false] call EPOCH_fnc_returnConfigEntry) then {
    ["EPOCH_onPlayerConnected", "onPlayerConnected", _onPlayerConnected] call BIS_fnc_addStackedEventHandler;
    ["EPOCH_onPlayerDisconnected", "onPlayerDisconnected", _onPlayerDisconnected] call BIS_fnc_addStackedEventHandler;
} else {
    onPlayerDisconnected _onPlayerDisconnected;
    onPlayerConnected _onPlayerConnected;
};

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
_epochWorldPath = configfile >> "CfgEpoch" >> worldName;
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
EPOCH_BuildingSlotsLimit call EPOCH_fnc_server_loadBuildings;

diag_log "Epoch: Loading teleports and static props";
call EPOCH_server_createTeleport;

diag_log "Epoch: Loading NPC traders";
EPOCH_NPCSlotsLimit call EPOCH_server_loadTraders;

diag_log "Epoch: Spawning NPC traders";
call EPOCH_server_spawnTraders;

diag_log "Epoch: Loading vehicles";
EPOCH_VehicleSlotsLimit call EPOCH_load_vehicles;

diag_log "Epoch: Spawning vehicles";
call EPOCH_spawn_vehicles;

diag_log "Epoch: Loading storage";
EPOCH_StorageSlotsLimit call EPOCH_load_storage;

diag_log "Epoch: Loading static loot";
call EPOCH_server_spawnBoatLoot;

[] execFSM "\x\addons\a3_epoch_server\system\server_monitor.fsm";

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

// set time multiplier
setTimeMultiplier ([_serverSettingsConfig, "timeMultiplier", 1] call EPOCH_fnc_returnConfigEntry);

// globalize tax rate
EPOCH_taxRate = [_serverSettingsConfig, "taxRate", 0.1] call EPOCH_fnc_returnConfigEntry;
publicVariable "EPOCH_taxRate";

if !(EPOCH_SERVER isEqualTo []) then {
    publicVariable "EPOCH_SERVER";
};
publicVariable "Epoch_ServerVersion";

diag_log format ["Epoch: Server Start Complete: %1 seconds",diag_tickTime-_startTime];
