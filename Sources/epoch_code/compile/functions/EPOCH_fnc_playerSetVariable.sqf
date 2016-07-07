/*
	Author: Andrew Gregory - EpochMod.com

    Contributors:

	Description:
	call setVariable from client. Allows the server to call and set a local variable on an object via a player without broadcasting.

    Licence:
    Arma Public License Share Alike (APL-SA) - https://www.bistudio.com/community/licenses/arma-public-license-share-alike

    Github:
    https://github.com/EpochModTeam/Epoch/tree/release/Sources/epoch_code/compile/functions/EPOCH_fnc_playerSetVariable.sqf

    Example:
    [_obj,_var,_value,_local] call EPOCH_fnc_playerSetVariable;

    Parameter(s):
		_this select 0: OBJECT - Object to attach variable to
        _this select 1: STRING - Variable Name
		_this select 2: ANYTHING - Variable Value
        _this select 3: BOOLEAN - Broadcast ?
	Returns:

*/

params ["_obj", "_var", "_value", "_local"];
if(isNil "_local")then{_local = false;};
diag_log format["Epoch: ADMIN: Attempting Set variable [%2,%3,%4] on %1.", _obj, _var, _value,_local];
_obj setVariable [_var,_value,_local];