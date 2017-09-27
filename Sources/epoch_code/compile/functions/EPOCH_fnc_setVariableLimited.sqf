/*
	Author: Aaron Clark - EpochMod.com

    Contributors:

	Description:
	Sets GVAR value within min/max limits.

    Licence:
    Arma Public License Share Alike (APL-SA) - https://www.bistudio.com/community/licenses/arma-public-license-share-alike

    Github:
    https://github.com/EpochModTeam/Epoch/tree/release/Sources/epoch_code/compile/functions/EPOCH_setVariableLimited.sqf

	Example:
    ["TEST",-30,100,0] call EPOCH_fnc_setVariableLimited; // removes 30 and keeps number within 0-100 range.

    Parameter(s):
		_this select 0: STRING - GVar variable key
        _this select 1: NUMBER - Change variable
		_this select 2: NUMBER - max Value
        _this select 3: NUMBER - min Value
	Returns:
		NUMBER
*/
params [["_key","",[""]],["_change",0],["_max",100],["_min",0]];
private _result = (((missionNamespace getVariable [_key, 0]) + _change) min _max) max _min;
missionNamespace setVariable [_key, _result];
_result
