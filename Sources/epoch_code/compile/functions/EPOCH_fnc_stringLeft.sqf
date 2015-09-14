private["_strIn","_strOut","_count","_return","_arrFull","_arrOut"];
_arrOut = [];
_strIn = _this select 0;
if (count _this < 2)exitWith{"USAGE: [""String In"",<int>] call EPOCH_fnc_stringLeft"};
_count = _this select 1;
if (typename _strIn != "STRING") then {_strIn = str(_this select 0)};
_arrFull = toArray _strIn;
{
if (_forEachIndex < _count) then {
_arrOut pushBack _x;
};
}forEach _arrFull;
_return = toString _arrOut;
_return
