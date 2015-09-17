/*
Building Save function

Epoch Mod - EpochMod.com
All Rights Reserved.
*/
private ["_class","_worldspace","_objHiveKey","_animPhases","_VAL","_return","_objSlot"];
_return = false;
if !(isNull _this) then {
	_objSlot = _this getVariable["BUILD_SLOT", -1];
	if (_objSlot != -1) then{
    _this setDamage 0;
    _class = typeOf _this;
    _worldspace = [(getposATL _this call EPOCH_precisionPos), vectordir _this, vectorup _this];
		_objHiveKey = format["%1:%2", (call EPOCH_fn_InstanceID), _objSlot];
		_animPhases = [];
		{
			_animPhases pushBack (_this animationPhase _x)
		} foreach (getArray(configFile >> "CfgVehicles" >> _class >> "persistAnimations"));
		_VAL = [_class, _worldspace, _this getVariable["EPOCH_secureStorage", "-1"], _this getVariable["BUILD_OWNER", "-1"], _this getVariable["TEXTURE_SLOT", 0], _animPhases];
		["Building", _objHiveKey, EPOCH_expiresBuilding, _VAL] call EPOCH_fnc_server_hiveSETEX;
    _return = true;
	};
};
_return
