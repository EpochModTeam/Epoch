/*
	Author: Aaron Clark - EpochMod.com

    Contributors:

	Description:
	Returns the DisplayName of a Vehicle, Weapon, or Magazine.

    Licence:
    Arma Public License Share Alike (APL-SA) - https://www.bistudio.com/community/licenses/arma-public-license-share-alike

    Github:
    https://github.com/EpochModTeam/Epoch/tree/master/Sources/epoch_code/compile/functions/EPOCH_itemDisplayName.sqf

    Example:
    _displayName =  _part call EPOCH_itemDisplayName;

    Parameter(s):
		_this: STRING - Vehicle, Weapon, or Magazine config class name

	Returns:
	STRING
*/
private ["_return"];
params ["_item"];
_return = "";
if ([_item, "CfgVehicles"] call EPOCH_fnc_isAny) then {
  _return = getText(configfile >> "CfgVehicles" >> _item >> "DisplayName");
} else {
	if ([_item, "CfgWeapons"] call EPOCH_fnc_isAny) then {
	  _return = getText(configfile >> "CfgWeapons" >> _item >> "DisplayName");
	} else {
		if ([_item, "CfgMagazines"] call EPOCH_fnc_isAny) then {
		  _return = getText(configfile >> "CfgMagazines" >> _item >> "DisplayName");
		};
	};
};
_return;
