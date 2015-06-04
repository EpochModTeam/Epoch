_plantPosition = [epoch_centerMarkerPosition, 0, EPOCH_dynamicVehicleArea, 10, 0, 4000, 0] call BIS_fnc_findSafePos;
if ((count _plantPosition) == 2) then{

	_plants = ["Goldenseal_EPOCH", "Poppy_EPOCH", "Pumpkin_EPOCH"];
	_plant = _plants select(floor random(count _plants));

	_item = createVehicle[_plant, _plantPosition, [], 0.0, "CAN_COLLIDE"];
	if (EPOCH_showShippingContainers) then{
		_displayName = getText(configfile >> "CfgVehicles" >> typeOf _item >> "DisplayName");
		_marker = createMarker[str(_plantPosition), _plantPosition];
		_marker setMarkerShape "ICON";
		_marker setMarkerType "mil_triangle";
		// _marker setMarkerText _displayName;
		_marker setMarkerColor "ColorGreen";
	};

};