private ["_vehSlot"];
{
	_vehSlot = _x getVariable ["VEHICLE_SLOT", "ABORT"];
	if (_vehSlot != "ABORT") then {
		if !(_x in EPOCH_saveVehQueue) then { EPOCH_saveVehQueue pushBack _x };
	};
	_storSlot = _x getVariable["STORAGE_SLOT", "ABORT"];
	if (_storSlot != "ABORT") then {
		if !(_x in EPOCH_saveStorQueue) then { EPOCH_saveStorQueue pushBack _x };
	};
	_objSlot = _x getVariable["BUILD_SLOT", -1];
	if (_objSlot != -1) then{
		if !(_x in EPOCH_saveBuildQueue) then{ EPOCH_saveBuildQueue pushBack _x };
	};
} forEach _this;