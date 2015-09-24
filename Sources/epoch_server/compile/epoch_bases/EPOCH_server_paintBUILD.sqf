/*
Building Paint

Epoch Mod - EpochMod.com
All Rights Reserved.
*/
private["_color", "_class", "_object", "_textureSlot", "_currentTextureSlot", "_plyr", "_slot", "_worldspace", "_objHiveKey", "_VAL", "_return", "_plyrUID", "_objSlot"];

_object = _this select 0;
_textureSlot = _this select 1;
_plyr = _this select 2;

if !([_plyr, _this select 3] call EPOCH_server_getPToken) exitWith{};
if (isNull _object) exitWith{};
if (_plyr distance _object > 20) exitWith{};

_plyrUID = getPlayerUID _plyr;

_objSlot = _object getVariable["BUILD_SLOT", -1];
if (_objSlot != -1) then {

	_currentTextureSlot = _object getVariable["TEXTURE_SLOT", 0];
	if (_textureSlot != _currentTextureSlot) then {

		// get texture path from index
		_class = typeOf _object;
		_color = getArray(configFile >> "CfgVehicles" >> _class >> "availableTextures");
		if !(_color isEqualTo[]) then {
			_object setObjectTextureGlobal[0, (_color select _textureSlot)];
			_object setVariable["TEXTURE_SLOT", _textureSlot, true];

			// save building with new color
			// _slot = "-1";
			// _worldspace = [(getposATL _object call EPOCH_precisionPos), (vectordir _object), (vectorup _object)];
			// _objHiveKey = format["%1:%2", (call EPOCH_fn_InstanceID), _objSlot];

			_object call EPOCH_fnc_saveBuilding;

			//_VAL = [_class, _worldspace, _slot, _plyrUID, _textureSlot, _animPhases];
			//_return = ["Building", _objHiveKey, EPOCH_expiresBuilding, _VAL] call EPOCH_fnc_server_hiveSETEX;
		};
	};
};
