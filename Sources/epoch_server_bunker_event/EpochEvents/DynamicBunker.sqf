/*
	Author/s:
		Aaron Clark - EpochMod.com

	Description:
		Spawns Bunker Dynamically.

	Improvements and or bugfixes and other contributions are welcome via the github:
	https://github.com/EpochModTeam/Epoch/tree/release/Sources/epoch_server_bunker_event/EpochEvents/BunkerSpawner.sqf
*/
//[[[cog import generate_private_arrays ]]]
private ["_allBunkers","_animationStates","_bunkerClasses","_bunkerCounter","_bunkerLocationsKey","_bunkerLocationsTMP","_colCount","_debug","_debugLocation","_expiresBunker","_firstBunker","_instanceID","_list","_loc1","_location","_maxBunkerLimitPerRow","_maxBunkerLimitSlots","_maxColumns","_memoryPoints","_modelInfo","_newBunkerCounter","_object","_originalLocation","_pOffset","_response","_rng","_rngChance","_rowCount","_score","_scriptHiveKey","_seed","_selectedBunker","_size","_veh"];
//[[[end]]]
if (worldName == "VR") then {

	_debug = false;
	_expiresBunker = 14400; // four hours

	_memoryPoints = ["one","two","three","four"];

	_bunkerCounter = 0;
	_newBunkerCounter = 0;

	_instanceID = call EPOCH_fn_InstanceID;

	_maxBunkerLimitSlots = 100;
	_maxBunkerLimitPerRow = 10;

	_rngChance = 0.3; // Lower this to spawn more positions
	_scriptHiveKey = "EPOCH:DynamicBunker"; // change this to force a new seed to be generated.

	_bunkerLocationsKey = format ["%1:%2", _instanceID, worldname];
	_response = [_scriptHiveKey, _bunkerLocationsKey] call EPOCH_fnc_server_hiveGETRANGE;
	_response params [["_status",0],["_data",[]] ];

	_firstBunker = objNull;

	// check for proper return and data type
	if (_status == 1 && _data isEqualType [] && !(_data isEqualTo [])) then {

		// spawn cached bunker
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
		} forEach _data;

	} else {

		// generate new bunker
		_size = 13.081;
		_maxColumns = _maxBunkerLimitSlots / _maxBunkerLimitPerRow;
		_allBunkers = [];
		_bunkerLocationsTMP = [];
		_newBunkerCounter = 0;

		// Generate Seed
		_seed = random 999999;
		diag_log format["Generating bunker with seed: %1",_seed];

		// starting location corner of map
		_debugLocation = getMarkerPos "respawn_west";
		_location = ATLToASL _debugLocation;
		_originalLocation = +_location;

		_bunkerClasses = [
			"bunker_epoch"
		];

		_rowCount = 0;
		_colCount = 0;

		//spawn x number of connected bunkers.
		while {true} do {
			if (_colCount > _maxColumns) exitWith {};
			_rng = _seed random [_location select 0,_location select 1];
			if (_rng > _rngChance) then {
				_selectedBunker = selectRandom _bunkerClasses;
				_object = createSimpleObject [_selectedBunker, _location];
				if (isNull _firstBunker) then {_firstBunker = _object;};
				_allBunkers pushBack _object;
				//_bunkerLocationsTMP pushBack [_selectedBunker,getPosWorld _object, vectorDir _object, vectorUp _object];
				_newBunkerCounter = _newBunkerCounter + 1;
			};
			_location set [0,(_location select 0) + _size];
			_rowCount = _rowCount + 1;
			if (_rowCount >= _maxBunkerLimitPerRow) then {
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
					_list = nearestObjects[_loc1, [], 1];
					if !(_list isEqualTo []) then {
						_veh animate [_x,0,true];
						_score = _score + 1;
						_animationStates pushBack 0
					} else {
						_veh animate [_x,1,true];
						_animationStates pushBack 1
					};
				};
			} forEach _memoryPoints;
			_modelInfo = getModelInfo _veh;
			_bunkerLocationsTMP pushBack [_modelInfo select 1, getPosWorld _veh, _animationStates, _score];
		} forEach _allBunkers;

		// save to DB
	    [_scriptHiveKey, _bunkerLocationsKey, _expiresBunker, _bunkerLocationsTMP] call EPOCH_fnc_server_hiveSETEX;
	};

	// move respawn point into first bunker.
	if (!(isNull _firstBunker) && {_firstBunker distance _debugLocation > 2}) then {
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
