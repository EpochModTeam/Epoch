/*
	Author: Aaron Clark - EpochMod.com

    Contributors:

	Description:
    Refuel Vehicles

    Licence:
    Arma Public License Share Alike (APL-SA) - https://www.bistudio.com/community/licenses/arma-public-license-share-alike

    Github:
    https://github.com/EpochModTeam/Epoch/tree/release/Sources/epoch_server/compile/epoch_vehicle/EPOCH_server_lockStorage.sqf
*/
//[[[cog import generate_private_arrays ]]]
private ["_cfgBaseBuilding","_owners","_playerGroup","_playerUID","_response","_type","_locked","_LockStateChanged","_msg"];
//[[[end]]]
params ["_unit","_lockStatus","_player",["_token","",[""]] ];
if !([_player, _token] call EPOCH_server_getPToken) exitWith{};
if (isNull _unit) exitWith{};
if (_player distance _unit > 20) exitWith{};
_VehLockMessages = ['CfgEpochClient' call EPOCH_returnConfig, "VehLockMessages", true] call EPOCH_fnc_returnConfigEntry;
_type = typeOf _unit;
_playerUID = getPlayerUID _player;
_playerGroup = _player getVariable["GROUP", ""];

_fnc_Lock_Unlock = {
	_locked = !_locked;
	_unit setVariable ["EPOCH_Locked", _locked, true];
	if (_unit iskindof "GunSafe_EPOCH") then {
		_animations = if (_locked) then {[['door1',0],['door2',0],['handle1',0],['handle2',0]]} else {[['handle1',1],['handle2',1],['door1',1],['door2',1]]};
		[_unit,_animations,[0,1,0]] remoteexec ['EPOCH_fnc_AnimateScheduled',_player];
	};
	_LockStateChanged = true;
};

_cfgBaseBuilding = 'CfgBaseBuilding' call EPOCH_returnConfig;
if (getNumber(_cfgBaseBuilding >> _type >> "isSecureStorage") == 1) then {
	_owners = _unit getVariable["STORAGE_OWNERS", []];
	_locked = _unit getVariable ["EPOCH_Locked", true];
	_LockStateChanged = false;
	if (_playerUID in _owners) then {
		call _fnc_Lock_Unlock;
	}
	else {
		if (_playerGroup != "") then {
			if (_playerGroup in _owners) then {
				call _fnc_Lock_Unlock;
			}
			else {
				_response = ["Group", _playerGroup] call EPOCH_fnc_server_hiveGETRANGE;
				(_response param [1,[]]) params ["","","",["_modArray",[]],["_memberArray",[]]];
				if (
					{(_x select 0) in _owners} count _modArray > 0 ||
					{(_x select 0) in _owners} count _memberArray > 0
				) then {
					call _fnc_Lock_Unlock;
				};
			};
		};
	};
	_msg = "You are not the owner";
	if (_LockStateChanged) then {
		if (_locked) then {
			EPOCH_saveStorQueue pushBackUnique _unit;
			_msg = "Storage Locked";
		}
		else {
			_msg = "Storage Unlocked";
		};
	};
	if (_VehLockMessages) then {
		[_msg,5] remoteExec ["Epoch_Message",_player];
	};
};
