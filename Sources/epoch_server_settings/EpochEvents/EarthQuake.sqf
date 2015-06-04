
_position = [epoch_centerMarkerPosition, 0, EPOCH_dynamicVehicleArea, 10, 0, 1000, 0] call BIS_fnc_findSafePos;
if ((count _position) == 2) then{
	_plyrsNearEpicenter = _position nearEntities[["Epoch_Male_F", "Epoch_Female_F"], 1000];
	if !(_plyrsNearEpicenter isEqualTo[]) then{

		if ((random 1) > 0.5) then{
			// send earthquake to each player in zone
			{
				[["earthQuake", _position], (owner _x)] call EPOCH_sendPublicVariableClient;
			}forEach _plyrsNearEpicenter;
			_minerals = ["MineralDepositCopper_EPOCH", "MineralDepositGold_EPOCH", "MineralDepositSilver_EPOCH"];
			_randomIndex = floor(random(count _minerals));
			_item = createVehicle[(_minerals select _randomIndex), _position, [], 0.0, "CAN_COLLIDE"];
			if (EPOCH_showEarthQuakes) then{
				_marker = createMarker[str(_position), _position];
				_marker setMarkerShape "ICON";
				_marker setMarkerType "mil_dot";
				// _marker setMarkerText "Mineral";
				_marker setMarkerColor "ColorGrey";
			};
		};
	};
};