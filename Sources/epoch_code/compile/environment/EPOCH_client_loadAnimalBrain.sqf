private["_fightOrFlight", "_id", "_animal", "_tryAnimalPos", "_animalPos", "_randomIndex", "_randomAIClass", "_aiTables", "_plyrPos"];

if (count(player nearEntities["Animal_Base_F", 200]) >= 1) exitWith{};

_animalAiTables = ["Sheep_random_EPOCH", "Sheep_random_EPOCH", "Goat_random_EPOCH", "Goat_random_EPOCH", "Goat_random_EPOCH", ["Cock_random_EPOCH", "Hen_random_EPOCH"], ["Cock_random_EPOCH", "Hen_random_EPOCH"], "Rabbit_EPOCH", "Rabbit_EPOCH", "Rabbit_EPOCH", "Snake_random_EPOCH", "Snake2_random_EPOCH", ["Fin_random_EPOCH", "Alsatian_Random_EPOCH"]];
_randomIndex = floor(random(count _animalAiTables));
_randomAIClass = _animalAiTables select _randomIndex;
_animalPos = nil;
_plyrPos = position player;

if (typeName _randomAIClass == "ARRAY") then {
	_randomIndex = floor(random(count _randomAIClass));
	_randomAIClass = _randomAIClass select _randomIndex;
};

for "_i" from 1 to 3 step 1 do {
	_tryAnimalPos = [_plyrPos, floor(random 350) + 50, floor(random 360)] call BIS_fnc_relPos;
	if!(surfaceIsWater _tryAnimalPos) exitWith {
		_animalPos = _tryAnimalPos;
	};
};

if!(isNil "_animalPos") then {
	// diag_log format["DEBUG: Spawning animal at %1.",_animalPos];
	_animal = createAgent[_randomAIClass, _animalPos, [], 5, "NONE"];
	_animal setVariable["BIS_fnc_animalBehaviour_disable", true];

	// diag_log format["DEBUG: spawned %1", _randomAIClass];

	EPOCH_TEMPOBJ_PVS = _animal;
	publicVariableServer "EPOCH_TEMPOBJ_PVS";

	{
		_animal disableAI _x;
	}forEach ["TARGET","AUTOTARGET","FSM"];

	if (_randomAIClass in ["Fin_random_EPOCH", "Alsatian_Random_EPOCH"]) then {
			_id = [_animal] execFSM "\x\addons\a3_epoch_code\System\Dog_Brain.fsm";
	}else{
			_id = [_animal, _randomAIClass in ["Snake_random_EPOCH","Snake2_random_EPOCH"]] execFSM "\x\addons\a3_epoch_code\System\Animal_brain.fsm";
	};
};
