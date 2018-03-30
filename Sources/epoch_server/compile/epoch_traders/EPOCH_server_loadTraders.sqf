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
private [	"_TraderGodMode","_StaticTraderItemPurge","_DynamicTraderRespawnCount","_TraderItemsDeleteRestart","_TraderInit","_TraderItemsClean","_newstock","_agent","_aiTables",
			"_arr","_config","_currentStock","_existingStock","_indexStock","_markers","_objHiveKey","_pos","_randomAIUniform","_response","_response2","_schedule",
			"_serverSettingsConfig","_staticTrader","_staticTradersArrCount","_staticTradersArray","_storedVehicleLimit","_traderSlotIndex","_work","_arrchanged","_deleteat","_maxrnd"
		];
//[[[end]]]
params [["_maxTraderLimit",0]];

_staticTradersArray = +EPOCH_staticNPCTraderPos;
EPOCH_staticNPCTraderPos = nil;
_config = (configFile >> "CfgEpoch" >> worldName);
_staticTradersArray append getArray(_config >> "staticNpcPos");
_staticTradersArrCount = count _staticTradersArray;
_aiTables = getArray(_config >> "traderUniforms");
_serverSettingsConfig = configFile >> "CfgEpochServer";
_TraderGodMode = [_serverSettingsConfig, "TraderGodMode", false] call EPOCH_fnc_returnConfigEntry;
_storedVehicleLimit = [_serverSettingsConfig, "storedVehicleLimit", 20] call EPOCH_fnc_returnConfigEntry;
_StaticTraderItemPurge = [_serverSettingsConfig, "StaticTraderItemPurge", []] call EPOCH_fnc_returnConfigEntry;
_DynamicTraderRespawnCount = [_serverSettingsConfig, "DynamicTraderRespawnCount", 150] call EPOCH_fnc_returnConfigEntry;
_TraderItemCountPerItem = [_serverSettingsConfig, "TraderItemCountPerItem", [100,100]] call EPOCH_fnc_returnConfigEntry;
_TraderItemsDeleteRestart = [_serverSettingsConfig, "TraderItemsDeleteRestart", []] call EPOCH_fnc_returnConfigEntry;

_TraderInit = {
	addToRemainsCollector[_this];
	_this allowdamage !_TraderGodMode;
	_this addUniform _randomAIUniform;
	_this setDir _dir;
	_this setVariable ["AI_SLOT", _i, true];
	_this setVariable ["AI_ITEMS", _arr, true];
	_this disableAI "FSM";
	_this setBehaviour "CARELESS";
	_this setCombatMode "RED";
	_this setSkill 0;
	_this addEventHandler ["Killed", { _this call EPOCH_server_traderKilled; }];
};
_TraderItemsClean = {
	private ["_idx","_delete","_k"];
	_idx = 0;
	for "_k" from 1 to (count (_arr select 0)) do {
		_delete = false;
		_item = _arr select 0 select _idx;
		_currentStock = (_arr select 1) param[_idx, 0];
		_maxrnd = 1;
		if ([_item,"cfgMagazines"] call Epoch_fnc_isAny) then {
			_maxrnd = getnumber (configfile >> "cfgMagazines" >> _item >> "count");
		};
		_currentStock = _currentStock / _maxrnd;
		if (_currentStock >= (_TraderItemCountPerItem select 0)) then {
			_currentStock = _TraderItemCountPerItem select 1;
			(_arr select 1) set [_idx,_currentStock];
			_arrchanged = true;
		};
		if (_currentStock == 0) then {
			_arrchanged = true;
			_delete = true;
		} 
		else {
			if (_item in _TraderItemsDeleteRestart) then {
//				diag_log format ["EPOCH_DEBUG: TraderSlot: %1 | Removed %2 from Trader (Items to remove on Restart)",_i,str _item];
				_arrchanged = true;
				_delete = true;
			}
			else {
				if (_item isKindOf "Air" || _item isKindOf "Ship" || _item isKindOf "LandVehicle" || _item isKindOf "Tank") then {
					_newstock = 0;
					for "_k" from 1 to _currentStock do {
						if (EPOCH_storedVehicleCount < _storedVehicleLimit) then {
							_newstock = _newstock + 1;
							EPOCH_storedVehicleCount = EPOCH_storedVehicleCount + 1;
							if !(_item in EPOCH_traderStoredVehicles) then {
								EPOCH_traderStoredVehicles pushBack _item;
								EPOCH_traderStoredVehiclesCnt pushBack 1;
							} 
							else {
								_indexStock = EPOCH_traderStoredVehicles find _item;
								if (_indexStock != -1) then {
									_existingStock = EPOCH_traderStoredVehiclesCnt select _indexStock;
									EPOCH_traderStoredVehiclesCnt set [_indexStock, (_existingStock + 1)];
								};
							};
						};
					};
					if !(_newstock == _currentStock) then {
						_arrchanged = true;
						if (_newstock > 0) then {
//							diag_log format ["EPOCH_DEBUG: TraderSlot: %1 | Changed stock of %2 from Trader | _currentStock: %3 | _newstock: %4 | EPOCH_storedVehicleCount: %5 | _storedVehicleLimit: %6",_i,str _item,_currentStock,_newstock,EPOCH_storedVehicleCount,_storedVehicleLimit];
							(_arr select 1) set [_idx,_newstock];
						}
						else {
//							diag_log format ["EPOCH_DEBUG: TraderSlot: %1 | Removed %2 from Trader | EPOCH_storedVehicleCount: %3 | _storedVehicleLimit: %4",_i,str _item,EPOCH_storedVehicleCount,_storedVehicleLimit];
							_delete = true;
						};
					};
				};
			};
		};
		if (_delete) then {
			(_arr select 0) deleteat _idx;
			(_arr select 1) deleteat _idx;
		}
		else {
			_idx = _idx + 1;
		};
	};
};

