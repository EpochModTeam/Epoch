/*
	Author: Aaron Clark - EpochMod.com

    Contributors:

	Description:
    NPC trade mech

    Licence:
    Arma Public License Share Alike (APL-SA) - https://www.bistudio.com/community/licenses/arma-public-license-share-alike

    Github:
    https://github.com/EpochModTeam/Epoch/tree/release/Sources/epoch_server/compile/epoch_trading/EPOCH_server_makeNPCTrade.sqf
*/
private ["_SkipOut","_tradeIn","_tradeOut","_message","_vehicleSold","_vehHiveKey","_VAL","_makeTradeIn","_vehSlot","_playerNetID","_vehicle","_vehicles","_tradeTotal","_current_crypto","_tradeQtyTotal","_currQty","_qtyIndex","_itemWorth","_item","_itemQty","_position","_foundSmoke","_objOwner","_tmpposition","_lockOwner","_helipad","_helipads","_smoke","_vehicleBought","_playerGroup","_vehObj","_final_location","_group","_wp","_wHPos","_wH","_nearByHolder","_itemTax","_tax","_objHiveKey","_playerCryptoLimit","_config","_cIndex","_vars","_current_cryptoRaw","_aiItems","_itemClasses","_itemQtys","_returnIn","_returnOut","_slot"];
params ["_trader","_itemsIn","_itemsOut","_player",["_token","",[""]]];

_playerUID = getplayeruid _player;

_vehicleSold = false;
_vehicleBought = false;

_returnIn = [];
_returnOut = [];
_final_location = [];

if (isNull _trader) exitWith{};
if !([_player,_token] call EPOCH_server_getPToken) exitWith {};
if (_player distance _trader > 20) exitWith{};

