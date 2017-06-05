/*
	Author: Aaron Clark - EpochMod.com

    Contributors:

	Description:
	Request trash loot event

    Licence:
    Arma Public License Share Alike (APL-SA) - https://www.bistudio.com/community/licenses/arma-public-license-share-alike

    Github:
    https://github.com/EpochModTeam/Epoch/tree/release/Sources/epoch_code/compile/EPOCH_lootTrash.sqf
*/
//[[[cog import generate_private_arrays ]]]
private ["_animal","_animalPos","_animals","_bankTerminal","_blood","_bloodPos","_cfgItemInteractions","_cfgObjectInteractions","_config","_configWorldName","_destroyTrashObj","_found","_foundLootObject","_foundObjConfig","_foundObjType","_foundTerminal","_getWorldTypes","_id","_index","_inputWorldTypes","_interactAttributes","_lootAnimalObj","_objects","_output","_randomAIClass","_return","_trashClasses","_trashType"];
//[[[end]]]
_return = false;
if (diag_tickTime - EPOCH_lastTrash > 2)  then {
	EPOCH_lastTrash = diag_tickTime;

	_config = 'CfgEpochClient' call EPOCH_returnConfig;

    _interactAttributes = [];
	_cfgObjectInteractions = 'CfgObjectInteractions' call EPOCH_returnConfig;
	_inputWorldTypes = ["bankTerminal"];
    _trashClasses = getArray(_config >> worldname >> "TrashClasses");
	_inputWorldTypes append _trashClasses;

	_destroyTrashObj = objNull;
	_lootAnimalObj = objNull;
	_bankTerminal = objNull;
	_trashType = 0;
	_objects = nearestObjects[player, [], 2];
	{
		_found = false;
		_foundTerminal = false;
		_foundLootObject = false;

        _foundObjType = typeOf _x;
        _foundObjConfig = (_cfgObjectInteractions >> _foundObjType);

		if (alive _x) then {
			_getWorldTypes = [_x, _inputWorldTypes] call EPOCH_worldObjectType;
			{
				_found = _getWorldTypes param [_inputWorldTypes find _x, false];
				if (_found) exitWith{ _trashType = _forEachIndex };
			} forEach _trashClasses;
			_foundTerminal = _getWorldTypes param [_inputWorldTypes find "bankTerminal", false];
            _foundLootObject = ((getNumber(_foundObjConfig >> "interactMode") == 3) && (getNumber (_foundObjConfig >> "aliveState") == 0));
        } else {
			_foundLootObject = (getNumber(_foundObjConfig >> "interactMode") == 3);
        };

		if (_found) exitWith{ _destroyTrashObj = _x };
		if (_foundLootObject) exitWith{ _lootAnimalObj = _x };
		if (_foundTerminal) exitWith{ _bankTerminal = _x };

	}forEach _objects;

	if (!isNull _lootAnimalObj) then {

		_cfgItemInteractions = (_cfgObjectInteractions >> (typeOf _lootAnimalObj));
		_interactAttributes = getArray(_cfgItemInteractions >> "interactAttributes");

		_bloodPos = getPosATL _lootAnimalObj;
		_blood = "BloodSplat" createVehicleLocal _bloodPos;
		_blood setPosATL _bloodPos;

		// send
		[_lootAnimalObj, player, Epoch_personalToken] remoteExec ["EPOCH_server_lootAnimal",2];
		_return = true;
	};
	if (!isNull _destroyTrashObj) then {
		[_destroyTrashObj, _trashType, player, Epoch_personalToken] remoteExec ["EPOCH_server_destroyTrash",2];
		_interactAttributes = [["Soiled",1]];
		_return = true;
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
			} forEach(allPlayers - [player]);
		};
		_return = true;
	};

	{
		_output = _x call EPOCH_giveAttributes;
		if (_output != "") then {
			[_output, 5] call Epoch_message;
		};
	} foreach _interactAttributes;
};
_return
