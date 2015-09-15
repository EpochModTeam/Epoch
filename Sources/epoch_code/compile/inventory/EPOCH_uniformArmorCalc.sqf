private ["_uniformClass","_uniformArmor","_uniformConfig","_uniformArmorStructural"];

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
