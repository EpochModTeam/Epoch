private [
	"_aiTables","_counter"
	,"_slot","_position"
	,"_randomIndex","_randomAIUniform","_randomAIClass","_usedBuildings","_building"
	,"_home","_pos","_homeBuildingPositions","_homeBuildingPosition","_acceptableBlds","_buildings"
	,"_buildingWork","_work","_buildingPositions","_buildingPosition","_startTime","_endTime","_schedule","_pos","_agent","_objHiveKey"
	,"_marker"
];

// TODO: configize
_aiTables = ["U_OG_leader", "U_C_Poloshirt_stripped", "U_C_Poloshirt_blue", "U_C_Poloshirt_burgundy", "U_C_Poloshirt_tricolour", "U_C_Poloshirt_salmon", "U_C_Poloshirt_redwhite", "U_C_Poor_1", "U_C_WorkerCoveralls", "U_C_Journalist", "U_C_Scientist", "U_OrestesBody"];

_spawnCount = count EPOCH_TraderSlots;

diag_log format["DEBUG: count EPOCH_TraderSlots: %1", _spawnCount];

_usedBuildings = [];

for "_i" from 1 to _spawnCount do {

	_position = [epoch_centerMarkerPosition, 0, EPOCH_dynamicVehicleArea, 20, 0, 4000, 0] call BIS_fnc_findSafePos;
	// only proceed if two params otherwise BIS_fnc_findSafePos failed and may spawn in air
	if (count _position == 2) then {

		_randomAIUniform = selectRandom _aiTables;
		_randomAIClass = "C_man_1";

		// find home
		_building = nearestBuilding _position;
		if !(_building in _usedBuildings) then {

			_home = getPosATL _building;
			_pos = _home;

			_usedBuildings pushBack _building;

			_homeBuildingPositions = _building buildingPos -1;
			if !(_homeBuildingPositions isEqualTo []) then {
				_home = selectRandom _homeBuildingPositions;
			};

			_acceptableBlds = getArray(configFile >> "CfgEpoch" >> worldName >> "traderBlds");
			_buildings = nearestObjects[_home, _acceptableBlds, 500];

			if !(_buildings isEqualTo []) then {
				_buildingWork = selectRandom _buildings;

				if !(_buildingWork in _usedBuildings) then {

					_usedBuildings pushBack _buildingWork;
					_work = getPosATL _buildingWork;

					_buildingPositions = _buildingWork buildingPos -1;
					if !(_buildingPositions isEqualTo []) then {
						_work = selectRandom _buildingPositions;
					};

					_startTime = floor(random 16);
					_endTime = _startTime + 8;
					_schedule = [_startTime, _endTime];

					if (daytime > (_schedule select 0) && daytime < (_schedule select 1)) then {
						_pos = _work;
					};

					_agent = createAgent[_randomAIClass, _pos, [], 0, "CAN_COLLIDE"];

					addToRemainsCollector[_agent];

					_agent addUniform _randomAIUniform;

					_slot = EPOCH_TraderSlots deleteAt 0;

					// Set slot used by vehicle
					_agent setVariable["AI_SLOT", _slot, true];

					// allow input here to provide default items
					_agent setVariable["AI_ITEMS", EPOCH_starterTraderItems, true];

					_objHiveKey = format["%1:%2", (call EPOCH_fn_InstanceID), _slot];

					["AI_ITEMS", _objHiveKey, EPOCH_expiresAIdata, EPOCH_starterTraderItems] call EPOCH_fnc_server_hiveSETEX;

					_agent addEventHandler["Killed", { _this call EPOCH_server_traderKilled; }];

					if !(EPOCH_forceStaticTraders) then {
						[_agent, _home, [_work, _schedule]] execFSM "\x\addons\a3_epoch_server\system\Trader_brain.fsm";
					};

					["AI", _objHiveKey, [_randomAIClass, _home, [_work, _schedule]]] call EPOCH_fnc_server_hiveSET;

					if (EPOCH_SHOW_TRADERS) then {
						_marker = createMarker[str(_agent), (_pos)];
						_marker setMarkerShape "ICON";
						_marker setMarkerType "mil_dot";
						_marker setMarkerColor "ColorKhaki";
						_agent setVariable["MARKER_REF", _marker];
					};
				};
			};
		};
	};
};
true
