/*
	Author: Niklas Wagner - EpochMod.com

    Contributors: Aaron Clark

	Description:
	TODO: DESC-TBA

    Licence:
    Arma Public License Share Alike (APL-SA) - https://www.bistudio.com/community/licenses/arma-public-license-share-alike

    Github:
    https://github.com/EpochModTeam/Epoch/tree/release/Sources/epoch_code/gui/groupTemp/EPOCH_tempGroup_BtnKick.sqf
*/
//[[[cog import generate_private_arrays ]]]
private ["_BtnKick","_group","_playerName","_playerUID","_ret","_selected","_txt"];
//[[[end]]]
disableSerialization;
_BtnKick = (findDisplay -1300) displayCtrl 33;

_playerUID = getPlayerUID player;

Epoch_my_tempGroup params [
    ["_groupName",""],
    ["_leaderName",""],
    ["_groupSize",0],
    ["_modArray",[]],
    ["_memberArray",[]]
];

if (_playerUID == Epoch_my_tempGroupUID || {_x select 0 == _playerUID}count (_modArray) > 0) then {
	_group = (findDisplay -1300) displayCtrl 40;
	_selected = lbCurSel _group;
	if (_selected >= 0) then {
		_playerUID = _group lbData _selected;
		_playerName = _group lbText _selected;
		if (_playerUID != "" && _playerName != "") then {
			_txt = format["Do you want to kick %1 from your Temp Group?",_playerName];
			[_playerUID,_txt] spawn {
                params ["_playerUID","_txt"];
				_ret = [_txt,"Epoch Temp Group Menu",true,true] call BIS_fnc_GUImessage;
				if (_ret) then {
					[Epoch_my_tempGroupUID,_playerUID,false,false,player,Epoch_personalToken] remoteExec ["EPOCH_server_updatePlayerTempGroup",2];
				};
			};
		};
	};
};
