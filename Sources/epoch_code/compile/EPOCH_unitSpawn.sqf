/*
	Author: Aaron Clark - EpochMod.com

    Contributors: Andrew Gregory

	Description:
	Antagonist spawn function

    Licence:
    Arma Public License Share Alike (APL-SA) - https://www.bistudio.com/community/licenses/arma-public-license-share-alike

    Github:
    https://github.com/EpochModTeam/Epoch/tree/release/Sources/epoch_code/compile/EPOCH_unitSpawn.sqf
*/
//[[[cog import generate_private_arrays ]]]
private ["_bomb","_config","_currentLimit","_disableAI","_driver","_grp","_index","_jammerRange","_jammers","_loop","_nonJammer","_nonTrader","_nonTraderAIRange","_restricted","_sapperNum","_spawnLimit","_targetPos","_unit","_units"];
//[[[end]]]
params ["_unitClass",["_trgt",player],["_doVariable",false],["_extraData",[]]];

_bomb = objNull;
// diag_log format["DEBUG: Antagonist %1 Spawning on %2. Do variable: %3.", _unitClass, _trgt, _doVariable];
if(_doVariable)then{_unitClass call EPOCH_unitSpawnIncrease;};//Assumes Antagonist is required.

_index = EPOCH_spawnIndex find _unitClass;
_spawnLimit = EPOCH_playerSpawnArray select _index;
_currentLimit = count(_trgt nearEntities[_unitClass, 800]);
if (!_doVariable && (_currentLimit >= _spawnLimit)) exitWith {
	diag_log format["DEBUG: too many %1 exiting unitspawn",_unitClass];
};

_nonJammer = ["CfgEpochClient", "nonJammerAI", ["B_Heli_Transport_01_F","PHANTOM","EPOCH_Sapper_F","Epoch_SapperB_F","I_UAV_01_F","EPOCH_RyanZombie_1"]] call EPOCH_fnc_returnConfigEntryV2;
_nonTrader = ["CfgEpochClient", "nonTraderAI", ["B_Heli_Transport_01_F","PHANTOM","EPOCH_Sapper_F","Epoch_SapperB_F","I_UAV_01_F","Epoch_Cloak_F","GreatWhite_F","EPOCH_RyanZombie_1"]] call EPOCH_fnc_returnConfigEntryV2;
_nonTraderAIRange = ["CfgEpochClient", "nonTraderAIRange", 150] call EPOCH_fnc_returnConfigEntryV2;
_loop = false;
_unit = objNull;

_targetPos = getPosATL _trgt;
_targetPos set [2,0];

_config = 'CfgEpochClient' call EPOCH_returnConfig;
_jammerRange = getNumber(_config >> "buildingJammerRange");
_jammers = nearestObjects[_targetPos, ["PlotPole_EPOCH"], _jammerRange];
if(!(_jammers isEqualTo []) && (_unitClass in _nonJammer))exitWith{};

_restricted = nearestObjects [_targetPos, ["ProtectionZone_Invisible_F"], _nonTraderAIRange];
if(!(_restricted isEqualTo []) && (_unitClass in _nonTrader))exitWith{};

