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
_cfgEpoch = configFile >> "CfgEpoch" >> worldname;
if (getNumber(_cfgEpoch >> "shipwreckLootEnabled") isEqualTo 1) then {
	_worldSize = worldSize/2;
	_shipwrecks = nearestTerrainObjects [ [_worldSize, _worldSize], ["SHIPWRECK"], _worldSize];
	_total = getNumber(_cfgEpoch >> "maxSpawnedShipwrecks");
	for "_i" from 1 to _total do {
		if (_shipwrecks isEqualTo []) exitWith {};
		_wreck = selectRandom _shipwrecks;
		_shipwrecks = _shipwrecks - [_wreck];
		_item = createVehicle["container_epoch", _wreck, [], 0, "NONE"];
		_item setMass 220;
		if (EPOCH_SHOW_BOATLOOT) then {
			_markers = ["Shipwreck",_wreck] call EPOCH_server_createGlobalMarkerSet;
		};
	};
};
