/****************************************************************************
Copyright (C) 2015 - ARMA 3 EPOCH MOD [EpochMod.com] (v0.3.0.1)
*****************************************************************************/

#define _ARMA_

class CfgPatches {
	class A3_epoch_server {
		units[] = {};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = {"A3_epoch_server_core","A3_epoch_config","A3_server_settings"};
	};
};
class cfgFunctions
{
	class A3E
	{
		tag = "EPOCH";
		class Epoch_Server
		{
			file = "\x\addons\a3_epoch_server\init";
			class init
			{
				preInit = 1;
			};
			class postinit
			{
				postInit = 1;
			};
		};
		class vehicles {
			class spawn_vehicle {
				file = "\x\addons\a3_epoch_server\compile\epoch_vehicle\EPOCH_spawn_vehicle.sqf";
			};
		};
		class bases {
			class saveBuilding {
				file = "\x\addons\a3_epoch_server\compile\epoch_bases\fn_saveBuilding.sqf";
			};
		};
	};

};
class CfgServerVersion
{
	client = "0.3.6.0";
	config = "0.3.6.0";
	hive = "0.5.1.7";
};
