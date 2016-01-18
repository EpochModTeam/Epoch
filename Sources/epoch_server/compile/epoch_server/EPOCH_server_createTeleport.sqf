private ["_pos1","_pos","_veh","_veh1","_veh2"];

_debugLocation = getMarkerPos "respawn_west";
_debugLocation set[2, 0];
_debug = createVehicle["Debug_static_F", _debugLocation, [], 0, "CAN_COLLIDE"];
_protection = createVehicle["ProtectionZone_Invisible_F", _debugLocation, [], 0, "CAN_COLLIDE"];

for "_i" from 1 to 4 do {
	_class = ["clone_empty_static_F", "clone_male_static_F", "clone_female_static_F"] select(floor(random 3));
	_debug1 = createVehicle[_class, (_debug modelToWorld(_debug selectionPosition(str _i))), [], 0, "CAN_COLLIDE"];
	_debug1 setDir-90;

};
for "_i" from 5 to 8 do {
	_class = ["clone_empty_static_F", "clone_male_static_F", "clone_female_static_F"] select(floor(random 3));
	_debug1 = createVehicle[_class, (_debug modelToWorld(_debug selectionPosition(str _i))), [], 0, "CAN_COLLIDE"];
	_debug1 setDir 90;
};

// spawn lights
{
	_lightLocation = _debug modelToWorld _x;
	_light = createVehicle["Land_PortableLight_double_F", _lightLocation, [], 0, "CAN_COLLIDE"];
	_light setDir ([_debugLocation,_lightLocation] call BIS_fnc_dirTo);
	_light setpos _lightLocation;
} forEach [[-16.623,-8.50195,-10.5417],[15.0352,-9.08594,-10.5417]];

_config = configFile >> "CfgEpoch";

// spawn area props
{
	// diag_log str(_x);
	_class = _x select 0;
	_pos = _x select 1;
	_dir = _x select 2;

	_deSimulate = _class isKindOf "ThingX";
	if (count _x >= 4) then {

		_deSimulate = (_x select 3) isEqualTo "true";
	};

	_ep = createVehicle[_class, _pos, [], 0, "CAN_COLLIDE"];

	_ep allowDamage false;
	if (typeName _dir == "ARRAY") then{
		_ep setVectorDirAndUp _dir;
	} else {
		_ep setDir _dir;
	};
	_ep setposATL _pos;

	if (_deSimulate) then{
		_ep enableSimulationGlobal false;
	};

} forEach(getArray(_config >> worldname >> "propsPos"));

{
	_enterClass = _x select 0;

	_useWorldPos = false;
	if (count _x >= 5) then {
		_useWorldPos = (_x select 4) isEqualTo "true";
	};
	_pos1 = _x select 1;
	if !(_useWorldPos) then {
		_pos1 = _debug modelToWorld (_x select 1);
	};

	_exitClass = _x select 2;
	_pos = _x select 3;

	_pro1 = createVehicle ["ProtectionZone_Invisible_F", _pos1, [], 0, "CAN_COLLIDE"];
	_veh1 = createVehicle[_enterClass, _pos1, [], 0, "CAN_COLLIDE"];
	_veh1 enableSimulationGlobal false;
	_veh1 allowDamage false;
	_veh1 setVariable["ParentBuilding", _pos];
	_veh1 setDir 0;
	_veh1 setposATL _pos1;

	if (_exitClass != "") then {
		_veh2 = createVehicle[_exitClass, _pos, [], 0, "CAN_COLLIDE"];
		_veh2 enableSimulationGlobal false;
		_veh2 allowDamage false;
		_veh2 setVariable["ParentBuilding", _pos1];
		_veh2 setDir 0;
		_veh2 setposATL _pos;
	};
	_pro2 = createVehicle ["ProtectionZone_Invisible_F", _pos, [], 0, "CAN_COLLIDE"];
	EPOCH_staticTraderLocations pushBack _pos;
} foreach (getArray(_config >> worldname >> "telePos"));
