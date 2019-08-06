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
private ["_ReservedSlots","_SideHQ1","_SideHQ2","_SideHQ3","_abortAndError","_allBunkers","_allowedVehicleIndex","_allowedVehicleListName","_allowedVehiclesList","_allowedVehiclesListArray","_animationStates","_blacklist","_bunkerCounter","_bunkerLocations","_bunkerLocationsKey","_cfgServerVersion","_channelColor","_channelNumber","_channelTXT","_clientVersion","_colCount","_config","_configSize","_configVersion","_customRadioactiveLocations","_date","_dateChanged","_debug","_debugLocation","_distance","_epochConfig","_epochWorldPath","_existingStock","_firstBunker","_hiveVersion","_index","_indexStock","_instanceID","_list","_loc1","_locName","_locPOS","_locSize","_location","_locations","_markers","_markertxt","_maxColumns","_maxRows","_memoryPoints","_modelInfo","_nearBLObj","_newBunkerCounter","_object","_originalLocation","_pOffset","_pos","_radio","_radioactiveLocations","_radioactiveLocationsTmp","_radius","_response","_rng","_rngChance","_rowCount","_sapper","_score","_scriptHiveKey","_seed","_selectedBunker","_serverConfig","_serverSettingsConfig","_servicepoints","_size","_startTime","_staticDateTime","_staticFuelSources","_timeDifference","_valuesAndWeights","_veh","_vehicleCount","_vehicleSlotLimit","_worldSize"];
//[[[end]]]
_startTime = diag_tickTime;
missionNamespace setVariable ['Epoch_ServerVersion', getText(configFile >> "CfgMods" >> "Epoch" >> "version"), true];
diag_log format["Epoch: Starting ArmA3 Epoch Server, Version %1. Note: If server crashes directly after this point check that Redis is running and the connection info is correct.",Epoch_ServerVersion];

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

// detect if Ryan's Zombies and Deamons mod is present
if (["CfgEpochClient", "ryanZombiesEnabled", true] call EPOCH_fnc_returnConfigEntryV2) then {
    EPOCH_mod_Ryanzombies_Enabled = (parseNumber (getText (configFile >> "CfgPatches" >> "Ryanzombies" >> "version")) >= 4.5);
    if (EPOCH_mod_Ryanzombies_Enabled) then {
        diag_log "Epoch: Ryanzombies detected";
		missionNamespace setVariable ["EPOCH_mod_Ryanzombies_Enabled", true, true];
    };
} else {
    EPOCH_mod_Ryanzombies_Enabled = false;
};

// detect if Mad Arma is present
if (["CfgEpochClient", "madArmaEnabled", true] call EPOCH_fnc_returnConfigEntryV2) then {
    EPOCH_mod_madArma_Enabled = (parseNumber (getText (configFile >> "CfgPatches" >> "bv_wheels" >> "version")) >= 2016);
    if (EPOCH_mod_madArma_Enabled) then {
        diag_log "Epoch: Mad Arma detected";
		missionNamespace setVariable ["EPOCH_mod_madArma_Enabled", true, true];
    };
} else {
    EPOCH_mod_madArma_Enabled = false;
};

diag_log "Epoch: Init Variables";
call compile preprocessFileLineNumbers "\epoch_server\init\server_variables.sqf";
call compile preprocessFileLineNumbers "\epoch_server\init\server_securityfunctions.sqf";

// Set Server RealTime
Epoch_ServerRealtime = date;
_response = "epochserver" callExtension "510";
if (_response != "") then {
	diag_log format ["Epoch: Set Real Time: %1", _response];
	_date = parseSimpleArray _response;
	_date resize 5;
	Epoch_ServerRealtime = _date;
};

// Enable Dynamic simulation
_dynSimToggle = [_serverSettingsConfig, "enableDynamicSimulationSystem", true] call EPOCH_fnc_returnConfigEntry;
enableDynamicSimulationSystem _dynSimToggle;
if(_dynSimToggle)then
{
	"IsMoving" setDynamicSimulationDistanceCoef ([_serverSettingsConfig, "isMovingCoefValue", 2] call EPOCH_fnc_returnConfigEntry);
	"Group" setDynamicSimulationDistance ([_serverSettingsConfig, "groupDynSimDistance", 500] call EPOCH_fnc_returnConfigEntry);
	"Vehicle" setDynamicSimulationDistance ([_serverSettingsConfig, "vehicleDynSimDistance", 350] call EPOCH_fnc_returnConfigEntry);
	"EmptyVehicle" setDynamicSimulationDistance ([_serverSettingsConfig, "emptyVehicleDynSimDistance", 250] call EPOCH_fnc_returnConfigEntry);
	"Prop" setDynamicSimulationDistance ([_serverSettingsConfig, "propDynSimDistance", 50] call EPOCH_fnc_returnConfigEntry);
};
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
    diag_log "Epoch: Error cannot find center marker! - default used instead";
	epoch_centerMarkerPosition = [worldSize / 2, worldsize / 2, 0];
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

