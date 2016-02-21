if !([_this select 3, _this select 4] call EPOCH_server_getPToken) exitWith{};

_playerUID = _this select 0;
{
	if (getPlayerUID _x == _playerUID) exitWith {
		diag_log format ["DEBUG GROUP %1 - %2",_this,_x];
		// send invite to player
		[_this select 1, _this select 2] remoteExec ['EPOCH_Group_invitePlayer',_x];
	};
} forEach playableUnits;
