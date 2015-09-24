private ["_rain","_fog","_overcast","_windValX","_windValZ","_tempOVRD","_rainOVRD","_fogOVRD","_overcastOVRD","_windOVRD","_arr","_response","_rnd_temp"];

if !(EPOCH_WeatherStaticForecast isEqualTo []) then {
	_tempOVRD = EPOCH_WeatherStaticForecast select 0;
	_rainOVRD = EPOCH_WeatherStaticForecast select 1;
	_fogOVRD = EPOCH_WeatherStaticForecast select 2;
	_overcastOVRD = EPOCH_WeatherStaticForecast select 3;
	_windOVRD = EPOCH_WeatherStaticForecast select 4;
	diag_log format["DEBUG: static weather: %1", EPOCH_WeatherStaticForecast];
} else {
	_response = ["Weather", (call EPOCH_fn_InstanceID)] call EPOCH_fnc_server_hiveGETRANGE;
	if ((_response select 0) == 1 && typeName(_response select 1) == "ARRAY" && !((_response select 1) isEqualTo[])) then {
		_arr = _response select 1;
		_tempOVRD = _arr select 0;
		_rainOVRD = _arr select 1;
		_fogOVRD = _arr select 2;
		_overcastOVRD = _arr select 3;
		_windOVRD = _arr select 4;
		diag_log format["DEBUG: hive weather: %1", _arr];
	};
};

_rnd_temp = if (sunOrMoon < 1) then { (random 35) + 15 } else { (random 75) + 50 };

EPOCH_CURRENT_WEATHER = if (isNil "_tempOVRD") then { _rnd_temp } else { _tempOVRD };
publicVariable "EPOCH_CURRENT_WEATHER";

_fog = if (isNil "_fogOVRD") then { [random 0.2, random 0.2, random 20] } else { _fogOVRD };
_rain = if (isNil "_rainOVRD") then { random 1 } else { _rainOVRD };
_overcast = if (isNil "_overcastOVRD") then { random 1 } else { _overcastOVRD };

EPOCH_WeatherChangeTime setFog _fog;
EPOCH_WeatherChangeTime setOvercast _overcast;
EPOCH_WeatherChangeTime setRain _rain;

_windValX = random 10 - 5;
_windValZ = random 10 - 5;
if (_rain > 0.5) then {
	_windValX = random 20 - 10;
	_windValZ = random 20 - 10;
};

if !(isNil "_windOVRD") then { 
	_windValX = _windOVRD select 0;
	_windValZ = _windOVRD select 1;
};

setWind[_windValX, _windValZ, true];

if (_this) then {
	forceWeatherChange;
};

diag_log format["Weather Change: fog: %1 rain: %2 overcast: %3 windx: %4 windz: %5 forced: %6", _fog, _overcast, _rain, _windValX, _windValZ, _this];