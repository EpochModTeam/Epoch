// TODO remove unused file
//[[[cog import generate_private_arrays ]]]
private ["_dialog","_forceGear","_handled","_target","_targets","_vehicle"];
//[[[end]]]
closeDialog 0;
_dialog = "";
_handled = false;
_forceGear = false;
_target = objNull;

// params ["_ctrl"];

_vehicle = vehicle player;
if (_vehicle != player) exitWith {false};
if (!isNull cursorTarget) then {
	if ((player distance cursorTarget) < 6) then {
		_target = cursorTarget;
	};
};
if (isNull _target) then {
	_targets = nearestObjects [player, ["WeaponHolder", "WeaponHolderSimulated"], 3];
	if !(_targets isEqualTo []) then {
		_target = _targets select 0;
		_forceGear = true;
	};
};

if (!isNull _target) then {
	if (_forceGear) then {
		player action ["Gear", _target];
		_handled = true;
	} else {
		if (_dialog != "") then {
			_handled = createdialog _dialog;
			setMousePosition [0.5, 0.5];
		};
	};
};
_handled
