private ["_index","_data","_control","_text","_pic","_craftingArray","_craftingArrayNames"];

EPOCH_InteractedItem = [];

_control = _this select 0;
_index = _this select 1;

if (typeName _index == "ARRAY") then {
  _index = (_index select 0) select 1;
};

_text = _control lbText _index;
_data = _control lbData _index;
_pic = _control lbPicture _index;

_craftingArray = [];
_craftingArrayNames = [];

comment 'Not ideal This is needed as weapons do not return a class in the UI';
comment 'This test is to over come an issue that causes the wrong class selected';
comment 'when more than two classes share the same displayName';
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
