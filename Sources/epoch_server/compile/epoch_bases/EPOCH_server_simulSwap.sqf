/*
Building - Sim to Static

Epoch Mod - EpochMod.com
All Rights Reserved.
*/
private["_cfgClass", "_worldspace", "_newObj", "_return", "_class", "_oemType", "_config", "_object", "_objSlot", "_damage", "_color", "_textureSlot"];

_object = _this select 0;
_return = _object;

_objSlot = _object getVariable ["BUILD_SLOT", -1];
if (_objSlot != -1) then {

	_cfgClass = "staticClass";
	if (_this select 1) then {
		_cfgClass = "simulClass";
	};
	_oemType = typeOf _object;

	_config = (configFile >> "CfgVehicles" >> _oemType >> _cfgClass);
	if (isText _config) then {
		_class = getText(_config);

		if (_oemType != _class) then {

			_textureSlot = _object getVariable["TEXTURE_SLOT", 0];
			_damage = damage _object;

			_worldspace = [getposATL _object,vectordir _object,vectorup _object];
			deleteVehicle _object;

			_newObj = createVehicle [_class, _worldspace select 0, [], 0, "CAN_COLLIDE"];
			_newObj setVariable ["BUILD_SLOT",_objSlot,true];
			_newObj call EPOCH_server_buildingInit;

			if (_textureSlot != 0) then {
				// get texture path from index
				_color = getArray(configFile >> "CfgVehicles" >> _class >> "availableTextures");
				if !(_color isEqualTo[]) then {
					_newObj setObjectTextureGlobal[0, (_color select _textureSlot)];
					_newObj setVariable["TEXTURE_SLOT", _textureSlot, true];
				};
			};

			// spawn additional object for trap
			_ammoClass = (configFile >> "CfgVehicles" >> _class >> "ammoClass");
			if (isText _ammoClass) then {
				_ammoClass = getText _ammoClass;
				_ammoObj = createVehicle [_ammoClass, _worldspace select 0, [], 0, "CAN_COLLIDE"];
				_ammoObj setVectorDirAndUp [(_worldspace select 1),(_worldspace select 2)];
				_ammoObj setposATL (_worldspace select 0);
				_newObj setVariable ["EPOCH_TRAP_OBJ",_ammoObj];
			};

			_newObj setVectorDirAndUp [(_worldspace select 1),(_worldspace select 2)];
			_newObj setposATL (_worldspace select 0);
			_newObj	setDamage _damage;
			_return = _newObj;

		};
	};
};
_return
