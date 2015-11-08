private ["_tempVars","_tempVal","_tempIndex","_time"];
_time = if (_this) then [{15},{80}];

_EPOCH_lastSave = missionNamespace getVariable["EPOCH_lastSave", diag_tickTime];

if ((diag_tickTime - _EPOCH_lastSave) >= _time) then {

	// manually set hitpoints array
	EPOCH_playerHitPoints = ((getAllHitPointsDamage player) param [2,[]]);

	// Get all custom variables
	_customVars = [];
	_customVarsInit = ["CfgEpochClient", "customVarsDefaults", missionNamespace getVariable["EPOCH_customVarsDefaults", []]] call EPOCH_fnc_returnConfigEntryV2;
	{
		_customVars pushBack (missionNamespace getVariable format["EPOCH_player%1",_x select 0]);
	} forEach _customVarsInit;

	// TODO: use remoteExec here
	missionNamespace setVariable ["EPOCH_pushPlayer_PVS",[player,_customVars,missionNamespace getVariable "Epoch_personalToken"]];
	publicVariableServer "EPOCH_pushPlayer_PVS";

	missionNamespace setVariable["EPOCH_lastSave", diag_tickTime];
};
