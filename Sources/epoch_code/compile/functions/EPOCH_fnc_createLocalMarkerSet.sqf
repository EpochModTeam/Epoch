/*

	Author: DirtySanchez

    Contributors:

	Description:
	Utilize new Epoch Active Markers, Backgrounds and Icons courtesy of DrokZ.
	
    Licence:
    Arma Public License Share Alike (APL-SA) - https://www.bistudio.com/community/licenses/arma-public-license-share-alike

	Github:
    https://github.com/EpochModTeam/Epoch/tree/release/Sources/epoch_code/compile/functions/EPOCH_fnc_createLocalMarkerSet.sqf
	
	usage: 
	[_markerClass, _position] call EPOCH_fnc_createLocalMarkerSet;
	
	_markerClass(_mClass) - use one of the class markers in the epoch_configs/Configs/CfgMarkerSets.hpp or create new
	
	_position(_mPos) - position you would like to place the marker set on the map
	
	Example:
	1. ['DeathMarker',_pos] call EPOCH_fnc_createLocalMarkerSet;
	
	2. ['PlayerMarker',_pos] call EPOCH_fnc_createLocalMarkerSet;
	
*/
private["_config", "_markerArray", "_markerName", "_ccText"];

params [ ["_mClass",""], ["_mPos",[0,0,0]], ["_OverrideTxt",""] ];
if(_mClass isEqualTo "") exitWith {
	diag_log "EPOCHDebug: createLocalMarkerSet -1- empty markerClass, nothing to create";
};

// get config for custom marker sets
_config = 'CfgMarkerSets' call EPOCH_returnConfig;
if !(isclass (_config >> _mClass)) exitwith {
	diag_log "EPOCHDebug: createLocalMarkerSet -2- not a class markerClass, nothing to create";
};

// get array for custom marker set
_markerArray = getArray(_config >> _mClass >> "markerArray");
if(_markerArray isEqualTo []) exitWith {
	diag_log "EPOCHDebug: createLocalMarkerSet -3- empty markerArray, nothing to create";
};

// get a markerName and check for it on map
_markerName = (_markerArray select 0) select 0;
if(_markerName in allMapMarkers) exitWith {
	diag_log "EPOCHDebug: createLocalMarkerSet -4- marker already exists on map";
};

// check for defined Marker counter
if(isNil {Epoch_markerCounter})then{Epoch_markerCounter = 0};

// run forEach loop on array
{
	// double check all, use these defaults if not defined
	_x params [ 
		["_mName",format["EPOCH_marker_%1", Epoch_markerCounter]],
		["_mShape","ICON"],
		["_mType","hd_dot"],
		["_mColor","ColorRed"],
		["_mAlpha",1],
		["_mSize",[0.8,0.8]],
		["_mDir",0],
		["_mText",""]
	];
	
	_marker = createMarkerLocal [_mName, _mPos];
	
	_mName setMarkerShapeLocal _mShape;
	
	if!(_mShape isEqualTo "ICON")then{
		if!(_mType in (getArray(_config >> "brushes")))exitWith{
			diag_log "EPOCHDebug: createLocalMarkerSet -5- Shape is Ellipse or Rectangle and needs a Brush Type";
		};
	};
	_mName setMarkerTypeLocal _mType; 
	
	_mName setMarkerAlphaLocal _mAlpha;
	_mName setMarkerSizeLocal _mSize;
	_mName setMarkerDirLocal _mDir;
	
	if (!(_OverrideTxt isequalto "") && _OverrideTxt isequaltype "") then {
		_mName setMarkerTextlocal _OverrideTxt;
	}
	else {
		if!(_mText isEqualTo "")then{
			_ccText = call compile _mText;
			_mName setMarkerTextlocal _ccText;
		};
	};
	
	if!(_mColor isEqualTo "")then{
		_mName setMarkerColorLocal _mColor
	};
	
	missionNameSpace setVariable[_mName, _mSize];
	if(_mName isEqualTo (format["EPOCH_marker_%1", Epoch_markerCounter]))then{
		Epoch_markerCounter = Epoch_markerCounter + 1;
	};
}forEach _markerArray;
