/*
	Author: Niklas Wagner - EpochMod.com

    Contributors: Aaron Clark

	Description:
	TODO: DESC-TBA

    Licence:
    Arma Public License Share Alike (APL-SA) - https://www.bistudio.com/community/licenses/arma-public-license-share-alike

    Github:
    https://github.com/EpochModTeam/Epoch/tree/release/Sources/epoch_code/gui/group/EPOCH_Group_invitePlayer.sqf
*/
if !(_this in Epoch_invited_tempGroupUIDs) then {
  Epoch_invited_tempGroupUIDs pushBack _this;
  ["Temp Group request received", 5] call Epoch_message;
};
