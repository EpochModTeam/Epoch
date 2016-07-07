/*
	Author: Raimonds Virtoss - EpochMod.com

    Contributors:

	Description:
	Config for Epoch Configuration system

    Licence:
    Arma Public License Share Alike (APL-SA) - https://www.bistudio.com/community/licenses/arma-public-license-share-alike

    Github:
    https://github.com/EpochModTeam/Epoch/tree/release/Sources/epoch_config/Configs/CfgEpochConfiguration.hpp
*/

class CfgEpochConfiguration
{
	/** class order here decides order of buttons on gui **/
	class remap
	{
		name = "Controls";
		color[] = {1,1,1,1};
		icon = "\x\addons\a3_epoch_code\Data\owner.paa";
		controlGroup = "EpochConfigKeyMap";
	};
	class HUD
	{
		name = "Customize HUD (WIP)";
		color[] = {1,1,1,1};
		icon = "\x\addons\a3_epoch_code\Data\owner.paa";
		controlGroup = "Epoch_main_config_dynamicHUD";
	};
	class html
	{
		name = "Changelog";
		color[] = {1,1,1,1};
		icon = "\x\addons\a3_epoch_code\Data\owner.paa";
		controlGroup = "Epoch_main_config_changelog";
	};
};
