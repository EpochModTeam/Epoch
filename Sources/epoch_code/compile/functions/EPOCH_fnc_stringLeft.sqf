/*
	Author: Andrew Gregory - EpochMod.com

    Contributors:

	Description:
	Picks a random spot relative to the target with some randomness. (Unused)

    Licence:
    Arma Public License Share Alike (APL-SA) - https://www.bistudio.com/community/licenses/arma-public-license-share-alike

    Github:
    https://github.com/EpochModTeam/Epoch/tree/master/Sources/epoch_code/compile/functions/EPOCH_fnc_stringLeft.sqf

    Example:
    _trimmedStr = ["String In",3] call EPOCH_fnc_stringLeft;

    Parameter(s):
		_this select 0: STRING or anything - String to be trimmed
        _this select 1: SCALAR - number of chars to remove

	Returns:
	STRING
*/
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
