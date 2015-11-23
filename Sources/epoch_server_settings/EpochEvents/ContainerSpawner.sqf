/*
  Shipping Containter Event
	by Aaron Clark - EpochMod.com
	This work is licensed under a Creative Commons Attribution-NonCommercial-NoDerivatives 4.0 International License.
	http://creativecommons.org/licenses/by-nc-nd/4.0/
	Improvements and or bugfixes and other contributions are welcome via the github:
	https://github.com/EpochModTeam/Epoch/tree/master/Sources/epoch_server_settings/EpochEvents/ContainterSpawner.sqf
*/
private ["_marker","_item","_cargoPosition"];
_cargoPosition = [epoch_centerMarkerPosition, 0, EPOCH_dynamicVehicleArea, 10, 0, 4000, 1] call BIS_fnc_findSafePos;
if ((count _cargoPosition) == 2) then{
	_item = createVehicle["Cargo_Container", _cargoPosition, [], 0.0, "CAN_COLLIDE"];
	if (EPOCH_showShippingContainers) then{
		_marker = createMarker[str(_cargoPosition), _cargoPosition];
		_marker setMarkerShape "ICON";
		_marker setMarkerType "mil_dot";
		// _marker setMarkerText "Container";
		_marker setMarkerColor "ColorOrange";
	};
};
