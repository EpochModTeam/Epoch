/*
	Author: Niklas Wagner - EpochMod.com

    Contributors: Aaron Clark

	Description:
	TODO: DESC-TBA

    Licence:
    Arma Public License Share Alike (APL-SA) - https://www.bistudio.com/community/licenses/arma-public-license-share-alike

    Github:
    https://github.com/EpochModTeam/Epoch/tree/release/Sources/epoch_code/gui/group/EPOCH_iGroup_onLoad.sqf
*/
disableSerialization;
//[[[cog import generate_private_arrays ]]]
private ["_display","_text"];
//[[[end]]]
_display = findDisplay -1400;
if (Epoch_invited_GroupUID == "" || Epoch_invited_GroupName == "") exitWith { _display closeDisplay 0};
_text = _display displayCtrl 21;
_text ctrlSetText format ["Join the group called %1?",Epoch_invited_GroupName];
