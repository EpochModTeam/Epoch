//Picks a random spot relative to the target with some randomness.
//usage: [200,50,60] call EPOCH_fnc_findRandomPosBehind
//_maxIn - Maximum distance to choose point
//_minIn - Minimum distance to choose point
//_arcIn - Spread of arc in degrees relative to _unitIn. Is randomised to add fuzziness to final location.
//_unitIn - Unit, player, vehicle etc.
//_offset - Offset initial angle, allows to pick position to the side of _unitIn with -90 or 90.
//_trgtIn = Target to use for relative position from _unitIn. Allows to pick a position left of _trgtin for example.
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