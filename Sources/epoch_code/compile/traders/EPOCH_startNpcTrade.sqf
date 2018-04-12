/*
	Author: He-Man - Ignatz-Gaming

    Contributors: Raimonds Virtoss

	Description:
	Move Items in Tradermenu from TraderOut window to Traderinventory

    Licence:
    Arma Public License Share Alike (APL-SA) - https://www.bistudio.com/community/licenses/arma-public-license-share-alike

    Github:
    https://github.com/EpochModTeam/Epoch/tree/release/Sources/epoch_code/compile/traders/EPOCH_startNpcTrade.sqf
*/

private ["_EnableTempVehTrade","_PlayerItemsOutBox","_TraderItemsOutBox","_config","_current_crypto","_sizeIn","_arrayIn","_item","_rounds","_mags","_itemMags","_index","_sizeOut","_arrayOut","_itemWorth","_itemTax","_tax","_maxrnd"];

if (!isNil "EPOCH_TRADE_STARTED") exitWith{};
if (isNull _this) exitWith{};

if (alive _this) then {
	_EnableTempVehTrade = ["CfgEpochClient", "EnableTempVehTrade", false] call EPOCH_fnc_returnConfigEntryV2;
	_PlayerItemsOutBox = 41501;
	_TraderItemsOutBox = 41502;
	_config = 'CfgPricing' call EPOCH_returnConfig;
	_current_crypto = EPOCH_playerCrypto;
	_sizeIn = lbSize _PlayerItemsOutBox;
	_arrayIn = [];
	if (_sizeIn > 0) then {
		for "_i" from 0 to (_sizeIn - 1) do {
			_item = lbData [_PlayerItemsOutBox, _i];
			_rounds = lbValue [_PlayerItemsOutBox, _i];
			if (isClass (_config >> _item)) then{
				_itemWorth = getNumber (_config >> _item >> "price");
				_maxrnd = 1;
				if ([_item,"cfgMagazines"] call Epoch_fnc_isAny) then {
					_maxrnd = getnumber (configfile >> "cfgMagazines" >> _item >> "count");
				};
				_itemWorth = round (_itemWorth*(_rounds/_maxrnd));
				_added = false;
				if ([_item, "CfgWeapons"] call EPOCH_fnc_isAny) then {
					if (_item in items player) then {
						player removeItem _item;
						_arrayIn pushBack [_item,_rounds];
						_added = true;
					}
					else {
						if (_item in [primaryweapon player, secondaryweapon player]) then {
							player removeweapon _item;
							_arrayIn pushBack [_item,_rounds];
							_added = true;
						};
					};
				}
				else {
					if ([_item, "CfgVehicles"] call EPOCH_fnc_isAny) then {
						if (_item == backpack player) then {
							removeBackpack player;
							_arrayIn pushBack [_item,_rounds];
							_added = true;
						}
						else {
							_vehicles = _this nearEntities[[_item], 30];
							if (!(_vehicles isEqualTo[])) then {
								_vehicle = _vehicles select 0;
								if (!isNull _vehicle) then {
									if (local _vehicle) then {
										_vehSlot = _vehicle getVariable["VEHICLE_SLOT", "ABORT"];
										if (_vehSlot != "ABORT" || _EnableTempVehTrade) then {
											_arrayIn pushBack [_item,_rounds];
											_added = true;
										};
									};
								};
							};
						};
					}
					else {
						_mags = magazinesAmmo player;
						_itemMags = [];
						{
							_x params ["_className","_count"];
							if (_className isequalto _item) then {
								_itemMags pushBack _x;
							};
						} forEach _mags;
						_index = _itemMags find [_item,_rounds];
						if (_index >= 0) then {
							_arrayIn pushback (_itemMags deleteat _index);
							_added = true;
							player removemagazines _item;
							{
								_x call EPOCH_fnc_addMagazineOverflow;
							} foreach _itemMags;
						};
					};
				};
				if (_added) then {
					_current_crypto = _current_crypto + _itemWorth;
				};
			};
		};
	};
	_sizeOut = lbSize _TraderItemsOutBox;
	_arrayOut = [];
	if (_sizeOut > 0) then {
		for "_i" from 0 to (_sizeOut - 1) do {
			_item = lbData [_TraderItemsOutBox, _i];
			_rounds = lbValue [_TraderItemsOutBox, _i];
			if (isClass (_config >> _item)) then {
				_itemWorth = getNumber (_config >> _item >> "price");
				_itemTax = getNumber (_config >> _item >> "tax");
				_tax = _itemWorth * (EPOCH_taxRate + _itemTax);
				_itemWorth = ceil (_itemWorth + _tax);
				_maxrnd = 1;
				if ([_item,"cfgMagazines"] call Epoch_fnc_isAny) then {
					_maxrnd = getnumber (configfile >> "cfgMagazines" >> _item >> "count");
				};
				_itemWorth = round (_itemWorth*(_rounds/_maxrnd));
				if (_current_crypto >= _itemWorth) then {
					_current_crypto = _current_crypto - _itemWorth;
					_arrayOut pushBack [_item,_rounds];
				};
			};
		};
	};
	if !(_arrayIn isEqualTo[] && _arrayOut isEqualTo[]) then {
		EPOCH_TRADE_STARTED = true;
		[_this, _arrayIn, _arrayOut, player, Epoch_personalToken] remoteExec ["EPOCH_server_makeNPCTrade",2];
		closeDialog 0;
	};
};
