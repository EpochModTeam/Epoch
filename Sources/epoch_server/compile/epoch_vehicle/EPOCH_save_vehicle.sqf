private ["_vehicle","_class","_vehSlot","_vehHiveKey","_damage","_fuel","_pos","_dir","_worldspace","_hitpoints","_actualHitpoints","_inventory","_VAL","_return","_magazines","_colorSlot","_magsAmmoCargoMinimized","_cargoIndex"];
if (!isNull _this) then {

	_vehicle = _this;
	// if (!alive _vehicle) exitWith {diag_log format["DEBUG DEAD VEHICLE SKIPPED SAVE: %1 %2", _vehicle]};
	_vehSlot = _this getVariable["VEHICLE_SLOT", "ABORT"];
	if (_vehSlot != "ABORT") then {

		_vehHiveKey = format ["%1:%2", (call EPOCH_fn_InstanceID),_vehSlot];

		_hitpoints = (getAllHitPointsDamage _vehicle) param [2,[]];

		// may not be needed but should prevent <null> in DB.
		_wepsItemsCargo = weaponsItemsCargo _vehicle;
		if (isNil "_wepsItemsCargo") then {
			_wepsItemsCargo = [];
		};
		_magsAmmoCargo = magazinesAmmoCargo _vehicle;
		if (isNil "_magsAmmoCargo") then {
			_magsAmmoCargo = [];
		};

		// minimize magazine ammo cargo
		_magsAmmoCargoMinimized = [[],[]];
		{
			// find cargo in temp var
			_cargoIndex = _magsAmmoCargoMinimized find (_x select 0);
			if (_cargoIndex >= 0) then {
				(_magsAmmoCargoMinimized select 1) set [_cargoIndex, ((_magsAmmoCargoMinimized select 1) select _cargoIndex) + (_x select 1)]; // get count & add current
			}
			else {
				(_magsAmmoCargoMinimized select 0) pushBack (_x select 0); // classname
				(_magsAmmoCargoMinimized select 1) pushBack (_x select 1); // count
			};
		} forEach _magsAmmoCargo;

		_inventory = [
			_wepsItemsCargo,
			_magsAmmoCargoMinimized,
			getBackpackCargo _vehicle,
			getItemCargo _vehicle
		];
		_colorSlot = _vehicle getVariable ["VEHICLE_TEXTURE",0];

		_VAL = [typeOf _vehicle,[(getposATL _vehicle call EPOCH_precisionPos),vectordir _vehicle,vectorup _vehicle],damage _vehicle,_hitpoints,fuel _vehicle,_inventory,magazinesAmmo _vehicle,_colorSlot];
		["Vehicle", _vehHiveKey, EPOCH_expiresVehicle, _VAL] call EPOCH_fnc_server_hiveSETEX;
		//["Vehicle", _vehHiveKey, _VAL] call EPOCH_fnc_server_hiveSET;
	};
};
