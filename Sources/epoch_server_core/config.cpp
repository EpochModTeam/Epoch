/*
	Author: Aaron Clark - EpochMod.com

    Contributors:

	Description:
	Epoch Server Core Config

    Licence:
    Arma Public License Share Alike (APL-SA) - https://www.bistudio.com/community/licenses/arma-public-license-share-alike

    Github:
    https://github.com/EpochModTeam/Epoch/tree/master/Sources/epoch_server_core/config.hpp
*/

#define _ARMA_
class CfgPatches {
	class A3_epoch_server_core {
		units[] = {};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = {};
		#include "build.hpp"
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
			class server_hiveGETRANGE  		{};
			class server_hiveGETBIT 	 	{};
			class server_hiveGETTTL    		{};
			class server_hiveDEL       		{};
			class server_hiveLog       		{};
		};
	};
};
