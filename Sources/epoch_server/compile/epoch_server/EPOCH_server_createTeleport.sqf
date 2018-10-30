/*
	Author: Aaron Clark - EpochMod.com

    Contributors:

	Description:
	Creates inital teleport zones and sets up trader city props.

    Licence:
    Arma Public License Share Alike (APL-SA) - https://www.bistudio.com/community/licenses/arma-public-license-share-alike

    Github:
    https://github.com/EpochModTeam/Epoch/tree/release/Sources/epoch_server/compile/epoch_server/EPOCH_server_createTeleport.sqf
*/
//[[[cog import generate_private_arrays ]]]
private ["_array","_center","_class","_cloneClasses","_config","_configWorld","_deSimulate","_debug","_debug1","_debugBox","_debugLocation","_dir","_dir1","_dir2","_enterClass","_ep","_exitClass","_light","_lightLocation","_loadBaseTemplateConfig","_markerName","_part","_partPos","_pos","_pos1","_pro1","_pro2","_protection","_useWorldPos","_veh1","_veh2"];
//[[[end]]]
_loadBaseTemplateConfig = {
	private ["_partPos","_part","_array","_center","_deSimulate"];
	params ["_templateClass","_selectedTemplate","_pos","_class"];
    _array = getArray(configfile >> "CfgPropTemplate" >> _selectedTemplate);
	_pos set [2,0];
    _center = createVehicle [_templateClass, _pos, [], 0, "CAN_COLLIDE"];
    {
        _partPos = _center modelToWorld (_x select 1);
		_partPos set [2,0];
		if ((_x select 0) isKindOf "Man") then {
			EPOCH_staticNPCTraderPos pushBack [(_x select 0), _partPos, (_x select 2)];
		} else {
			_part = createVehicle [_x select 0, _partPos, [], 0, "CAN_COLLIDE"];
	        _part setDir (_x select 2);
	        _part setPos _partPos;

			_deSimulate = _class isKindOf "ThingX";
			// disable simulation if true
			if (count _x >= 4) then {
				_deSimulate = (_x select 3) isEqualTo "true";
			};

			if (_deSimulate) then{
				_part enableSimulationGlobal false;
			};
		};
    } forEach _array;
};

// load map config
_config = configFile >> "CfgEpoch";
_configWorld = _config >> worldname;

_debugBox = getText(_configWorld >> "debugBoxClass"); // debugBoxClass = "" to disable
if !(_debugBox isEqualTo "") then {
	_debugLocation = getMarkerPos "respawn_west";
	_debugLocation set[2, 0];
	_debug = createVehicle[_debugBox, _debugLocation, [], 0, "CAN_COLLIDE"];
	_debug setposATL _debugLocation;
	_protection = createVehicle["ProtectionZone_Invisible_F", _debugLocation, [], 0, "CAN_COLLIDE"];
	_protection setposATL _debugLocation;
	_cloneClasses = getArray(_configWorld >> "cloneClasses");
	if !(_cloneClasses isEqualTo []) then {
		for "_i" from 1 to 4 do {
			_class = selectRandom _cloneClasses;
			_debug1 = createVehicle[_class, (_debug modelToWorld(_debug selectionPosition(str _i))), [], 0, "CAN_COLLIDE"];
			_debug1 setDir-90;

		};
		for "_i" from 5 to 8 do {
			_class = selectRandom _cloneClasses;
			_debug1 = createVehicle[_class, (_debug modelToWorld(_debug selectionPosition(str _i))), [], 0, "CAN_COLLIDE"];
			_debug1 setDir 90;
		};
	};
	// spawn lights
	{
		_lightLocation = _debug modelToWorld _x;
		_light = createVehicle["Land_PortableLight_double_F", _lightLocation, [], 0, "CAN_COLLIDE"];
		_light setDir (_debugLocation getDir _lightLocation);
		_light setpos _lightLocation;
	} forEach (getArray(_configWorld >> "lightPos"));
};

