/*
	Player Respawn
	
	Epoch Mod - EpochMod.com - All Rights Reserved.
*/
private["_defaultUniform", "_class", "_vest", "_dir", "_location", "_plyrObj", "_plyr"];

if !([_this select 0, _this select 1] call EPOCH_server_getPToken) exitWith{};

_plyr = _this select 0;
_plyrObj = _plyr;

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


	_plyrObj = (group _plyr) createUnit [_class, _location, [], 0, "CAN_COLLIDE"];
	{
		_plyrObj disableAI _x;
	} forEach["FSM", "MOVE", "AUTOTARGET", "TARGET"];

	_plyrObj setDir _dir;
	_plyrObj setPosATL _location;

	EPOCH_switchPlayer_PVC = _plyrObj;
	(owner _plyr) publicVariableClient "EPOCH_switchPlayer_PVC";
};


_plyrObj setVariable ["REVIVE", true];
true