private ["_vehicle","_class","_vehSlot","_vehHiveKey","_damage","_fuel","_pos","_dir","_worldspace","_hitpoints","_actualHitpoints","_inventory","_VAL","_return","_magazines","_colorSlot","_wepsItemsCargo","_magsAmmoCargo","_magsAmmoCargoMinimized","_cargoIndex"];
if (!isNull _this) then {
	_vehicle = _this;

	_class = typeOf _vehicle;
	_vehSlot = _vehicle getVariable["STORAGE_SLOT", "ABORT"];
	if (_vehSlot != "ABORT") then {

		_vehHiveKey = format ["%1:%2", (call EPOCH_fn_InstanceID),_vehSlot];
		_damage = damage _vehicle;

		_pos = getposATL _vehicle call EPOCH_precisionPos;
		_dir = getDir _vehicle;
		_worldspace = [_dir,_pos];

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

		_colorSlot = _vehicle getVariable ["STORAGE_TEXTURE",0];

		_storageOwners = _vehicle getVariable["STORAGE_OWNERS",[]];
		_storageParent = _vehicle getVariable["EPOCH_secStorParent",-1];

		_parentID = _vehicle getVariable["EPOCH_secStorParent", -1];
		_parent = missionNamespace getVariable[format["EPOCH_BUILD_%1", _parentID], objNull];

		/*
		if (!isNull _parent) then {
			_objSlot = _parent getVariable["BUILD_SLOT", -1];
			if (_objSlot != -1) then {
				_objHiveKey = format["%1:%2", (call EPOCH_fn_InstanceID), _objSlot];
				_VAL2 = [typeOf _parent, [(getposATL _parent call EPOCH_precisionPos), vectordir _parent, vectorup _parent], _vehSlot, _parent getVariable["BUILD_OWNER", "-1"], _parent getVariable["TEXTURE_SLOT", 0]];

				_parent call EPOCH_fnc_saveBuilding;

				["Building", _objHiveKey, EPOCH_expiresBuilding, _VAL2] call EPOCH_fnc_server_hiveSETEX;
			};
		};
		*/

		_VAL = [_class, _worldspace, _damage, _inventory, _colorSlot, _storageOwners, _storageParent];
		["Storage", _vehHiveKey, EPOCH_expiresBuilding, _VAL] call EPOCH_fnc_server_hiveSETEX;
		//["Storage", _vehHiveKey, _VAL] call EPOCH_fnc_server_hiveSET;

		diag_log format["STORAGE: saved to hive %1 Pos %2 Owners %3 Parent %4", _class, _worldspace, _storageOwners, _storageParent];
	};

};
