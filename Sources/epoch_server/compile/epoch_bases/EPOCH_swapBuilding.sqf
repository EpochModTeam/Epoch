// _newObj = [_class,_object] call EPOCH_swapBuilding;
//[[[cog import generate_private_arrays ]]]
private ["_newObj","_objectPos","_owner","_UpdatePlots"];
//[[[end]]]
params [["_class",""],["_object",objNull],["_method",0]];
_newObj = objNull;
if (!isNull _object && !(_class isEqualTo "")) then {
    _objectPos = getPosWorld _object;
    _newObj = createVehicle [_class, ASLtoAGL _objectPos, [], 0, "CAN_COLLIDE"];
    if (!isNull _newObj) then {
		_owner = _object getvariable ["Build_Owner",""];
		if !(_owner isEqualTo "") then {
			_newObj setVariable ["BUILD_OWNER", _owner, true];
		};
		_UpdatePlots = false;
		if (_object in EPOCH_Plotpoles) then {
			EPOCH_Plotpoles = EPOCH_Plotpoles - [_object];
			_UpdatePlots = true;
		};
		if (_class in (call EPOCH_JammerClasses)) then {
			EPOCH_Plotpoles pushback _newObj;
			_UpdatePlots = true;
		};
		if (_UpdatePlots) then {
			publicvariable 'EPOCH_Plotpoles';
		};
        _object hideObjectGlobal true;
        switch (_method) do {
            case 0: {
                _newObj setposATL (getPosATL _object);
				_newObj setDir (getDir _object);
				_newObj setVectorDirAndUp [vectorDir _object, vectorUP _object];
            };
            case 1: {
                _newObj attachTo [_object,[0,0,0]];
		detach _newObj;
            };
			/*
			case 2: {
				_newObj setPosWorld _objectPos;
				_newObj setDir (getDir _object);
                _newObj setVectorUp (vectorup _object);
            };
			*/
        };
        deleteVehicle _object;

		_serverSettingsConfig = configFile >> "CfgEpochServer";
		_UseIndestructible = [_serverSettingsConfig, "UseIndestructible", false] call EPOCH_fnc_returnConfigEntry;
		_IndestructibleBaseObjects = [_serverSettingsConfig, "IndestructibleBaseObjects", []] call EPOCH_fnc_returnConfigEntry;
		_ExceptedBaseObjects = [_serverSettingsConfig, "ExceptedBaseObjects", []] call EPOCH_fnc_returnConfigEntry;
		_DisableDoorsOnObj = [_serverSettingsConfig, "DisableDoorsOnObj", []] call EPOCH_fnc_returnConfigEntry;
		{
			_x params ["_ClassX",["_VarsX",[]]];
			if ((tolower _class) isequalto (tolower _ClassX)) exitwith {
				{
					_x params ["_VarNameX","_ValueX"];
					_newObj setvariable [_VarNameX,_ValueX,true];
				} foreach _VarsX;
			};
		} foreach _DisableDoorsOnObj;
		if (_UseIndestructible) then {
			if ({_class iskindof _x} count _ExceptedBaseObjects == 0) then {
				{
					if (_class iskindof _x) exitwith {
						_newObj allowdamage false;
					};
				} foreach _IndestructibleBaseObjects;
			};
		};
		// new Dynamicsimulation
		if([configFile >> "CfgEpochServer", "baseDynamicSimulationSystem", true] call EPOCH_fnc_returnConfigEntry)then
		{
			_newObj enableDynamicSimulation true;
			_newObj triggerDynamicSimulation false; // this object doesnt need to turn anything on in the server
		};
    };
};
_newObj
