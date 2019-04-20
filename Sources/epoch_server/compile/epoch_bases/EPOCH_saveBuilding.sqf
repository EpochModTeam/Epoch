/*
	Author: Aaron Clark - EpochMod.com

    Contributors:

	Description:
    Building Save function

    Licence:
    Arma Public License Share Alike (APL-SA) - https://www.bistudio.com/community/licenses/arma-public-license-share-alike

    Github:
    https://github.com/EpochModTeam/Epoch/tree/release/Sources/epoch_server/compile/epoch_bases/EPOCH_saveBuilding.sqf
*/
//[[[cog import generate_private_arrays ]]]
private ["_VAL","_animPhases","_cfgBaseBuilding","_class","_objHiveKey","_objSlot","_return","_worldspace"];
//[[[end]]]
_return = false;
if !(isNull _this) then {
	_objSlot = _this getVariable["BUILD_SLOT", -1];
	if (_objSlot != -1) then{
		_cfgBaseBuilding = 'CfgBaseBuilding' call EPOCH_returnConfig;
		_this setDamage 0;
		_class = typeOf _this;
		_worldspace = [(getposATL _this call EPOCH_precisionPos), vectordir _this, vectorup _this];
		_objHiveKey = format["%1:%2", (call EPOCH_fn_InstanceID), _objSlot];
		_animPhases = [];
		{
			_animPhases pushBack (_this animationPhase _x)
		} foreach (getArray(_cfgBaseBuilding >> _class >> "persistAnimations"));

		_Textures = [];
		if (missionnamespace getvariable ["UseCustomTextures",false]) then {
			_Textures = getObjectTextures _this;
		};

		_VAL = [_class, _worldspace, _this getVariable["EPOCH_secureStorage", "-1"], _this getVariable["BUILD_OWNER", "-1"], _this getVariable["TEXTURE_SLOT", 0], _animPhases, _Textures];
		["Building", _objHiveKey, EPOCH_expiresBuilding, _VAL] call EPOCH_fnc_server_hiveSETEX;
		_return = true;
	};
};
_return
