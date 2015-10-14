private ["_arr","_type","_check","_dist","_cnt","_inflamed","_alive","_nearObjects","_result"];
_arr = param [3,[2,""]];
_type = _arr select 0;
_check = _arr select 1;
_dist = param [4,0];
_cnt = param [5,1];
_inflamed = param [6,0];
_alive = param [7,0];
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
