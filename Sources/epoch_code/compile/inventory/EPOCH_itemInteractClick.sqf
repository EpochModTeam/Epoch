/*
	Author: Aaron Clark - EpochMod.com

    Contributors: Raimonds Virtoss

	Description:
	Epoch Item Interact

    Licence:
    Arma Public License Share Alike (APL-SA) - https://www.bistudio.com/community/licenses/arma-public-license-share-alike

    Github:
    https://github.com/EpochModTeam/Epoch/tree/release/Sources/epoch_code/compile/inventory/EPOCH_itemInteractClick.sqf
*/
private ["_data","_confData","_type","_interactOption","_buttonTXT","_magCount","_text","_pic","_display","_useBtn","_config","_craftingConfig"];
_this call EPOCH_selectInventoryItem;
_data = EPOCH_InteractedItem select 1;

_interactOption = 0;
_buttonTXT = "";
_magCount = 1;
_config = (configfile >> "CfgWeapons" >> _data);
_cfgItemInteractions = (('CfgItemInteractions' call EPOCH_returnConfig) >> _data);
if (isClass (_config)) then {
    _type = getNumber (_config >> "type");
    _interactOption = getNumber (_cfgItemInteractions >> "interactAction");
    _buttonTXT = getText(_cfgItemInteractions >> "interactText");
} else {
    _config = (configfile >> "CfgMagazines" >> _data);
    _type = getNumber (_config >> "type");
    _interactOption = getNumber (_cfgItemInteractions >> "interactAction");
    _buttonTXT = getText(_cfgItemInteractions >> "interactText");
    _magCount = getNumber (_config >> "count");
};

_display = (findDisplay 602);
_useBtn = _display displayCtrl -13;

if (_buttonTXT != "") then {
  _useBtn ctrlSetText _buttonTXT;
  _useBtn ctrlEnable true;
} else {
  if (_magCount > 1) then {
      _useBtn ctrlEnable true;
      _useBtn ctrlSetText "REPACK";
  } else {
      _useBtn ctrlSetText "EXAMINE";
      _useBtn ctrlEnable false;
  };
};

_useBtn = _display displayCtrl -14;
_useBtn ctrlEnable true;

_config = 'CfgCrafting' call EPOCH_returnConfig;
if (isClass (_config >> _data)) then {
	_useBtn ctrlSetTextColor [0,1,0,1];
	EPOCH_CraftingItem = EPOCH_InteractedItem select 0;
} else {
	_useBtn ctrlSetTextColor [1,0,0,1];
	EPOCH_CraftingItem = "";
};

true
