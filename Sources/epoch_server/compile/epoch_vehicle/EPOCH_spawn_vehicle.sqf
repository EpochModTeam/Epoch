/*
  Epoch Vehicle Spawn Function
*/

_vehClass = _this select 0;
_position = _this select 1;
_direction =  _this select 2;
_locked = _this select 3;
_slot = _this select 4;

_lockOwner  =  param [5, ""];
_can_collide = param [6, "CAN_COLLIDE"];
_spawnLoot = param [7, false];
_spawnDamaged = param [8, true];

//diag_log format["DEBUG: spawn_vehicle %1", _this];

//place vehicle
_vehObj = createVehicle[_vehClass, _position, [], 0, _can_collide];

if !(isNull _vehObj) then{

	_vehObj call EPOCH_server_setVToken;

	// Set Direction
	if (typeName _direction == "ARRAY") then{
	  _vehObj setVectorDirAndUp _direction;
	} else {
	  _vehObj setdir _direction;
	};
	// Set Position
	_vehObj setposATL _position;

	// Normalize vehicle inventory
	clearWeaponCargoGlobal    _vehObj;
	clearMagazineCargoGlobal  _vehObj;
	clearBackpackCargoGlobal  _vehObj;
	clearItemCargoGlobal	  _vehObj;

	// Disable Termal Equipment
	_vehObj disableTIEquipment true;

	// Vehicle Lock
	_vehObj lock _locked;

	// randomize fuel TODO push min max to config
	_vehObj setFuel ((random 1 max 0.1) min 0.9);

	// add random damage to vehicles (avoid setting engine or fuel to 100% damage to prevent instant destruction)
	if (_spawnDamaged) then {
		{
			_maxDamage = if (_x in ["HitEngine","HitFuel"]) then {0.9} else {1};
			_vehObj setHitIndex [_forEachIndex,random(_maxDamage)];
		} forEach ((getAllHitPointsDamage _vehObj) param [0,[]]);
	};

	// get colors from config
	_config = (configFile >> "CfgVehicles" >> _vehClass >> "availableColors");

	if (isArray(_config)) then{

	  _textureSelectionIndex = configFile >> "CfgVehicles" >> _vehClass >> "textureSelectionIndex";
	  _selections = if (isArray(_textureSelectionIndex)) then{ getArray(_textureSelectionIndex) } else { [0] };
	  _colors = getArray(_config);
	  _textures = _colors select 0;
	  _color = floor(random(count _textures));
	  _count = (count _colors) - 1;
	  {
		if (_count >= _forEachIndex) then{
		  _textures = _colors select _forEachIndex;
		};
		_vehObj setObjectTextureGlobal[_x, (_textures select _color)];
	  } forEach _selections;
	  _vehObj setVariable["VEHICLE_TEXTURE", _color];
	};

	// add random loots
	if (_spawnLoot) then {
	  if (_vehClass isKindOf "Ship") then{
		[_vehObj, "VehicleBoat"] call EPOCH_serverLootObject;
	  } else {
		[_vehObj, "Vehicle"] call EPOCH_serverLootObject;
	  };
	};

	// Set slot used by vehicle
	_vehObj setVariable["VEHICLE_SLOT", _slot, true];

	// Lock vehicle for owner
	if (_locked && _lockOwner != "") then {
	  _vehLockHiveKey = format["%1:%2", (call EPOCH_fn_InstanceID), _slot];
	  ["VehicleLock", _vehLockHiveKey, EPOCH_vehicleLockTime, [_lockOwner]] call EPOCH_fnc_server_hiveSETEX;
	} else {
	  _vehLockHiveKey = format["%1:%2", (call EPOCH_fn_InstanceID), _slot];
	  ["VehicleLock", _vehLockHiveKey] call EPOCH_fnc_server_hiveDEL;
	};

	// SAVE VEHICLE
	_vehObj call EPOCH_server_save_vehicle;

	// Event Handlers
	_vehObj call EPOCH_server_vehicleInit;

	// Markers
	if (EPOCH_DEBUG_VEH) then{
	  _marker = createMarker[str(_position), _position];
	  _marker setMarkerShape "ICON";
	  _marker setMarkerType "mil_dot";
	  _marker setMarkerText _vehClass;
	};

	// Add to A3 remains collector
	addToRemainsCollector[_vehObj];

} else {
	diag_log format["DEBUG: Failed to create vehicle: %1", _this];
};

_vehObj
