/*
	Author: Aaron Clark - EpochMod.com

    Contributors:

	Description:
    Killed building handler

    Licence:
    Arma Public License Share Alike (APL-SA) - https://www.bistudio.com/community/licenses/arma-public-license-share-alike

    Github:
    https://github.com/EpochModTeam/Epoch/tree/master/Sources/epoch_server/compile/epoch_vehicle/EPOCH_server_save_killedVehicle.sqf
*/
private ["_vehSlot","_vehHiveKey"];
params ["_vehicle","_killer"];
if (!isNull _vehicle) then {
	_vehSlot = _vehicle getVariable ["VEHICLE_SLOT", "ABORT"];
	if (_vehSlot != "ABORT") then {
		_vehHiveKey = format ["%1:%2", (call EPOCH_fn_InstanceID), _vehSlot];
		["Vehicle", _vehHiveKey] call EPOCH_fnc_server_hiveDEL;
		EPOCH_VehicleSlots pushBack _vehSlot;
		EPOCH_VehicleSlotCount = count EPOCH_VehicleSlots;
		publicVariable "EPOCH_VehicleSlotCount";

		['VehicleKilled', format["%1 was killed by %2 at %3", typeOf _vehicle, _killer, getPosATL _vehicle]] call EPOCH_fnc_server_hiveLog;
	};
};
