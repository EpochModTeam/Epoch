private ["_vehicle","_vehSlot","_vehHiveKey","_storage","_killer"];

_storage = _this select 0;
_killer = _this select 1;

if (!isNull _storage) then {
	_vehSlot = _storage getVariable["STORAGE_SLOT", "ABORT"];
	if (_vehSlot != "ABORT") then {
		_vehHiveKey = format ["%1:%2", (call EPOCH_fn_InstanceID), _vehSlot];
		["Storage", _vehHiveKey] call EPOCH_fnc_server_hiveDEL;

		EPOCH_StorageSlots pushBack _vehSlot;

		EPOCH_StorageSlotsCount = count EPOCH_StorageSlots;
		publicVariable "EPOCH_StorageSlotsCount";

		['StorageKilled', format["%1 was killed by %2 at %3", typeOf _storage, _killer, getPosATL _storage]] call EPOCH_fnc_server_hiveLog;
	};
};
