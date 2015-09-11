/****************************************************************************
Copyright (C) 2015 - ARMA 3 EPOCH MOD [EpochMod.com] (v0.3.3.0)
*****************************************************************************/
#define _ARMA_
class CfgPatches {
	class A3_epoch_server_core {
		units[] = {};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = {};
	};
};
class cfgFunctions
{
	class A3E_CORE
	{
		tag = "EPOCH";
		file = "\epoch_server_core\compile";
		class epoch_hive {
			file = "\epoch_server_core\compile\epoch_hive";
			class server_hiveSET    		{};
			class server_hiveSETBIT 		{};
			class server_hiveSETEX  		{};
			class server_hiveEXPIRE 		{};
			class server_hiveGET  			{};
			class server_hiveGETRANGE  	{};
			class server_hiveGETBIT 	 	{};
			class server_hiveGETTTL    	{};
			class server_hiveDEL       	{};
		};
	};
};
