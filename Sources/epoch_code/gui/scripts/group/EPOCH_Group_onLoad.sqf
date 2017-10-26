/*
	Author: Niklas Wagner - EpochMod.com

    Contributors: Aaron Clark

	Description:
	TODO: DESC-TBA

    Licence:
    Arma Public License Share Alike (APL-SA) - https://www.bistudio.com/community/licenses/arma-public-license-share-alike

    Github:
    https://github.com/EpochModTeam/Epoch/tree/release/Sources/epoch_code/gui/group/EPOCH_Group_onLoad.sqf
*/
//[[[cog import generate_private_arrays ]]]
private ["_BtnInvite","_GroupMemberList","_InvitePlayerCombo","_currentMaxMember","_display","_found","_index","_myPlayerUID","_onlinePUID","_picture","_playerIsLeader","_playerIsMod","_playerUID","_players"];
//[[[end]]]
disableSerialization;
_display = findDisplay -1300;
_BtnInvite = _display displayCtrl 30;

_GroupMemberList = _display displayCtrl 40;
_InvitePlayerCombo = _display displayCtrl 41;

Epoch_my_Group params [
    ["_groupName",""],
    ["_leaderName",""],
    ["_groupSize",0],
    ["_modArray",[]],
    ["_memberArray",[]]
];

_currentMaxMember = count(_modArray) + count(_memberArray) + 1;

(_display displayCtrl 21) ctrlSetText format["Group Name: %1 (%2/%3 Slots)",_groupName,_currentMaxMember,_groupSize];

_myPlayerUID = getPlayerUID player;
_playerIsLeader = _myPlayerUID == Epoch_my_GroupUID;
_playerIsMod = {_x select 0 == _myPlayerUID}count (_modArray) > 0;
(_display displayCtrl 32) ctrlEnable false;
(_display displayCtrl 33) ctrlEnable false;

_onlinePUID = [];
{
	_onlinePUID pushBack (getPlayerUID _x);
}forEach (units group player);

if (_currentMaxMember < _groupSize) then {
	_players = player nearEntities [["Epoch_Male_F","Epoch_Female_F","LandVehicle","Ship","Air","Tank"], 10];

	if (_playerIsLeader || _playerIsMod) then {
		{
			if (!isNull _x) then {
				if (isPlayer _x && alive _x) then {
					_index = _InvitePlayerCombo lbAdd format["%1",name _x];
					_InvitePlayerCombo lbSetData [_index,getPlayerUID _x];
				};
			};
		}forEach (_players-(units group player));
	};

	if ((lbSize _InvitePlayerCombo) == 0) then {
		_InvitePlayerCombo ctrlEnable false;
		_BtnInvite ctrlEnable false;
		_BtnInvite ctrlSetText (if (_playerIsLeader || _playerIsMod) then {"No one nearby to invite."} else {"Must be an Owner or a Mod to invite!"});
	} else {
		_InvitePlayerCombo lbSetCurSel 0;
		lbsort _InvitePlayerCombo;
	};
} else {
	if (_playerIsLeader || _playerIsMod) then {
		_found = EPOCH_group_upgrade_lvl find _currentMaxMember;
		if (count EPOCH_group_upgrade_lvl >= (_found+3)) then {
			_BtnInvite ctrlSetText format ["Upgrade +%1 Slots for %2 Krypto",abs (_currentMaxMember-(EPOCH_group_upgrade_lvl select (_found+2))),EPOCH_group_upgrade_lvl select (_found+3)];
		} else {
			_BtnInvite ctrlSetText format ["No Upgrade Available!"];
			_BtnInvite ctrlEnable false;
		};
	} else {
		_BtnInvite ctrlSetText format ["You need to be the Owner or a Mod to Upgrade the group!"];
		_BtnInvite ctrlEnable false;
	};
};

if (_playerIsLeader) then {
	(findDisplay -1300) displayCtrl 31 ctrlSetText "Delete Group";
};


{
	_picture = EPOCH_group_level_img select _forEachIndex; //0 = lead / 1 = mod / 2 = member
	{
		_playerUID = _x select 0;

		_index = _GroupMemberList lbAdd format["%1",_x select 1];
		_GroupMemberList lbSetColor [_index,if (_playerUID in _onlinePUID) then {[1,1,1,1]}else{[1,1,1,0.45]}];
		_GroupMemberList lbSetPicture [_index, _picture];

		if (_playerIsLeader || _playerIsMod) then {
			_GroupMemberList lbSetData [_index,_playerUID];
		};
	}forEach _x;
}forEach
[
	[[Epoch_my_GroupUID,_leaderName]],
	_modArray,
	_memberArray
];
