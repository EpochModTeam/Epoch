/*
	Author: Aaron Clark - EpochMod.com

    Contributors:

	Description:
	removes any non numeric chars and inforce number to max limit to a control.

    Licence:
    Arma Public License Share Alike (APL-SA) - https://www.bistudio.com/community/licenses/arma-public-license-share-alike

    Github:
    https://github.com/EpochModTeam/Epoch/tree/release/Sources/epoch_code/compile/interface_event_handlers/EPOCH_onChar.sqf

    Example:
    [_control,_maxLimit] call EPOCH_onChar;

    Parameter(s):
		_this select 0: CONTROL - _display
		_this select 0: NUMBER - max limit

	Returns:
	NOTHING
*/
//[[[cog import generate_private_arrays ]]]
private ["_num","_textArr"];
//[[[end]]]
params ["_control",["_maxLimit",0]];
_textArr = toArray(ctrlText(_control select 0));
{
	if !(_x in [48,49,50,51,52,53,54,55,56,57]) then {
		_textArr = _textArr - [_x];
	};
} forEach _textArr;
if (count _textArr > 10) then {
	_textArr resize 10;
};
_num = parseNumber(toString _textArr) min _maxLimit;
(_control select 0) ctrlSetText str(_num);
