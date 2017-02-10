/*
	Author: Aaron Clark - EpochMod.com

    Contributors: He-Man

	Description:
	NPC trade code

    Licence:
    Arma Public License Share Alike (APL-SA) - https://www.bistudio.com/community/licenses/arma-public-license-share-alike

    Github:
    https://github.com/EpochModTeam/Epoch/tree/release/Sources/epoch_code/traders/EPOCH_startNpcTrade.sqf

    Example:
    cursorTarget call EPOCH_startNpcTrade;

    Parameter(s):
		_this: OBJECT

	Returns:
	NOTHING
*/
//[[[cog import generate_private_arrays ]]]
private ["_addWeaponToHands","_arrayIn","_arrayOut","_config","_current_crypto","_errorMsg","_item","_itemTax","_itemWorth","_sizeOut","_tax","_type","_vehSlot","_vehicle","_vehicles"];
//[[[end]]]

if (!isNil "EPOCH_TRADE_STARTED") exitWith{};
if (isNull _this) exitWith{};

if (alive _this) then {

	_config = 'CfgPricing' call EPOCH_returnConfig;

	_current_crypto = EPOCH_playerCrypto;

	// _arrayIn = Sell Array
	_sizeOut = lbSize 41501;
	_arrayIn = [];
	if (_sizeOut > 0) then {
		for "_i" from 0 to(_sizeOut - 1) do {
			_item = lbData[41501, _i];

			if (isClass (_config >> _item)) then{

				// test remove items to be sold and add to array
				if ([_item, "CfgWeapons"] call EPOCH_fnc_isAny) then {
					if (_item in items player) then {
						player removeItem _item;
						_arrayIn pushBack _item;
					} else {
						if (_item == primaryweapon player) then {
							player removeweapon _item;
							_arrayIn pushBack _item;
						};
					};
				} else {
					if ([_item, "CfgVehicles"] call EPOCH_fnc_isAny) then {
						if (_item == backpack player) then {
							removeBackpack player;
							_arrayIn pushBack _item;
						} else {
							_vehicles = _this nearEntities[[_item], 30];
							if (!(_vehicles isEqualTo[])) then {
								_vehicle = _vehicles select 0;
								if (!isNull _vehicle) then {
									if (local _vehicle) then {
										_vehSlot = _vehicle getVariable["VEHICLE_SLOT", "ABORT"];
										if (_vehSlot != "ABORT") then {
											_arrayIn pushBack _item;
											// will be removed server side
										};
									};
								};
							};
						};
					} else {
						if (_item in magazines player) then {
							player removeMagazine _item;
							_arrayIn pushBack _item;
						};
					};
				};
				// test



			};
		};
	};

	// _arrayOut = Purchase Array
	_sizeOut = lbSize 41502;
	_arrayOut = [];
	if (_sizeOut > 0) then {
		for "_i" from 0 to(_sizeOut - 1) do {
			_item = lbData[41502, _i];

			if (isClass (_config >> _item)) then{
				_itemWorth = getNumber(_config >> "price");
				_itemTax = getNumber(_config >> "tax");
				_tax = _itemWorth * (EPOCH_taxRate + _itemTax);
				_itemWorth = ceil(_itemWorth + _tax);

				if (_current_crypto >= _itemWorth) then {
					_current_crypto = _current_crypto - _itemWorth;
					_arrayOut pushBack _item;
				};
			};
		};
	};

	if (!(_arrayIn isEqualTo[]) || !(_arrayOut isEqualTo[])) then {
		EPOCH_TRADE_STARTED = true;

		// make trade
		[_this, _arrayIn, _arrayOut, player, Epoch_personalToken] remoteExec ["EPOCH_server_makeNPCTrade",2];

		// close menu
		closeDialog 0;
	};
};
