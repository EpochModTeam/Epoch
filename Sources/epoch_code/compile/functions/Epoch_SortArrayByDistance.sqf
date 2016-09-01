/*
	Author: Aaron Clark - EpochMod.com

    Contributors:

	Description:
	Sorts an array based on distance to input array. (unused)

    Licence:
    Arma Public License Share Alike (APL-SA) - https://www.bistudio.com/community/licenses/arma-public-license-share-alike

    Github:
    https://github.com/EpochModTeam/Epoch/tree/release/Sources/epoch_code/compile/functions/Epoch_SortArrayByDistance.sqf

    Example:
    _sorted = [_unsorted, _inPosition] call Epoch_SortArrayByDistance;

    Parameter(s):
		_this select 0: ARRAY - of unsorted positions
		_this select 1: ARRAY - position

	Returns:
	ARRAY of ARRAYS
*/
//[[[cog import generate_private_arrays ]]]
private ["_closest","_closestPos","_pos","_sorted","_testPos","_unsorted"];
//[[[end]]]
params ["_unsorted","_pos"];
if (_pos isEqualType objNull) then {_pos = getpos _pos;};
_sorted = [];
_closest = [];
_testPos = [0,0,0];
_closestPos = [0,0,0];
{
	_closest = _unsorted select count _unsorted -1;
	{
		if (_x isEqualType objNull) then {_testPos = position _x}else{_testPos = _x};
		if (_closest isEqualType objNull) then {_closestPos = position _closest}else{_closestPos = _closest};
		if ((_testPos distance _pos) < (_closestPos distance _pos)) then {_closest = _x};
	} forEach _unsorted;
	_sorted pushBack _closest;
	_unsorted = _unsorted - [_closest];
} forEach _unsorted;
_sorted
