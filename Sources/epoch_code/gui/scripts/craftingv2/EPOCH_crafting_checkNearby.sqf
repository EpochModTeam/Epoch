/*
	Author: Raimonds Virtoss - EpochMod.com

    Contributors:

	Description:
	DESC-TBA

    Licence:
    Arma Public License Share Alike (APL-SA) - https://www.bistudio.com/community/licenses/arma-public-license-share-alike

    Github:
    https://github.com/EpochModTeam/Epoch/tree/release/Sources/epoch_code/gui/scripts/craftingv2/EPOCH_crafting_checkNearby.sqf
*/
//[[[cog import generate_private_arrays ]]]
private ["_check","_countAlive","_countOnFire","_find","_nearObjects","_result","_test1","_test2","_tmpResult"];
//[[[end]]]
params ["","","",["_arr",[2,""]],["_dist",0],["_cnt",1],["_inflamed",0],["_alive",0]];
_arr params ["_type","_check"];
_result = false;
switch (_type) do {
	case 0:
	{
		private ["_test1","_test2","_find"];
		_nearObjects = nearestObjects [player, [], _dist];
		_test1 = 0;
		{
			_test2 = _x;
			_find = {(str _x find _test2) != -1} count _nearObjects;
			_test1 = _test1 + _find;
		} forEach _check;

		_result = (_cnt <= _test1);
	};
	case 1:
	{
		_nearObjects = nearestObjects [player, _check, _dist];
		_result = (_cnt <= (count _nearObjects));
	};
	case 2:
	{
		_nearObjects = nearestObjects [player, [], _dist];
		_check = _check select 0;
		_tmpResult = false;
		{
			if (alive _x) then {
				_tmpResult = [_x, _check] call EPOCH_worldObjectType;
			};
			if (_tmpResult) exitWith {_result = _tmpResult};
		} forEach _nearObjects;
	};
};

if !(_result) exitWith {false}; //not enough objects

if (_inflamed > 0) then {
	_countOnFire = 0;
	_countOnFire = {inflamed _x} count _nearObjects;
	_result = (_cnt <= _countOnFire);
};
if !(_result) exitWith {false};

if (_alive > 0) then {
	_countAlive = 0;
	_countAlive = {alive _x} count _nearObjects;
	_result = (_cnt <= _countAlive);
};
_result
