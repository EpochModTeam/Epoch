// store all interacted vehicles for update
private ["_vehSlot"];
0 call EPOCH_refeshUI;
if (!isNull _this) then {
	_vehSlot = _this getVariable ["VEHICLE_SLOT", "ABORT"];
	if (_vehSlot != "ABORT") then {
		if !(_this in EPOCH_arr_interactedObjs) then {
			EPOCH_arr_interactedObjs pushBack _this;
		};
	};
	_storSlot = _this getVariable["STORAGE_SLOT", "ABORT"];
	if (_storSlot != "ABORT") then {
		if !(_this in EPOCH_arr_interactedObjs) then {
			EPOCH_arr_interactedObjs pushBack _this;
		};
	};
};
true
