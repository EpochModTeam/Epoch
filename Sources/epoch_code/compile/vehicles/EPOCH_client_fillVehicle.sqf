/*
	Author: Aaron Clark - EpochMod.com

    Contributors:

	Description:
	sets Fuel on local vehicle

    Licence:
    Arma Public License Share Alike (APL-SA) - https://www.bistudio.com/community/licenses/arma-public-license-share-alike

    Github:
    https://github.com/EpochModTeam/Epoch/tree/release/Sources/epoch_code/compile/vehicles/EPOCH_client_fillVehicle.sqf
*/
params ["_vehicle","_value"];
if (local _vehicle) then {
	_vehicle setFuel _value;
};
