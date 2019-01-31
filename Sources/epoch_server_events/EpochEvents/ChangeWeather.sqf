
private ["_Changetime","_randomNightTemp","_randomNightRainTemp","_randomDayTemp","_randomDayRainTemp","_WeatherSettings","_selectedweather","_temp"];

_Changetime = 120;
_randomNightTemp = [-5,50,85];
_randomNightRainTemp = [-10,50,70];
_randomDayTemp = [20,75,100];
_randomDayRainTemp = [15,75,85];
_WeatherSettings = [
	[// Sun
		[0, 0.2, 5],	// Fog
		0.2,			// Overcast
		0.2,			// Waves
		0.25,			// Wind
		0.1,			// Gust
		0,				// Rain
		0,				// Lightnings
		0				// Rainbow
	],
	[// Mid
		[0.05, 0.1, 5],
		0.5,
		0.4,
		0.25,
		0.3,
		0.1,
		0.1,
		1
	],
	[// Rain
		[0.1, 0.2, 5],
		0.7,
		0.5,
		0.25,
		0.5,
		0.3,
		0.5,
		0.5
	],
	[// Rain+
		[0.15, 0.2, 5],
		1,
		1,
		0.25,
		0.5,
		1,
		1,
		0.5
	]
];

_selectedweather = _WeatherSettings selectRandomWeighted EPOCH_WeatherChances;
_selectedweather params ["_fog","_overcast","_waves","_windstr","_gusts","_rain","_lightnings","_rainbow"];

// cooler at night / rain
if (_rain > 0.1) then {
    _randomNightTemp = _randomNightRainTemp;
    _randomDayTemp = _randomDayRainTemp;
};
_temp = if (sunOrMoon < 1) then {random _randomNightTemp} else {random _randomDayTemp};
_temp = round _temp;
// push temp to all players and JIP.
missionNamespace setVariable ["EPOCH_CURRENT_WEATHER",_temp, true];

_Changetime setFog _fog;
_Changetime setOvercast _overcast;
_Changetime setWaves _waves;
_Changetime setWindStr _windstr;
_Changetime setGusts _gusts;
_Changetime setRain _rain;
_Changetime setLightnings _lightnings;
_Changetime setRainbow _rainbow;

diag_log format["Epoch: Weather Change - temp: %1 | fog: %2 | overcast: %3 | waves: %4 | windstr: %5 | gusts: %6 | rain: %7 | Lightnings: %8 | rainbow: %9",_temp, _fog, _overcast, _waves, _windstr, _gusts, _rain, _lightnings, _rainbow];

