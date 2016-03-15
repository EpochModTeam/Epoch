/*
	Author: Aaron Clark - EpochMod.com

    Contributors:

	Description:
    Killed building handler

    Licence:
    Arma Public License Share Alike (APL-SA) - https://www.bistudio.com/community/licenses/arma-public-license-share-alike

    Github:
    https://github.com/EpochModTeam/Epoch/tree/master/Sources/epoch_server/compile/epoch_vehicle/EPOCH_server_save_killedBuilding.sqf
*/
private ["_vehSlot","_vehHiveKey","_ammoObj"];
params ["_building","_killer"];
if (!isNull _building) then {
	_vehSlot = _building getVariable["BUILD_SLOT", -1];
	if (_vehSlot != -1) then {
		// Set off trap object
		_ammoObj = _building getVariable ["EPOCH_TRAP_OBJ",objNull];
		if !(isNull _ammoObj) then {
			_ammoObj setDamage 1;
		};
		_vehHiveKey = format ["%1:%2", (call EPOCH_fn_InstanceID), _vehSlot];
		["Building", _vehHiveKey] call EPOCH_fnc_server_hiveDEL;
		EPOCH_BuildingSlots set [_vehSlot, 0];
		missionNamespace setVariable ['EPOCH_BuildingSlotCount', { _x == 0 } count EPOCH_BuildingSlots, true];

		['BuildingKilled', format["%1 was killed by %2 at %3", typeOf _building, _killer, getPosATL _building]] call EPOCH_fnc_server_hiveLog;
	};
};
