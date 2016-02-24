/*
	Author: Aaron Clark - EpochMod.com

    Contributors:

	Description:
	Antagonist spawn function

    Licence:
    Arma Public License Share Alike (APL-SA) - https://www.bistudio.com/community/licenses/arma-public-license-share-alike

    Github:
    https://github.com/EpochModTeam/Epoch/tree/master/Sources/epoch_code/compile/EPOCH_unitSpawn.sqf
*/
private ["_unit","_group","_bomb","_unitClass","_targetPos","_disableAI","_nonJammer","_nonTrader","_jammerRange","_jammers","_restricted","_sapperNum"];

_unitClass = _this;

if(random 100 < 6)then{
[] execFSM "epoch_code\System\Event_Air_Drop.fsm";
};

_index = EPOCH_spawnIndex find _unitClass;
if (count(player nearEntities[_unitClass, 800]) >= (EPOCH_playerSpawnArray select _index)) exitWith{};

_nonJammer = ["B_Heli_Transport_01_F","PHANTOM","Epoch_Cloak_F"];
_nonTrader = ["B_Heli_Transport_01_F","PHANTOM","Epoch_Cloak_F","GreatWhite_F"];
_unit = objNull;

_targetPos = getPosATL player;
_targetPos set [2,0];

_jammers = [];
_config = 'CfgEpochClient' call EPOCH_returnConfig;
_jammerRange = getNumber(_config >> "buildingJammerRange");
_jammers = nearestObjects[_targetPos, ["PlotPole_EPOCH"], _jammerRange];

if(count _jammers > 0)then{
if!(_unitClass in _nonJammer)exitWith{};
};

_restricted = [];
_restricted = nearestObjects [_targetPos, ["ProtectionZone_Invisible_F"], 150];
if(count _restricted > 0)then{
if!(_unitClass in _nonTrader)exitWith{};
};


_disableAI = {
	{_this disableAI _x}forEach["TARGET","AUTOTARGET","FSM"];
};

switch _unitClass do {
	case "Epoch_Cloak_F": {
		_unit = createAgent[_unitClass, _targetPos, [], 256, "FORM"];
		_unit call _disableAI;
		[_unit] execFSM "epoch_code\System\cloak.fsm";
	};
	case "GreatWhite_F": {
		if (surfaceIsWater _targetPos) then{
			if (((_targetPos vectorDiff getPosASL player) select 2) > 25) then{
				_unit = createAgent[_unitClass, _targetPos, [], 120, "FORM"];
				_unit call _disableAI;
				[_unit] execFSM "epoch_code\System\Shark_Brain.fsm";
			};
		};
	};
	case "Epoch_Sapper_F": {
		if(random 100 < 6)then{
			_config = 'CfgEpochSapper' call EPOCH_returnConfig;
			_sapperNum = 8;
			if(getNumber(_config >> "sapperMigrationCount") > 0)then{
				_sapperNum = getNumber(_config >> "sapperMigrationCount");
			};
			[player,_sapperNum] execVM "epoch_code\compile\EPOCH_callSapperMigration.sqf";
		}else{
			_unit = createAgent[_unitClass, _targetPos, [], 256, "FORM"];
			_bomb = createVehicle ["Sapper_Charge_Ammo", _targetPos, [], 0, "CAN_COLLIDE"];
			_bomb attachTo [_unit, [0,0,0],"Pelvis"];
			_unit call _disableAI;
			sapperHndl = [_unit, _bomb] execFSM "epoch_code\System\Sapper_Brain.fsm";
			_unit addEventHandler ["FiredNear", "sapperHndl setFSMVariable [""_sFiredNear"",[_this select 1, _this select 2]];"];
			_unit addEventHandler ["Hit", "sapperHndl setFSMVariable [""_sHit"",[_this select 1, _this select 2]];"];
		};
	};
	case "Epoch_SapperB_F": {
		_unit = createAgent[_unitClass, _targetPos, [], 256, "FORM"];
		_bomb = createVehicle["SapperB_Charge_Ammo", _targetPos, [], 0, "CAN_COLLIDE"];
		_bomb attachTo[_unit, [0, 0, 0], "Pelvis"];
		_unit call _disableAI;
		sapperHndl = [_unit, _bomb] execFSM "epoch_code\System\Sapper_Brain2.fsm";
		_unit addEventHandler["FiredNear", "sapperHndl setFSMVariable [""_sFiredNear"",[_this select 1, _this select 2]];"];
		_unit addEventHandler["Hit", "sapperHndl setFSMVariable [""_sHit"",[_this select 1, _this select 2]];"];
	};
	case "I_UAV_01_F": {
		_targetPos = getPosATL player;
		_targetPos = [_targetPos, 600, 1200, 5, 0, 400, 0] call BIS_fnc_findSafePos;
		_targetPos set[2, 600];
		_unit = createVehicle["I_UAV_01_F", _targetPos, [], 0, "FLY"];
		addToRemainsCollector[_unit];
		_unit flyInHeight 600;
		_grp = createGroup RESISTANCE;
		_driver = _grp createUnit["I_UAV_AI", position _unit, [], 0, "CAN_COLLIDE"];
		_driver moveInAny _unit;
		[_unit, player] execFSM "epoch_code\System\Copter_brain.fsm";
	};
	case "PHANTOM": {
		[] execFSM "epoch_code\System\Phantom_Brain.fsm";
	};
	case "B_Heli_Transport_01_F": {
		[] execFSM "epoch_code\System\Event_Air_Drop.fsm";
	};
};

if !(isNull _unit) then {
	// send to server
	[_unit] remoteExec ["EPOCH_localCleanup",2];
};