_slot = _trader getVariable["AI_SLOT", -1];
if (_slot != -1) then {

	_tradeTotal = 0;
	_tradeIn = 0;
	_tradeOut = 0;
	_tradeQtyTotal = 0;
	_message = "";
	_SkipOut = false;

	_config = 'CfgPricing' call EPOCH_returnConfig;

	// get vars array and current Crypto value
	_cIndex = EPOCH_customVars find "Crypto";
	_vars = _player getVariable["VARS", call EPOCH_defaultVars_SEPXVar];
	_current_crypto = _vars select _cIndex;
	_current_cryptoRaw = _current_crypto;

	// SELL ITEMS TO TRADER
	_aiItems = _trader getVariable["AI_ITEMS", [[], []]];
	_itemClasses = _aiItems select 0;
	_itemQtys = _aiItems select 1;
	{
		_item = _x;
		_itemQty = 1;

		if (isClass (_config >> _item)) then{
			_itemWorth = getNumber(_config >> _item >> "price");

			_makeTradeIn = false;

			if (_item isKindOf "Air" || _item isKindOf "Ship" || _item isKindOf "LandVehicle" || _item isKindOf "Tank") then{

				_vehicles = _trader nearEntities[[_item], 30];
				if !(_vehicles isEqualTo[]) then {

					_vehicle = _vehicles select 0;
					if (!isNull _vehicle) then {

						_playerNetID = owner _player;
						if (_playerNetID == (owner _vehicle)) then {

							_vehSlot = _vehicle getVariable["VEHICLE_SLOT", "ABORT"];
							if (!_vehicleSold && _vehSlot != "ABORT") then {

								removeFromRemainsCollector[_vehicle];
								deleteVehicle _vehicle;
								_vehicleSold = true;

								_vehHiveKey = format["%1:%2", (call EPOCH_fn_InstanceID), _vehSlot];
								_VAL = [];
								["Vehicle", _vehHiveKey, _VAL] call EPOCH_fnc_server_hiveSET;

								EPOCH_VehicleSlots pushBack _vehSlot;

								missionNamespace setVariable ['EPOCH_VehicleSlotCount', count EPOCH_VehicleSlots, true];

								_makeTradeIn = true;
							};
						};
					};
				};
			} else {
				_makeTradeIn = true;
			};

			if (_makeTradeIn) then {

				_returnIn pushBack _item;

				_qtyIndex = _itemClasses find _item;
				if (_qtyIndex == -1) then {
					_itemClasses pushBack  _item;
					_itemQtys pushBack _itemQty;
					_tradeIn = _tradeIn + _itemWorth;
					_current_crypto = _current_crypto + _itemWorth;
					_tradeQtyTotal = _tradeQtyTotal + _itemQty;
				} else {
					_currQty = _itemQtys select _qtyIndex;
					_itemQtys set[_qtyIndex, (_currQty + _itemQty)];
					_tradeIn = _tradeIn + _itemWorth;
					_current_crypto = _current_crypto + _itemWorth;
					_tradeQtyTotal = _tradeQtyTotal + _itemQty;
				};
			};
		};
	} forEach _itemsIn;
	
		_response = ["Bank", _playerUID] call EPOCH_fnc_server_hiveGETRANGE;
		if ((_response select 0) == 1 && (_response select 1) isEqualType []) then {
			_bankData = _response select 1;
			if !(_bankData isEqualTo[]) then {
				_serverSettingsConfig = configFile >> "CfgEpochServer";
				_MaxBankDebit = [_serverSettingsConfig, "MaxBankDebitforTrade", -999999] call EPOCH_fnc_returnConfigEntry;
				_bankBalance = _bankData select 0;
				if (_bankBalance < _MaxBankDebit) then {
					if (_tradeIn > 0) then {
						_bankBalance = _bankBalance + _tradeIn;
						_return = ["Bank", _playerUID, EPOCH_expiresBank, [_bankBalance]] call EPOCH_fnc_server_hiveSETEX;
						_message = _message + "Items sold, but the Money goes to your Bank - to much Bank-Debit";
					}
					else {
						_message = _message + "Putchase not possible - to much Bank-Debit";
					};
					_current_crypto = _current_cryptoRaw;
					_tradeIn = 0;
					_itemsIn = [];
					_itemsOut = [];
					_SkipOut = true;
				};
			};
		};

	if (!_SkipOut) then {
		{
			_item = _x;
			_itemQty = 1;
			if (isClass (_config >> _item)) then{
				_itemWorth = getNumber(_config >> _item >> "price");
				_itemTax = getNumber(_config >> _item >> "tax");
				_tax = _itemWorth * (EPOCH_taxRate + _itemTax);
				_itemWorth = ceil(_itemWorth + _tax);
				_qtyIndex = _itemClasses find _item;
				// add items to array
				if (_qtyIndex != -1) then {

					_currQty = _itemQtys select _qtyIndex;
					if (_currQty >= _itemQty) then {

						if (_current_crypto >= _itemWorth) then {

							if (_item isKindOf "Air" || _item isKindOf "Ship" || _item isKindOf "LandVehicle" || _item isKindOf "Tank") then{

								if (!_vehicleBought) then {

									if !(EPOCH_VehicleSlots isEqualTo[])  then {
										_position = getPosATL _player;

										_helipad = nearestObjects[_position, ["Land_HelipadEmpty_F", "Land_HelipadCircle_F"], 100];
										_helipads = [];
										_smoke = nearestObject[_position, "SmokeShell"];
										if (!isNull _smoke) then {
											_helipad pushBack _smoke;
										};

										// water check
										if (_item isKindOf "Ship") then {
											{
												if (surfaceIsWater (getposATL _x)) then {
													_helipads pushBack _x;
												}
											} forEach _helipad;
										} else {
											{
												if !(surfaceIsWater (getposATL _x)) then {
													_helipads pushBack _x;
												}
											} forEach _helipad;
										};

										if !(_helipads isEqualTo[]) then {

											_foundSmoke = false;
											{
												if (_x isKindOf "SmokeShell") then {
													_objOwner = owner _x;
													if (_objOwner == owner _player) then {
														_position = getPosATL _x;
														_foundSmoke = true;
													} else {
														{
															if (_objOwner == owner _x) exitWith{
																_position = getPosATL _x;
																_foundSmoke = true;
															};
														} forEach (units _player);
													};
												};
												if (_foundSmoke) exitWith {};
											} forEach _helipads;
											if !(_foundSmoke) then {
												_position = getPosATL (_helipads select 0);
											};
										} else {
											_tmpposition = [];
											if (_item isKindOf "Ship") then {
												_tmpposition = [_position, 20, 150, 5, 0, 1000, 1] call BIS_fnc_findSafePos;
												_tmpposition = [_tmpposition, 0, 60, 10, 2, 1000, 0] call BIS_fnc_findSafePos;
											} else {
												_tmpposition = [_position, 20, 120, 5, 0, 2000, 0] call BIS_fnc_findSafePos;
											};
											if ((count _tmpposition) == 2) then {
												_tmpposition set [2, 0];
												if (surfaceIsWater _tmpposition) then {
													_tmpposition = ATLtoASL _tmpposition;
												};
												_position = _tmpposition;
											}
											else {
												_road = [getpos _player,100] call BIS_fnc_nearestRoad;
												if (!isnull _road) then {
													_position = getpos _road;
												};										
											};
										};
										// select available slot
										_vehslot = EPOCH_VehicleSlots select 0;
										// Remove from available slots
										EPOCH_VehicleSlots = EPOCH_VehicleSlots - [_vehslot];
										missionNamespace setVariable ['EPOCH_VehicleSlotCount', count EPOCH_VehicleSlots, true];
										_vehicleBought = true;

										// Group access
										_lockOwner = getPlayerUID _player;
										_playerGroup = _player getVariable["GROUP", ""];
										if (_playerGroup != "") then {
											_lockOwner = _playerGroup;
										};

										_vehObj = [_item,_position,random 360,true,_vehslot,_lockOwner,"NONE",false,false] call EPOCH_spawn_vehicle;
										_final_location = getPosATL _vehObj;

										_group = group _player;
										_wp = _group addWaypoint [_final_location, 0];
										deleteWaypoint [_group, 0];

										_returnOut pushBack _item;

										_itemQtys set[_qtyIndex, (_currQty - _itemQty)];
										_tradeOut = _tradeOut - _itemWorth;
										_current_crypto = _current_crypto - _itemWorth;
										_tradeQtyTotal = _tradeQtyTotal + _itemQty;
									}
									else {
										_errorMsg = "Failed to purchase vehicle.";
										[_errorMsg, 5] remoteExec ['Epoch_message',_player];
									};
								};
							} else {

								if (_item isKindOf "Bag_Base") then {
									_wH = objNull;
									_nearByHolder = nearestObjects [position _player,["groundWeaponHolder"],3];
									if (_nearByHolder isEqualTo []) then {
									  _wHPos = _player modelToWorld [0,1,0];
									  if (surfaceIsWater _wHPos) then {
										_wHPos = ASLToATL _wHPos;
									  };
									  _wH = createVehicle ["groundWeaponHolder",_wHPos, [], 0, "CAN_COLLIDE"];
									} else {
									  _wH = _nearByHolder select 0;
									};
									_wh addBackpackCargoGlobal [_item,1];
								};
								_returnOut pushBack _item;
								_itemQtys set[_qtyIndex, (_currQty - _itemQty)];
								_tradeOut = _tradeOut - _itemWorth;
								_current_crypto = _current_crypto - _itemWorth;
								_tradeQtyTotal = _tradeQtyTotal + _itemQty;
							};
						};
					};
				};
			};
		} forEach _itemsOut;
	};
	
	
	if !(_itemsIn isEqualTo []) then {
		if (_itemsIn isEqualTo _returnIn) then {
			_message = _message + "All Items sold";
		}
		else {
			_message = _message + "Not all Items sold";
		};	
	};
	if !(_itemsOut isEqualTo []) then {
		if (_itemsOut isEqualTo _returnOut) then {
			if !(_message isequalto "") then {
				_message = _message + " | ";
			};
			_message = _message + "All Items purchased";
		}
		else {
			if !(_message isequalto "") then {
				_message = _message + " / ";
			};
			_message = _message + "Not all Items purchased";
		};	
	};

	_tradeTotal = _tradeIn + _tradeOut;


	if !(_returnIn isequalto [] && _returnOut isEqualTo []) then {
		_trader setVariable["AI_ITEMS", [_itemClasses, _itemQtys], true];
		_objHiveKey = format["%1:%2", (call EPOCH_fn_InstanceID), _slot];
		["AI_ITEMS", _objHiveKey, EPOCH_expiresAIdata, [_itemClasses, _itemQtys]] call EPOCH_fnc_server_hiveSETEX;
		if !(_tradeTotal isequalto 0) then {
			_playerCryptoLimit = EPOCH_customVarLimits select _cIndex;
			_playerCryptoLimit params ["_playerCryptoLimitMax","_playerCryptoLimitMin"];
			_current_crypto = ((_current_cryptoRaw + _tradeTotal) min _playerCryptoLimitMax) max _playerCryptoLimitMin;
			_current_crypto remoteExec ['EPOCH_effectCrypto',_player];
			_vars set[_cIndex, _current_crypto];
			_player setVariable["VARS", _vars];
		};
	};

	// Send completed trade back to player
	[_returnIn, _returnOut,_message] remoteexec ["EPOCH_NpcTrade_return",_player];
};
