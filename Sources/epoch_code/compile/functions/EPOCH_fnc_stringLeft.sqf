/*
	Author: Andrew Gregory - EpochMod.com

    Contributors:

	Description:
	Picks a random spot relative to the target with some randomness. (Unused)

    Licence:
    Arma Public License Share Alike (APL-SA) - https://www.bistudio.com/community/licenses/arma-public-license-share-alike

    Github:
    https://github.com/EpochModTeam/Epoch/tree/release/Sources/epoch_code/compile/functions/EPOCH_fnc_stringLeft.sqf

    Example:
    _trimmedStr = ["String In",3] call EPOCH_fnc_stringLeft;

    Parameter(s):
		_this select 0: STRING or anything - String to be trimmed
        _this select 1: SCALAR - number of chars to remove

	Returns:
	STRING
*/
//[[[cog import generate_private_arrays ]]]
private ["_arrFull","_arrOut","_strIn","_trimmedStr"];
//[[[end]]]
private["_arrFull","_arrOut"];
params [
    "_strIn",
    ["_count",0,[0]]
];
_arrOut = [];
if !(_strIn isEqualType "STRING") then {_strIn = str(_strIn)};
_arrFull = toArray _strIn;
{
    if (_forEachIndex < _count) then {
        _arrOut pushBack _x;
    };
}forEach _arrFull;
(toString _arrOut)
