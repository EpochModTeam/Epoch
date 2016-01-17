/*
	Author: Aaron Clark - EpochMod.com

    Contributors: Niklas Wagner

	Description:
	Epoch Functions config - Intent of this config is to apply a custom respawn template

    Licence:
    Arma Public License Share Alike (APL-SA) - https://www.bistudio.com/community/licenses/arma-public-license-share-alike

    Github:
    https://github.com/EpochModTeam/Epoch/tree/master/Sources/epoch_functions/config.hpp
*/

#define _ARMA_

class CfgPatches
{
	class A3_epoch_functions
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = {"A3_Functions_F","A3_epoch_code"};
		epochVersion = "0.3.7.0";
	};
};
class cfgFunctions
{
	version = 4;
	init = "x\addons\a3_epoch_code\compile\bis_functions\initFunctions.sqf";
	class A3
	{
		tag = "BIS";
		class Respawn
		{
			file = "A3\functions_f\Respawn";
			class selectRespawnTemplate
			{
				file = "\x\addons\a3_epoch_code\compile\bis_functions\Respawn\fn_selectRespawnTemplate.sqf";
			};
		};
	};
};
