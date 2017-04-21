/*
	Author: Andrew Gregory - EpochMod.com

    Contributors:

	Description:
	Mission selection configs and dialogs. Defines the missions for trader menu or triggered event.

    Licence:
    Arma Public License Share Alike (APL-SA) - https://www.bistudio.com/community/licenses/arma-public-license-share-alike

    Github:
    https://github.com/EpochModTeam/Epoch/tree/release/Sources/epoch_config/Configs/CfgMissions.hpp
*/

class EpochMissionList{
//	traderMissionClasses[] = {"missionMonster","missionDelivery","missionEscort","missionUav","missionSapper","missionSkull","missionMilitary","gameCaptureTheJammer","gameCarRace","infoTime","infoName","infoNews","infoVehicles","infoPeople","helpAirDrop","debugResetMission"}; //Exclude from here to remove from menu and trigger
	traderMissionClasses[] = {"missionfishing","missionMonster","missionDelivery","missionUav","infoTime","infoName","infoNews","infoVehicles","infoPeople","debugResetMission"}; //Exclude from here to remove from menu and trigger
	traderMissionActiveNames[] = {}; //Not currently used (WIP)
	traderMissionLongDesc[] = {}; //Not currently used (WIP)
	traderMissionActiveLongDesc[] = {}; //Not currently used (WIP)
};

class epochMissions {
	class missionfishing{
		missionName = "Bring me a fresh Fish"; //Name of mission as it appears in trader list
		missionToolTip= "Bring the Trader a fresh Fish from the Water."; //Tooltip for trader menu
		missionDesc = "You must went to the Water and catch a Fish for the Trader and bring it to him."; //Misison description as it appears in trader menu.
		missionDeny = "!(""MeleeRod"" in weapons player)"; //Specify a call compile condition. If it returns true the mission will be dis-allowed. Title will be rust coloured and prefixed with NOT ALLOWED.
		missionDenyToolTip = "You need a Fishing-Rod for this Mission"; //Provides a tooltip explaining why the mission is denied. prefixed with NOT ALLOWED.
		tasksList[] = {"StartFishMission"}; //Must contain a list of tasks used for this mission, in order. Used to control trader menu when mission is active. WIP - To control mission from this array alone.
		missionTrigger = ""; //A dynamic trigger that sets off the mission anywhere in-game. e.g. player != vehicle player Not currently used (WIP)
		missionTriggerDialog[] = {""}; //Randomly selected dialogue that is shown when mission is dynamically triggered. Not currently used (WIP)
	};
	class missionMonster{
		missionName = "Escort my Monster (Experimental)"; //Name of mission as it appears in trader list
		missionToolTip= "Escort a Monster."; //Tooltip for trader menu
		missionDesc = "You must escort the Traders Monster to another Trader somewhere else on the map."; //Misison description as it appears in trader menu.
		missionDeny = ""; //Specify a call compile condition. If it returns true the mission will be dis-allowed. Title will be rust coloured and prefixed with NOT ALLOWED.
		missionDenyToolTip = ""; //Provides a tooltip explaining why the mission is denied. prefixed with NOT ALLOWED.
		tasksList[] = {"prepForMonsterEscort"}; //Must contain a list of tasks used for this mission, in order. Used to control trader menu when mission is active. WIP - To control mission from this array alone.
		missionTrigger = ""; //A dynamic trigger that sets off the mission anywhere in-game. e.g. player != vehicle player Not currently used (WIP)
		missionTriggerDialog[] = {""}; //Randomly selected dialogue that is shown when mission is dynamically triggered. Not currently used (WIP)
	};
	class missionDelivery{
		missionName = "Pikes Peak Express"; //Name of mission as it appears in trader list
		missionToolTip= "Courier."; //Tooltip for trader menu
		missionDesc = "You must deliver an important message to another trader somewhere else on the map. Choose your trader wisely."; //Misison description as it appears in trader menu.
		missionDeny = ""; //Specify a call compile condition. If it returns true the mission will be dis-allowed. Title will be rust coloured and prefixed with NOT ALLOWED.
		missionDenyToolTip = ""; //Provides a tooltip explaining why the mission is denied. prefixed with NOT ALLOWED.
		tasksList[] = {"prepForDelivery","doDelivery","finishDelivery"}; //Must contain a list of tasks used for this mission, in order. Used to control trader menu when mission is active. WIP - To control mission from this array alone.
		missionTrigger = ""; //A dynamic trigger that sets off the mission anywhere in-game. e.g. player != vehicle player Not currently used (WIP)
		missionTriggerDialog[] = {""}; //Randomly selected dialogue that is shown when mission is dynamically triggered. Not currently used (WIP)
	};
	
	class missionEscort{
		missionName = "VIP Escort";
		missionToolTip = "Escort a VIP..";
		missionDesc = "You must deliver the generals daughter to a secret military base.";
		missionDeny = "true";
		missionDenyToolTip = "Not Ready.";
		tasksList[] = {"takeEscortDelivery","startEscortMission","AIVehicleFind","rndDenyIfInGroup"};
		missionTrigger = "";
		missionTriggerDialog = "";
	};
	
	class missionUav{
		missionName = "Drone Pilot";
		missionToolTip = "Pilot a UAV.";
		missionDesc = "Fly a drone to another trader and perform reconnaissance over the area. Girls make better pilots.";
		missionDeny = "missionNameSpace getVariable [""EPOCH_playerEnergy"",0] < 50";
		missionDenyToolTip = "You require energy for this mission !";
		tasksList[] = {"uavMissionAccepted","doUAVSpawn","doUAVAttach","takeOffUAV","uavMission1","uavMission2","uavMission3"};
		missionTrigger = "";
		missionTriggerDialog = "";
	};
	
