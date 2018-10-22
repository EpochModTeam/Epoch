class DocCheckAccept{
	author 					= "He-Man";
	title 					= "Document check accept";
	simpleTask 				= 0;
	items[] 				= {};
	triggerDelay 			= 1;
	triggerintervall		= 10;
	markerType 				= 0;
	markerVisible			= 0;
	markerRadius 			= 0;
	markerText 				= "";
	initcall 				= "";
	cleanUpCall 			= "";
	dialogues[]				= {};
	callevents[]			= {};
	abandonTime 			= 240;
	failedCondition 		= "missionNameSpace getVariable ['InSafeZone',false]";
	faileddialogues[] 		= {"Mission not allowed in Safe Zone"};
	completeCondition		= "true";
	completedialogues[] 	= {};
	completedCALL 			= "";
	reward[] 				= {};
	cleanUp 				= 0;
	nextTask[] 				= {"DocCheckStart"};
};
class DocCheckStart{
	author 					= "He-Man";
	title 					= "Document check start";
	simpleTask 				= 0;
	items[] 				= {};
	triggerDelay 			= 1;
	triggerintervall		= 8;
	markerType 				= 0;
	markerVisible			= 0;
	markerRadius 			= 0;
	markerText 				= "";
	initcall 				= "EPOCH_Mission_StartPos = getpos player";
	cleanUpCall 			= "EPOCH_Mission_StartPos = nil;";
	dialogues[]				= {
		{
			"'ItemDocument' in magazines player",
			{"You have an unknown Document for me? Let's have a look...","Lets try to find out what kind of document you have...","Let's try to identify your unknown document..."}
		},
		{
			"'ItemDocument' in magazines player",
			{"Hmm, it's hard to identify it... give me some seconds","Oh, I think it is... hmm... no... wait..."}
		}
	};
	callevents[]			= {
		{
			"player distance EPOCH_Mission_StartPos > 5",
			"[selectrandom ['Abort - Come back or I can not check your document!','Abort - Hey, I need your document. Come back!','Abort - If you run away, I can not check your document!'],5,[[0,0,0,0.5],[1,0.5,0,1]]] call epoch_message",
			{"DocCheckAbord"}
		},
		{
			"!('ItemDocument' in magazines player)",
			"[selectrandom ['Come back later with an unknown document.','You have no unknown document. Find one and come back later.','Without an unknown document, I have nothing to check'],5,[[0,0,0,0.5],[1,0.5,0,1]]] call epoch_message",
			{"DocCheckAbord"}
		}
	};
	abandonTime 			= 240;
	failedCondition 		= "!(alive player)";
	faileddialogues[] 		= {};
	completeCondition		= "'ItemDocument' in magazines player && diag_tickTime - EPOCH_task_startTime >= 12 && alive player && player distance EPOCH_Mission_StartPos <= 5";
	completedialogues[] 	= {};
	completedCALL 			= "if !('ItemDocument' in magazines player) exitwith {}; player removeMagazine 'ItemDocument'; if ((random 100) > 70) exitwith {[selectrandom ['Oh no, your document is too much damaged. Sorry!','Sorry, I can not read this document. It is only trash. Sorry!'],5] call epoch_message};_randomdoc = selectRandomWeighted ['ItemVehDoc1',10,'ItemVehDoc2',6,'ItemVehDoc3',4,'ItemVehDoc4',2,'ItemVehDocRara',1]; [format ['Oh great, it is a %1 - I put it in your pocket',_randomdoc call EPOCH_itemDisplayName],5,[[0,0,0,0.5],[1,0.5,0,1]]] call Epoch_Message; _randomdoc call EPOCH_fnc_addItemOverflow";
	reward[] 				= {};
	cleanUp 				= 1;
	nextTask[] 				= {};
};
class DocCheckAbord{
	author 					= "He-Man";
	title 					= "DocCheckAbord";
	simpleTask 				= 0;
	items[] 				= {};
	triggerDelay 			= 1;
	triggerintervall		= 1;
	markerType 				= 0;
	markerVisible			= 0;
	markerRadius 			= 0;
	markerText 				= "";
	initcall 				= "EPOCH_Mission_StartPos = nil;";
	cleanUpCall 			= "";
	dialogues[]				= {
	};
	callevents[]			= {
	};
	abandonTime 			= 240;
	failedCondition 		= "true";
	faileddialogues[] 		= {};
	completeCondition		= "false";
	completedialogues[] 	= {};
	completedCALL 			= "";
	reward[] 				= {};
	cleanUp 				= 0;
	nextTask[] 				= {};
};

