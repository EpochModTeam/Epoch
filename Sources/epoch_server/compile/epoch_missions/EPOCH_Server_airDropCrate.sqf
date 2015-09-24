private["_plyr","_axeCopter","_pos","_axeCrate","_crateSmoke","_weps","_mags","_items"];
_plyr = _this select 1;
if !([_plyr,_this select 2]call EPOCH_server_getPToken)exitWith{};

_axeCopter = _this select 0;
_pos = getPos _axeCopter;
//diag_log format["Air Drop At: %1 for %2",_pos, name _plyr];
 _pos set [2,(_pos select 2) - 2];
_axeCrate = createVehicle ["B_supplyCrate_F", _pos, [], 10, "NONE"];
_axeChute = createVehicle ["NonSteerable_Parachute_F", _pos, [], 10, "FLY"];
_axeCrate attachTo [_axeChute, [0, 0, 0] ]; 
_crateSmoke = "SmokeShell" createVehicle _pos;
_crateSmoke attachTo [_axeChute,[0,0,-0.4]];
clearWeaponCargoGlobal _axeCrate;
clearItemCargoGlobal _axeCrate;
clearMagazineCargoGlobal  _axeCrate;
clearBackpackCargoGlobal _axeCrate;
_axeLight = "Land_Camping_Light_F" createvehicle _pos;
_axeLight attachTo [_axeCrate, [0.71, 0.18, -0.22] ]; 
_axeCrate setPos _pos;
// universal payout system
[_axeCrate, "AirDrop_Payout1"] call EPOCH_serverLootObject;
