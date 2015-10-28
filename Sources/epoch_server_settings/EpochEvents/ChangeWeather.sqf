/*
    Weather Control System
	by Aaron Clark - EpochMod.com

	This work is licensed under a Creative Commons Attribution-NonCommercial-NoDerivatives 4.0 International License.
	http://creativecommons.org/licenses/by-nc-nd/4.0/

	Improvements and or bugfixes and other contributions are welcome via the github:
	https://github.com/EpochModTeam/Epoch/tree/master/Sources/epoch_server_settings/EpochEvents/ChangeWeather.sqf
*/

private ["_tempOVRD","_rainOVRD","_fogOVRD","_overcastOVRD","_windOVRD","_arr","_response","_windValX","_windValZ","_WeatherChangeTime","_force","_rnd_temp","_fog","_rain","_overcast"];

// Initalize variable for tracking time between runs.
if (isNil "EPOCH_lastWeatherChange") then {
	EPOCH_lastWeatherChange = diag_tickTime;
};

// get the time between weather change events to use as tranistion time.
_WeatherChangeTime = diag_tickTime - EPOCH_lastWeatherChange;

// increment timer to current time.
EPOCH_lastWeatherChange = diag_tickTime;

_force = false;

// use config static weather if set.
if !(EPOCH_WeatherStaticForecast isEqualTo []) then {
	_tempOVRD = EPOCH_WeatherStaticForecast select 0;
	_rainOVRD = EPOCH_WeatherStaticForecast select 1;
	_fogOVRD = EPOCH_WeatherStaticForecast select 2;
	_overcastOVRD = EPOCH_WeatherStaticForecast select 3;
	_windOVRD = EPOCH_WeatherStaticForecast select 4;
	diag_log format["DEBUG: static weather: %1", EPOCH_WeatherStaticForecast];
} else {

	// Make database call to get "Weather:InstanceID" that can be set in the database to allow for weather controls outside of the game.
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

// get random temp.
_rnd_temp = if (sunOrMoon < 1) then { (random 35) + 15 } else { (random 75) + 50 };

// push temp to all players and JIP.
EPOCH_CURRENT_WEATHER = if (isNil "_tempOVRD") then { _rnd_temp } else { _tempOVRD };
publicVariable "EPOCH_CURRENT_WEATHER";

// fog, rain, overcast.
_fog = if (isNil "_fogOVRD") then { [random 0.2, random 0.2, random 20] } else { _fogOVRD };
_rain = if (isNil "_rainOVRD") then { random 1 } else { _rainOVRD };
_overcast = if (isNil "_overcastOVRD") then { random 1 } else { _overcastOVRD };

_WeatherChangeTime setFog _fog;
_WeatherChangeTime setOvercast _overcast;
_WeatherChangeTime setRain _rain;

// wind.
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

// will force weather change if set to true (will cause lag).
if (_force) then {
	forceWeatherChange;
};

diag_log format["Weather Change: fog: %1 rain: %2 overcast: %3 windx: %4 windz: %5 forced: %6", _fog, _overcast, _rain, _windValX, _windValZ, _force];
