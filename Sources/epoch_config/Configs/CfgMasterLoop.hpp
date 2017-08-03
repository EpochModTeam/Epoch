/*[[[cog from arma_config_tools import *; json_to_arma()]]]*/
/*
    @author = "Aaron Clark - https://EpochMod.com";
    @contributors[] = {};
    @description = "Master loop is a simple config based event scheduler that handles all time based player related tasks.";
    @licence = "Arma Public License Share Alike (APL-SA) - https://www.bistudio.com/community/licenses/arma-public-license-share-alike";
    @github = "https://github.com/EpochModTeam/Epoch/tree/release/Sources/epoch_config/Configs/CfgMasterLoop.hpp";
*/
class CfgMasterLoop
{
    class Init
    {
        file = "epoch_code\compile\setup\masterLoop\init.sqf";
    };
    class Events
    {
        condition = "alive player";
        file = "epoch_code\compile\setup\masterLoop";
        class Event1
        {
            delay = 1;
        };
        class Event2
        {
            delay = 10;
        };
        class Event3
        {
            delay = 15;
        };
        class Event4
        {
            delay = 30;
        };
        class Event5
        {
            delay = 60;
        };
        class Event6
        {
            delay = 300;
        };
        class Event7
        {
            delay = 600;
        };
		class Event8
		{
			delay = 5; //used for FavBar, adjust as required
		};
    };
};

/*[[[end]]]*/
