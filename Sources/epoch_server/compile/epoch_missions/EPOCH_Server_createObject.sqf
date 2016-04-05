/*
	Author: Aaron Clark - EpochMod.com

    Contributors:

	Description:
	Server side spawing of shipwreck loots

    Licence:
    Arma Public License Share Alike (APL-SA) - https://www.bistudio.com/community/licenses/arma-public-license-share-alike

    Github:
    https://github.com/EpochModTeam/Epoch/tree/master/Sources/epoch_server/compile/epoch_missions/EPOCH_Server_createObject.sqf
*/
private ["_grp","_driver","_gunner","_commander","_crew","_missionVehList","_obj"];
params ["_player",["_token","",[""]],"_objType","_clearCargo","_pos",["_objSpc","CAN_COLLIDE"],"_driverType","_gunnerType","_commanderType","_crewType"];

if !([_player,_token]call EPOCH_server_getPToken)exitWith{};

if (count _this != 11) exitWith {diag_log format ["Epoch: Debug: %1 exit with %2",__FILE__,_this]};

_missionVehList = ["O_UAV_01_F","B_UAV_01_F","I_Boat_Armed_01_minigun_F","B_Heli_Transport_01_F",""];
if!(_objType in _missionVehList)exitWith{};

if !(_pos isEqualTo []) then {
	_pos = (getPosATL _player) findEmptyPosition [1,250,_objType];
	if (count _pos < 1) then {
		_pos = getPosATL _player;
	};
};

//_doOwner = _this select 10;
_obj = createVehicle [_objType, _pos, [], 0, _objSpc];
_obj call EPOCH_server_setVToken;
addToRemainsCollector[_obj];
_obj disableTIEquipment true;

_obj allowdamage false;
_obj setPosATL _pos;
_obj setFuel 1;
//if (_doOwner) then {_obj setOwner (owner _player)};

if (_clearCargo) then {
	clearWeaponCargoGlobal _obj;
	clearItemCargoGlobal _obj;
	clearMagazineCargoGlobal  _obj;
	clearBackpackCargoGlobal _obj;
};

if (_driverType != "" || _gunnerType != "" ||_commanderType != "") then {
	_grp = createGroup RESISTANCE;
};

if (_driverType != "") then {
	_driver = _grp createUnit[_driverType, position _obj, [], 1, "CAN_COLLIDE"];
	_driver assignAsDriver _obj;
	_driver moveInDriver _obj;
	//if (_doOwner) then {_driver setOwner (owner _player)};
};

if (_gunnerType != "") then {
	_gunner = _grp createUnit[_gunnerType, position _obj, [], 1, "CAN_COLLIDE"];
	_gunner assignAsGunner _obj;
	_gunner moveInGunner _obj;
	//if (_doOwner) then {_gunner setOwner (owner _player)};
};

if (_commanderType != "") then {
	_commander = _grp createUnit[_commanderType, position _obj, [], 1, "CAN_COLLIDE"];
	_commander assignAsCommander _obj;
	_commander moveInCommander _obj;
	//if (_doOwner) then {_commander setOwner (owner _player)};
};

if (_crewType != "") then {
	_crew = _grp createUnit[_crewType, position _obj, [], 1, "CAN_COLLIDE"];
	_crew assignAsCargo _obj;
	_crew moveInCargo _obj;
	//if (_doOwner) then {_crew setOwner (owner _player)};
};
_obj allowdamage true;
diag_log format["Epoch: Spawned Object %1(%5) for %3(%4) at %2",_objType,_pos,name _player,owner _player,owner _obj];
