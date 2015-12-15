/*
	Author: Aaron Clark - EpochMod.com

    Contributors:

	Description:
	Key Up EH functions

    Licence:
    Arma Public License Share Alike (APL-SA) - https://www.bistudio.com/community/licenses/arma-public-license-share-alike

    Github:
    https://github.com/EpochModTeam/Epoch/tree/master/Sources/epoch_code/compile/interface_event_handlers/EPOCH_KeyUp.sqf

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
private["_handled"];
params ["_display","_dikCode","_shift","_ctrl","_alt"];
_handled = false;

//Main actions

if (_dikCode == EPOCH_keysAction) then {
	EPOCH_keysActionPressed = false;
	true call Epoch_dynamicMenuCleanup;
};


_handled
