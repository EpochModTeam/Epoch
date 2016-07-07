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
//EPOCH_task_startTime - task start diag_tickTime | Usage: diag_tickTime - EPOCH_task_startTime > _someDelayTime;
//EPOCH_taskMarkerPos - Will override the built in marker position. Must be set at init stage, i.e. before marker is created.
//EPOCH_taskTitle - As set by title in each task class.
//EPOCH_taskLastLoop - is the diag_tickTime at the last loop start (based on taskCheckTime). Set to start time until loop starts.
//EPOCH_taskItem - Weaponholder object used to hold task item. Is null object until items are spawned in.
//EPOCH_taskMarkerName - Name for the marker generated automatically by the task system.
//
//Stand alone missions can be called by triggering the first task class with: epochTaskHandle = ["myTaskClass"] execFSM "epoch_code\System\task_control.fsm";
//

	
class taskWithComments{
	//Task Author
	author = "axeman";
	//Task Title as appears in (Accept / Decline) dialogue box. Leave as "" to trigger code only.
	//title, desc and img are WIP and will be used for future dialogue GUIs.
	title = "Find the Backpack.";
	//Description on task. For dialogue box.
	desc = "Our new friend has lost his backpack. Find it in a nearby house. It will be within 50m and looks like a white package. He needs the contents to continue on his way.";
	//Task Image. For dialogue box.
	img = "\A3\Characters_F_EPA\Data\ui\Icon_V_plate_carrier_snake_ca.paa";
	//Simple tasks are used for one off calls, e.g. Ask the trader the time. initfsm, initsqf and/or initcall will be triggered and the task will exit with no monitoring.
	simpleTask = 0;
	//Trigger this task. Use this condition to trigger the task (WIP - Mission and Individual Task Triggers from the Main Loop)
	triggerCondition = "count nearestObjects [player,[""house""],250] > 8";
	//Limit the number of times this task can run for player per life or server restart. (WIP - Part of client / server mission & task monitoring) - Leave as default !
	taskLimit = 3;
	//Pause time in the task loop. This figure is also applied before triggering completion of mission and again before cleanup / reminder / next task.
	taskCheckTime = 16;
	//A pause at the start of the task after collecting variables, before anything is created. TODO: maybe remove..
	triggerDelay = 16;
	//Spawn helper objects at start of task / mission (e.g. a hatchet for a tree chopping task). Array will accept any object classes which will be positioned appropriately (WIP - Mainly to support vehicle spawning).
	items[] = {"ItemSodaOrangeSherbet","itemGPS"};
	//Item Spawn (0 - Do not spawn, 1 - Nearby in House, 2 - Nearby Hidden, 3 - Near Player)
	itemSpawn = 1;
	
	//Call these functions at init of task, after item spawn but before marker creation. Allows setting EPOCH_taskMarkerPos
	initfsm = "";
	initsqf = "";
	initcall = "systemChat 'STARTING FROM CONFIG'";
	
	//Place a marker on task target (0 = No Marker, 1 = Marker, with text, exactly on target, 2 = radial marker with target somewhere random inside marker)
	markerType = 2;
	//Set marker radius for radial marker (markerType = 2)
	markerRadius = 50;
	//Marker Text - Add text to marker, leave "" for no text. No text available for Marker type 2 yet.
	markerText = "Last seen here somewhere.";
	//task fsm / sqf. Call an sqf or FSM, designed to manage the mission locally. Will trigger at task start (After specified delay)
	//All FSM & SQF Calls pass default variables. e.g. [player ,EPOCH_taskItem] execVM "yourSQF.sqf";
	//Both options (SQF or FSM) will be presented when a script call is available. Both will be called if value is not ""
	//All sqf, fsm files are stored, by default, in <Mission Folder>\epoch_code\compile\missions\tasks\ (WIP - Can be edited with the task setting in CfgMissionTasks.hpp)
	//TODO - Reduce to just call so these can all be pre-CompileFinaled
	
	//Call additional functions based on condition, e.g. air drop, antagonist spawn, or custom code.
	//Conditions must return a boolean. e.g. player distance player < 12;
	callEventBinTask = 0;//If calling another task (callEventTask1 etc.) then bin this task before starting the new one ? - WIP
	callEventCondition1 = "true";
	callEventCondition2 = "EPOCH_taskItem distance player < 50";
	callEventCondition3 = "";
	
	//All sqf, fsm files are stored, by default, in <Mission Folder>\epoch_code\compile\missions\tasks\ (WIP - Can be edited with the task setting above)
	callEventCALL1 = "";
	callEventFSM1 = "";
	callEventSQF1 = "triggerAirDrop.sqf";
	//Call another task class from the same mission.
	callEventTask1 = "";
	
	callEventCALL2 = "hint 'You are getting warm'";
	callEventFSM2 = "";
	callEventSQF2 = "";
	callEventTask2 = "";
	
	callEventCALL3 = "";
	callEventFSM3 = "";
	callEventSQF3 = "";
	callEventTask3 = "";
	