EPOCH_storedVehicleCount = 0;

for "_i" from 0 to (_maxTraderLimit-1) do {
	_traderSlotIndex = EPOCH_TraderSlots pushBack _i;
	_randomAIUniform = selectRandom _aiTables;
	_arr = [[], []];
	_arrchanged = false;
	_objHiveKey = format ["%1:%2", (call EPOCH_fn_InstanceID), _i];
	_response = ["AI_ITEMS", _objHiveKey] call EPOCH_fnc_server_hiveGETRANGE;
	if ((_response select 0) == 1 && (_response select 1) isEqualType []) then {
		_arr = (_response select 1);
		if (_arr isEqualTo []) then {
			_arr = [[], []];
		};
	};
	if (_arr isEqualTo [[], []]) then{
		_arr = EPOCH_starterTraderItems;
		_arrchanged = true;
	};
	call _TraderItemsClean;

	// Spawn static traders first
	if (_staticTradersArrCount > 0 && _i < _staticTradersArrCount) then {
		_staticTrader = _staticTradersArray select _i;
		_staticTrader params ["_class","_pos","_dir"];
		if (count (_arr select 0) > (_StaticTraderItemPurge select 0)) then {
//			diag_log format ["EPOCH_DEBUG: TraderSlot: %1 | Cleaning %2 Items from Trader | before: %3",_i,((count (_arr select 0))*(_StaticTraderItemPurge select 1)/100), count (_arr select 0)];
			_arrchanged = true;
			for "_j" from 1 to ((count (_arr select 0))*(_StaticTraderItemPurge select 1)/100) do {
				_deleteat = (round random (count (_arr select 0)-1));
				(_arr select 0) deleteAt _deleteat;
				(_arr select 1) deleteAt _deleteat;
			};
		};
		EPOCH_TraderSlots deleteAt _traderSlotIndex;
		_agent = createAgent [_class, _pos, [], 0, "CAN_COLLIDE"];
		_agent call _TraderInit;
		_agent setPosATL _pos;
		if (_arrchanged) then {
//			diag_log format ["EPOCH_DEBUG: TraderSlot: %1 | Saved",_i];
			["AI_ITEMS", _objHiveKey, EPOCH_expiresAIdata, _arr] call EPOCH_fnc_server_hiveSETEX;
		};
		if (EPOCH_SHOW_TRADERS) then {
			_markers = ["StaticTrader",_pos] call EPOCH_server_createGlobalMarkerSet;
			_agent setVariable["MARKER_REF", _markers];
		};
	} 
	else {
		// Spawn dynamic traders
		_response2 = ["AI", _objHiveKey] call EPOCH_fnc_server_hiveGETRANGE;
		if ((_response2 select 0) == 1 && (_response2 select 1) isEqualType [] && !((_response2 select 1) isEqualTo [])) then {
			(_response2 select 1) params ["_class","_home","_work"];
			if (_home isEqualType [] && _work isEqualType []) then {
				// check schedule
				_pos = _home;
				_schedule = [9, 17];
				if ((_work select 1) isEqualType []) then {
					_schedule = _work select 1;
				}
				else {
//					diag_log format ["DEBUG INVAILD SCHEDULE: SLOT: %1 CLASS: %2 POS: %3 WORK: %4", _i, _class, _pos, _work];
				};
				if (daytime > (_schedule select 0) && daytime < (_schedule select 1)) then {
					_pos = (_work select 0);
				};
				if !(count (_arr select 0) >= _DynamicTraderRespawnCount) then {
					EPOCH_TraderSlots deleteAt _traderSlotIndex;
					_agent = createAgent [_class, _pos, [], 0, "NONE"];
					_dir = random 360;
					_agent call _TraderInit;
					if (_arrchanged) then {
//						diag_log format ["EPOCH_DEBUG: TraderSlot: %1 | Saved",_i];
						["AI_ITEMS", _objHiveKey, EPOCH_expiresAIdata, _arr] call EPOCH_fnc_server_hiveSETEX;
					};
					if !(EPOCH_forceStaticTraders) then {
						[_agent, _home, _work] execFSM "\epoch_server\system\Trader_brain.fsm";
					};
					if (EPOCH_SHOW_TRADERS) then {
						_markers = ["DynamicTrader",_pos] call EPOCH_server_createGlobalMarkerSet;
						_agent setVariable["MARKER_REF", _markers];
					};
				}
				else {
//					diag_log format ["EPOCH_DEBUG: TraderSlot: %1 | Supressed Trader Load - Too much items (%2) and will respawn",_i,count (_arr select 0)];
					["AI", _objHiveKey] call EPOCH_fnc_server_hiveDEL;
					["AI_ITEMS", _objHiveKey] call EPOCH_fnc_server_hiveDEL;
				};
			};
		};
	};
};
true
