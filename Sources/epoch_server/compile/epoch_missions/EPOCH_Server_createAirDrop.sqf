private["_plyr","_objType","_obj","_pos","_unitPos","_driver","_unit","_grp","_axeCopter","_plyrOwner"];
_plyr = _this select 0;
if !([_plyr,_this select 1]call EPOCH_server_getPToken)exitWith{};

_pos = _this select 2;
_pos set[2, 2400];

if !((nearestObjects[_pos, ["B_Heli_Transport_01_F"], 1000]) isEqualTo[]) exitWith{ diag_log "DEBUG: prevented air drop, too many in area." };

_plyrOwner = owner _plyr;

_objType = "B_Heli_Transport_01_F";
diag_log format["DEBUG: Creating %1 for %3 (Owner ID: %4) at %2",_objType, _pos, name _plyr, owner _plyr];
_obj = createVehicle [_objType, _pos, [], 0, "FLY"];
_obj call EPOCH_server_setVToken; 
addToRemainsCollector[_obj]; 
_obj disableTIEquipment true; 

clearWeaponCargoGlobal _obj;
clearItemCargoGlobal _obj;
clearMagazineCargoGlobal  _obj;
clearBackpackCargoGlobal _obj;

_obj allowdamage false;
_obj setPosATL _pos;
_obj setFuel 1;
_obj flyInHeight 120;
_grp = createGroup RESISTANCE;

_unitPos = _pos;
_driver = _grp createUnit["I_helipilot_F", _unitPos, [], 0, "CAN_COLLIDE"];
_driver assignAsDriver _obj;
_driver moveInDriver _obj;

_unitPos = _pos findEmptyPosition [1,75,"I_helipilot_F"];

_unit = _grp createUnit["I_helicrew_F", _unitPos, [], 0, "CAN_COLLIDE"];
_unit assignAsGunner _obj;
_unit moveInGunner _obj;

_grp setCombatMode "BLUE";

(driver _obj) action ["engineOn", _obj];
_obj setVehicleLock "LOCKEDPLAYER"; 

[_obj,_driver,_plyr] spawn {	
	axenotSent = false;
	axenotSent = true;
	_obj = _this select 0;
	_driver = _this select 1;
	_plyr = _this select 2;
	while {axenotSent} do {
		_drvOwner = owner _driver;
		_plyrOwner = owner _plyr; 
		(group _driver) setGroupOwner _plyrOwner;
		if((_drvOwner == _plyrOwner)) then {
			[["airDrop", _obj], owner _plyr] call EPOCH_sendPublicVariableClient;
			diag_log format["DEBUG: Transferred ownership of %1 to %2, new owner ID is %3",_driver, name _plyr, owner _driver];
			axenotSent = false;
			// since we found an owner, add cleanup if ownership reverts to server. This can also be used to change ownership instead later.
			_obj call EPOCH_localCleanup;
		};
		uiSleep 0.5;
	};
};