	//dialogues. One of the array will be selected randomly upon each trigger
	//Dialogue 1 will trigger only one time upon it's condition, designed to be a welcome message.
	diag1Condition = "true";
	dialogue1[] = {"Ok, first thing I need to do is find my rucksack","Help me find my rucksack first.","I need to find my rucksack."};
	
	//Delay between triggering dialogue, to stop flooding.
	diagSquelch = 60;
	//Dialogue 2 and 3 will repeat everytime the condition is met and the squelch time has elapsed. Designed as warnings / hint dialogues. Again, a random message will be chosen from the array.
	diag2Condition = "diag_tickTime - EPOCH_task_startTime > 20";
	dialogue2[] = {"I dropped it in one of these buildings. Some.. thing was chasing me.","It is in a house nearby, I have a map that I need in it.","Search the nearby houses until you find it."};
	diag3Condition = "EPOCH_taskItem distance player < 12";
	dialogue3[] = {"Wow, you are really close now.","Keep looking, it is right near you.","Smoking hot, you are practically standing on it."};
	
	//FAILED / ABANDONED
	//Apply a condition to detect mission failure. e.g. '!alive _unit' if escorting a NPC. Task will bin upon player death anyway.
	failedCondition = "!alive player";
	//Abandon Distance - Player moves this far from 'task trigger position' causes abandonment of mission (0 = unlimited)
	abandonDist = 100;
	//Time Limit - Once time limit is reached, and completed condition is not met, the mission has failed and will be disposed. 0 = No Limit.
	abandonTime = 240;
	//Failed Message (triggered by timeLimit or abandon distance) - Display random message from array upon task failure.
	failed[] = {"You blew it.","Don't give up your day job pal..","That's you finished mate, bring on the pain."};
	//Run a command to punish failure of task (triggered by timeLimit or failure condition).
	failedFSM = "";
	failedSQF = "";
	failedCall = "[] call EPOCH_callSapperMigration;";
	//Add failure task. Can be multiple tasks that are picked at random.
	failedTask[] = {""};
	//Dispose of task item at failure 0 = No, 1 = Yes. Cleans up any spawned weaponholders.
	cleanUp = 1;
	//Upon FSM disposal call compile each piece of code. Designed to cleanup namespace(s).
	cleanUpCalls[] = {""};
	//COMPLETED
	//Condition met to trigger completion of task.
	completeCondition = "EPOCH_taskItem distance player < 2";
	//Drop reward for player - Currently always nearby, on the floor.
	reward[] = {"ItemSodaOrangeSherbet","ItemSodaPurple","ItemSodaMocha"};
	//Completed dialogues, selected randomly from each array. With pause in-between completed1 and completed2.
	completed1[] = {"Well done, that was quick. Let me have it, and here's something for you.","You've found it, good job. I have something in here you can have.","Well found, you're a natural. Here, this is yours, thank you."};
	completed2[] = {"Now let's head out of town, you lead the way !","It's time to leave this area, let's go !","Do you think we should get out of this area now ?"};
	//Remind / hint to the player to get them onto the NEXT task. Displays after longer pause
	reminder[] = {"It's about time we headed out of town.","We need to get away from these houses.","Let's move away from these built up areas."};
	//Trigger next task at disposal of this one. Allows tasks to be strung together. If more than one a task is selected at random. Leave blank to end mission and reset menu item at trader.
	nextTask[] = {"findHouseItem"};
};
	
class blankTaskWithDefaults{
	author = "axeman";
	title = "";
	desc = "";
	img = "";
	simpleTask = 0;
	triggerCondition = "";
	taskLimit = 3;
	taskCheckTime = 16;
	triggerDelay = 16;
	items[] = {""};
	itemSpawn = 1;
	markerType = 2;
	markerRadius = 50;
	markerText = "";
	initfsm = "";
	initsqf = "";
	initcall = "";
	callEventBinTask = 0;
	callEventCondition1 = "";
	callEventCondition2 = "";
	callEventCondition3 = "";
	callEventCALL1 = "";
	callEventFSM1 = "";
	callEventSQF1 = "";
	callEventTask1 = "";
	callEventCALL2 = "";
	callEventFSM2 = "";
	callEventSQF2 = "";
	callEventTask2 = "";
	callEventCALL3 = "";
	callEventFSM3 = "";
	callEventSQF3 = "";
	callEventTask3 = "";
	diag1Condition = "";
	dialogue1[] = {""};
	diagSquelch = 60;
	diag2Condition = "";
	dialogue2[] = {""};
	diag3Condition = "";
	dialogue3[] = {""};
	failedCondition = "";
	abandonDist = 100;
	abandonTime = 240;
	failed[] = {""};
	failedFSM = "";
	failedSQF = "";
	failedCall = "";
	failedTask[] = {""};
	cleanUp = 1;
	cleanUpCalls[] = {};
	completeCondition = "";
	reward[] = {""};
	completed1[] = {""};
	completed2[] = {""};
	completedCALL = "";
	reminder[] = {""};
	nextTask[] = {""};
};