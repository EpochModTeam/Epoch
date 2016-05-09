/*
	Author: Aaron Clark - EpochMod.com

    Contributors:

	Description:
    Splits a position into two arrays: Whole number array and decimal array.

    Licence:
    Arma Public License Share Alike (APL-SA) - https://www.bistudio.com/community/licenses/arma-public-license-share-alike

    Github:
    https://github.com/EpochModTeam/Epoch/tree/master/Sources/epoch_server/compile/epoch_traders/EPOCH_server_spawnTraders.sqf
*/
private ["_home","_work","_pos","_marker","_buildingPositions","_startTime","_endTime","_schedule","_agent","_slot","_objHiveKey","_buildingWork","_homeBuildingPositions","_acceptableBlds","_buildings","_randomAIUniform","_randomAIClass","_building","_position","_aiTables","_spawnCount","_usedBuildings"];

// TODO: configize
_aiTables = ["U_OG_leader", "U_C_Poloshirt_stripped", "U_C_Poloshirt_blue", "U_C_Poloshirt_burgundy", "U_C_Poloshirt_tricolour", "U_C_Poloshirt_salmon", "U_C_Poloshirt_redwhite", "U_C_Poor_1", "U_C_WorkerCoveralls", "U_C_Journalist", "U_C_Scientist", "U_OrestesBody"];

_spawnCount = count EPOCH_TraderSlots;

//diag_log format["DEBUG: Tradercount EPOCH_TraderSlots: %1", _spawnCount];

_usedBuildings = [];
for "_i" from 1 to _spawnCount do {

	_position = [epoch_centerMarkerPosition, 0, EPOCH_dynamicVehicleArea, 20, 0, 4000, 0] call BIS_fnc_findSafePos;
	// only proceed if two params otherwise BIS_fnc_findSafePos failed and may spawn in air
	if (count _position == 2) then {
		_randomAIUniform = selectRandom _aiTables;
		_randomAIClass = "C_man_1"; // static for now

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

					if (_pos nearEntities[_randomAIClass, 50] isEqualTo []) then {

						_agent = createAgent[_randomAIClass, _pos, [], 0, "CAN_COLLIDE"];
						addToRemainsCollector[_agent];
						_agent addUniform _randomAIUniform;
						_slot = EPOCH_TraderSlots deleteAt 0;
						_agent setVariable["AI_SLOT", _slot, true];
						_agent setVariable["AI_ITEMS", EPOCH_starterTraderItems, true];
						_objHiveKey = format["%1:%2", (call EPOCH_fn_InstanceID), _slot];

						["AI_ITEMS", _objHiveKey, EPOCH_expiresAIdata, EPOCH_starterTraderItems] call EPOCH_fnc_server_hiveSETEX;
						_agent addEventHandler["Killed", { _this call EPOCH_server_traderKilled; }];

						if !(EPOCH_forceStaticTraders) then {
							[_agent, _home, [_work, _schedule]] execFSM "\epoch_server\system\Trader_brain.fsm";
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
};
true
