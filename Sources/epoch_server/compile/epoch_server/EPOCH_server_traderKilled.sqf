private ["_marker","_slot","_objHiveKey"];
if (!isNull (_this select 0)) then {
	_marker = (_this select 0) getVariable["MARKER_REF",""];
	if (_marker != "") then {
		_marker setMarkerColor "ColorRed";
	};

	_slot = (_this select 0) getVariable["AI_SLOT", -1];
	if (_slot != -1) then {
		// Spawn Drone on player
		[(_this select 1), "UAV"] call EPOCH_server_triggerEvent;

		_objHiveKey = format ["%1:%2", (call EPOCH_fn_InstanceID), _slot];
		["AI", _objHiveKey] call EPOCH_fnc_server_hiveDEL;
	};
};
