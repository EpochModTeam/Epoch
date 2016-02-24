/*
Building Save Damage

Epoch Mod - EpochMod.com
All Rights Reserved.

private["_class", "_worldspace", "_VAL", "_storageSlot", "_owner", "_textureSlot", "_arr", "_arrCount", "_bldHiveKey", "_response", "_vehicle", "_slot"];

_vehicle = _this;

if (alive _vehicle) then {
	_slot = _vehicle getVariable["BUILD_SLOT", -1];
	if (_slot != -1) then {

		_bldHiveKey = format["%1:%2", (call EPOCH_fn_InstanceID), _slot];
		_response = ["Building", _bldHiveKey] call EPOCH_fnc_server_hiveGETRANGE;

		if ((_response select 0) == 1 && (_response select 1) isEqualType [] && !((_response select 1) isEqualTo[])) then {
			_arr = _response select 1;
			_arrCount = count _arr;

			_class = _arr select 0;
			_worldspace = _arr select 1;

			_storageSlot = "-1";
			if (_arrCount >= 3) then {
				if ((_arr select 2) isEqualType 0) then {
					_storageSlot = str(_arr select 2);
				} else {
					_storageSlot = _arr select 2;
				};
			};

			_owner = "-1";
			if (_arrCount >= 4) then {
				_owner = _arr select 3;
			};

			_textureSlot = 0;
			if (_arrCount >= 5) then {
				_textureSlot = _arr select 4;
			};

			_VAL = [_class, _worldspace, _storageSlot, _owner, _textureSlot, damage _vehicle];
			["Building", _bldHiveKey, EPOCH_expiresBuilding, _VAL] call EPOCH_fnc_server_hiveSETEX;

		};
	};
};

*/
