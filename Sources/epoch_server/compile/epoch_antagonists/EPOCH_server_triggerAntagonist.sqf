/*
	Author: Andrew Gregory - EpochMod.com

    Contributors: Aaron Clark

	Description:
    Trigger an antagonist on a client. Option to add antagonist object to target as a variable.

    Licence:
    Arma Public License Share Alike (APL-SA) - https://www.bistudio.com/community/licenses/arma-public-license-share-alike

    Github:
    https://github.com/EpochModTeam/Epoch/tree/master/Sources/epoch_server/compile/epoch_antagonists/EPOCH_server_triggerAntagonist.sqf
*/
params ["_target","_antagonistClass","_doVariable","_player","_token"];
diag_log format["Epoch: ADMIN: Attempting antagonist (%3) trigger from %1 for %2.", getPlayerUID _player, _target, _antagonistClass];
if !([_player,_token]call EPOCH_server_getPToken)exitWith{};

if(!isNull _target)then{
diag_log format["Epoch: ADMIN: Calling antagonist (%3) trigger from %1 for %2.", getPlayerUID _player, _target, _antagonistClass];

[_antagonistClass, _target, _doVariable] remoteExec ["EPOCH_unitSpawn",_target];
//if(!isNull _player)then{hideObjectGlobal _player;};//Do elsewhere, allow revival
};
