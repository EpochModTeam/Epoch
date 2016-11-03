/*
	Author: Aaron Clark - EpochMod.com

    Contributors:

	Description:
	Gear armor calculation with support for A3 1.54+.

    Licence:
    Arma Public License Share Alike (APL-SA) - https://www.bistudio.com/community/licenses/arma-public-license-share-alike

    Github:
    https://github.com/EpochModTeam/Epoch/tree/release/Sources/epoch_code/compile/inventory/EPOCH_gearArmorCalc.sqf

    Example:
    _vestArmor = (vest player) call EPOCH_gearArmorCalc;

    Parameter(s):
		_this: STRING - Vest or Headhear classname

	Returns:
	NUMBER
*/
//[[[cog import generate_private_arrays ]]]
private ["_armor","_gearArmor","_gearConfig","_passThrough","_vestArmor"];
//[[[end]]]
_gearConfig = (configfile >> "CfgWeapons" >> _this);
_passThrough = getNumber(_gearConfig >> "ItemInfo" >> "passThrough");
_armor = getNumber(_gearConfig >> "ItemInfo" >> "armor");
_gearArmor = ([_passThrough,_armor] call EPOCH_factorArmor);
{
  _gearArmor = _gearArmor + ([getNumber(_x >> 'passThrough'),getNumber(_x >> 'armor')] call EPOCH_factorArmor)
} forEach ("isClass _x" configclasses (_gearConfig >> "ItemInfo" >> "HitpointsProtectionInfo"));
_gearArmor
