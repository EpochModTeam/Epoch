class EpochGameUI
{
	idd = -2;
	duration = 999999;
	onLoad = "uiNamespace setVariable ['EPOCH_EpochGameUI', _this select 0];";
	class controls
	{

		class custom_picture: RscPicture
		{
			style = 48 + 0x800;
		};
		class icon1: custom_picture
		{
			idc = 21201;
			text = "\x\addons\a3_epoch_code\Data\UI\thirst_ca.paa";
			x = "10 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(profilenamespace getvariable [""IGUI_GRID_WEAPON_X"",		((safezoneX + safezoneW) - 		(12.4 * 			(			((safezoneW / safezoneH) min 1.2) / 40)) - 0.5 * 			(			((safezoneW / safezoneH) min 1.2) / 40))])";
			y = "0 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(profilenamespace getvariable [""IGUI_GRID_WEAPON_Y"",		(safezoneY + 0.5 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25))])";
			w = "2.5 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "2.5 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";

		};
		class icon2: custom_picture
		{
			idc = 21202;
			text = "\x\addons\a3_epoch_code\Data\UI\hunger_ca.paa";
			x = "7.5 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(profilenamespace getvariable [""IGUI_GRID_WEAPON_X"",		((safezoneX + safezoneW) - 		(12.4 * 			(			((safezoneW / safezoneH) min 1.2) / 40)) - 0.5 * 			(			((safezoneW / safezoneH) min 1.2) / 40))])";
			y = "0 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(profilenamespace getvariable [""IGUI_GRID_WEAPON_Y"",		(safezoneY + 0.5 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25))])";
			w = "2.5 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "2.5 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";

		};
		class icon3: custom_picture
		{
			idc = 21203;
			text = "\x\addons\a3_epoch_code\Data\UI\broken_ca.paa";
			x = "5 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(profilenamespace getvariable [""IGUI_GRID_WEAPON_X"",		((safezoneX + safezoneW) - 		(12.4 * 			(			((safezoneW / safezoneH) min 1.2) / 40)) - 0.5 * 			(			((safezoneW / safezoneH) min 1.2) / 40))])";
			y = "0 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(profilenamespace getvariable [""IGUI_GRID_WEAPON_Y"",		(safezoneY + 0.5 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25))])";
			w = "2.5 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "2.5 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";

		};
		class icon4: custom_picture
		{
			idc = 21204;
			text = "\x\addons\a3_epoch_code\Data\UI\oxygen_ca.paa";
			x = "2.5 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(profilenamespace getvariable [""IGUI_GRID_WEAPON_X"",		((safezoneX + safezoneW) - 		(12.4 * 			(			((safezoneW / safezoneH) min 1.2) / 40)) - 0.5 * 			(			((safezoneW / safezoneH) min 1.2) / 40))])";
			y = "0 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(profilenamespace getvariable [""IGUI_GRID_WEAPON_Y"",		(safezoneY + 0.5 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25))])";
			w = "2.5 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "2.5 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";

		};
		class icon5: custom_picture
		{
			idc = 21205;
			text = "\x\addons\a3_epoch_code\Data\UI\hazzard_ca.paa";
			x = "0 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(profilenamespace getvariable [""IGUI_GRID_WEAPON_X"",		((safezoneX + safezoneW) - 		(12.4 * 			(			((safezoneW / safezoneH) min 1.2) / 40)) - 0.5 * 			(			((safezoneW / safezoneH) min 1.2) / 40))])";
			y = "0 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(profilenamespace getvariable [""IGUI_GRID_WEAPON_Y"",		(safezoneY + 0.5 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25))])";
			w = "2.5 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "2.5 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";

		};
		class icon6: custom_picture
		{
			idc = 21206;
			text = "\x\addons\a3_epoch_code\Data\UI\bleeding_ca.paa";
			x = "-2.5 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(profilenamespace getvariable [""IGUI_GRID_WEAPON_X"",		((safezoneX + safezoneW) - 		(12.4 * 			(			((safezoneW / safezoneH) min 1.2) / 40)) - 0.5 * 			(			((safezoneW / safezoneH) min 1.2) / 40))])";
			y = "0 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(profilenamespace getvariable [""IGUI_GRID_WEAPON_Y"",		(safezoneY + 0.5 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25))])";
			w = "2.5 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "2.5 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";

		};
	};
};

class EpochGameUI2
{
	idd = -3;
	duration = 10;
	onLoad = "uiNamespace setVariable ['EPOCH_EpochGameUI2', _this select 0];";
	class controls
	{

