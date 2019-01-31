/*
	Author: Aaron Clark - EpochMod.com

    Contributors:

	Description:
    Killed building handler

    Licence:
    Arma Public License Share Alike (APL-SA) - https://www.bistudio.com/community/licenses/arma-public-license-share-alike

    Github:
    https://github.com/EpochModTeam/Epoch/tree/release/Sources/epoch_server/compile/epoch_vehicle/EPOCH_server_save_killedBuilding.sqf
*/
//[[[cog import generate_private_arrays ]]]
private ["_ammoObj","_vehHiveKey","_vehSlot"];
//[[[end]]]
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

		// If is BaseCam, remove from Array
		if (_building iskindof "BaseCam_EPOCH") then {
			EPOCH_BaseCams = EPOCH_BaseCams - [_building];
			publicvariable "EPOCH_BaseCams";
		};
		if (_building iskindof "PlotPole_EPOCH") then {
			EPOCH_Plotpoles = EPOCH_Plotpoles - [_building];
			publicvariable "EPOCH_Plotpoles";
		};
		// Check if building killer is the owner and log accordingly
		if (_killer isequaltype objnull) then {
			if ((_building getVariable["BUILD_OWNER", "-1"]) in [getPlayerUID _killer, _killer getVariable["GROUP", ""]]) then
			{
				['BuildingRemoved', format["%1 was removed by %2 (owner) at %3", typeOf _building, _killer, getPosATL _building]] call EPOCH_fnc_server_hiveLog;
			}
			else
			{
				['BuildingKilled', format["%1 was killed by %2 at %3", typeOf _building, _killer, getPosATL _building]] call EPOCH_fnc_server_hiveLog;
			};
		}
		else {
			// Killer is no Obj, but a String (some AdminTools use it)
			['BuildingRemoved', format["%1 was removed by %2 at %3", typeOf _building, _killer, getPosATL _building]] call EPOCH_fnc_server_hiveLog;
		};
	};
};
