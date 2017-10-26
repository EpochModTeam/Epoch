/*
	Author: DirtySanchez - EpochMod.com

    Contributors:

	Description:
	Delete Marker Set
	
    License:
    Arma Public License Share Alike (APL-SA) - https://www.bistudio.com/community/licenses/arma-public-license-share-alike

	Github:
    https://github.com/EpochModTeam/Epoch/tree/release/Sources/epoch_code/compile/functions/EPOCH_fnc_deleteLocalMarkerSet.sqf
	
	usage: 
	[_mClass] call EPOCH_fnc_deleteLocalMarkerSet;
	
	_mClass - name of marker you used from: epoch_configs/Configs/CfgMarkerSets.hpp
*/
private["_config","_markerArray"];

params [ ["_mClass",""], ["_data",[]] ];

if(_mClass isEqualTo "") exitWith {
	diag_log "EPOCHDebug: deleteLocalMarkerSet -1- empty markerClass, nothing to delete";
};

// get config for custom marker sets
_config = 'CfgMarkerSets' call EPOCH_returnConfig;
if !(isclass (_config >> _mClass)) exitwith {
	diag_log "EPOCHDebug: deleteLocalMarkerSet -2- not a class markerClass, nothing to delete";
};
// get array for custom marker set
_markerArray = getArray(_config >> _mClass >> "markerArray");
if(_markerArray isEqualTo []) exitWith {
	diag_log "EPOCHDebug: deleteLocalMarkerSet -3- empty markerArray, nothing to delete";
};
// get a markerName and check for it on map
_markerName = (_markerArray select 0) select 0;
if!(_markerName in allMapMarkers) exitWith {
	diag_log "EPOCHDebug: deleteLocalMarkerSet -4- marker does not exist on map";
};

{
	_mName = _x select 0;
	deleteMarkerLocal _mName;
}forEach _markerArray;
