/*
	Author: Niklas Wagner - EpochMod.com

    Contributors: Aaron Clark

	Description:
	TODO: DESC-TBA

    Licence:
    Arma Public License Share Alike (APL-SA) - https://www.bistudio.com/community/licenses/arma-public-license-share-alike

    Github:
    https://github.com/EpochModTeam/Epoch/tree/master/Sources/epoch_code/gui/group/EPOCH_Group_invitePlayer.sqf
*/
if !(_this in Epoch_invited_GroupUIDs) then {
  Epoch_invited_GroupUIDs pushBack _this;
  ["<t size = ""1.6"" color = ""#99ffffff"">Group request received</t>", 5] call Epoch_dynamicText;
};
