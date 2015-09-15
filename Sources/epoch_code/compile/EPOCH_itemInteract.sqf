disableSerialization;

_text = "";
_data = "";
_pic = "";

if (typeName _this isEqualTo "BOOL" && count EPOCH_InteractedItem == 3) then {
	_text = EPOCH_InteractedItem select 0;
	_data = EPOCH_InteractedItem select 1;
	_pic = EPOCH_InteractedItem select 2;
	//diag_log "DEBUG: mode 1";
	
} else {
	//diag_log "DEBUG: mode 2";

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
};

_craftingArray = [];
_craftingArrayNames = [];

// _craftingConfig = configfile >> "CfgCrafting" >> _data;

_config = 'CfgCrafting' call EPOCH_returnConfig;
_craftingConfig = _config >> _data;

if (isClass (_craftingConfig)) then {
	_usedIn = [] + getArray (_craftingConfig >> "usedIn");
	{
		//diag_log format["DEBUG: %1",_x,(_x call EPOCH_itemPicture),(_x call EPOCH_itemDisplayName)];
		_craftingArray pushBack (_x call EPOCH_itemPicture);
		_craftingArrayNames pushBack (_x call EPOCH_itemDisplayName);
	} forEach _usedIn;
};

//diag_log format["DEBUG: EPOCH_itemInteract %1  EPOCH_InteractedItem %2", _this, EPOCH_InteractedItem];
// diag_log format["DEBUG: _craftingArrayNames %1  _craftingArray %2", _craftingArrayNames, _craftingArray];

closeDialog 0;
if !(createdialog "InteractItem") exitWith {};

ctrlShow[1600, false];
ctrlShow[2100, false];
ctrlShow[1000, false];
ctrlShow[41008, false];
ctrlShow[42000, false];

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

if (_buttonTXT == "") then {
	_buttonTXT = "EXAMINE";
};

ctrlSetText [41201, _buttonTXT];
ctrlSetText [41200, _pic];
_craftingArrayCount = count _craftingArray;
_controls = [41202,41203,41204,41205,41206,41207];
_buttons = [1602,1603,1604,1605,1606,1607];

{
	if (_craftingArrayCount >= (_forEachIndex+1)) then {
		ctrlSetText [_x, (_craftingArray select _forEachIndex)];
		((findDisplay -15) displayCtrl (_buttons select _forEachIndex)) ctrlSetTooltip (_craftingArrayNames select _forEachIndex);
		ctrlShow [_buttons select _forEachIndex, true];
	} else {
		ctrlShow [_buttons select _forEachIndex, false];
	};
}forEach _controls;