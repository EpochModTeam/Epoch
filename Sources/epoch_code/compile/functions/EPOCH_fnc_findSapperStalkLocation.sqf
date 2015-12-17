/*
	Author: Andrew Gregory - EpochMod.com

    Contributors:

	Description:
	Picks a random spot relative to the target with some randomness. (Unused)

    Licence:
    Arma Public License Share Alike (APL-SA) - https://www.bistudio.com/community/licenses/arma-public-license-share-alike

    Github:
    https://github.com/EpochModTeam/Epoch/tree/master/Sources/epoch_code/compile/functions/EPOCH_fnc_findSapperStalkLocation.sqf

    Example:
    _moveTo = [_centre, _min_distance, _max_distance, _height, _onRoad] call EPOCH_fnc_findSafePos;

    Parameter(s):
		_this select 0: SCALAR - Maximum distance to choose point
        _this select 1: SCALAR - Minimum distance to choose point
        _this select 2: SCALAR - Spread of arc in degrees relative to _unitIn. Is randomised to add fuzziness to final location.
		_this select 3: OBJECT -  Unit, player, vehicle etc.
		_this select 4: SCALAR - Offset initial angle, allows to pick position to the side of _unitIn with -90 or 90.
        _this select 5: OBJECT - Target to use for relative position from _unitIn. Allows to pick a position left of _trgtin for example. [optional: default false]

	Returns:
	ARRAY
*/
_maxIn = _this select 0;
_minIn = _this select 1;
_arcIn = _this select 2;
_unitIn = _this select 3;
_offset = _this select 4;
_trgtIn = _this select 5;
_dirTo = [position _unitIn, position _trgtIn] call BIS_fnc_dirTo;
_rnd = _offset - (random _arcIn);
_pos = getPosATL _trgtIn;
_dist = ((random (_maxIn - _minIn)) + _minIn) max _minIn;
_dir = _dirTo - _rnd;
if (_dir<0) then {_dir = _dir + 360};
_outPos = [(_pos select 0) + (_dist*(sin _dir)), (_pos select 1) + (_dist*(cos _dir)), _pos select 2];
_outPos
