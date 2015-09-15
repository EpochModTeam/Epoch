//Picks a random spot behind the player
//usage: [200,50,60] call EPOCH_fnc_findRandomPosBehind
//_maxIn - Maximum distance to choose point
//_minIn - Minimum distance to choose point
//_arcIn - Spread of arc in degrees behind player
//_unitIn - Unit, player, vehicle etc.
//_offset - offset initial angle, allows to pick position to the side with -90 or 90 (right or left)

_maxIn = _this select 0;
_minIn = _this select 1;
_arcIn = _this select 2;
_unitIn = _this select 3;
_offset = 0;
if ((count _this) > 4) then {
	_offset = _this select 4;
};

_rnd = ((180 +_offset) - (_arcIn / 2)) + (random _arcIn);
_pos = getPosATL _unitIn;  
_dist = ((random (_maxIn - _minIn)) + _minIn) max _minIn;
_dir = (getDir _unitIn) - _rnd;
if (_dir<0) then {_dir = _dir + 360};

_outPos = [(_pos select 0) + (_dist*(sin _dir)), (_pos select 1) + (_dist*(cos _dir)), _pos select 2];
_outPos
