private ["_nearObjects","_result"];
params ["","","",["_arr",[2,""]],["_dist",0],["_cnt",1],["_inflamed",0],["_alive",0]];
_arr params ["_type","_check"];
_result = true;
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
		_config = 'CfgEpochClient' call EPOCH_returnConfig;
		_configWorldInteractions = (_config >> "WorldInteractions");
		_nearObjects = nearestObjects [player, [], _dist];
		_check = _check select 0;
		_tmpResult = false;
		{
			if (alive _x) then {
				if !(_x isKindOf "All") then {
					_tmpResult = [str(_x), _check] call EPOCH_worldObjectType;
				} else {
					_tmpResult = (getNumber(_configWorldInteractions >> (typeOf _x) >> _check) == 1);
				};
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
