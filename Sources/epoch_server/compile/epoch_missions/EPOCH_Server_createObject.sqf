private["_plyr","_objType","_obj","_objSpc","_clearCargo","_pos","_chance","_driver","_driverType","_gunner","_gunnerType","_commander","_commanderType","_crew","_crewType","_grp","_doOwner","_missionVehList"];
_missionVehList = ["O_UAV_01_F","B_UAV_01_F","I_Boat_Armed_01_minigun_F","B_Heli_Transport_01_F",""];

_plyr = _this select 0;
if !([_plyr,_this select 1]call EPOCH_server_getPToken)exitWith{};
if (count _this != 11) exitWith {diag_log format ["Debug: %1 exit with %2",__FILE__,_this]};

_objType = _this select 2;
if!(_objType in _missionVehList)exitWith{};


_clearCargo = _this select 3;
if ((_this select 4) isEqualTo []) then {
	_pos = _this select 4;
} else {
	_pos = (getPosATL _plyr) findEmptyPosition [1,250,_objType];
	if (count _pos < 1) then {
		_pos = getPosATL _plyr;
	};
};

_objSpc = if (_this select 5 == "") then {"CAN_COLLIDE"}else{_this select 5};
_driverType = _this select 6;
_gunnerType = _this select 7;
_commanderType = _this select 8;
_crewType = _this select 9;
//_doOwner = _this select 10;


_obj = createVehicle [_objType, _pos, [], 0, _objSpc];
_obj call EPOCH_server_setVToken; 
addToRemainsCollector[_obj]; 
_obj disableTIEquipment true; 

_obj allowdamage false;
_obj setPosATL _pos;
_obj setFuel 1;
//if (_doOwner) then {_obj setOwner (owner _plyr)};

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
	//if (_doOwner) then {_driver setOwner (owner _plyr)};
};

if (_gunnerType != "") then {
	_gunner = _grp createUnit[_gunnerType, position _obj, [], 1, "CAN_COLLIDE"];
	_gunner assignAsGunner _obj;
	_gunner moveInGunner _obj;
	//if (_doOwner) then {_gunner setOwner (owner _plyr)};
};

if (_commanderType != "") then {
	_commander = _grp createUnit[_commanderType, position _obj, [], 1, "CAN_COLLIDE"];
	_commander assignAsCommander _obj;
	_commander moveInCommander _obj;
	//if (_doOwner) then {_commander setOwner (owner _plyr)};
};

if (_crewType != "") then {
	_crew = _grp createUnit[_crewType, position _obj, [], 1, "CAN_COLLIDE"];
	_crew assignAsCargo _obj;
	_crew moveInCargo _obj;
	//if (_doOwner) then {_crew setOwner (owner _plyr)};
};
_obj allowdamage true;
//diag_log format["Spawned Object %1(%5) for %3(%4) at %2",_objType,_pos,name _plyr,owner _plyr,owner _obj];
