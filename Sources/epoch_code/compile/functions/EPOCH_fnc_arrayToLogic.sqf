/*
	Author: Aaron Clark - EpochMod.com

	Contributors:

	Description:
	Converts array to boolean logic checks

	Licence:
	Arma Public License Share Alike (APL-SA) - https://www.bistudio.com/community/licenses/arma-public-license-share-alike

	Github:
	https://github.com/EpochModTeam/Epoch/tree/release/Sources/epoch_code/compile/functions/EPOCH_fnc_arrayToLogic.sqf

	Example:
	[1,">=",0] call EPOCH_fnc_arrayToLogic; // returns: true

	Parameter(s):
		_this select 0: NUMBER - First value
		_this select 1: STRING - compare operator
		_this select 2: NUMBER - Second value

	Returns:
	BOOL
*/
params [["_v",""],["_t",""],["_d",""]];
switch (_t) do {
	case ">=": {_v >= _d};
	case "<=": {_v <= _d};
	case "<": {_v < _d};
	case ">": {_v > _d};
	case "!=": {!(_v isEqualTo _d)};
	default {_v isEqualTo _d};
}
