/*
	Author: Andrew Gregory - EpochMod.com

    Contributors: Aaron Clark

	Description:
	Spawn drone function

    Licence:
    Arma Public License Share Alike (APL-SA) - https://www.bistudio.com/community/licenses/arma-public-license-share-alike

    Github:
    https://github.com/EpochModTeam/Epoch/tree/release/Sources/epoch_code/compile/EPOCH_supportCopter.sqf
*/
//[[[cog import generate_private_arrays ]]]
private ["_aiskill","_arrSkills","_arrUnits","_arrVals","_grp","_minAISkill","_player","_unit","_unitCount","_units"];
//[[[end]]]
params ["_pos","_copter"];

_player = player; //need to check on change owner
_unit = objNull;

_grp = createGroup RESISTANCE;
_grp setBehaviour "COMBAT";
_grp setCombatMode "RED";

_minAISkill = getNumber (getMissionConfig "CfgEpochUAVSupport" >> "minAISkill");
_arrUnits = getArray (getMissionConfig "CfgEpochUAVSupport" >> "unitTypes");
_unitCount = getNumber (getMissionConfig "CfgEpochUAVSupport" >> "maxUnitNum");
_arrSkills = ["aimingAccuracy","aimingShake","aimingSpeed","endurance","spotDistance","spotTime","courage","reloadSpeed","commanding","general"];
_arrVals = [
getNumber (getMissionConfig "CfgEpochUAVSupport" >> "maxAimingAccuracy"),
getNumber (getMissionConfig "CfgEpochUAVSupport" >> "maxAimingShake"),
getNumber (getMissionConfig "CfgEpochUAVSupport" >> "maxAimingSpeed"),
getNumber (getMissionConfig "CfgEpochUAVSupport" >> "maxEndurance"),
getNumber (getMissionConfig "CfgEpochUAVSupport" >> "maxSpotDistance"),
getNumber (getMissionConfig "CfgEpochUAVSupport" >> "maxSpotTime"),
getNumber (getMissionConfig "CfgEpochUAVSupport" >> "maxCourage"),
getNumber (getMissionConfig "CfgEpochUAVSupport" >> "maxReloadSpeed"),
getNumber (getMissionConfig "CfgEpochUAVSupport" >> "maxCommanding"),
getNumber (getMissionConfig "CfgEpochUAVSupport" >> "maxGeneral")
];
_units = [];
for "_i" from 0 to (_unitCount - 1) do {

	_unit = _grp createUnit[selectRandom _arrUnits, _pos, [], 0, "FORM"];
	_units pushBack _unit;

	//_unit setSkill 0.6;
	_unit setRank "Private";

	_unit enableAI "TARGET";
	_unit enableAI "AUTOTARGET";
	_unit enableAI "MOVE";
	_unit enableAI "ANIM";
	_unit disableAI "FSM";

	for "_i" from 0 to ((count _arrSkills)-1) do {
		_aiskill = floor random (_arrVals select _i);
		if (_aiskill<_minAISkill) then {_aiskill=_minAISkill};
		_unit setSkill [_arrSkills select _i,_arrVals select _i];
	};

	if (_i == 0) then {
		_grp selectLeader _unit;
		[_pos,_copter,_player,_unit] execFSM "\x\addons\a3_epoch_code\System\Group_Leader_Brain.fsm";
	};
};

// cleanup units or (transfer ownership) if player logs out
_units remoteExec ["EPOCH_localCleanup",2];
