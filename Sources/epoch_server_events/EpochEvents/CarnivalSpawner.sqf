/*
  Carnival Event
	by Aaron Clark - EpochMod.com

	Improvements and or bugfixes and other contributions are welcome via the github:
	https://github.com/EpochModTeam/Epoch/tree/release/Sources/epoch_server_settings/EpochEvents/CarnivalSpawner.sqf
*/
//[[[cog import generate_private_arrays ]]]
private ["_cfgEpoch", "_debug", "_showMarkers", "_limit", "_counter", "_others", "_distFromOthers", "_position", "_goodPos", "_objs","_item", "_lootPos", "_loot", "_debugMkr", "_markers", "_originalColors", "_decayMarkerColor", "_compromisedColor", "_decayTime", "_serverSettingsConfig", "_timeMultiplier", "_rEvents", "_thisEvent"];
//[[[end]]]
_cfgEpoch = configFile >> "CfgEpoch" >> worldname;
_debug = if(getNumber(_cfgEpoch >> "debugCarnivalSpawner") isEqualTo 1)then{true}else{false};
_limit = getNumber(_cfgEpoch >> "maxCarnivalSpawns");
_counter = missionNameSpace getVariable["EPOCH_carnivalCounter",0];
_others = missionNameSpace getVariable["EPOCH_carnivals", [[0,0,0]] ];
_distFromOthers = getNumber(_cfgEpoch >> "distFromOtherCarnivals");

//STOP THE SCRIPT AND EXIT IF THE COUNTER IS TOO HIGH.
if (_counter >= _limit) exitWith {
	if (_debug) then {diag_log "DEBUG: suppressed carnival spawn over limit"};
};

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

_objs = [];
if ((count _position) == 2) then{
	// CREATE THE CARNIVAL AREA AND LOOT
	_item = createVehicle["ferrisWheel_EPOCH", _position, [], 0.0, "CAN_COLLIDE"];
	_objs pushBack _item;
	_lootPos = [_position,1,20,3,1,20,0] call BIS_fnc_findSafePos;
	_loot = createVehicle["container_epoch", _lootPos, [], 0.0, "CAN_COLLIDE"];
	_loot setMass 220;
	_loot setVariable["EPOCH_Loot",false,true];
	
	if(_debug)then{
		_debugMkr = createMarker [str(_lootPos),_lootPos];
		_debugMkr setMarkerShape "ICON";
		_debugMkr setMarkerType "mil_dot";
		_debugMkr setMarkerColor "ColorRed";
	};
	
	{
		_item = createVehicle[_x, _position, [], 80, "NONE"];
		_objs pushBack _item;
		sleep 1;
	} forEach (getArray(_cfgEpoch >> "carnivalSpawnedObjects"));
	
	// SET UP THE MARKER.
	_markers = [];
	_originalColors = [];
	_showMarkers = if(getNumber(_cfgEpoch >> "showCarnivalMarkers") isEqualTo 1)then{true}else{false};
	_decayMarkerColor = getText(_cfgEpoch >> "carnivalDecayMarkerColor");
	_compromisedColor = getText(_cfgEpoch >> "carnivalCompromisedColor");
	if (_showMarkers) then{
		_markers = ["Carnival",_position] call EPOCH_server_createGlobalMarkerSet;
		{
			_originalColors pushBack (getMarkerColor _x);
		}forEach _markers;
		
		// Check for HeightenedPlayerVsPlayer false and remove comprimised coloring
		if!(getNumber(_cfgEpoch >> "HeightenedPlayerVsPlayer") isEqualTo 1)then{
			_compromisedColor = getMarkerColor (_markers select 0);
		};
	};
	
	// TICK COUNTER + 1 SPAWNED PLANT PATCH.
	_counter = _counter + 1;
	missionNameSpace setVariable["EPOCH_carnivalCounter",_counter];
	
	// ADD POSITION TO OTHERS ARRAY
	missionNameSpace setVariable["EPOCH_carnivals", _others + [_position]];
	
	// SEND EVENT TO MONITOR
	_decayTime = getNumber(_cfgEpoch >> "carnivalDecayTime");
	_serverSettingsConfig = configFile >> "CfgEpochServer";
	_timeMultiplier = ([_serverSettingsConfig, "timeMultiplier", 1] call EPOCH_fnc_returnConfigEntry);
	_rEvents = missionNameSpace getVariable["EPOCH_RunningEvents",[]];
	_thisEvent = [_lootPos, [_loot], _objs,"carnivalCounter", diag_tickTime, (_decayTime * _timeMultiplier), _showMarkers, _markers, _originalColors, _decayMarkerColor, _compromisedColor];
	missionNameSpace setVariable["EPOCH_RunningEvents",_rEvents + [_thisEvent]];
	if (_debug) then {
		diag_log format["EPOCHDebug: carnivalSpawner-%1",  missionNameSpace getVariable["EPOCH_RunningEvents",[]]];
	};
};
