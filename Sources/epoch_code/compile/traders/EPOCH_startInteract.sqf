closeDialog 0;
_dialog = "";
_handled = false;
_forceGear = false;
_target = objNull;
_ctrl = _this;

_vehicle = vehicle player;
if (_vehicle != player) exitWith {false};
if (!isNull cursorTarget) then {
	if ((player distance cursorTarget) < 6) then {
		_target = cursorTarget;
	};
};
if (isNull _target) then {
	_targets = nearestObjects [getPosATL player, ["WeaponHolder", "WeaponHolderSimulated"], 3];
	if !(_targets isEqualTo []) then {
		_target = _targets select 0;
		_forceGear = true;
	};
};

if (!isNull _target) then {
	
	if (alive _target) then {
		/*
		if ((_target isKindOf "LandVehicle") || (_target isKindOf "Air") || (_target isKindOf "Ship") || (_target isKindOf "Tank")) then {
			_dialog = "InteractVehicle";	
		};
		
		if (_ctrl) then {
			if (_target isKindOf "Constructions_static_F" || _target isKindOf "Constructions_foundation_F") then {
				_dialog = "InteractBaseBuilding";
			};
		};
		*/
		/*
		if (_target isKindOf "Man") then {
			if (_target != player) then {
				if (!isPlayer _target) then {
					if ((_target getVariable["AI_SLOT", -1]) != -1) then {
						_dialog = "InteractNPC";
					};
				};
			};
		};
		*/
	};
	
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