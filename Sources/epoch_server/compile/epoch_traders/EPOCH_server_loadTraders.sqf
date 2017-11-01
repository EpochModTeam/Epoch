/*
	Author: Aaron Clark - EpochMod.com

    Contributors:

	Description:
    Splits a position into two arrays: Whole number array and decimal array.

    Licence:
    Arma Public License Share Alike (APL-SA) - https://www.bistudio.com/community/licenses/arma-public-license-share-alike

    Github:
    https://github.com/EpochModTeam/Epoch/tree/release/Sources/epoch_server/compile/epoch_traders/EPOCH_server_loadTraders.sqf
*/
//[[[cog import generate_private_arrays ]]]
private ["_agent","_aiTables","_arr","_class","_config","_currentStock","_existingStock","_home","_indexStock","_limit","_markers","_objHiveKey","_pos","_randomAIUniform","_response","_schedule","_serverSettingsConfig","_staticTrader","_staticTradersArrCount","_staticTradersArray","_storedVehicleLimit","_toBeRemoved","_traderSlotIndex","_work"];
//[[[end]]]
params [["_maxTraderLimit",0]];

_staticTradersArray = +EPOCH_staticNPCTraderPos;
EPOCH_staticNPCTraderPos = nil;
_config = (configFile >> "CfgEpoch" >> worldName);
_staticTradersArray append getArray(_config >> "staticNpcPos");
_staticTradersArrCount = count _staticTradersArray;
_aiTables = getArray(_config >> "traderUniforms");

_serverSettingsConfig = configFile >> "CfgEpochServer";
_storedVehicleLimit = [_serverSettingsConfig, "storedVehicleLimit", 20] call EPOCH_fnc_returnConfigEntry;

EPOCH_storedVehicleCount = 0;

for "_i" from 0 to (_maxTraderLimit-1) do {
	_traderSlotIndex = EPOCH_TraderSlots pushBack _i;

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

						// Count how many of this vehicle are in stock at any trader.
						if !(_x in EPOCH_traderStoredVehicles) then {
							EPOCH_traderStoredVehicles pushBack _x;
							EPOCH_traderStoredVehiclesCnt pushBack _currentStock;
						} else {
							_indexStock = EPOCH_traderStoredVehicles find _x;
							if (_indexStock != -1) then {
								_existingStock = EPOCH_traderStoredVehiclesCnt select _indexStock;
								EPOCH_traderStoredVehiclesCnt set [_indexStock, (_existingStock + _currentStock)];
							};
						};
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
			_markers = ["StaticTrader",_pos] call EPOCH_server_createGlobalMarkerSet;
			_agent setVariable["MARKER_REF", _markers];
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
					[_agent, _home, _work] execFSM "\epoch_server\system\Trader_brain.fsm";
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

								// Count how many of this vehicle are in stock at any trader.
								if !(_x in EPOCH_traderStoredVehicles) then {
									EPOCH_traderStoredVehicles pushBack _x;
									EPOCH_traderStoredVehiclesCnt pushBack _currentStock;
								} else {
									_indexStock = EPOCH_traderStoredVehicles find _x;
									if (_indexStock != -1) then {
										_existingStock = EPOCH_traderStoredVehiclesCnt select _indexStock;
										EPOCH_traderStoredVehiclesCnt set [_indexStock, (_existingStock + _currentStock)];
									};
								};
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
					_markers = ["DynamicTrader",_pos] call EPOCH_server_createGlobalMarkerSet;
					_agent setVariable["MARKER_REF", _markers];
				};
			};
		};
	};
};
true
