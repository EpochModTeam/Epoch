/*
	Author: Aaron Clark - EpochMod.com

    Contributors:

	Description:
	Sends message server to save custom variables from player

    Licence:
    Arma Public License Share Alike (APL-SA) - https://www.bistudio.com/community/licenses/arma-public-license-share-alike

    Github:
    https://github.com/EpochModTeam/Epoch/tree/master/Sources/epoch_code/compile/functions/EPOCH_pushCustomVar.sqf

    Example:
    true call EPOCH_pushCustomVar;

    Parameter(s):
		_this: BOOL - true = fast save, false = slow save window

	Returns:
	NOTHING
*/
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
