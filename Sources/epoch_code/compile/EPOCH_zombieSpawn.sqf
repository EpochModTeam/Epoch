/*
	Author: Andrew Gregory - EpochMod.com

    Contributors:

	Description:
	Call a zombie. (Ryans required)

    Licence:
    Arma Public License Share Alike (APL-SA) - https://www.bistudio.com/community/licenses/arma-public-license-share-alike

    Github:
    https://github.com/EpochModTeam/Epoch/tree/master/Sources/epoch_code/compile/EPOCH_zombieSpawn.sqf

    Example:
	[] call EPOCH_zombieSpawn;

    Parameter(s):

	Returns:
	OBJECT - Zombie Agent
*/
params [["_justSpawn",false]];
private ["_zRange","_disableAI","_unitClass","_unit","_clutterPos","_zedHandle","_zMax"];
_disableAI = {{_this disableAI _x}forEach["TARGET","AUTOTARGET","FSM"];};
_units = [];
_zRange = getNumber (getMissionConfig "CfgEpochRyanZombie" >> "range");
_zeds = getArray (getMissionConfig "CfgEpochRyanZombie" >> "zeds");
_zMax = getNumber (getMissionConfig "CfgEpochRyanZombie" >> "maxNumber");
_zDoCnt = 0;
//Check for horde
_nrZeds = nearestObjects [player,_zeds,_zRange];
_currZCount =  count _nrZeds;
if(_currZCount < _zMax)then{_zDoCnt = _zMax - _currZCount;};
for "_i" from 1 to _zDoCnt step 1 do{

	_unitClass = selectRandom _zeds;
	_unit = createAgent[_unitClass, position player, [], _zRange, "FORM"];
	// todo cleanup this object after some time
	//_clutterPos = getPosATL _unit;
	//if!(isOnRoad _unit)then{	
		// _grave = createVehicle ["Land_Grave_dirt_F", _clutterPos, [], 0, "CAN_COLLIDE"];
	//};
	_unit call _disableAI;
	_unit switchMove "AmovPercMstpSnonWnonDnon_SaluteOut";
	[[_unit,player], 4, Epoch_personalToken] remoteExec ["EPOCH_server_handle_switchMove",2];

	_unit setmimic "dead";
	_unit setface (selectRandom ["RyanZombieFace1", "RyanZombieFace2", "RyanZombieFace3", "RyanZombieFace4", "RyanZombieFace5"]);
	removegoggles _unit;
	_zedHandle = [_unit,true] execFSM "epoch_code\system\EPOCH_zombie_brain.fsm";
	_unit addEventHandler ["FiredNear", "(_this select 0) setVariable [""zFiredNear"",[_this select 1, _this select 2]];"];
	_unit addEventHandler ["Hit", "(_this select 0) setVariable  [""zHit"",[_this select 1, _this select 2]];"];
	_units pushBack _unit;

};

if !(_units isEqualTo []) then {
	_units remoteExec ["EPOCH_localCleanup",2];
};
