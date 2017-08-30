/*
	Crashed Satellite Event
	by Aaron Clark - EpochMod.com

	Improvements and or bugfixes and other contributions are welcome via the github:
	https://github.com/EpochModTeam/Epoch/tree/release/Sources/epoch_server_settings/EpochEvents/Satellite.sqf
*/
//[[[cog import generate_private_arrays ]]]
private ["_item","_marker","_playersNearEpicenter","_position","_satellites"];
//[[[end]]]
_position = [epoch_centerMarkerPosition, 0, EPOCH_dynamicVehicleArea, 10, 0, 1000, 0] call BIS_fnc_findSafePos;
if ((count _position) == 2) then{
	_playersNearEpicenter = _position nearEntities[["Epoch_Male_F", "Epoch_Female_F"], 1000];

	// todo send shockwave + effects to each player in zone
	/*
	if !(_playersNearEpicenter isEqualTo[]) then{
		// todo add shockwave effects script
		[_position] remoteExec ['EPOCH_client_earthQuake',_playersNearEpicenter];
	};
	*/

	// Satellite classes
	_satellites = ["Land_Wreck_Satellite_EPOCH"];

	_item = createVehicle[(selectRandom _satellites), _position, [], 0.0, "CAN_COLLIDE"];

	if (EPOCH_showSatellites) then{
		_marker = createMarker[str(_position), _position];
		_marker setMarkerShape "ICON";
		_marker setMarkerType "hd_warning";
		// _marker setMarkerText "Satellite";
		_marker setMarkerColor "ColorGreen";
	};
};
