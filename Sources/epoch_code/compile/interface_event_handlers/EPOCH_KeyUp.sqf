private["_dikCode", "_handled"];
params ["_display","_dikCode","_shift","_ctrl","_alt"];
_handled = false;

//Main actions

if (_dikCode == EPOCH_keysAction) then {
	EPOCH_keysActionPressed = false;
	true call Epoch_dynamicMenuCleanup;
};


_handled

