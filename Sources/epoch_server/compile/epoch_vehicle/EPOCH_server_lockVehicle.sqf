/*
	Author: Aaron Clark - EpochMod.com

    Contributors:

	Description:
    (Un)Lock Vehicles

    Licence:
    Arma Public License Share Alike (APL-SA) - https://www.bistudio.com/community/licenses/arma-public-license-share-alike

    Github:
    https://github.com/EpochModTeam/Epoch/tree/release/Sources/epoch_server/compile/epoch_vehicle/EPOCH_server_lockVehicle.sqf
*/
//[[[cog import generate_private_arrays ]]]
private ["_VehLockMessages","_msg","_crew","_driver","_isLocked","_lockOwner","_lockedOwner","_logic","_playerGroup","_playerUID","_response","_vehLockHiveKey","_vehSlot","_nearhome","_lockArr"];
//[[[end]]]
params [
    ["_vehicle",objNull,[objNull]],
    ["_value",true,[true]],
    ["_player",objNull,[objNull]],
    ["_token","",[""]]
];

if (isNull _vehicle) exitWith {};
if !([_player,_token] call EPOCH_server_getPToken) exitWith {};
if (_player distance _vehicle > 20) exitWith {};

_VehLockMessages = ['CfgEpochClient' call EPOCH_returnConfig, "VehLockMessages", true] call EPOCH_fnc_returnConfigEntry;

// Group access
_playerUID = getPlayerUID _player;
_playerGroup = _player getVariable["GROUP", ""];

_lockOwner = _playerUID;
_lockArr = [_playerUID];
if (_playerGroup != "") then {
	_lockOwner = _playerGroup;
	_lockArr pushbackunique _playerGroup;
};

_lockedOwner = "-1";
_nearhome = false;
_vehSlot = _vehicle getVariable["VEHICLE_SLOT", "ABORT"];
_vehLockHiveKey = format["%1:%2", (call EPOCH_fn_InstanceID), _vehSlot];
if (_vehSlot != "ABORT") then {
	_response = ["VehicleLock", _vehLockHiveKey] call EPOCH_fnc_server_hiveGETRANGE;
	if ((_response select 0) == 1 && (_response select 1) isEqualType [] && !((_response select 1) isEqualTo[])) then {
		_lockedOwner = _response select 1 select 0;
	};
}
else {
	_lockedOwner = _vehicle getvariable ["EPOCH_LockedOwner","-1"];
};

// get locked state
_isLocked = locked _vehicle in[2, 3];

_driver = driver _vehicle;
_crew = [];
{
	// only get alive crew
	if (alive _x) then {
		_crew pushBack _x;
	};
} forEach (crew _vehicle);


// if vehicle has a crew and player is not inside vehicle only allow locking if already owner
_logic = if !(_crew isEqualTo []) then {
	if (_player in _crew) then {
		// allow unlock if player is the driver or is inside the vehicle with out a driver.
		(_player isEqualTo _driver || isNull(_driver) || _lockedOwner in _lockArr || !alive _driver)
	} else {
		// allow only if player is already the owner as they are not inside the occupied vehicle.
		(_lockedOwner in _lockArr)
	};
} else {
	// vehicle has no crew, so allow only if: unlocked, is already the owner, vehicle has no owner.
	(!_isLocked || _lockedOwner in _lockArr || _lockedOwner == "-1")
};

// Lockout mech
if (_logic) then {

	if (_value) then {
		if !(_vehSlot isequalto "ABORT") then {
			_nearhome = {(_x getVariable["BUILD_OWNER", "-1"]) in [_lockOwner] && {((_vehicle distance _x) < (getnumber (missionconfigfile >> "CfgEpochClient" >> "CfgJammers" >> (typeof _x) >> "buildingJammerRange")))}} count Epoch_PlotPoles > 0;
			["VehicleLock", _vehLockHiveKey, if (_nearhome) then {EPOCH_vehicleLockTimeHome} else {EPOCH_vehicleLockTime}, [_lockOwner]] call EPOCH_fnc_server_hiveSETEX;
		}
		else {
			_vehicle setvariable ["EPOCH_LockedOwner",_lockOwner];
		};
	} else {
        // re-allow damage (server-side) on first unlock
        if (_vehicle getVariable ["EPOCH_disallowedDamage", false]) then {
            _vehicle allowDamage true;
            _vehicle setVariable ["EPOCH_disallowedDamage", nil];
        };
    };

    // lock/unlock
	if (local _vehicle) then {
		_vehicle lock _value;
	} else {
		[_vehicle, _value] remoteExec ['EPOCH_client_lockVehicle',_vehicle];
	};
	if (_VehLockMessages) then {
		if (_value) then {
			_msg = format ["Vehicle Locked for %1 ",
				if (_nearhome && {(call compile EPOCH_vehicleLockTimeHome) > (call compile EPOCH_vehicleLockTime)}) then {
					(((call compile EPOCH_vehicleLockTimeHome)/60/60) toFixed 1) + " hours - Base Lock"
				} 
				else {
					(((call compile EPOCH_vehicleLockTime)/60/60) toFixed 1) + " hours"
				}
			];
			[_msg,10,[[1,0,0,0.2],[1,1,1,1]]] remoteExec ["Epoch_Message",_player];
		}
		else {
			_msg = "Vehicle unlocked";
			[_msg,10,[[0,1,0,0.2],[1,1,1,1]]] remoteExec ["Epoch_Message",_player];
		};
	};
}
else {
	if (_VehLockMessages) then {
		["You are not the owner",5] remoteExec ["Epoch_Message",_player];
	};
};
