/*
	Author: Aaron Clark - EpochMod.com

    Contributors:

	Description:
	CfgSounds config and CfgSay3Dhandler

    Licence:
    Arma Public License Share Alike (APL-SA) - https://www.bistudio.com/community/licenses/arma-public-license-share-alike

    Github:
    https://github.com/EpochModTeam/Epoch/tree/master/Sources/epoch_config/Configs/CfgSounds.hpp
*/

class CfgSounds
{
	class dog_bark
	{
		sound[] = { "\A3\Sounds_F\ambient\animals\dog1", 0.6, 1.0 };
		titles[] = {};
	};
	class dog_cry
	{
		sound[] = { "\A3\Sounds_F\ambient\animals\dog4", 0.6, 1.0 };
		titles[] = {};
	};
	class hed_cluck0
	{
		sound[] = { "\A3\Sounds_F\ambient\animals\hen1", 0.3, 1.0 };
		titles[] = {};
	};
	class hed_cluck1
	{
		sound[] = { "\A3\Sounds_F\ambient\animals\hen2", 0.3, 1.0 };
		titles[] = {};
	};
	class hed_cluck2
	{
		sound[] = { "\A3\Sounds_F\ambient\animals\hen3", 0.3, 1.0 };
		titles[] = {};
	};
	class cultist_talk
	{
		sound[] = { "\x\addons\a3_epoch_assets\sounds\cloak\cultist_banter1", 0.7, 1.0 };
		titles[] = {};
	};
	class cultist_death
	{
		sound[] = { "\x\addons\a3_epoch_assets\sounds\cloak\cultist_death", 0.7, 1.0 };
		titles[] = {};
	};
	class cultist_laugh
	{
		sound[] = { "\x\addons\a3_epoch_assets\sounds\cloak\cultist_laugh", 0.7, 1.0 };
		titles[] = {};
	};
	class cultist_nearby
	{
		sound[] = { "\x\addons\a3_epoch_assets\sounds\cloak\cultist_nearby", 0.7, 1.0 };
		titles[] = {};
	};
	class cultist_taunt
	{
		sound[] = { "\x\addons\a3_epoch_assets\sounds\cloak\cultist_taunt", 0.7, 1.0 };
		titles[] = {};
	};
};

// Custom Epoch config for say3d broadcsting
class CfgSay3Dhandler {
	class snake_bite0 {
		distance = 100;
	};
	class cultist_nearby {
		distance = 100;
	};
	class dog_bark {
		distance = 750;
	};
	class dog_cry {
		distance = 600;
	};
	class hed_cluck0 {
		distance = 600;
	};
	class hed_cluck1 {
		distance = 600;
	};
	class hed_cluck2 {
		distance = 600;
	};
	class cultist_talk {
		distance = 30;
	};
	class cultist_laugh {
		distance = 30;
	};
	class cloak_death {
		distance = 30;
	};
	class drone_alert0 {
		distance = 400;
	};
	class sapper_alert0 {
		distance = 400;
	};
	class sapper_groan0 {
		distance = 400;
	};
	class sapper_groan1 {
		distance = 400;
	};
	class sapper_groan2 {
		distance = 400;
	};
	class sapper_explode {
		distance = 1000;
	};
};
