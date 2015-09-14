//Currently only used to find random position
//TODO: Expand upon to find spot on road || in field for unit spawn.
//Usage: [centre, min distance, max distance, height, onRoad] call EPOCH_fnc_findSafePos;
//centre - centre position (array)
//min distance - minimum distance away from centre to choose a location
//max distance - maximum distance away from centre to choose a location
//height - is passed through
//onRoad - (boolean) - will select a point on the nearest road (within 250m) from the randomly found position.
//
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
