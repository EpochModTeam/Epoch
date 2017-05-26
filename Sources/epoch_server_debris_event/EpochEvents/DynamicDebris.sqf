/*
	Author/s:
		Aaron Clark - EpochMod.com

	Description:
		Spawns Debris Dynamically on Roadways.

	Improvements and or bugfixes and other contributions are welcome via the github:
	https://github.com/EpochModTeam/Epoch/tree/release/Sources/epoch_server_settings/EpochEvents/DebrisSpawner.sqf
*/
//[[[cog import generate_private_arrays ]]]
private ["_allRoads","_debris","_debrisCounter","_debrisLocations","_debrisLocationsKey","_expiresDebris","_export","_hiveKey","_instanceID","_intersections","_marker","_maxDebrisLimit","_object","_offsetX","_offsetY","_position","_response","_rng","_seed","_selectedDebris","_worldSize"];
//[[[end]]]

_expiresDebris = 604800;
_debris = [
    "Land_GarbageBags_F",
    "Land_GarbagePallet_F",
    "Land_GarbageWashingMachine_F",
    "Land_GarbageHeap_01_F",
    "Land_GarbageHeap_03_F",
    "Land_GarbageHeap_04_F",
    "Land_Wreck_Skodovka_F",
    "Land_Wreck_CarDismantled_F",
    "Land_Wreck_Truck_F",
    "Land_Wreck_Car2_F",
    "Land_Wreck_Car_F",
    "Land_Wreck_Car3_F",
    "Land_Wreck_Hunter_F",
    "Land_Wreck_Van_F",
    "Land_Wreck_Offroad_F",
    "Land_Wreck_UAZ_F",
    "Land_Wreck_Ural_F",
    "Land_Wreck_Truck_dropside_F",
    "Land_Wreck_HMMWV_F"
];
_debrisCounter = 0;
_worldSize = worldSize/2;
_instanceID = call EPOCH_fn_InstanceID;
_maxDebrisLimit = 500;

_debrisLocationsKey = format ["%1:%2", _instanceID, worldname];
_response = ["DebrisLocations", _debrisLocationsKey] call EPOCH_fnc_server_hiveGETRANGE;

_response params [["_status",0],["_data",[]] ];
_debrisLocations = [];
if (_status == 1 && _data isEqualType [] && !(_data isEqualTo [])) then {
    _debrisLocations = _data;
} else {
    diag_log format["DEBUG: Generating new Debris Locations... this is only done once every %1 days.",(_expiresDebris/86400)];
    _allRoads = [_worldSize,_worldSize] nearRoads _worldSize;
    _seed = random 999999;
    diag_log format["DEBUG: Generating new Debris Locations... with seed %1",_seed];
    {
        _position = getPosWorld _x;
        _position params ["_posX","_posY"];
        _rng = _seed random [_posX,_posY];
        if (_rng > 0.95) then {
            _debrisLocations pushBack _position;
        };
    } forEach _allRoads;
    ["DebrisLocations", _debrisLocationsKey, _expiresDebris, _debrisLocations] call EPOCH_fnc_server_hiveSETEX;
};

for "_i" from 1 to _maxDebrisLimit do {

	_hiveKey = format ["%1:%2", _instanceID, _i];
	_response = ["Debris", _hiveKey] call EPOCH_fnc_server_hiveGETRANGE;
    _response params [["_status",0],["_data",[]] ];

    if (_status == 1 && _data isEqualType [] && !(_data isEqualTo [])) then {

        _data params ["_selectedDebris","_posWorld", "_vectorDir", "_vectorUp"];
        _object = createSimpleObject [_selectedDebris, _posWorld];
        _object setVectorDirAndUp [_vectorDir,_vectorUp];
        _object setPosWorld _posWorld;
        _debrisCounter = _debrisCounter + 1;

    } else {

        _position = selectRandom _debrisLocations;
        _debrisLocations = _debrisLocations - _position;

        _marker = createMarker[str(_position), _position];
        _marker setMarkerShape "ICON";
        _marker setMarkerType "waypoint";
        _marker setMarkerColor "ColorGreen";

        _selectedDebris = selectRandom _debris;
        _offsetX = (random 10) - 5;
        _offsetY = (random 10) - 5;
        _position set [0,(_position select 0) + _offsetX];
        _position set [1,(_position select 1) + _offsetY];
        _position set [2,0];

        _intersections = lineIntersectsSurfaces [[_position select 0,_position select 1,1000], _position, objNull, objNull, true, 1];
        if !(_intersections isEqualTo []) then {
            (_intersections select 0) params ["_intersectPosASL","_surfaceNormal","_intersectObject","_parentObject"];
            _object = createSimpleObject [_selectedDebris, _intersectPosASL];
            _object setDir random 360;
            _object setVectorUp _surfaceNormal;
            _object setPosASL _intersectPosASL;
            _export = [_selectedDebris,getPosWorld _object, vectorDir _object, vectorUp _object];
            ["Debris", _hiveKey, _expiresDebris, _export] call EPOCH_fnc_server_hiveSETEX;
            _debrisCounter = _debrisCounter + 1;
        };
    };
};

EP = _debrisCounter;