		class custom_picture : RscPicture
		{
			style = 48 + 0x800;
		};
		class icon1 : custom_picture
		{
			idc = 21207;
			text = "\x\addons\a3_epoch_code\Data\UI\cc_ca.paa";
			x = "0 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(profilenamespace getvariable [""IGUI_GRID_VEHICLE_X"",		(safezoneX + 0.5 * 			(			((safezoneW / safezoneH) min 1.2) / 40))])";
			y = "-2.1 * 			(		(		((safezoneW / safezoneH) min 1.2) / 1.2) / 20) + 			(safezoneY + safezoneH - 		(		((safezoneW / safezoneH) min 1.2) / 1.2)) +  			18 * 			(		(		((safezoneW / safezoneH) min 1.2) / 1.2) / 20) - (1 * 			(		(		((safezoneW / safezoneH) min 1.2) / 1.2) / 20))";
			w = "2.5 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "2.5 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";

		};
		class RscCryptoText : RscText
		{
			idc = 21208;
			text = "";
			colorText[] = { 1, 1, 1, 0.5 };
			shadow = 0;
			sizeEx = 0.08;
			x = "2.1 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(profilenamespace getvariable [""IGUI_GRID_VEHICLE_X"",		(safezoneX + 0.5 * 			(			((safezoneW / safezoneH) min 1.2) / 40))])";
			y = "-2.2 * 			(		(		((safezoneW / safezoneH) min 1.2) / 1.2) / 20) + 			(safezoneY + safezoneH - 		(		((safezoneW / safezoneH) min 1.2) / 1.2)) +  			18 * 			(		(		((safezoneW / safezoneH) min 1.2) / 1.2) / 20) - (1 * 			(		(		((safezoneW / safezoneH) min 1.2) / 1.2) / 20))";
			w = "15 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "2.5 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";

		};

	};
};

class EpochGameUI3
{
	idd = -4;
	duration = 10;
	onLoad = "uiNamespace setVariable ['EPOCH_EpochGameUI3', _this select 0];";
	class controls
	{

		class custom_picture : RscPicture
		{
			style = 48 + 0x800;
		};
		class icon1 : custom_picture
		{
			idc = 21209;
			text = "\x\addons\a3_epoch_code\Data\UI\battery_ca.paa";
			x = "0 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(profilenamespace getvariable [""IGUI_GRID_VEHICLE_X"",		(safezoneX + 0.5 * 			(			((safezoneW / safezoneH) min 1.2) / 40))])";
			y = "0 * 			(		(		((safezoneW / safezoneH) min 1.2) / 1.2) / 20) + 			(safezoneY + safezoneH - 		(		((safezoneW / safezoneH) min 1.2) / 1.2)) +  			18 * 			(		(		((safezoneW / safezoneH) min 1.2) / 1.2) / 20) - (1 * 			(		(		((safezoneW / safezoneH) min 1.2) / 1.2) / 20))";
			w = "2.5 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "2.5 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";

		};
		class RscEnergyText : RscText
		{
			idc = 21210;
			text = "";
			colorText[] = { 1, 1, 1, 0.5 };
			shadow = 0;
			sizeEx = 0.08;
			x = "2.1 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(profilenamespace getvariable [""IGUI_GRID_VEHICLE_X"",		(safezoneX + 0.5 * 			(			((safezoneW / safezoneH) min 1.2) / 40))])";
			y = "-0.1 * 			(		(		((safezoneW / safezoneH) min 1.2) / 1.2) / 20) + 			(safezoneY + safezoneH - 		(		((safezoneW / safezoneH) min 1.2) / 1.2)) +  			18 * 			(		(		((safezoneW / safezoneH) min 1.2) / 1.2) / 20) - (1 * 			(		(		((safezoneW / safezoneH) min 1.2) / 1.2) / 20))";
			w = "15 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "2.5 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";

		};
	};
};
class rmx_progressTest
{
	idd = 10200;
	duration = 999999;
	fadein = 0.5;
	fadeout = 0.5;
	onLoad = "uiNamespace setVariable ['rmx_var_progressTestDisplay',_this select 0]";
	
	class controls {};
};
class rmx_CraftingProgress
{
	idd = 10100;
	duration = 999999;
	fadein = 0.2;
	fadeout = 0.2;
	onLoad = "uiNamespace setVariable ['rmx_var_CraftingProgressDisplay',_this select 0]";
	
	class controls {};
};
class Default //use to delete title resources
{
	idd = -1;
	fadein = 0;
	fadeout = 0;
	duration = 0;
};