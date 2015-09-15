private["_found", "_return", "_foundLocalAnimal", "_str", "_blood", "_foundTerminal", "_index"];

_return = false;

if (isNil "EPOCH_trashLootList") then{
	_config = 'CfgEpochClient' call EPOCH_returnConfig;
	EPOCH_trashLootList = [];
	{
		EPOCH_trashLootList pushBack getArray(_config >> worldname >> _x);
	} forEach(getArray(_config >> worldname >> "TrashClasses"));
};
if (isNil "EPOCH_atmList") then{
	_config = 'CfgEpochClient' call EPOCH_returnConfig;
	EPOCH_atmList = getArray(_config >> worldname >> "ATM");
};

if (diag_tickTime - EPOCH_lastTrash > 2)  then {
	EPOCH_lastTrash = diag_tickTime;

	_destroyTrashObj = objNull;
	_lootAnimalObj = objNull;
	EPOCH_bankTerminal = objNull;
	_trashType = 0;

	_objects = nearestObjects[player, [], 2];

	{
		_found = false;
		_foundTerminal = false;
		_foundLocalAnimal = false;
		if !(_x isKindOf "All") then {
			if (alive _x) then {
				_str = str(_x);
				_findStart = _str find ": ";
				if (_findStart != -1) then {
					_p3dName = _str select[_findStart + 2, 999];
					{
						_found = _p3dName in _x;
						if (_found) exitWith{ _trashType = _forEachIndex };
					} forEach EPOCH_trashLootList;
					_foundTerminal = _p3dName in EPOCH_atmList;
				};
			};
		} else {
			if (alive _x) then {
				if ((typeOf _x) in["Land_PhoneBooth_02_F", "Land_PhoneBooth_01_F", "Land_Atm_01_F", "Land_Atm_02_F", "Land_Laptop_device_F"]) then {
					_foundTerminal = true
				};
				if (_x isKindOf "Snake_random_EPOCH") then {
					_foundLocalAnimal = true;
					if (random 1 < 0.1) then {
						EPOCH_playerToxicity = (EPOCH_playerToxicity + (random(100 - EPOCH_playerImmunity))) min 100;
					};
				};
			} else {
				if ((_x isKindOf "Animal_Base_F" && !(_x isKindOf "Dog_Base_F")) || (typeOf _x) in["Epoch_Sapper_F", "Epoch_SapperB_F", "Epoch_Cloak_F", "I_UAV_01_F"]) then {
					_foundLocalAnimal = true;
				};
			};
		};
		if (_found) exitWith{ _destroyTrashObj = _x };
		if (_foundLocalAnimal) exitWith{ _lootAnimalObj = _x };
		if (_foundTerminal) exitWith{ EPOCH_bankTerminal = _x };

	}forEach _objects;

	if (!isNull _lootAnimalObj) then {
		EPOCH_lootAnimal = [_lootAnimalObj, player, Epoch_personalToken];
		_bloodPos = getPosATL _lootAnimalObj;
		_blood = "BloodSplat" createVehicleLocal _bloodPos;
		_blood setPosATL _bloodPos;
		EPOCH_playerSoiled = (EPOCH_playerSoiled + 1) min 100;
		publicVariableServer "EPOCH_lootAnimal";
		_return = true;
		_dt = ["<t size='0.8' shadow='0' color='#99ffffff'>Object Looted</t>", 0, 1, 5, 2, 0, 1] spawn bis_fnc_dynamictext;
	};
	if (!isNull _destroyTrashObj) then {

		EPOCH_destroyTrash = [_destroyTrashObj, _trashType, player, Epoch_personalToken];
		// hint str EPOCH_destroyTrash;
		publicVariableServer "EPOCH_destroyTrash";
		EPOCH_playerSoiled = (EPOCH_playerSoiled + 1) min 100;
		_return = true;
		_dt = ["<t size='0.8' shadow='0' color='#99ffffff'>Object Looted</t>", 0, 1, 5, 2, 0, 1] spawn bis_fnc_dynamictext;

		// Snake Den
		if (random 1 < 0.04) then {
			_animalPos = getposATL _destroyTrashObj;
			_randomAIClass = ["Snake_random_EPOCH", "Snake2_random_EPOCH"];
			_randomIndex = floor(random(count _randomAIClass));
			_randomAIClass = _randomAIClass select _randomIndex;
			_animals = [];
			for "_i" from 1 to 2 step 1 do {
				_animal = createAgent[_randomAIClass, _animalPos, [], 0, "CAN_COLLIDE"];
				_animal setVariable["BIS_fnc_animalBehaviour_disable", true];
				_id = [_animal, true] execFSM "\x\addons\a3_epoch_code\System\Animal_brain.fsm";
				_animals pushBack _animal;
			};
			EPOCH_TEMPOBJ_PVS = _animals;
			publicVariableServer "EPOCH_TEMPOBJ_PVS";
		};
	};
	if (!isNull EPOCH_bankTerminal) then {
		// make balance request
		if (isNil "EPOCH_bankTransferActive") then {
			EPOCH_storeCrypto_PVS = [player, [], Epoch_personalToken];
			publicVariableServer "EPOCH_storeCrypto_PVS";
			closeDialog 0;
			createDialog "InteractBank";

			lbClear 21500;
			{
				_index = lbAdd[21500, name _x];
				lbSetData[21500, _index, netId _x];
			} forEach(playableUnits - [player]);
		};
		_return = true;
	};
};
_return
