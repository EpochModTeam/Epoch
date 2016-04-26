/*
	Author: Aaron Clark - EpochMod.com

    Contributors: Andrew Gregory

	Description:
	Antagonist spawn function

    Licence:
    Arma Public License Share Alike (APL-SA) - https://www.bistudio.com/community/licenses/arma-public-license-share-alike

    Github:
    https://github.com/EpochModTeam/Epoch/tree/master/Sources/epoch_code/compile/EPOCH_unitSpawn.sqf
*/
private ["_unit","_sapperNum","_config","_targetPos","_grp","_driver","_index","_nonJammer","_nonTrader","_jammers","_jammerRange","_restricted","_disableAI"];
params ["_unitClass","_trgt","_doVariable"];
private _bomb = objNull;
if(isNil "_doVariable")then{_doVariable=false;};
if(isNil "_trgt")then{_trgt=player;};
diag_log format["Epoch: ADMIN: Antagonist %1 Spawning on %2. Do variable: %3.", _unitClass, _trgt, _doVariable];
if(random 100 < 6)then{
	[] execFSM "\x\addons\a3_epoch_code\System\Event_Air_Drop.fsm";
};
if(_doVariable)then{_unitClass call EPOCH_unitSpawnIncrease;};//Assumes Antagonist is required.

_index = EPOCH_spawnIndex find _unitClass;
if (!_doVariable && (count(_trgt nearEntities[_unitClass, 800]) >= (EPOCH_playerSpawnArray select _index))) exitWith{};

_nonJammer = ["CfgEpochClient", "nonJammerAI", ["B_Heli_Transport_01_F","PHANTOM","Epoch_Cloak_F"]] call EPOCH_fnc_returnConfigEntryV2;
_nonTrader = ["CfgEpochClient", "nonTraderAI", ["B_Heli_Transport_01_F","PHANTOM","Epoch_Cloak_F","GreatWhite_F"]] call EPOCH_fnc_returnConfigEntryV2;
_nonTraderAIRange = ["CfgEpochClient", "nonTraderAIRange", 150] call EPOCH_fnc_returnConfigEntryV2;

_unit = objNull;

_targetPos = getPosATL _trgt;
_targetPos set [2,0];

_jammers = [];
_config = 'CfgEpochClient' call EPOCH_returnConfig;
_jammerRange = getNumber(_config >> "buildingJammerRange");
_jammers = nearestObjects[_targetPos, ["PlotPole_EPOCH"], _jammerRange];
if(count _jammers > 0 && (_unitClass in _nonJammer))exitWith{
	if(_doVariable)then{["<t size='1.6' color='#99ffffff'>Not allowed near a base - Please respawn !</t>", 5] call Epoch_dynamicText;};
};

_restricted = [];
_restricted = nearestObjects [_targetPos, ["ProtectionZone_Invisible_F"], _nonTraderAIRange];
if(count _restricted > 0 && (_unitClass in _nonTrader))exitWith{
	if(_doVariable)then{["<t size='1.6' color='#99ffffff'>Not allowed near a trader - Please respawn !</t>", 5] call Epoch_dynamicText;};
};

_disableAI = {
	{_this disableAI _x}forEach["TARGET","AUTOTARGET","FSM"];
};

switch _unitClass do {
	case "Epoch_Cloak_F": {
		_unit = createAgent[_unitClass, _targetPos, [], 256, "FORM"];
		_unit call _disableAI;
		[_unit,_trgt] execFSM "\x\addons\a3_epoch_code\System\cloak.fsm";
	};
	case "GreatWhite_F": {
		if (surfaceIsWater _targetPos) then{
			if (((_targetPos vectorDiff getPosASL _trgt) select 2) > 25) then{
				_unit = createAgent[_unitClass, _targetPos, [], 120, "FORM"];
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
			_bomb = createVehicle ["Sapper_Charge_Ammo", _targetPos, [], 0, "CAN_COLLIDE"];
			_bomb attachTo [_unit, [0,0,0],"Pelvis"];
			_unit call _disableAI;
			sapperHndl = [_unit, _bomb, _trgt] execFSM "\x\addons\a3_epoch_code\System\Sapper_Brain.fsm";
			_unit addEventHandler ["FiredNear", "sapperHndl setFSMVariable [""_sFiredNear"",[_this select 1, _this select 2]];"];
			_unit addEventHandler ["Hit", "sapperHndl setFSMVariable [""_sHit"",[_this select 1, _this select 2]];"];
		};
	};
	case "Epoch_SapperB_F": {
		_unit = createAgent[_unitClass, _targetPos, [], 256, "FORM"];
		_bomb = createVehicle["SapperB_Charge_Ammo", _targetPos, [], 0, "CAN_COLLIDE"];
		_bomb attachTo[_unit, [0, 0, 0], "Pelvis"];
		_unit call _disableAI;
		sapperHndl = [_unit, _bomb, _trgt] execFSM "\x\addons\a3_epoch_code\System\Sapper_Brain2.fsm";
		_unit addEventHandler["FiredNear", "sapperHndl setFSMVariable [""_sFiredNear"",[_this select 1, _this select 2]];"];
		_unit addEventHandler["Hit", "sapperHndl setFSMVariable [""_sHit"",[_this select 1, _this select 2]];"];
	};
	case "I_UAV_01_F": {
		_targetPos = getPosATL _trgt;
		_targetPos = [_targetPos, 600, 1200, 5, 0, 400, 0] call BIS_fnc_findSafePos;
		_targetPos set[2, 600];
		_unit = createVehicle["I_UAV_01_F", _targetPos, [], 0, "FLY"];
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
};

if(_doVariable && (!isNull _unit) && (!isNull _trgt))then{
_trgt setVariable ["EPOCH_antagObj", _unit, true];
if!(isNull _bomb)then{
_trgt setVariable ["EPOCH_antagBomb", _bomb, true];
};
};
if !(isNull _unit) then {
	// send to server
	[_unit] remoteExec ["EPOCH_localCleanup",2];
};
