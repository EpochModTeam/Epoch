/*
	Author: Niklas Wagner - EpochMod.com

    Contributors: Aaron Clark

	Description:
	TODO: DESC-TBA

    Licence:
    Arma Public License Share Alike (APL-SA) - https://www.bistudio.com/community/licenses/arma-public-license-share-alike

    Github:
    https://github.com/EpochModTeam/Epoch/tree/release/Sources/epoch_code/gui/group/EPOCH_Group_BtnKick.sqf
*/
private ["_txt","_playerUID","_playerName","_group","_selected","_BtnKick"];
disableSerialization;
_BtnKick = (findDisplay -1300) displayCtrl 33;

_playerUID = getPlayerUID player;
if (_playerUID == Epoch_my_GroupUID || {_x select 0 == _playerUID}count (Epoch_my_Group select 3) > 0) then {
	_group = (findDisplay -1300) displayCtrl 40;
	_selected = lbCurSel _group;
	if (_selected >= 0) then {
		_playerUID = _group lbData _selected;
		_playerName = _group lbText _selected;
		if (_playerUID != "" && _playerName != "") then {
			_txt = format["Do you want to kick %1 from your Group?",_playerName];
			[_playerUID,_txt] spawn {
				_ret = [_this select 1,"Epoch Group Menu",true,true] call BIS_fnc_GUImessage;
				if (_ret) then {
					[Epoch_my_GroupUID,_this select 0,false,false,player,Epoch_personalToken] remoteExec ["EPOCH_server_updatePlayerGroup",2];
				};
			};
		};
	};
};
