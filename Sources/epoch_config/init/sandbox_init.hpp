author = "Epoch Mod Team";
class Header
{
 gameType = Sandbox;
 minPlayers = 1;
 maxPlayers = 100;
};
respawn = "BASE";
respawnDelay = 600;
respawnDialog = 0;

onLoadMission= "Epoch";
OnLoadIntro = "Welcome to Epoch Mod";
loadScreen = "\x\addons\a3_epoch_assets\pictures\loadScreen_ca.paa";
OnLoadIntroTime = False;
OnLoadMissionTime = False;
onLoadName = "Epoch Mod";
disabledAI = true;
scriptedPlayer = 1;
disableChannels[]={0,1,2,6};
enableItemsDropping = 0;
briefing = 0;
debriefing = 0;
enableDebugConsole = 0;
joinUnassigned = 0;
respawnOnStart = 0;
forceRotorLibSimulation = 1;

corpseManagerMode = 1;
corpseLimit = 10;
corpseRemovalMinTime = 1200;
corpseRemovalMaxTime = 3600;

wreckManagerMode = 1;
wreckLimit = 2;
wreckRemovalMinTime = 60;
wreckRemovalMaxTime = 360;