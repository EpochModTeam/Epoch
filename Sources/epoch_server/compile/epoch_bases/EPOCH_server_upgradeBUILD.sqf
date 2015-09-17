/*
Building Upgrades

Epoch Mod - EpochMod.com
All Rights Reserved.
*/
private["_worldspace", "_class", "_newObj", "_objHiveKey", "_VAL", "_return", "_upgrade", "_objSlot", "_objType", "_object", "_player"];

_object = _this select 0;
_player = _this select 1;
_index = param [2,0];

if (isNull _object) exitWith{};
if !([_player, _this select 3] call EPOCH_server_getPToken) exitWith{};

_objSlot = _object getVariable["BUILD_SLOT", -1];
if (_objSlot != -1) then {
	_config = 'CfgBaseBuilding' call EPOCH_returnConfig;

	_upgrades = getArray(_config >> (typeOf _object) >> "upgradeBuilding");
	if !(_upgrades isEqualTo []) then {

		_upgrade = _upgrades param [_index,[]];

		_objectPos = getposATL _object;
		_worldspace = [(_objectPos call EPOCH_precisionPos), vectordir _object, vectorup _object];

		deleteVehicle _object;
		_class = _upgrade select 0;

		_newObj = createVehicle [_class, _objectPos, [], 0, "CAN_COLLIDE"];
		_newObj setVariable ["BUILD_SLOT",_objSlot,true];
		_newObj call EPOCH_server_buildingInit;
		_newObj setVectorDirAndUp [(_worldspace select 1),(_worldspace select 2)];
		_newObj setposATL _objectPos;

		_newObj call EPOCH_fnc_saveBuilding;

		diag_log format["DEBUG upgrade BUILD : %1 slot %2", _object, _objSlot];
	};
} else {
	_objType = typeOf _object;
	if (getNumber(configFile >> "CfgVehicles" >> _objType >> "isTemporary") == 1) then{
		_config = 'CfgBaseBuilding' call EPOCH_returnConfig;

		_upgrades = getArray(_config >> (typeOf _object) >> "upgradeBuilding");
		if !(_upgrades isEqualTo []) then {

			_upgrade = _upgrades param [_index,[]];

			_worldspace = [getposATL _object, vectordir _object, vectorup _object];
			deleteVehicle _object;
			_class = _upgrade select 0;

			_newObj = createVehicle[_class, (_worldspace select 0), [], 0, "CAN_COLLIDE"];
			_newObj setVectorDirAndUp[(_worldspace select 1), (_worldspace select 2)];
			_newObj setposATL(_worldspace select 0);

			diag_log format["DEBUG upgrade BUILD : %1 slot %2", _object, _objSlot];
		};
	};
};
