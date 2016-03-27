/*
	Author: Niklas Wagner - EpochMod.com

    Contributors: Aaron Clark

	Description:
	TODO: DESC-TBA

    Licence:
    Arma Public License Share Alike (APL-SA) - https://www.bistudio.com/community/licenses/arma-public-license-share-alike

    Github:
    https://github.com/EpochModTeam/Epoch/tree/master/Sources/epoch_code/gui/group/EPOCH_Group_Combo.sqf
*/
disableSerialization;
private ["_BtnInvite","_currentMember","_currentMaxMember","_ctrl","_selected","_playerUID"];
_ctrl = _this select 0;
_selected = _this select 1;
_playerUID = getPlayerUID player;
if (_playerUID == Epoch_my_GroupUID || {_x select 0 == _playerUID}count (Epoch_my_Group select 3) > 0) then {
	_BtnInvite = (findDisplay -1300) displayCtrl 30;
	_currentMember = count(Epoch_my_Group select 3) + count(Epoch_my_Group select 4) + 1;
	_currentMaxMember = Epoch_my_Group select 2;
	if (_currentMember < _currentMaxMember) then {
		_BtnInvite ctrlSetText format ["Invite %1",_ctrl lbtext _selected];
	};
	true
} else {
	if (_selected != -1) then {
		_ctrl lbSetCurSel -1;
	};
	false
};
