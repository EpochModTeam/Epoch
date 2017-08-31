/*
	Author: Aaron Clark - EpochMod.com

	Contributors:

	Description:
	Generates loot tables from configs

	Licence:
	Arma Public License Share Alike (APL-SA) - https://www.bistudio.com/community/licenses/arma-public-license-share-alike

	Github:
	https://github.com/EpochModTeam/Epoch/tree/release/Sources/epoch_code/compile/both/EPOCH_weightedArray.sqf
*/
//[[[cog import generate_private_arrays ]]]
private ["_allow","_lootIndex","_lootTableArray","_lootTableName","_return","_value","_weightedArray"];
//[[[end]]]
params ["_configName","_keyName","_arrayName"];

_lootTableName = format["EPOCH_LT_%1_%2_%3",_configName,_keyName,_arrayName];
_return = missionNamespace getVariable[_lootTableName,[]];

// check for compiled loot table
if(_return isEqualTo[]) then {
	// Since no cached version is found, make one.
	_lootTableArray = [];
	_weightedArray  = [];
	_lootIndex = 0;
	{
		if(_x isEqualType []) then {
			_x params ["_tname","_tqty",["_extraLogicRaw", [] ]];
			_allow = true;
			if !(_extraLogicRaw isEqualTo[]) then {
				_extraLogicRaw params [["_extraLogicType",""],["_extraLogicName",""],["_extraLogicCond",""],["_extraLogicData",""]];
				// check extra logic
				_value = switch _extraLogicType do {
					case "getDate": {
						date select _extraLogicName;
					};
					case "getSunorMoon": {
						sunOrMoon;
					};
					case "getMissionNamespaceVariable": {
						missionNamespace getVariable [_extraLogicName, _extraLogicData];
					};
					// not really needed
					default {
						_extraLogicName;
					};
				};
				_allow = [_value,_extraLogicCond,_extraLogicData] call EPOCH_fnc_arrayToLogic;
			};
			if (_allow) then {
				_lootTableArray pushBack _tname;
				for "_i" from 1 to _tqty do {
					_weightedArray pushBack _lootIndex;
				};
				_lootIndex = _lootIndex + 1;
			};
		} else {
			_lootTableArray pushBack _x;
			_weightedArray pushBack _lootIndex;
			_lootIndex = _lootIndex + 1;
		};
	}forEach getArray((_configName call EPOCH_returnConfig) >> _keyName >> _arrayName);
	_return = [_lootTableArray,_weightedArray];
	// cache loot final loot table
	missionNamespace setVariable[_lootTableName,_return];
};

_return
