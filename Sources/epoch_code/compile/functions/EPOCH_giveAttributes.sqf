// EPOCH_giveAttributes
//[[[cog import generate_private_arrays ]]]
private ["_addPlus","_celcuis","_celcuisNew","_currentVal","_customVarIndex","_data","_limits","_max","_min","_newValue","_return","_varName"];
//[[[end]]]
params ["_selectedVarName",["_data",0],["_randomizeData",0]];
_addPlus = if (_data > 0) then {"+"} else {""};
_return = "";
_customVarIndex = EPOCH_customVars find _selectedVarName;
if (_customVarIndex != -1) then {
    _varName = format["EPOCH_player%1",_selectedVarName];
    _limits = EPOCH_customVarLimits select _customVarIndex;
	_limits params [["_max",100],["_min",0]];
	if (_max isEqualType "") then {
		_max = missionNamespace getVariable [_max, 0];
	};
	if (_min isEqualType "") then {
		_min = missionNamespace getVariable [_min, 0];
	};
	_currentVal = missionNamespace getVariable [_varName, EPOCH_defaultVars select _customVarIndex];
	if (_randomizeData isEqualTo 1) then {
		_data = round(random _data);
	};
    if (_data != 0) then {
    	_newValue = ((_currentVal + _data) min _max) max _min;
    	missionNamespace setVariable [_varName, _newValue];
    	if (_selectedVarName == "Temp") then {
    		_celcuis = _data call EPOCH_convertTemp;
    		_celcuisNew = _newValue call EPOCH_convertTemp;
    		_return = format["%1: %2%3 (%4 °F) %2%5 (%6 °C)",(localize format["str_epoch_pvar_%1",_selectedVarName]),_addPlus,_data,_newValue,_celcuis,_celcuisNew];
    	} else {
    		_return = format["%1: %2%3 (%4/%5)", (localize format["str_epoch_pvar_%1",_selectedVarName]), _addPlus, _data, _newValue, _max];
    	};
    };
};

_return
