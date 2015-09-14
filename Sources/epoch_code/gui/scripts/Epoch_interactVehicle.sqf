private["_mode","_display","_vehicle","_isLock"];
_mode = [_this,0,"",[""]] call bis_fnc_param;
_display = [_this,1,displayNull,[displayNull]] call bis_fnc_param;

_vehicle = cursorTarget;

if (vehicle player != player) then {
	_vehicle = vehicle player;
};

if (isNull _vehicle) exitWith { closeDialog 0 };
disableSerialization;

_isLock = locked _vehicle in [2,3];
switch _mode do {
	case "onLoad": {
		if !((crew _vehicle) isEqualTo []) then {
			(_display displayCtrl 2400) ctrlEnable false;
		};
		if (_isLock) then {
			(_display displayCtrl 2400) ctrlEnable false; //Lock Button
			(_display displayCtrl 2402) ctrlEnable false; //Inspect Button
		} else {
			(_display displayCtrl 2401) ctrlEnable false; //Unlock Button
		};
	};
	case "Lock": {
		if (!_isLock) then {
			EPOCH_lockVehicle_PVS = [_vehicle, true, player, Epoch_personalToken];
			publicVariableServer "EPOCH_lockVehicle_PVS";
		};
		closeDialog 0;
	};
	case "Unlock": {
		if (_isLock) then {
			EPOCH_lockVehicle_PVS = [_vehicle, false, player, Epoch_personalToken];
			publicVariableServer "EPOCH_lockVehicle_PVS";
		};
		closeDialog 0;
	};

	default { closeDialog 0 };
};