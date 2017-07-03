/*
	Author: Aaron Clark - EpochMod.com

    Contributors: He-Man and DirtySanchez

	Description:
    Upgrade vehicle

    Licence:
    Arma Public License Share Alike (APL-SA) - https://www.bistudio.com/community/licenses/arma-public-license-share-alike
*/
params [["_array",[]],["_player",objnull],["_token","",[""]]];
if (_array isequalto []) exitwith {
	diag_log "Array is empty";
};
if !([_player, _token] call EPOCH_server_getPToken) exitWith{
	diag_log "Tokencheck failed";
};
_array params [["_veh",objnull],["_UpgradeVeh",""],["_removeCrypto",[]]];
if (isnull _veh) exitwith {
	diag_log "Vehicle is null";
};
if (_UpgradeVeh isequalto "") exitwith {
	diag_log "No Upgrade Vehicle Class";
};
if !(_removeCrypto isequalto []) && !(_removeCrypto isEqualTo 0) then {
	[_player,-_removeCrypto] remoteExec ["EPOCH_server_effectCrypto",2];
};
_slot = _veh getvariable ["vehicle_slot","-1"];
if (_slot isequalto "-1") exitwith {
	diag_log "Vehicle has no Slot";
};
_pos = getposasl _veh;
_dir = getdir _veh;
deletevehicle _veh;
waituntil {isnull _veh};
_pos set [2,(_pos select 2)+0.5];
_veh = createVehicle [_UpgradeVeh, [random 500, random 500,500], [], 0, "CAN_COLLIDE"];		
_veh setVariable ["VEHICLE_SLOT", _slot, true];
_veh call EPOCH_server_setVToken;
_veh call EPOCH_server_vehicleInit;
_veh setdir _dir;
_veh setposasl _pos;

