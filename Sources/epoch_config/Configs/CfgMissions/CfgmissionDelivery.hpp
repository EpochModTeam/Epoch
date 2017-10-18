class prepForDelivery {
	author 					= "axeman";
	title 					= "Prep for Delivery";
	simpleTask 				= 0;
	items[] 				= {"ItemDocumentMission"};
	triggerDelay 			= 2;
	triggerintervall		= 8;
	markerType 				= 0;
	markerVisible			= 0;
	markerRadius 			= 0;
	markerText 				= "";
	initcall 				= "";
	cleanUpCall 			= "uiNameSpace setVariable ['axeStartTraders', nil]";
	dialogues[]				= {	// {{ARRAY1},{ARRAY2},... }
		{	// {"condition",{"Message1","Message2", ...}}
			"true",
			{"Pick up the Document to Start."}
		},
		{
			"!(""ItemDocumentMission"" in magazines player)",
			{"Come on Buddy, Pick it up !","It's right next to you on the floor, pick it up to start."}
		}
	};
	callevents[]			= {	// {{ARRAY1},{ARRAY2},... }
	};
	abandonTime 			= 240;
	failedCondition 		= "false";
	faileddialogues[] 		= {"I guess you have better things to do.","Try again later.","You didn't pick up the document. Misison Failed !"};
	completeCondition		= "('ItemDocumentMission' in magazines player)";
	completedialogues[] 	= {"That's great, let's get out of here.","Good, you have the document, let's move on.","Ok, well done. We can start now."};
	completedCALL 			= "uiNameSpace setVariable ['axeStartTraders',(player nearentities [['C_Man_1'],500]) apply {_x getVariable ['AI_SLOT',-1]} select {!(_x == -1)}]";
	reward[] 				= {};
	cleanUp 				= 0;
	nextTask[] 				= {"doDelivery"};

// Not used atm	
	taskLimit 				= 3;
	itemSpawn 				= 3;
	callEventBinTask 		= 0;
	diagSquelch 			= 30;
	abandonDist 			= 100;
};
class doDelivery {
	author 					= "axeman";
	title 					= "Do Delivery";
	simpleTask 				= 0;
	items[] 				= {};
	triggerDelay 			= 8;
	triggerintervall		= 8;
	markerType 				= 0;
	markerVisible			= 0;
	markerRadius 			= 0;
	markerText 				= "";
	initcall 				= "";
	cleanUpCall 			= "uiNameSpace setVariable ['axeStartTraders', nil]";
	dialogues[]				= {	// {{ARRAY1},{ARRAY2},... }
		{	// {"condition",{"Message1","Message2", ...}}
			"(""ItemDocumentMission"" in magazines player)",
			{"Ok, head off to another trader, you can't deliver to any nearby.","All set. Now take that document to another trader further away.","Take that message to another trader or trader city."}
		},
		{
			"!('ItemDocumentMission' in magazines player)",
			{"Don't leave that document anywhere.","If you lose that document you will fail the mission."}
		},
		{
			"(count (((player nearentities [['C_Man_1'],42]) apply {_x getvariable ['AI_SLOT',-1]}) select {!(_x == -1)}) > 0) && (count (((player nearentities [['C_Man_1'],42]) apply {_x getVariable ['AI_SLOT',-1]}) select {_x in (uiNameSpace getVariable ['axeStartTraders',[]])}) < 1)",
			{"Well done, you have a trader nearby, go see him","Looks like you found another trader, well done, deliver the message.","UAV has spotted another trader nearby, go deliver the message."}
		}
	};
	callevents[]			= {	// {{ARRAY1},{ARRAY2},... }
		{	// {"condition",{"Message1","Message2", ...},{"NextTask1","NextTask2", ...}}
			"(EPOCH_task_startTime + 480 < diag_tickTime) && (count (((player nearentities [['C_Man_1'],500]) apply {_x getVariable ['AI_SLOT',-1]}) select {_x in (uiNameSpace getVariable ['axeStartTraders',[]])}) > 0)",
			"[""Hey, what are you doing here ? Get on with your task !"", 5] call Epoch_message",
			{}
		}
	};
	abandonTime 			= 1800;
	failedCondition 		= "false";
	faileddialogues[] 		= {"Looks like you took too long buddy, Mission Over.","You need to be quicker next time, Mission Over !","Misison Failed - You took too long, better luck next time."};
	completeCondition		= "(count (((player nearentities [['C_Man_1'],6]) apply {_x getvariable ['AI_SLOT',-1]}) select {!(_x == -1)}) > 0) && (count (((player nearentities [['C_Man_1'],6]) apply {_x getVariable ['AI_SLOT',-1]}) select {_x in (uiNameSpace getVariable ['axeStartTraders',[]])}) < 1)";
	completedialogues[] 	= {"Hey there pal, it looks like you have something for me ?","Great Job there. Step into my office traveller.","You made it, time to take a look at that message."};
	completedCALL 			= "";
	reward[] 				= {};
	cleanUp 				= 0;
	nextTask[] 				= {"finishDelivery"};
};
class finishDelivery {
	author 					= "axeman";
	title 					= "Finish Delivery";
	simpleTask 				= 0;
	items[] 				= {};
	triggerDelay 			= 8;
	triggerintervall		= 8;
	markerType 				= 0;
	markerVisible			= 0;
	markerRadius 			= 0;
	markerText 				= "";
	initcall 				= "axeRndBadNews = floor random 100";
	cleanUpCall 			= "uiNameSpace setVariable ['axeStartTraders', nil];axeRndBadNews = nil";
	dialogues[]				= {	// {{ARRAY1},{ARRAY2},... }
		{	// {"condition",{"Message1","Message2", ...}}
			"axeRndBadNews > 5",
			{"That's interesting news. Thanks for bringing this.","Great news, you did well to bring this to me."}
		}
	};
	callevents[]			= {	// {{ARRAY1},{ARRAY2},... }
		{	// {"condition",{"Message1","Message2", ...},{"NextTask1","NextTask2", ...}}
			"(""ItemDocumentMission"" in magazines player)",
			"player removeMagazine ""ItemDocumentMission""",
			{}
		},
		{	// {"condition",{"Message1","Message2", ...},{"NextTask1","NextTask2", ...}}
			"axeRndBadNews < 6",
			"",
			{"deliveryMissionBadNews"}
		}
	};
	abandonTime 			= 240;
	failedCondition 		= "false";
	faileddialogues[] 		= {};
	completeCondition		= "diag_ticktime - EPOCH_task_startTime > 16 && axeRndBadNews > 5";
	completedialogues[] 	= {"Take your reward, you have earnt it","Here is your reward, you are a great courier.","Any time you need work, come and see me, great job."};
	completedCALL 			= "[objnull,""Pelican_EPOCH"",true,getposatl player] remoteExec [""EPOCH_serverLootObject"",2];";
	reward[] 				= {};
	cleanUp 				= 1;
	nextTask[] 				= {};
};
class deliveryMissionBadNews {
	author 					= "axeman";
	title 					= "Delivery Gone Bad";
	simpleTask 				= 0;
	items[] 				= {};
	triggerDelay 			= 0;
	triggerintervall		= 8;
	markerType 				= 0;
	markerVisible			= 0;
	markerRadius 			= 0;
	markerText 				= "";
	initcall 				= "[player,6] call EPOCH_callSapperMigration";
	cleanUpCall 			= "uiNameSpace setVariable ['axeStartTraders', nil]";
	dialogues[]				= {	// {{ARRAY1},{ARRAY2},... }
		{	// {"condition",{"Message1","Message2", ...}}
			"true",
			{"Oh my, that's terrible, why did you bring me this news ?","No no no, why would you do this to me, this is awful news."}
		}
	};
	callevents[]			= {	// {{ARRAY1},{ARRAY2},... }
	};
	abandonTime 			=240;
	failedCondition 		= "false";
	faileddialogues[] 		= {};
	completeCondition		= "diag_ticktime - EPOCH_task_startTime > 8";
	completedialogues[] 	= {"You are going to pay for that, get out of my sight","Nobody does that to me, go away.","I would run buddy, I am not pleased."};
	completedCALL 			= "";
	reward[] 				= {};
	cleanUp 				= 1;
	nextTask[] 				= {};
};
