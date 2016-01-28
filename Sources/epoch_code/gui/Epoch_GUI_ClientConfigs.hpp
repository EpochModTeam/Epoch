/*
The x and y coords of the child control are relative to the parent class, the height and width are not
If the height and / or width of the child control are greater than the parent control then scrollbars will be seen
This allows the creation of scrollable active text controls etc
The entire child class needs to be defined in the parents subclass class Controls {};

External parent classes:
RscControlsGroup
RscControlsGroupNoScrollbars
RscControlsGroupNoHScrollbars

http://ru.armacomref.wikia.com/wiki/Dialog_Control
*/

/** ---- TEMPLATE ----
Copy the array part of text below, from $[ to ]
Open GUI editor in game and press CTRL + O
That's it!

Note: IDCs for groups are automatically generated, but not for the controls inside groups!
Note: x and y from the output should be set to 0!
 **/
/* #Xasyno
$[
	1.063,
	["interrupTemplate",[[0,0,1,1],0.025,0.04,"GUI_GRID"],0,0,0],
	[2300,"EpochConfigTemplateGROUP",[1,"",["0.29375 * safezoneW + safezoneX","0.225 * safezoneH + safezoneY","0.4135 * safezoneW","0.4202 * safezoneH"],[-1,-1,-1,-1],[-1,-1,-1,-1],[-1,-1,-1,-1],"","-1"],[]]
]
*/

/** Inherit from this template if confused **/
class Epoch_main_config_template: RscControlsGroup
{
	idc = -1;
	x = 0; //keep x and y absolute
	y = 0;
	w = 40 * GUI_GRID_W;
	h = 19.5 * GUI_GRID_H;
	class controls {};
};

class Epoch_main_config_changelog: Epoch_main_config_template
{
	w = 0.425 * safezoneW;

	onLoad = "((findDisplay 49) displayCtrl 71000) htmlLoad 'x\addons\a3_epoch_code\gui\changelog.html';";
	//onLoad = "((findDisplay 49) displayCtrl 71000) htmlLoad 'https://raw.githubusercontent.com/epochmodteam/epoch/test/changelog.html';";
	class controls
	{
		class Epoch_main_config_html: RscHtml //https://community.bistudio.com/wiki/DialogControls-Text#CT_HTML.3D9
		{
			idc = 71000;
			type = 9;
			style = 0x00;
			x = 0; //keep x and y absolute
			y = 0;
			w = 0.425 * safezoneW;
			h = 1.4 * safezoneH;
			filename = "changelog.html";
			text="test";

			colorText[] = {1,1,1,1.0};
			colorBold[] = {0.76,0.5,0.07,0.8};
			colorLink[] = {1,1,1,0.75};
			colorLinkActive[] = {1,1,1,1.0};

			colorBackground[] = {0.2,0.2,0.2,1};

			colorPicture[] = {1, 1, 1, 1};
			colorPictureBorder[] = {1, 0, 0, 1};
			colorPictureLink[] = {0, 0, 1, 1};
			colorPictureSelected[] = {0, 1, 0, 1};

			sizeEx = "(			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 1)";
			prevPage = "\A3\ui_f\data\gui\rsccommon\rschtml\arrow_left_ca.paa";
			nextPage = "\A3\ui_f\data\gui\rsccommon\rschtml\arrow_right_ca.paa";
			shadow = 2;
			class H1
			{
				font = "PuristaMedium";
				fontBold = "PuristaSemibold";
				sizeEx = "(			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 1.2)";
				align = "left";
			};
			class H2
			{
				font = "PuristaMedium";
				fontBold = "PuristaSemibold";
				sizeEx = "(			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 1)";
				align = "right";
			};
			class H3
			{
				font = "PuristaMedium";
				fontBold = "PuristaSemibold";
				sizeEx = "(			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 1)";
				align = "left";
			};
			class H4
			{
				font = "PuristaMedium";
				fontBold = "PuristaSemibold";
				sizeEx = "(			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 1)";
				align = "left";
			};
			class H5
			{
				font = "PuristaMedium";
				fontBold = "PuristaSemibold";
				sizeEx = "(			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 1)";
				align = "left";
			};
			class H6
			{
				font = "PuristaMedium";
				fontBold = "PuristaSemibold";
				sizeEx = "(			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 1)";
				align = "left";
			};
			class P
			{
				font = "PuristaMedium";
				fontBold = "PuristaSemibold";
				sizeEx = "(			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 1)";
				align = "left";
			};
		};
	};
};

