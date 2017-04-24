class prepForMonsterEscort {
	author 					= "He-Man";
	title 					= "Prep for Monster Escort";
	simpleTask 				= 0;
	items[] 				= {};
	triggerDelay 			= 2;
	triggerintervall		= 8;
	markerType 				= 0;
	markerVisible			= 0;
	markerRadius 			= 0;
	markerText 				= "";
	initcall 				= "EPOCH_Monster = objnull";
	cleanUpCall 			= "uiNameSpace setVariable ['axeStartTraders', nil]";
	dialogues[]				= {	// {{ARRAY1},{ARRAY2},... }
		{	// {"condition",{"Message1","Message2", ...}}
			"true",
			{"Hey, thanks for helping me to take my Monster to a friend"}
		},
		{
			"true",
			{"I will call my monster. Bring him to another Trader"}
		}
	};
	callevents[]			= {	// {{ARRAY1},{ARRAY2},... }
		{	// {"condition",{"Message1","Message2", ...},{"NextTask1","NextTask2", ...}}
			"true",
			"uiNameSpace setVariable ['axeStartTraders',(player nearentities [[""C_Man_1""],500]) apply {_x getVariable [""AI_SLOT"",-1]}]",
			{}
		},
		{	// {"condition",{"Message1","Message2", ...},{"NextTask1","NextTask2", ...}}
			"true",
			"_animalPos = [getposatl player, 150, 250, 5, 0, 2000, 0] call BIS_fnc_findSafePos;_randomAIClass = ""Construct_F"";_animal = createAgent[_randomAIClass, _animalPos, [], 5, ""NONE""];EPOCH_Monster = _animal;[EPOCH_Monster] remoteExec [""EPOCH_localCleanup"",2]",
			{}
		}
	};
	abandonTime 			= 240;
	failedCondition 		= "false";
	faileddialogues[] 		= {"I guess you have better things to do.","Try again later.","You didn't pick up the document. Misison Failed !"};
	completeCondition		= "!isnull EPOCH_Monster";
	completedialogues[] 	= {};
	completedCALL 			= "[] spawn {_pos = getpos player;_stay = false;while {!isnull EPOCH_Monster && alive EPOCH_Monster && alive player} do {if (EPOCH_Monster distance2d player > 35) then {_stay = false;_pos = getposatl player;}else {if (!_stay) then {_pos = getposatl EPOCH_Monster;_stay = true;};};EPOCH_Monster moveto _pos;_time = diag_ticktime;uisleep 3;waituntil {diag_ticktime - _time > 15 || EPOCH_Monster distance _pos < 25 || isnull EPOCH_Monster};};};";
	reward[] 				= {};
	cleanUp 				= 0;
	nextTask[] 				= {"EscortMonster"};

// Not used atm	
	taskLimit 				= 3;
	itemSpawn 				= 3;
	callEventBinTask 		= 0;
	diagSquelch 			= 30;
	abandonDist 			= 100;
};
class EscortMonster {
	author 					= "He-Man";
	title 					= "Escort Monster";
	simpleTask 				= 0;
	items[] 				= {};
	triggerDelay 			= 5;
	triggerintervall		= 8;
	markerType 				= 0;
	markerVisible			= 0;
	markerRadius 			= 0;
	markerText 				= "";
	initcall 				= "";
	cleanUpCall 			= "uiNameSpace setVariable ['axeStartTraders', nil]; deletevehicle EPOCH_Monster";
	dialogues[]				= {	// {{ARRAY1},{ARRAY2},... }
		{	// {"condition",{"Message1","Message2", ...}}
			"true",
			{"That's great, look for the Monster outside.","Good, now search my Monster outside","Ok, well done. We can start now."}
		},
		{
			"true",
			{"Ok, head off to another trader, you can't deliver to any nearby.","All set. Now take the Monster to another trader further away.","Take that Monster to another trader or trader city."}
		},
		{
			"EPOCH_task_startTime + 60 < diag_ticktime",
			{"Sorrz, he is an old Man and not very fast...","My Monster is very old a bit lazy"}
		},
		{
			"EPOCH_task_startTime + 120 < diag_ticktime && EPOCH_Monster distance player > 350",
			{"Don't go to far away or you loose the Monster","Hey, wait for my Monster!"}
		},
		{
			"EPOCH_Monster distance player < 20",
			{"Go forward, my Monster will follow you!","Hurry up a bit. My Monster is hungry..."}
		},
		{
			"(count (player nearentities [[""C_Man_1""],42]) > 0) && (count (((player nearentities [[""C_Man_1""],42]) apply {_x getVariable [""AI_SLOT"",-1]}) select {_x in (uiNameSpace getVariable [""axeStartTraders"",[]])}) < 1)",
			{"Well done, you have a trader nearby, go see him","Looks like you found another trader, well done, deliver the Monster.","UAV has spotted another trader nearby, go deliver the Monster."}
		},
		{
			"(EPOCH_task_startTime + 480 < diag_tickTime) && ((player nearentities [[""C_Man_1""],500]) apply {_x getVariable [""AI_SLOT"",-1]} isEqualTo (uiNameSpace getVariable [""axeStartTraders"",[]]))",
			{"Hey, what are you doing here ? Get on with your task!"}
		}
	};
	callevents[]			= {	// {{ARRAY1},{ARRAY2},... }
	};
	abandonTime 			= 2000;
	failedCondition 		= "!alive EPOCH_Monster || !alive player || EPOCH_Monster distance player > 500";
	faileddialogues[] 		= {"Oh no, you lost my Monster - Mission Failed","My Monster ist gone, Mission Over!"};
	completeCondition		= "player distance EPOCH_Monster < 50 && (count (player nearentities [[""C_Man_1""],20]) > 0) && (count (((player nearentities [[""C_Man_1""],20]) apply {_x getVariable [""AI_SLOT"",-1]}) select {_x in (uiNameSpace getVariable [""axeStartTraders"",[]])}) < 1)";
	completedialogues[] 	= {"Hey, you bring me my friends Monster?","Great Job there. Step into my office traveller.","You made it, thanks for bringing me the Monster."};
	completedCALL 			= "";
	reward[] 				= {};
	cleanUp 				= 0;
	nextTask[] 				= {"finishMonsterEscort"};
};
class finishMonsterEscort {
	author 					= "He-Man";
	title 					= "Finish Monster Escort";
	simpleTask 				= 0;
	items[] 				= {};
	triggerDelay 			= 8;
	triggerintervall		= 8;
	markerType 				= 0;
	markerVisible			= 0;
	markerRadius 			= 0;
	markerText 				= "";
	initcall 				= "";
	cleanUpCall 			= "uiNameSpace setVariable ['axeStartTraders', nil]; deletevehicle EPOCH_Monster";
	dialogues[]				= {	// {{ARRAY1},{ARRAY2},... }
	};
	callevents[]			= {	// {{ARRAY1},{ARRAY2},... }
	};
	abandonTime 			= 240;
	failedCondition 		= "false";
	faileddialogues[] 		= {};
	completeCondition		= "true";
	completedialogues[] 	= {"Take your reward, you have earnt it","Here is your reward, you are a great courier.","Any time you need work, come and see me, great job."};
	completedCALL 			= "[objnull,""Mission_Monster_Payout"",true,getposatl player] remoteExec [""EPOCH_serverLootObject"",2];";
	reward[] 				= {};
	cleanUp 				= 1;
	nextTask[] 				= {};
};
