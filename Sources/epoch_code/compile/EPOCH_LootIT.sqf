/*
	Author: Aaron Clark - EpochMod.com

    Contributors:

	Description:
	Request loot event

    Licence:
    Arma Public License Share Alike (APL-SA) - https://www.bistudio.com/community/licenses/arma-public-license-share-alike

    Github:
    https://github.com/EpochModTeam/Epoch/tree/release/Sources/epoch_code/compile/EPOCH_LootIT.sqf
*/
if (!isNull _this) then {
	[_this,player,Epoch_personalToken] remoteExec ["EPOCH_server_lootContainer",2];
};
