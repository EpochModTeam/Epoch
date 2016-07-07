/*
	Author: Niklas Wagner - EpochMod.com

    Contributors: Aaron Clark

	Description:
	TODO: DESC-TBA

    Licence:
    Arma Public License Share Alike (APL-SA) - https://www.bistudio.com/community/licenses/arma-public-license-share-alike

    Github:
    https://github.com/EpochModTeam/Epoch/tree/release/Sources/epoch_code/gui/group/EPOCH_iGroup_acceptInvite.sqf
*/
if (Epoch_invited_GroupUID != "") then {
	[Epoch_invited_GroupUID,getPlayerUID player,true,false,player,Epoch_personalToken] remoteExec ["EPOCH_server_updatePlayerGroup",2];
};
(findDisplay -1500) closeDisplay 0;
