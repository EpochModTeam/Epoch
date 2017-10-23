disableSerialization;
_energyRange = _this;
_lcd = uiNamespace getVariable ["EPOCH_geiger_LCD",controlNull];
_led = uiNamespace getVariable ["EPOCH_geiger_LED",controlNull];

_src = nearestObjects[player,["All"],_energyRange];
_radObjects = _src select {(_x getVariable ["EPOCH_Rads", []]) select 0 > 0};
_rads = 0;
{
	_reldir = player getRelDir _x;
	
	if (_reldir > 315 || _reldir < 45) then { //only capture 90 degrees in front of player
		_reldir = if (_reldir > 315) then { 360 - _reldir} else {_reldir}; //convert into 0-45 degrees
		_prc = 100 - (_reldir / 45 * 100); //current direction percent, 45 = 100%
		
		_x getVariable "EPOCH_Rads" params ["_str","_intensity"];
		_dist = player distance _x;
		_radIntensity = if (_dist <= _intensity) then { //only capture rads when within distance
			_rds = (_str / _dist);
			_rdsPrc = (_prc / 100 * _rds);
			_rdsPrc
		} else {
			0
		};
	_rads = _rads + _radIntensity
	};
} forEach _radObjects; //sum up radiation of all objects in vicinity and in FOV

{
	_location = [];
	_LocName = (_x select 0) joinString " ";
	{
		if( (str _x) == _LocName ) exitwith { _location = _x; };
	} foreach EPOCH_nearestLocations;
	if !(_location isEqualTo []) then {
		_x select 1 params ["_str","_intensity"];
		_dist = player distance getPos _location;
		_radIntensity = if (_dist <= _intensity) then {
			_str / _dist
		} else {
			0
		};
		_rads = _rads + _radIntensity;
	};
}foreach EPOCH_radioactiveLocations; //sum up radiation of all radiactive locations in vicinity

_rads = _rads + EPOCH_ambientRadiation;
_lcd ctrlSetText format ["%1r",_rads toFixed 1];
_rads spawn epoch_geiger_animate;

true 
