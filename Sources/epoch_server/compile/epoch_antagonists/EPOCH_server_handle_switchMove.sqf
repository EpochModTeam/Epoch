/*
	Author: Aaron Clark - EpochMod.com

    Contributors:

	Description:
    Player Animations

    Licence:
    Arma Public License Share Alike (APL-SA) - https://www.bistudio.com/community/licenses/arma-public-license-share-alike

    Github:
    https://github.com/EpochModTeam/Epoch/tree/release/Sources/epoch_server/compile/epoch_antagonists/EPOCH_server_handle_switchMove.sqf

	Usage:
	[_player,"moveName","token",_target] call EPOCH_server_handle_switchMove;
	or
	[_player,"moveName","token"] call EPOCH_server_handle_switchMove;
*/
//[[[cog import generate_private_arrays ]]]
private ["_nearBy","_range","_selectedMove","_switchMovehandlerConfig","_target","_targets"];
//[[[end]]]
params [["_player",objNull,[objNull]],["_move","",[""]],["_token","",[""]],["_target",objNull]];

if !([_player, _token] call EPOCH_server_getPToken) exitWith{};
if (_move isEqualTo "") exitWith {};
if (isNull _target) then {_target = _player};

_switchMovehandlerConfig = 'CfgSwitchMovehandler' call EPOCH_returnConfig;
_selectedMove = (_switchMovehandlerConfig >> _move);
if (isClass _selectedMove) then {
	// get nearby players based on range
	_range = getNumber(_selectedMove >> "distance");
	_nearBy = (_target nearEntities [["Epoch_Male_F","Epoch_Female_F","LandVehicle","Ship","Air","Tank"], _range]) select {isPlayer _x};
	 // send move to everyone except caller.
	_targets = _nearBy - [_player];
	if !(_targets isEqualTo []) then {
		[_target, _move] remoteExec ['switchMove',_targets];
	};
};
