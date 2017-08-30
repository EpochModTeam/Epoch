/*
  Earthquake and Mineral Deposit Event
	by Aaron Clark - EpochMod.com

	Improvements and or bugfixes and other contributions are welcome via the github:
	https://github.com/EpochModTeam/Epoch/tree/release/Sources/epoch_server_settings/EpochEvents/Earthquake.sqf
*/
//[[[cog import generate_private_arrays ]]]
private ["_chance","_item","_marker","_minerals","_playersNearEpicenter","_position"];
//[[[end]]]
_position = [epoch_centerMarkerPosition, 0, EPOCH_dynamicVehicleArea, 10, 0, 1000, 0] call BIS_fnc_findSafePos;
if ((count _position) == 2) then{
	_playersNearEpicenter = _position nearEntities[["Epoch_Male_F", "Epoch_Female_F"], 1000];
	// decrease chance with more players
	_chance = linearConversion [1, 100, (count allPlayers), 0, 0.5, true];
	if ((random 1) > _chance) then {

		if !(_playersNearEpicenter isEqualTo[]) then{
			// send earthquake to each player in zone
			[_position] remoteExec ['EPOCH_client_earthQuake',_playersNearEpicenter];
		};

		// Mineral veins
		_minerals = ["MineralDepositCopper_EPOCH", "MineralDepositGold_EPOCH", "MineralDepositSilver_EPOCH"];
		_item = createVehicle[(selectRandom _minerals), _position, [], 0.0, "CAN_COLLIDE"];
		if (EPOCH_showEarthQuakes) then{
			_marker = createMarker[str(_position), _position];
			_marker setMarkerShape "ICON";
			_marker setMarkerType "hd_objective";
			// _marker setMarkerText "Mineral";
			_marker setMarkerColor "ColorGrey";
		};
	};
};
