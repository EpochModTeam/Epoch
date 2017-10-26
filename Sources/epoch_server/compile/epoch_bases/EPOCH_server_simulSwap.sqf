/*
	Author: Aaron Clark - EpochMod.com

    Contributors:

	Description:
    Building - Sim to Static

    Licence:
    Arma Public License Share Alike (APL-SA) - https://www.bistudio.com/community/licenses/arma-public-license-share-alike

    Github:
    https://github.com/EpochModTeam/Epoch/tree/release/Sources/epoch_server/compile/epoch_bases/EPOCH_server_simulSwap.sqf
*/
//[[[cog import generate_private_arrays ]]]
private ["_ammoClass","_ammoObj","_cfgBaseBuilding","_cfgClass","_class","_classConfig","_color","_damage","_newObj","_objSlot","_oemType","_return","_textureSlot","_worldspace"];
//[[[end]]]
params [["_object",objNull,[objNull]],["_static",false,[false]] ];
_return = _object;
_objSlot = _object getVariable ["BUILD_SLOT", -1];
if (_objSlot != -1) then {

	_cfgClass = "staticClass";
	if (_static) then {
		_cfgClass = "simulClass";
	};
	_oemType = typeOf _object;
	_cfgBaseBuilding = 'CfgBaseBuilding' call EPOCH_returnConfig;
	_classConfig = (_cfgBaseBuilding >> _oemType >> _cfgClass);
	if (isText _classConfig) then {
		_class = getText(_classConfig);

		if (_oemType != _class) then {

			_textureSlot = _object getVariable["TEXTURE_SLOT", 0];
			_damage = damage _object;

			//_worldspace = [getposATL _object,vectordir _object,vectorup _object];
			//_newObj = createVehicle [_class, [0,0,0], [], 0, "CAN_COLLIDE"];
			_newObj = [_class,_object] call EPOCH_swapBuilding;

			_newObj setVariable ["BUILD_SLOT",_objSlot,true];
			_newObj call EPOCH_server_buildingInit;

			if (_textureSlot != 0) then {
				// get texture path from index
				_color = getArray(_cfgBaseBuilding >> _class >> "availableTextures");
				if !(_color isEqualTo[]) then {
					_newObj setObjectTextureGlobal[0, (_color select _textureSlot)];
					_newObj setVariable["TEXTURE_SLOT", _textureSlot, true];
				};
			};

			// spawn additional object for trap
			_ammoClass = (_cfgBaseBuilding >> _class >> "ammoClass");
			if (isText _ammoClass) then {
				_ammoClass = getText _ammoClass;
				_ammoObj = createVehicle [_ammoClass, [0,0,0], [], 0, "CAN_COLLIDE"];
				_ammoObj attachTo [_newObj,[0,0,0]];
				_newObj setVariable ["EPOCH_TRAP_OBJ",_ammoObj];
				_newObj addEventHandler ["Explosion", {(_this select 0) setDamage 1}];
			};

			_newObj	setDamage _damage;
			_return = _newObj;
		};
	};
};
_return