UseCustomTextures = ([_serverSettingsConfig, "UseCustomTextures", false] call EPOCH_fnc_returnConfigEntry);

//Execute Server Functions
diag_log "Epoch: Loading buildings";
EPOCH_BuildingSlotsLimit call EPOCH_server_loadBuildings;

diag_log "Epoch: Loading teleports and static props";
call EPOCH_server_createTeleport;

diag_log "Epoch: Loading NPC traders";
EPOCH_Traders = [];
EPOCH_NPCSlotsLimit call EPOCH_server_loadTraders;

diag_log "Epoch: Spawning NPC traders";
call EPOCH_server_spawnTraders;
publicvariable "EPOCH_Traders";

if (([_serverSettingsConfig, "ReplaceCarService", false] call EPOCH_fnc_returnConfigEntry)) then {
	{
		private _shop = "paintshop" createvehicle (getpos _x);
		_shop setposatl (getposatl _x);
		_shop setVectorDirAndUp [VectorDir _x, VectorUp _x];
		_x HideobjectGlobal true;
	} foreach (epoch_centerMarkerPosition nearObjects ["Land_CarService_F", EPOCH_dynamicVehicleArea]);
};
{
	_markers = ["PaintGarage", (getpos _x),"Paint Garage"] call EPOCH_server_createGlobalMarkerSet;
} foreach (allmissionobjects "paintshop");

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
_ReservedVehSlots = [_serverSettingsConfig, "ReservedVehSlots", 50] call EPOCH_fnc_returnConfigEntry;
_vehicleSlotLimit = _vehicleSlotLimit + _ReservedVehSlots;
if (EPOCH_useOldLoadVehicles) then {
    _vehicleSlotLimit call EPOCH_load_vehicles_old;
} else {
    _vehicleSlotLimit call EPOCH_load_vehicles;
};
diag_log "Epoch: Spawning vehicles";
_allowedVehiclesListArray = [];
{
    _x params ["_vehClass","_velimit"];
     _vehicleCount = {(_x getvariable ["VEHICLE_BaseClass",typeOf _x]) == _vehClass} count vehicles;

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
	_date = Epoch_ServerRealtime;
	_date set[0, (_date select 0) + 21];
	_date set[3, (_date select 3) + _timeDifference];
	_dateChanged = true;
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
	_markertxt = "Service Point";
	if (count _x > 3) then {
		_pos = _x select 0;
		if ((_x select 3) isequaltype "") then {
			_markertxt = _x select 3;
		};
	};
	if !(_markertxt isequalto "") then {
		_markers = ["ServicePoint", _pos,_markertxt] call EPOCH_server_createGlobalMarkerSet;
		if !(surfaceiswater _pos) then {
			"Land_HelipadCircle_F" createvehicle _pos;
		};
	};
} forEach _ServicePoints;

// Remove Auto-Refuel from all maps
if ([_serverSettingsConfig, "disableAutoRefuel", false] call EPOCH_fnc_returnConfigEntry) then {
    // get all fuel source objects on the map (Note: this maybe slow consider refactor with another command)
    _staticFuelSources = ((epoch_centerMarkerPosition nearObjects ['Building',EPOCH_dynamicVehicleArea]) select {getFuelCargo _x > 0});
    // globalize all fuel sources
    missionNamespace setVariable ["EPOCH_staticFuelSources", _staticFuelSources, true];
}
else {
	// Remove Auto-Refuel in PlotPole-Range
	if ([_serverSettingsConfig, "disableFuelNearPlots", true] call EPOCH_fnc_returnConfigEntry) then {
		_staticFuelSources = [];
		{
			{
				_staticFuelSources pushback _x;
			} foreach (((_x nearObjects ['Building',call EPOCH_MaxJammerRange]) select {getFuelCargo _x > 0}));
		
		} foreach (missionnamespace getvariable ["Epoch_Plotpoles",call {_allplots = [];{_allplots append (allmissionobjects _x)} foreach (call EPOCH_JammerClasses);_allplots}]);
		missionNamespace setVariable ["EPOCH_staticFuelSources", _staticFuelSources, true];
	};
};

