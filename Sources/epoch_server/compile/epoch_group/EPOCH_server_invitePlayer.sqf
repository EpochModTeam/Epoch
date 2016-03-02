params ["_playerUID","_var1","_var2","_player","_token"];
if !([_player, _token] call EPOCH_server_getPToken) exitWith{};
{
	if (getPlayerUID _x == _playerUID) exitWith {
		[_var1, _var2] remoteExec ['EPOCH_Group_invitePlayer',_x];
	};
} forEach playableUnits;
