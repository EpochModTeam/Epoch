/*
	Author: Aaron Clark - EpochMod.com

    Contributors:

	Description:
	Sends message server to save custom variables from player

    Licence:
    Arma Public License Share Alike (APL-SA) - https://www.bistudio.com/community/licenses/arma-public-license-share-alike

    Github:
    https://github.com/EpochModTeam/Epoch/tree/release/Sources/epoch_code/compile/functions/EPOCH_pushCustomVar.sqf

    Example:
    true call EPOCH_pushCustomVar;

    Parameter(s):
		_this: BOOL - true = fast save, false = slow save window

	Returns:
	NOTHING
*/
//[[[cog import generate_private_arrays ]]]
private ["_customVars","_lastSave","_time"];
//[[[end]]]
_time = if (_this) then [{15},{80}];
_lastSave = missionNamespace getVariable["EPOCH_lastSave", diag_tickTime];
if ((diag_tickTime - _lastSave) >= _time) then {
	EPOCH_playerHitPoints = ((getAllHitPointsDamage player) param [2,[]]);
	_customVars = [];
	{
		_customVars pushBack (missionNamespace getVariable format["EPOCH_player%1",_x]);
	} forEach (missionNamespace getVariable["EPOCH_customVars", []]);
	[player,_customVars,missionNamespace getVariable "Epoch_personalToken"] remoteExec ["EPOCH_fnc_savePlayer",2];
	missionNamespace setVariable["EPOCH_lastSave", diag_tickTime];
};
