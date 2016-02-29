/*
	Author: Aaron Clark - EpochMod.com

    Contributors:

	Description:
	workaround for weapons not returning class in the inventory listboxes

    Licence:
    Arma Public License Share Alike (APL-SA) - https://www.bistudio.com/community/licenses/arma-public-license-share-alike

    Github:
    https://github.com/EpochModTeam/Epoch/tree/master/Sources/epoch_code/compile/inventory/EPOCH_selectInventoryItem.sqf

    Example:
        [_control,_index] call EPOCH_selectInventoryItem;

    Parameter(s):
		_this select 0: CONTROL - control
        _this select 1: NUMBER - listbox index

	Returns:
	NOTHING
*/
private ["_arr","_exit","_data","_name","_text","_pic","_craftingArray","_craftingArrayNames"];
params ["_control","_index"];
EPOCH_InteractedItem = [];

if (_index isEqualType []) then {
  _index = (_index select 0) select 1;
};

_text = _control lbText _index;
_data = _control lbData _index;
_pic = _control lbPicture _index;

_craftingArray = [];
_craftingArrayNames = [];

// This test is to over come an issue that causes the wrong class selected
// when more than two classes share the same displayName
if (_data == "") then {
  {
    _name = configName(_x);
    _exit = false;
    if !(isNull EPOCH_lastContainer) then {
        _arr = ((getItemCargo EPOCH_lastContainer) select 0) + [uniform player,vest player,headgear player];
        _exit = (_name in _arr);
    };
    if (_exit) exitWith {_data = _name};
  } forEach ("getText (_x >> 'displayName') == _text" configClasses(configFile >> "CfgWeapons"));
};
EPOCH_InteractedItem = [_text,_data,_pic];
