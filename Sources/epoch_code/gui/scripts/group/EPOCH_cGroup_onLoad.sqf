/*
	Author: Niklas Wagner - EpochMod.com

    Contributors: Aaron Clark

	Description:
	TODO: DESC-TBA

    Licence:
    Arma Public License Share Alike (APL-SA) - https://www.bistudio.com/community/licenses/arma-public-license-share-alike

    Github:
    https://github.com/EpochModTeam/Epoch/tree/release/Sources/epoch_code/gui/group/EPOCH_cGroup_onLoad.sqf
*/
//[[[cog import generate_private_arrays ]]]
private ["_textCtrl"];
//[[[end]]]
if (Epoch_my_GroupUID != "") exitWith {(findDisplay -1200) closeDisplay 0};
disableSerialization;
_textCtrl = (findDisplay -1200) displayCtrl 22;
if (EPOCH_playerCrypto < parseNumber(EPOCH_group_upgrade_lvl select 1)) then {
	_textCtrl CtrlSetText format ["Need %1 Krypto to create your own group",EPOCH_group_upgrade_lvl select 1];
} else {
	_textCtrl CtrlSetText format["Cost to create group %1 Krypto", EPOCH_group_upgrade_lvl select 1];
};
