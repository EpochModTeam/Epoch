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
private ["_cfgBaseBuilding","_fnc_lock","_fnc_unlock","_gArray","_owners","_playerGroup","_playerUID","_response","_type"];
//[[[end]]]
params ["_unit","_lockStatus","_player",["_token","",[""]] ];
if !([_player, _token] call EPOCH_server_getPToken) exitWith{};
if (isNull _unit) exitWith{};
if (_player distance _unit > 20) exitWith{};
_type = typeOf _unit;
_playerUID = getPlayerUID _player;
_playerGroup = _player getVariable ["GROUP",""];

_fnc_lock = {
	_this setVariable ["EPOCH_Locked", true, true];
	EPOCH_saveStorQueue pushBackUnique _this;
};
_fnc_unlock = {
	_this setVariable ["EPOCH_Locked", false, true];
};

_cfgBaseBuilding = 'CfgBaseBuilding' call EPOCH_returnConfig;
if (getNumber(_cfgBaseBuilding >> _type >> "isSecureStorage") == 1) then{

	_owners = _unit getVariable["STORAGE_OWNERS", []];

	// locked > unlocked
	if !(_unit getVariable ["EPOCH_Locked", true]) then {

		// allow group members and owner access
		if (_playerGroup != "") then {
			if (_playerGroup in _owners) then {
				_unit call _fnc_lock;
			} else {

				_response = ["Group", _playerGroup] call EPOCH_fnc_server_hiveGETRANGE;
				if ((_response select 0) == 1 && (_response select 1) isEqualType []) then {
					_gArray = _response select 1;
					if (
						{(_x select 0) in _owners}count(_gArray select 3) > 0 ||
						{(_x select 0) in _owners}count(_gArray select 4) > 0 ||
						_playerUID in _owners
					) then {
						_unit call _fnc_lock;
					};
				};
			};

		} else {
			if (_playerUID in _owners) then {
				_unit call _fnc_lock;
			};
		};

	// unlocked > locked
	} else {

		// allow group members and owner access
		if (_playerGroup != "") then {
			if (_playerGroup in _owners) then {
				_unit call _fnc_unlock;
			} else {
				_response = ["Group", _playerGroup] call EPOCH_fnc_server_hiveGETRANGE;
				if ((_response select 0) == 1 && (_response select 1) isEqualType []) then {
					_gArray = _response select 1;
					if (
						{(_x select 0) in _owners }count(_gArray select 3) > 0 ||
						{(_x select 0) in _owners}count(_gArray select 4) > 0 ||
						_playerUID in _owners
					) then {
						_unit call _fnc_unlock;
					};
				};
			};
		} else {
			if (_playerUID in _owners) then {
				_unit call _fnc_unlock;
			};
		};
	};
};
