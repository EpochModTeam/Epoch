/*
	Author: Aaron Clark - EpochMod.com

    Contributors: He-Man - Ignatz-Gaming

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
private ["_addWeaponToHands","_item","_type"];
//[[[end]]]
params [["_returnIn",[]],["_returnOut",[]],["_message",""]];

if (isNil "EPOCH_TRADE_STARTED") exitWith{};

if !(_returnOut isEqualTo[]) then {
	// add purchased items
	{
		_x params ["_item","_count"];
		if ([_item, "CfgWeapons"] call EPOCH_fnc_isAny) then {
			_type = getNumber(configfile >> "CfgWeapons" >> _item >> "type");
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
				player addWeapon _item;
			}
			else {
				_item call EPOCH_fnc_addItemOverflow;
			};
		}
		else {
			if ([_item, "CfgMagazines"] call EPOCH_fnc_isAny) then {
				[_item,_count] call EPOCH_fnc_addMagazineOverflow;
			};
		};
	} forEach _returnOut;
};

if !(_message isequalto "") then {
	[_message, 5] call Epoch_message;
};

EPOCH_TRADE_STARTED = nil;

