/*
	Author: Aaron Clark - EpochMod.com

    Contributors:

	Description:
	lock local object

    Licence:
    Arma Public License Share Alike (APL-SA) - https://www.bistudio.com/community/licenses/arma-public-license-share-alike

    Github:
    https://github.com/EpochModTeam/Epoch/tree/release/Sources/epoch_code/compile/vehicles/EPOCH_client_lockVehicle.sqf
*/
params ["_vehicle","_value"];
if (local _vehicle) then {
	_vehicle lock _value;
};
