/*
	Author: Aaron Clark - EpochMod.com

	Contributors:

	Description:
	Returns specific values based on an index or falls back to defaults.

	Licence:
	Arma Public License Share Alike (APL-SA) - https://www.bistudio.com/community/licenses/arma-public-license-share-alike

	Github:
	https://github.com/EpochModTeam/Epoch/tree/release/Sources/epoch_code/compile/functions/EPOCH_fnc_returnHudVar.sqf

	Example:
	// HUD and Logic functions - todo move to client function.
	[_selVarName,_varIndex,_selVarType,_selVarSubData] call EPOCH_fnc_returnHudVar

	Parameter(s):
		_this select 0: STRING - variable name
		_this select 1: NUMBER - default variable index
		_this select 2: STRING - variable type
		_this select 3: STRING - extra data

	Returns:
	MIXED
*/
//[[[cog import generate_private_arrays ]]]
private ["_customVarLimits","_customVarNames","_customVarsInit","_defaultVarValues","_varName","_varNameTmp"];
//[[[end]]]

params [["_selVarName",""],["_varIndex",0],["_selVarType",""],["_selVarSubData",""]];
switch (_selVarType) do {
	case "getMissionNamespaceVariable": {missionNamespace getVariable[_selVarName,_selVarSubData]};
	case "getPlayerHitPointDamage": {player getHitPointDamage _selVarSubData};
	case "getPlayerOxygenRemaining": {getOxygenRemaining player};
	case "getPlayerDamage": {damage player};
	default {
		_customVarsInit = getArray(getMissionConfig "CfgEpochClient" >> "customVarsDefaults");
		_customVarNames = _customVarsInit apply {_x param [0,""]};
		_defaultVarValues = _customVarsInit apply {_x param [1,0]};
		_customVarLimits = _customVarsInit apply {_x param [2,[]]};
		_varName = format["EPOCH_player%1",_selVarName];
		if (_selVarName in _customVarNames) then {
			_varNameTmp = call compile format["_player%1Key",_selVarName];
			if !(isNil "_varNameTmp") then {_varName = _varNameTmp};
		};
		missionNamespace getVariable[_varName,_defaultVarValues select _varIndex]
	};
}
