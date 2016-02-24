/*
	Author: Aaron Clark - EpochMod.com

    Licence:
    Arma Public License Share Alike (APL-SA) - https://www.bistudio.com/community/licenses/arma-public-license-share-alike

    Github:
    https://github.com/EpochModTeam/Epoch/tree/master/Sources/epoch_config/config.cpp
*/

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

class CfgCommands
{
	// allowedHTMLLoadURIs[] += // think this adds to an existing array?
	allowedHTMLLoadURIs[] +=
	{
		"http://epochmod.com*"
	};
};
