/*
	Author: Aaron Clark - EpochMod.com

    Contributors:

	Description:
	Epoch Server Event (DynamicDebris)

    Licence:
    Arma Public License Share Alike (APL-SA) - https://www.bistudio.com/community/licenses/arma-public-license-share-alike

    Github:
    https://github.com/EpochModTeam/Epoch/tree/release/Sources/epoch_server_debris_event/config.cpp
*/

#define _ARMA_

class CfgPatches {
	class A3_server_debris_event {
		requiredVersion = 0.1;
		requiredAddons[] = {"A3_server_events"};
        #include "build.hpp"
	};
};

// import settings
class CfgEpochServerEvents
{
    class DynamicDebris {
        delay = 120; // delay in seconds between executions <SCALAR>,
        script = "\epoch_server_debris_event\EpochEvents\DynamicDebris.sqf"; // script: name or full path if usePrefix is set to 0
        runOnStart = 1; // runOnStart: 1 = run script at startup, 0 normal delay
        usePrefix = 0; // usePrefix: 1 = pre/postfix path (use if file is inside epoch settings pbo EpochEvents folder), 2 = pre/postfix path (use if file inside epoch events pbo EpochEvents folder), 0 = use full file path
        runNumTimes = 1; // runNumTimes: -1 = no limit, 0 = disabled, 1+ = number of times to execute before removing event.
        input[] = {}; // array input to execVM at time of run and accessed with _this inside of script.
		disallowedWorlds[] = {"VR"};
    };
};
