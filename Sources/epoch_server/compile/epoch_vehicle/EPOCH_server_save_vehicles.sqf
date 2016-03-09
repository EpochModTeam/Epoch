/*
	Author: Aaron Clark - EpochMod.com

    Contributors:

	Description:
    Adds an array of objects to save queues

    Licence:
    Arma Public License Share Alike (APL-SA) - https://www.bistudio.com/community/licenses/arma-public-license-share-alike

    Github:
    https://github.com/EpochModTeam/Epoch/tree/master/Sources/epoch_server/compile/epoch_vehicle/EPOCH_server_save_vehicles.sqf
*/
private ["_vehSlot","_storSlot","_objSlot"];
params [["_objects",[]]];
{
	if (!isNull _x) then {
		_vehSlot = _x getVariable ["VEHICLE_SLOT", "ABORT"];
		if (_vehSlot != "ABORT") then {
			EPOCH_saveVehQueue pushBackUnique _x;
		};
		_storSlot = _x getVariable["STORAGE_SLOT", "ABORT"];
		if (_storSlot != "ABORT") then {
			EPOCH_saveStorQueue pushBackUnique _x;
		};
		_objSlot = _x getVariable["BUILD_SLOT", -1];
		if (_objSlot != -1) then{
			EPOCH_saveBuildQueue pushBackUnique _x;
		};
	};
} forEach _objects;
