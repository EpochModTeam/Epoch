/*
	Author: Niklas Wagner - EpochMod.com

    Contributors: Aaron Clark

	Description:
	TODO: DESC-TBA

    Licence:
    Arma Public License Share Alike (APL-SA) - https://www.bistudio.com/community/licenses/arma-public-license-share-alike

    Github:
    https://github.com/EpochModTeam/Epoch/tree/release/Sources/epoch_code/gui/group/EPOCH_Group_Combo.sqf
*/
disableSerialization;
//[[[cog import generate_private_arrays ]]]
private ["_BtnInvite","_ctrl","_currentMember","_playerUID","_selected"];
//[[[end]]]

Epoch_my_Group params [
    ["_groupName",""],
    ["_leaderName",""],
    ["_groupSize",0],
    ["_modArray",[]],
    ["_memberArray",[]]
];

_ctrl = _this select 0;
_selected = _this select 1;
_playerUID = getPlayerUID player;
if (_playerUID == Epoch_my_GroupUID || {_x select 0 == _playerUID}count (_modArray) > 0) then {
	_BtnInvite = (findDisplay -1300) displayCtrl 30;
	_currentMember = count(_modArray) + count(_memberArray) + 1;
	if (_currentMember < _groupSize) then {
		_BtnInvite ctrlSetText format ["Invite %1",_ctrl lbtext _selected];
	};
	true
} else {
	if (_selected != -1) then {
		_ctrl lbSetCurSel -1;
	};
	false
};
