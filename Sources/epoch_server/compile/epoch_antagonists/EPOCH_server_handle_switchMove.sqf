/*
	Author: Aaron Clark - EpochMod.com

    Contributors:

	Description:
    Player Animations

    Licence:
    Arma Public License Share Alike (APL-SA) - https://www.bistudio.com/community/licenses/arma-public-license-share-alike

    Github:
    https://github.com/EpochModTeam/Epoch/tree/master/Sources/epoch_server/compile/epoch_antagonists/EPOCH_server_handle_switchMove.sqf
*/
private["_range", "_move", "_nearBy"];
params ["_target","_moveCase",["_token","",[""]]];
_player = _target;
if (_target isEqualType []) then {
	_target params ["_target","_player"];
};
if !([_player, _token] call EPOCH_server_getPToken) exitWith{};
_range = 0;
_move = "";

// TODO configize
switch (_moveCase) do {
	case 1: {
		_range = 1000;
		_move = "AovrPercMrunSrasWrflDf";
	};
	case 2: {
		_range = 1000;
		_move = "epoch_unarmed_jump";
	};
	case 3: {
		_range = 400;
		_move = "AwopPercMstpSgthWnonDnon_throw";
	}
};

if (_range > 0 && _move != "") then {
	_nearBy = _target nearEntities [["Epoch_Male_F","Epoch_Female_F"], _range];
	{
		[_target, _move] remoteExec ['switchMove',_x];
	}forEach (_nearBy - [_target]); //_target == the caller, already plays the animation locally!
};
