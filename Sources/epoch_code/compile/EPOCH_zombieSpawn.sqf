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
	zedHandle
*/
_zRange = getNumber (getMissionConfig "CfgEpochRyanZombie" >> "range");
_disableAI = {{_this disableAI _x}forEach["TARGET","AUTOTARGET","FSM"];};
_unitClass = selectRandom ["EPOCH_RyanZombie_1","EPOCH_RyanZombie_2","EPOCH_RyanZombie_3","EPOCH_RyanZombie_4","EPOCH_RyanZombie_5"];
_unit = createAgent[_unitClass, position player, [], _zRange, "FORM"];
_clutterPos = getPosATL _unit;
if!(isOnRoad _unit)then{ 
createVehicle ["Land_Grave_dirt_F", _clutterPos, [], 0, "CAN_COLLIDE"];
};
_unit call _disableAI;
_unit switchMove "AmovPercMstpSnonWnonDnon_SaluteOut";
_unit setmimic "dead";
_unit setface (selectRandom ["RyanZombieFace1", "RyanZombieFace2", "RyanZombieFace3", "RyanZombieFace4", "RyanZombieFace5"]);
removegoggles _unit;
zedHandle = [_unit,true] execFSM "epoch_code\system\EPOCH_zombie_brain.fsm";
_unit addEventHandler ["FiredNear", "(_this select 0) setVariable [""zFiredNear"",[_this select 1, _this select 2]];"];
_unit addEventHandler ["Hit", "(_this select 0) setVariable  [""zHit"",[_this select 1, _this select 2]];"];
//if(isNil "axeFlag")then{ axeFlag = createVehicle ["Flag_Blue_F", (getpos player), [], 10, "CAN_COLLIDE"];};
