private ["_data","_confData","_usedIn","_type","_interactOption","_buttonTXT","_control","_index","_text","_pic","_craftingArray","_craftingArrayNames","_config","_craftingConfig","_display","_useBtn"];

EPOCH_InteractedItem = [];
_control = _this select 0;
_index = _this select 1;

_text = _control lbText _index;
_data = _control lbData _index;
_pic = _control lbPicture _index;

_craftingArray = [];
_craftingArrayNames = [];

if (_data == "") then {
  _confData = "getText (_x >> 'displayName') == _text" configClasses(configFile >> "CfgWeapons");
  if !(_confData isEqualTo[]) then {
    _data = configName(_confData select 0);
  };
};

_config = 'CfgCrafting' call EPOCH_returnConfig;
_craftingConfig = _config >> _data;

if (isClass (_craftingConfig)) then {
  _usedIn = [] + getArray (_craftingConfig >> "usedIn");
  {
    _craftingArray pushBack (_x call EPOCH_itemPicture);
    _craftingArrayNames pushBack (_x call EPOCH_itemDisplayName);
  } forEach _usedIn;
};

EPOCH_InteractedItem = [_text,_data,_pic];

_interactOption = 0;
_buttonTXT = "";
if (isClass (configfile >> "cfgweapons" >> _data)) then {
  _type = getNumber (configfile >> "CfgWeapons" >> _data >> "type");
  _interactOption = getNumber (configfile >> "CfgWeapons" >> _data >> "interactAction");
  _buttonTXT = getText(configfile >> "CfgWeapons" >> _data >> "interactText");
} else {
  _type = getNumber (configfile >> "CfgMagazines" >> _data >> "type");
  _interactOption = getNumber (configfile >> "CfgMagazines" >> _data >> "interactAction");
  _buttonTXT = getText(configfile >> "CfgMagazines" >> _data >> "interactText");
};

_display = (findDisplay 602);
_useBtn = _display displayCtrl -13;

if (_buttonTXT != "") then {
  _useBtn ctrlSetText _buttonTXT;
  _useBtn ctrlEnable true;
} else {
  _useBtn ctrlSetText "EXAMINE";
  _useBtn ctrlEnable false;
};

_useBtn = _display displayCtrl -14;
if !(_craftingArray isEqualTo []) then {
  _useBtn ctrlEnable true;
} else {
  _useBtn ctrlEnable false;
};
