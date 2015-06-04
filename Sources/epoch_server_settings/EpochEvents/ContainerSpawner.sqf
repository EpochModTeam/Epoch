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