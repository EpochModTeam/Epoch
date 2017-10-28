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
private ["_worldSize","_shipwrecks","_total","_count","_distFromOthers","_tooClose","_spawnedLoot","_wreck","_item","_markers"];
//[[[end]]]
_cfgEpoch = configFile >> "CfgEpoch" >> worldname;
if (getNumber(_cfgEpoch >> "shipwreckLootEnabled") isEqualTo 1) then {
	_worldSize = worldSize/2;
	_shipwrecks = nearestTerrainObjects [ [_worldSize, _worldSize], ["SHIPWRECK"], _worldSize];
	_total = getNumber(_cfgEpoch >> "maxSpawnedShipwrecks");
	
	if(_shipwrecks isEqualTo [])exitWith{diag_log "EPOCHDebug: no shipwrecks found"};
	if(_total isEqualTo 0)exitWith{diag_log "EPOCHDebug: no shipwrecks allowed"};
	_count = count(_shipwrecks);
	if(_count < _total)then{diag_log "EPOCHDebug: not enough shipwrecks to fill your needs on this map, trying all available locations!"};
	
	_distFromOthers = getNumber(_cfgEpoch >> "distFromOtherShipwrecks");
	_tooClose = false;
	_spawnedLoot = [];
	for "_i" from 1 to (_total min _count) do {
		_wreck = selectRandom _shipwrecks;
		{
			if(!(_spawnedLoot isEqualTo []) && ((_wreck distance _x) < _distFromOthers))exitWith{
				diag_log "EPOCHDebug: Shipwreck too close to another shipwreck";
				_tooClose = true;
				_i = (_i - 1);
			};
		}forEach _spawnedLoot;
		
		_shipwrecks = _shipwrecks - [_wreck];
		if!(_tooClose)then{
			_item = createVehicle["container_epoch", _wreck, [], 0, "NONE"];
			_spawnedLoot pushback _wreck;
			_item setMass 220;

			if (EPOCH_SHOW_BOATLOOT) then {
				_markers = ["Shipwreck",_wreck] call EPOCH_server_createGlobalMarkerSet;
			};
		};
	};
	diag_log format["EPOCHDebug: Safely spawned %1 loot container(s) at these shipwreck locations:%2",count _spawnedLoot , _spawnedLoot];
};