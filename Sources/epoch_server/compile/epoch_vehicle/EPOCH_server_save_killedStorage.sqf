/*
	Author: Aaron Clark - EpochMod.com

    Contributors:

	Description:
    Killed building handler

    Licence:
    Arma Public License Share Alike (APL-SA) - https://www.bistudio.com/community/licenses/arma-public-license-share-alike

    Github:
    https://github.com/EpochModTeam/Epoch/tree/master/Sources/epoch_server/compile/epoch_vehicle/EPOCH_server_save_killedStorage.sqf
*/
private ["_vehSlot","_vehHiveKey"];
params ["_storage","_killer"];

if (!isNull _storage) then {
	_vehSlot = _storage getVariable["STORAGE_SLOT", "ABORT"];
	if (_vehSlot != "ABORT") then {
		_vehHiveKey = format ["%1:%2", (call EPOCH_fn_InstanceID), _vehSlot];
		["Storage", _vehHiveKey] call EPOCH_fnc_server_hiveDEL;
		EPOCH_StorageSlots pushBack _vehSlot;
		missionNamespace setVariable ['EPOCH_StorageSlotsCount', count EPOCH_StorageSlots, true];

		['StorageKilled', format["%1 was killed by %2 at %3", typeOf _storage, _killer, getPosATL _storage]] call EPOCH_fnc_server_hiveLog;
	};
};
