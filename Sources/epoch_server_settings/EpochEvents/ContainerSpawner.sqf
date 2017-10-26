/*
  Shipping Containter Event
	by Aaron Clark - EpochMod.com

	Improvements and or bugfixes and other contributions are welcome via the github:
	https://github.com/EpochModTeam/Epoch/tree/release/Sources/epoch_server_settings/EpochEvents/ContainterSpawner.sqf
*/
//[[[cog import generate_private_arrays ]]]
private ["_cargoPosition","_item","_markers"];
//[[[end]]]
_cargoPosition = [epoch_centerMarkerPosition, 0, EPOCH_dynamicVehicleArea, 10, 0, 4000, 1] call BIS_fnc_findSafePos;
if ((count _cargoPosition) == 2) then{
	_item = createVehicle["Cargo_Container", _cargoPosition, [], 0.0, "CAN_COLLIDE"];
	if (EPOCH_showShippingContainers) then{
		_markers = ["Container",_cargoPosition] call EPOCH_server_createGlobalMarkerSet;
	};
};
