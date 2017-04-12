/*
    Weather Control System
	by Aaron Clark - EpochMod.com

	Improvements and or bugfixes and other contributions are welcome via the github:
	https://github.com/EpochModTeam/Epoch/tree/release/Sources/epoch_server_settings/EpochEvents/ChangeWeather.sqf
*/

private ["_tempOVRD","_rainOVRD","_fogOVRD","_overcastOVRD","_windOVRD","_arr","_response","_windValX","_windValY","_WeatherChangeTime","_force","_temp","_fog","_rain","_overcast"];

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
_staticWeatherForecast = [];
if !(EPOCH_WeatherStaticForecast isEqualTo []) then {
    _staticWeatherForecast = EPOCH_WeatherStaticForecast;
} else {
	// Make database call to get "Weather:InstanceID" that can be set in the database to allow for weather controls outside of the game.
	_response = ["Weather", (call EPOCH_fn_InstanceID)] call EPOCH_fnc_server_hiveGETRANGE;
	if ((_response select 0) == 1 && (_response select 1) isEqualType [] && !((_response select 1) isEqualTo[])) then {
		_arr = _response select 1;
        _staticWeatherForecast = _arr;
	};
};
_staticWeatherForecast params ["_tempOVRD","_rainOVRD","_fogOVRD","_overcastOVRD","_windOVRD","_lightningOVRD"];

/*
    New weather configs
    BAD WEATHER:
*/
_randomNightTemp = [0,10,32];
_randomNightRainTemp = [-10,5,25];
_randomDayTemp = [50,95,112];
_randomDayRainTemp = [50,75,99];

_randomFogValue = [0,0.1,0.2] vectorMultiply (1-rain);
_randomFogDecay = [0,0.1,0.2] vectorMultiply (1-rain);
_randomFogBase = [0,10,20] vectorMultiply (1-rain);

_randomFogAfterRainValue = [0,0.15,0.25];
_randomFogAfterRainDecay = [0,0.20,0];
_randomFogAfterRainBase = [0,12,25];

_randomRainValue = [0,1,0];
_randomOvercastValue = [0,1,0];
_randomLightningValue = [0,1,0];

_randomDirection = random 360;
_randomWindStr = random 20;
// config end

_rain = if (isNil "_rainOVRD") then { random _randomRainValue } else { _rainOVRD };
_windVal = [cos _randomDirection,sin _randomDirection,0] vectorMultiply (_randomWindStr * _rain);
_windVal params ["_windValX","_windValY"];

// wind.
if (_rain > 0.1) then {
    _randomNightTemp = _randomNightRainTemp;
    _randomDayTemp = _randomDayRainTemp;
} else {
    // use increase fog settings if just it rained
    if (humidity > 0.5) then {
        _randomFogValue = _randomFogAfterRainValue vectorMultiply humidity;
        _randomFogDecay = _randomFogAfterRainDecay vectorMultiply humidity;
        _randomFogBase = _randomFogAfterRainBase vectorMultiply humidity;
    };
};

if !(isNil "_windOVRD") then {
    _windValX = _windOVRD select 0;
    _windValY = _windOVRD select 1;
};

// cooler at night
_temp = if (sunOrMoon < 1) then { random _randomNightTemp } else { random _randomDayTemp };

// force reduced fog if temps are out of range
if (_temp < 32 || _temp > 75) then {
    _randomFogValue = _randomFogValue vectorMultiply 0.1;
    _randomFogDecay = _randomFogValue vectorMultiply 0.1;
    _randomFogBase = _randomFogValue vectorMultiply 0.1;
};

_fog = if (isNil "_fogOVRD") then { [random _randomFogValue, random _randomFogDecay, random _randomFogBase] } else { _fogOVRD };
_overcast = if (isNil "_overcastOVRD") then { random _randomOvercastValue } else { _overcastOVRD };
_lightning = if (isNil "_lightningOVRD") then { random _randomLightningValue } else { _lightningOVRD };

_WeatherChangeTime setFog _fog;
_WeatherChangeTime setOvercast _overcast;
_WeatherChangeTime setRain _rain;
_WeatherChangeTime setLightnings _lightning;
setWind[_windValX, _windValY, true];

// push temp to all players and JIP.
missionNamespace setVariable ["EPOCH_CURRENT_WEATHER", if (isNil "_tempOVRD") then { round(_temp) } else { _tempOVRD }, true];

// will force weather change if set to true (will cause lag).
if (_force) then {
	forceWeatherChange;
};

diag_log format["Epoch: Weather Change - fog: %1 rain: %2 overcast: %3 wind: %4 wind-xy: %5 forced: %6", _fog, _overcast, _rain, [_randomDirection,_randomWindStr], [_windValX,_windValY], _force];
