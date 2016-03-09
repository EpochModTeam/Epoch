/*
	Author: Aaron Clark - EpochMod.com

    Contributors:

	Description:
	Creates air drop crate

    Licence:
    Arma Public License Share Alike (APL-SA) - https://www.bistudio.com/community/licenses/arma-public-license-share-alike

    Github:
    https://github.com/EpochModTeam/Epoch/tree/master/Sources/epoch_server/compile/epoch_missions/EPOCH_Server_airDropCrate.sqf
*/
private ["_pos","_axeCrate","_axeChute","_crateSmoke","_axeLight"];
params ["_object","_player","_token"];

if !([_player,_token] call EPOCH_server_getPToken)exitWith{};

_pos = getPos _object;
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
