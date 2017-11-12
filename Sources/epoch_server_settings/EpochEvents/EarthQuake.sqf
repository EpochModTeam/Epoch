/*
	Earthquake and Mineral Deposit Event
	by Aaron Clark - EpochMod.com
	
	Events Overhaul by DirtySanchez
	
	Improvements and or bugfixes and other contributions are welcome via the github:
	https://github.com/EpochModTeam/Epoch/tree/release/Sources/epoch_server_settings/EpochEvents/Earthquake.sqf
*/
//[[[cog import generate_private_arrays ]]]
private ["_cfgEpoch", "_debug", "_limit", "_counter", "_others", "_distFromOthers", "_position", "_goodPos", "_playersNearEpicenter", "_chance", "_minerals", "_item", "_debugMkr", "_markers", "_originalColors", "_showMarkers", "_decayMarkerColor", "_compromisedColor", "_spawned", "_decayTime", "_rEvents", "_thisEvent"];
//[[[end]]]
_cfgEpoch = configFile >> "CfgEpoch" >> worldname;
_debug = if(getNumber(_cfgEpoch >> "debugEarthquakeSpawner") isEqualTo 1)then{true}else{false};
_limit = getNumber(_cfgEpoch >> "maxEarthquakeSpawns");
_counter = missionNameSpace getVariable["EPOCH_earthquakeCounter",0];
_others = missionNameSpace getVariable["EPOCH_earthquakes", [[0,0,0]] ];
_distFromOthers = getNumber(_cfgEpoch >> "distFromOtherEarthquakes");

//STOP THE SCRIPT AND EXIT IF THE COUNTER IS TOO HIGH.
if (_counter >= _limit) exitWith {
	if (_debug) then {diag_log "DEBUG: suppressed EARTHQUAKE spawn over limit"};
};

for "_i" from 0 to 100 step 1 do {
	_position = [epoch_centerMarkerPosition, 0, EPOCH_dynamicVehicleArea, 10, 0, 1000, 0] call BIS_fnc_findSafePos;
	_goodPos = true;
	
	_goodPos = [_position, true, true, false, _others, _distFromOthers] call EPOCH_server_isNearChecks;
	
	if(_goodPos)then{
		_i = 100;
	}else{
		_position = [];
	};
};

if ((count _position) == 2) then{
	_playersNearEpicenter = _position nearEntities[["Epoch_Male_F", "Epoch_Female_F"], 1000];
	// decrease chance with more players
	_chance = linearConversion [1, 100, (count allPlayers), 0, 0.5, true];
	if ((random 1) > _chance) then {

		if !(_playersNearEpicenter isEqualTo[]) then{
			// send earthquake to each player in zone
			[_position] remoteExec ['EPOCH_client_earthQuake',_playersNearEpicenter];
		};

		// Mineral veins
		_minerals = getArray(_cfgEpoch >> "availableMinerals");
		_item = createVehicle[(selectRandom _minerals), _position, [], 0.0, "CAN_COLLIDE"];
		if(_debug)then{
			_debugMkr = createMarker [str(_position), _position];
			_debugMkr setMarkerShape "ICON";
			_debugMkr setMarkerType "mil_dot";
			_debugMkr setMarkerColor "ColorRed";
		};
		
		// Place markers and get decay, compromised and original colors
		_markers = [];
		_originalColors = [];
		_showMarkers = if(getNumber(_cfgEpoch >> "showEarthquakeMarkers") isEqualTo 1)then{true}else{false};
		_decayMarkerColor = getText(_cfgEpoch >> "earthquakeDecayMarkerColor");
		_compromisedColor = getText(_cfgEpoch >> "earthquakeCompromisedColor");
		if (_showMarkers) then{
			_markers = ["EarthQuake",_position] call EPOCH_server_createGlobalMarkerSet;
			{
				_originalColors pushBack (getMarkerColor _x);
			}forEach _markers;
			
			// Check for HeightenedPlayerVsPlayer false and remove comprimised coloring
			if!(getNumber(_cfgEpoch >> "HeightenedPlayerVsPlayer") isEqualTo 1)then{
				_compromisedColor = getMarkerColor (_markers select 0);
			};
		};
		
		// Tick Counter +1
		_counter = _counter + 1;
		missionNameSpace setVariable["EPOCH_earthquakeCounter",_counter];
		
		// ADD POSITION TO OTHERS ARRAY
		missionNameSpace setVariable["EPOCH_earthquakes", _others + [_position]];

		// SEND EVENT TO MONITOR
		_decayTime = getNumber(_cfgEpoch >> "earthquakeDecayTime");
		_serverSettingsConfig = configFile >> "CfgEpochServer";
		_timeMultiplier = ([_serverSettingsConfig, "timeMultiplier", 1] call EPOCH_fnc_returnConfigEntry);
		_rEvents = missionNameSpace getVariable["EPOCH_RunningEvents",[]];
		_thisEvent = [_position, [_item], [], "earthquakeCounter", diag_tickTime, (_decayTime * _timeMultiplier), _showMarkers, _markers, _originalColors, _decayMarkerColor, _compromisedColor];
		missionNameSpace setVariable["EPOCH_RunningEvents",_rEvents + [_thisEvent]];
		if (_debug) then {
			diag_log format["EPOCHDebug: earthquakeSpawner-%1",  missionNameSpace getVariable["EPOCH_RunningEvents",[]]];
		};
	};
};
