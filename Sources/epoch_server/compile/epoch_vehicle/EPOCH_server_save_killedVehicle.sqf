private ["_vehicle","_vehSlot","_vehHiveKey","_killer"];

_vehicle = _this select 0;
_killer = _this select 1;

if (!isNull _vehicle) then {
	_vehSlot = _vehicle getVariable ["VEHICLE_SLOT", "ABORT"];
	if (_vehSlot != "ABORT") then {
		_vehHiveKey = format ["%1:%2", (call EPOCH_fn_InstanceID), _vehSlot];
		["Vehicle", _vehHiveKey] call EPOCH_fnc_server_hiveDEL;
		EPOCH_VehicleSlots pushBack _vehSlot;
		EPOCH_VehicleSlotCount = count EPOCH_VehicleSlots;
		publicVariable "EPOCH_VehicleSlotCount";

		['VehicleKilled', format["%1 was killed by %2 at %3", typeOf _vehicle, _killer, getPosATL _vehicle]] call EPOCH_fnc_server_hiveLog;
	};
};
