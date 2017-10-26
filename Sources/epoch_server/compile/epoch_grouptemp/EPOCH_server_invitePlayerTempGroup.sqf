/*
	Author: Aaron Clark - EpochMod.com

    Contributors:

	Description:
	Invite Player

    Licence:
    Arma Public License Share Alike (APL-SA) - https://www.bistudio.com/community/licenses/arma-public-license-share-alike

    Github:
    https://github.com/EpochModTeam/Epoch/tree/release/Sources/epoch_server/compile/epoch_grouptemp/EPOCH_server_invitePlayerTempGroup.sqf
*/
params ["_playerUID","_var1","_var2","_player",["_token","",[""]]];
if !([_player, _token] call EPOCH_server_getPToken) exitWith{};
private _targets = allPlayers select {getPlayerUID _x == _playerUID};
if !(_targets isEqualTo []) then {
	[_var1, _var2] remoteExec ['EPOCH_tempGroup_invitePlayer',_targets];
};
