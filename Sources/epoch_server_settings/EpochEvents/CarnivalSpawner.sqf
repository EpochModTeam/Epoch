/*
  Carnival Event
	by Aaron Clark - EpochMod.com

	Improvements and or bugfixes and other contributions are welcome via the github:
	https://github.com/EpochModTeam/Epoch/tree/release/Sources/epoch_server_settings/EpochEvents/CarnivalSpawner.sqf
*/
//[[[cog import generate_private_arrays ]]]
private ["_ferrisPosition","_item","_markers"];
//[[[end]]]
_ferrisPosition = [epoch_centerMarkerPosition, 0, EPOCH_dynamicVehicleArea, 10, 0, 4000, 0] call BIS_fnc_findSafePos;
if ((count _ferrisPosition) == 2) then{
	_item = createVehicle["ferrisWheel_EPOCH", _ferrisPosition, [], 0.0, "CAN_COLLIDE"];

	{
		_item = createVehicle[_x, _ferrisPosition, [], 80, "NONE"];
		sleep 1;
	} forEach["Carnival_Tent", "Land_Slide_F", "Carnival_Tent", "Land_Carousel_01_F", "Carnival_Tent", "Carnival_Tent"];

	if (EPOCH_showShippingContainers) then{
		_markers = ["Carnival",_ferrisPosition] call EPOCH_server_createGlobalMarkerSet;
	};
};
