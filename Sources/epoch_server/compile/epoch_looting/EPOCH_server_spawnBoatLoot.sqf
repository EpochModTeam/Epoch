/*
	Author: Aaron Clark - EpochMod.com

    Contributors:

	Description:
	Server side spawing of shipwreck loots

    Licence:
    Arma Public License Share Alike (APL-SA) - https://www.bistudio.com/community/licenses/arma-public-license-share-alike

    Github:
    https://github.com/EpochModTeam/Epoch/tree/master/Sources/epoch_server/compile/epoch_looting/EPOCH_server_spawnBoatLoot.sqf
*/
private ["_item","_marker"];
{
	// 20 percent chance for loot to spawn
	if ((random 1) <= 0.4) then {
		_item = createVehicle["container_epoch", _x, [], 0, "NONE"];
		_item setMass 220;

		if (EPOCH_SHOW_BOATLOOT) then {
			_marker = createMarker[str(_x), _x];
			_marker setMarkerShape "ICON";
			_marker setMarkerType "mil_dot";
			// _marker setMarkerText "Shipwreak";
			_marker setMarkerColor "ColorOrange";
		};
	};
} foreach (getArray (configFile >> "CfgEpoch" >> worldname >> "containerPos"));
