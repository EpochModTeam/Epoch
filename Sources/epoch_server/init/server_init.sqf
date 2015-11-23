_startTime = diag_tickTime;
Epoch_ServerVersion = getText(configFile >> "CfgMods" >> "Epoch" >> "version");
EPOCH_SERVER = [];
diag_log format["Epoch: Starting ArmA3 Epoch Server, Version %1",Epoch_ServerVersion];

_abortAndError = {
    publicVariable "EPOCH_SERVER";
    EPOCH_BADHIVE = true; //Kick all player
    publicVariable "EPOCH_BADHIVE";
    for "_i" from 0 to 15 do {
        diag_log _this;
    };
};

_clientVersion = getText(configFile >> "CfgServerVersion" >> "client");
_configVersion = getText(configFile >> "CfgServerVersion" >> "config");
_hiveVersion = getText(configFile >> "CfgServerVersion" >> "hive");

if (_clientVersion != Epoch_ServerVersion) exitWith{
    format["Epoch: Version mismatch! Current: %2 Needed: %1", _clientVersion, Epoch_ServerVersion] call _abortAndError;
};
if (_configVersion != getText(configFile >> "CfgPatches" >> "A3_server_settings" >> "epochVersion")) exitWith {
    format["Epoch: Config file needs updated! Current: %1 Needed: %2", _configVersion, getText(configFile >> "CfgPatches" >> "A3_server_settings" >> "epochVersion")] call _abortAndError;
};


if (isClass(missionConfigFile >> "CfgEpochClient") && _configVersion != getText(missionConfigFile >> "CfgEpochClient" >> "epochVersion")) exitWith{
	format["Epoch: Mission Config file needs updated! Current: %1 Needed: %2", _configVersion, getText(missionConfigFile >> "CfgEpochClient" >> "epochVersion")] call _abortAndError;
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

call EPOCH_server_publicEH;
diag_log "Epoch: Init PublicEH";

// Connect/Disconnect
addMissionEventHandler ["HandleDisconnect", { _this call EPOCH_server_onPlayerDisconnect }];
onPlayerDisconnected{
    diag_log format["playerDisconnected:%1:%2", _uid, _name];
    ['Disconnected', [_uid, _name]] call EPOCH_fnc_server_hiveLog;
    _uid call EPOCH_server_disconnect;
};
onPlayerConnected{
    "epochserver" callExtension format["001|%1", _uid];
    diag_log format["playerConnected:%1:%2", _uid, _name];
    ['Connected', [_uid, _name]] call EPOCH_fnc_server_hiveLog;
    ["PlayerData", _uid, EPOCH_expiresPlayer, [_name]] call EPOCH_fnc_server_hiveSETEX;
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

// diag_log "Epoch: Set Weather";
// true call EPOCH_server_setWeather;

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
_startTime spawn {

    diag_log "Epoch: Loading buildings";
    _workload1 = EPOCH_BuildingSlotsLimit call EPOCH_server_loadBuildings;


    // Underground and teleports
    diag_log "Epoch: Loading teleports and static props";
    _workload8 = [] call EPOCH_server_createTeleport;


    // Traders
    diag_log "Epoch: Loading NPC traders";
    _workload4 = EPOCH_NPCSlotsLimit call EPOCH_server_loadTraders;


    diag_log "Epoch: Spawning NPC traders";
    _workload5 = [] call EPOCH_server_spawnTraders;


    // Vehicles
    diag_log "Epoch: Loading vehicles";
    _workload2 = EPOCH_VehicleSlotsLimit call EPOCH_load_vehicles;


    diag_log "Epoch: Spawning vehicles";
    _workload3 = [] call EPOCH_spawn_vehicles;


    // Storage
    diag_log "Epoch: Loading storage";
    _workload6 = EPOCH_StorageSlotsLimit call EPOCH_load_storage;


    // Loot
    diag_log "Epoch: Loading static loot";
    _workload9 = [] call EPOCH_server_spawnBoatLoot;


    [] execFSM "\x\addons\a3_epoch_server\system\server_monitor.fsm";

    _serverSettingsConfig      = configFile >> "CfgEpochServer";

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

    diag_log format ["Epoch: Server Start Complete: %1 seconds",diag_tickTime-_this];

    if (_dateChanged) then {
        uiSleep 60;
        _date set [4, (_date select 4) + 1]; //add 1 min to be 100% correct
        setDate _date;
    };
};
