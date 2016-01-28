/*
NPC trade mech

Epoch Mod - EpochMod.com
All Rights Reserved.
*/
private["_vehicleSold", "_vehicleBought", "_vehHiveKey", "_VAL", "_vehSlot", "_vehicle", "_vehicles", "_trader", "_item", "_plyrNetID", "_plyr", "_itemWorth", "_position", "_tmpposition", "_textures", "_textureSelectionIndex", "_selections", "_colors", "_color", "_count", "_helipad", "_slot", "_vehObj", "_config", "_makeTradeIn", "_tradeTotal", "_current_crypto", "_tradeQtyTotal", "_currQty", "_qtyIndex", "_itemQty", "_foundSmoke", "_objOwner", "_lockOwner", "_plyrGroup", "_itemTax", "_tax", "_objHiveKey", "_cIndex", "_aiItems", "_itemClasses", "_itemQtys", "_itemsIn", "_itemsOut", "_returnIn", "_returnOut", "_smoke", "_vehLockHiveKey", "_colorsConfig", "_vars", "_current_cryptoRaw"];
_trader = _this select 0;
_itemsIn = _this select 1;
_itemsOut = _this select 2;
_plyr = _this select 3;

_vehicleSold = false;
_vehicleBought = false;

_returnIn = [];
_returnOut = [];
_final_location = [];

if (isNull _trader) exitWith{};
if !([_plyr,_this select 4] call EPOCH_server_getPToken) exitWith {};
if (_plyr distance _trader > 20) exitWith{};

