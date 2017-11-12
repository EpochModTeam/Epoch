/*
	Crashed Satellite Event
	by Aaron Clark - EpochMod.com

	Improvements and or bugfixes and other contributions are welcome via the github:
	https://github.com/EpochModTeam/Epoch/tree/release/Sources/epoch_server_settings/EpochEvents/Satellite.sqf
*/
//[[[cog import generate_private_arrays ]]]
private ["_satellite","_markers","_playersNearEpicenter","_position","_satellites"];
//[[[end]]]
_cfgEpoch = configFile >> "CfgEpoch" >> worldname;
_debug = if(getNumber(_cfgEpoch >> "debugSatelliteSpawner") isEqualTo 1)then{true}else{false};
_limit = getNumber(_cfgEpoch >> "maxSatelliteSpawns");
_counter = missionNameSpace getVariable["EPOCH_satelliteCounter",0];
_others = missionNameSpace getVariable["EPOCH_satellites", [[0,0,0]] ];
_distFromOthers = getNumber(_cfgEpoch >> "distFromOtherSatellites");

//STOP THE SCRIPT AND EXIT IF THE COUNTER IS TOO HIGH.
if (_counter >= _limit) exitWith {
	if (_debug) then {diag_log "DEBUG: suppressed SATELLITE spawn over limit"};
};

// FIND A POSITION
for "_i" from 0 to 100 step 1 do {
	_position = [epoch_centerMarkerPosition, 0, EPOCH_dynamicVehicleArea, 10, 0, 1000, 0] call BIS_fnc_findSafePos;
	_goodPos = true;
	
	_goodPos = [_position, true, true, true, _others, _distFromOthers] call EPOCH_server_isNearChecks;
	
	if(_goodPos)then{
		_i = 100;
	}else{
		_position = [];
	};
};

if ((count _position) == 2) then{
	// select a Satellite type to spawn
	_satellites = getArray(_cfgEpoch >> "availableSatellites");
	_satellite = createVehicle[(selectRandom _satellites), _position, [], 0.0, "CAN_COLLIDE"];
	if(_debug)then{
		_debugMkr = createMarker [str(_position), _position];
		_debugMkr setMarkerShape "ICON";
		_debugMkr setMarkerType "mil_dot";
		_debugMkr setMarkerColor "ColorRed";
	};
	
	// SET UP THE MARKER.
	_markers = [];
	_originalColors = [];
	_showMarkers = if(getNumber(_cfgEpoch >> "showSatelliteMarkers") isEqualTo 1)then{true}else{false};
	_decayMarkerColor = getText(_cfgEpoch >> "satelliteDecayMarkerColor");
	_compromisedColor = getText(_cfgEpoch >> "satelliteCompromisedColor");
	if (_showMarkers) then{
		_markers = ["Satellite",_position] call EPOCH_server_createGlobalMarkerSet;
		{
			_originalColors pushBack (getMarkerColor _x);
		}forEach _markers;
		
		// Check for HeightenedPlayerVsPlayer false and remove comprimised coloring
		if!(getNumber(_cfgEpoch >> "HeightenedPlayerVsPlayer") isEqualTo 1)then{
			_compromisedColor = getMarkerColor (_markers select 0);
		};
	};
	
	// TICK COUNTER + 1
	_counter = _counter + 1;
	missionNameSpace setVariable["EPOCH_satelliteCounter",_counter];
	
	// ADD POSITION TO OTHERS ARRAY
	missionNameSpace setVariable["EPOCH_satellites", _others + [_position]];
	
	// SEND EVENT TO MONITOR
	_decayTime = getNumber(_cfgEpoch >> "satelliteDecayTime");
	_serverSettingsConfig = configFile >> "CfgEpochServer";
	_timeMultiplier = ([_serverSettingsConfig, "timeMultiplier", 1] call EPOCH_fnc_returnConfigEntry);
	_rEvents = missionNameSpace getVariable["EPOCH_RunningEvents",[]];
	_thisEvent = [_position, [_satellite], [], "satelliteCounter", diag_tickTime, (_decayTime * _timeMultiplier), _showMarkers, _markers, _originalColors, _decayMarkerColor, _compromisedColor];
	missionNameSpace setVariable["EPOCH_RunningEvents",_rEvents + [_thisEvent]];
	if (_debug) then {
		diag_log format["EPOCHDebug: satelliteSpawner-%1",  missionNameSpace getVariable["EPOCH_RunningEvents",[]]];
	};
};
// END SCRIPT.