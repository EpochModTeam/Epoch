/*
	Player Respawn

	Epoch Mod - EpochMod.com - All Rights Reserved.
*/
private["_defaultUniform", "_class", "_vest", "_dir", "_location", "_playerObj", "_player"];

if !([_this select 0, _this select 1] call EPOCH_server_getPToken) exitWith{};

_player = _this select 0;
_playerObj = _player;

if (count _this == 3) then {

	_defaultUniform = "U_Test_uniform";
	_class = "Epoch_Female_F";
	_vest = "V_F41_EPOCH";
	if (_this select 2) then { //true == male
		_defaultUniform = "U_Test1_uniform";
		_class = "Epoch_Male_F";
		_vest = "V_41_EPOCH";
	};

	_dir = random 360;
	_location = getMarkerPos "respawn_west";
	_location set[2, 0];


	_playerObj = (group _player) createUnit [_class, _location, [], 0, "CAN_COLLIDE"];
	{
		_playerObj disableAI _x;
	} forEach["FSM", "MOVE", "AUTOTARGET", "TARGET"];

	_playerObj setDir _dir;
	_playerObj setPosATL _location;

	// send player object to player
	["_switchPlayer_PVC",_playerObj] remoteExec ['EPOCH_playerGenderInit',_player];


};


_playerObj setVariable ["REVIVE", true];
true
