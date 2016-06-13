/*
	Author: Aaron Clark - EpochMod.com

    Contributors:

	Description:
	Save player with token check for use with RemoteExec

    Licence:
    Arma Public License Share Alike (APL-SA) - https://www.bistudio.com/community/licenses/arma-public-license-share-alike

    Github:
    https://github.com/EpochModTeam/Epoch/tree/release/Sources/epoch_server/compile/epoch_player/EPOCH_fnc_savePlayer.sqf
*/
params ["_player","",["_token","",[""]]];
if([_player,_token] call EPOCH_server_getPToken)then{
    _this call EPOCH_server_savePlayer
}
