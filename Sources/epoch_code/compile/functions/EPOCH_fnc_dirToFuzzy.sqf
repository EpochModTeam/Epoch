/*
	Author: Andrew Gregory - EpochMod.com

    Contributors:

	Description:
	Direction from one object to another plus a degree value to chose a random direction within.

    Licence:
    Arma Public License Share Alike (APL-SA) - https://www.bistudio.com/community/licenses/arma-public-license-share-alike

    Github:
    https://github.com/EpochModTeam/Epoch/tree/release/Sources/epoch_code/compile/functions/EPOCH_fnc_dirToFuzzy.sqf

    Example:
    _dirToF = [_pos,_destination,44] call EPOCH_fnc_dirToFuzzy;

    Parameter(s):
		_this select 0: (ARRAY or OBJECT) - position1
        _this select 1: (ARRAY or OBJECT) - position2
        _this select 2: NUMBER - random spread [optional: default 32] max 360

	Returns:
	SCALAR - (direction 0-360)
*/
//[[[cog import generate_private_arrays ]]]
private ["_dirToF","_pos1","_pos2","_ret"];
//[[[end]]]
params ["_pos1","_pos2",["_spread",32]];

//if objects, not positions, were passed in, then get their positions
if(_pos1 isEqualType objNull) then {_pos1 = getpos _pos1};
if(_pos2 isEqualType objNull) then {_pos2 = getpos _pos2};

//get compass heading from _pos1 to _pos2
_ret = ((_pos2 select 0) - (_pos1 select 0)) atan2 ((_pos2 select 1) - (_pos1 select 1));
_ret = _ret + ((random _spread) - (_spread / 2));
if (_ret < 0) then {_ret = _ret + 360}; //remove negative value
_ret = _ret % 360; //ensure return is 0-360
_ret
