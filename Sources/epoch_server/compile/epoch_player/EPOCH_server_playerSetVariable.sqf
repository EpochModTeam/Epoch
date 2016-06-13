/*
	Author: Andrew Gregory - EpochMod.com

    Contributors:

	Description:
    Call setVariable on specific client.

    Licence:
    Arma Public License Share Alike (APL-SA) - https://www.bistudio.com/community/licenses/arma-public-license-share-alike

    Github:
    https://github.com/EpochModTeam/Epoch/tree/release/Sources/epoch_server/compile/epoch_antagonists/EPOCH_server_playerSetVariable.sqf
*/
params ["_player","_token","_obj", "_var", "_value", "_local"];
if !([_player,_token]call EPOCH_server_getPToken)exitWith{};
diag_log format["Epoch: ADMIN: Attempting Set variable [%2,%3,%4] on %1.", _obj, _var, _value,_local];
[_obj, _var,_value,_local] remoteExec ['EPOCH_fnc_playerSetVariable', _obj];