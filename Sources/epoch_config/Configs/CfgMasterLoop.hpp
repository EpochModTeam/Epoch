class CfgMasterLoop
{
	class Init
	{
		file = "\x\addons\a3_epoch_code\compile\setup\masterLoop\init.sqf";
	};

	class Events
	{
		condition = "alive player";
		file = "\x\addons\a3_epoch_code\compile\setup\masterLoop";

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
