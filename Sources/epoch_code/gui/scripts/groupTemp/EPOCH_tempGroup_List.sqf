/*
	Author: Niklas Wagner - EpochMod.com

    Contributors: Aaron Clark

	Description:
	TODO: DESC-TBA

    Licence:
    Arma Public License Share Alike (APL-SA) - https://www.bistudio.com/community/licenses/arma-public-license-share-alike

    Github:
    https://github.com/EpochModTeam/Epoch/tree/release/Sources/epoch_code/gui/groupTemp/EPOCH_tempGroup_List.sqf
*/
disableSerialization;
//[[[cog import generate_private_arrays ]]]
private ["_BtnKick","_BtnSetMod","_img"];
//[[[end]]]
params ["_ctrl","_selected"];

if (getPlayerUID player == Epoch_my_tempGroupUID) then {
	_img = _ctrl lbPicture _selected;

	_BtnSetMod = (findDisplay -1300) displayCtrl 32;
	_BtnKick = (findDisplay -1300) displayCtrl 33;

	switch _img do {
		case {getPlayerUID player == _ctrl lbData _selected}:{_BtnSetMod ctrlEnable false;_BtnKick ctrlEnable false};
		case(EPOCH_group_level_img select 0) : {_BtnSetMod ctrlEnable false; _BtnKick ctrlEnable false};
		case(EPOCH_group_level_img select 1) : {_BtnSetMod ctrlEnable true; _BtnKick ctrlEnable true; _BtnSetMod ctrlSetText "Remove Mod"};
		case(EPOCH_group_level_img select 2) : {_BtnSetMod ctrlEnable true; _BtnKick ctrlEnable true; _BtnSetMod ctrlSetText "Set Mod"};
	};
	true
} else {
	if (_selected != -1) then {
		_ctrl lbSetCurSel -1;
	};
	false
};