// spawn area props
{
	_x params [
		["_class",""],
		["_pos",[0,0,0]],
		["_dir",0],
		["_disableSim","true"],
		["_dynSim","false"],
		["_allowDmg","false"],
		["_dmg",0]
	];

	_ep = createVehicle[_class, _pos, [], 0, "CAN_COLLIDE"];
	_ep setposATL _pos;
	if (_dir isEqualType []) then{
		_ep setVectorDirAndUp _dir;
	} else {
		_ep setDir _dir;
	};
	_deSimulate = _class isKindOf "ThingX";
	if((_deSimulate) || (_disableSim isEqualTo "true"))then{
		_ep enableSimulationGlobal false;
	};
	if([configFile >> "CfgEpochServer", "enableDynamicSimulationSystem", true] call EPOCH_fnc_returnConfigEntry) then {
		_ep enableDynamicSimulation (_dynSim isEqualTo "true");
	};
	_ep allowDamage (_allowDmg isEqualTo "true");
	_ep setDamage (_dmg min 0.75);
} forEach(getArray(_configWorld >> "propsPos"));

{
	_x params ["_enterClass","_pos1","_exitClass","_pos",["_useWorldPos",false]];

	// allow forth position element to set direction if set
	_dir1 = 0;
	_dir2 = 0;
	if (count _pos1 >= 4) then {
		_dir1 = _pos1 deleteAt 3;
	};

	if !(_useWorldPos) then {
		_pos1 = asltoatl (_debug modeltoworldworld _pos1);
	};

	// allow forth position element to set direction if set
	if (_pos isEqualType [] && {count _pos >= 4}) then {
		_dir2 = _pos deleteAt 3;
	};

	// load template props for marker location
	if (_pos isEqualType "") then {
		_markerName = _pos;
		_pos = getMarkerPos _markerName;
		["ProtectionZone_Invisible_F",_markerName,_pos,_class] call _loadBaseTemplateConfig;
	} else {
		_pro2 = createVehicle ["ProtectionZone_Invisible_F", _pos, [], 0, "CAN_COLLIDE"];
	};



	_pro1 = createVehicle ["ProtectionZone_Invisible_F", _pos1, [], 0, "CAN_COLLIDE"];
	_veh1 = createVehicle[_enterClass, _pos1, [], 0, "CAN_COLLIDE"];
	// force addaction on any other objects that are not setup properly
	if !(_veh1 isKindOf "Transport_EPOCH") then {
		[_veh1, [(localize "STR_EPOCH_Teleport"), {(_this select 0) call EPOCH_EnterBuilding}, [], 1, true, true, "Action", "alive _target", 3, false, ""]] remoteExec ["addAction", -2, _veh1, true];
	};
	_veh1 enableSimulationGlobal false;
	_veh1 allowDamage false;
	_veh1 setVariable["ParentBuilding", _pos];
	_veh1 setDir _dir1;
	_veh1 setposATL _pos1;

	if (_exitClass != "") then {
		_veh2 = createVehicle[_exitClass, _pos, [], 0, "CAN_COLLIDE"];
		// force addaction on any other objects that are not setup properly
		if !(_veh2 isKindOf "Transport_EPOCH") then {
			[_veh2, [(localize "STR_EPOCH_Teleport"), {(_this select 0) call EPOCH_EnterBuilding}, [], 1, true, true, "Action", "alive _target", 3, false, ""]] remoteExec ["addAction", -2, _veh1, true];
		};
		_veh2 enableSimulationGlobal false;
		_veh2 allowDamage false;
		_veh2 setVariable["ParentBuilding", _pos1];
		_veh2 setDir _dir2;
		_veh2 setposATL _pos;
	};

	EPOCH_staticTraderLocations pushBack _pos;
} foreach (getArray(_configWorld >> "telePos"));
