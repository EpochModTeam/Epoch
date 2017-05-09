/*
	Author: Aaron Clark - EpochMod.com

    Contributors:

	Description:
    Uses Epoch server extension to perform various functions like: kick, ban, shutdown, message, unlock/lock

    Licence:
    Arma Public License Share Alike (APL-SA) - https://www.bistudio.com/community/licenses/arma-public-license-share-alike

    Github:
    https://github.com/EpochModTeam/Epoch/tree/release/Sources/epoch_server/compile/epoch_server/EPOCH_serverLootObject.sqf
*/
//[[[cog import generate_private_arrays ]]]
private ["_config","_debug","_exit","_loop","_lootItemArray","_lootItemWeightedArray","_lootTable","_lootTableClass","_lootTableIndex","_loots","_magazineSize","_mags","_maxLoot","_maxPayout","_minLoot","_pricingConfig","_quan","_randomItem","_randomItemArray","_randomizeMagazineAmmoCount","_weightedItemArray"];
//[[[end]]]
params ["_object","_type",["_forceSpawn",false],["_pos",[]] ];
_debug = true;
_pricingConfig = 'CfgPricing' call EPOCH_returnConfig;

_lootTableIndex = if (EPOCH_modCUPVehiclesEnabled) then {if (EPOCH_mod_madArma_Enabled) then {3} else {1}} else {if (EPOCH_mod_madArma_Enabled) then {2} else {0}};
_lootTableClass = ["CfgLootTable","CfgLootTable_CUP","CfgLootTable_MAD","CfgLootTable_MADCUP"] select _lootTableIndex;
if !(EPOCH_forcedLootSpawnTable isEqualTo "") then {
    _lootTableClass = EPOCH_forcedLootSpawnTable;
};
_randomizeMagazineAmmoCount = ["CfgEpochClient", "randomizeMagazineAmmoCount", true] call EPOCH_fnc_returnConfigEntryV2;
if (isnull _object && !(_pos isequalto [])) then {
	_object = createVehicle ["groundWeaponHolder",_pos,[],0,"CAN_COLLIDE"];
};
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
			_lootItemWeightedArray = [_x, _lootTableClass, "items"] call EPOCH_weightedArray;
			_lootItemArray = _lootItemWeightedArray select 0;
			if !(_lootItemArray isEqualTo[]) then {
				_weightedItemArray = _lootItemWeightedArray select 1;
				_randomItemArray = _lootItemArray select (selectRandom _weightedItemArray);
				_randomItem = _randomItemArray select 0;
				_type = _randomItemArray select 1;
				_quan = 1;
				_loop = true;
				_exit = false;
				while {_loop} do {
					switch _type do {
						case "item": {
							if (isClass (_pricingConfig >> _randomItem) || _forceSpawn) then {
								_object additemCargoGlobal [_randomItem, _quan];
							} else {
								if (_debug) then {diag_log format["DEBUG: suppress spawn of %1 does not have price.",_randomItem]};
							};
							_loop = false;
						};
						case "magazine": {
							if (isClass (_pricingConfig >> _randomItem) || _forceSpawn) then {
								if (_randomizeMagazineAmmoCount) then {
									// spawn a single Magazine with a random ammo count
									_magazineSize = getNumber (configFile >> "CfgMagazines" >> _randomItem >> "count");
									_object addMagazineAmmoCargo[_randomItem, _quan, ceil(random(_magazineSize))];
								} else {
									// spawn a single full Magazine
									_object addMagazineCargoGlobal [_randomItem, _quan];
								};
							} else {
								if (_debug) then {diag_log format["DEBUG: suppress spawn of %1 does not have price.",_randomItem]};
							};
							_loop = false;
						};
						case "backpack": {
							if (isClass (_pricingConfig >> _randomItem) || _forceSpawn) then {
								_object addBackpackCargoGlobal [_randomItem, _quan];
							} else {
								if (_debug) then {diag_log format["DEBUG: suppress spawn of %1 does not have price.",_randomItem]};
							};
							_loop = false;
						};
						case "weapon": {
							if (isClass (_pricingConfig >> _randomItem) || _forceSpawn) then {
								_object addWeaponCargoGlobal [_randomItem, _quan];
								// only spawn mags that have prices
								_mags = getArray (configFile >> "CfgWeapons" >> _randomItem >> "magazines") select {isClass (_pricingConfig >> _x)};
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
							} else {
								if (_debug) then {diag_log format["DEBUG: suppress spawn of %1 does not have price.",_randomItem]};
							};
							_loop = false;
						};
						case "CfgLootTable": {
							// go down the rabit hole
							_lootItemWeightedArray = [_randomItem, _lootTableClass, "items"] call EPOCH_weightedArray;
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
					if (_exit) exitWith{if (_debug) then {diag_log "DEBUG: exit from spawn with default state."}};
				};
			};
		} forEach _loots;
	};
};
