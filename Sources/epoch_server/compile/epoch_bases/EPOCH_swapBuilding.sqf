// _newObj = [_class,_object] call EPOCH_swapBuilding;
//[[[cog import generate_private_arrays ]]]
private ["_newObj","_objectPos"];
//[[[end]]]
params [["_class",""],["_object",objNull],["_method",0]];
_newObj = objNull;
if (!isNull _object && !(_class isEqualTo "")) then {
    _objectPos = getPosWorld _object;
    _newObj = createVehicle [_class, ASLtoAGL _objectPos, [], 0, "CAN_COLLIDE"];
    if (!isNull _newObj) then {
        _object hideObjectGlobal true;
        switch (_method) do {
            case 0: {
                _newObj setposATL (getPosATL _object);
				_newObj setDir (getDir _object);
				_newObj setVectorDirAndUp [vectorDir _object, vectorUP _object];
            };
            case 1: {
                _newObj attachTo [_object,[0,0,0]];
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
		if (_class in _DisableDoorsOnObj) then {
			_baseObj setvariable ["bis_disabled_door",1,true];
			_baseObj setvariable ["bis_disabled_hatch",1,true];
		};
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
