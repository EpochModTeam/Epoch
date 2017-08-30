/*
	Author: Niklas Wagner - EpochMod.com

    Contributors: Aaron Clark

	Description:
	TODO: DESC-TBA

    Licence:
    Arma Public License Share Alike (APL-SA) - https://www.bistudio.com/community/licenses/arma-public-license-share-alike

    Github:
    https://github.com/EpochModTeam/Epoch/tree/release/Sources/epoch_code/gui/groupTemp/EPOCH_cTempGroup_onLoad.sqf
*/
//[[[cog import generate_private_arrays ]]]
private ["_textCtrl"];
//[[[end]]]
if!(Epoch_my_tempGroup isEqualTo [])exitWith {(findDisplay -1200) closeDisplay 0};
disableSerialization;
_textCtrl = (findDisplay -1200) displayCtrl 22;
_textCtrl CtrlSetText format ["%1, Temp Groups are free forever",name player];
