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
private ["_aiskill","_unit","_plyr","_grp","_arrUnits","_arrSkills","_units"];
params ["_pos","_copter"];

_plyr = player; //need to check on change owner
_unit = objNull;

_grp = createGroup RESISTANCE;
_grp setBehaviour "COMBAT";
_grp setCombatMode "RED";

// TODO: make configized
_arrUnits = ["I_Soldier_EPOCH", "I_Soldier2_EPOCH", "I_Soldier3_EPOCH"];
_arrSkills = ["aimingAccuracy","aimingShake","aimingSpeed","endurance","spotDistance","spotTime","courage","reloadSpeed","commanding","general"];
_units = [];
for "_i" from 0 to ((count _arrUnits)-1) do {

	_unit = _grp createUnit[(_arrUnits select _i), _pos, [], 0, "FORM"];
	_units pushBack _unit;

	_unit setSkill 0.6;
	_unit setRank "Private";

	_unit enableAI "TARGET";
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
		_grp selectLeader _unit;
		[_pos,_copter,_plyr,_unit] execFSM "\x\addons\a3_epoch_code\System\Group_Leader_Brain.fsm";
	};
};

// cleanup units or (transfer ownership) if player logs out
_units remoteExec ["EPOCH_localCleanup",2];
