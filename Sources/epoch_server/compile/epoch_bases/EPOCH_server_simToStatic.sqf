/*
Building - Converts to static all simulated objects that have not moved since last check

Epoch Mod - EpochMod.com
All Rights Reserved.
*/
private ["_worldspace","_newObj","_class","_objSlot","_config","_lastPosition","_currentPosition","_entities"];
_entities = allMissionObjects "Constructions_modular_F";
{
	_lastPosition = _x getVariable["LAST_POS", []];
	_currentPosition = getposATL _x;
	if (_lastPosition isEqualTo _currentPosition) then {
		_config = (configFile >> "CfgVehicles" >> (typeOf _x) >> "staticClass");
		if (isText(_config)) then {
			_class = getText(_config);
			_objSlot = _x getVariable["BUILD_SLOT", -1];
			if (_objSlot != -1) then {
				_worldspace = [_currentPosition,(vectordir _x),(vectorup _x)];
				deleteVehicle _x;
				_newObj = createVehicle [_class, (_worldspace select 0), [], 0, "CAN_COLLIDE"];
				_newObj setVariable ["BUILD_SLOT",_objSlot,true];
				_newObj call EPOCH_server_buildingInit;
				_newObj setVectorDirAndUp [(_worldspace select 1),(_worldspace select 2)];
				_newObj setposATL (_worldspace select 0);
			};
		};
	};
	_x setVariable ["LAST_POS",_currentPosition];
	uiSleep 1;
} forEach _entities;