/* #Tefyru
$[
	1.063,
	["asd",[[0,0,1,1],0.025,0.04,"GUI_GRID"],0,0,0],
	[-2300,"EpochConfigKeyMap",[1,"",["0.29375 * safezoneW + safezoneX","0.225 * safezoneH + safezoneY","0.237183 * safezoneW","0.308 * safezoneH"],[-1,-1,-1,-1],[-1,-1,-1,-1],[-1,-1,-1,-1],"","-1"],[]],
	[2200,"mainBG",[2300,"",["0 * safezoneW","1.63913e-008 * safezoneH","0.237183 * safezoneW","0.308 * safezoneH"],[-1,-1,-1,-1],[0.2,0.2,0.2,1],[-1,-1,-1,-1],"","-1"],[]],
	[2201,"IGUIBack_2202",[2300,"",["0.123747 * safezoneW","0.022 * safezoneH","0.103171 * safezoneW","0.022 * safezoneH"],[-1,-1,-1,-1],[0.76,0.5,0.07,0.8],[-1,-1,-1,-1],"","-1"],["idc = 2202;"]],
	[2202,"IGUIBack_2201",[2300,"",["0.0103125 * safezoneW","0.022 * safezoneH","0.103171 * safezoneW","0.022 * safezoneH"],[-1,-1,-1,-1],[0.76,0.5,0.07,0.8],[-1,-1,-1,-1],"","-1"],["idc = 2201;"]],
	[1000,"RscText_1001",[2300,"Assign a key:",["0.125811 * safezoneW","0.0264 * safezoneH","0.0989998 * safezoneW","0.0154  * safezoneH"],[-1,-1,-1,-1],[-1,-1,-1,-1],[-1,-1,-1,-1],"","-1"],["idc = 1001;"]],
	[1001,"RscText_1000",[2300,"Action:",["0.0123751 * safezoneW","0.0264 * safezoneH","0.0989997 * safezoneW","0.0154 * safezoneH"],[-1,-1,-1,-1],[-1,-1,-1,-1],[-1,-1,-1,-1],"","-1"],["idc = 1000;"]],
	[1002,"RscListbox_1500: RscListBox",[2300,"",["0.0103125 * safezoneW","0.044 * safezoneH","0.103125 * safezoneW","0.242 * safezoneH"],[-1,-1,-1,-1],[0,0,0,0.5],[-1,-1,-1,-1],"","-1"],["idc = 1500;"]],
	[1400,"RscEdit_1400",[2300,"",["0.124779 * safezoneW","0.154 * safezoneH","0.102093 * safezoneW","0.0242 * safezoneH"],[-1,-1,-1,-1],[-1,-1,-1,-1],[-1,-1,-1,-1],"","-1"],["idc = 1400;"]],
	[1003,"RscText_1002",[2300,"New Key:",["0.125809 * safezoneW","0.1364 * safezoneH","0.0989998 * safezoneW","0.0154 * safezoneH"],[-1,-1,-1,-1],[0,0,0,0],[-1,-1,-1,-1],"","-1"],["idc = 1002;"]],
	[1004,"RscText_1003",[2300,"Default:",["0.123747 * safezoneW","0.066 * safezoneH","0.103124 * safezoneW","0.022 * safezoneH"],[-1,-1,-1,-1],[0,0,0,0.5],[-1,-1,-1,-1],"","-1"],["idc = 1003;"]],
	[1700,"",[2300,"Save",["0.12684 * safezoneW","0.198 * safezoneH","0.0464063 * safezoneW","0.0308 * safezoneH"],[-1,-1,-1,-1],[-1,-1,-1,-1],[-1,-1,-1,-1],"","-1"],[]],
	[1701,"",[2300,"Reset",["0.17531 * safezoneW","0.198 * safezoneH","0.0484687 * safezoneW","0.0308 * safezoneH"],[-1,-1,-1,-1],[-1,-1,-1,-1],[-1,-1,-1,-1],"","-1"],[]],
	[2400,"",[2300,"Reset all keys",["0.123747 * safezoneW","0.264 * safezoneH","0.103125 * safezoneW","0.022 * safezoneH"],[-1,-1,-1,-1],[-1,-1,-1,-1],[-1,-1,-1,-1],"","-1"],[]],
	[1005,"",[2300,"Current:",["0.12375 * safezoneW","0.088 * safezoneH","0.103124 * safezoneW","0.022 * safezoneH"],[-1,-1,-1,-1],[0,0,0,0.5],[-1,-1,-1,-1],"","-1"],["idc = 1003;"]]
]
*/



