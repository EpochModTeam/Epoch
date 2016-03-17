/*
	Author: Aaron Clark - EpochMod.com

    Contributors:

	Description:
	Request trash loot event

    Licence:
    Arma Public License Share Alike (APL-SA) - https://www.bistudio.com/community/licenses/arma-public-license-share-alike

    Github:
    https://github.com/EpochModTeam/Epoch/tree/master/Sources/epoch_code/compile/EPOCH_lootTrash.sqf
*/
private["_found", "_return", "_foundLocalAnimal", "_str", "_blood", "_foundTerminal", "_index"];

_return = false;
_config = 'CfgEpochClient' call EPOCH_returnConfig;
_configWorldInteractions = (_config >> "WorldInteractions");
_configWorldName = (_config >> worldname);

if (diag_tickTime - EPOCH_lastTrash > 2)  then {
	EPOCH_lastTrash = diag_tickTime;

	_destroyTrashObj = objNull;
	_lootAnimalObj = objNull;
	_bankTerminal = objNull;
	_trashType = 0;

	_objects = nearestObjects[player, [], 2];

	{
		_found = false;
		_foundTerminal = false;
		_foundLocalAnimal = false;
		if !(_x isKindOf "All") then {
			if (alive _x) then {
				_str = str(_x);
				_inputWorldTypes = ["bankTerminal"];
				_inputWorldTypes append getArray(_configWorldName >> "TrashClasses");
				_getWorldTypes = [_str, _inputWorldTypes] call EPOCH_worldObjectType;
				{
					_found = _getWorldTypes param [_inputWorldTypes find _x, false];
					if (_found) exitWith{ _trashType = _forEachIndex };
				} forEach getArray(_configWorldName >> "TrashClasses");
				_foundTerminal = _getWorldTypes param [_inputWorldTypes find "bankTerminal", false];
			};
		} else {
			if (alive _x) then {
				_foundTerminal = (getNumber(_configWorldInteractions >> (typeOf _x) >> "bankTerminal") == 1);
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
		if (_foundTerminal) exitWith{ _bankTerminal = _x };

	}forEach _objects;

	if (!isNull _lootAnimalObj) then {
		_bloodPos = getPosATL _lootAnimalObj;
		_blood = "BloodSplat" createVehicleLocal _bloodPos;
		_blood setPosATL _bloodPos;
		EPOCH_playerSoiled = (EPOCH_playerSoiled + 1) min 100;
		// send
		[_lootAnimalObj, player, Epoch_personalToken] remoteExec ["EPOCH_server_lootAnimal",2];
		_return = true;
		_dt = ["<t size='0.8' shadow='0' color='#99ffffff'>Object Looted</t>", 0, 1, 5, 2, 0, 1] spawn bis_fnc_dynamictext;
	};
	if (!isNull _destroyTrashObj) then {
		[_destroyTrashObj, _trashType, player, Epoch_personalToken] remoteExec ["EPOCH_server_destroyTrash",2];
		EPOCH_playerSoiled = (EPOCH_playerSoiled + 1) min 100;
		_return = true;
		_dt = ["<t size='0.8' shadow='0' color='#99ffffff'>Object Looted</t>", 0, 1, 5, 2, 0, 1] spawn bis_fnc_dynamictext;

		// Snake Den
		if (random 1 < 0.04) then {
			_animalPos = getposATL _destroyTrashObj;
			_randomAIClass = selectRandom ["Snake_random_EPOCH", "Snake2_random_EPOCH"];
			_animals = [];
			for "_i" from 1 to 2 step 1 do {
				_animal = createAgent[_randomAIClass, _animalPos, [], 0, "CAN_COLLIDE"];
				_animal setVariable["BIS_fnc_animalBehaviour_disable", true];
				_id = [_animal, true] execFSM "\x\addons\a3_epoch_code\System\Animal_brain.fsm";
				_animals pushBack _animal;
			};
			_animals remoteExec ["EPOCH_localCleanup",2];
		};
	};
	if (!isNull _bankTerminal) then {
		// make balance request
		if (isNil "EPOCH_bankTransferActive") then {
			[player, [], Epoch_personalToken] remoteExec ["EPOCH_server_storeCrypto",2];

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
