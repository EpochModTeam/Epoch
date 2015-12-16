/*
	Author: Aaron Clark - EpochMod.com

    Contributors: Raimonds Virtoss

	Description:
	Epoch Item Interact when double clicked

    Licence:
    Arma Public License Share Alike (APL-SA) - https://www.bistudio.com/community/licenses/arma-public-license-share-alike

    Github:
    https://github.com/EpochModTeam/Epoch/tree/master/Sources/epoch_code/compile/inventory/EPOCH_itemInteractDblClick.sqf

    Example:
        onLBDblClick = "_this call EPOCH_itemInteractDblClick";

    Parameter(s):
		_this select 0: CONTROL - control
        _this select 1: NUMBER - listbox index

	Returns:
	NOTHING
*/
EPOCH_InteractedItem = [];
_control = _this select 0;
_index = _this select 1;

_text = _control lbText _index;
_data = _control lbData _index;
_pic = _control lbPicture _index;

if (_data == "") then {
  _confData = "getText (_x >> 'displayName') == _text" configClasses(configFile >> "CfgWeapons");
  if !(_confData isEqualTo[]) then {
    _data = configName(_confData select 0);
  };
};

EPOCH_InteractedItem = [_text,_data,_pic];

_config = 'CfgCrafting' call EPOCH_returnConfig;
_craftingConfig = _config >> _data;

if (isClass (_craftingConfig)) then {
	(EPOCH_InteractedItem select 0) call EPOCH_crafting_load;
} else {
	//TODO: eat, drink, build ... etc
};
