private ["_tempArmor","_maxArmorUniform","_curArmor","_maxArmorVest","_maxArmorHeadgear"];
_maxArmorUniform = 0;
{

  _tempArmor = 0;
  {_tempArmor = _tempArmor + ([getNumber(_x >> 'passThrough'),getNumber(_x >> 'armor')] call EPOCH_factorArmor)} forEach ("isClass _x" configclasses (_x >> "HitPoints"));
  _curArmor = ([getNumber(_x >> 'passThrough'),getNumber(_x >> 'armor')] call EPOCH_factorArmor) + getNumber(_x >> 'armorStructural') + _tempArmor;

  if (_curArmor > _maxArmorUniform) then {
    _maxArmorUniform = _curArmor;
  };
} forEach (("isclass _x && getnumber (_x >> 'scope') == 2 && getText (_x >> 'uniformClass') != ''") configclasses (configfile >> "CfgVehicles"));

_maxArmorVest = 0;
{
  _curArmor = ([getNumber(_x >> 'itemInfo' >> 'passThrough'),getNumber(_x >> 'itemInfo' >> 'armor')] call EPOCH_factorArmor);
  if (_curArmor > _maxArmorVest) then {
    _maxArmorVest = _curArmor;
  };
} forEach (("isclass _x && getnumber (_x >> 'scope') == 2 && getnumber (_x >> 'itemInfo' >> 'type') in [701]") configclasses (configfile >> "cfgweapons"));

_maxArmorHeadgear = 0;
{
  _curArmor = ([getNumber(_x >> 'itemInfo' >> 'passThrough'),getNumber(_x >> 'itemInfo' >> 'armor')] call EPOCH_factorArmor);
  if (_curArmor > _maxArmorHeadgear) then {
    _maxArmorHeadgear = _curArmor;
  };
} forEach (("isclass _x && getnumber (_x >> 'scope') == 2 && getnumber (_x >> 'itemInfo' >> 'type') in [605]") configclasses (configfile >> "cfgweapons"));
missionNamespace setVariable ["EPOCH_MAX_ARMOR",[_maxArmorUniform,_maxArmorVest,_maxArmorHeadgear,(_maxArmorUniform + _maxArmorVest + _maxArmorHeadgear)]];
