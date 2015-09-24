epoch_centerMarkerPosition = getpos player;
EPOCH_dynamicVehicleArea = 20000 / 2;

EPOCH_VehicleSlots = [];
for "_i" from 1 to 156 do {
	EPOCH_VehicleSlots pushBack str(_i);
};

EPOCH_storedVehicleCount = 0;

EPOCH_allowedVehiclesList = [
      ["C_Offroad_01_EPOCH", 8],
      ["C_Quadbike_01_EPOCH", 8],
      ["C_Hatchback_01_EPOCH", 10],
      ["C_Hatchback_02_EPOCH", 10],
      ["C_SUV_01_EPOCH", 10],
      ["C_Rubberboat_EPOCH", 5],
      ["C_Rubberboat_02_EPOCH", 5],
      ["C_Rubberboat_03_EPOCH", 5],
      ["C_Rubberboat_04_EPOCH", 5],
      ["C_Van_01_box_EPOCH", 8],
      ["C_Van_01_transport_EPOCH", 9],
      ["C_Boat_Civil_01_EPOCH", 5],
      ["C_Boat_Civil_01_police_EPOCH", 5],
      ["C_Boat_Civil_01_rescue_EPOCH", 5],
      ["B_Heli_Light_01_EPOCH", 2],
      ["B_SDV_01_EPOCH", 2],
      ["B_MRAP_01_EPOCH", 3],
      ["B_Truck_01_transport_EPOCH", 1],
      ["B_Truck_01_covered_EPOCH", 2],
      ["B_Truck_01_mover_EPOCH", 1],
      ["B_Truck_01_box_EPOCH", 1],
      ["O_Truck_02_covered_EPOCH", 2],
      ["O_Truck_02_transport_EPOCH", 1],
      ["O_Truck_03_covered_EPOCH", 1],
      ["O_Truck_02_box_EPOCH", 1],
      ["I_Heli_light_03_unarmed_EPOCH", 1],
      ["O_Heli_Light_02_unarmed_EPOCH", 1],
      ["I_Heli_Transport_02_EPOCH", 1],
      ["O_Heli_Transport_04_EPOCH", 1],
      ["O_Heli_Transport_04_bench_EPOCH", 1],
      ["O_Heli_Transport_04_box_EPOCH", 1],
      ["O_Heli_Transport_04_covered_EPOCH", 1],
      ["B_Heli_Transport_03_unarmed_EPOCH", 1],
      ["jetski_epoch", 7],
      ["K01", 2],
      ["K02", 2],
      ["K03", 2],
      ["K04", 2],
      ["ebike_epoch", 7],
      ["mosquito_epoch", 5],
      ["C_Heli_Light_01_civil_EPOCH",5]
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







_spawnPositionSize = [
      ["FlatAreaCity",1],
      ["FlatAreaCitySmall",1],
      ["NameCity",2],
      ["NameVillage",1],
      ["NameCityCapital",4],
      ["Airport",5]
];
if (worldName in ["Bornholm","Australia"]) then {
      _spawnPositionSize append [
            ["NameLocal",2],
            ["StrongpointArea",1],
            ["VegetationBroadleaf",1],
            ["VegetationFir",1],
            ["ViewPoint",1]
      ];
};


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


{
  if (count EPOCH_VehicleSlots <= EPOCH_storedVehicleCount) exitWith{};

  _vehClass = _allowedVehiclesList deleteAt (floor(random(count _allowedVehiclesList)));

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
        _road = _roads select(floor random(count _roads));

        _position = getPosATL _road;
        _position deleteAt 2;
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

			_vehObj = [_vehClass,_position,_direction,true,_x,"",_collide,true] call EPOCH_fnc_spawn_vehicle;


      _marker = createMarker [str(_position) , _position];
      _marker setMarkerShape "ICON";
      _marker setMarkerType "mil_dot";
      _marker setMarkerText format ["%1",_vehClass];
      _marker setMarkerColor "ColorRed";


			EPOCH_VehicleSlots set[_forEachIndex, "REM"];
	};

} forEach EPOCH_VehicleSlots;

EPOCH_VehicleSlots = EPOCH_VehicleSlots - ["REM"];

EPOCH_VehicleSlotCount = count EPOCH_VehicleSlots;
publicVariable "EPOCH_VehicleSlotCount";

EPOCH_allowedVehiclesList = nil;
true
