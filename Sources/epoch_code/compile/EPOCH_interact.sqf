/*
	Author: Aaron Clark - EpochMod.com

    Contributors:

	Description:
	store all interacted vehicles for update

    Licence:
    Arma Public License Share Alike (APL-SA) - https://www.bistudio.com/community/licenses/arma-public-license-share-alike

    Github:
    https://github.com/EpochModTeam/Epoch/tree/release/Sources/epoch_code/compile/EPOCH_interact.sqf
*/
//[[[cog import generate_private_arrays ]]]
private ["_storSlot","_vehSlot","_buildSlot"];
//[[[end]]]
0 call EPOCH_refeshUI;
if (!isNull _this) then {
	_vehSlot = _this getVariable ["VEHICLE_SLOT", "ABORT"];
	if !(_vehSlot isEqualTo "ABORT") then {
		EPOCH_arr_interactedObjs pushBackUnique _this;
	};
	_storSlot = _this getVariable["STORAGE_SLOT", "ABORT"];
	if !(_storSlot isEqualTo "ABORT") then {
		EPOCH_arr_interactedObjs pushBackUnique _this;
	};
	_buildSlot = _this getVariable["BUILD_SLOT", "ABORT"];
	if !(_buildSlot isEqualTo "ABORT") then {
		EPOCH_arr_interactedObjs pushBackUnique _this;
	};
};
true
