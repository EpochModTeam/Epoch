/*
	Crashed Satellite Event
	by Aaron Clark - EpochMod.com

	Improvements and or bugfixes and other contributions are welcome via the github:
	https://github.com/EpochModTeam/Epoch/tree/release/Sources/epoch_server_settings/EpochEvents/Satellite.sqf
*/
//[[[cog import generate_private_arrays ]]]
private ["_satellite","_markers","_playersNearEpicenter","_position","_satellites"];
//[[[end]]]
_position = [epoch_centerMarkerPosition, 0, EPOCH_dynamicVehicleArea, 10, 0, 1000, 0] call BIS_fnc_findSafePos;
if ((count _position) == 2) then{

	// spawn Satellite
	_satellites = ["Land_Wreck_Satellite_EPOCH"];
	_satellite = createVehicle[(selectRandom _satellites), _position, [], 0.0, "CAN_COLLIDE"];

	// send shockwave + effects to each player in zone at time of crash
	_playersNearEpicenter = _position nearEntities[["Epoch_Male_F", "Epoch_Female_F"], 1000];
	if !(_playersNearEpicenter isEqualTo[]) then{
		[_satellite, -1, 0.8, false] remoteExec ['BIS_fnc_sandstorm',_playersNearEpicenter];
	};

	// set rads
	_satellite setVariable ["EPOCH_Rads", [30,50], true]; //30 rads within 50 meters

	if (EPOCH_showSatellites) then{
		_markers = ["Satellite",_position] call EPOCH_server_createGlobalMarkerSet;
	};
};
