/*
	Author: Aaron Clark - EpochMod.com

	Contributors:

	Description:
	Controls attributes given custom vars system and returns text based on these changes.

	Licence:
	Arma Public License Share Alike (APL-SA) - https://www.bistudio.com/community/licenses/arma-public-license-share-alike

	Github:
	https://github.com/EpochModTeam/Epoch/tree/release/Sources/epoch_code/epoch_code/compile/functions/EPOCH_giveAttributes.sqf

	Example:
	_text = _x call EPOCH_giveAttributes

	Parameter(s):
		_this select 0: STRING - Player Stat Name
		_this select 1: NUMBER - Input
		_this select 2: NUMBER - 1 = randomize input, 0 = normal
	Returns:
	STRING
*/

//[[[cog import generate_private_arrays ]]]
private ["_addPlus","_celcuis","_celcuisNew","_color","_currentVal","_customVarIndex","_customVarLimits","_customVarNames","_customVarsInit","_data","_defaultVarValues","_limits","_max","_min","_newValue","_return","_varName","_varNameTmp"];
//[[[end]]]
params ["_selectedVarName",["_data",0],["_randomizeData",0]];
_addPlus = if (_data > 0) then {"+"} else {""};
_return = "";

_customVarsInit = getArray(getMissionConfig "CfgEpochClient" >> "customVarsDefaults");
_customVarNames = _customVarsInit apply {_x param [0,""]};
_defaultVarValues = _customVarsInit apply {_x param [1,0]};
_customVarLimits = _customVarsInit apply {_x param [2,[]]};

_customVarIndex = _customVarNames find _selectedVarName;
if (_customVarIndex != -1) then {

	_varName = format["EPOCH_player%1",_selectedVarName];
	if (_selectedVarName in _customVarNames) then {
		_varNameTmp = call compile format["_player%1Key",_selectedVarName];
		if !(isNil "_varNameTmp") then {_varName = _varNameTmp};
	};

	_limits = _customVarLimits select _customVarIndex;
	_limits params [["_max",100],["_min",0]];
	if (_max isEqualType "") then {
		_max = missionNamespace getVariable [_max, 0];
	};
	if (_min isEqualType "") then {
		_min = missionNamespace getVariable [_min, 0];
	};
	_currentVal = missionNamespace getVariable [_varName, _defaultVarValues select _customVarIndex];
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
