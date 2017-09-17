/*
	Author: Aaron Clark - EpochMod.com

    Contributors:

	Description:
	Epoch Server Event (DynamicDebris)

    Licence:
    Arma Public License Share Alike (APL-SA) - https://www.bistudio.com/community/licenses/arma-public-license-share-alike

    Github:
    https://github.com/EpochModTeam/Epoch/tree/release/Sources/epoch_server_vip_event/config.cpp
*/

#define _ARMA_

class CfgPatches {
	class A3_server_vip_event {
		requiredVersion = 0.1;
		requiredAddons[] = {"A3_server_events"};
        #include "build.hpp"
	};
};

// import settings
class CfgEpochServerEvents
{
    class VIP {
        delay = 900; // delay in seconds between executions <SCALAR>,
        script = "\epoch_server_vip_event\EpochEvents\event1.sqf"; // script: name or full path if usePrefix is set to 0.
        runOnStart = 0; // runOnStart: 0 normal delay, 1 = run script at startup.
        usePrefix = 0; // usePrefix: 0 = use full file path, 1 = pre/postfix path (use if file is inside epoch settings pbo EpochEvents folder), 2 = pre/postfix path (use if file inside epoch events pbo EpochEvents folder).
        runNumTimes = -1; // runNumTimes: 0 = disabled, 1+ = number of times to execute before removing event, -1 = no limit.
        input[] = {"ItemBriefcaseGold100oz"}; // array input to execVM at time of run and accessed with _this inside of script.
		disallowedWorlds[] = {"VR"};
    };
};
