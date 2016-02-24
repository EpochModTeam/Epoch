/*
	Author: Andrew Gregory - EpochMod.com

    Contributors: Aaron Clark

	Description:
	Spawn drone function

    Licence:
    Arma Public License Share Alike (APL-SA) - https://www.bistudio.com/community/licenses/arma-public-license-share-alike

    Github:
    https://github.com/EpochModTeam/Epoch/tree/master/Sources/epoch_code/compile/EPOCH_supportCopter.sqf
*/
private["_pos","_copter","_plyr","_unit","_copterSupportGrp","_arrUnits","_arrSkills","_aiskill"];
_pos = _this select 0;
_copter = _this select 1;
_plyr = player;//need to check on change owner
_unit = objNull;

_grp = createGroup RESISTANCE;
_grp setBehaviour "COMBAT";
_grp setCombatMode "RED";
// comment out and use sanitized soldiers for now
// _arrUnits = ["I_Soldier_TL_F","I_Soldier_GL_F","I_Soldier_AR_F","I_Soldier_LAT_F"];
_arrUnits = ["I_Soldier_EPOCH", "I_Soldier2_EPOCH", "I_Soldier3_EPOCH"];
_arrSkills = ["aimingAccuracy","aimingShake","aimingSpeed","endurance","spotDistance","spotTime","courage","reloadSpeed","commanding","general"];
_units = [];
for "_i" from 0 to ((count _arrUnits)-1) do {

	_unit = _grp createUnit[(_arrUnits select _i), _pos, [], 0, "FORM"];
	_units pushBack _unit;

	_unit setSkill 0.6;
	_unit setRank "Private";

	_unit enableAI "TARGET";
	//_unit disableAI "AUTOTARGET";
	_unit enableAI "AUTOTARGET";
	_unit enableAI "MOVE";
	_unit enableAI "ANIM";
	_unit disableAI "FSM";

	for "_i" from 0 to ((count _arrSkills)-1) do {
	_aiskill = ((floor(random 10))+1)/10;
	if (_aiskill<0.6) then {_aiskill=0.6};
	_unit setSkill [_arrSkills select _i,_aiskill];
	};

	if (_i == 0) then {
	//_unit enableAI "AUTOTARGET";
		_grp selectLeader _unit;
		[_pos,_copter,_plyr,_unit] execFSM "epoch_code\System\Group_Leader_Brain.fsm";
	//}else{
	//[_pos,_copter,_plyr,_unit] execFSM "epoch_code\System\Group_Soldier_brain.fsm";
	};

};

// cleanup units or (transfer ownership) if player logs out
// send to server
_units remoteExec ["EPOCH_localCleanup",2];
