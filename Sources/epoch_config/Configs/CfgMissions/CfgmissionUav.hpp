class uavMissionAccepted{
	author 					= "axeman";
	title 					= "UAV Mission Accepted";
	simpleTask 				= 0;
	items[] 				= {};
	triggerDelay 			= 1;
	triggerintervall		= 8;
	markerType 				= 0;
	markerVisible			= 0;
	markerRadius 			= 0;
	markerText 				= "";
	initcall 				= "";
	cleanUpCall 			= "";
	dialogues[]				= {};
	callevents[]			= {};
	abandonTime 			= 240;
	failedCondition 		= "missionNameSpace getVariable [""InSafeZone"",false]";
	faileddialogues[] 		= {"Mission not allowed in Safe Zone"};
	completeCondition		= "true";
	completedialogues[] 	= {};
	completedCALL 			= "";
	reward[] 				= {};
	cleanUp 				= 0;
	nextTask[] 				= {"uavMissionStart"};

// Not used atm	
	taskLimit 				= 3;
	itemSpawn 				= 3;
	callEventBinTask 		= 0;
	diagSquelch 			= 30;
	abandonDist 			= 100;
};
class uavMissionStart{
	author 					= "axeman";
	title 					= "UAV Mission Start";
	simpleTask 				= 0;
	items[] 				= {"B_UavTerminal"};
	triggerDelay 			= 1;
	triggerintervall		= 8;
	markerType 				= 0;
	markerVisible			= 0;
	markerRadius 			= 0;
	markerText 				= "";
	initcall 				= "";
	cleanUpCall 			= "";
	dialogues[]				= {
		{
			"true",
			{"The UAV terminal is at your feet, Equip it !","Pick up the terminal and equip yourself with it.","Grab the UAV terminal and put it in your GPS slot."}
		},
		{
			"!('B_UavTerminal' in assignedItems player)",
			{"Hurry it up, pick up and equip the terminal.","Come on, Equip yourself with the terminal.","We don't have all day, get that terminal equipped."}
		}
	};
	callevents[]			= {
		{
			"missionNameSpace getVariable [""InSafeZone"",false]",
			"['Mission not allowed in Safe Zone',5] call Epoch_Message",
			{}
		}
		
		
	};
	abandonTime 			= 240;
	failedCondition 		= "false";
	faileddialogues[] 		= {"I guess you have better things to do.","Try again later.","You didn't pick up the terminal. Misison Failed !"};
	completeCondition		= "'B_UavTerminal' in assignedItems player";
	completedialogues[] 	= {"That's great, you have 30 seconds to find a safe position.","Find a hidden spot to operate from, take off in 30 seconds.","Find yourself a concealed position to work from, taking off in half a minute."};
	completedCALL 			= "";
	reward[] 				= {};
	cleanUp 				= 0;
	nextTask[] 				= {"doUAVSpawn"};

// Not used atm	
	taskLimit 				= 3;
	itemSpawn 				= 3;
	callEventBinTask 		= 0;
	diagSquelch 			= 30;
	abandonDist 			= 100;
};
class doUAVSpawn{
	author 					= "axeman";
	title 					= "UAV Spawn";
	simpleTask 				= 0;
	items[] 				= {};
	triggerDelay 			= 30;
	triggerintervall		= 2;
	markerType 				= 0;
	markerVisible			= 0;
	markerRadius 			= 0;
	markerText 				= "";
	initcall 				= "axeUAV = objNull";
	cleanUpCall 			= "";
	dialogues[]				= {
		{
			"true",
			{"UAV is ready, get prepared! Connecting in 10 seconds","Here it comes, connecting you in 10 seconds..","Nice spot, connecting you to the UAV in 10 seconds!"}
		}
	};
	callevents[]			= {
		{
			"(diag_tickTime - EPOCH_task_startTime) > 40",
			"_targetPos = (getPosATL player) findEmptyPosition [25,250,""I_UAV_01_F""];axeUAV = createVehicle[""I_UAV_01_F"", _targetPos, [], 10, ""CAN_COLLIDE""];axeUAV disableTIEquipment true;_driver = (group player) createUnit[""I_UAV_AI"", position axeUAV, [], 0, ""CAN_COLLIDE""];_driver moveInAny axeUAV;[axeUAV] remoteExec [""EPOCH_localCleanup"",2]",
			{}
		}
	};
	abandonTime 			= 240;
	failedCondition 		= "!('B_UavTerminal' in assignedItems player) || !(alive player)";
	faileddialogues[] 		= {"Lost it already.. Mission Over","Not a willing pilot eh ? Try again later.","Equipment Lost.. Mission Failed !"};
	completeCondition 		= "!(isNull axeUAV)";
	completedialogues[] 	= {};
	completedCALL			= "";
	reward[] 				= {};
	cleanUp 				= 0;
	nextTask[] 				= {"doUAVAttach"};
};
class doUAVAttach{
	author 					= "axeman";
	title 					= "UAV Spawn";
	simpleTask 				= 0;
	items[] 				= {};
	triggerDelay 			= 2;
	triggerintervall		= 8;
	markerType 				= 0;
	markerVisible			= 0;
	markerRadius 			= 0;
	markerText 				= "";
	initcall 				= "player action [""SwitchToUAVDriver"", axeUAV];addToRemainsCollector[axeUAV];";
	cleanUpCall 			= "[(driver axeUAV)] joinSilent grpNull; removeFromRemainsCollector [axeUAV]; deletevehicle axeUAV";
	dialogues[]				= {
		{
			"true",
			{"Woohoo, here we go.. Get it in the air.","Get it in the air, no time to waste","You are a natural kid. Let's fly."}
		}
	};
	callevents[]			= {};
	abandonTime 			= 1200;
	failedCondition 		= "!('B_UavTerminal' in assignedItems player) || !(alive axeUAV) || !(alive player) || cameraon != axeUAV";
	faileddialogues[] 		= {"Lost it already.. Mission Over","Not a natural pilot. Try again later.","Mission Failed !"};
	completeCondition 		= "(getPosATL axeUAV select 2) > 10";
	completedialogues[] 	= {};
	completedCALL 			= "if(SunOrMoon < 1)then{player action [""lightOn"", axeUAV];};";
	reward[] 				= {};
	cleanUp 				= 0;
	nextTask[]				= {"takeOffUAV"};
};
class takeOffUAV{
	author 					= "axeman";
	title 					= "Pilot the UAV";
	simpleTask 				= 0;
	items[] 				= {};
	triggerDelay 			= 8;
	triggerintervall		= 8;
	markerType 				= 0;
	markerVisible			= 0;
	markerRadius 			= 0;
	markerText 				= "";
	initcall 				= "";
	cleanUpCall 			= "[(driver axeUAV)] joinSilent grpNull; removeFromRemainsCollector [axeUAV]; deletevehicle axeUAV";
	dialogues[]				= {
		{
			"alive axeUAV",
			{"Great start.. Lets take this thing for a ride.","We're off, get some practice, I am finding you a target.","Get clear of this area, I am calculating your target."}
		},
		{
			"alive axeUAV",
			{"Keep it up, you are doing a great job.","Try and find some targets on your way.","Don't get shot down now !"}
		}
	};
	callevents[]			= {
		{
			"diag_tickTime - EPOCH_task_startTime > 30",
			"",
			{"uavMission1","uavMission2"}
		}
	};
	abandonTime 			= 240;
	failedCondition 		= "!('B_UavTerminal' in assignedItems player) || !(alive axeUAV) || !(alive player) || cameraon != axeUAV";
	faileddialogues[] 		= {"Oh dear, that didn't go well..","Try again later.","Misison Failed !"};
	completeCondition 		= "false";
	completedialogues[] 	= {};
	completedCALL 			= "";
	reward[] 				= {};
	cleanUp 				= 0;
	nextTask[] 				= {};
};
class uavMission1{
	author 					= "axeman";
	title 					= "Trader House Recon";
	simpleTask 				= 0;
	items[] 				= {};
	triggerDelay 			= 0;
	triggerintervall		= 8;
	markerType 				= 2;
	markerVisible			= 0;
	markerRadius 			= 180;
	markerText 				= "Trader House Recon";
	initcall 				= "_obj = selectRandom (nearestObjects [axeUAV,[""HOUSE""],2500]);EPOCH_taskMarkerPos = getPosATL _obj;";
	cleanUpCall 			= "[(driver axeUAV)] joinSilent grpNull; removeFromRemainsCollector [axeUAV]; deletevehicle axeUAV";
	dialogues[]				= {
		{
			"true",
			{"I need some recon on a nearby house","We need intelligence on a potential trader location.","Help us gather intel on a trader house !"}
		},
		{
			"EPOCH_taskMarkerPos distance axeUAV > 450",
			{"I have marked your map, it will be nearby.","Check you map, there is a marker near a safehouse","Search your map for the landing zone, near a traders safehouse."}
		},
		{
			"EPOCH_taskMarkerPos distance axeUAV < 450",
			{"Land it nearby and switch off the engine.","You need to land by the house, quietly.","Drop the UAV in the marker, then keep quiet."}
		}
	};
	callevents[]			= {};
	abandonTime				= 900;
	failedCondition 		= "!('B_UavTerminal' in assignedItems player) || !(alive axeUAV) || !(alive player) || cameraon != axeUAV";
	faileddialogues[] 		= {"Oh dear, Mission Over !","Mission Failed !"};
	completeCondition 		= "!(isengineOn axeUAV) && EPOCH_taskMarkerPos distance axeUAV < 275";
	completedialogues[] 	= {"Great work, here's your reward."};
	completedCALL 			= "[(driver axeUAV)] joinSilent grpNull; removeFromRemainsCollector [axeUAV]; deletevehicle axeUAV";
	reward[] 				= {"ItemGoldBar","ItemGoldBar"};
	cleanUp 				= 1;
	nextTask[] 				= {};
};
class uavMission2{
	author 					= "axeman";
	title 					= "Deliver UAV To Trader";
	simpleTask 				= 0;
	items[] 				= {};
	triggerDelay 			= 0;
	triggerintervall		= 8;
	markerType 				= 2;
	markerVisible			= 0;
	markerRadius 			= 220;
	markerText 				= "UAV Trader";
	initcall 				= "_obj = selectRandom (player nearentities [[""C_Man_1""],10500] select {_x getVariable [""AI_SLOT"",-1] > -1 && player distance _x > 50});EPOCH_taskMarkerPos = getPosATL _obj;";
	cleanUpCall 			= "[(driver axeUAV)] joinSilent grpNull; removeFromRemainsCollector [axeUAV]; deletevehicle axeUAV";
	dialogues[]				= {
		{
			"true",
			{"I need this UAV delivering to my buddy","Recon a rogue trader, land this near his location.","Land this UAV near the target trader."}
		},
		{
			"EPOCH_taskMarkerPos distance axeUAV > 450",
			{"Check your map for his location, you will need to land nearby.","I have marked your map with his location.","Fly to the location marked on your map, then land."}
		},
		{
			"EPOCH_taskMarkerPos distance axeUAV < 450",
			{"Get this thing down and the engine off.","Land in the zone and switch your engine off quickly.","Find a landing spot in the area and keep quiet."}
		}
	};
	callevents[]			= {};
	abandonTime 			= 900;
	failedCondition 		= "!('B_UavTerminal' in assignedItems player) || !(alive axeUAV) || !(alive player) || cameraon != axeUAV";
	faileddialogues[] 		= {"Oh dear, Mission Over !","Mission Failed !"};
	completeCondition 		= "!(isengineOn axeUAV) && EPOCH_taskMarkerPos distance axeUAV < 275";
	completedialogues[]		= {"Great work, here's your reward."};
	completedCALL 			= "[(driver axeUAV)] joinSilent grpNull; removeFromRemainsCollector [axeUAV]; deletevehicle axeUAV";
	reward[] 				= {"ItemGoldBar","ItemGoldBar"};
	cleanUp 				= 1;
	nextTask[] 				= {};
};
