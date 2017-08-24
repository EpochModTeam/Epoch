/*
	Author/s:
		Aaron Clark - EpochMod.com

	Description:
		Spawns Debris Dynamically on Roadways.

	Improvements and or bugfixes and other contributions are welcome via the github:
	https://github.com/EpochModTeam/Epoch/tree/release/Sources/epoch_server_debris_event/EpochEvents/DebrisSpawner.sqf
*/
//[[[cog import generate_private_arrays ]]]
private ["_allRoads","_allowDebris","_debris","_debrisCounter","_debrisLocations","_debrisLocationsKey","_debrisLocationsTMP","_debug","_disallowedLocations","_expiresDebris","_export","_instanceID","_intersections","_marker","_maxDebrisLimit","_nearbyLocations","_newDebrisCounter","_object","_offsetX","_offsetY","_position","_response","_rng","_rngChance","_scriptHiveKey","_seed","_selectedDebris","_upperPos","_worldSize"];
//[[[end]]]
_debug = false;
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
_disallowedLocations = ["Airport"];

_debrisCounter = 0;
_newDebrisCounter = 0;
_worldSize = worldSize/2;
_instanceID = call EPOCH_fn_InstanceID;

_maxDebrisLimit = 500; // max total objects to spawn
_rngChance = 0.95; // Lower this to spawn more positions
_scriptHiveKey = "EPOCH:DynamicDebris789"; // change this to force a new seed to be generated.

_debrisLocationsKey = format ["%1:%2", _instanceID, worldname];
_response = [_scriptHiveKey, _debrisLocationsKey] call EPOCH_fnc_server_hiveGETRANGE;

_response params [["_status",0],["_data",[]] ];
_debrisLocations = [];
_debrisLocationsTMP = [];
if (_status == 1 && _data isEqualType [] && !(_data isEqualTo [])) then {
    _debrisLocations = _data;
} else {
    diag_log format["DEBUG: Generating new Debris Locations... this is only done once every %1 days.",(_expiresDebris/86400)];
    _allRoads = [_worldSize,_worldSize] nearRoads _worldSize;
    _allRoads = _allRoads call BIS_fnc_arrayShuffle;

    _seed = random 999999;
    diag_log format["DEBUG: Generating new Debris Locations... with seed %1.",_seed];
    {
        if (_newDebrisCounter >= _maxDebrisLimit) exitWith {};
        _position = getPosASL _x;
        _position params ["_posX","_posY"];
        _rng = _seed random [_posX,_posY];
        if (_rng > _rngChance) then {

            _nearbyLocations = nearestLocations [_position, _disallowedLocations, 100];
            if (_nearbyLocations isEqualTo []) then {

                if (_debug) then {
                    _marker = createMarker[str(_position), _position];
                    _marker setMarkerShape "ICON";
                    _marker setMarkerType "waypoint";
                    _marker setMarkerColor "ColorGreen";
                };
                _selectedDebris = selectRandom _debris;
                _offsetX = (random 10) - 5;
                _offsetY = (random 10) - 5;

                _position set [0,(_position select 0) + _offsetX];
                _position set [1,(_position select 1) + _offsetY];
                _position set [2,(_position select 2) - 1];

                _upperPos = +_position;
                _upperPos set [2,(_position select 2) + 3];

                _intersections = lineIntersectsSurfaces [_upperPos, _position, objNull, objNull, true, 1];
                if !(_intersections isEqualTo []) then {
                    (_intersections select 0) params ["_intersectPosASL","_surfaceNormal","_intersectObject","_parentObject"];
                    _allowDebris = true;
                    if !(isNull _intersectObject) then {
                        _allowDebris = !((typeOf _intersectObject) in _debris);
                    };
                    if (_allowDebris) then {
                        _object = createSimpleObject [_selectedDebris, _intersectPosASL];
                        _object setDir random 360;
                        _object setVectorUp _surfaceNormal;
                        _object setPosASL _intersectPosASL;
                        _export = [_selectedDebris,getPosWorld _object, vectorDir _object, vectorUp _object];
                        _debrisLocationsTMP pushBack _export;
                        _newDebrisCounter = _newDebrisCounter + 1;
                    };
                };
            };
        };
    } forEach _allRoads;
    [_scriptHiveKey, _debrisLocationsKey, _expiresDebris, _debrisLocationsTMP] call EPOCH_fnc_server_hiveSETEX;
};

{
    if (_debrisCounter >= _maxDebrisLimit) exitWith {};
    if (_x isEqualType [] && !(_x isEqualTo [])) then {
        _x params ["_selectedDebris","_posWorld", "_vectorDir", "_vectorUp"];
        _object = createSimpleObject [_selectedDebris, _posWorld];
        _object setVectorDirAndUp [_vectorDir,_vectorUp];
        _object setPosWorld _posWorld;
        _debrisCounter = _debrisCounter + 1;
    };
} forEach _debrisLocations;

if (_debug) then {
    diag_log format["DEBUG: Spawned %1 Existing Debris",_debrisCounter];
    if (_newDebrisCounter > 0) then {
        diag_log format["DEBUG: Spawned %1 New Debris.",_newDebrisCounter];
    };
};