class EpochConfigKeyMap: RscControlsGroupNoScrollbars
{
	x = 0;
	y = 0;
	w = 0.237183 * safezoneW;
	h = 0.308 * safezoneH;
	onLoad = "'load' call Epoch_config_keymap;";
	class controls
	{
		class rmx_eckm_BG: IGUIBack
		{
			idc = 78000;
			x = 0 * safezoneW;
			y = 0 * safezoneH;
			w = 0.237183 * safezoneW;
			h = 0.308 * safezoneH;
			colorBackground[] = {0.2,0.2,0.2,1};
		};
		class rmx_eckm_BG_assign: IGUIBack
		{
			idc = 78001;

			x = 0.123747 * safezoneW;
			y = 0.022 * safezoneH;
			w = 0.103171 * safezoneW;
			h = 0.022 * safezoneH;
			colorBackground[] = {0.76,0.5,0.07,0.8};
		};
		class rmx_eckm_BG_action: IGUIBack
		{
			idc = 78002;

			x = 0.0103125 * safezoneW;
			y = 0.022 * safezoneH;
			w = 0.103171 * safezoneW;
			h = 0.022 * safezoneH;
			colorBackground[] = {0.76,0.5,0.07,0.8};
		};
		class rmx_eckm_txt_assign: RscText
		{
			idc = 78003;

			text = "Assign a key:"; //--- ToDo: Localize;
			x = 0.125811 * safezoneW;
			y = 0.0264 * safezoneH;
			w = 0.0989998 * safezoneW;
			h = 0.0154  * safezoneH;
		};
		class rmx_eckm_txt_action: RscText
		{
			idc = 78004;

			text = "Action:"; //--- ToDo: Localize;
			x = 0.0123751 * safezoneW;
			y = 0.0264 * safezoneH;
			w = 0.0989997 * safezoneW;
			h = 0.0154 * safezoneH;
		};
		class rmx_eckm_txt_nk: RscText
		{
			idc = 78005;

			text = "New Key:"; //--- ToDo: Localize;
			x = 0.125809 * safezoneW;
			y = 0.1364 * safezoneH;
			w = 0.0989998 * safezoneW;
			h = 0.0154 * safezoneH;
			colorBackground[] = {0,0,0,0};
		};
		class rmx_eckm_txt_default: RscText
		{
			idc = 78006;

			text = "Default:"; //--- ToDo: Localize;
			x = 0.123747 * safezoneW;
			y = 0.066 * safezoneH;
			w = 0.103124 * safezoneW;
			h = 0.022 * safezoneH;
			colorBackground[] = {0,0,0,0.5};
		};
		class rmx_eckm_txt_current: RscText
		{
			idc = 78007;

			text = "Current:"; //--- ToDo: Localize;
			x = 0.12375 * safezoneW;
			y = 0.088 * safezoneH;
			w = 0.103124 * safezoneW;
			h = 0.022 * safezoneH;
			colorBackground[] = {0,0,0,0.5};
		};
		class rmx_eckm_lb: RscListBox
		{
			idc = 78008;

			x = 0.0103125 * safezoneW;
			y = 0.044 * safezoneH;
			w = 0.103125 * safezoneW;
			h = 0.242 * safezoneH;
			colorBackground[] = {0,0,0,0.5};
			onLBSelChanged = "_this call Epoch_config_keymap;";
		};
		class rmx_eckm_edit: RscEdit
		{
			idc = 78009;

			x = 0.124779 * safezoneW;
			y = 0.154 * safezoneH;
			w = 0.102093 * safezoneW;
			h = 0.0242 * safezoneH;
			onKeyUp = "_this call Epoch_config_keymap;";
		};
		class rmx_eckm_btn_save: RscShortcutButton
		{
			idc = 78010;
			text = "Save"; //--- ToDo: Localize;
			x = 0.12684 * safezoneW;
			y = 0.198 * safezoneH;
			w = 0.0464063 * safezoneW;
			h = 0.0308 * safezoneH;
			onMouseButtonClick = "_this call Epoch_config_keymap;";
		};
		class rmx_eckm_btn_reset: RscShortcutButton
		{
			idc = 78011;
			text = "Reset"; //--- ToDo: Localize;
			x = 0.17531 * safezoneW;
			y = 0.198 * safezoneH;
			w = 0.0484687 * safezoneW;
			h = 0.0308 * safezoneH;
			onMouseButtonClick = "_this call Epoch_config_keymap;";
		};
		class rmx_eckm_btn_resetall: RscButtonMenu
		{
			idc = 78012;
			text = "Reset all keys"; //--- ToDo: Localize;
			x = 0.123747 * safezoneW;
			y = 0.264 * safezoneH;
			w = 0.103125 * safezoneW;
			h = 0.022 * safezoneH;
			onMouseButtonClick = "_this call Epoch_config_keymap;";
		};
	};
};
