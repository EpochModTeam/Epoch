/*
	Author: Andrew Gregory - EpochMod.com
    Contributors: 

	Description:
	Example Mission file containing individual tasks (Commented)

    Licence:
    Arma Public License Share Alike (APL-SA) - https://www.bistudio.com/community/licenses/arma-public-license-share-alike

    Github:
    https://github.com/EpochModTeam/Epoch/tree/release/Sources/epoch_config/Configs/CfgEpochClient.hpp
*/

//Built in useful vars that can be used in code based conditions / responses etc.
//N.B. Local vars can not be used as they are not in scope when call compiled.
//
// EPOCH_task_startTime 	- task start diag_tickTime | Usage: diag_tickTime - EPOCH_task_startTime > _someDelayTime;
// EPOCH_mission_starttime 	- mission start diag_ticktime
// EPOCH_taskMarker 		- Array for Marker, if set [markername,markerType]. "markerType" see in task description
// EPOCH_taskMarkerPos 		- Markerposition, if set.


class sampletask {
	author 					= "My Name";
	title 					= "Mission Title";
	simpleTask 				= 0;
	items[] 				= {"B_UavTerminal"};	// Items will be dropped on the Ground next to Player
	triggerDelay 			= 2;					// Before this time (in sec) the task will not Start
	taskCheckTime 			= 3;					// Intervall (in sec) for the triggers
	markerType 				= 0;					// Place a marker on task target (0 = No Marker, 1 = Marker, with text, exactly on target, 2 = radial marker with target somewhere random inside marker)
	markerVisible			= 0;					// Marker visible for: 0 = Only Player (default), 1 = Group of Player, 2 = Global
	markerRadius 			= 0;					// Set marker radius for radial marker (markerType = 2)
	markerText 				= "";					// Marker Text - Add text to marker, leave "" for no text. No text available for Marker type 2 yet.
	initcall 				= "";					// Code to call on task-start
	cleanUpCall 			= "";					// Code to call on task failed or when cleanUp = 1 on finished
	dialogues[]				= {						// Array to make dialogues while task is running
		{
			"alive player",							// Condition 1
			{"Text 1","Text 2","Text 3"}			// Array of random dialogues when condition 1 = true
		},
		{
			"alive player",							// Condition 2
			{"Text 1","Text 2","Text 3"}			// Array of random dialogues when condition 2 = true
		}
	};
	callevents[]			= {						// Array to call codes and / or start a nex task
		{
			"(diag_tickTime - StartTime > 30)",		// Condition 1
			"",										// String with code to call when condition 1 = true
			{"uavMission1"}							// Array of random selected tasks to switch to when condition 1 = true
		},
		{
			"!alive player",						// Condition 2
			"player setdamage 1",					// String with code to call when condition 2 = true
			{"uavMission2"}							// Array of random selected tasks to switch to when condition 2 = true
		},
	};
	abandonTime 			= 240;					// Timeout for task
	failedCondition 		= "false";				// Failed Condition for Task
	faileddialogues[] 		= {"Text1","Text2"};	// Array of random dialogues when task failed
	completeCondition		= "'B_UavTerminal' in assignedItems player";	// Condition to complete the task succesfully
	completedialogues[] 	= {"Text1","Text2"};	// Array of random dialogues when task completed successfully
	completedCALL 			= "";					// Code to call when task completed successfully
	reward[] 				= {};					// Array of items, that spawn next to the Player when completed successfully
	cleanUp 				= 0;					// Set to 1 to call cleanupcall on success
	nextTask[] 				= {"doUAVSpawn"};		// Array of next selected random tasks

// Not used atm	
	taskLimit 				= 3;
	itemSpawn 				= 3;
	callEventBinTask 		= 0;
	diagSquelch 			= 30;
	abandonDist 			= 100;
};