	class missionSapper{
		missionName = "Sapper Bait";
		missionToolTip = "Lure a sapper back to the trader.";
		missionDesc = "Traders use sappers as bait for bigger prey, earn a reward.";
		missionDeny = "true";
		missionDenyToolTip = "Not Ready.";
		tasksList[] = {"takeEscortDelivery","startSapperMission","AIVehicleFind","rndDenyIfInGroup"};
		missionTrigger = "";
		missionTriggerDialog = "";
	};
	
	class missionSkull{
		missionName = "Skulls New Target";
		missionToolTip = "Infiltrate a secure location.";
		missionDesc = "Use your sniper and camouflage skills to complete this mission for a large reward.";
		missionDeny = "true";
		missionDenyToolTip = "Not Ready.";
		tasksList[] = {"prepForMisssion","moveToContact","TakeMission","leaveContact","moveToMilitary","meetInsurgentContact","spawnCOntact","findPosition","removeTargets","moveIn","takeReward","rndVehicleSpawn","rndLooter","rndSapperSpwn","rndInsurgentTaskBin","rndInsurgentTaksCont"};
		missionTrigger = "";
		missionTriggerDialog = "";
	};
	
	class missionMilitary{
		missionName = "Military Crash";
		missionToolTip = "Loot the crashed military vehcile.";
		missionDesc = "Expect some resistance as you clear out the remaining troops and reap the rewards.";
		missionDeny = "count weapons player < 1";
		missionDenyToolTip = "You are going to need weapons.";
		tasksList[] = {"milMissionAccepted","milSpawnCrashSite","milMarkCrashSite","milFindCrashSite","milEndCrashSite"};
		missionTrigger = "";
		missionTriggerDialog = "";
	};

	class gameCaptureTheJammer{
		missionName = "Capture the Jammer";
		missionToolTip = "Mini Game - Fight for control of the base with your group.";
		missionDesc = "Weapon and ammo drops during the game, the longer you keep the jammer the larger the prize, if you can find it.";
		missionDeny = "true";
		missionDenyToolTip = "Not Ready.";
		tasksList[] = {"acceptMisssion","tpPlayerFSM","scoreMOnitorFSM","timeoutSpawnRndReward"};
		missionTrigger = "";
		missionTriggerDialog = "";
	};
	
	class gameCarRace{
		missionName = "First Past The Line";
		missionToolTip = "Mini Game - Vehicle Race";
		missionDesc = "Mini Game - Race your vehicles to the finish point, make it there without stacking into a tree, there may be a prize for the winner.";
		missionDeny = "true";
		missionDenyToolTip = "Not Ready.";
		tasksList[] = {};
		missionTrigger = "";
		missionTriggerDialog = "";
	};
	
	class infoTime{
		missionName = "What is the time ?";
		missionDesc = "Find out the time from the trader.";
		missionToolTip = "What's the time";
		missionDeny = "";
		missionDenyToolTip = "";
		tasksList[] = {"traderDiagTime"};
		missionTrigger = "";
		missionTriggerDialog = "";
	};
	
	class infoName{
		missionName = "What is your name friend ?";
		missionDesc = "Ask the trader his name..";
		missionToolTip = "Trader Name";
		missionDeny = "";
		missionDenyToolTip = "";
		tasksList[] = {"traderDiagName"};
		missionTrigger = "";
		missionTriggerDialog = "";
	};
	
	class infoNews{
		missionName = "So, what's new ?";
		missionDesc = "Ask the trader for news or tips.";
		missionToolTip = "News";
		missionDeny = "";
		missionDenyToolTip = "";
		tasksList[] = {"traderDiagNews"};
		missionTrigger = "";
		missionTriggerDialog = "";
	};
	class infoPeople{
		missionName = "Who is nearby ?";
		missionDesc = "Find out if there are nearby players.";
		missionToolTip = "Players";
		missionDeny = "";
		missionDenyToolTip = "";
		tasksList[] = {"traderDiagNearby"};
		missionTrigger = "";
		missionTriggerDialog = "";
	};
	class infoVehicles{
		missionName = "What Vehicles are Nearby ?";
		missionDesc = "Ask the trader if they know of any vehicle locations.";
		missionToolTip = "Need a Ride.";
		missionDeny = "";
		missionDenyToolTip = "";
		tasksList[] = {"traderNearVehicles"};
		missionTrigger = "";
		missionTriggerDialog = "";
	};
	class helpAirDrop{
		missionName = "Call an Air Drop";
		missionDesc = "Helper - Call an airdrop if available";
		missionToolTip = "Airdrop Request.";
		missionDeny = "";
		missionDenyToolTip = "";
		tasksList[] = {"traderTriggerAirDrop"};
		missionTrigger = "";
		missionTriggerDialog = "";
	};
	class debugResetMission{
		missionName = "Reset Missions";
		missionDesc = "Experimental - Reset missions cache if stuck on a mission.";
		missionToolTip = "DEBUG - Reset.";
		missionDeny = "";
		missionDenyToolTip = "";
		tasksList[] = {"traderMissionReset"};
		missionTrigger = "";
		missionTriggerDialog = "";
	};
};
