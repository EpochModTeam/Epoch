/*
	Author: Aaron Clark - EpochMod.com

    Contributors:

	Description:
	Server side spawing of shipwreck loots

    Licence:
    Arma Public License Share Alike (APL-SA) - https://www.bistudio.com/community/licenses/arma-public-license-share-alike

    Github:
    https://github.com/EpochModTeam/Epoch/tree/release/Sources/epoch_server/compile/epoch_looting/EPOCH_server_spawnBoatLoot.sqf
*/
//[[[cog import generate_private_arrays ]]]
private ["_shipwrecks","_item","_markers"];
//[[[end]]]
_worldSize = worldSize/2;
_shipwrecks = nearestTerrainObjects [ [_worldSize, _worldSize], [], _worldSize, false ];
{
	// 20 percent chance for loot to spawn
	if ((random 1) <= 0.4) then {
		_item = createVehicle["container_epoch", _x, [], 0, "NONE"];
		_item setMass 220;

		if (EPOCH_SHOW_BOATLOOT) then {
			_markers = ["Shipwreck",_x] call EPOCH_server_createGlobalMarkerSet;
		};
	};
} foreach _shipwrecks;
