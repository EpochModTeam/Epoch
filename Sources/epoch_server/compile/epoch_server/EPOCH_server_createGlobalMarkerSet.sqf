/*

	Author: DirtySanchez

    Contributors:

	Description:
	Utilize new Epoch Active Markers, Backgrounds and Icons courtesy of DrokZ.
	
    Licence:
    Arma Public License Share Alike (APL-SA) - https://www.bistudio.com/community/licenses/arma-public-license-share-alike

	Github:
    https://github.com/EpochModTeam/Epoch/tree/release/Sources/epoch_server/compile/epoch_server/EPOCH_server_createGlobalMarkerSet.sqf
	
	usage: 
	[_markerClass, _position] call EPOCH_server_createGlobalMarkerSet;
	
	_markerClass(_mClass) - use one of the class markers in the epoch_configs/Configs/CfgMarkerSets.hpp or create new
	
	_position(_mPos) - position you would like to place the marker set on the map
	
	Example:
	1. ['DeathMarker',_pos] call EPOCH_server_createGlobalMarkerSet;
	
	2. ['PlayerMarker',_pos] call EPOCH_server_createGlobalMarkerSet;
	
*/
private["_config", "_markerArray", "_ccText"];

params [ ["_mClass",""], ["_mPos",[0,0,0]], ["_OverrideTxt",""] ];
if(_mClass isEqualTo "") exitWith {
	diag_log "EPOCHDebug: createGlobalMarkerSet -1- empty markerClass, nothing to create";
};

// get config for custom marker sets
_config = 'CfgMarkerSets' call EPOCH_returnConfig;
if !(isclass (_config >> _mClass)) exitwith {
	diag_log "EPOCHDebug: createGlobalMarkerSet -2- not a class markerClass, nothing to create";
};

// get array for custom marker set
_markerArray = getArray(_config >> _mClass >> "markerArray");
if(_markerArray isEqualTo []) exitWith {
	diag_log "EPOCHDebug: createGlobalMarkerSet -3- empty markerArray, nothing to create";
};

// check for defined Marker counter
if(isNil {Epoch_markerCounterGlobal})then{Epoch_markerCounterGlobal = 0};

_return = [];
// run forEach loop on array
{
	// double check all, use these defaults if not defined
	_x params [ 
		["_mName",format["EPOCH_globalMarker_%1", Epoch_markerCounterGlobal]],
		["_mShape","ICON"],
		["_mType","hd_dot"],
		["_mColor","ColorBlack"],
		["_mAlpha",1],
		["_mSize",[0.8,0.8]],
		["_mDir",0],
		["_mText",""]
	];
	_mName = format["EPOCH_globalMarker_%1", Epoch_markerCounterGlobal];
	_marker = createMarker [_mName, _mPos];
	_return pushBack _mName;
	_mName setMarkerShape _mShape;
	if!(_mShape isEqualTo "ICON")then{
		if!(_mType in (getArray(_config >> "brushes")))exitWith{
			diag_log "EPOCHDebug: createGlobalMarkerSet -5- Shape is Ellipse or Rectangle and needs a Brush Type";
		};
	};
	_mName setMarkerType _mType; 
	_mName setMarkerAlpha _mAlpha;
	_mName setMarkerSize _mSize;
	_mName setMarkerDir _mDir;
	
	if (!(_OverrideTxt isequalto "") && _OverrideTxt isequaltype "") then {
		_mName setMarkerText _OverrideTxt;
	}
	else {
		if!(_mText isEqualTo "")then{
			_ccText = call compile _mText;
			_mName setMarkerText _ccText;
		};
	};
	
	if!(_mColor isEqualTo "")then{
		_mName setMarkerColor _mColor
	};
		
	Epoch_markerCounterGlobal = Epoch_markerCounterGlobal + 1;
}forEach _markerArray;

_return
