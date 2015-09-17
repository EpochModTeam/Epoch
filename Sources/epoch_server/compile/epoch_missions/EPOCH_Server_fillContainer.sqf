private["_plyr","_container","_clearFirst","_pos","_chance","_weps","_mags","_items"];
_plyr = _this select 0;
if !([_plyr,_this select 1]call EPOCH_server_getPToken)exitWith{};

_container = objNull;
if (typename (_this select 2) == "OBJECT") then {_container = _this select 2;};

_clearFirst = false;
if (count _this > 3) then {_clearFirst = _this select 3;};

_chance = 25;
if (count _this > 4) then {_chance = _this select 4;};

_pos = getPosATL _plyr;
if (count _this > 5) then {_pos = _this select 5;};

if (isNull _container) then {
_container = createVehicle ["GroundWeaponHolder", _pos, [], 12, "CAN_COLLIDE"];
_container setPosATL _pos;
};
//diag_log format["Creating GroundWeaponHolder %3 at %1 for %2",_pos, name _plyr,_container];
if (_clearFirst) then {
clearWeaponCargoGlobal _container;
clearItemCargoGlobal _container;
clearMagazineCargoGlobal  _container;
clearBackpackCargoGlobal _container;
};

if (_chance > 0) then {
	// TODO add separate loot tables for each payout type
	[_container, "Mission_Payout1"] call EPOCH_serverLootObject;
};
