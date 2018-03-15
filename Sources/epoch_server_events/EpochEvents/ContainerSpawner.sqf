/*
  Shipping Containter Event
	by Aaron Clark - EpochMod.com

	Improvements and or bugfixes and other contributions are welcome via the github:
	https://github.com/EpochModTeam/Epoch/tree/release/Sources/epoch_server_settings/EpochEvents/ContainterSpawner.sqf
*/
//[[[cog import generate_private_arrays ]]]
private ["_cfgEpoch", "_debug", "_limit", "_counter", "_others", "_distFromOthers", "_position", "_goodPos", "_item", "_debugMkr", "_markers", "_originalColors", "_showMarkers", "_decayMarkerColor", "_compromisedColor", "_decayTime", "_serverSettingsConfig", "_timeMultiplier", "_rEvents", "_thisEvent"];
//[[[end]]]
_cfgEpoch = configFile >> "CfgEpoch" >> worldname;
_debug = if(getNumber(_cfgEpoch >> "debugContainerSpawner") isEqualTo 1)then{true}else{false};
_limit = getNumber(_cfgEpoch >> "maxContainerSpawns");
_counter = missionNameSpace getVariable["EPOCH_containerCounter",0];
_others = missionNameSpace getVariable["EPOCH_containers", [[0,0,0]] ];
_distFromOthers = getNumber(_cfgEpoch >> "distFromOtherContainers");

//STOP THE SCRIPT AND EXIT IF THE COUNTER IS TOO HIGH.
if (_counter >= _limit) exitWith {
	if (_debug) then {diag_log "DEBUG: suppressed CONTAINER spawn over limit"};
};

// FIND A POSITION
for "_i" from 0 to 100 step 1 do {
	_position = [epoch_centerMarkerPosition, 0, EPOCH_dynamicVehicleArea, 10, 0, 4000, 1] call BIS_fnc_findSafePos;
	_goodPos = true;
	
	_goodPos = [_position, true, true, true, _others, _distFromOthers] call EPOCH_server_isNearChecks;
	
	if(_goodPos)then{
		_i = 100;
	}else{
		_position = [];
	};
};

if ((count _position) == 2) then{
	// CREATE THE CARGO CONTAINER
	_item = createVehicle["Cargo_Container", _position, [], 0.0, "CAN_COLLIDE"];
	if(_debug)then{
		_debugMkr = createMarker [str(_position), _position];
		_debugMkr setMarkerShape "ICON";
		_debugMkr setMarkerType "mil_dot";
		_debugMkr setMarkerColor "ColorRed";
	};
	
	// SET UP THE MARKER.
	_markers = [];
	_originalColors = [];
	_showMarkers = if(getNumber(_cfgEpoch >> "showContainerMarkers") isEqualTo 1)then{true}else{false};
	_decayMarkerColor = getText(_cfgEpoch >> "containerDecayMarkerColor");
	_compromisedColor = getText(_cfgEpoch >> "containerCompromisedColor");
	if (_showMarkers) then{
		_markers = ["Container",_position] call EPOCH_server_createGlobalMarkerSet;
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
	missionNameSpace setVariable["EPOCH_containerCounter",_counter];
	
	// ADD POSITION TO OTHERS ARRAY
	missionNameSpace setVariable["EPOCH_containers", _others + [_position]];
	
	// SEND EVENT TO MONITOR
	_decayTime = getNumber(_cfgEpoch >> "containerDecayTime");
	_serverSettingsConfig = configFile >> "CfgEpochServer";
	_timeMultiplier = ([_serverSettingsConfig, "timeMultiplier", 1] call EPOCH_fnc_returnConfigEntry);
	_rEvents = missionNameSpace getVariable["EPOCH_RunningEvents",[]];
	_thisEvent = [_position, [_item], [], "containerCounter", diag_tickTime, (_decayTime * _timeMultiplier), _showMarkers, _markers, _originalColors, _decayMarkerColor, _compromisedColor];
	missionNameSpace setVariable["EPOCH_RunningEvents",_rEvents + [_thisEvent]];
	if (_debug) then {
		diag_log format["EPOCHDebug: containerSpawner-%1",  missionNameSpace getVariable["EPOCH_RunningEvents",[]]];
	};
};
// END SCRIPT.