/*
	Author: Aaron Clark - EpochMod.com

    Contributors:

	Description:
	repair object via hit index

    Licence:
    Arma Public License Share Alike (APL-SA) - https://www.bistudio.com/community/licenses/arma-public-license-share-alike

    Github:
    https://github.com/EpochModTeam/Epoch/tree/release/Sources/epoch_code/compile/vehicles/EPOCH_client_repairVehicle.sqf
*/
//[[[cog import generate_private_arrays ]]]
private ["_currentDMG"];
//[[[end]]]
params ["_vehicle","_value"];
if (local _vehicle) then {
	_currentDMG = _vehicle getHitIndex (_value select 0);
	_vehicle setHitIndex[_value select 0, (_currentDMG - 0.5) max 0];
};
