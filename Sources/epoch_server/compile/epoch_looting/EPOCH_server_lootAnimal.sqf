private["_item", "_class", "_pos", "_objectClass", "_object", "_player"];

_object = _this select 0;
_player = _this select 1;

if !([_player, _this select 2] call EPOCH_server_getPToken) exitWith{};

if !(isNull _object) then {
	_pos = getPosATL _object;
	_objectClass = typeOf _object;

	deleteVehicle _object;

	_item = createVehicle["groundWeaponHolder", _pos, [], 0.0, "CAN_COLLIDE"];
	_item setPosATL _pos;

	_class = "SeaFood";
	_config = configFile >> "CfgMainTable" >> _objectClass;
	if (isClass(_config)) then {
		_class = _objectClass;
	};
	[_item, _class] call EPOCH_serverLootObject;
};
true