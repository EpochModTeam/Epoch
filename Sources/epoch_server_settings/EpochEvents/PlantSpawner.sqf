/*
	Author/s:
		Redbeard Actual
		Aaron Clark - EpochMod.com

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
private ["_debug","_decayTime","_jammers","_marker","_nearbyLocations","_plant","_plantCount","_plants","_playersNearby","_position","_restricted","_scatter","_selectedLocation","_showPlantMarkers","_timeStamp"];
//[[[end]]]

// SET THIS TO TRUE TO GET MESSAGES IN LOG.
_debug = true;
_showPlantMarkers = true;

// select a plant type to spawn
_plant = selectRandom ["Goldenseal_EPOCH", "Goldenseal_EPOCH", "Goldenseal_EPOCH", "Poppy_EPOCH", "Pumpkin_EPOCH"];

// START PLANT PATCH SPAWN LIMIT CODE IF EPOCH_plantCounter HAS NOT BEEN INITIATED.
// THIS MAKES SURE IT ONLY DOES THIS BIT THE FIRST TIME THE EVENT RUNS.
if (isNil "EPOCH_plantCounter") then {
	//SET COUNTER TO ZERO.
	EPOCH_plantCounter = 0;
	//SET LIMIT TO FIVE.
	EPOCH_plantLimit = 5;
};

//STOP THE SCRIPT AND EXIT IF THE COUNTER IS TOO HIGH.
if (EPOCH_plantCounter >= EPOCH_plantLimit) exitWith {
	if (_debug) then {diag_log "DEBUG: suppressed plant spawn over limit"};
};

// FIND A POSITION FOR PLANT PATCH prefer Hills and Vineyards
_nearbyLocations = nearestLocations [epoch_centerMarkerPosition,["VegetationVineyard","Hill"],EPOCH_dynamicVehicleArea];
if (_nearbyLocations isEqualTo []) then {
	_position = [epoch_centerMarkerPosition, 0, EPOCH_dynamicVehicleArea, 10, 0, 4000, 0] call BIS_fnc_findSafePos;
} else {
	_selectedLocation = locationPosition (selectRandom _nearbyLocations);
	_position = [_selectedLocation, 0, 1000, 10, 0, 4000, 0] call BIS_fnc_findSafePos;
};

//CHECK FOR PROTECTED AREA WITIN 2000 METERS.
_restricted = nearestObjects [_position, ["ProtectionZone_Invisible_F"], 2000];
if(count _restricted > 0) exitWith {
	if (_debug) then {diag_log "DEBUG: suppressed PLANT PATCH spawn TRADER too close"};
};

//CHECK FOR JAMMERS IN THE AREA WITHIN 1000 METERS.
_jammers = nearestObjects[_position, ["PlotPole_EPOCH"], 1000];
if(count _jammers > 0) exitWith {
	if (_debug) then {diag_log "DEBUG: suppressed PLANT PATCH spawn jammer too close"};
};

//CHECK TO SEE IF PLAYERS WITHIN 900 METERS.
_playersNearby = _position nearEntities[["Epoch_Male_F", "Epoch_Female_F"], 900];
if(count _playersNearby > 0) exitWith {
	if (_debug) then {diag_log "DEBUG: suppressed PLANT PATCH spawn PLAYER too close"};
};

// IF WE MADE IT THIS FAR, WE CAN SPAWN SOME SHIT.
if ((count _position) == 2) then{

	// vary plant count and scatter by plant type
	_plantCount = 1;
	_scatter = 10;
	_decayTime = 1200;
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
	for "_i" from 1 to _plantCount step 1 do  {
		_plants pushBack createVehicle[_plant, _position, [], _scatter, "NONE"];
	};
	_timeStamp = diag_tickTime;

	// SET UP THE MARKER.
	if (_showPlantMarkers) then{
		_marker = createMarker[str(_position), _position];
		_marker setMarkerShape "ICON";
		_marker setMarkerType "waypoint";
		_marker setMarkerColor "ColorGreen";
	};

	// TICK COUNTER + 1 SPAWNED PLANT PATCH.
	EPOCH_plantCounter = EPOCH_plantCounter + 1;

	// wait loop to handle plant patch
	while {true} do {
		private _plantsLeft = _plants select {!isNull _x};
		// Wait for all plants to be picked or to decay
		if (_plantsLeft isEqualTo [] || (diag_tickTime - _timeStamp) > _decayTime) exitWith {
			// TICK THE COUNTER DOWN SO A NEW PLANT PATCH WILL SPAWN TO TAKE ITS PLACE.
			EPOCH_plantCounter = EPOCH_plantCounter - 1;
			// DELETE THAT MARKER.
			if (_showPlantMarkers) then{
				deleteMarker _marker;
			};
			// remove any left over "dead" plants (only if decayTime is reached)
			{deleteVehicle _x} forEach _plantsLeft;
		};
		// set marker to brown to show 50% decay but not if already marked as picked (red).
		if !(getMarkerColor _marker in ["ColorRed","ColorBrown"]) then {
			if ((diag_tickTime - _timeStamp) > (_decayTime/2)) then {
				_marker setMarkerColor "ColorBrown";
			};
		};
		// WAIT FOR A PLAYER TO Pick one plant then set marker to red
		if (count _plantsLeft != _plantCount) then {
			if (_showPlantMarkers) then{
				if (getMarkerColor _marker != "ColorRed") then {
					_marker setMarkerColor "ColorRed";
				};
			};
		};
		sleep 30;
	};
};
// END SCRIPT.
