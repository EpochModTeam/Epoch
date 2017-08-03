/*
	Author: Aaron Clark - EpochMod.com

    Contributors: Raymix

	Description:
	Key Up EH functions

    Licence:
    Arma Public License Share Alike (APL-SA) - https://www.bistudio.com/community/licenses/arma-public-license-share-alike

    Github:
    https://github.com/EpochModTeam/Epoch/tree/release/Sources/epoch_code/compile/interface_event_handlers/EPOCH_KeyUp.sqf

    Example:
    _this call EPOCH_KeyUp;

    Parameter(s):
		_this select 0: CONTROL - _display
		_this select 1: NUMBER - _dikcode
		_this select 2: BOOL - Shift State
		_this select 3: BOOL - Ctrl State
		_this select 4: BOOL - Alt State

	Returns:
	BOOL
*/
//[[[cog import generate_private_arrays ]]]
private ["_handled"];
//[[[end]]]
params ["_display","_dikCode","_shift","_ctrl","_alt"];
_handled = false;

_this call Epoch_custom_EH_KeyUp;
if (_handled) exitWith{ true };

if !(EPOCH_modKeys isequalto [_shift,_ctrl,_alt]) then {
	EPOCH_modKeys = [_shift,_ctrl,_alt];
	call epoch_favBar_modifier;
};

//Main actions
if (_dikCode == EPOCH_keysAction) then {
	EPOCH_keysActionPressed = false;
	true call Epoch_dynamicMenuCleanup;
};
if (_dikCode in(actionKeys "Gear")) then {
	EPOCH_gearKeyPressed = false;
};

_handled
