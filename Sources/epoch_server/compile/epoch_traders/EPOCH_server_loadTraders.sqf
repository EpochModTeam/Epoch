/*
	Author: Aaron Clark - EpochMod.com

    Contributors:

	Description:
    Splits a position into two arrays: Whole number array and decimal array.

    Licence:
    Arma Public License Share Alike (APL-SA) - https://www.bistudio.com/community/licenses/arma-public-license-share-alike

    Github:
    https://github.com/EpochModTeam/Epoch/tree/master/Sources/epoch_server/compile/epoch_traders/EPOCH_server_loadTraders.sqf
*/
private ["_arr","_currentStock","_limit","_toBeRemoved","_marker","_staticTrader","_agent","_class","_pos","_randomAIUniform","_dir","_objHiveKey","_response","_schedule","_home","_work","_traderSlotIndex","_staticTradersArray","_staticTradersArrCount","_aiTables","_serverSettingsConfig","_storedVehicleLimit"];
params [["_maxTraderLimit",0]];

_staticTradersArray = [] + EPOCH_staticNPCTraderPos;
EPOCH_staticNPCTraderPos = nil;
_staticTradersArray append getArray(configFile >> "CfgEpoch" >> worldName >> "staticNpcPos");
_staticTradersArrCount = count _staticTradersArray;
// TODO: configize
_aiTables = ["U_OG_leader", "U_C_Poloshirt_stripped", "U_C_Poloshirt_blue", "U_C_Poloshirt_burgundy", "U_C_Poloshirt_tricolour", "U_C_Poloshirt_salmon", "U_C_Poloshirt_redwhite", "U_C_Poor_1", "U_C_WorkerCoveralls", "U_C_Journalist", "U_C_Scientist", "U_OrestesBody"];

_serverSettingsConfig = configFile >> "CfgEpochServer";
_storedVehicleLimit = [_serverSettingsConfig, "storedVehicleLimit", 20] call EPOCH_fnc_returnConfigEntry;

EPOCH_storedVehicleCount = 0;

