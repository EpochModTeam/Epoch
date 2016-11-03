/*
	Author: Aaron Clark - EpochMod.com

    Contributors:

	Description:
	Creates animals with custom Epoch fsm AI "brain"

    Licence:
    Arma Public License Share Alike (APL-SA) - https://www.bistudio.com/community/licenses/arma-public-license-share-alike

    Github:
    https://github.com/EpochModTeam/Epoch/tree/release/Sources/epoch_code/compile/environment/EPOCH_client_loadAnimalBrain.sqf

    Example:
    call EPOCH_client_loadAnimalBrain;

    Parameter(s):
		None

	Returns:
	NOTHING
*/
//[[[cog import generate_private_arrays ]]]
private ["_animal","_animalAiTables","_animalPos","_id","_playerPos","_randomAIClass","_tryAnimalPos"];
//[[[end]]]

if (count(player nearEntities["Animal_Base_F", 200]) >= 1) exitWith{};

_animalAiTables = ["CfgEpochClient", "animalAiTables", ["Sheep_random_EPOCH", "Sheep_random_EPOCH", "Goat_random_EPOCH", "Goat_random_EPOCH", "Goat_random_EPOCH", ["Cock_random_EPOCH", "Hen_random_EPOCH"], ["Cock_random_EPOCH", "Hen_random_EPOCH"], "Rabbit_EPOCH", "Rabbit_EPOCH", "Rabbit_EPOCH", "Snake_random_EPOCH", "Snake2_random_EPOCH", ["Fin_random_EPOCH", "Alsatian_Random_EPOCH"] ] ] call EPOCH_fnc_returnConfigEntryV2;

_randomAIClass = selectRandom _animalAiTables;
_animalPos = nil;
_playerPos = position player;

if (_randomAIClass isEqualType []) then {
	_randomAIClass = selectRandom _randomAIClass;
};

for "_i" from 1 to 3 step 1 do {
	_tryAnimalPos = player getPos [floor(random 350) + 50, floor(random 360)];
	if!(surfaceIsWater _tryAnimalPos) exitWith {
		_animalPos = _tryAnimalPos;
	};
};

if!(isNil "_animalPos") then {
	_animal = createAgent[_randomAIClass, _animalPos, [], 5, "NONE"];
	_animal setVariable["BIS_fnc_animalBehaviour_disable", true];

	// send to server
	[_animal] remoteExec ["EPOCH_localCleanup",2];

	{
		_animal disableAI _x;
	}forEach ["TARGET","AUTOTARGET","FSM"];

	if (_randomAIClass in ["Fin_random_EPOCH", "Alsatian_Random_EPOCH"]) then {
		_id = [_animal] execFSM "\x\addons\a3_epoch_code\System\Dog_Brain.fsm";
	}else{
		_id = [_animal, _randomAIClass in ["Snake_random_EPOCH","Snake2_random_EPOCH"]] execFSM "\x\addons\a3_epoch_code\System\Animal_brain.fsm";
	};
};
