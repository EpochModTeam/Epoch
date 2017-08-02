/*
	Author: Raimonds Virtoss - EpochMod.com

    Contributors:

	Description: no use outside favbar probably. Weapons return display names only, so this hack allows getting their className
					
    Licence:
    Arma Public License Share Alike (APL-SA) - https://www.bistudio.com/community/licenses/arma-public-license-share-alike

    Github:
    https://github.com/EpochModTeam/Epoch/tree/release/Sources/epoch_code/gui/scripts/favBar/epoch_favBar_getGearItem.sqf

	Usage: none

	RETURNS: classname for item in inventory
*/
private ["_return","_dispName","_idx","_className"];
(_this select 1 select 0) params ["_dispName","_idx","_className"];
_return = "";

if (_className isEqualTo "") then { //do itemsWithMagazines instead 

{
	_txt = getText (configFile >> "CfgWeapons" >> _x >> "displayName");
	if (_txt isEqualTo _dispName) exitWith {_return = _x};
} forEach (items player);

} else {
	_return = _className;
};

_return 