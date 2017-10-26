/*
	Author: Aaron Clark - EpochMod.com

	Contributors:

	Description:
	Generates loot tables from configs

	Licence:
	Arma Public License Share Alike (APL-SA) - https://www.bistudio.com/community/licenses/arma-public-license-share-alike

	Github:
	https://github.com/EpochModTeam/Epoch/tree/release/Sources/epoch_code/compile/both/EPOCH_weightedArray.sqf

	Usage:
	_lootTable = ["CfgMainTable", _type, "tables"] call EPOCH_fnc_weightedArray;
	_loot = selectRandomWeighted _lootTable;
*/
//[[[cog import generate_private_arrays ]]]
private ["_allow","_itemType","_lootTableArray","_lootTableName","_return","_totalChances","_value","_weightedArray"];
//[[[end]]]
params ["_configName","_keyName","_arrayName"];

_debug = ["CfgEpochClient", "debug", false] call EPOCH_fnc_returnConfigEntryV2;
_lootTableName = format["EPOCH_LT_%1_%2_%3",_configName,_keyName,_arrayName];
_return = missionNamespace getVariable[_lootTableName,[]];

// check for compiled loot table
if(_return isEqualTo[]) then {
	// Since no cached version is found, make one.
	_lootTableArray = [];
	_weightedArray  = [];
	{
		if(_x isEqualType []) then {
			_x params ["_tname","_tqty",["_extraLogicRaw", [] ]];
			_tname params ["_item",["_itemType","NA"]];
			_allow = true;
			if !(_extraLogicRaw isEqualTo[]) then {
				_extraLogicRaw params [["_extraLogicType",""],["_extraLogicName",""],["_extraLogicCond",""],["_extraLogicData",""]];
				// check extra logic
				_value = switch _extraLogicType do {
					case "getDate": {
						date select _extraLogicName
					};
					case "getSunorMoon": {
						sunOrMoon
					};
					case "getMissionNamespaceVariable": {
						missionNamespace getVariable [_extraLogicName, _extraLogicData]
					};
					// not really needed
					default {
						_extraLogicName
					};
				};
				_allow = [_value,_extraLogicCond,_extraLogicData] call EPOCH_fnc_arrayToLogic;
			};
			// Check if config item actually exists
			if (_allow) then {
				switch _itemType do {
					case "magazine": {
						_allow = isClass (configFile >> "CfgMagazines" >> _item);
					};
					case "backpack": {
						_allow = isClass (configFile >> "CfgVehicles" >> _item);
					};
					case "item";
					case "weapon": {
						_allow = isClass (configFile >> "CfgWeapons" >> _item);
					};
				};
			};
			// add to loot table
			if (_allow) then {
				_lootTableArray pushBack _tname;
				_weightedArray pushBack _tqty;
			};
		} else {
			_lootTableArray pushBack _x;
			_weightedArray pushBack 1;
		};
	}forEach getArray((_configName call EPOCH_returnConfig) >> _keyName >> _arrayName);

	// compile to selectRandomWeighted <ARRAY> format.
	private _totalChances = 0;
	{_totalChances = _totalChances + _x} count _weightedArray;
	_return = [];
	{
		_return append [_lootTableArray select _forEachIndex,linearConversion [0,_totalChances,_x,0,1]];
	} forEach _weightedArray;

	// cache loot final loot table
	missionNamespace setVariable[_lootTableName,_return];

	// debug
	if (_debug) then {
		diag_log format["DEBUG: LootTable: %1 DATA: %2",_lootTableName,_return];
	};
};

_return
