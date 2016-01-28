/*
  Earthquake and Mineral Deposit Event
	by Aaron Clark - EpochMod.com
	This work is licensed under a Creative Commons Attribution-NonCommercial-NoDerivatives 4.0 International License.
	http://creativecommons.org/licenses/by-nc-nd/4.0/
	Improvements and or bugfixes and other contributions are welcome via the github:
	https://github.com/EpochModTeam/Epoch/tree/master/Sources/epoch_server_settings/EpochEvents/Earthquake.sqf
*/
private ["_marker","_minerals","_randomIndex","_item","_plyrsNearEpicenter","_position","_chance"];
_position = [epoch_centerMarkerPosition, 0, EPOCH_dynamicVehicleArea, 10, 0, 1000, 0] call BIS_fnc_findSafePos;
if ((count _position) == 2) then{
	_plyrsNearEpicenter = _position nearEntities[["Epoch_Male_F", "Epoch_Female_F"], 1000];
	if !(_plyrsNearEpicenter isEqualTo[]) then{

		// decrease chance with more players
		_chance = linearConversion [1, 100, (count allPlayers), 0, 0.5, true];
		if ((random 1) > _chance) then {
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
