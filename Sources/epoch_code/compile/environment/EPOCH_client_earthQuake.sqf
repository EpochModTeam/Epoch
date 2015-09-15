_epicenter = _this;
_distance = player distance _epicenter;
_intensity = 1;
if (_distance < 250) then {
	_intensity = 4;
} else {
	if (_distance < 500) then {
		_intensity = 3;
	} else {
		if (_distance < 750) then {
			_intensity = 2;
		};
	};
};
_intensity spawn BIS_fnc_earthQuake;