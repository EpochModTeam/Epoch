private [
	"_spawnPositionSize","_spawnPositions","_type","_position","_range","_roads","_maxSpawnSize"
	,"_vehicleFound","_vehClass"
	,"_countAllowedVeh","_randomVehicleIndex","_randomVehicle","_velimit","_vehicleCount"
	,"_isShip"
	,"_spawnPositionIndex","_spawnPosition","_roadPosition"
	,"_dir","_vehObj","_config"
	,"_textureSelectionIndex","_selections","_colors","_textures","_color","_count"
	,"_marker"
];

_allowedVehiclesList = [];
{
  _vehClass = _x select 0;
  _velimit = _x select 1;
  _vehicleCount = {typeOf _x == _vehClass} count vehicles;
  for "_i" from 1 to (_velimit-_vehicleCount) do {
    _allowedVehiclesList pushBack _vehClass;
  };
} forEach EPOCH_allowedVehiclesList;

if (_allowedVehiclesList isEqualTo []) exitWith {
	diag_log "DEBUG: All vehicles over limit";
};

_spawnPositionSizeDefaults = [
	["FlatAreaCity",1],
	["FlatAreaCitySmall",1],
	["NameCity",2],
	["NameVillage",1],
	["NameCityCapital",4],
	["Airport",5],
	["NameLocal",2],
	["StrongpointArea",1],
	["VegetationBroadleaf",1],
	["VegetationFir",1],
	["ViewPoint",1]
];
_serverMapConfig = configFile >> "CfgEpoch" >> worldName;
_spawnPositionSize = [_serverMapConfig, "vehicleSpawnTypes", _spawnPositionSizeDefaults] call EPOCH_fnc_returnConfigEntry;

_allowedTypes = [];
{
  _allowedTypes pushBack (_x select 0)
}forEach _spawnPositionSize;


_allCitys = "getText(_x >> 'type') in _allowedTypes" configClasses (configfile >> "CfgWorlds" >> worldName >> "Names");
_allCitysDync = [];

{
    _cityPos = getArray(_x >> "position");
    _range = getNumber(_x >> "radiusA") * 1.3;
    _nearBy = count(_cityPos nearEntities[["LandVehicle", "Ship", "Air", "Tank"], _range]);
    _find = _allowedTypes find (getText(_x >> "type"));
    if (_find > -1) then{
        _limit = _spawnPositionSize select _find select 1;
        if (_limit > _nearBy) then{
          _allCitysDync pushBack _x;
        };
    };
} forEach _allCitys;

_position = [0,0,0];

_spawnCount = (count EPOCH_VehicleSlots - EPOCH_storedVehicleCount) - 1;

diag_log format["DEBUG: count EPOCH_VehicleSlots: %1 EPOCH_storedVehicleCount: %2 _spawnCount %3", (count EPOCH_VehicleSlots), EPOCH_storedVehicleCount, _spawnCount];

for "_i" from 1 to _spawnCount do {

	_slot = EPOCH_VehicleSlots deleteAt 0;

	_vehCount = count _allowedVehiclesList;
	_vehClass = _allowedVehiclesList deleteAt(floor(random(_vehCount)));
	if (isNil "_vehClass") exitWith{diag_log "DEBUG: Failed to find vehicle class"};

	_direction = random 360;
	_position = [0,0,0];
	_getRandomPos = true;

	_preferedPos = getArray(configFile >> "CfgEpoch" >> worldname >> "whitelistedVehiclePos" >> _vehClass);
	if !(_preferedPos isEqualTo []) then{
		_newPosition = _preferedPos select(floor(random(count _preferedPos)));
		if ((nearestObjects[(_newPosition select 0), ["LandVehicle", "Ship", "Air", "Tank"], 50]) isEqualTo []) then{
			_position = _newPosition select 0;
			_direction = _newPosition select 1;
			_getRandomPos = false;
		};
	};


	if (_getRandomPos) then{
		_isShip = _vehClass isKindOf "Ship";
		if (_isShip || (_vehClass isKindOf "Air")) then{
			if (_isShip) then{
			_position = [epoch_centerMarkerPosition, 0, EPOCH_dynamicVehicleArea, 10, 0, 4000, 1] call BIS_fnc_findSafePos;
			_position = [_position, 0, 100, 10, 2, 4000, 0] call BIS_fnc_findSafePos;
			} else {
			_position = [epoch_centerMarkerPosition, 0, EPOCH_dynamicVehicleArea, 10, 0, 1000, 0] call BIS_fnc_findSafePos;
			};
		} else {

			if (_allCitysDync isEqualTo []) then {
				_position = [epoch_centerMarkerPosition, 0, EPOCH_dynamicVehicleArea, 10, 0, 1000, 0] call BIS_fnc_findSafePos;
			} else {
				_selectedCity = _allCitysDync deleteAt (floor random(count _allCitysDync));
				_cityPos = getArray(_selectedCity >> "position");
				_range = getNumber(_selectedCity >> "radiusA") * 1.3;

				_roads = _cityPos nearRoads _range;
				if !(_roads isEqualTo []) then {
					_road = _roads select(floor random(count _roads));
					_position = getPosATL _road;
					_position deleteAt 2;
				};
			};
		};
	};

	if ((count _position == 2 && _getRandomPos) || !_getRandomPos) then{

		_collide = "CAN_COLLIDE";
		if (_getRandomPos) then{
			_collide = "NONE";
			_position set[2, 0];
			if (surfaceIsWater _position) then{
				_position = ASLToATL _position;
			};
		};

		_vehObj = [_vehClass,_position,_direction,true,_slot,"",_collide,true,true] call EPOCH_fnc_spawn_vehicle;

		if (EPOCH_DEBUG_VEH) then {
			_marker = createMarker [str(_position) , _position];
			_marker setMarkerShape "ICON";
			_marker setMarkerType "mil_dot";
			_marker setMarkerText _vehClass;
			_marker setMarkerColor "ColorBlue";
		};

	};

};

EPOCH_VehicleSlotCount = count EPOCH_VehicleSlots;
publicVariable "EPOCH_VehicleSlotCount";

EPOCH_allowedVehiclesList = nil;
true
