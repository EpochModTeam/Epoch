/*
	Author: Andrew Gregory - EpochMod.com

    Contributors: Aaron Clark

	Description:
	Creates helicopter air drop

    Licence:
    Arma Public License Share Alike (APL-SA) - https://www.bistudio.com/community/licenses/arma-public-license-share-alike

    Github:
    https://github.com/EpochModTeam/Epoch/tree/release/Sources/epoch_server/compile/epoch_missions/EPOCH_Server_createAirDrop.sqf
*/
private ["_playerOwner","_objType","_obj","_grp","_unitPos","_driver","_unit"];
params ["_player",["_token","",[""]],"_pos"];

if (!isNil "axenotSent" && {axenotSent}) exitWith {
	diag_log format ["DEBUG: airdrop script already running %1",_this];
};

if !([_player,_token]call EPOCH_server_getPToken)exitWith{};

_pos set[2, 2400];

if !((nearestObjects[_pos, ["B_Heli_Transport_01_F"], 1000]) isEqualTo[]) exitWith{ diag_log "DEBUG: prevented air drop, too many in area." };

_playerOwner = owner _player;

_objType = "B_Heli_Transport_01_F";
diag_log format["Epoch: Creating %1 for %3 (Owner ID: %4) at %2",_objType, _pos, name _player, owner _player];
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

[_obj,_driver,_player] spawn {
	axenotSent = true;
	params ["_obj","_driver","_player"];
	while {axenotSent} do {
		if (isNull _obj || isNull _driver ||isNull _player) exitWith {axenotSent = false};
		_drvOwner = owner _driver;
		_playerOwner = owner _player;
		if(_drvOwner == _playerOwner) exitWith {
			// send airdrop to player
			_obj remoteExec ['EPOCH_mission_returnObj',_player];
			// since we found an owner, add cleanup if ownership reverts to server. This can also be used to change ownership instead later.
			_obj call EPOCH_localCleanup;
			diag_log format["DEBUG: Transferred ownership of %1 to %2, new owner ID is %3",_driver, name _player, owner _driver];
			axenotSent = false;
		};
		(group _driver) setGroupOwner _playerOwner;
		uiSleep 1;
	};
};
