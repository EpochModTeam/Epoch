private ["_sorted","_closest","_unsorted","_pos","_testPos","_closestPos"];
_sorted = [];
_closest = [];
_unsorted = _this select 0;
_pos = _this select 1;
if (typename _pos == "OBJECT") then {_pos = getpos _pos;};
_sorted = [];
_testPos = [0,0,0];
_closestPos = [0,0,0];
{
	 _closest = _unsorted select count _unsorted -1;
	 {
	 if (typename _x == "OBJECT") then {_testPos = position _x}else{_testPos = _x};
	 if (typename _closest == "OBJECT") then {_closestPos = position _closest}else{_closestPos = _closest};
	 if ((_testPos distance _pos) < (_closestPos distance _pos)) then {_closest = _x};
	 } forEach _unsorted;
	 _sorted pushBack _closest;
	 _unsorted = _unsorted - [_closest];
} forEach _unsorted;
_sorted