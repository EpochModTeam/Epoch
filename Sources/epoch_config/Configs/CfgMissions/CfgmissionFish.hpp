class StartFishMission {
	author 					= "He-Man";
	title 					= "Start Fish Mission";
	simpleTask 				= 0;
	items[] 				= {};
	triggerDelay 			= 2;
	triggerintervall		= 5;
	markerType 				= 0;
	markerVisible			= 0;
	markerRadius 			= 0;
	markerText 				= "";
	initcall 				= "uiNameSpace setVariable ['axeStartTraders',(player nearentities [[""C_Man_1""],20]) apply {_x getVariable [""AI_SLOT"",-1]}]; EPOCH_Mission_StartPos = getpos player";
	cleanUpCall 			= "uiNameSpace setVariable ['axeStartTraders', nil];EPOCH_Mission_StartPos = nil";
	dialogues[]				= {	// {{ARRAY1},{ARRAY2},... }
		{	// {"condition",{"Message1","Message2", ...}}
			"true",
			{"I really need a fresh Fish. Can you fish me one?","Go to the Water and catch me a fresh Fish. I will reward you"}
		},
		{	// {"condition",{"Message1","Message2", ...}}
			"true",
			{"But don't bring me a Fish from this region. Go a bit away","The Fishes from this region are boring. Please go a bit farther"}
		},
		{
			"!(""MeleeRod"" in weapons player)",
			{"Hey, you need your Fishin Rod for fishing! Don't throw it away"}
		},
		{
			"(surfaceiswater (getpos player) || (surfaceiswater (player modelToWorld[0, 5 + (random 5), 0]))) && player distance EPOCH_Mission_StartPos < 1000",
			{"The Fishes in this region taste awful. Go to another Spot.","Don't bring me a fish frome here! They taste terrible..."}
		},
		{
			"(surfaceiswater (getpos player) || (surfaceiswater (player modelToWorld[0, 5 + (random 5), 0]))) && player distance EPOCH_Mission_StartPos > 1000",
			{"Oh nice, here is an excellent spot for fishing...","Use your Fishing-Rod to catch me a fresh Fish"}
		}
	};
	callevents[]			= {	// {{ARRAY1},{ARRAY2},... }
	};
	abandonTime 			= 1200;
	failedCondition 		= "!alive player";
	faileddialogues[] 		= {"I guess you have better things to do. - Mission Failed","Mission Failed - Try again later."};
	completeCondition		= "player distance (missionNamespace getVariable [""EPOCH_myBobber"", objNull]) < 40 && player distance EPOCH_Mission_StartPos > 900";
	completedialogues[] 	= {"Okay, now catch a Fish","Let's wait now..."};
	completedCALL 			= "";
	reward[] 				= {};
	cleanUp 				= 0;
	nextTask[] 				= {"CatchFish"};

// Not used atm	
	taskLimit 				= 3;
	itemSpawn 				= 3;
	callEventBinTask 		= 0;
	diagSquelch 			= 30;
	abandonDist 			= 100;
};
class CatchFish {
	author 					= "He-Man";
	title 					= "Catch the Fish";
	simpleTask 				= 0;
	items[] 				= {};
	triggerDelay 			= 8;
	triggerintervall		= 5;
	markerType 				= 0;
	markerVisible			= 0;
	markerRadius 			= 0;
	markerText 				= "";
	initcall 				= "";
	cleanUpCall 			= "uiNameSpace setVariable ['axeStartTraders', nil];EPOCH_Mission_StartPos = nil";
	dialogues[]				= {	// {{ARRAY1},{ARRAY2},... }
	};
	callevents[]			= {	// {{ARRAY1},{ARRAY2},... }
	};
	abandonTime 			= 600;
	failedCondition 		= "!alive player";
	faileddialogues[] 		= {"I guess you have better things to do. - Mission Failed","Mission Failed - You took to long."};
	completeCondition		= "{_x in magazines player} count ([""CfgEpochClient"", ""fishLoots"", [""ItemTuna"",""ItemSeaBass"",""ItemSeaBass"",""ItemSeaBass"",""ItemTrout"",""ItemTrout"",""ItemTrout"",""ItemTrout"",""ItemTrout"",""ItemTrout""]] call EPOCH_fnc_returnConfigEntryV2) > 0";
	completedialogues[] 	= {"YEAH! You got one. Bring it to me","Wow, bring the Fish to me!"};
	completedCALL 			= "";
	reward[] 				= {};
	cleanUp 				= 0;
	nextTask[] 				= {"BringTheFish"};
};
class BringTheFish {
	author 					= "He-Man";
	title 					= "Bring the Fish";
	simpleTask 				= 0;
	items[] 				= {};
	triggerDelay 			= 8;
	triggerintervall		= 8;
	markerType 				= 0;
	markerVisible			= 0;
	markerRadius 			= 0;
	markerText 				= "";
	initcall 				= "";
	cleanUpCall 			= "uiNameSpace setVariable ['axeStartTraders', nil];EPOCH_Mission_StartPos = nil";
	dialogues[]				= {	// {{ARRAY1},{ARRAY2},... }
		{	// {"condition",{"Message1","Message2", ...}}
			"diag_ticktime - EPOCH_task_startTime > 180",
			{"Hurry up, I am really hungry.","Hey, where is my Fish? Bring it to me!","Why does it take so long to bring me a Fish?"}
		}
	};
	callevents[]			= {	// {{ARRAY1},{ARRAY2},... }
	};
	abandonTime 			= 1200;
	failedCondition 		= "!alive player";
	faileddialogues[] 		= {"I guess you have better things to do. - Mission Failed","Mission Failed - You took to long."};
	completeCondition		= "((player nearentities [[""C_Man_1""],20]) apply {_x getVariable [""AI_SLOT"",-1]} isEqualTo (uiNameSpace getVariable [""axeStartTraders"",[]])) && {_x in magazines player} count ([""CfgEpochClient"", ""fishLoots"", [""ItemTuna"",""ItemSeaBass"",""ItemSeaBass"",""ItemSeaBass"",""ItemTrout"",""ItemTrout"",""ItemTrout"",""ItemTrout"",""ItemTrout"",""ItemTrout""]] call EPOCH_fnc_returnConfigEntryV2) > 0";
	completedialogues[] 	= {"Hey, you bring me my Fish? - THANKS!!!","Great Job there. Step into my office traveller.","You made it, thanks for bringing me the Fish."};
	completedCALL 			= "{if (_x in magazines player) exitwith {player removeMagazine _x}} foreach ([""CfgEpochClient"", ""fishLoots"", [""ItemTuna"",""ItemSeaBass"",""ItemSeaBass"",""ItemSeaBass"",""ItemTrout"",""ItemTrout"",""ItemTrout"",""ItemTrout"",""ItemTrout"",""ItemTrout""]] call EPOCH_fnc_returnConfigEntryV2)";
	reward[] 				= {};
	cleanUp 				= 0;
	nextTask[] 				= {"FinishFishMission"};
};
class FinishFishMission {
	author 					= "He-Man";
	title 					= "Finish Fish Mission";
	simpleTask 				= 0;
	items[] 				= {};
	triggerDelay 			= 8;
	triggerintervall		= 8;
	markerType 				= 0;
	markerVisible			= 0;
	markerRadius 			= 0;
	markerText 				= "";
	initcall 				= "";
	cleanUpCall 			= "uiNameSpace setVariable ['axeStartTraders', nil];EPOCH_Mission_StartPos = nil";
	dialogues[]				= {	// {{ARRAY1},{ARRAY2},... }
	};
	callevents[]			= {	// {{ARRAY1},{ARRAY2},... }
	};
	abandonTime 			= 240;
	failedCondition 		= "false";
	faileddialogues[] 		= {};
	completeCondition		= "true";
	completedialogues[] 	= {"Take your reward, you have earnt it","Here is your reward, you are a great fisher man.","Any time you need work, come and see me, great job."};
	completedCALL 			= "[objnull,""Mission_Fishing_Payout"",true,getposatl player] remoteExec [""EPOCH_serverLootObject"",2];";
	reward[] 				= {};
	cleanUp 				= 1;
	nextTask[] 				= {};
};
