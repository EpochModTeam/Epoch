/*
	Author: Aaron Clark - EpochMod.com

    Contributors:

	Description:
    Uses Epoch server extension to perform various functions like: kick, ban, shutdown, message, unlock/lock

    Licence:
    Arma Public License Share Alike (APL-SA) - https://www.bistudio.com/community/licenses/arma-public-license-share-alike

    Github:
    https://github.com/EpochModTeam/Epoch/tree/master/Sources/epoch_server/compile/epoch_server/EPOCH_serverLootObject.sqf
*/
private["_randomItemArray", "_quan", "_randomLootClass", "_randomItem", "_lootPaid", "_mags", "_lootItemWeightedArray", "_lootItemArray", "_weightedItemArray", "_exit", "_maxPayout", "_lootTable", "_lootTableArray", "_weightedArray"];
params ["_object","_type"];
_randomizeMagazineAmmoCount = ["CfgEpochClient", "randomizeMagazineAmmoCount", true] call EPOCH_fnc_returnConfigEntryV2;
if !(isNull _object) then{
	_lootTable = [_type, "CfgMainTable", "tables"] call EPOCH_weightedArray;
	_lootTable params ["_lootTableArray","_weightedArray"];
	if !(_lootTableArray isEqualTo []) then {
		_loots = [];
		_config = configFile >> "CfgMainTable" >> _type;
		_minLoot = getNumber(_config >> "lootMin");
		_maxLoot = getNumber(_config >> "lootMax");
		_maxPayout = ((random(_maxLoot) * EPOCH_lootMultiplier) min _maxLoot) max _minLoot;
		for "_k" from 1 to _maxPayout do {
			_loots pushBack (_lootTableArray select(selectRandom _weightedArray));
		};

		{
			_lootItemWeightedArray = [_x, "CfgLootTable", "items"] call EPOCH_weightedArray;
			_lootItemArray = _lootItemWeightedArray select 0;
			if !(_lootItemArray isEqualTo[]) then {
				_weightedItemArray = _lootItemWeightedArray select 1;
				_randomItemArray = _lootItemArray select (selectRandom _weightedItemArray);
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
								_randomItemArray = _lootItemArray select(selectRandom _weightedItemArray);
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
			};
		} forEach _loots;
	};

};
