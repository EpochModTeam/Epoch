/*
	Author: Andrew Gregory - EpochMod.com

    Contributors:

	Description:
	Dynamically call an FSM and return handle.

    Licence:
    Arma Public License Share Alike (APL-SA) - https://www.bistudio.com/community/licenses/arma-public-license-share-alike

    Github:
    https://github.com/EpochModTeam/Epoch/tree/master/Sources/epoch_code/compile/functions/EPOCH_fnc_dynamicFSM.sqf

    Example:
    _handle = [] call EPOCH_fnc_dynamicFSM.;

    Parameter(s):
		_this select 0: STRING - FSM Name (without the .fsm)
        _this select 1: STRING - FSM Path e.g. epoch_code\system
        _this select 2: ARRAY - Vars to pass to FSM

	Returns:
	HANDLE
*/
params ["_file","_path",["_vars",[]],["_ret",-1]];
call compile format["
_ret = _vars execFSM ""%1\%2.fsm"";
",_path,_file];
_ret
