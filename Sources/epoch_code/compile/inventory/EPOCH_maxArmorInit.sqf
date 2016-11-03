/*
	Author: Aaron Clark - EpochMod.com

    Contributors:

	Description:
	Gear armor max armor calculation with support for A3 1.54+.

    Licence:
    Arma Public License Share Alike (APL-SA) - https://www.bistudio.com/community/licenses/arma-public-license-share-alike

    Github:
    https://github.com/EpochModTeam/Epoch/tree/release/Sources/epoch_code/compile/inventory/EPOCH_maxArmorInit.sqf

    Example:
        call EPOCH_maxArmorInit;

    Parameter(s):
	   None

	Returns:
	NOTHING
*/
//[[[cog import generate_private_arrays ]]]
private ["_curArmor","_maxArmorHeadgear","_maxArmorUniform","_maxArmorVest"];
//[[[end]]]
_maxArmorUniform = 0;
{
  _curArmor = ([getNumber(_x >> 'passThrough'),getNumber(_x >> 'armor')] call EPOCH_factorArmor) + getNumber(_x >> 'armorStructural');
  {_curArmor = _curArmor + ([getNumber(_x >> 'passThrough'),getNumber(_x >> 'armor')] call EPOCH_factorArmor)} forEach ("isClass _x" configclasses (_x >> "HitPoints"));
  if (_curArmor > _maxArmorUniform) then {
    _maxArmorUniform = _curArmor;
  };
} forEach (("isclass _x && getnumber (_x >> 'scope') == 2 && getText (_x >> 'uniformClass') != ''") configclasses (configfile >> "CfgVehicles"));

_maxArmorVest = 0;
{
  _curArmor = ([getNumber(_x >> 'itemInfo' >> 'passThrough'),getNumber(_x >> 'itemInfo' >> 'armor')] call EPOCH_factorArmor);
  {_curArmor = _curArmor + ([getNumber(_x >> 'passThrough'),getNumber(_x >> 'armor')] call EPOCH_factorArmor)} forEach ("isClass _x" configclasses (_x >>  "ItemInfo" >> "HitpointsProtectionInfo"));
  if (_curArmor > _maxArmorVest) then {
    _maxArmorVest = _curArmor;
  };
} forEach (("isclass _x && getnumber (_x >> 'scope') == 2 && getnumber (_x >> 'itemInfo' >> 'type') in [701]") configclasses (configfile >> "cfgweapons"));

_maxArmorHeadgear = 0;
{
  _curArmor = ([getNumber(_x >> 'itemInfo' >> 'passThrough'),getNumber(_x >> 'itemInfo' >> 'armor')] call EPOCH_factorArmor);
  {_curArmor = _curArmor + ([getNumber(_x >> 'passThrough'),getNumber(_x >> 'armor')] call EPOCH_factorArmor)} forEach ("isClass _x" configclasses (_x >>  "ItemInfo" >> "HitpointsProtectionInfo"));
  if (_curArmor > _maxArmorHeadgear) then {
    _maxArmorHeadgear = _curArmor;
  };
} forEach (("isclass _x && getnumber (_x >> 'scope') == 2 && getnumber (_x >> 'itemInfo' >> 'type') in [605]") configclasses (configfile >> "cfgweapons"));
missionNamespace setVariable ["EPOCH_MAX_ARMOR",[_maxArmorUniform,_maxArmorVest,_maxArmorHeadgear,(_maxArmorUniform + _maxArmorVest + _maxArmorHeadgear)]];
