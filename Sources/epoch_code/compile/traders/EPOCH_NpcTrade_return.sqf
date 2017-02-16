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
params [["_returnIn",[]],["_returnOut",[]],["_message",""]];

if (isNil "EPOCH_TRADE_STARTED") exitWith{};

if !(_returnOut isEqualTo[]) then {
	// add purchased items
	{
		if ([_x, "CfgWeapons"] call EPOCH_fnc_isAny) then {
			_type = getNumber(configfile >> "CfgWeapons" >> (_x) >> "type");
			_addWeaponToHands = false;
			switch (_type) do {
				case 1: {
					if (primaryWeapon player == "") then {
						_addWeaponToHands = true;
					};
				};
				case 4: {
					if (secondaryWeapon player == "") then {
						_addWeaponToHands = true;
					};
				};
				case 2: {
					if (handgunWeapon player == "") then {
						_addWeaponToHands = true;
					};
				};
			};
			if (_addWeaponToHands) then {
				player addWeapon _x;
			}
			else {
				_x call EPOCH_fnc_addItemOverflow;
			};
		}
		else {
			if ([_x, "CfgMagazines"] call EPOCH_fnc_isAny) then {
				_x call EPOCH_fnc_addItemOverflow;
			};
		};
	} forEach _returnOut;
};

if !(_message isequalto "") then {
	[_message, 5] call Epoch_message;
};

EPOCH_TRADE_STARTED = nil;
