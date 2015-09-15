closeDialog 0;
if (!isNull cursorTarget) then {
	_vehicles = player nearEntities[["LandVehicle", "Ship", "Air", "Tank"], 6];
	if (cursorTarget in _vehicles) then {
		player action["Gear", cursorTarget];
	};
};