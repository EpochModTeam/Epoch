/*
	Epoch Mod Sandbox Survival Gamemode

	Author: Epoch Mod Team - EpochMod.com

    Licence:
    Arma Public License Share Alike (APL-SA) - https://www.bistudio.com/community/licenses/arma-public-license-share-alike

    Github:
    https://github.com/EpochModTeam/Epoch/tree/master/Sources/epoch_config/config.hpp
*/

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
respawnButton = 0;
respawnOnStart = -1;
onPauseScript = "epoch_code\gui\scripts\Epoch_onPause.sqf";
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
forceRotorLibSimulation = 1;
saving = 0;

corpseManagerMode = 1;
corpseLimit = 10;
corpseRemovalMinTime = 1200;
corpseRemovalMaxTime = 3600;

wreckManagerMode = 1;
wreckLimit = 2;
wreckRemovalMinTime = 60;
wreckRemovalMaxTime = 360;

disableRandomization[] = {"All"};

#include "Configs\CfgTraderMissions.hpp"
#include "Configs\cfgCrafting.hpp"
#include "Configs\cfgPricing.hpp"
#include "Configs\CfgEpochClient.hpp"
#include "Configs\CfgMasterLoop.hpp"
#include "Configs\CfgBaseBuilding.hpp"
#include "Configs\CfgSnapChecks.hpp"
#include "Configs\CfgBuildingLootPos.hpp"
#include "Configs\CfgActionMenu\CfgActionMenu_core.hpp"
#include "Configs\CfgEpochConfiguration.hpp"
#include "Configs\CfgClientFunctions.hpp"
#include "Configs\CfgFunctions.hpp"
#include "Configs\CfgRemoteExec.hpp"

class CfgEpochBuild
{
 	#include "build.hpp"
};
