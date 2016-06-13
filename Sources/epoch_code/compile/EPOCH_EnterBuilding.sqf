/*
	Author: Aaron Clark - EpochMod.com

    Contributors:

	Description:
	Epoch request teleport

    Licence:
    Arma Public License Share Alike (APL-SA) - https://www.bistudio.com/community/licenses/arma-public-license-share-alike

    Github:
    https://github.com/EpochModTeam/Epoch/tree/release/Sources/epoch_code/compile/EPOCH_EnterBuilding.sqf
*/
if !(isNull _this) then{
	[player,_this,Epoch_personalToken] remoteExec ["EPOCH_server_teleportPlayer",2];
};
