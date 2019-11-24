/*
	Author: Aaron Clark - EpochMod.com

    Contributors:

	Description:
    Save Storage Object

    Licence:
    Arma Public License Share Alike (APL-SA) - https://www.bistudio.com/community/licenses/arma-public-license-share-alike

    Github:
    https://github.com/EpochModTeam/Epoch/tree/release/Sources/epoch_server/compile/epoch_vehicle/EPOCH_server_save_storage.sqf
*/
//[[[cog import generate_private_arrays ]]]
private ["_VAL","_cargo","_cargoIndex","_class","_colorSlot","_damage","_inventory","_locked","_magsAmmoCargo","_magsAmmoCargoMinimized","_magsAmmoCargox","_newComponents","_selectedWeapon","_selectedWeaponComponents","_storageOwners","_vehHiveKey","_vehSlot","_vehiclePos","_weapon","_weaponComponents","_wepsItemsCargo","_wepsItemsCargoNormalized","_wepsItemsCargox","_worldspace"];
//[[[end]]]
params [["_vehicle",objNull]];

if (!isNull _vehicle) then {
	_class = typeOf _vehicle;
	_vehSlot = _vehicle getVariable["STORAGE_SLOT", "ABORT"];
	if (_vehSlot != "ABORT") then {

		_vehHiveKey = format ["%1:%2", (call EPOCH_fn_InstanceID),_vehSlot];

		_damage = 0;
		_vehicle setDamage 0;

		_inventory = _vehicle call EPOCH_server_CargoSave;
		
		_colorSlot = _vehicle getVariable ["STORAGE_TEXTURE",0];
		_storageOwners = _vehicle getVariable["STORAGE_OWNERS",[]];
		_locked = if (_vehicle getVariable["EPOCH_Locked", true]) then {1} else {-1};
		_worldspace = [getposworld _vehicle call EPOCH_precisionPos, vectordir _vehicle, vectorup _vehicle, true];

		_VAL = [_class, _worldspace, _damage, _inventory, _colorSlot, _storageOwners, _locked];
		["Storage", _vehHiveKey, EPOCH_expiresBuilding, _VAL] call EPOCH_fnc_server_hiveSETEX;
		diag_log format["STORAGE: saved to hive %1 Pos %2 Owners %3 Locked %4", _class, _worldspace, _storageOwners, _locked];
	};

};
