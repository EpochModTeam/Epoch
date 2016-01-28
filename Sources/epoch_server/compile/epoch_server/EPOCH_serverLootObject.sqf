private["_randomItemArray", "_quan", "_randomLootClass", "_type", "_randomItem", "_object", "_lootPaid", "_mags", "_lootItemWeightedArray", "_lootItemArray", "_weightedItemArray", "_weightedItemArrayCount", "_exit", "_maxPayout", "_lootTable", "_lootTableArray", "_weightedArray", "_weightedArrayCount"];
_object = _this select 0;
_type = _this select 1;

_randomizeMagazineAmmoCount = ["CfgEpochClient", "randomizeMagazineAmmoCount", true] call EPOCH_fnc_returnConfigEntryV2;

if !(isNull _object) then{

	_lootTable = [_type, "CfgMainTable", "tables"] call EPOCH_weightedArray;

	// diag_log format["%1: lootTable %2", __FILE__, _lootTable];

	_lootTableArray = _lootTable select 0;
	_weightedArray = _lootTable select 1;
	_weightedArrayCount = _lootTable select 2;

	if !(_lootTableArray isEqualTo []) then {

		_loots = [];

		_config = configFile >> "CfgMainTable" >> _type;
		_minLoot = getNumber(_config >> "lootMin");
		_maxLoot = getNumber(_config >> "lootMax");

		_maxPayout = ((random(_maxLoot) * EPOCH_lootMultiplier) min _maxLoot) max _minLoot;
		for "_k" from 1 to _maxPayout do {
			_loots pushBack (_lootTableArray select(_weightedArray select floor(random _weightedArrayCount)));
		};

		// diag_log format["%1: loots: %2", __FILE__, _loots];

		{
			// get weighted array
			_lootItemWeightedArray = [_x, "CfgLootTable", "items"] call EPOCH_weightedArray;

			// diag_log format["%1: lootItemWeightedArray1 %2", __FILE__, _lootItemWeightedArray];

			_lootItemArray = _lootItemWeightedArray select 0;
			if !(_lootItemArray isEqualTo[]) then {
				_weightedItemArray = _lootItemWeightedArray select 1;
				_weightedItemArrayCount = _lootItemWeightedArray select 2;

				_randomItemArray = _lootItemArray select (_weightedItemArray select floor(random _weightedItemArrayCount));

				_randomItem = _randomItemArray select 0;
				_type = _randomItemArray select 1;

				_quan = 1;

				/*
				if ((count _randomItem) >= 3) then {
					_quan = _randomItem select 2;
				};
				*/

				_loop = true;
				_exit = false;

				while {_loop} do {

					switch _type do {
						case "item": {
							_object additemCargoGlobal [_randomItem, _quan];
							_loop = false;
						};
						case "magazine": {
							if (_randomizeMagazineAmmoCount) then {
								// spawn a single Magazine with a random ammo count
								_magazineSize = getNumber (configFile >> "CfgMagazines" >> _randomItem >> "count");
								_object addMagazineAmmoCargo[_randomItem, _quan, ceil(random(_magazineSize))];
							} else {
								// spawn a single full Magazine
								_object addMagazineCargoGlobal [_randomItem, _quan];
							};
							_loop = false;
						};
						case "backpack": {
							_object addBackpackCargoGlobal [_randomItem, _quan];
							_loop = false;
						};
						case "weapon": {
							_object addWeaponCargoGlobal [_randomItem, _quan];
							_mags = getArray (configFile >> "CfgWeapons" >> _randomItem >> "magazines");

							if !(_mags isEqualTo []) then {
								if (_randomizeMagazineAmmoCount) then {
									// spawn a single Magazine with a random ammo count
									_magazineSize = getNumber (configFile >> "CfgMagazines" >> (_mags select 0) >> "count");
									_object addMagazineAmmoCargo[_mags select 0, 1, ceil(random(_magazineSize))];
								} else {
									// spawn a single full Magazine with weapon
									_object addMagazineCargoGlobal [_mags select 0, 1];
								};
							};
							_loop = false;
						};
						case "CfgLootTable": {

							// go down the rabit hole
							_lootItemWeightedArray = [_randomItem, "CfgLootTable", "items"] call EPOCH_weightedArray;

							_lootItemArray = _lootItemWeightedArray select 0;
							if !(_lootItemArray isEqualTo[]) then {

								_weightedItemArray = _lootItemWeightedArray select 1;
								_weightedItemArrayCount = _lootItemWeightedArray select 2;

								_randomItemArray = _lootItemArray select(_weightedItemArray select floor(random _weightedItemArrayCount));

								_randomItem = _randomItemArray select 0;
								_type = _randomItemArray select 1;
							} else {
								_exit = true;
							};
						};

						default {
							_exit = true;
						};
					};
					if (_exit) exitWith{ diag_log format["%1: CASE DEFAULT WITH %2", __FILE__, _this] };
				};
				//diag_log format["DEBUG SPAWN LOOT IN VEH: %1 %2 %3 type:%4", typeOf _object, _x, _randomItem, _type];
			};
		} forEach _loots;
	};

};