// set time multiplier
setTimeMultiplier ([_serverSettingsConfig, "timeMultiplier", 1] call EPOCH_fnc_returnConfigEntry);

// globalize tax rate
missionNamespace setVariable ["EPOCH_taxRate", [_serverSettingsConfig, "taxRate", 0.1] call EPOCH_fnc_returnConfigEntry, true];

// pick random radioactive locations
_radioactiveLocations = getArray(_epochConfig >> worldName >> "radioactiveLocations");
_blacklist = (call EPOCH_JammerClasses) + (getArray(_epochConfig >> worldName >> "radioactiveLocBLObjects"));
_distance = getNumber(_epochConfig >> worldName >> "radioactiveLocBLDistance");
_radioactiveLocationsTmp = [];
if !(_radioactiveLocations isEqualTo []) then {
	private _locations = nearestLocations[epoch_centerMarkerPosition, _radioactiveLocations, EPOCH_dynamicVehicleArea];
	if !(_locations isEqualTo []) then {
		{
			_locPOS = locationPosition _x;
			_nearBLObj = nearestObjects [_locPOS, _blacklist, _distance];
			if!(_nearBLObj isEqualTo [])then{_locations = _locations - [_x]};
		}forEach _locations;
		for "_i" from 0 to ((getNumber(_epochConfig >> worldName >> "radioactiveLocationsCount"))-1) do
		{
			if (_locations isEqualTo []) exitWith {};
			private _selectedLoc = selectRandom _locations;
			_locations = _locations - [_selectedLoc];
			_locSize = size _selectedLoc;
			_radius = sqrt((_locSize select 0)^2 + (_locSize select 1)^2);
			_locName = (str(_selectedLoc)) splitString " ";
			_radioactiveLocationsTmp pushBack [_locName,[random 666,_radius]];
			private _position = locationPosition _selectedLoc;
			_markers = ["Radiation", _position] call EPOCH_server_createGlobalMarkerSet;
		};
	};
	_customRadioactiveLocations = getArray(_epochConfig >> worldName >> "customRadioactiveLocations");
	if !(_customRadioactiveLocations isEqualTo []) then {
		{
			_x params [["_position",[0,0,0]],["_radius",0],["_className",""] ];
			if ((!(_position isEqualTo [0,0,0]) && !(_radius isEqualTo 0) && !(_className isEqualTo "")) && ((nearestObjects [_position, _blacklist, _distance]) isEqualTo [])) then{
				_object = (_x select 2) createVehicle _position;
				_object setVariable ["EPOCH_Rads",[random 666,(_x select 1)],true];
				_markers = ["Radiation", _position] call EPOCH_server_createGlobalMarkerSet;
				_object setVariable ["EPOCH_MarkerSet",_markers,true];
			}else{
				diag_log "EPOCHDebug:Check your custom radioactive locations for errors or blacklisted locations";
			};
		}forEach _customRadioactiveLocations;
	};
};
missionNamespace setVariable ["EPOCH_radioactiveLocations", _radioactiveLocationsTmp, true];