for "_i" from 0 to _maxTraderLimit do {
	_traderSlotIndex = EPOCH_TraderSlots pushBack str(_i);

	// Spawn static traders first
	if (_staticTradersArrCount > 0 && _i < _staticTradersArrCount) then {

		_staticTrader = _staticTradersArray select _i;
		_staticTrader params ["_class","_pos","_dir"];
		_agent = createAgent [_class, _pos, [], 0, "CAN_COLLIDE"];
		_randomAIUniform = selectRandom _aiTables;
		_agent addUniform _randomAIUniform;
		_agent setDir _dir;
		_agent setPosATL _pos;
		_agent setVariable ["AI_SLOT", _i, true];
		_agent disableAI "FSM";
		_agent setBehaviour "CARELESS";
		_agent setCombatMode "RED";
		_agent setSkill 0;
		_agent addEventHandler ["Killed", { _this call EPOCH_server_traderKilled; }];
		_arr = [[], []];
		_objHiveKey = format ["%1:%2", (call EPOCH_fn_InstanceID), _i];
		_response = ["AI_ITEMS", _objHiveKey] call EPOCH_fnc_server_hiveGETRANGE;
		if ((_response select 0) == 1 && (_response select 1) isEqualType []) then {
			_arr = (_response select 1);
			if (_arr isEqualTo []) then {
				_arr = [[], []];
			};
			_toBeRemoved = [];
			// count vehicles
			{
				_limit = ["CfgTraderLimits", _x, 100] call EPOCH_fnc_returnConfigEntryV2;
				_currentStock = (_arr select 1) param[_forEachIndex, 0];
				if (_limit == 0) then {
					// mark for removal since limit is 0
					_toBeRemoved pushBack _forEachIndex;
					_currentStock = 0;
				} else {
					// lower to limit current qty is over limit
					if (_currentStock > _limit) then {
						(_arr select 1) set [_forEachIndex,_limit];
						_currentStock = _limit;
					};
				};
				if (_x isKindOf "Air" || _x isKindOf "Ship" || _x isKindOf "LandVehicle" || _x isKindOf "Tank") then {
					if (EPOCH_storedVehicleCount <= _storedVehicleLimit) then {
						EPOCH_storedVehicleCount = EPOCH_storedVehicleCount + _currentStock;
					} else {
						_toBeRemoved pushBack _forEachIndex;
					};

				};
			} forEach (_arr select 0);
			// remove any marked for removal
			{
					(_arr select 0) deleteAt _x;
					(_arr select 1) deleteAt _x
			} forEach _toBeRemoved;
		};

		if (_arr isEqualTo [[], []]) then{
			_arr = EPOCH_starterTraderItems;
			["AI_ITEMS", _objHiveKey, EPOCH_expiresAIdata, _arr] call EPOCH_fnc_server_hiveSETEX;
		};

		_agent setVariable ["AI_ITEMS", _arr, true];

		EPOCH_TraderSlots deleteAt _traderSlotIndex;

		if (EPOCH_SHOW_TRADERS) then {
			_marker = createMarker [str(_agent), (_pos)];
			_marker setMarkerShape "ICON";
			_marker setMarkerType "mil_dot";
			_marker setMarkerColor "ColorBlack";

			_agent setVariable["MARKER_REF", _marker];
		};
	} else {
		// Spawn dynamic traders
		_objHiveKey = format ["%1:%2", (call EPOCH_fn_InstanceID), _i];
		_response = ["AI", _objHiveKey] call EPOCH_fnc_server_hiveGETRANGE;
		if ((_response select 0) == 1 && (_response select 1) isEqualType [] && !((_response select 1) isEqualTo [])) then {
			_arr = (_response select 1);

			_class = _arr select 0; //"C_man_1"
			_home = _arr select 1;
			_work = _arr select 2;

			if (_home isEqualType [] && _work isEqualType []) then {
				// check schedule
				_pos = _home;

				_schedule = [9, 17];
				if ((_work select 1) isEqualType []) then {
					_schedule = _work select 1;
				}
				else {
					diag_log format ["DEBUG INVAILD SCHEDULE: SLOT: %1 CLASS: %2 POS: %3 WORK: %4", _i, _class, _pos, _work];
				};

				if (daytime > (_schedule select 0) && daytime < (_schedule select 1)) then {
					_pos = (_work select 0);
				};
				_agent = createAgent [_class, _pos, [], 0, "NONE"];

				addToRemainsCollector[_agent];

				_randomAIUniform = selectRandom _aiTables;
				_agent addUniform _randomAIUniform;

				// _agent enableSimulationGlobal false;
				_agent setPos _pos;

				_agent addEventHandler ["Killed", { _this call EPOCH_server_traderKilled; }];

				if !(EPOCH_forceStaticTraders) then {
					[_agent, _home, _work] execFSM "\x\addons\a3_epoch_server\system\Trader_brain.fsm";
				};

				_agent setVariable ["AI_SLOT", _i, true];

				_arr = [[],[]];
				_objHiveKey = format ["%1:%2", (call EPOCH_fn_InstanceID), _i];
				_response = ["AI_ITEMS", _objHiveKey] call EPOCH_fnc_server_hiveGETRANGE;

				if ((_response select 0) == 1 && (_response select 1) isEqualType []) then {
					_arr = (_response select 1);

					if (_arr isEqualTo []) then {
						_arr = [[], []];
					};

					_toBeRemoved = [];
					// count vehicles
					{
						_limit = ["CfgTraderLimits", _x, 100] call EPOCH_fnc_returnConfigEntryV2;
						_currentStock = (_arr select 1) param[_forEachIndex, 0];
						if (_limit == 0) then {
							// mark for removal since limit is 0
							_toBeRemoved pushBack _forEachIndex;
							_currentStock = 0;
						} else {
							// lower to limit current qty is over limit
							if (_currentStock > _limit) then {
								(_arr select 1) set [_forEachIndex,_limit];
								_currentStock = _limit;
							};
						};
						if (_x isKindOf "Air" || _x isKindOf "Ship" || _x isKindOf "LandVehicle" || _x isKindOf "Tank") then {
							if (EPOCH_storedVehicleCount <= _storedVehicleLimit) then {
								EPOCH_storedVehicleCount = EPOCH_storedVehicleCount + _currentStock;
							} else {
								_toBeRemoved pushBack _forEachIndex;
							};

						};
					} forEach (_arr select 0);

					// remove any marked for removal
					{
							(_arr select 0) deleteAt _x;
							(_arr select 1) deleteAt _x
					} forEach _toBeRemoved;

					if (_arr isEqualTo [[], []]) then{
						_arr = EPOCH_starterTraderItems;
						["AI_ITEMS", _objHiveKey, EPOCH_expiresAIdata, _arr] call EPOCH_fnc_server_hiveSETEX;
					};

				};
				_agent setVariable ["AI_ITEMS", _arr, true];

				EPOCH_TraderSlots deleteAt _traderSlotIndex;

				if (EPOCH_SHOW_TRADERS) then {
					_marker = createMarker [str(_agent), (_pos)];
					_marker setMarkerShape "ICON";
					_marker setMarkerType "mil_dot";
					_marker setMarkerColor "ColorBrown";
					_agent setVariable["MARKER_REF", _marker];
				};
			};
		};
	};
};
true
