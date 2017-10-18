/*
	Author: DirtySanchez - EpochMod.com

    Contributors:

	Description:
	Delete Marker Set
	
    License:
    Arma Public License Share Alike (APL-SA) - https://www.bistudio.com/community/licenses/arma-public-license-share-alike

	Github:
    https://github.com/EpochModTeam/Epoch/tree/release/Sources/epoch_server/compile/epoch_server/EPOCH_server_deleteGlobalMarkerSet.sqf
	
	usage: 
	[_markerArray] call EPOCH_server_deleteGlobalMarkerSet;
	
	_markerArray - 1 or more in game marker names
*/
private["_mName"];

params [ ["_markerArray",[]], ["_data",[]] ];

if(_markerArray isEqualTo []) exitWith {
	diag_log "EPOCHDebug: deleteGlobalMarkerSet -1- empty markerArray, nothing to delete";
};

{
	_mName = _x;
	deleteMarker _mName;
}forEach _markerArray;
