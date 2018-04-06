/*
	Author: Aaron Clark - EpochMod.com

    Contributors:

	Description:
    Save Storage Object

    Licence:
    Arma Public License Share Alike (APL-SA) - https://www.bistudio.com/community/licenses/arma-public-license-share-alike

    Github:
    https://github.com/EpochModTeam/Epoch/tree/release/Sources/epoch_server/compile/epoch_vehicle/EPOCH_server_save_vehicle.sqf
*/
//[[[cog import generate_private_arrays ]]]
private ["_VAL","_cargo","_cargoIndex","_colorSlot","_hitpoints","_inventory","_magsAmmoCargo","_magsAmmoCargoMinimized","_magsAmmoCargox","_newComponents","_selectedWeapon","_selectedWeaponComponents","_startTime","_vehHiveKey","_vehSlot","_weapon","_weaponComponents","_wepsItemsCargo","_wepsItemsCargoNormalized","_wepsItemsCargox"];
//[[[end]]]
params [["_vehicle",objNull]];

if (!isNull _vehicle) then {

	if (!alive _vehicle) exitWith {diag_log format["DEBUG DEAD VEHICLE SKIPPED SAVE: %1 %2", _vehicle]};
	_vehSlot = _vehicle getVariable["VEHICLE_SLOT", "ABORT"];
	if (_vehSlot != "ABORT") then {

		_vehHiveKey = format ["%1:%2", (call EPOCH_fn_InstanceID),_vehSlot];

		_hitpoints = (getAllHitPointsDamage _vehicle) param [2,[]];

		_inventory = _vehicle call EPOCH_server_CargoSave;
		
		_colorSlot = _vehicle getVariable ["VEHICLE_TEXTURE",0];
		_baseType = _vehicle getVariable ["VEHICLE_BASECLASS",""];
		_VAL = [typeOf _vehicle,[getposworld _vehicle,vectordir _vehicle,vectorup _vehicle,true],damage _vehicle,_hitpoints,fuel _vehicle,_inventory,[true,magazinesAllTurrets _vehicle],_colorSlot,_baseType];
		["Vehicle", _vehHiveKey, EPOCH_expiresVehicle, _VAL] call EPOCH_fnc_server_hiveSETEX;
	};
};
