private ["_vehSlot"];
{
	_vehSlot = _x getVariable ["VEHICLE_SLOT", "ABORT"];
	if (_vehSlot != "ABORT") then {
		EPOCH_saveVehQueue pushBackUnique _x;
	};
	_storSlot = _x getVariable["STORAGE_SLOT", "ABORT"];
	if (_storSlot != "ABORT") then {
		EPOCH_saveStorQueue pushBackUnique _x;
	};
	_objSlot = _x getVariable["BUILD_SLOT", -1];
	if (_objSlot != -1) then{
		EPOCH_saveBuildQueue pushBackUnique _x;
	};
} forEach _this;
