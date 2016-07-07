/*
	Author: Aaron Clark - EpochMod.com

    Contributors:

	Description:
	Master loop is a simple config based event scheduler that handles all time based player related tasks.

    Licence:
    Arma Public License Share Alike (APL-SA) - https://www.bistudio.com/community/licenses/arma-public-license-share-alike

    Github:
    https://github.com/EpochModTeam/Epoch/tree/release/Sources/epoch_config/Configs/CfgMasterLoop.hpp
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
			delay = 1; // in seconds
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
	};
};