_disableAI = {
	{_this disableAI _x}forEach["TARGET","AUTOTARGET","FSM"];
};
_units = [];
switch _unitClass do {
	case "Epoch_Cloak_F": {
		_unit = createAgent[_unitClass, _targetPos, [], 256, "FORM"];
		_units pushBack _unit;
		_unit call _disableAI;
		[_unit,_trgt] execFSM "\x\addons\a3_epoch_code\System\cloak.fsm";
	};
	case "GreatWhite_F": {
		if (surfaceIsWater _targetPos) then{
			if (((_targetPos vectorDiff getPosASL _trgt) select 2) > 25) then{
				_unit = createAgent[_unitClass, _targetPos, [], 120, "FORM"];
				_units pushBack _unit;
				_unit call _disableAI;
				[_unit] execFSM "\x\addons\a3_epoch_code\System\Shark_Brain.fsm";
			};
		};
	};
	case "Epoch_Sapper_F": {
		if(random 100 < 6 && isNull _trgt)then{
			_config = 'CfgEpochSapper' call EPOCH_returnConfig;
			_sapperNum = 8;
			if(getNumber(_config >> "sapperMigrationCount") > 0)then{
				_sapperNum = getNumber(_config >> "sapperMigrationCount");
			};
			[_trgt,_sapperNum] execVM "epoch_code\compile\EPOCH_callSapperMigration.sqf";
		}else{
			_unit = createAgent[_unitClass, _targetPos, [], 256, "FORM"];
			_units pushBack _unit;
			_bomb = createVehicle ["Sapper_Charge_Ammo", _targetPos, [], 0, "CAN_COLLIDE"];
			_bomb attachTo [_unit, [0,0,0],"Pelvis"];
			_unit call _disableAI;
			_sapperHndl = [_unit, _bomb, _trgt] execFSM "\x\addons\a3_epoch_code\System\Sapper_Brain.fsm";
            _unit setVariable ["sapperHndl",_sapperHndl];
			_unit addEventHandler ["FiredNear", format ["%1 setFSMVariable [""_sFiredNear"",[_this select 1, _this select 2]];",_sapperHndl]];
			_unit addEventHandler ["Hit", format ["%1 setFSMVariable [""_sHit"",[_this select 1, _this select 2]];",_sapperHndl]];
		};
	};
	case "Epoch_SapperB_F": {
		_unit = createAgent[_unitClass, _targetPos, [], 256, "FORM"];
		_units pushBack _unit;
		_bomb = createVehicle["SapperB_Charge_Ammo", _targetPos, [], 0, "CAN_COLLIDE"];
		_bomb attachTo[_unit, [0, 0, 0], "Pelvis"];
		_unit call _disableAI;
		_sapperHndl = [_unit, _bomb, _trgt] execFSM "\x\addons\a3_epoch_code\System\Sapper_Brain2.fsm";
        _unit setVariable ["sapperHndl",_sapperHndl];
        _unit addEventHandler ["FiredNear", format ["%1 setFSMVariable [""_sFiredNear"",[_this select 1, _this select 2]];",_sapperHndl]];
        _unit addEventHandler ["Hit", format ["%1 setFSMVariable [""_sHit"",[_this select 1, _this select 2]];",_sapperHndl]];
	};
	case "I_UAV_01_F": {
		_targetPos = getPosATL _trgt;
		_targetPos = [_targetPos, 600, 1200, 5, 0, 400, 0] call BIS_fnc_findSafePos;
		_targetPos set[2, 600];
		_unit = createVehicle["I_UAV_01_F", _targetPos, [], 0, "FLY"];
        _unit disableTIEquipment true;
		_units pushBack _unit;
		addToRemainsCollector[_unit];
		_unit flyInHeight 600;
		_grp = createGroup RESISTANCE;
		_driver = _grp createUnit["I_UAV_AI", position _unit, [], 0, "CAN_COLLIDE"];
		_driver moveInAny _unit;
		[_unit, _trgt] execFSM "\x\addons\a3_epoch_code\System\Copter_brain.fsm";
	};
	case "PHANTOM": {
		[] execFSM "\x\addons\a3_epoch_code\System\Phantom_Brain.fsm";
	};
	case "B_Heli_Transport_01_F": {
		[] execFSM "\x\addons\a3_epoch_code\System\Event_Air_Drop.fsm";
	};
	case "EPOCH_RyanZombie_1": {
		for "_i" from 1 to (_spawnLimit - _currentLimit) do
		{
			_unit = [] call EPOCH_zombieSpawn;
			_units pushBack _unit;
		};
	};
    case "I_Soldier_EPOCH": {
        _extraData params ["_pos","_copter"];
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
        	_unit setRank "Private";
        	_unit enableAI "TARGET";
        	_unit enableAI "AUTOTARGET";
        	_unit enableAI "MOVE";
        	_unit enableAI "ANIM";
        	_unit disableAI "FSM";
            // randomize skill
        	for "_i" from 0 to ((count _arrSkills)-1) do {
        		_aiskill = floor random (_arrVals select _i);
        		if (_aiskill<_minAISkill) then {_aiskill=_minAISkill};
        		_unit setSkill [_arrSkills select _i,_arrVals select _i];
        	};
            // spawn brains only on leader
        	if (_i == 0) then {
        		_grp selectLeader _unit;
        		[_pos,_copter,_trgt,_unit] execFSM "\x\addons\a3_epoch_code\System\Group_Leader_Brain.fsm";
        	};
        };
	};
};

if(_doVariable && (!isNull _unit) && (!isNull _trgt))then{
	_trgt setVariable ["EPOCH_antagObj", _unit, true];
	if!(isNull _bomb)then{
		_trgt setVariable ["EPOCH_antagBomb", _bomb, true];
	};
};

if !(_units isEqualTo []) then {
	_units remoteExec ["EPOCH_localCleanup",2];
};
