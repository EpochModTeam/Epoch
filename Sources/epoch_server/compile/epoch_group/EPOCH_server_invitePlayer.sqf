/*
	Author: Aaron Clark - EpochMod.com

    Contributors:

	Description:
	Invite Player

    Licence:
    Arma Public License Share Alike (APL-SA) - https://www.bistudio.com/community/licenses/arma-public-license-share-alike

    Github:
    https://github.com/EpochModTeam/Epoch/tree/master/Sources/epoch_server/compile/epoch_group/EPOCH_server_invitePlayer.sqf
*/
params ["_playerUID","_var1","_var2","_player","_token"];
if !([_player, _token] call EPOCH_server_getPToken) exitWith{};

{
	[_var1, _var2] remoteExec ['EPOCH_Group_invitePlayer',_x];
} forEach (allPlayers select {getPlayerUID _x == _playerUID});
