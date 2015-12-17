/*
	Author: Andrew Gregory - EpochMod.com

    Contributors:

	Description:
	Currently only used to find random position (Unused)
	//TODO: Expand upon to find spot on road || in field for unit spawn.

    Licence:
    Arma Public License Share Alike (APL-SA) - https://www.bistudio.com/community/licenses/arma-public-license-share-alike

    Github:
    https://github.com/EpochModTeam/Epoch/tree/master/Sources/epoch_code/compile/functions/EPOCH_fnc_findSafePos.sqf

    Example:
    _moveTo = [_centre, _min_distance, _max_distance, _height, _onRoad] call EPOCH_fnc_findSafePos;

    Parameter(s):
		_this select 0: SCALAR - center position
        _this select 1: SCALAR - minimum distance away from centre to choose a location
        _this select 2: SCALAR - minimum distance away from centre to choose a location
		_this select 3: SCALAR - height - is passed through. [optional: default 0]
		_this select 4: BOOL - will select a point on the nearest road (within 250m) from the randomly found position. [optional: default false]

	Returns:
	ARRAY
*/
private["_MinDist","_MaxDist","_outHeight","_inPos","_rDist","_rDir","_outPos","_nrRoad","_nrRoads","_onRoad"];
_inPos = _this select 0;
_MinDist = _this select 1;
_MaxDist = _this select 2;

_outHeight = 0;
if ((count _this) > 3) then {
	_outHeight = _this select 3;
};

_onRoad = false;
if ((count _this) > 4) then {
	_onRoad = _this select 4;
};


_rDist = (random (_MaxDist - _MinDist))+_MinDist;
_rDir = random 360;
_outPos = [(_inPos select 0) + (sin _rDir) * _rDist, (_inPos select 1) + (cos _rDir) * _rDist, _outHeight];

if (_onRoad) then {
	_nrRoads = _outPos nearRoads 250;
	if (count _nrRoads > 0) then {
		_nrRoad = _nrRoads select (floor(random (count _nrRoads)));
		_outPos = getPosATL _nrRoad;
	};
};
_outPos
