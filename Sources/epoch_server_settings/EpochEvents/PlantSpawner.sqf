/*
	Author/s:
		Redbeard Actual
		Aaron Clark - EpochMod.com

	Events Overhaul by DirtySanchez
	
	Description:
		Improved Plant Spawner - Plant Patch Spawner
		Event spawns a random number of plants based on plant type.
		Prefers "Hill" locations and restricts Jammers and Protected Trader Zones.
		Plants now decay after 20 minutes and marker will change to brown at 50%.
		Plant patch marker will turn red after one plant is picked
		Plants and marker will cleanup after all plants in a patch are picked or die due to decay.

	Improvements and or bugfixes and other contributions are welcome via the github:
	https://github.com/EpochModTeam/Epoch/tree/release/Sources/epoch_server_settings/EpochEvents/PlantSpawner.sqf
*/
//[[[cog import generate_private_arrays ]]]
private ["_cfgEpoch", "_debug", "_limit", "_counter", "_others", "_distFromOthers", "_nearbyLocations", "_position", "_selectedLocation", "_goodPos", "_plantsArray", "_plant", "_plantCount", "_scatter", "_plants", "_plantPos", "_debugMkr", "_markers", "_originalColors", "_showMarkers", "_decayMarkerColor", "_compromisedColor", "_decayTime", "_serverSettingsConfig", "_timeMultiplier", "_rEvents","_thisEvent"];
//[[[end]]]
_cfgEpoch = configFile >> "CfgEpoch" >> worldname;
_debug = if(getNumber(_cfgEpoch >> "debugPlantSpawner") isEqualTo 1)then{true}else{false};
_limit = getNumber(_cfgEpoch >> "maxPlantSpawns");
_counter = missionNameSpace getVariable["EPOCH_plantCounter",0];
_others = missionNameSpace getVariable["EPOCH_plants", [[0,0,0]] ];
_distFromOthers = getNumber(_cfgEpoch >> "distFromOtherPlants");

//STOP THE SCRIPT AND EXIT IF THE COUNTER IS TOO HIGH.
if (_counter >= _limit) exitWith {
	if (_debug) then {diag_log "DEBUG: suppressed plant spawn over limit"};
};

// FIND A POSITION FOR PLANT PATCH prefer Hills and Vineyards
_nearbyLocations = nearestLocations [epoch_centerMarkerPosition,["VegetationVineyard","Hill"],EPOCH_dynamicVehicleArea];
for "_i" from 0 to 100 step 1 do {
	if (_nearbyLocations isEqualTo []) then {
		_position = [epoch_centerMarkerPosition, 0, EPOCH_dynamicVehicleArea, 10, 0, 4000, 0] call BIS_fnc_findSafePos;
	} else {
		_selectedLocation = locationPosition (selectRandom _nearbyLocations);
		_position = [_selectedLocation, 0, 1000, 10, 0, 4000, 0] call BIS_fnc_findSafePos;
	};
	_goodPos = true;
	
	_goodPos = [_position, true, true, true, _others, _distFromOthers] call EPOCH_server_isNearChecks;

	if(_goodPos)then{
		_i = 100;
	}else{
		_position = [];
	};
};

// IF WE MADE IT THIS FAR, WE CAN SPAWN SOME SHIT.
if ((count _position) == 2) then{
	// select a plant type to spawn
	_plantsArray = getArray(_cfgEpoch >> "availablePlants");
	_plant = selectRandom _plantsArray;
	
	// vary plant count and scatter by plant type
	_plantCount = (floor(random(2)));
	_scatter = 10;
	switch _plant do {
		case "Goldenseal_EPOCH": {
			_plantCount = (floor(random(4)))+3;
			_scatter = 10;
		};
		case "Poppy_EPOCH": {
			_plantCount = (floor(random(2)))+3;
			_scatter = 15;
		};
		case "Pumpkin_EPOCH": {
			_plantCount = (floor(random(3)))+5;
			_scatter = 20;
		};
	};

	_plants = [];
	// CREATE THE PATCH OF PLANTS.
	for "_i" from 0 to (_plantCount - 1) step 1 do  {
		_plants pushBack createVehicle[_plant, _position, [], _scatter, "NONE"];
		if(_debug)then{
			_plantPos = getPosATL (_plants select _i);
			_debugMkr = createMarker [str(_plantPos), _plantPos];
			_debugMkr setMarkerShape "ICON";
			_debugMkr setMarkerType "mil_dot";
			_debugMkr setMarkerColor "ColorRed";
		};
	};

	// SET UP THE MARKER.
	_markers = [];
	_originalColors = [];
	_showMarkers = if(getNumber(_cfgEpoch >> "showPlantMarkers") isEqualTo 1)then{true}else{false};
	_decayMarkerColor = getText(_cfgEpoch >> "plantDecayMarkerColor");
	_compromisedColor = getText(_cfgEpoch >> "plantCompromisedColor");
	if (_showMarkers) then{
		_markers = ["PlantSpawn",_position] call EPOCH_server_createGlobalMarkerSet;
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
	missionNameSpace setVariable["EPOCH_plantCounter",_counter];
	
	// ADD POSITION TO OTHERS ARRAY
	missionNameSpace setVariable["EPOCH_plants", _others + [_position]];
	
	// SEND EVENT TO MONITOR
	_decayTime = getNumber(_cfgEpoch >> "plantDecayTime");
	_serverSettingsConfig = configFile >> "CfgEpochServer";
	_timeMultiplier = ([_serverSettingsConfig, "timeMultiplier", 1] call EPOCH_fnc_returnConfigEntry);
	_rEvents = missionNameSpace getVariable["EPOCH_RunningEvents",[]];
	_thisEvent = [_position, _plants, [], "plantCounter", diag_tickTime, (_decayTime * _timeMultiplier), _showMarkers, _markers, _originalColors, _decayMarkerColor, _compromisedColor];
	missionNameSpace setVariable["EPOCH_RunningEvents",_rEvents + [_thisEvent]];
	if (_debug) then {
		diag_log format["EPOCHDebug: plantSpawner-EPOCH_PlantSpawns:%1",  missionNameSpace getVariable["EPOCH_RunningEvents",[]]];
	};
};
// END SCRIPT.