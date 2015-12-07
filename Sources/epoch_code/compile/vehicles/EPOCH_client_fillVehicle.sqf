/*
	Author: Aaron Clark - EpochMod.com

    Contributors:

	Description:
	sets Fuel on local vehicle

    Licence:
    Arma Public License Share Alike (APL-SA) - https://www.bistudio.com/community/licenses/arma-public-license-share-alike

    Github:
    https://github.com/EpochModTeam/Epoch/tree/master/Sources/epoch_code/compile/vehicles/EPOCH_client_fillVehicle.sqf
*/
private["_vehicle","_value"];

_vehicle = _this select 0;
_value = _this select 1;
if (local _vehicle) then {
	_vehicle setFuel _value;
};