// spawn bunkers, just in VR for now.
if (worldName == "VR") then {
	_debug = true;
	_debugLocation = getMarkerPos "respawn_west";
	_memoryPoints = ["one","two","three","four"];
	_bunkerCounter = 0;
	_newBunkerCounter = 0;

	// size
	_maxRows = 30;
	_maxColumns = 30;

	_rngChance = 0; // Lower this to spawn more positions
	_scriptHiveKey = "EPOCH:DynamicBunker"; // do not change

	_bunkerLocationsKey = format ["%1:%2", _instanceID, worldname]; // change instance id to force a new map to be generated.
	_response = [_scriptHiveKey, _bunkerLocationsKey] call EPOCH_fnc_server_hiveGETRANGE;
	_response params [["_status",0],["_data",[]] ];

	_firstBunker = objNull;
	_bunkerLocations = [];

	// check for proper return and data type
	if (_status == 1 && _data isEqualType [] && !(_data isEqualTo [])) then {
		_bunkerLocations = _data;

		// spawn cached bunkers
		{
			if (_x isEqualType [] && !(_x isEqualTo [])) then {
				_x params ["_selectedBunker", "_posWorld", ["_memoryPointsStatus",[]] ];
				_object = createSimpleObject [_selectedBunker, _posWorld];
				if (isNull _firstBunker) then {_firstBunker = _object;};
				{
					_object animate [_x,(_memoryPointsStatus param [_forEachIndex,1]),true];
				} forEach _memoryPoints;
				_bunkerCounter = _bunkerCounter + 1;
			};
		} forEach _bunkerLocations;

	} else {

		// generate new bunker
		_size = 13.08;

		_allBunkers = [];
		_newBunkerCounter = 0;
		// Generate Seed
		_seed = random 999999;
		diag_log format["Generating bunker with seed: %1",_seed];
		_location = _debugLocation;
		_originalLocation = +_location;
		_valuesAndWeights = [
			"bunker_epoch", 0.2, // empty bunker
			"bunker_epoch_01", 0.1, // tall concrete maze 1
			"bunker_epoch_02", 0.05, // Epoch Corp storage
			// "bunker_epoch_03", 0.01, // save for xmas
			"bunker_epoch_04", 0.05, // generator room
			// "bunker_epoch_05", 0.01, // invisible walls
			"bunker_epoch_06", 0.05, // jail
			"bunker_epoch_07", 0.05, // clone chamber
			"bunker_epoch_08", 0.01, // epoch celebration room
			"bunker_epoch_09", 0.05, // tallest concrete walls
			"bunker_epoch_10", 0.05, // knee high concrete walls
			"bunker_epoch_11", 0.1, // sewer
			"bunker_epoch_12", 0.05, // concrete mid wall
			"bunker_epoch_13", 0.05, // tall concrete maze 2
			"bunker_epoch_14", 0.08, // odd concrete walls
			"bunker_epoch_15", 0.05   // concrete mid wall maze
		];
		_rowCount = 0;
		_colCount = 0;
		//spawn x number of connected bunkers.
		while {true} do {
			if (_colCount > _maxColumns) exitWith {};
			_rng = _seed random [_location select 0,_location select 1];
			if (_rng > _rngChance) then {
				_selectedBunker = selectRandomWeighted _valuesAndWeights;
				_object = createVehicle [_selectedBunker, _location, [], 0, "CAN_COLLIDE"];
				if (isNull _firstBunker) then {_firstBunker = _object;};
				_allBunkers pushBack _object;
				_newBunkerCounter = _newBunkerCounter + 1;
			};
			_location set [0,(_location select 0) + _size];
			_rowCount = _rowCount + 1;
			if (_rowCount >= _maxRows) then {
				_rngChance = 0.3;
				_colCount = _colCount + 1;
				_rowCount = 0;
				_location set [0,_originalLocation select 0];
				_location set [1,(_location select 1) + _size];
			};
		};
		_score = 0;
		{
			_veh = _x;
			_animationStates = [];
			{
				_pOffset = _veh selectionPosition _x;
				if !(_pOffset isEqualTo [0,0,0]) then {
					_loc1 = _veh modelToWorldVisual _pOffset;
					_list = _loc1 nearObjects ["bunker_epoch", 1];
					if !(_list isEqualTo []) then {
						_score = _score + 1;
						_animationStates pushBack 0;
						_veh animate [_x,0];
					} else {
						_animationStates pushBack 1;
						_veh animate [_x,1];
					};
				};
			} forEach _memoryPoints;
			_modelInfo = getModelInfo _veh;
			_bunkerLocations pushBack [_modelInfo select 1, getPosWorld _veh, _animationStates, _score];
		} forEach _allBunkers;

		// save to DB
		[_scriptHiveKey, _bunkerLocationsKey, _bunkerLocations] call EPOCH_fnc_server_hiveSET;
	};

	// move respawn point into first bunker.
	if (!(isNull _firstBunker) && {_firstBunker distance _debugLocation > 1}) then {
		deleteMarker "respawn_west";
		createMarker ["respawn_west", getposATL _firstBunker];
	};

	if (_debug) then {
	    diag_log format["DEBUG: Spawned %1 Existing Bunker",_bunkerCounter];
	    if (_newBunkerCounter > 0) then {
	        diag_log format["DEBUG: Spawned %1 New Bunker.",_newBunkerCounter];
	    };
	};
};



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
