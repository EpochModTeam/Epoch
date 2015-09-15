disableSerialization;
// diag_log format["DEBUG INTERACT: %1", _this];

_control =  _this select 0;
_prevIndex = _this select 1;

_selected = (_control lbValue _prevIndex);
_data = (_control lbData _prevIndex);

// diag_log format["DEBUG INTERACT SELECTED: %1 DATA: %2", _selected, _data];

lbClear 1700;


_selectedInteractID = format["%1_%2",_data,_selected];

if (_data == "Shop") exitWith {
	_shopArray =  getArray (configFile >> "CfgInteract" >> _selectedInteractID >> "shop");
	_dt = [format["<t size='0.8' shadow='0' color='#99ffffff'>START SHOP DIALOG: %1</t>", _shopArray], 0, 1, 5, 2, 0, 1] spawn bis_fnc_dynamictext;
	closeDialog 0;
};


if (_data == "Mission") exitWith {
	_missionArray =  getArray (configFile >> "CfgInteract" >> _selectedInteractID >> "mission");
	_dt = [format["<t size='0.8' shadow='0' color='#99ffffff'>START MISSION DIALOG: %1</t>", _missionArray], 0, 1, 5, 2, 0, 1] spawn bis_fnc_dynamictext;
	closeDialog 0;
};

_responseArray =  getArray (configFile >> "CfgInteract" >> _selectedInteractID >> "responseNPC");

if !(_responseArray isEqualTo []) then {
	_response =  (_responseArray select floor(random(count _responseArray)));
	if (_response != "") then {
		_dt = [format["<t size='0.8' shadow='0' color='#99ffffff'>%1</t>", _response], 0, 1, 5, 2, 0, 1] spawn bis_fnc_dynamictext;
	};
};

// diag_log format["DEBUG INTERACT _interactID: %1", _selectedInteractID];


_dataArray =  getArray (configFile >> "CfgInteract" >> _selectedInteractID >> "interactMenu");
{
	_interactSecondID = format["Interact_%1", _x];
	_interactName =  getText (configFile >> "CfgInteract" >> _interactSecondID >> "interactName");
	_index = lbAdd[1700,_interactName];


	lbSetValue [1700, _index, _x];
	lbSetData [1700, _index,"Interact"];
}forEach _dataArray;



_dataArray =  getArray (configFile >> "CfgInteract" >> _selectedInteractID >> "missionMenu");
{
	_interactSecondID = format["Mission_%1", _x];
	_interactName =  getText (configFile >> "CfgInteract" >> _interactSecondID >> "interactName");
	_index = lbAdd[1700,_interactName];

	lbSetValue [1700, _index, _x];
	lbSetData [1700, _index,"Mission"];
}forEach _dataArray;



_dataArray =  getArray (configFile >> "CfgInteract" >> _selectedInteractID >> "shopMenu");
{
	_interactSecondID = format["Shop_%1", _x];
	_interactName =  getText (configFile >> "CfgInteract" >> _interactSecondID >> "interactName");
	_index = lbAdd[1700,_interactName];

	lbSetValue [1700, _index, _x];
	lbSetData [1700, _index,"Shop"];
}forEach _dataArray;