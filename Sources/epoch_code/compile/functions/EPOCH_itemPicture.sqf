/*
	Author: Aaron Clark - EpochMod.com

    Contributors:

	Description:
	Returns the picture variable of a Vehicle, Weapon, or Magazine.

    Licence:
    Arma Public License Share Alike (APL-SA) - https://www.bistudio.com/community/licenses/arma-public-license-share-alike

    Github:
    https://github.com/EpochModTeam/Epoch/tree/release/Sources/epoch_code/compile/functions/EPOCH_itemPicture.sqf

    Example:
    _part call EPOCH_itemPicture;

    Parameter(s):
		_this: STRING - Vehicle, Weapon, or Magazine config class name

	Returns:
	STRING
*/
//[[[cog import generate_private_arrays ]]]
private ["_return"];
//[[[end]]]
params ["_item"];
_return = "";
if ([_item, "CfgVehicles"] call EPOCH_fnc_isAny) then {
  _return = getText(configfile >> "CfgVehicles" >> _item >> "picture");
} else {
	if ([_item, "CfgWeapons"] call EPOCH_fnc_isAny) then {
	  _return = getText(configfile >> "CfgWeapons" >> _item >> "picture");
	} else {
		if ([_item, "CfgMagazines"] call EPOCH_fnc_isAny) then {
		  _return = getText(configfile >> "CfgMagazines" >> _item >> "picture");
		};
	};
};
_return
