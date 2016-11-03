/*
	Author: Aaron Clark - EpochMod.com

    Contributors:

	Description:
	Uniform Gear armor calculation

    Licence:
    Arma Public License Share Alike (APL-SA) - https://www.bistudio.com/community/licenses/arma-public-license-share-alike

    Github:
    https://github.com/EpochModTeam/Epoch/tree/release/Sources/epoch_code/compile/inventory/EPOCH_uniformArmorCalc.sqf

    Example:
        _newArmor = _selectedClass call EPOCH_uniformArmorCalc;

    Parameter(s):
	   _this: STRING - CfgWeapons class name of uniform

	Returns:
	NUMBER
*/
//[[[cog import generate_private_arrays ]]]
private ["_newArmor","_uniformArmor","_uniformArmorStructural","_uniformClass","_uniformConfig"];
//[[[end]]]

_uniformClass = _this;
if (isClass (configFile >> "CfgWeapons" >> _this)) then {
  _uniformClass = gettext (configFile >> "CfgWeapons" >> _this >> "ItemInfo" >> "uniformclass");
};
_uniformConfig = (configfile >> "cfgvehicles" >> _uniformClass);
_uniformArmor = getNumber(_uniformConfig >> "armor");
_uniformArmorStructural = getNumber(_uniformConfig >> "armorStructural");
{
  _uniformArmor = _uniformArmorStructural + ([getNumber(_x >> 'passThrough'),getNumber(_x >> 'armor')] call EPOCH_factorArmor)
} forEach ("isClass _x" configclasses (_uniformConfig >> "HitPoints"));
_uniformArmor