_slot = _trader getVariable["AI_SLOT", -1];
if (_slot != -1) then {

	_tradeTotal = 0;
	_tradeQtyTotal = 0;

	_config = 'CfgPricing' call EPOCH_returnConfig;

	// get vars array and current Crypto value
	_cIndex = EPOCH_customVars find "Crypto";
	_vars = _plyr getVariable["VARS", [] + EPOCH_defaultVars_SEPXVar];
	_current_crypto = _vars select _cIndex;
	_current_cryptoRaw = _current_crypto;

	//diag_log format["_current_crypto: %1 _cIndex:%2 %3", _current_crypto, _cIndex, _this];

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

						_plyrNetID = owner _plyr;
						if (_plyrNetID == (owner _vehicle)) then {

							_vehSlot = _vehicle getVariable["VEHICLE_SLOT", "ABORT"];
							if (!_vehicleSold && _vehSlot != "ABORT") then {

								removeFromRemainsCollector[_vehicle];
								deleteVehicle _vehicle;
								_vehicleSold = true;

								_vehHiveKey = format["%1:%2", (call EPOCH_fn_InstanceID), _vehSlot];
								_VAL = [];
								["Vehicle", _vehHiveKey, _VAL] call EPOCH_fnc_server_hiveSET;

								EPOCH_VehicleSlots pushBack _vehSlot;
								EPOCH_VehicleSlotCount = count EPOCH_VehicleSlots;
								publicVariable "EPOCH_VehicleSlotCount";

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
					_tradeTotal = _tradeTotal + _itemWorth;
					_current_crypto = _current_crypto + _itemWorth;
					_tradeQtyTotal = _tradeQtyTotal + _itemQty;
				} else {
					_currQty = _itemQtys select _qtyIndex;
					_itemQtys set[_qtyIndex, (_currQty + _itemQty)];
					_tradeTotal = _tradeTotal + _itemWorth;
					_current_crypto = _current_crypto + _itemWorth;
					_tradeQtyTotal = _tradeQtyTotal + _itemQty;
				};
				//diag_log format["_itemClasses: %1 _itemQtys:%2", _itemClasses, _itemQtys];
			};
		};
	} forEach _itemsIn;



	{
		_item = _x;
		_itemQty = 1;

		 //diag_log format["_item: %1", _item];
		if (isClass (_config >> _item)) then{
			_itemWorth = getNumber(_config >> _item >> "price");
			_itemTax = getNumber(_config >> _item >> "tax");
			_tax = _itemWorth * (EPOCH_taxRate + _itemTax);
			_itemWorth = ceil(_itemWorth + _tax);

			//diag_log format["_itemWorth: %1", _itemWorth];

			_qtyIndex = _itemClasses find _item;
			// add items to array
			if (_qtyIndex != -1) then {

				_currQty = _itemQtys select _qtyIndex;

				//diag_log format["_currQty: %1 >= %2", _currQty, _itemQty];

				if (_currQty >= _itemQty) then {

					if (_current_crypto >= _itemWorth) then {

						if (_item isKindOf "Air" || _item isKindOf "Ship" || _item isKindOf "LandVehicle" || _item isKindOf "Tank") then{

							if (!_vehicleBought) then {

								if !(EPOCH_VehicleSlots isEqualTo[])  then {
									_position = getPosATL _plyr;

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

									// diag_log format["DEBUG: helipad: %1", _helipad];

									if !(_helipads isEqualTo[]) then {

										_foundSmoke = false;
										{
											if (_x isKindOf "SmokeShell") then {
												_objOwner = owner _x;
												if (_objOwner == owner _plyr) then {
													_position = getPosATL _x;
													_foundSmoke = true;
												} else {
													{
														if (_objOwner == owner _x) exitWith{
															_position = getPosATL _x;
															_foundSmoke = true;
														};
													} forEach (units _plyr);
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
											_tmpposition = [_position, 20, 120, 10, 0, 1000, 1] call BIS_fnc_findSafePos;
											_tmpposition = [_tmpposition, 0, 60, 10, 2, 1000, 0] call BIS_fnc_findSafePos;
										} else {
											_tmpposition = [_position, 20, 120, 20, 0, 2000, 0] call BIS_fnc_findSafePos;
										};
										if ((count _tmpposition) == 2) then {
											_tmpposition set [2, 0];
											if (surfaceIsWater _tmpposition) then {
												_tmpposition = ATLtoASL _tmpposition;
											};
											_position = _tmpposition;
										};
									};
									// select available slot
									_vehslot = EPOCH_VehicleSlots select 0;
									// Remove from available slots
									EPOCH_VehicleSlots = EPOCH_VehicleSlots - [_vehslot];
									EPOCH_VehicleSlotCount = count EPOCH_VehicleSlots;
									publicVariable "EPOCH_VehicleSlotCount";



									_vehicleBought = true;


									// Group access
									_lockOwner = getPlayerUID _plyr;
									_plyrGroup = _plyr getVariable["GROUP", ""];
									if (_plyrGroup != "") then {
										_lockOwner = _plyrGroup;
									};

									_vehObj = [_item,_position,random 360,true,_vehslot,_lockOwner,"NONE",false,false] call EPOCH_fnc_spawn_vehicle;
									_final_location = getPosATL _vehObj;

									_group = group _plyr;
									_wp = _group addWaypoint [_final_location, 0];
									deleteWaypoint [_group, 0];

									_returnOut pushBack _item;

									_itemQtys set[_qtyIndex, (_currQty - _itemQty)];
									_tradeTotal = _tradeTotal - _itemWorth;
									_current_crypto = _current_crypto - _itemWorth;
									_tradeQtyTotal = _tradeQtyTotal + _itemQty;
								} else {
									diag_log "DEBUG: no slots found to spawn vehicle";
								};
							};
						} else {

							if (_item isKindOf "Bag_Base") then {
								// add to players back
								/*
								if (backpack _plyr == "") then {
									_plyr addBackpackGlobal _item;
									diag_log "backpack added to players back";
								} else {
								*/
									//diag_log "backpack added to players feet";
									// add to the ground
									_wH = objNull;
									_nearByHolder = nearestObjects [position _plyr,["groundWeaponHolder"],3];
									if (_nearByHolder isEqualTo []) then {
									  _wHPos = _plyr modelToWorld [0,1,0];
									  if (surfaceIsWater _wHPos) then {
										_wHPos = ASLToATL _wHPos;
									  };
									  _wH = createVehicle ["groundWeaponHolder",_wHPos, [], 0, "CAN_COLLIDE"];
									} else {
									  _wH = _nearByHolder select 0;
									};
									//diag_log "backpack added to container";
									_wh addBackpackCargoGlobal [_item,1];
								//};
							};

							_returnOut pushBack _item;

							_itemQtys set[_qtyIndex, (_currQty - _itemQty)];
							_tradeTotal = _tradeTotal - _itemWorth;
							_current_crypto = _current_crypto - _itemWorth;
							_tradeQtyTotal = _tradeQtyTotal + _itemQty;
						};
						//diag_log format["_itemClasses: %1 _itemQtys:%2", _itemClasses, _itemQtys];
					};
				};
			};
		};
	} forEach _itemsOut;

	if (_itemsIn isEqualTo _returnIn || _itemsOut isEqualTo _returnOut) then {

		// save changes to array
		_trader setVariable["AI_ITEMS", [_itemClasses, _itemQtys], true];

		// Force Save
		_objHiveKey = format["%1:%2", (call EPOCH_fn_InstanceID), _slot];
		["AI_ITEMS", _objHiveKey, EPOCH_expiresAIdata, [_itemClasses, _itemQtys]] call EPOCH_fnc_server_hiveSETEX;
		// diag_log format["UPDATED DB FOR TRADER: %1 SLOT: %2 DATA: %3", _trader, _slot, [_itemClasses, _itemQtys]];

		// diag_log format["ADMIN: %1 TRADETOTAL:%2", _plyr, _tradeTotal];

		// push crypto changes to player
		_playerCryptoLimit = [(configFile >> "CfgSecConf" >> "limits"), "playerCrypto", 25000] call EPOCH_fnc_returnConfigEntry;
		_current_crypto = ((_current_cryptoRaw + _tradeTotal) min _playerCryptoLimit) max 0;
		[["effectCrypto", _current_crypto], (owner _plyr)] call EPOCH_sendPublicVariableClient;
		_vars set[_cIndex, _current_crypto];
		_plyr setVariable["VARS", _vars];
	};

	// Send completed trade back to player
	EPOCH_TRADE_COMPLETE = [_returnIn, _returnOut];
	(owner _plyr) publicVariableClient "EPOCH_TRADE_COMPLETE";
};
