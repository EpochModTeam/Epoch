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
private ["_cfgEpoch", "_debug", "_worldSize", "_shipwrecks", "_customLocs", "_customWrecks", "_totalCustomLocs", "_customWreck", "_total", "_count", "_distFromOthers", "_spawnedLoot","_tooClose", "_wreck", "_position", "_item", "_debugMkr", "_markers", "_originalColors", "_showMarkers", "_decayMarkerColor", "_compromisedColor", "_rEvents", "_thisEvent"];
//[[[end]]]
_cfgEpoch = configFile >> "CfgEpoch" >> worldname;
_debug = if(getNumber(_cfgEpoch >> "debugShipwreckLoot") isEqualTo 1)then{true}else{false};
// Check for shipwreck loot allowed
if (getNumber(_cfgEpoch >> "shipwreckLootEnabled") isEqualTo 1) then {
	// Check for total shipwrecks allowed
	_total = getNumber(_cfgEpoch >> "maxSpawnedShipwrecks");
	if(_total isEqualTo 0)exitWith{if(_debug)then{diag_log "EPOCHDebug: no shipwrecks allowed"}};
	// Load shipwrecks and custom locations
	_worldSize = worldSize/2;
	_shipwrecks = (nearestTerrainObjects [ [_worldSize, _worldSize], ["SHIPWRECK"], _worldSize]) select {surfaceiswater (getpos _x)} ;
	_customLocs = getArray(_cfgEpoch >> "shipwreckCustomLocs");
	_customWrecks = getArray(_cfgEpoch >> "shipwreckCustomWrecks");
	_totalCustomLocs = count(_customLocs);
	if(_totalCustomLocs > 0)then{
		for "_c" from 0 to _totalCustomLocs-1 do {
			_customWreck = (selectRandom _customWrecks) createVehicle (_customLocs select _c);
			_shipwrecks pushBack _customWreck;
		};	
	};	
	if(_shipwrecks isEqualTo [])exitWith{if(_debug)then{diag_log "EPOCHDebug: no shipwrecks found"}};
	// Check combined array count
	_count = count(_shipwrecks);
	if(_count < _total)then{if(_debug)then{diag_log "EPOCHDebug: not enough shipwrecks to fill your needs on this map, trying all available locations!"}};
	// Start spawning loot
	_distFromOthers = getNumber(_cfgEpoch >> "distFromOtherShipwrecks");
	_spawnedLoot = [];
	for "_i" from 1 to _total do {
		if(_shipwrecks isEqualTo [])exitWith{if(_debug)then{diag_log "EPOCHDebug: no more shipwrecks found"}};
		
		_tooClose = false;
		_wreck = selectRandom _shipwrecks;
		if(isNil "_wreck")exitWith{};
		{
			if(!(_spawnedLoot isEqualTo []) && ((_wreck distance _x) < _distFromOthers))exitWith{
				if(_debug)then{diag_log "EPOCHDebug: Shipwreck too close to another shipwreck"};
				_tooClose = true;
				_i = (_i - 1);
			};
		}forEach _spawnedLoot;
		
		_shipwrecks = _shipwrecks - [_wreck];
		if!(_tooClose)then{
			_position = [_wreck,1,20,3,1,20,0] call BIS_fnc_findSafePos;
			_item = createVehicle["container_epoch",_position, [], 0, "NONE"];
			_spawnedLoot pushback _wreck;
			if(_debug)then{
				_debugMkr = createMarker [str(_position),_position];
				_debugMkr setMarkerShape "ICON";
				_debugMkr setMarkerType "mil_dot";
				_debugMkr setMarkerColor "ColorRed";
			};
			_item setMass 220;
			_item setVariable["EPOCH_Loot",false,true];

			// SET UP THE MARKER.
			_markers = [];
			_originalColors = [];
			_showMarkers = if(getNumber(_cfgEpoch >> "showBoatLootMarkers") isEqualTo 1)then{true}else{false};
			_decayMarkerColor = getText(_cfgEpoch >> "shipwreckDecayMarkerColor");
			_compromisedColor = getText(_cfgEpoch >> "shipwreckCompromisedColor");
			if (_showMarkers) then{
				_markers = ["Shipwreck",_position] call EPOCH_server_createGlobalMarkerSet;
				{
					_originalColors pushBack (getMarkerColor _x);
				}forEach _markers;
				
				// Check for HeightenedPlayerVsPlayer false and remove comprimised coloring
				if!(getNumber(_cfgEpoch >> "HeightenedPlayerVsPlayer") isEqualTo 1)then{
					_compromisedColor = getMarkerColor (_markers select 0);
				};
			};

			_rEvents = missionNameSpace getVariable["EPOCH_RunningEvents",[]];
			_thisEvent = [_position, [_item], [], "shipwreckCounter", diag_tickTime, 99999, _showMarkers, _markers, _originalColors, _decayMarkerColor, _compromisedColor];
			missionNameSpace setVariable["EPOCH_RunningEvents",_rEvents + [_thisEvent]];
		};
	};
	if(_debug)then{
		diag_log format["EPOCHDebug: Safely spawned %1 loot container(s) at these shipwreck locations:%2",count _spawnedLoot , _spawnedLoot];
	};
};
