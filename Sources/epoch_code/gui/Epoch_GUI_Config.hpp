#include "\a3\functions_f\GUI\editor\GUI_styles.hpp"
class RscListbox;
class RscListNBox;
class RscButtonMenuOK;
class RscButtonMenuCancel;
class RscText;
class RscPicture;
class RscActiveText;
class RscCombo;
class RscProgress;
class RscButton;
class RscButtonMenu;
class RscShortcutButton;
class RscObject;
class RscStandardDisplay;
class RscStructuredText;
class RscControlsGroupNoScrollbars;
class RscHTML;
class RscEdit;
class RscTitle;
class RscVignette;
class RscFrame;
class RscControlsGroupNoHScrollbars;
class RscControlsGroup;
class RscIGProgress;
class RscHitZones;
class RscIGUIValue;
class RscIGUIText;
class RscPictureKeepAspect;
class RscUnitInfo;
class VScrollbar;
class HScrollbar;
class RscOpticsValue;
class RscOpticsText;
class RscLadderPicture;
class Attributes;
class RscDisplayGetReady;
class IGUIBack;
class CA_Title;
class ScrollBar;

#include "Epoch_GUI_ClientConfigs.hpp"
#include "Epoch_GUI_rmx.hpp"

class RscTitles 
{
	#include "Epoch_RscTitles.hpp"
};

class RscCustomProgress : RscProgress
{
	texture = "";
	textureExt = "";
	colorBar[] = { 0.9, 0.9, 0.9, 0.9 };
	colorExtBar[] = { 1, 1, 1, 1 };
	colorFrame[] = { 1, 1, 1, 1 };
	idc = 23868;
	x = "0 * 			(			((safezoneW / safezoneH) min 1.2) / 40)";
	y = "16 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
	w = "26 * 			(			((safezoneW / safezoneH) min 1.2) / 40)";
	h = "1 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
	colorBackground[] = { 1, 1, 1, 0.75 };
};

class SKN_RscEdit
{
	access = 0;
	type = 2;
	x = 0;
	y = 0;
	h = 0.04;
	w = 0.2;
	colorBackground[] = { 0, 0, 0, 1 };
	colorText[] = { 0.95, 0.95, 0.95, 1 };
	colorDisabled[] = { 1, 1, 1, 0.25 };
	colorSelection[] = { "(profilenamespace getvariable ['GUI_BCG_RGB_R',0.69])", "(profilenamespace getvariable ['GUI_BCG_RGB_G',0.75])", "(profilenamespace getvariable ['GUI_BCG_RGB_B',0.5])", 1 };
	autocomplete = "";
	text = "";
	size = 0.2;
	style = "0x00 + 0x40";
	font = "PuristaMedium";
	shadow = 2;
	sizeEx = "(			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 1)";
	canModify = 1;
	tooltipColorText[] = { 1, 1, 1, 1 };
	tooltipColorBox[] = { 1, 1, 1, 1 };
	tooltipColorShade[] = { 0, 0, 0, 0.65 };
};

/*
class TradeRequest
{
	idd = -1;
	duration = -1;
	class controls
	{
		class RscPicture_1201: RscPicture
		{
			idc = 1201;
			text = "#(argb,8,8,3)color(0,0,0,0.5)";
			x = 0.425497 * safezoneW + safezoneX;
			y = 0.720018 * safezoneH + safezoneY;
			w = 0.149006 * safezoneW;
			h = 0.0550046 * safezoneH;
		};
		class RscButtonMenu_2403: RscButtonMenu
		{
			idc = 2403;
			text = "Accept Trade Request";
			x = 0.431228 * safezoneW + safezoneX;
			y = 0.731019 * safezoneH + safezoneY;
			w = 0.137544 * safezoneW;
			h = 0.0330028 * safezoneH;
			action = "call EPOCH_startTrade";
		};
	};
};
*/

class QuickUpgrade
{
	idd = -15;
	duration = -1;
	onload = "setMousePosition [0.5, 0.5];";
	class controls
	{
		class quick_take_bg : IGUIBack
		{
			idc = 2201;
			x = 0.411875 * safezoneW + safezoneX;
			y = 0.264874 * safezoneH + safezoneY;
			w = 0.17625 * safezoneW;
			h = 0.470252 * safezoneH;
		};
		class RscListbox_1500: RscListbox
		{
			idc = 1500;
			style = LB_MULTI;
			sizeEx = "0.8 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			sizeEx2 = "0.8 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			rowHeight = "2 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			canDrag = 1;
			colorText[] = { 1, 1, 1, 1 };
			colorBackground[] = { 0, 0, 0, 0 };
			itemBackground[] = { 1, 1, 1, 0.1 };
			itemSpacing = 0.001;
			x = 0.431458 * safezoneW + safezoneX;
			y = 0.330709 * safezoneH + safezoneY;
			w = 0.127292 * safezoneW;
			h = 0.291556 * safezoneH;
		};
		class RscButtonMenuCancel_2700: RscButtonMenuCancel
		{
			x = 0.504896 * safezoneW + safezoneX;
			y = 0.622266 * safezoneH + safezoneY;
			w = 0.0538542 * safezoneW;
			h = 0.0282151 * safezoneH;
		};
		class RscButtonMenu_2400: RscButtonMenu
		{
			idc = 2400;
			text = "Upgrade"; //--- ToDo: Localize;
			x = 0.431458 * safezoneW + safezoneX;
			y = 0.622266 * safezoneH + safezoneY;
			w = 0.05875 * safezoneW;
			h = 0.0282151 * safezoneH;
			action = "cursorTarget call EPOCH_upgradeBUILDv2";
		};

	};
};

class QuickTake
{
	idd = -5;
	duration = -1;
	onload = "setMousePosition [0.5, 0.5];";
	class controls
	{
		class quick_take_bg : IGUIBack
		{
			idc = 2201;
			x = 0.411875 * safezoneW + safezoneX;
			y = 0.264874 * safezoneH + safezoneY;
			w = 0.17625 * safezoneW;
			h = 0.470252 * safezoneH;
		};

		class GroundContainer : RscListBox
		{
			idc = 1500;
			style = LB_MULTI;
			sizeEx = "0.8 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			sizeEx2 = "0.8 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			rowHeight = "2 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			canDrag = 1;
			colorText[] = { 1, 1, 1, 1 };
			colorBackground[] = { 0, 0, 0, 0 };
			itemBackground[] = { 1, 1, 1, 0.1 };
			itemSpacing = 0.001;
			x = 0.416771 * safezoneW + safezoneX;
			y = 0.274279 * safezoneH + safezoneY;
			w = 0.166458 * safezoneW;
			h = 0.413822 * safezoneH;
		};
		/*
		class Take_Btn : RscButtonMenu
		{
			idc = 2400;
			text = "Take";
			x = 0.416771 * safezoneW + safezoneX;
			y = 0.697506 * safezoneH + safezoneY;
			w = 0.0489583 * safezoneW;
			h = 0.0282151 * safezoneH;
			action = "call EPOCH_QuickTake";
		};
		*/
		class RscButtonMenu_2401 : RscButtonMenu
		{
			idc = 2401;
			text = "Take All";
			x = 0.534271 * safezoneW + safezoneX;
			y = 0.697506 * safezoneH + safezoneY;
			w = 0.0489583 * safezoneW;
			h = 0.0282151 * safezoneH;
			action = "call EPOCH_QuickTakeAll";
		};
	};
};


class TapOut
{
	idd = -6;
	duration = -1;
	onload = "setMousePosition [0.5, 0.5];";
	class controls
	{
		class RscText_1000: RscText
		{
			idc = 1000;
			text = "Vital signs critical";
			x = 0.392292 * safezoneW + safezoneX;
			y = 0.46238 * safezoneH + safezoneY;
			w = 0.381875 * safezoneW;
			h = 0.0564303 * safezoneH;
			colorBackground[] = {0,0,0,0};
			 colorText[] = {1,1,1,0.7};
			shadow = 0;
			sizeEx = 0.08;
		};
		class RscPicture_1200: RscPicture
		{
			idc = 1200;
			style = 48 + 0x800;
			text = "\x\addons\a3_epoch_code\Data\UI\heart_ca.paa";
			x = 0.568542 * safezoneW + safezoneX;
			y = 0.434165 * safezoneH + safezoneY;
			w = 0.078125 * safezoneW;
			h = 0.131671 * safezoneH;
		};

		class tapout : RscButton
		{
			idc = 1600;
			text = "Respawn";
			x = 0.436354 * safezoneW + safezoneX;
			y = 0.631671 * safezoneH + safezoneY;
			w = 0.127292 * safezoneW;
			h = 0.0376202 * safezoneH;
			action = "(findDisplay 46) closeDisplay 0;";
			onKeyDown = "if (_this select 1 == 0x01) then {(findDisplay 46) closeDisplay 0;};";
		};
	};
};



class SelectGender
{
	idd = -7;
	duration = -1;
	onload = "setMousePosition [0.5, 0.5];";
	class controls
	{
		class RscText_PickYourGender : RscText
		{
			idc = 1000;
			text = "Select your gender:";
			x = 0.2875;
			y = 0;
			w = 0.5125;
			h = 0.12;
			colorBackground[] = { 0, 0, 0, 0 };
			colorText[] = { 1, 1, 1, 0.7 };
			shadow = 0;
			sizeEx = 0.08;
		};
		class RscButtonMenu_Male : RscButtonMenu
		{
			idc = 2401;
			text = "Male";
			x = 0.3875;
			y = 0.52;
			w = 0.1125;
			h = 0.08;
			action = "closeDialog 0; EPOCH_PlayerIsMale = true;";
		};
		class RscButtonMenu_Female : RscButtonMenu
		{
			idc = 2403;
			text = "Female";
			x = 0.5125;
			y = 0.52;
			w = 0.1125;
			h = 0.08;
			action = "closeDialog 0; EPOCH_PlayerIsMale = false;";
		};
	};
};

class TradeNPCMenu
{
	idd = -8;
	duration = -1;
	onload = "setMousePosition [0.5, 0.5];";
	class controls
	{
		class RscPicture_1203 : RscPicture
		{
			idc = 1203;
			text = "\x\addons\a3_epoch_code\data\UI\UIBG_ca.paa";
			x = 0.460833 * safezoneW + safezoneX;
			y = 0.142608 * safezoneH + safezoneY;
			w = 0.279063 * safezoneW;
			h = 0.526683 * safezoneH;
		};
		class RscPicture_1201 : RscPicture
		{
			idc = 1201;
			text = "\x\addons\a3_epoch_code\data\UI\UIBG_ca.paa";
			x = 0.460833 * safezoneW + safezoneX;
			y = 0.51881 * safezoneH + safezoneY;
			w = 0.279063 * safezoneW;
			h = 0.291556 * safezoneH;
		};
		class RscPicture_1202 : RscPicture
		{
			idc = 1202;
			text = "\x\addons\a3_epoch_code\data\UI\UIBG_ca.paa";
			x = 0.260104 * safezoneW + safezoneX;
			y = 0.142608 * safezoneH + safezoneY;
			w = 0.279063 * safezoneW;
			h = 0.526683 * safezoneH;
		};
		class RscPicture_1200 : RscPicture
		{
			idc = 1200;
			text = "\x\addons\a3_epoch_code\data\UI\UIBG_ca.paa";
			x = 0.260104 * safezoneW + safezoneX;
			y = 0.51881 * safezoneH + safezoneY;
			w = 0.279063 * safezoneW;
			h = 0.291556 * safezoneH;
		};

		class RscCombo_2100: RscCombo
		{
				idc = 42100;
				x = 0.377604 * safezoneW + safezoneX;
				y = 0.227254 * safezoneH + safezoneY;
				w = 0.1175 * safezoneW;
				h = 0.0188101 * safezoneH;
				onLBSelChanged = "_this call EPOCH_NPCTraderMenuFilter";
		};
		class RscCombo_2101: RscCombo
		{
				idc = 42101;
				x = 0.578333 * safezoneW + safezoneX;
				y = 0.227254 * safezoneH + safezoneY;
				w = 0.0979167 * safezoneW;
				h = 0.0188101 * safezoneH;
				onLBSelChanged = "_this call EPOCH_NPCTraderMenuFilter";
		};
		class RscListbox_playerInventory: RscListbox
		{
				idc = 41500;
				x = 0.304167 * safezoneW + safezoneX;
				y = 0.264874 * safezoneH + safezoneY;
				w = 0.190937 * safezoneW;
				h = 0.282151 * safezoneH;
				onLBDblClick = "[41501,_this] call EPOCH_npcTraderAdd";
				onLBDrop = "[41501,_this] call EPOCH_npcTraderAdd";
		};
		class RscListbox_playerOffer: RscListbox
		{
				idc = 41501;
				x = 0.304167 * safezoneW + safezoneX;
				y = 0.584645 * safezoneH + safezoneY;
				w = 0.190937 * safezoneW;
				h = 0.150481 * safezoneH;
				onLBDblClick = "[41500,_this] call EPOCH_npcTraderAdd";
				onLBDrop = "[41500,_this] call EPOCH_npcTraderAdd";
		};
		class RscListbox_npcOffer: RscListbox
		{
				idc = 41502;
				x = 0.504896 * safezoneW + safezoneX;
				y = 0.584645 * safezoneH + safezoneY;
				w = 0.190937 * safezoneW;
				h = 0.150481 * safezoneH;
				onLBDblClick = "[41503,_this] call EPOCH_npcTraderAdd3";
				onLBDrop = "[41503,_this] call EPOCH_npcTraderAdd3";
		};
		class RscListbox_npcInventory : RscListNBox
		{
			idc = 41503;
			columns[] = { 0.1, 0, 0.2 };

			colorPicture[] = { 1, 1, 1, 1 };
			colorPictureSelected[] = { 1, 1, 1, 1 };
			colorPictureDisabled[] = { 1, 1, 1, 1 };

			// canDrag = 1;
			//colorText[] = { 1, 1, 1, 1 };
			//colorBackground[] = { 0, 0, 0, 0.7 };
			//itemBackground[] = { 1, 1, 1, 0.1 };

			/*
			x = "1.5 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(safezoneX + (safezoneW - 					((safezoneW / safezoneH) min 1.2))/2)";
			y = "3.7 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(safezoneY + (safezoneH - 					(			((safezoneW / safezoneH) min 1.2) / 1.2))/2)";
			w = "11 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "18.4 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			*/
			x = 0.504896 * safezoneW + safezoneX;
			y = 0.255469 * safezoneH + safezoneY;
			w = 0.190937 * safezoneW;
			h = 0.282151 * safezoneH;

			onLBDblClick = "[41502,_this] call EPOCH_npcTraderAdd2";
			onLBDrop = "[41502,_this] call EPOCH_npcTraderAdd2";
	};

		class RscText_1000: RscText
		{
				idc = -1;
				text = "INVENTORY";
				x = 0.304167 * safezoneW + safezoneX;
				y = 0.227254 * safezoneH + safezoneY;
				w = 0.0783333 * safezoneW;
				h = 0.0188101 * safezoneH;
		};
		class RscText_1001: RscText
		{
				idc = -1;
				text = "SELLING";
				x = 0.304167 * safezoneW + safezoneX;
				y = 0.55643 * safezoneH + safezoneY;
				w = 0.0783333 * safezoneW;
				h = 0.0188101 * safezoneH;
		};
		class RscText_1002: RscText
		{
				idc = -1;
				text = "BUYING";
				x = 0.5 * safezoneW + safezoneX;
				y = 0.55643 * safezoneH + safezoneY;
				w = 0.0783333 * safezoneW;
				h = 0.0188101 * safezoneH;
		};
		class RscText_1003: RscText
		{
				idc = -1;
				text = "VENDOR ITEMS";
				x = 0.504896 * safezoneW + safezoneX;
				y = 0.227254 * safezoneH + safezoneY;
				w = 0.0783333 * safezoneW;
				h = 0.0188101 * safezoneH;
		};
		class RscText_1004: RscText
		{
				idc = 41004;
				text = "0 Krypto";
				x = 0.377604 * safezoneW + safezoneX;
				y = 0.55643 * safezoneH + safezoneY;
				w = 0.112604 * safezoneW;
				h = 0.0188101 * safezoneH;
		};
		class RscText_1005: RscText
		{
				idc = 41005;
				text = "0 Krypto";
				x = 0.583229 * safezoneW + safezoneX;
				y = 0.55643 * safezoneH + safezoneY;
				w = 0.112604 * safezoneW;
				h = 0.0188101 * safezoneH;
		};
		class RscButtonMenu_2400: RscButtonMenu
		{
				idc = 42400;
				text = "TRADE";
				x = 0.480417 * safezoneW + safezoneX;
				y = 0.763341 * safezoneH + safezoneY;
				w = 0.0391667 * safezoneW;
				h = 0.0282151 * safezoneH;
				action = "cursorTarget call EPOCH_startNpcTrade";
		};
		/*/
		class RscButtonMenu_2401: RscButtonMenu
		{
				idc = 42401;
				text = "BUY";
				x = 0.545707;
				y = 0.929495;
				w = 0.0987372;
				h = 0.0534678;
				action = "cursorTarget call EPOCH_startNpcTrade";
		};
		*/
		class RscButtonMenuCancel_2700: RscButtonMenuCancel
		{
			idc = -1;
			text = "X";
			x = 0.681146 * safezoneW + safezoneX;
			y = 0.227254 * safezoneH + safezoneY;
			w = 0.0146875 * safezoneW;
			h = 0.0188101 * safezoneH;
			action = "closeDialog 0";
		};

	};

};

/*
class RscEpochObjectUI: RscStandardDisplay
{
	idd = -9;
	class objects
	{
		class TestObject: RscObject
		{
			type = 82;
			idc = -1;
			scale = 1;

			model = "\x\addons\a3_epoch_assets_3\CfgVehicles\center_plane.p3d";

			position[] = {0,0,1.15};
			positionBack[] = {0,0,1.15};
			inBack = 0;
			enableZoom = 1;
			zoomDuration = 0.5;
			direction[] = {0,0,1};
			up[] = {0,1,0};
			class Areas
			{
				class UsertextureL
				{
					selection = "usertextureL";
					class controls
					{
						class Test: RscText
						{
							text = "Schnobble";
							idc = 4201;
							sizeEx = 0.1;
							colorText[] = {0,1,0,1};
							colorBackground[] = {0,0,0,0};
							x = 0;
							y = 0;
							w = 1;
							h = 0.1;
							shadow = 0;
						};
						class EPOCH_playerTemp: RscText
						{
							text = "Temp";
							idc = 4202;
							sizeEx = 0.1;
							colorText[] = {0,1,0,1};
							colorBackground[] = {0,0,0,0};
							x = 0;
							y = 0.1;
							w = 1;
							h = 0.1;
							shadow = 0;
						};
						class EPOCH_playerHunger: RscText
						{
							text = "Hunger";
							idc = 4203;
							sizeEx = 0.1;
							colorText[] = {0,1,0,1};
							colorBackground[] = {0,0,0,0};
							x = 0;
							y = 0.2;
							w = 1;
							h = 0.1;
							shadow = 0;
						};
						class EPOCH_playerThirst: RscText
						{
							text = "Thirst";
							idc = 4204;
							sizeEx = 0.1;
							colorText[] = {0,1,0,1};
							colorBackground[] = {0,0,0,0};
							x = 0;
							y = 0.3;
							w = 1;
							h = 0.1;
							shadow = 0;
						};
						class EPOCH_playerEnergy: RscText
						{
							text = "Energy";
							idc = 4205;
							sizeEx = 0.1;
							colorText[] = {0,1,0,1};
							colorBackground[] = {0,0,0,0};
							x = 0;
							y = 0.4;
							w = 1;
							h = 0.1;
							shadow = 0;
						};
						class Picture: RscPicture
						{
							idc = 4206;
							text = "";
							x = 0;
							y = 0.5;
							w = 0.5;
							h = 0.5;
						};
					};
				};
				class Usertexture
				{
					selection = "usertexture";
					class controls
					{
						class Test: RscText
						{
							text = "";
							idc = 4207;
							sizeEx = 0.07;
							colorText[] = {0,1,0,1};
							colorBackground[] = {1,0,0,1};
							x = 0;
							y = 0;
							w = 1;
							h = 0.1;
							shadow = 0;
						};
						class EPOCH_playerTemp: RscText
						{
							text = "";
							idc = 4208;
							sizeEx = 0.07;
							colorText[] = {0,1,0,1};
							colorBackground[] = {0,0,0,0};
							x = 0;
							y = 0.1;
							w = 1;
							h = 0.1;
							shadow = 0;
						};
						class EPOCH_playerHunger: RscText
						{
							text = "";
							idc = 4209;
							sizeEx = 0.07;
							colorText[] = {0,1,0,1};
							colorBackground[] = {0,0,0,0};
							x = 0;
							y = 0.2;
							w = 1;
							h = 0.1;
							shadow = 0;
						};
						class EPOCH_playerThirst: RscText
						{
							text = "";
							idc = 4210;
							sizeEx = 0.07;
							colorText[] = {0,1,0,1};
							colorBackground[] = {0,0,0,0};
							x = 0;
							y = 0.3;
							w = 1;
							h = 0.1;
							shadow = 0;
						};
						class EPOCH_playerEnergy: RscText
						{
							text = "";
							idc = 4211;
							sizeEx = 0.07;
							colorText[] = {0,1,0,1};
							colorBackground[] = {0,0,0,0};
							x = 0;
							y = 0.4;
							w = 1;
							h = 0.1;
							shadow = 0;
						};
						class Picture: RscPicture
						{
							idc = 4212;
							text = "";
							x = 0;
							y = 0.5;
							w = 0.5;
							h = 0.5;
						};
					};
				};
				class UsertextureR
				{
					selection = "usertextureR";
					class controls
					{
						class Test: RscText
						{
							text = "";
							idc = 4213;
							sizeEx = 0.1;
							colorText[] = {0,1,0,1};
							colorBackground[] = {0,0,1,1};
							x = 0;
							y = 0;
							w = 1;
							h = 0.1;
							shadow = 0;
						};
						class EPOCH_playerTemp: RscText
						{
							text = "";
							idc = 4214;
							sizeEx = 0.1;
							colorText[] = {0,1,0,1};
							colorBackground[] = {0,0,0,0};
							x = 0;
							y = 0.1;
							w = 1;
							h = 0.1;
							shadow = 0;
						};
						class EPOCH_playerHunger: RscText
						{
							text = "";
							idc = 4215;
							sizeEx = 0.1;
							colorText[] = {0,1,0,1};
							colorBackground[] = {0,0,0,0};
							x = 0;
							y = 0.2;
							w = 1;
							h = 0.1;
							shadow = 0;
						};
						class EPOCH_playerThirst: RscText
						{
							text = "";
							idc = 4216;
							sizeEx = 0.1;
							colorText[] = {0,1,0,1};
							colorBackground[] = {0,0,0,0};
							x = 0;
							y = 0.3;
							w = 1;
							h = 0.1;
							shadow = 0;
						};
						class EPOCH_playerEnergy: RscText
						{
							text = "";
							idc = 4217;
							sizeEx = 0.1;
							colorText[] = {0,1,0,1};
							colorBackground[] = {0,0,0,0};
							x = 0;
							y = 0.4;
							w = 1;
							h = 0.1;
							shadow = 0;
						};
						class Picture: RscPicture
						{
							idc = 4218;
							text = "";
							x = 0;
							y = 0.5;
							w = 0.5;
							h = 0.5;
						};
					};
				};
			};
		};
	};
};


class Interact
{
	idd = -9;
	duration = -1;
	onload = "setMousePosition [0.5, 0.5];";
	//onLoad = "";
	class controls
	{
		class interactive_box: RscListbox
		{
			idc = 1700;
			x = 0.15;
			y = 0.46;
			w = 0.6;
			h = 0.04;
			onLBDblClick = "_this call EPOCH_Interface_interact";
		};
		class interactive_cancel: RscButtonMenuCancel
		{
			x = 0.7625;
			y = 0.46;
			w = 0.1;
			h = 0.04;
		};
	};
};

*/

class GroupRequests
{
	idd = -1500;
	duration = -1;
	onLoad = "setMousePosition [0.5, 0.5]; [] spawn { uiSleep 0.5; waitUntil {_this call EPOCH_iGroup_refresh; uiSleep 1; isNull (findDisplay -1500)};}";
	class controls
	{
		class IGUIBack_2200 : IGUIBack
		{
			idc = 2200;
			x = 0.304167 * safezoneW + safezoneX;
			y = 0.264874 * safezoneH + safezoneY;
			w = 0.391667 * safezoneW;
			h = 0.470252 * safezoneH;
		};
		class RscListbox_1500 : RscListbox
		{
			idc = 1500;
			x = 0.309062 * safezoneW + safezoneX;
			y = 0.311899 * safezoneH + safezoneY;
			w = 0.381875 * safezoneW;
			h = 0.376202 * safezoneH;
			onLBSelChanged = "missionNamespace setVariable [""Epoch_invited_GroupUID"",(_this select 0) lbData (_this select 1)]; missionNamespace setVariable [""Epoch_invited_GroupName"",(_this select 0) lbText (_this select 1)];";
		};
		class RscButtonMenu_2400 : RscButtonMenu
		{
			idc = 2400;
			text = "ACCEPT";
			x = 0.304167 * safezoneW + safezoneX;
			y = 0.697506 * safezoneH + safezoneY;
			w = 0.0832292 * safezoneW;
			h = 0.0376202 * safezoneH;
			action = "if ((lbCurSel 1500) >= 0) then { call EPOCH_iGroup_acceptInvite; Epoch_invited_GroupUIDs deleteAt (lbCurSel 1500); closeDialog 0;};";
		};
		class RscButtonMenu_2401 : RscButtonMenu
		{
			idc = 2401;
			text = "CANCEL";
			x = 0.612604 * safezoneW + safezoneX;
			y = 0.697506 * safezoneH + safezoneY;
			w = 0.0832292 * safezoneW;
			h = 0.0376202 * safezoneH;
			action = "closeDialog 0";
		};
		class RscText_1000 : RscText
		{
			idc = 1000;
			text = "Group requests";
			x = 0.309062 * safezoneW + safezoneX;
			y = 0.274279 * safezoneH + safezoneY;
			w = 0.0685417 * safezoneW;
			h = 0.0376202 * safezoneH;
		};
		class RscButtonMenu_2402 : RscButtonMenu
		{
			idc = 2402;
			text = "REMOVE";
			x = 0.387396 * safezoneW + safezoneX;
			y = 0.697506 * safezoneH + safezoneY;
			w = 0.0832292 * safezoneW;
			h = 0.0376202 * safezoneH;
			action = "if ((lbCurSel 1500) >= 0) then {Epoch_invited_GroupUIDs deleteAt (lbCurSel 1500); }; ";
		};
		class RscButtonMenu_2403 : RscButtonMenu
		{
			idc = 2403;
			text = "CLEAR ALL";
			x = 0.470625 * safezoneW + safezoneX;
			y = 0.697506 * safezoneH + safezoneY;
			w = 0.0832292 * safezoneW;
			h = 0.0376202 * safezoneH;
			action = "Epoch_invited_GroupUIDs = [];";
		};
	};
};


/*
class Crafting
{
	idd = 419999;
	duration = -1;
	//onLoad = "";
	class controls
	{
		class RscButtonMenuCancel_2700: RscButtonMenuCancel
		{
			x = 0.9;
			y = 0.9;
			w = 0.1;
			h = 0.1;
		};
		class RscListNBox_1557: RscListNBox
		{
			idc = 1557;
			x = 0;
			y = 0;
			w = 0.9;
			h = 1;
			canDrag=true;
			rows=10;
			lineSpacing = 1.3;
		};
	};
};
*/

class CraftItem
{
	idd = -10;
	duration = -1;
	onload = "setMousePosition [0.5, 0.5];";
	//onLoad = "";
	class controls
	{

		class CraftButton : RscButton
		{
			idc = 1600;
			text = "CRAFT";
			x = 0.654739 * safezoneW + safezoneX;
			y = 0.728222 * safezoneH + safezoneY;
			w = 0.04125 * safezoneW;
			h = 0.033 * safezoneH;
			action = "call EPOCH_craftItem;";
		};


		class CraftQuantity : RscText
		{
			idc = 1000;
			text = "QTY";
			x = 0.588546 * safezoneW + safezoneX;
			y = 0.729102 * safezoneH + safezoneY;
			w = 0.020625 * safezoneW;
			h = 0.022 * safezoneH;
		};
		class Quantity : RscCombo
		{
			idc = 2100;
			x = 0.611771 * safezoneW + safezoneX;
			y = 0.732842 * safezoneH + safezoneY;
			w = 0.0360937 * safezoneW;
			h = 0.022 * safezoneH;
		};



		class isof1 : RscText
		{
			idc = 1001;
			text = "";
			x = 0.515469 * safezoneW + safezoneX;
			y = 0.577 * safezoneH + safezoneY;
			w = 0.0515625 * safezoneW;
			h = 0.022 * safezoneH;
		};
		class isof2 : RscText
		{
			idc = 1002;
			text = "";
			x = 0.5825 * safezoneW + safezoneX;
			y = 0.577 * safezoneH + safezoneY;
			w = 0.0515625 * safezoneW;
			h = 0.022 * safezoneH;
		};
		class isof3 : RscText
		{
			idc = 1003;
			text = "";
			x = 0.649531 * safezoneW + safezoneX;
			y = 0.577 * safezoneH + safezoneY;
			w = 0.0515625 * safezoneW;
			h = 0.022 * safezoneH;
		};
		class isof4 : RscText
		{
			idc = 1004;
			text = "";
			x = 0.515469 * safezoneW + safezoneX;
			y = 0.698 * safezoneH + safezoneY;
			w = 0.0515625 * safezoneW;
			h = 0.022 * safezoneH;
		};
		class isof5 : RscText
		{
			idc = 1005;
			text = "";
			x = 0.5825 * safezoneW + safezoneX;
			y = 0.698 * safezoneH + safezoneY;
			w = 0.0515625 * safezoneW;
			h = 0.022 * safezoneH;
		};
		class isof6 : RscText
		{
			idc = 1006;
			text = "";
			x = 0.649531 * safezoneW + safezoneX;
			y = 0.698 * safezoneH + safezoneY;
			w = 0.0515625 * safezoneW;
			h = 0.022 * safezoneH;
		};


		class bBox1 : RscPicture
		{
			idc = 1200;
			x = 0.515469 * safezoneW + safezoneX;
			y = 0.489 * safezoneH + safezoneY;
			w = 0.0515625 * safezoneW;
			h = 0.088 * safezoneH;
		};
		class bBox2 : RscPicture
		{
			idc = 1201;
			x = 0.5825 * safezoneW + safezoneX;
			y = 0.489 * safezoneH + safezoneY;
			w = 0.0515625 * safezoneW;
			h = 0.088 * safezoneH;
		};
		class bBox3 : RscPicture
		{
			idc = 1202;
			x = 0.649531 * safezoneW + safezoneX;
			y = 0.489 * safezoneH + safezoneY;
			w = 0.0515625 * safezoneW;
			h = 0.088 * safezoneH;
		};
		class bBox4 : RscPicture
		{
			idc = 1203;
			x = 0.515469 * safezoneW + safezoneX;
			y = 0.61 * safezoneH + safezoneY;
			w = 0.0515625 * safezoneW;
			h = 0.088 * safezoneH;
		};
		class bBox5 : RscPicture
		{
			idc = 1204;
			x = 0.5825 * safezoneW + safezoneX;
			y = 0.61 * safezoneH + safezoneY;
			w = 0.0515625 * safezoneW;
			h = 0.088 * safezoneH;
		};
		class bBox6 : RscPicture
		{
			idc = 1205;
			x = 0.649531 * safezoneW + safezoneX;
			y = 0.61 * safezoneH + safezoneY;
			w = 0.0515625 * safezoneW;
			h = 0.088 * safezoneH;
		};

		class s1: RscPicture
		{
			idc = 41200;
			x = 0.515469 * safezoneW + safezoneX;
			y = 0.489 * safezoneH + safezoneY;
			w = 0.0515625 * safezoneW;
			h = 0.088 * safezoneH;
		};
		class s2: RscPicture
		{
			idc = 41201;
			x = 0.5825 * safezoneW + safezoneX;
			y = 0.489 * safezoneH + safezoneY;
			w = 0.0515625 * safezoneW;
			h = 0.088 * safezoneH;
		};
		class s3: RscPicture
		{
			idc = 41202;
			x = 0.649531 * safezoneW + safezoneX;
			y = 0.489 * safezoneH + safezoneY;
			w = 0.0515625 * safezoneW;
			h = 0.088 * safezoneH;
		};
		class s4: RscPicture
		{
			idc = 41203;
			x = 0.515469 * safezoneW + safezoneX;
			y = 0.61 * safezoneH + safezoneY;
			w = 0.0515625 * safezoneW;
			h = 0.088 * safezoneH;
		};
		class s5: RscPicture
		{
			idc = 41204;
			x = 0.5825 * safezoneW + safezoneX;
			y = 0.61 * safezoneH + safezoneY;
			w = 0.0515625 * safezoneW;
			h = 0.088 * safezoneH;
		};
		class s6: RscPicture
		{
			idc = 41205;
			x = 0.649531 * safezoneW + safezoneX;
			y = 0.61 * safezoneH + safezoneY;
			w = 0.0515625 * safezoneW;
			h = 0.088 * safezoneH;
		};




		/*
		class bBtn1 : RscPicture
		{
		idc = 1213;
		x = 0.515469 * safezoneW + safezoneX;
		y = 0.489 * safezoneH + safezoneY;
		w = 0.0515625 * safezoneW;
		h = 0.088 * safezoneH;
		};
		class bBtn2 : RscPicture
		{
		idc = 1214;
		x = 0.5825 * safezoneW + safezoneX;
		y = 0.489 * safezoneH + safezoneY;
		w = 0.0515625 * safezoneW;
		h = 0.088 * safezoneH;
		};
		class bBtn3 : RscPicture
		{
		idc = 1215;
		x = 0.649531 * safezoneW + safezoneX;
		y = 0.489 * safezoneH + safezoneY;
		w = 0.0515625 * safezoneW;
		h = 0.088 * safezoneH;
		};
		class bBtn4 : RscPicture
		{
		idc = 1216;
		x = 0.515469 * safezoneW + safezoneX;
		y = 0.61 * safezoneH + safezoneY;
		w = 0.0515625 * safezoneW;
		h = 0.088 * safezoneH;
		};
		class bBtn5 : RscPicture
		{
		idc = 1217;
		x = 0.5825 * safezoneW + safezoneX;
		y = 0.61 * safezoneH + safezoneY;
		w = 0.0515625 * safezoneW;
		h = 0.088 * safezoneH;
		};
		class bBtn6 : RscPicture
		{
		idc = 1218;
		x = 0.649531 * safezoneW + safezoneX;
		y = 0.61 * safezoneH + safezoneY;
		w = 0.0515625 * safezoneW;
		h = 0.088 * safezoneH;
		};
		*/

	};
};


class InteractVehicle
{
	idd = -11;
	duration = -1;
	onLoad = "setMousePosition [0.5, 0.5]; [""onLoad"",_this select 0] call Epoch_interactVehicle;";
	class controls
	{
		class RscButtonMenu_2400: RscButtonMenu
		{
			idc = 2400;
			text = "Lock";
			x = 0.3875;
			y = 0.42;
			w = 0.1125;
			h = 0.08;
			action = "[""Lock""] call Epoch_interactVehicle";
		};
		class RscButtonMenu_2401: RscButtonMenu
		{
			idc = 2401;
			text = "Unlock";
			x = 0.5125;
			y = 0.42;
			w = 0.1125;
			h = 0.08;
			action = "[""Unlock""] call Epoch_interactVehicle";
		};
		class RscButtonMenu_2402: RscButtonMenu
		{
			idc = 2402;
			text = "Inspect";
			x = 0.3875;
			y = 0.52;
			w = 0.1125;
			h = 0.08;
			action = "call Epoch_client_gearVehicle";
		};
		class RscButtonMenu_2403: RscButtonMenu
		{
			idc = 2403;
			text = "Cancel";
			x = 0.5125;
			y = 0.52;
			w = 0.1125;
			h = 0.08;
			action = "closeDialog 0";
		};
	};
};

/*
class InteractPlayer
{
	idd = 420002;
	duration = -1;
	//onLoad = "";
	class controls
	{
		class RscButtonMenu_2401: RscButtonMenu
		{
			idc = 2401;
			text = "Trade";
			x = 0.3875;
			y = 0.52;
			w = 0.1125;
			h = 0.08;
			action = "closeDialog 0; [cursorTarget,player] call EPOCH_startTRADEREQ";
		};
		class RscButtonMenu_2403: RscButtonMenu
		{
			idc = 2403;
			text = "Cancel";
			x = 0.5125;
			y = 0.52;
			w = 0.1125;
			h = 0.08;
			action = "closeDialog 0";
		};
	};
};
*/

class InteractNPC
{
	idd = -12;
	duration = -1;
	onload = "setMousePosition [0.5, 0.5];";
	//onLoad = "";
	class controls
	{
		class RscButtonMenu_2401: RscButtonMenu
		{
			idc = 2401;
			text = "Talk";
			x = 0.5125;
			y = 0.42;
			w = 0.1125;
			h = 0.08;
			action = "closeDialog 0; cursorTarget call EPOCH_startInteractNPC";
		};
		class RscButtonMenu_2402: RscButtonMenu
		{
			idc = 2402;
			text = "Shop";
			x = 0.3875;
			y = 0.42;
			w = 0.1125;
			h = 0.08;
			action = "call EPOCH_startNPCTraderMenu;";
		};
		/*
		class RscButtonMenu_2403: RscButtonMenu
		{
			idc = 2403;
			text = "Steal";
			x = 0.3875;
			y = 0.52;
			w = 0.1125;
			h = 0.08;
			action = "closeDialog 0; player action [""Gear"", cursorTarget];";
		};
		*/
		class RscButtonMenu_2404: RscButtonMenu
		{
			idc = 2405;
			text = "Cancel";
			x = 0.5125;
			y = 0.52;
			w = 0.1125;
			h = 0.08;
			action = "closeDialog 0";
		};
	};
};

/*
class InteractBuilding
{
	idd = 420004;
	duration = -1;
	//onLoad = "";
	class controls
	{
		class RscListbox_1550: RscListbox
		{
			idc = 1550;
			x = 0.2125;
			y = 0.08;
			w = 0.6;
			h = 0.84;
			onLBDblClick = "call compile ((_this select 0) lbData (_this select 1)); call EPOCH_buildingInteract;";
		};
		class RscButtonMenuCancel_2700: RscButtonMenuCancel
		{
			x = 0.4625;
			y = 0.92;
			w = 0.1125;
			h = 0.08;
		};
	};
};
*/

class InteractBank
{
	idd = -13;
	duration = -1;
	onLoad = "setMousePosition[0.5, 0.5]; call EPOCH_showStats; [] spawn { uiSleep 0.5; waitUntil {ctrlSetText [1005,format['%1',EPOCH_bankBalance]]; uiSleep 1; isNull (findDisplay -13)};}";
	class controls
	{
		class IGUIBack_2200 : IGUIBack
		{
			idc = 2200;
			x = 0;
			y = 0;
			w = 1;
			h = 1;
		};
		class RscListbox_1500 : RscListbox
		{
			idc = 21500;
			x = 0.7375;
			y = 0.04;
			w = 0.2375;
			h = 0.64;
		};
		class transfer_amount : RscEdit
		{
			idc = 1400;
			text = "0";
			x = 0.7375;
			y = 0.78;
			w = 0.2375;
			h = 0.08;
			onKeyUp = "[_this,EPOCH_bankBalance] call EPOCH_onChar;";
		};
		class transfer_btn : RscButton
		{
			idc = 1600;
			text = "Transfer";
			x = 0.375;
			y = 0.9;
			w = 0.2375;
			h = 0.08;
			// action = "closeDialog 0; EPOCH_storeCrypto_PVS = [player,[parseNumber(ctrlText 1401),parseNumber(ctrlText 1402),[parseNumber(ctrlText 1400),(lbData [21500, (lbCurSel 21500)])]],Epoch_personalToken]; publicVariableServer 'EPOCH_storeCrypto_PVS'; ";
			action = "call EPOCH_startBankTransfer;";
		};
		class RscEdit_deposit : RscEdit
		{
			idc = 1401;
			text = "0";
			x = 0.375;
			y = 0.78;
			w = 0.2375;
			h = 0.08;
			onKeyUp = "[_this,EPOCH_playerCrypto] call EPOCH_onChar;";
		};
		class RscEdit_withdraw : RscEdit
		{
			idc = 1402;
			text = "0";
			x = 0.025;
			y = 0.78;
			w = 0.2375;
			h = 0.08;
			onKeyUp = "[_this,EPOCH_bankBalance] call EPOCH_onChar;";
		};
		class RscText_1001 : RscText
		{
			idc = 1001;
			text = "Withdraw";
			shadow = 0;
			x = 0.025;
			y = 0.7;
			w = 0.2375;
			h = 0.06;
		};
		class RscText_1002 : RscText
		{
			idc = 1002;
			text = "Deposit";
			shadow = 0;
			x = 0.375;
			y = 0.7;
			w = 0.2375;
			h = 0.06;
		};
		class RscText_1003 : RscText
		{
			idc = 1003;
			text = "Transfer";
			shadow = 0;
			x = 0.7375;
			y = 0.7;
			w = 0.2375;
			h = 0.06;
		};
		class RscPicture_1200 : RscPicture
		{
			idc = 1200;
			style = 48 + 0x800;
			text = "";
			x = 0.9;
			y = 0.88;
			w = 0.1;
			h = 0.1;
		};
		class RscText_1004 : RscText
		{
			idc = 1004;
			text = "Epoch Corp. Retrocrypt v0.217";
			shadow = 0;
			x = 0.175;
			y = 0.38;
			w = 0.3625;
			h = 0.04;
		};
		class RscText_1005 : RscText
		{
			idc = 1005;
			text = "0";
			shadow = 0;
			x = 0.1125;
			y = 0.02;
			w = 0.5875;
			h = 0.08;
			sizeEx = "2.0 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
		};
		class RscPicture_1201 : RscPicture
		{
			idc = 1201;
			style = 48 + 0x800;
			text = "\x\addons\a3_epoch_code\Data\UI\cc_ca.paa";
			x = 0;
			y = 0;
			w = 0.1;
			h = 0.1;
		};
	};
};
class InteractBaseBuilding
{
	idd = -14;
	duration = -1;
	onload = "setMousePosition [0.5, 0.5];";
	//onLoad = "";
	class controls
	{
		class RscButtonMenu_2400 : RscButtonMenu
		{
			idc = 2400;
			text = "Upgrade";
			x = 0.5125;
			y = 0.42;
			w = 0.125;
			h = 0.08;
			action = "closeDialog 0; cursorTarget call EPOCH_QuickUpgrade;";
		};
		class RscButtonMenu_2401 : RscButtonMenu
		{
			idc = 2401;
			text = "Remove";
			x = 0.3625;
			y = 0.42;
			w = 0.125;
			h = 0.08;
			action = "closeDialog 0; cursorTarget call EPOCH_removeBUILD;";
		};

		class RscButtonMenu_2403: RscButtonMenu
		{
			idc = 2403;
			text = "Cancel";
			x = 0.5125;
			y = 0.52;
			w = 0.125;
			h = 0.08;
			action = "closeDialog 0";
		};

		class RscButtonMenu_2402 : RscButtonMenu
		{
			idc = 2402;
			text = "Move";
			x = 0.3625;
			y = 0.52;
			w = 0.125;
			h = 0.08;
			action = "closeDialog 0; cursorTarget call EPOCH_fnc_SelectTargetBuild;";
		};
		
	};
};
/*
class InteractItem
{
	idd = -15;
	duration = -1;
	onload = "setMousePosition [0.5, 0.5];";
	//onLoad = "";

	class custom_button : RscButton
	{
		idc = -1;
		text = "";
		style = "0x02 + 0x100";
		colorText[] = { 1, 1, 1, 0 };
		colorDisabled[] = { 1, 1, 1, 0 };
		colorBackground[] = { 1, 1, 1, 0 };
		colorBackgroundDisabled[] = { 1, 1, 1, 0 };
		colorBackgroundActive[] = { 1, 1, 1, 0.1 };
		colorShadow[] = { 1, 1, 1, 0 };
		colorFocused[] = { 1, 1, 1, 0.1 };
		soundClick[] = { "", 0.6, 1 };
	};

	class controls
	{
		class IGUIBack_2200 : IGUIBack
		{
			idc = 2200;
			x = 0.29375 * safezoneW + safezoneX;
			y = 0.225 * safezoneH + safezoneY;
			w = 0.4125 * safezoneW;
			h = 0.55 * safezoneH;
		};
		class RscButton_1600 : RscButton
		{
			idc = 41201;
			text = "USE";
			x = 0.324687 * safezoneW + safezoneX;
			y = 0.456 * safezoneH + safezoneY;
			w = 0.0721875 * safezoneW;
			h = 0.044 * safezoneH;
			action = "closeDialog 0; call EPOCH_consumeItem;";
		};
		class RscButton_1601 : RscButton
		{
			idc = 1601;
			text = "CANCEL";
			x = 0.412344 * safezoneW + safezoneX;
			y = 0.456 * safezoneH + safezoneY;
			w = 0.0721875 * safezoneW;
			h = 0.044 * safezoneH;
			action = "closeDialog 0";
		};
		class p1: RscPicture
		{
			idc = 41202;
			x = 0.515469 * safezoneW + safezoneX;
			y = 0.258 * safezoneH + safezoneY;
			w = 0.0515625 * safezoneW;
			h = 0.088 * safezoneH;
		};
		class p2: RscPicture
		{
			idc = 41203;
			x = 0.5825 * safezoneW + safezoneX;
			y = 0.258 * safezoneH + safezoneY;
			w = 0.0515625 * safezoneW;
			h = 0.088 * safezoneH;
		};
		class p3: RscPicture
		{
			idc = 41204;
			x = 0.649531 * safezoneW + safezoneX;
			y = 0.258 * safezoneH + safezoneY;
			w = 0.0515625 * safezoneW;
			h = 0.088 * safezoneH;
		};
		class p4: RscPicture
		{
			idc = 41205;
			x = 0.515469 * safezoneW + safezoneX;
			y = 0.368 * safezoneH + safezoneY;
			w = 0.0515625 * safezoneW;
			h = 0.088 * safezoneH;
		};
		class p5: RscPicture
		{
			idc = 41206;
			x = 0.5825 * safezoneW + safezoneX;
			y = 0.368 * safezoneH + safezoneY;
			w = 0.0515625 * safezoneW;
			h = 0.088 * safezoneH;
		};
		class p6: RscPicture
		{
			idc = 41207;
			x = 0.649531 * safezoneW + safezoneX;
			y = 0.368 * safezoneH + safezoneY;
			w = 0.0515625 * safezoneW;
			h = 0.088 * safezoneH;
		};

		class b1: custom_button
		{
			idc = 1602;
			x = 0.515469 * safezoneW + safezoneX;
			y = 0.258 * safezoneH + safezoneY;
			w = 0.0515625 * safezoneW;
			h = 0.088 * safezoneH;
			action = "[0] call EPOCH_craftItemPreview";
		};
		class b2: custom_button
		{
			idc = 1603;
			x = 0.5825 * safezoneW + safezoneX;
			y = 0.258 * safezoneH + safezoneY;
			w = 0.0515625 * safezoneW;
			h = 0.088 * safezoneH;
			action = "[1] call EPOCH_craftItemPreview";
		};
		class b3: custom_button
		{
			idc = 1604;
			x = 0.649531 * safezoneW + safezoneX;
			y = 0.258 * safezoneH + safezoneY;
			w = 0.0515625 * safezoneW;
			h = 0.088 * safezoneH;
			action = "[2] call EPOCH_craftItemPreview";
		};
		class b4: custom_button
		{
			idc = 1605;
			x = 0.515469 * safezoneW + safezoneX;
			y = 0.368 * safezoneH + safezoneY;
			w = 0.0515625 * safezoneW;
			h = 0.088 * safezoneH;
			action = "[3] call EPOCH_craftItemPreview";
		};
		class b5: custom_button
		{
			idc = 1606;
			x = 0.5825 * safezoneW + safezoneX;
			y = 0.368 * safezoneH + safezoneY;
			w = 0.0515625 * safezoneW;
			h = 0.088 * safezoneH;
			action = "[4] call EPOCH_craftItemPreview";
		};
		class b6: custom_button
		{
			idc = 1607;
			x = 0.649531 * safezoneW + safezoneX;
			y = 0.368 * safezoneH + safezoneY;
			w = 0.0515625 * safezoneW;
			h = 0.088 * safezoneH;
			action = "[5] call EPOCH_craftItemPreview";
		};

		class MainPicture : RscPicture
		{
			style = 48 + 0x800;
			idc = 41200;
			x = 0.298906 * safezoneW + safezoneX;
			y = 0.258 * safezoneH + safezoneY;
			w = 0.211406 * safezoneW;
			h = 0.187 * safezoneH;
		};








		class CraftButton : RscButton
		{
			idc = 1600;
			text = "CRAFT";
			x = 0.654739 * safezoneW + safezoneX;
			y = 0.728222 * safezoneH + safezoneY;
			w = 0.04125 * safezoneW;
			h = 0.033 * safezoneH;
			action = "call EPOCH_craftItem;";
		};


		class CraftQuantity : RscText
		{
			idc = 1000;
			text = "QTY";
			x = 0.588546 * safezoneW + safezoneX;
			y = 0.729102 * safezoneH + safezoneY;
			w = 0.020625 * safezoneW;
			h = 0.022 * safezoneH;
		};
		class Quantity : RscCombo
		{
			idc = 2100;
			x = 0.611771 * safezoneW + safezoneX;
			y = 0.732842 * safezoneH + safezoneY;
			w = 0.0360937 * safezoneW;
			h = 0.022 * safezoneH;
		};



		class isof1 : RscText
		{
			idc = 41001;
			text = "";
			x = 0.515469 * safezoneW + safezoneX;
			y = 0.577 * safezoneH + safezoneY;
			w = 0.0515625 * safezoneW;
			h = 0.022 * safezoneH;
		};
		class isof2 : RscText
		{
			idc = 41002;
			text = "";
			x = 0.5825 * safezoneW + safezoneX;
			y = 0.577 * safezoneH + safezoneY;
			w = 0.0515625 * safezoneW;
			h = 0.022 * safezoneH;
		};
		class isof3 : RscText
		{
			idc = 41003;
			text = "";
			x = 0.649531 * safezoneW + safezoneX;
			y = 0.577 * safezoneH + safezoneY;
			w = 0.0515625 * safezoneW;
			h = 0.022 * safezoneH;
		};
		class isof4 : RscText
		{
			idc = 41004;
			text = "";
			x = 0.515469 * safezoneW + safezoneX;
			y = 0.698 * safezoneH + safezoneY;
			w = 0.0515625 * safezoneW;
			h = 0.022 * safezoneH;
		};
		class isof5 : RscText
		{
			idc = 41005;
			text = "";
			x = 0.5825 * safezoneW + safezoneX;
			y = 0.698 * safezoneH + safezoneY;
			w = 0.0515625 * safezoneW;
			h = 0.022 * safezoneH;
		};
		class isof6 : RscText
		{
			idc = 41006;
			text = "";
			x = 0.649531 * safezoneW + safezoneX;
			y = 0.698 * safezoneH + safezoneY;
			w = 0.0515625 * safezoneW;
			h = 0.022 * safezoneH;
		};


		class bBox1 : RscPicture
		{
			idc = 1200;
			x = 0.515469 * safezoneW + safezoneX;
			y = 0.489 * safezoneH + safezoneY;
			w = 0.0515625 * safezoneW;
			h = 0.088 * safezoneH;
		};
		class bBox2 : RscPicture
		{
			idc = 1201;
			x = 0.5825 * safezoneW + safezoneX;
			y = 0.489 * safezoneH + safezoneY;
			w = 0.0515625 * safezoneW;
			h = 0.088 * safezoneH;
		};
		class bBox3 : RscPicture
		{
			idc = 1202;
			x = 0.649531 * safezoneW + safezoneX;
			y = 0.489 * safezoneH + safezoneY;
			w = 0.0515625 * safezoneW;
			h = 0.088 * safezoneH;
		};
		class bBox4 : RscPicture
		{
			idc = 1203;
			x = 0.515469 * safezoneW + safezoneX;
			y = 0.61 * safezoneH + safezoneY;
			w = 0.0515625 * safezoneW;
			h = 0.088 * safezoneH;
		};
		class bBox5 : RscPicture
		{
			idc = 1204;
			x = 0.5825 * safezoneW + safezoneX;
			y = 0.61 * safezoneH + safezoneY;
			w = 0.0515625 * safezoneW;
			h = 0.088 * safezoneH;
		};
		class bBox6 : RscPicture
		{
			idc = 1205;
			x = 0.649531 * safezoneW + safezoneX;
			y = 0.61 * safezoneH + safezoneY;
			w = 0.0515625 * safezoneW;
			h = 0.088 * safezoneH;
		};

		class s1 : RscPicture
		{
			idc = 42200;
			x = 0.515469 * safezoneW + safezoneX;
			y = 0.489 * safezoneH + safezoneY;
			w = 0.0515625 * safezoneW;
			h = 0.088 * safezoneH;
		};
		class s2 : RscPicture
		{
			idc = 42201;
			x = 0.5825 * safezoneW + safezoneX;
			y = 0.489 * safezoneH + safezoneY;
			w = 0.0515625 * safezoneW;
			h = 0.088 * safezoneH;
		};
		class s3 : RscPicture
		{
			idc = 42202;
			x = 0.649531 * safezoneW + safezoneX;
			y = 0.489 * safezoneH + safezoneY;
			w = 0.0515625 * safezoneW;
			h = 0.088 * safezoneH;
		};
		class s4 : RscPicture
		{
			idc = 42203;
			x = 0.515469 * safezoneW + safezoneX;
			y = 0.61 * safezoneH + safezoneY;
			w = 0.0515625 * safezoneW;
			h = 0.088 * safezoneH;
		};
		class s5 : RscPicture
		{
			idc = 42204;
			x = 0.5825 * safezoneW + safezoneX;
			y = 0.61 * safezoneH + safezoneY;
			w = 0.0515625 * safezoneW;
			h = 0.088 * safezoneH;
		};
		class s6 : RscPicture
		{
			idc = 42205;
			x = 0.649531 * safezoneW + safezoneX;
			y = 0.61 * safezoneH + safezoneY;
			w = 0.0515625 * safezoneW;
			h = 0.088 * safezoneH;
		};

		class sbtn1 : custom_button
		{
			idc = 43200;
			x = 0.515469 * safezoneW + safezoneX;
			y = 0.489 * safezoneH + safezoneY;
			w = 0.0515625 * safezoneW;
			h = 0.088 * safezoneH;
		};
		class sbtn2 : custom_button
		{
			idc = 43201;
			x = 0.5825 * safezoneW + safezoneX;
			y = 0.489 * safezoneH + safezoneY;
			w = 0.0515625 * safezoneW;
			h = 0.088 * safezoneH;
		};
		class sbtn3 : custom_button
		{
			idc = 43202;
			x = 0.649531 * safezoneW + safezoneX;
			y = 0.489 * safezoneH + safezoneY;
			w = 0.0515625 * safezoneW;
			h = 0.088 * safezoneH;
		};
		class sbtn4 : custom_button
		{
			idc = 43203;
			x = 0.515469 * safezoneW + safezoneX;
			y = 0.61 * safezoneH + safezoneY;
			w = 0.0515625 * safezoneW;
			h = 0.088 * safezoneH;
		};
		class sbtn5 : custom_button
		{
			idc = 43204;
			x = 0.5825 * safezoneW + safezoneX;
			y = 0.61 * safezoneH + safezoneY;
			w = 0.0515625 * safezoneW;
			h = 0.088 * safezoneH;
		};
		class sbtn6 : custom_button
		{
			idc = 43205;
			x = 0.649531 * safezoneW + safezoneX;
			y = 0.61 * safezoneH + safezoneY;
			w = 0.0515625 * safezoneW;
			h = 0.088 * safezoneH;
		};


		class Top6Text : RscText
		{
			idc = -1;
			text = "Craftables";
			x = 0.568855 * safezoneW + safezoneX;
			y = 0.228704 * safezoneH + safezoneY;
			w = 0.0773437 * safezoneW;
			h = 0.022 * safezoneH;
		};

		class Bottom6Text : RscText
		{
			idc = 41008;
			text = "Materials";
			x = 0.569376 * safezoneW + safezoneX;
			y = 0.462426 * safezoneH + safezoneY;
			w = 0.0825 * safezoneW;
			h = 0.022 * safezoneH;
		};


		// Resources
		class resource1 : RscPicture
		{
			idc = 45202;
			text = "";
			x = 0.313958 * safezoneW + safezoneX;
			y = 0.547025 * safezoneH + safezoneY;
			w = 0.0489583 * safezoneW;
			h = 0.0846454 * safezoneH;
		};
		class rbtn1 : custom_button
		{
			idc = 44202;
			x = 0.313958 * safezoneW + safezoneX;
			y = 0.547025 * safezoneH + safezoneY;
			w = 0.0489583 * safezoneW;
			h = 0.0846454 * safezoneH;
		};

		class resource2 : RscPicture
		{
			idc = 45203;
			text = "";
			x = 0.372708 * safezoneW + safezoneX;
			y = 0.547025 * safezoneH + safezoneY;
			w = 0.0489583 * safezoneW;
			h = 0.0846454 * safezoneH;
		};
		class rbtn2 : custom_button
		{
			idc = 44203;
			x = 0.372708 * safezoneW + safezoneX;
			y = 0.547025 * safezoneH + safezoneY;
			w = 0.0489583 * safezoneW;
			h = 0.0846454 * safezoneH;
		};

		class resource3 : RscPicture
		{
			idc = 45204;
			text = "";
			x = 0.431458 * safezoneW + safezoneX;
			y = 0.547025 * safezoneH + safezoneY;
			w = 0.0489583 * safezoneW;
			h = 0.0846454 * safezoneH;
		};
		class rbtn3 : custom_button
		{
			idc = 44204;
			x = 0.431458 * safezoneW + safezoneX;
			y = 0.547025 * safezoneH + safezoneY;
			w = 0.0489583 * safezoneW;
			h = 0.0846454 * safezoneH;
		};

		class resource4 : RscPicture
		{
			idc = 45205;
			text = "";
			x = 0.313958 * safezoneW + safezoneX;
			y = 0.650481 * safezoneH + safezoneY;
			w = 0.0489583 * safezoneW;
			h = 0.0846454 * safezoneH;
		};
		class rbtn4 : custom_button
		{
			idc = 44205;
			x = 0.313958 * safezoneW + safezoneX;
			y = 0.650481 * safezoneH + safezoneY;
			w = 0.0489583 * safezoneW;
			h = 0.0846454 * safezoneH;
		};

		class resource5 : RscPicture
		{
			idc = 45206;
			text = "";
			x = 0.372708 * safezoneW + safezoneX;
			y = 0.650481 * safezoneH + safezoneY;
			w = 0.0489583 * safezoneW;
			h = 0.0846454 * safezoneH;
		};
		class rbtn5 : custom_button
		{
			idc = 44206;
			x = 0.372708 * safezoneW + safezoneX;
			y = 0.650481 * safezoneH + safezoneY;
			w = 0.0489583 * safezoneW;
			h = 0.0846454 * safezoneH;
		};

		class resource6 : RscPicture
		{
			idc = 45207;
			text = "";
			x = 0.431458 * safezoneW + safezoneX;
			y = 0.650481 * safezoneH + safezoneY;
			w = 0.0489583 * safezoneW;
			h = 0.0846454 * safezoneH;
		};
		class rbtn6 : custom_button
		{
			idc = 44207;
			x = 0.431458 * safezoneW + safezoneX;
			y = 0.650481 * safezoneH + safezoneY;
			w = 0.0489583 * safezoneW;
			h = 0.0846454 * safezoneH;
		};

		class RscText_Resources : RscText
		{
			idc = 42000;
			text = "Resources";
			x = 0.353125 * safezoneW + safezoneX;
			y = 0.509405 * safezoneH + safezoneY;
			w = 0.112604 * safezoneW;
			h = 0.0376202 * safezoneH;
		};












	};
};
*/
class Trade
{
	idd = -1900;
	// onLoad = "player setVariable [""TRADE_ACTIVE"", EPOCH_p2ptradeTarget, true];";
	onload = "setMousePosition [0.5, 0.5];";
	onUnload = "EPOCH_pendingP2ptradeTarget = ObjNull;";
	class controls
	{
		class IGUIBack_2200 : IGUIBack
		{
			idc = 2200;
			x = 0.29375 * safezoneW + safezoneX;
			y = 0.225 * safezoneH + safezoneY;
			w = 0.4125 * safezoneW;
			h = 0.55 * safezoneH;
		};
		class Inventorylist: RscListbox
		{
			idc = 1500;
			canDrag = 1;
			x = 0.298906 * safezoneW + safezoneX;
			y = 0.302 * safezoneH + safezoneY;
			w = 0.134062 * safezoneW;
			h = 0.385 * safezoneH;
			onLBDblClick = "_index = lbAdd [1501, ((_this select 0) lbText (_this select 1))]; lbSetData [1501, _index, ((_this select 0) lbData (_this select 1))]; lbSetPicture [1501, _index, ((_this select 0) lbPicture (_this select 1))]; (_this select 0) lbDelete (_this select 1);";
			onLBDrop = "_index = lbAdd [1501, ((_this select 0) lbText (_this select 1))]; lbSetData [1501, _index, ((_this select 0) lbData (_this select 1))]; lbSetPicture [1501, _index, ((_this select 0) lbPicture (_this select 1))]; (_this select 0) lbDelete (_this select 1);";
		};
		class RscCombo_2100: RscCombo
		{
			idc = 2100;
			x = 0.309219 * safezoneW + safezoneX;
			y = 0.269 * safezoneH + safezoneY;
			w = 0.113437 * safezoneW;
			h = 0.022 * safezoneH;
			onLBSelChanged = "_this call EPOCH_tradeFilter";
		};
		class youroffer: RscListbox
		{
			idc = 1501;
			canDrag = 1;
			x = 0.438125 * safezoneW + safezoneX;
			y = 0.28 * safezoneH + safezoneY;
			w = 0.128906 * safezoneW;
			h = 0.407 * safezoneH;
			onLBDblClick = "_index = lbAdd [1500, ((_this select 0) lbText (_this select 1))]; lbSetData [1500, _index, ((_this select 0) lbData (_this select 1))]; lbSetPicture [1500, _index, ((_this select 0) lbPicture (_this select 1))]; (_this select 0) lbDelete (_this select 1);";
			onLBDrop = "_index = lbAdd [1500, ((_this select 0) lbText (_this select 1))]; lbSetData [1500, _index, ((_this select 0) lbData (_this select 1))]; lbSetPicture [1500, _index, ((_this select 0) lbPicture (_this select 1))]; (_this select 0) lbDelete (_this select 1);";
		};
		class othersoffer: RscListbox
		{
			idc = 1502;
			x = 0.572187 * safezoneW + safezoneX;
			y = 0.28 * safezoneH + safezoneY;
			w = 0.128906 * safezoneW;
			h = 0.407 * safezoneH;
		};
		class RscText_1000: RscText
		{
			idc = 1000;
			text = "Your Offer";
			x = 0.448438 * safezoneW + safezoneX;
			y = 0.236 * safezoneH + safezoneY;
			w = 0.108281 * safezoneW;
			h = 0.033 * safezoneH;
			//sizeEx = 2 * GUI_GRID_H;
		};
		class RscText_1001: RscText
		{
			idc = 1001;
			text = "Trade Offer";
			x = 0.5825 * safezoneW + safezoneX;
			y = 0.236 * safezoneH + safezoneY;
			w = 0.113437 * safezoneW;
			h = 0.033 * safezoneH;
			//sizeEx = 2 * GUI_GRID_H;
		};
		class RscText_1002: RscText
		{
			idc = 1002;
			text = "Inventory";
			x = 0.309219 * safezoneW + safezoneX;
			y = 0.225 * safezoneH + safezoneY;
			w = 0.0979687 * safezoneW;
			h = 0.033 * safezoneH;
			//sizeEx = 2 * GUI_GRID_H;
		};
		class RscButtonMenu_2400: RscButtonMenu
		{
			idc = 2400;
			text = "ACCEPT";
			x = 0.587656 * safezoneW + safezoneX;
			y = 0.709 * safezoneH + safezoneY;
			w = 0.0464062 * safezoneW;
			h = 0.033 * safezoneH;
			//sizeEx = 1 * GUI_GRID_H;
			action = "call EPOCH_makep2pTrade";
		};
		class RscButtonMenu_2401: RscButtonMenu
		{
			idc = 2401;
			text = "Decline";
			x = 0.644375 * safezoneW + safezoneX;
			y = 0.709 * safezoneH + safezoneY;
			w = 0.0464062 * safezoneW;
			h = 0.033 * safezoneH;
			//sizeEx = 1 * GUI_GRID_H;
			action = "closeDialog 0";
		};
		class RscPicture_1200 : RscPicture
		{
			idc = 1200;
			style = 48 + 0x800;
			text = "\x\addons\a3_epoch_code\Data\UI\cc_ca.paa";
			x = 0.298906 * safezoneW + safezoneX;
			y = 0.698 * safezoneH + safezoneY;
			w = 0.04125 * safezoneW;
			h = 0.066 * safezoneH;
		};

		// Crypto
		class RscEdit_1400 : RscEdit
		{
			idc = 1400;
			colorBackground[] = { 0, 0, 0, 0.1 };
			x = 0.345312 * safezoneW + safezoneX;
			y = 0.709 * safezoneH + safezoneY;
			w = 0.061875 * safezoneW;
			h = 0.033 * safezoneH;
			onKeyUp = "[_this,EPOCH_playerCrypto] call EPOCH_onChar;";
		};

	};
};

class CfgInteract
{
	class Default
	{
		responseNPC[] = {"How can I help you?"};
		interactMenu[] = {0,1,2};
		shopMenu[] = {};
		shop[] = {};
		mission[] = {};
	};

	class Interact_NPC_0 : Default
	{
	};
	class Interact_NPC_1 : Default
	{
	};
	class Interact_NPC_2 : Default
	{
	};
	class Interact_NPC_3 : Default
	{
	};
	class Interact_NPC_4 : Default
	{
	};
	class Interact_NPC_5 : Default
	{
	};
	class Interact_NPC_6 : Default
	{
	};
	class Interact_NPC_7 : Default
	{
	};
	class Interact_NPC_8 : Default
	{
	};
	class Interact_NPC_9 : Default
	{
	};
	class Interact_NPC_10 : Default
	{
	};
	class Interact_NPC_11 : Default
	{
	};
	class Interact_NPC_12 : Default
	{
	};
	class Interact_NPC_13 : Default
	{
	};
	class Interact_NPC_14 : Default
	{
	};
	class Interact_NPC_15 : Default
	{
	};
	class Interact_NPC_16 : Default
	{
	};
	class Interact_NPC_17 : Default
	{
	};
	class Interact_NPC_18 : Default
	{
	};
	class Interact_NPC_19 : Default
	{
	};
	class Interact_NPC_20 : Default
	{
	};

	class Default_Menu
	{
		responseNPC[] = {};
		interactMenu[] = {};
		shopMenu[] = {};
		shop[] = {};
		mission[] = {};
	};

	class Interact_0 : Default_Menu {
		interactName = "What do you have for Sell?";
		responseNPC[] = {"I have the follwing items:"};
		shopMenu[] = {0,1,2};
	};

	class Shop_0 : Default_Menu {
		interactName = "Pistols";
		shop[] = {"hgun_Rook40_snds_F"};
	};
	class Shop_1 : Default_Menu {
		interactName = "Rifles";
		shop[] = {"LMG_Mk200_MRCO_F"};
	};
	class Shop_2 : Default_Menu {
		interactName = "Backpacks";
		shop[] = {"B_FieldPack_blk"};
	};

	class Interact_1 : Default_Menu {
		interactName = "How can I gain faction?";
		responseNPC[] = {"By doing a job for me..."};
		missionMenu[] = {0,1};
	};

	class Mission_0 : Default_Menu {
		interactName = "Find and return an Item";
		mission[] = {"Book","Two"};
	};

	class Mission_1 : Default_Menu {
		interactName = "Kill someone that has low faction";
	};

	class Interact_2 : Default_Menu {
		interactName = "What is going on around here?";
		responseNPC[] = {"Not much these days."};
		interactMenu[] = {3};
	};

	class Interact_3 : Default_Menu {
		interactName = "Ok, Thanks.";
	};

};

class RscDisplayInventory_DLCTemplate
{
	class controls
	{
		class DlcBg
		{
			idc = 101;
			text = "\A3\Ui_f\data\GUI\Rsc\RscDisplayInventory\InventoryStripe_ca.paa";
			color[] = { 1, 1, 1, 1 };
			x = 0;
			y = 0;
			w = "1.8 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "1.8 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
		};
		class DlcIcon
		{
			idc = 100;
			text = "";
			color[] = { 1, 1, 1, 1 };
			x = "0 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			y = "0 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			w = "1 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
		};
	};
};
		

class RscDisplayInventory
{
	scriptName = "RscDisplayInventory";
	scriptPath = "IGUI";
	onLoad = "setMousePosition[0.5, 0.5]; call EPOCH_showStats; [""onLoad"",_this,""RscDisplayInventory"",'IGUI'] call 	(uinamespace getvariable 'BIS_fnc_initDisplay')";
	onUnload = "[""onUnload"",_this,""RscDisplayInventory"",'IGUI'] call 	(uinamespace getvariable 'BIS_fnc_initDisplay')";
	idd = 602;
	enableSimulation = 1;
	class Colors
	{
		dragValidBgr[] = { "(profilenamespace getvariable ['IGUI_TEXT_RGB_R',0])", "(profilenamespace getvariable ['IGUI_TEXT_RGB_G',1])", "(profilenamespace getvariable ['IGUI_TEXT_RGB_B',1])", 0.5 };
		dragInvalidBgr[] = { "(profilenamespace getvariable ['IGUI_ERROR_RGB_R',0.8])", "(profilenamespace getvariable ['IGUI_ERROR_RGB_G',0.0])", "(profilenamespace getvariable ['IGUI_ERROR_RGB_B',0.0])", 0.5 };
		dragValidBar[] = { "(profilenamespace getvariable ['IGUI_WARNING_RGB_R',0.8])", "(profilenamespace getvariable ['IGUI_WARNING_RGB_G',0.5])", "(profilenamespace getvariable ['IGUI_WARNING_RGB_B',0.0])", 0.5 };
		dragInvalidBar[] = { "(profilenamespace getvariable ['IGUI_ERROR_RGB_R',0.8])", "(profilenamespace getvariable ['IGUI_ERROR_RGB_G',0.0])", "(profilenamespace getvariable ['IGUI_ERROR_RGB_B',0.0])", 0.5 };
		progressBar[] = { "(profilenamespace getvariable ['IGUI_TEXT_RGB_R',0])", "(profilenamespace getvariable ['IGUI_TEXT_RGB_G',1])", "(profilenamespace getvariable ['IGUI_TEXT_RGB_B',1])", 1 };
		progressBarBgr[] = { "(profilenamespace getvariable ['IGUI_BCG_RGB_R',0])", "(profilenamespace getvariable ['IGUI_BCG_RGB_G',1])", "(profilenamespace getvariable ['IGUI_BCG_RGB_B',1])", 0.75 };
		highlight[] = { "(profilenamespace getvariable ['IGUI_TEXT_RGB_R',0])", "(profilenamespace getvariable ['IGUI_TEXT_RGB_G',1])", "(profilenamespace getvariable ['IGUI_TEXT_RGB_B',1])", 0.5 };
	};
	class controlsBackground{};
	class controls
	{
		delete Background;
		delete Title;
		delete ButtonOK;
		delete ButtonCancel;
		class CA_ContainerBackground : RscText
		{
			idc = 1001;
			x = "1 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(safezoneX + (safezoneW - 					((safezoneW / safezoneH) min 1.2))/2)";
			y = "1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(safezoneY + (safezoneH - 					(			((safezoneW / safezoneH) min 1.2) / 1.2))/2)";
			w = "12 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "23 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			colorBackground[] = { 0.05, 0.05, 0.05, 0.7 };
		};
		class CA_PlayerBackground : RscText
		{
			idc = 1002;
			x = "14.6 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(safezoneX + (safezoneW - 					((safezoneW / safezoneH) min 1.2))/2)";
			y = "2 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(safezoneY + (safezoneH - 					(			((safezoneW / safezoneH) min 1.2) / 1.2))/2)";
			w = "24.4 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "22 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			colorBackground[] = { 0.05, 0.05, 0.05, 0.7 };
		};
		class TitleBackground : RscText
		{
			idc = 1020;
			x = "14.6 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(safezoneX + (safezoneW - 					((safezoneW / safezoneH) min 1.2))/2)";
			y = "1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(safezoneY + (safezoneH - 					(			((safezoneW / safezoneH) min 1.2) / 1.2))/2)";
			w = "24.4 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			colorBackground[] = { 0.1, 0.1, 0.1, 1 };
		};
		class PlayersName : RscText
		{
			idc = 111;
			text = "$STR_DIARY_PLAYER_NAME";
			x = "15.6 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(safezoneX + (safezoneW - 					((safezoneW / safezoneH) min 1.2))/2)";
			y = "1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(safezoneY + (safezoneH - 					(			((safezoneW / safezoneH) min 1.2) / 1.2))/2)";
			w = "19.8 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
		};
		class RankBackground : RscText
		{
			idc = 1014;
			x = "15.1 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(safezoneX + (safezoneW - 					((safezoneW / safezoneH) min 1.2))/2)";
			y = "1.25 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(safezoneY + (safezoneH - 					(			((safezoneW / safezoneH) min 1.2) / 1.2))/2)";
			w = "0.6 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "0.6 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			colorBackground[] = { 1, 1, 1, 0.2 };
		};
		class RankPicture : RscPicture
		{
			idc = 1203;
			text = "\A3\Ui_f\data\GUI\Cfg\Ranks\corporal_gs.paa";
			x = "15.1 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(safezoneX + (safezoneW - 					((safezoneW / safezoneH) min 1.2))/2)";
			y = "1.25 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(safezoneY + (safezoneH - 					(			((safezoneW / safezoneH) min 1.2) / 1.2))/2)";
			w = "0.6 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "0.6 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
		};
		class ButtonBack : RscActiveText
		{
			idc = 2;
			style = 48;
			color[] = { 1, 1, 1, 0.7 };
			text = "\A3\Ui_f\data\GUI\Rsc\RscDisplayArcadeMap\icon_exit_cross_ca.paa";
			x = "38 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(safezoneX + (safezoneW - 					((safezoneW / safezoneH) min 1.2))/2)";
			y = "1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(safezoneY + (safezoneH - 					(			((safezoneW / safezoneH) min 1.2) / 1.2))/2)";
			w = "1 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			colorText[] = { 1, 1, 1, 0.7 };
			colorActive[] = { 1, 1, 1, 1 };
			tooltip = "$STR_DISP_CLOSE";
		};
		class BackgroundSlotPrimary : RscPicture
		{
			idc = 1242;
			x = "26.6 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(safezoneX + (safezoneW - 					((safezoneW / safezoneH) min 1.2))/2)";
			y = "6 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(safezoneY + (safezoneH - 					(			((safezoneW / safezoneH) min 1.2) / 1.2))/2)";
			w = "11.9 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "3 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
		};
		class BackgroundSlotPrimaryMuzzle : BackgroundSlotPrimary
		{
			idc = 1243;
			x = "26.6 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(safezoneX + (safezoneW - 					((safezoneW / safezoneH) min 1.2))/2)";
			y = "9.1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(safezoneY + (safezoneH - 					(			((safezoneW / safezoneH) min 1.2) / 1.2))/2)";
			w = "2.3 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "2 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
		};
		class BackgroundSlotPrimaryUnderBarrel : BackgroundSlotPrimary
		{
			idc = 1200;
			x = "29 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(safezoneX + (safezoneW - 					((safezoneW / safezoneH) min 1.2))/2)";
			y = "9.1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(safezoneY + (safezoneH - 					(			((safezoneW / safezoneH) min 1.2) / 1.2))/2)";
			w = "2.3 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "2 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
		};
		class BackgroundSlotPrimaryFlashlight : BackgroundSlotPrimary
		{
			idc = 1244;
			x = "31.4 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(safezoneX + (safezoneW - 					((safezoneW / safezoneH) min 1.2))/2)";
			y = "9.2 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(safezoneY + (safezoneH - 					(			((safezoneW / safezoneH) min 1.2) / 1.2))/2)";
			w = "2.3 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "2 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
		};
		class BackgroundSlotPrimaryOptics : BackgroundSlotPrimary
		{
			idc = 1245;
			x = "33.8 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(safezoneX + (safezoneW - 					((safezoneW / safezoneH) min 1.2))/2)";
			y = "9.1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(safezoneY + (safezoneH - 					(			((safezoneW / safezoneH) min 1.2) / 1.2))/2)";
			w = "2.3 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "2 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
		};
		class BackgroundSlotPrimaryMagazine : BackgroundSlotPrimary
		{
			idc = 1246;
			x = "36.2 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(safezoneX + (safezoneW - 					((safezoneW / safezoneH) min 1.2))/2)";
			y = "9.1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(safezoneY + (safezoneH - 					(			((safezoneW / safezoneH) min 1.2) / 1.2))/2)";
			w = "2.3 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "2 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
		};
		class BackgroundSlotSecondary : BackgroundSlotPrimary
		{
			idc = 1247;
			x = "26.6 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(safezoneX + (safezoneW - 					((safezoneW / safezoneH) min 1.2))/2)";
			y = "11.5 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(safezoneY + (safezoneH - 					(			((safezoneW / safezoneH) min 1.2) / 1.2))/2)";
			w = "11.9 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "3 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
		};
		class BackgroundSlotSecondaryMuzzle : BackgroundSlotPrimary
		{
			idc = 1248;
			x = "26.6 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(safezoneX + (safezoneW - 					((safezoneW / safezoneH) min 1.2))/2)";
			y = "14.6 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(safezoneY + (safezoneH - 					(			((safezoneW / safezoneH) min 1.2) / 1.2))/2)";
			w = "2.3 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "2 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
		};
		class BackgroundSlotSecondaryUnderBarrel : BackgroundSlotPrimary
		{
			idc = 1266;
			x = "29 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(safezoneX + (safezoneW - 					((safezoneW / safezoneH) min 1.2))/2)";
			y = "14.6 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(safezoneY + (safezoneH - 					(			((safezoneW / safezoneH) min 1.2) / 1.2))/2)";
			w = "2.3 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "2 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
		};
		class BackgroundSlotSecondaryFlashlight : BackgroundSlotPrimary
		{
			idc = 1249;
			x = "31.4 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(safezoneX + (safezoneW - 					((safezoneW / safezoneH) min 1.2))/2)";
			y = "14.6 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(safezoneY + (safezoneH - 					(			((safezoneW / safezoneH) min 1.2) / 1.2))/2)";
			w = "2.3 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "2 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
		};
		class BackgroundSlotSecondaryOptics : BackgroundSlotPrimary
		{
			idc = 1250;
			x = "33.8 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(safezoneX + (safezoneW - 					((safezoneW / safezoneH) min 1.2))/2)";
			y = "14.6 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(safezoneY + (safezoneH - 					(			((safezoneW / safezoneH) min 1.2) / 1.2))/2)";
			w = "2.3 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "2 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
		};
		class BackgroundSlotSecondaryMagazine : BackgroundSlotPrimary
		{
			idc = 1251;
			x = "36.2 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(safezoneX + (safezoneW - 					((safezoneW / safezoneH) min 1.2))/2)";
			y = "14.6 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(safezoneY + (safezoneH - 					(			((safezoneW / safezoneH) min 1.2) / 1.2))/2)";
			w = "2.3 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "2 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
		};
		class BackgroundSlotHandgun : BackgroundSlotPrimary
		{
			idc = 1252;
			x = "26.6 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(safezoneX + (safezoneW - 					((safezoneW / safezoneH) min 1.2))/2)";
			y = "17 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(safezoneY + (safezoneH - 					(			((safezoneW / safezoneH) min 1.2) / 1.2))/2)";
			w = "11.9 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "3 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
		};
		class BackgroundSlotHandgunMuzzle : BackgroundSlotPrimary
		{
			idc = 1253;
			x = "26.6 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(safezoneX + (safezoneW - 					((safezoneW / safezoneH) min 1.2))/2)";
			y = "20.1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(safezoneY + (safezoneH - 					(			((safezoneW / safezoneH) min 1.2) / 1.2))/2)";
			w = "2.3 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "2 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
		};
		class BackgroundSlotHandgunUnderBarrel : BackgroundSlotPrimary
		{
			idc = 1268;
			x = "29 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(safezoneX + (safezoneW - 					((safezoneW / safezoneH) min 1.2))/2)";
			y = "20.1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(safezoneY + (safezoneH - 					(			((safezoneW / safezoneH) min 1.2) / 1.2))/2)";
			w = "2.3 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "2 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
		};
		class BackgroundSlotHandgunFlashlight : BackgroundSlotPrimary
		{
			idc = 1254;
			x = "31.4 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(safezoneX + (safezoneW - 					((safezoneW / safezoneH) min 1.2))/2)";
			y = "20.1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(safezoneY + (safezoneH - 					(			((safezoneW / safezoneH) min 1.2) / 1.2))/2)";
			w = "2.3 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "2 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
		};
		class BackgroundSlotHandgunOptics : BackgroundSlotPrimary
		{
			idc = 1255;
			x = "33.8 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(safezoneX + (safezoneW - 					((safezoneW / safezoneH) min 1.2))/2)";
			y = "20.1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(safezoneY + (safezoneH - 					(			((safezoneW / safezoneH) min 1.2) / 1.2))/2)";
			w = "2.3 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "2 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
		};
		class BackgroundSlotHandgunMagazine : BackgroundSlotPrimary
		{
			idc = 1256;
			x = "36.2 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(safezoneX + (safezoneW - 					((safezoneW / safezoneH) min 1.2))/2)";
			y = "20.1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(safezoneY + (safezoneH - 					(			((safezoneW / safezoneH) min 1.2) / 1.2))/2)";
			w = "2.3 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "2 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
		};
		class BackgroundSlotHeadgear : BackgroundSlotPrimary
		{
			idc = 1257;
			x = "26.6 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(safezoneX + (safezoneW - 					((safezoneW / safezoneH) min 1.2))/2)";
			y = "2.5 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(safezoneY + (safezoneH - 					(			((safezoneW / safezoneH) min 1.2) / 1.2))/2)";
			w = "2.9 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "2.9 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
		};
		class BackgroundSlotGoggles : BackgroundSlotPrimary
		{
			idc = 1258;
			x = "29.6 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(safezoneX + (safezoneW - 					((safezoneW / safezoneH) min 1.2))/2)";
			y = "2.5 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(safezoneY + (safezoneH - 					(			((safezoneW / safezoneH) min 1.2) / 1.2))/2)";
			w = "2.9 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "2.9 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
		};
		class BackgroundSlotHMD : BackgroundSlotPrimary
		{
			idc = 1259;
			x = "32.6 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(safezoneX + (safezoneW - 					((safezoneW / safezoneH) min 1.2))/2)";
			y = "2.5 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(safezoneY + (safezoneH - 					(			((safezoneW / safezoneH) min 1.2) / 1.2))/2)";
			w = "2.9 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "2.9 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
		};
		class BackgroundSlotBinoculars : BackgroundSlotPrimary
		{
			idc = 1260;
			x = "35.6 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(safezoneX + (safezoneW - 					((safezoneW / safezoneH) min 1.2))/2)";
			y = "2.5 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(safezoneY + (safezoneH - 					(			((safezoneW / safezoneH) min 1.2) / 1.2))/2)";
			w = "2.9 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "2.9 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
		};
		class BackgroundSlotMap : BackgroundSlotPrimary
		{
			idc = 1261;
			x = "15.1 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(safezoneX + (safezoneW - 					((safezoneW / safezoneH) min 1.2))/2)";
			y = "20.1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(safezoneY + (safezoneH - 					(			((safezoneW / safezoneH) min 1.2) / 1.2))/2)";
			w = "2.12 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "2 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
		};
		class BackgroundSlotGPS : BackgroundSlotPrimary
		{
			idc = 1262;
			x = "17.32 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(safezoneX + (safezoneW - 					((safezoneW / safezoneH) min 1.2))/2)";
			y = "20.1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(safezoneY + (safezoneH - 					(			((safezoneW / safezoneH) min 1.2) / 1.2))/2)";
			w = "2.12 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "2 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
		};
		class BackgroundSlotCompass : BackgroundSlotPrimary
		{
			idc = 1263;
			x = "21.76 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(safezoneX + (safezoneW - 					((safezoneW / safezoneH) min 1.2))/2)";
			y = "20.1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(safezoneY + (safezoneH - 					(			((safezoneW / safezoneH) min 1.2) / 1.2))/2)";
			w = "2.12 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "2 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
		};
		class BackgroundSlotRadio : BackgroundSlotPrimary
		{
			idc = 1264;
			x = "19.54 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(safezoneX + (safezoneW - 					((safezoneW / safezoneH) min 1.2))/2)";
			y = "20.1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(safezoneY + (safezoneH - 					(			((safezoneW / safezoneH) min 1.2) / 1.2))/2)";
			w = "2.12 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "2 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
		};
		class BackgroundSlotWatch : BackgroundSlotPrimary
		{
			idc = 1265;
			x = "23.98 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(safezoneX + (safezoneW - 					((safezoneW / safezoneH) min 1.2))/2)";
			y = "20.1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(safezoneY + (safezoneH - 					(			((safezoneW / safezoneH) min 1.2) / 1.2))/2)";
			w = "2.12 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "2 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
		};
		class ExternalContainerBackground : RscPicture
		{
			colorText[] = { 1, 1, 1, 0.1 };
			idc = 1240;
			x = "1.5 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(safezoneX + (safezoneW - 					((safezoneW / safezoneH) min 1.2))/2)";
			y = "3.7 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(safezoneY + (safezoneH - 					(			((safezoneW / safezoneH) min 1.2) / 1.2))/2)";
			w = "11 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "18.4 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
		};
		class PlayerContainerBackground : ExternalContainerBackground
		{
			idc = 1241;
			x = "15.1 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(safezoneX + (safezoneW - 					((safezoneW / safezoneH) min 1.2))/2)";
			y = "6 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(safezoneY + (safezoneH - 					(			((safezoneW / safezoneH) min 1.2) / 1.2))/2)";
			w = "11 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "14 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
		};
		class GroundTab : RscActiveText
		{
			idc = 6321;
			colorBackgroundSelected[] = { 1, 1, 1, 1 };
			colorFocused[] = { 1, 1, 1, 0 };
			soundDoubleClick[] = { "", 0.1, 1 };
			color[] = { 1, 1, 1, 1 };
			colorBackground[] = { 0, 0, 0, 1 };
			x = "1.5 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(safezoneX + (safezoneW - 					((safezoneW / safezoneH) min 1.2))/2)";
			y = "1.5 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(safezoneY + (safezoneH - 					(			((safezoneW / safezoneH) min 1.2) / 1.2))/2)";
			w = "5.5 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
		};
		class SoldierTab : GroundTab
		{
			idc = 6401;
			x = "7 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(safezoneX + (safezoneW - 					((safezoneW / safezoneH) min 1.2))/2)";
			y = "1.5 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(safezoneY + (safezoneH - 					(			((safezoneW / safezoneH) min 1.2) / 1.2))/2)";
			w = "5.5 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
		};
		class GroundContainer : RscListBox
		{
			class DLCTemplate : RscDisplayInventory_DLCTemplate
			{
				class Controls;
			};
			idc = 632;
			sizeEx = "0.8 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			sizeEx2 = "0.8 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			rowHeight = "2 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			canDrag = 1;
			colorText[] = { 1, 1, 1, 1 };
			colorBackground[] = { 0, 0, 0, 0 };
			itemBackground[] = { 1, 1, 1, 0.1 };
			itemSpacing = 0.001;
			x = "1.5 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(safezoneX + (safezoneW - 					((safezoneW / safezoneH) min 1.2))/2)";
			y = "3.7 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(safezoneY + (safezoneH - 					(			((safezoneW / safezoneH) min 1.2) / 1.2))/2)";
			w = "11 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "18.4 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";

			onLBDrag = "_this call EPOCH_selectInventoryItem; _this call EPOCH_refeshUI";
			onLBSelChanged = "_this call EPOCH_selectInventoryItem; _this call EPOCH_refeshUI";

		};
		class SoldierContainer : GroundContainer
		{
			idc = 640;
		};
		class GroundFilter : RscCombo
		{
			idc = 6554;
			x = "1.5 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(safezoneX + (safezoneW - 					((safezoneW / safezoneH) min 1.2))/2)";
			y = "2.6 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(safezoneY + (safezoneH - 					(			((safezoneW / safezoneH) min 1.2) / 1.2))/2)";
			w = "11 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
		};
		class GroundLoad : RscProgress
		{
			idc = 6307;
			texture = "";
			textureExt = "";
			colorBar[] = { 0.9, 0.9, 0.9, 0.9 };
			colorExtBar[] = { 1, 1, 1, 1 };
			colorFrame[] = { 1, 1, 1, 1 };
			x = "1.5 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(safezoneX + (safezoneW - 					((safezoneW / safezoneH) min 1.2))/2)";
			y = "22.5 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(safezoneY + (safezoneH - 					(			((safezoneW / safezoneH) min 1.2) / 1.2))/2)";
			w = "11 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
		};
		class SlotPrimary : GroundTab
		{
			class DLCTemplate : RscDisplayInventory_DLCTemplate
			{
				class Controls;
			};
			idc = 610;
			style = "0x30 + 0x800";
			color[] = { 1, 1, 1, 1 };
			colorBackground[] = { 1, 1, 1, 0.1 };
			colorBackgroundSelected[] = { 1, 1, 1, 0.1 };
			colorFocused[] = { 0, 0, 0, 0 };
			canDrag = 1;
			x = "26.6 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(safezoneX + (safezoneW - 					((safezoneW / safezoneH) min 1.2))/2)";
			y = "6 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(safezoneY + (safezoneH - 					(			((safezoneW / safezoneH) min 1.2) / 1.2))/2)";
			w = "11.9 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "3 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			colorText[] = { 0, 0, 0, 0.5 };
		};
		class SlotPrimaryMuzzle : SlotPrimary
		{
			idc = 620;
			x = "26.6 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(safezoneX + (safezoneW - 					((safezoneW / safezoneH) min 1.2))/2)";
			y = "9.1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(safezoneY + (safezoneH - 					(			((safezoneW / safezoneH) min 1.2) / 1.2))/2)";
			w = "2.3 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "2 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			colorText[] = { 0, 0, 0, 0.5 };
		};
		class SlotPrimaryUnderBarrel : SlotPrimary
		{
			idc = 641;
			x = "29 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(safezoneX + (safezoneW - 					((safezoneW / safezoneH) min 1.2))/2)";
			y = "9.1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(safezoneY + (safezoneH - 					(			((safezoneW / safezoneH) min 1.2) / 1.2))/2)";
			w = "2.3 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "2 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			colorText[] = { 0, 0, 0, 0.5 };
		};
		class SlotPrimaryFlashlight : SlotPrimary
		{
			idc = 622;
			x = "31.4 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(safezoneX + (safezoneW - 					((safezoneW / safezoneH) min 1.2))/2)";
			y = "9.1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(safezoneY + (safezoneH - 					(			((safezoneW / safezoneH) min 1.2) / 1.2))/2)";
			w = "2.3 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "2 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			colorText[] = { 0, 0, 0, 0.5 };
		};
		class SlotPrimaryOptics : SlotPrimary
		{
			idc = 621;
			x = "33.8 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(safezoneX + (safezoneW - 					((safezoneW / safezoneH) min 1.2))/2)";
			y = "9.1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(safezoneY + (safezoneH - 					(			((safezoneW / safezoneH) min 1.2) / 1.2))/2)";
			w = "2.3 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "2 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			colorText[] = { 0, 0, 0, 0.5 };
		};
		class SlotPrimaryMagazine : SlotPrimary
		{
			idc = 623;
			x = "36.2 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(safezoneX + (safezoneW - 					((safezoneW / safezoneH) min 1.2))/2)";
			y = "9.1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(safezoneY + (safezoneH - 					(			((safezoneW / safezoneH) min 1.2) / 1.2))/2)";
			w = "2.3 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "2 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			colorText[] = { 0, 0, 0, 0.5 };
		};
		class SlotSecondary : SlotPrimary
		{
			idc = 611;
			x = "26.6 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(safezoneX + (safezoneW - 					((safezoneW / safezoneH) min 1.2))/2)";
			y = "11.5 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(safezoneY + (safezoneH - 					(			((safezoneW / safezoneH) min 1.2) / 1.2))/2)";
			w = "11.9 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "3 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			colorText[] = { 0, 0, 0, 0.5 };
		};
		class SlotSecondaryMuzzle : SlotPrimary
		{
			idc = 624;
			x = "26.6 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(safezoneX + (safezoneW - 					((safezoneW / safezoneH) min 1.2))/2)";
			y = "14.6 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(safezoneY + (safezoneH - 					(			((safezoneW / safezoneH) min 1.2) / 1.2))/2)";
			w = "2.3 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "2 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			colorText[] = { 0, 0, 0, 0.5 };
		};
		class SlotSecondaryUnderBarrel : SlotPrimary
		{
			idc = 642;
			x = "29 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(safezoneX + (safezoneW - 					((safezoneW / safezoneH) min 1.2))/2)";
			y = "14.59 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(safezoneY + (safezoneH - 					(			((safezoneW / safezoneH) min 1.2) / 1.2))/2)";
			w = "2.3 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "2 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			colorText[] = { 0, 0, 0, 0.5 };
		};
		class SlotSecondaryFlashlight : SlotPrimary
		{
			idc = 626;
			x = "31.4 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(safezoneX + (safezoneW - 					((safezoneW / safezoneH) min 1.2))/2)";
			y = "14.6 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(safezoneY + (safezoneH - 					(			((safezoneW / safezoneH) min 1.2) / 1.2))/2)";
			w = "2.3 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "2 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			colorText[] = { 0, 0, 0, 0.5 };
		};
		class SlotSecondaryOptics : SlotPrimary
		{
			idc = 625;
			x = "33.8 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(safezoneX + (safezoneW - 					((safezoneW / safezoneH) min 1.2))/2)";
			y = "14.6 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(safezoneY + (safezoneH - 					(			((safezoneW / safezoneH) min 1.2) / 1.2))/2)";
			w = "2.3 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "2 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			colorText[] = { 0, 0, 0, 0.5 };
		};
		class SlotSecondaryMagazine : SlotPrimary
		{
			idc = 627;
			x = "36.2 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(safezoneX + (safezoneW - 					((safezoneW / safezoneH) min 1.2))/2)";
			y = "14.6 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(safezoneY + (safezoneH - 					(			((safezoneW / safezoneH) min 1.2) / 1.2))/2)";
			w = "2.3 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "2 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			colorText[] = { 0, 0, 0, 0.5 };
		};
		class SlotHandgun : SlotPrimary
		{
			idc = 612;
			x = "26.6 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(safezoneX + (safezoneW - 					((safezoneW / safezoneH) min 1.2))/2)";
			y = "17 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(safezoneY + (safezoneH - 					(			((safezoneW / safezoneH) min 1.2) / 1.2))/2)";
			w = "11.9 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "3 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			colorText[] = { 0, 0, 0, 0.5 };
		};
		class SlotHandgunMuzzle : SlotPrimary
		{
			idc = 628;
			x = "26.6 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(safezoneX + (safezoneW - 					((safezoneW / safezoneH) min 1.2))/2)";
			y = "20.1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(safezoneY + (safezoneH - 					(			((safezoneW / safezoneH) min 1.2) / 1.2))/2)";
			w = "2.3 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "2 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			colorText[] = { 0, 0, 0, 0.5 };
		};
		class SlotHandgunUnderBarrel : SlotPrimary
		{
			idc = 643;
			x = "29 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(safezoneX + (safezoneW - 					((safezoneW / safezoneH) min 1.2))/2)";
			y = "20.1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(safezoneY + (safezoneH - 					(			((safezoneW / safezoneH) min 1.2) / 1.2))/2)";
			w = "2.3 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "2 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			colorText[] = { 0, 0, 0, 0.5 };
		};
		class SlotHandgunFlashlight : SlotPrimary
		{
			idc = 630;
			x = "31.4 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(safezoneX + (safezoneW - 					((safezoneW / safezoneH) min 1.2))/2)";
			y = "20.1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(safezoneY + (safezoneH - 					(			((safezoneW / safezoneH) min 1.2) / 1.2))/2)";
			w = "2.3 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "2 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			colorText[] = { 0, 0, 0, 0.5 };
		};
		class SlotHandgunOptics : SlotPrimary
		{
			idc = 629;
			x = "33.8 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(safezoneX + (safezoneW - 					((safezoneW / safezoneH) min 1.2))/2)";
			y = "20.1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(safezoneY + (safezoneH - 					(			((safezoneW / safezoneH) min 1.2) / 1.2))/2)";
			w = "2.3 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "2 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			colorText[] = { 0, 0, 0, 0.5 };
		};
		class SlotHandgunMagazine : SlotPrimary
		{
			idc = 631;
			x = "36.2 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(safezoneX + (safezoneW - 					((safezoneW / safezoneH) min 1.2))/2)";
			y = "20.1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(safezoneY + (safezoneH - 					(			((safezoneW / safezoneH) min 1.2) / 1.2))/2)";
			w = "2.3 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "2 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			colorText[] = { 0, 0, 0, 0.5 };
		};
		class SlotHeadgear : SlotPrimary
		{
			idc = 6240;
			x = "26.6 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(safezoneX + (safezoneW - 					((safezoneW / safezoneH) min 1.2))/2)";
			y = "2.5 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(safezoneY + (safezoneH - 					(			((safezoneW / safezoneH) min 1.2) / 1.2))/2)";
			w = "2.9 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "2.9 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			colorText[] = { 0, 0, 0, 0.5 };
		};
	  // Custom
		class SlotHeadgearArmor : GroundLoad
		{
			idc = 7240;
			x = "26.6 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(safezoneX + (safezoneW - 					((safezoneW / safezoneH) min 1.2))/2)";
			y = "5.5 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(safezoneY + (safezoneH - 					(			((safezoneW / safezoneH) min 1.2) / 1.2))/2)";
			w = "2.9 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "0.25 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			colorText[] = { 0.6,0.6,0.6,1 };
		};

		class SlotGoggles : SlotPrimary
		{
			idc = 6216;
			x = "29.6 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(safezoneX + (safezoneW - 					((safezoneW / safezoneH) min 1.2))/2)";
			y = "2.5 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(safezoneY + (safezoneH - 					(			((safezoneW / safezoneH) min 1.2) / 1.2))/2)";
			w = "2.9 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "2.9 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			colorText[] = { 0, 0, 0, 0.5 };
		};
		class SlotHMD : SlotPrimary
		{
			idc = 6217;
			x = "32.6 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(safezoneX + (safezoneW - 					((safezoneW / safezoneH) min 1.2))/2)";
			y = "2.5 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(safezoneY + (safezoneH - 					(			((safezoneW / safezoneH) min 1.2) / 1.2))/2)";
			w = "2.9 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "2.9 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			colorText[] = { 0, 0, 0, 0.5 };
		};
		class SlotBinoculars : SlotPrimary
		{
			idc = 6238;
			x = "35.6 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(safezoneX + (safezoneW - 					((safezoneW / safezoneH) min 1.2))/2)";
			y = "2.5 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(safezoneY + (safezoneH - 					(			((safezoneW / safezoneH) min 1.2) / 1.2))/2)";
			w = "2.9 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "2.9 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			colorText[] = { 0, 0, 0, 0.5 };
		};
		class SlotMap : SlotPrimary
		{
			idc = 6211;
			x = "15.16 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(safezoneX + (safezoneW - 					((safezoneW / safezoneH) min 1.2))/2)";
			y = "20.1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(safezoneY + (safezoneH - 					(			((safezoneW / safezoneH) min 1.2) / 1.2))/2)";
			w = "2 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "2 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			colorText[] = { 0, 0, 0, 0.5 };
		};
		class SlotGPS : SlotPrimary
		{
			idc = 6215;
			x = "17.38 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(safezoneX + (safezoneW - 					((safezoneW / safezoneH) min 1.2))/2)";
			y = "20.1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(safezoneY + (safezoneH - 					(			((safezoneW / safezoneH) min 1.2) / 1.2))/2)";
			w = "2 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "2 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			colorText[] = { 0, 0, 0, 0.5 };
		};
		class SlotCompass : SlotPrimary
		{
			idc = 6212;
			x = "21.82 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(safezoneX + (safezoneW - 					((safezoneW / safezoneH) min 1.2))/2)";
			y = "20.1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(safezoneY + (safezoneH - 					(			((safezoneW / safezoneH) min 1.2) / 1.2))/2)";
			w = "2 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "2 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			colorText[] = { 0, 0, 0, 0.5 };
		};
		class SlotRadio : SlotPrimary
		{
			idc = 6214;
			x = "19.6 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(safezoneX + (safezoneW - 					((safezoneW / safezoneH) min 1.2))/2)";
			y = "20.1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(safezoneY + (safezoneH - 					(			((safezoneW / safezoneH) min 1.2) / 1.2))/2)";
			w = "2 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "2 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			colorText[] = { 0, 0, 0, 0.5 };
		};
		class SlotWatch : SlotPrimary
		{
			idc = 6213;
			x = "24.04 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(safezoneX + (safezoneW - 					((safezoneW / safezoneH) min 1.2))/2)";
			y = "20.1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(safezoneY + (safezoneH - 					(			((safezoneW / safezoneH) min 1.2) / 1.2))/2)";
			w = "2 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "2 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			colorText[] = { 0, 0, 0, 0.5 };
		};
		class UniformTab : GroundTab
		{
			idc = 6332;
			x = "15.1 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(safezoneX + (safezoneW - 					((safezoneW / safezoneH) min 1.2))/2)";
			y = "2.5 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(safezoneY + (safezoneH - 					(			((safezoneW / safezoneH) min 1.2) / 1.2))/2)";
			w = "3.5 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "3 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			colorBackground[] = { 1, 1, 1, 0.5 };
		};
		class UniformSlot : SlotPrimary
		{
			idc = 6331;
			x = "15.35 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(safezoneX + (safezoneW - 					((safezoneW / safezoneH) min 1.2))/2)";
			y = "2.5 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(safezoneY + (safezoneH - 					(			((safezoneW / safezoneH) min 1.2) / 1.2))/2)";
			w = "3 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "3 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			colorText[] = { 0, 0, 0, 0.5 };
		};
		class UniformLoad : GroundLoad
		{
			idc = 6304;
			x = "15.1 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(safezoneX + (safezoneW - 					((safezoneW / safezoneH) min 1.2))/2)";
			y = "5.75 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(safezoneY + (safezoneH - 					(			((safezoneW / safezoneH) min 1.2) / 1.2))/2)";
			w = "3.5 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "0.25 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
		};
		// Custom
		class UniformArmor : GroundLoad
		{
			idc = 7304;
			x = "15.1 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(safezoneX + (safezoneW - 					((safezoneW / safezoneH) min 1.2))/2)";
			y = "5.5 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(safezoneY + (safezoneH - 					(			((safezoneW / safezoneH) min 1.2) / 1.2))/2)";
			w = "3.5 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "0.25 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			colorText[] = { 0.6,0.6,0.6,1 };
		};

		class UniformContainer : GroundContainer
		{
			//onLBDblClick = "_this call EPOCH_itemInteract";
			onLBSelChanged = "_this call EPOCH_itemInteractV2";

			idc = 633;
			x = "15.1 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(safezoneX + (safezoneW - 					((safezoneW / safezoneH) min 1.2))/2)";
			y = "6 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(safezoneY + (safezoneH - 					(			((safezoneW / safezoneH) min 1.2) / 1.2))/2)";
			w = "11 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "14 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
		};
		class VestTab : UniformTab
		{
			idc = 6382;
			x = "18.85 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(safezoneX + (safezoneW - 					((safezoneW / safezoneH) min 1.2))/2)";
			y = "2.5 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(safezoneY + (safezoneH - 					(			((safezoneW / safezoneH) min 1.2) / 1.2))/2)";
			w = "3.5 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "3 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
		};
		class VestSlot : SlotPrimary
		{
			idc = 6381;
			x = "19.1 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(safezoneX + (safezoneW - 					((safezoneW / safezoneH) min 1.2))/2)";
			y = "2.5 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(safezoneY + (safezoneH - 					(			((safezoneW / safezoneH) min 1.2) / 1.2))/2)";
			w = "3 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "3 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			colorText[] = { 0, 0, 0, 0.5 };
		};
		class VestLoad : GroundLoad
		{
			idc = 6305;
			x = "18.85 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(safezoneX + (safezoneW - 					((safezoneW / safezoneH) min 1.2))/2)";
			y = "5.75 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(safezoneY + (safezoneH - 					(			((safezoneW / safezoneH) min 1.2) / 1.2))/2)";
			w = "3.5 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "0.25 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
		};

		// Custom
		class VestArmor : GroundLoad
		{
			idc = 7305;
			x = "18.85 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(safezoneX + (safezoneW - 					((safezoneW / safezoneH) min 1.2))/2)";
			y = "5.5 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(safezoneY + (safezoneH - 					(			((safezoneW / safezoneH) min 1.2) / 1.2))/2)";
			w = "3.5 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "0.25 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			colorText[] = { 0.6,0.6,0.6,1 };
		};

		class VestContainer : UniformContainer
		{
			idc = 638;
		};
		class BackpackTab : UniformTab
		{
			idc = 6192;
			x = "22.6 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(safezoneX + (safezoneW - 					((safezoneW / safezoneH) min 1.2))/2)";
			y = "2.5 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(safezoneY + (safezoneH - 					(			((safezoneW / safezoneH) min 1.2) / 1.2))/2)";
			w = "3.5 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "3 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
		};

		class BackpackSlot : SlotPrimary
		{
			idc = 6191;
			x = "22.85 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(safezoneX + (safezoneW - 					((safezoneW / safezoneH) min 1.2))/2)";
			y = "2.5 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(safezoneY + (safezoneH - 					(			((safezoneW / safezoneH) min 1.2) / 1.2))/2)";
			w = "3 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "3 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			colorText[] = { 0, 0, 0, 0.5 };
		};
		class BackpackLoad : GroundLoad
		{
			idc = 6306;
			x = "22.6 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(safezoneX + (safezoneW - 					((safezoneW / safezoneH) min 1.2))/2)";
			y = "5.5 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(safezoneY + (safezoneH - 					(			((safezoneW / safezoneH) min 1.2) / 1.2))/2)";
			w = "3.5 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "0.5 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
		};
		class BackpackContainer : UniformContainer
		{
			idc = 619;
		};
		class TotalLoad : GroundLoad
		{
			idc = 6308;
			x = "15.1 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(safezoneX + (safezoneW - 					((safezoneW / safezoneH) min 1.2))/2)";
			y = "23.0 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(safezoneY + (safezoneH - 					(			((safezoneW / safezoneH) min 1.2) / 1.2))/2)";
			w = "23.4 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "0.5 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
		};
		// Custom
		class TotalArmor : GroundLoad
		{
			idc = 7308;
			x = "15.1 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(safezoneX + (safezoneW - 					((safezoneW / safezoneH) min 1.2))/2)";
			y = "22.5 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(safezoneY + (safezoneH - 					(			((safezoneW / safezoneH) min 1.2) / 1.2))/2)";
			w = "23.4 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "0.5 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			colorText[] = { 0.6,0.6,0.6,1 };
		};
		class TotalArmorCompare : RscCustomProgress
		{
			idc = 7309;
			x = "15.1 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(safezoneX + (safezoneW - 					((safezoneW / safezoneH) min 1.2))/2)";
			y = "22.5 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(safezoneY + (safezoneH - 					(			((safezoneW / safezoneH) min 1.2) / 1.2))/2)";
			w = "23.4 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "0.5 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			colorText[] = { 0.4,0.6,1,0.4 };
		};

		class ContainerMarker : GroundTab
		{
			idc = 6325;
			x = "0 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(safezoneX + (safezoneW - 					((safezoneW / safezoneH) min 1.2))/2)";
			y = "24 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(safezoneY + (safezoneH - 					(			((safezoneW / safezoneH) min 1.2) / 1.2))/2)";
			w = "1 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
		};
		class GroundMarker : ContainerMarker
		{
			idc = 6385;
			x = "1.5 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(safezoneX + (safezoneW - 					((safezoneW / safezoneH) min 1.2))/2)";
			y = "24 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(safezoneY + (safezoneH - 					(			((safezoneW / safezoneH) min 1.2) / 1.2))/2)";
			w = "1 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
		};
		class SoldierMarker : ContainerMarker
		{
			idc = 6405;
			x = "3 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(safezoneX + (safezoneW - 					((safezoneW / safezoneH) min 1.2))/2)";
			y = "24 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(safezoneY + (safezoneH - 					(			((safezoneW / safezoneH) min 1.2) / 1.2))/2)";
			w = "1 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
		};

		class EpochBtnBG : IGUIBack
		{
			idc = -10;
			

			//x = 0.433468 * safezoneW + safezoneX;
			//y = 0.75872 * safezoneH + safezoneY;
			//w = 0.30231 * safezoneW;
			//h = 0.0337482 * safezoneH;
			
			x = "14.5 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(safezoneX + (safezoneW - 					((safezoneW / safezoneH) min 1.2))/2)";
			y = "23.9 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(safezoneY + (safezoneH - 					(			((safezoneW / safezoneH) min 1.2) / 1.2))/2)";
			w = "24.5 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "1.7 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";

			colorBackground[] = { 0.05, 0.05, 0.05, 0.7 };
		};
		class EpochBTN1 : RscButtonMenu
		{
			idc = -11;
			text = "Group Menu";
			onMouseButtonDown = "_this call EPOCH_Inventory_Group";
			
			//x = 0.437079 * safezoneW + safezoneX;
			//y = 0.764 * safezoneH + safezoneY;
			//w = 0.0711741 * safezoneW;
			//h = 0.022 * safezoneH;
			
			x = "33.2 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(safezoneX + (safezoneW - 					((safezoneW / safezoneH) min 1.2))/2)";
			y = "24 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(safezoneY + (safezoneH - 					(			((safezoneW / safezoneH) min 1.2) / 1.2))/2)";
			w = "6 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "1.5 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
		};
		class EpochBTN2 : RscButtonMenu
		{
			idc = -12;
			text = "Requests";
			onMouseButtonDown = "_this call EPOCH_Inventory_iGroup";
			
			//x = 0.511347 * safezoneW + safezoneX;
			//y = 0.764 * safezoneH + safezoneY;
			//w = 0.0711741 * safezoneW;
			//h = 0.022 * safezoneH;
			
			x = "27.0 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(safezoneX + (safezoneW - 					((safezoneW / safezoneH) min 1.2))/2)";
			y = "24 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(safezoneY + (safezoneH - 					(			((safezoneW / safezoneH) min 1.2) / 1.2))/2)";
			w = "6 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "1.5 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
		};
		class EpochBTN3 : RscButtonMenu
		{
			idc = -13;
			text = "EXAMINE";
			onMouseButtonDown = "call EPOCH_consumeItem";
			
			//x = 0.585617 * safezoneW + safezoneX;
			//y = 0.764 * safezoneH + safezoneY;
			//w = 0.0711741 * safezoneW;
			//h = 0.022 * safezoneH;
			
			x = "14.62 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(safezoneX + (safezoneW - 					((safezoneW / safezoneH) min 1.2))/2)";
			y = "24 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(safezoneY + (safezoneH - 					(			((safezoneW / safezoneH) min 1.2) / 1.2))/2)";
			w = "6 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "1.5 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
		};
		class EpochBTN4 : RscButtonMenu
		{
			idc = -14;
			text = "CRAFT";
			onMouseButtonDown = "EPOCH_CraftingItem call EPOCH_crafting_load;";
			
			//x = 0.659883 * safezoneW + safezoneX;
			//y = 0.764 * safezoneH + safezoneY;
			//w = 0.0711741 * safezoneW;
			//h = 0.022 * safezoneH;
			
			x = "20.8 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(safezoneX + (safezoneW - 					((safezoneW / safezoneH) min 1.2))/2)";
			y = "24 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(safezoneY + (safezoneH - 					(			((safezoneW / safezoneH) min 1.2) / 1.2))/2)";
			w = "6 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "1.5 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";


		};
	};
};
class RscDisplayInterrupt: RscStandardDisplay //convert to preprocessFileNumbers
{
	onLoad = "[""onLoad"",_this,""RscDisplayInterrupt"",'GUI'] call (uinamespace getvariable 'BIS_fnc_initDisplay'); _this call EPOCH_InterruptConfig;";
};

class RscDisplayMPInterrupt: RscStandardDisplay
{
	onLoad = "[""onLoad"",_this,""Epoch_onPause"",'Epoch'] call compile preprocessfilelinenumbers ""A3\ui_f\scripts\initDisplay.sqf"";[""onLoad"",_this,""RscDisplayMPInterrupt"",'Epoch'] call compile preprocessfilelinenumbers ""A3\ui_f\scripts\initDisplay.sqf"";_this call EPOCH_InterruptConfig;";
	//onLoad = "[""onLoad"",_this,""RscDisplayMPInterrupt"",'GUI'] call compile preprocessfilelinenumbers ""A3\ui_f\scripts\initDisplay.sqf""";
	onUnload = "[""onUnload"",_this,""RscDisplayMPInterrupt"",'Epoch'] call compile preprocessfilelinenumbers ""A3\ui_f\scripts\initDisplay.sqf""";
};
class RscDisplayRemoteMissions: RscStandardDisplay
{
	onLoad = "[""onLoad"",_this,""RscDisplayRemoteMissions"",'GUI'] call compile preprocessfilelinenumbers ""A3\ui_f\scripts\initDisplay.sqf"";execVM ""\x\addons\a3_epoch_code\system\dummy.sqf""";
};
class RscDisplayPassword: RscStandardDisplay
{
	onLoad = "[""onLoad"",_this,""RscDisplayPassword"",'GUI'] call compile preprocessfilelinenumbers ""A3\ui_f\scripts\initDisplay.sqf"";execVM ""\x\addons\a3_epoch_code\system\dummy.sqf""";
};
class RscConfigEditor_Main{onLoad = "missionNamespace setVariable ['yolo',true];(_this select 0) closeDisplay 0";};
class RscDisplayDebriefing: RscStandardDisplay
{
	onLoad = "(_this select 0) closeDisplay 0";
};
class RscDisplayMain: RscStandardDisplay
{
	onLoad = "_this call compile preprocessfilelinenumbers ""\x\addons\a3_epoch_code\gui\scripts\Epoch_handleWelcomeScreen.sqf""";
	//onLoad = "_this call compile preprocessfilelinenumbers ""\x\addons\a3_epoch_code\gui\scripts\Epoch_handleWelcomeScreen.sqf"";[""onLoad"",_this,""RscDisplayMain"",'BootcampDisplays'] call compile preprocessfilelinenumbers ""A3\ui_f\scripts\initDisplay.sqf""";
};
class RscDisplayClientGetReady: RscDisplayGetReady
{
	onLoad = "uiNamespace setVariable ['Epoch_freshServer', true]; ctrlActivate ((_this select 0) displayCtrl 1); (_this select 0) closeDisplay 1";
	//onLoad = "[""onLoad"",_this,""RscDiary"",'GUI'] call compile preprocessfilelinenumbers ""A3\ui_f\scripts\initDisplay.sqf""";
};
class RscDisplayWelcome;
class RscWelcomeEpoch : RscDisplayWelcome
{
	idd = -666;
	onLoad = "[""onLoad"",[(_this select 0),""Welcome""],""Epoch_welcomeScreen"",'Epoch'] call compile preprocessfilelinenumbers ""A3\ui_f\scripts\initDisplay.sqf"""; //Used when we have it outside of the game
};
class RscDisplayInfo : RscWelcomeEpoch
{
	onLoad = "[""onLoad"",[(_this select 0),""Custom""],""Epoch_welcomeScreen"",'Epoch'] call compile preprocessfilelinenumbers ""A3\ui_f\scripts\initDisplay.sqf"""; //Used when we have it outside of the game}
};
class RscVersionUpdateEpoch : RscWelcomeEpoch
{
	onLoad = "[""onLoad"",[(_this select 0),""Changelog""],""Epoch_welcomeScreen"",'Epoch'] call compile preprocessfilelinenumbers ""A3\ui_f\scripts\initDisplay.sqf"""; //Used when we have it outside of the game}
};
class RscInGameUI
{
	colorReady[] = {"(profilenamespace getvariable ['IGUI_TEXT_RGB_R',0])","(profilenamespace getvariable ['IGUI_TEXT_RGB_G',1])","(profilenamespace getvariable ['IGUI_TEXT_RGB_B',1])","(profilenamespace getvariable ['IGUI_TEXT_RGB_A',0.8])"};
	colorPrepare[] = {"(profilenamespace getvariable ['IGUI_WARNING_RGB_R',0.8])","(profilenamespace getvariable ['IGUI_WARNING_RGB_G',0.5])","(profilenamespace getvariable ['IGUI_WARNING_RGB_B',0.0])","(profilenamespace getvariable ['IGUI_WARNING_RGB_A',0.8])"};
	colorUnload[] = {"(profilenamespace getvariable ['IGUI_ERROR_RGB_R',0.8])","(profilenamespace getvariable ['IGUI_ERROR_RGB_G',0.0])","(profilenamespace getvariable ['IGUI_ERROR_RGB_B',0.0])","(profilenamespace getvariable ['IGUI_ERROR_RGB_A',1.0])"};
	class RscUnitInfo
	{
		onLoad = "[""onLoad"",_this,""RscUnitInfo"",'IGUI'] call compile preprocessfilelinenumbers ""A3\ui_f\scripts\initDisplay.sqf""";
		onUnload = "[""onUnload"",_this,""RscUnitInfo"",'IGUI'] call compile preprocessfilelinenumbers ""A3\ui_f\scripts\initDisplay.sqf""";
		idd = 300;
		updateWidthByWeapon = 0;
		updateHeightByCrew = 0;
		updateWidthByCrew = 0;
		controls[] = {"WeaponInfoControlsGroupRight","CA_BackgroundVehicle","CA_BackgroundVehicleTitle","CA_BackgroundVehicleTitleDark","CA_BackgroundFuel","CA_Vehicle","CA_VehicleRole","CA_HitZones","CA_SpeedBackground","CA_SpeedUnits","CA_Speed","CA_ValueFuel"};
		class WeaponInfoControlsGroupLeft: RscControlsGroup
		{
			idc = 2302;
			x = "0 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(profilenamespace getvariable [""IGUI_GRID_WEAPON_X"",		((safezoneX + safezoneW) - 		(12.4 * 			(			((safezoneW / safezoneH) min 1.2) / 40)) - 0.5 * 			(			((safezoneW / safezoneH) min 1.2) / 40))])";
			y = "0 * 			(		(		((safezoneW / safezoneH) min 1.2) / 1.2) / 20) + 			(safezoneY + safezoneH - 		(		((safezoneW / safezoneH) min 1.2) / 1.2)) +  			18 * 			(		(		((safezoneW / safezoneH) min 1.2) / 1.2) / 20) - (1 * 			(		(		((safezoneW / safezoneH) min 1.2) / 1.2) / 20))";


			w = "10 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "6 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			class controls
			{
				class CA_BackgroundWeapon: RscPicture
				{
					colorText[] = {"(profilenamespace getvariable ['IGUI_BCG_RGB_R',0])","(profilenamespace getvariable ['IGUI_BCG_RGB_G',1])","(profilenamespace getvariable ['IGUI_BCG_RGB_B',1])","(profilenamespace getvariable ['IGUI_BCG_RGB_A',0.8])"};
					idc = 1202;
					text = "\A3\ui_f\data\igui\rscingameui\rscunitinfo\gradient_ca.paa";
					x = "0 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
					y = "1.2 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
					w = "10 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
					h = "2.5 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
				};
				class CA_BackgroundWeaponTitle: RscText
				{
					colorBackground[] = {"(profilenamespace getvariable ['IGUI_BCG_RGB_R',0])","(profilenamespace getvariable ['IGUI_BCG_RGB_G',1])","(profilenamespace getvariable ['IGUI_BCG_RGB_B',1])","(profilenamespace getvariable ['IGUI_BCG_RGB_A',0.8])"};
					idc = 1001;
					x = "0 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
					y = "0 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
					w = "10 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
					h = "1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
					sizeEx = "0.8 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
				};
				class CA_BackgroundWeaponTitleDark: RscText
				{
					idc = 1008;
					x = "0 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
					y = "0 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
					w = "10 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
					h = "1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
					colorBackground[] = {0,0,0,0.1};
					sizeEx = "0.8 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
				};
				class CA_BackgroundWeaponMode: RscPicture
				{
					colorText[] = {"(profilenamespace getvariable ['IGUI_BCG_RGB_R',0])","(profilenamespace getvariable ['IGUI_BCG_RGB_G',1])","(profilenamespace getvariable ['IGUI_BCG_RGB_B',1])","(profilenamespace getvariable ['IGUI_BCG_RGB_A',0.8])"};
					idc = 1203;
					text = "\A3\ui_f\data\igui\rscingameui\rscunitinfo\mode_background_ca.paa";
					x = "0 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
					y = "1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
					w = "10 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
					h = "0.2 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
				};
				class CA_ValueReload: RscIGProgress
				{
					idc = 154;
					colorBar[] = {"(profilenamespace getvariable ['IGUI_TEXT_RGB_R',0])","(profilenamespace getvariable ['IGUI_TEXT_RGB_G',1])","(profilenamespace getvariable ['IGUI_TEXT_RGB_B',1])",0.25};
					colorFrame[] = {0,0,0,0};
					style = 0;
					x = "0 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
					y = "1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
					w = "10 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
					h = "0.2 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
				};
				class CA_Weapon: RscText
				{
					idc = 118;
					colorText[] = {"(profilenamespace getvariable ['IGUI_TEXT_RGB_R',0])","(profilenamespace getvariable ['IGUI_TEXT_RGB_G',1])","(profilenamespace getvariable ['IGUI_TEXT_RGB_B',1])","(profilenamespace getvariable ['IGUI_TEXT_RGB_A',0.8])"};
					style = 1;
					x = "0 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
					y = "0 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
					w = "10 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
					h = "1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
					sizeEx = "0.8 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
				};
				class CA_ModeTexture: RscPicture
				{
					idc = 187;
					colorText[] = {"(profilenamespace getvariable ['IGUI_TEXT_RGB_R',0])","(profilenamespace getvariable ['IGUI_TEXT_RGB_G',1])","(profilenamespace getvariable ['IGUI_TEXT_RGB_B',1])","(profilenamespace getvariable ['IGUI_TEXT_RGB_A',0.8])"};
					x = "0 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
					y = "1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
					w = "10 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
					h = "0.2 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
				};
				class CA_Mode: RscText
				{
					idc = 149;
					colorText[] = {"(profilenamespace getvariable ['IGUI_TEXT_RGB_R',0])","(profilenamespace getvariable ['IGUI_TEXT_RGB_G',1])","(profilenamespace getvariable ['IGUI_TEXT_RGB_B',1])","(profilenamespace getvariable ['IGUI_TEXT_RGB_A',0.8])"};
					y = -1;
					x = "-5 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
					w = "4.5 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
					h = "1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
					sizeEx = "0.8 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
				};
				class CA_AmmoCount: RscText
				{
					idc = 184;
					style = 1;
					colorText[] = {"(profilenamespace getvariable ['IGUI_TEXT_RGB_R',0])","(profilenamespace getvariable ['IGUI_TEXT_RGB_G',1])","(profilenamespace getvariable ['IGUI_TEXT_RGB_B',1])","(profilenamespace getvariable ['IGUI_TEXT_RGB_A',0.8])"};
					x = "4.5 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
					y = "1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
					w = "3.5 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
					h = "1.5 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
					sizeEx = "1.5 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
				};
				class CA_MagCount: RscText
				{
					colorText[] = {"(profilenamespace getvariable ['IGUI_TEXT_RGB_R',0])","(profilenamespace getvariable ['IGUI_TEXT_RGB_G',1])","(profilenamespace getvariable ['IGUI_TEXT_RGB_B',1])","(profilenamespace getvariable ['IGUI_TEXT_RGB_A',0.8])"};
					idc = 185;
					x = "8 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
					y = "1.5 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
					w = "2 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
					h = "1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
					sizeEx = "0.8 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
				};
				class CA_AmmoType: RscText
				{
					idc = 155;
					colorText[] = {"(profilenamespace getvariable ['IGUI_TEXT_RGB_R',0])","(profilenamespace getvariable ['IGUI_TEXT_RGB_G',1])","(profilenamespace getvariable ['IGUI_TEXT_RGB_B',1])","(profilenamespace getvariable ['IGUI_TEXT_RGB_A',0.8])"};
					x = "0 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
					y = "1.5 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
					w = "4.5 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
					h = "1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
					sizeEx = "0.8 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
				};
				class CA_GrenadeType: RscText
				{
					colorText[] = {"(profilenamespace getvariable ['IGUI_TEXT_RGB_R',0])","(profilenamespace getvariable ['IGUI_TEXT_RGB_G',1])","(profilenamespace getvariable ['IGUI_TEXT_RGB_B',1])","(profilenamespace getvariable ['IGUI_TEXT_RGB_A',0.8])"};
					style = 2;
					idc = 152;
					x = "3.5 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
					y = "2.5 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
					w = "4.5 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
					h = "1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
					sizeEx = "0.8 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
				};
				class CA_GrenadeCount: RscText
				{
					colorText[] = {"(profilenamespace getvariable ['IGUI_TEXT_RGB_R',0])","(profilenamespace getvariable ['IGUI_TEXT_RGB_G',1])","(profilenamespace getvariable ['IGUI_TEXT_RGB_B',1])","(profilenamespace getvariable ['IGUI_TEXT_RGB_A',0.8])"};
					style = 1;
					idc = 151;
					x = "8 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
					y = "2.5 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
					w = "2 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
					h = "1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
					sizeEx = "0.8 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
				};
				class CA_GunnerWeapon: RscText
				{
					idc = 150;
					colorText[] = {"(profilenamespace getvariable ['IGUI_TEXT_RGB_R',0])","(profilenamespace getvariable ['IGUI_TEXT_RGB_G',1])","(profilenamespace getvariable ['IGUI_TEXT_RGB_B',1])","(profilenamespace getvariable ['IGUI_TEXT_RGB_A',0.8])"};
					colorBackground[] = {"(profilenamespace getvariable ['IGUI_BCG_RGB_R',0])","(profilenamespace getvariable ['IGUI_BCG_RGB_G',1])","(profilenamespace getvariable ['IGUI_BCG_RGB_B',1])","(profilenamespace getvariable ['IGUI_BCG_RGB_A',0.8])"};
					style = 1;
					x = "0 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
					y = "4 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
					w = "10 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
					h = "1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
					sizeEx = "0.8 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
				};
			};
		};
		class WeaponInfoControlsGroupRight: RscControlsGroup
		{
			idc = 2303;
			x = "0 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(profilenamespace getvariable [""IGUI_GRID_WEAPON_X"",		((safezoneX + safezoneW) - 		(12.4 * 			(			((safezoneW / safezoneH) min 1.2) / 40)) - 0.5 * 			(			((safezoneW / safezoneH) min 1.2) / 40))])";
			y = "0 * 			(		(		((safezoneW / safezoneH) min 1.2) / 1.2) / 20) + 			(safezoneY + safezoneH - 		(		((safezoneW / safezoneH) min 1.2) / 1.2)) +  			18 * 			(		(		((safezoneW / safezoneH) min 1.2) / 1.2) / 20) - (1 * 			(		(		((safezoneW / safezoneH) min 1.2) / 1.2) / 20))";
			w = "10 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "6 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			class controls
			{
				class CA_BackgroundWeapon: RscPicture
				{
					colorText[] = {"(profilenamespace getvariable ['IGUI_BCG_RGB_R',0])","(profilenamespace getvariable ['IGUI_BCG_RGB_G',1])","(profilenamespace getvariable ['IGUI_BCG_RGB_B',1])","(profilenamespace getvariable ['IGUI_BCG_RGB_A',0.8])"};
					idc = 1202;
					text = "\A3\ui_f\data\igui\rscingameui\rscunitinfo\gradient_ca.paa";
					x = "0 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
					y = "1.2 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
					w = "10 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
					h = "2.5 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
				};
				class CA_BackgroundWeaponTitle: RscText
				{
					colorBackground[] = {"(profilenamespace getvariable ['IGUI_BCG_RGB_R',0])","(profilenamespace getvariable ['IGUI_BCG_RGB_G',1])","(profilenamespace getvariable ['IGUI_BCG_RGB_B',1])","(profilenamespace getvariable ['IGUI_BCG_RGB_A',0.8])"};
					idc = 1001;
					x = "0 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
					y = "0 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
					w = "10 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
					h = "1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
					sizeEx = "0.8 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
				};
				class CA_BackgroundWeaponTitleDark: RscText
				{
					idc = 1008;
					x = "0 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
					y = "0 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
					w = "10 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
					h = "1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
					colorBackground[] = {0,0,0,0.1};
					sizeEx = "0.8 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
				};
				class CA_BackgroundWeaponMode: RscPicture
				{
					colorText[] = {"(profilenamespace getvariable ['IGUI_BCG_RGB_R',0])","(profilenamespace getvariable ['IGUI_BCG_RGB_G',1])","(profilenamespace getvariable ['IGUI_BCG_RGB_B',1])","(profilenamespace getvariable ['IGUI_BCG_RGB_A',0.8])"};
					idc = 1203;
					text = "\A3\ui_f\data\igui\rscingameui\rscunitinfo\mode_background_ca.paa";
					x = "0 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
					y = "1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
					w = "10 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
					h = "0.2 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
				};
				class CA_ValueReload: RscIGProgress
				{
					idc = 154;
					colorBar[] = {"(profilenamespace getvariable ['IGUI_TEXT_RGB_R',0])","(profilenamespace getvariable ['IGUI_TEXT_RGB_G',1])","(profilenamespace getvariable ['IGUI_TEXT_RGB_B',1])",0.25};
					colorFrame[] = {0,0,0,0};
					style = 0;
					x = "0 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
					y = "1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
					w = "10 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
					h = "0.2 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
				};
				class CA_Weapon: RscText
				{
					idc = 118;
					colorText[] = {"(profilenamespace getvariable ['IGUI_TEXT_RGB_R',0])","(profilenamespace getvariable ['IGUI_TEXT_RGB_G',1])","(profilenamespace getvariable ['IGUI_TEXT_RGB_B',1])","(profilenamespace getvariable ['IGUI_TEXT_RGB_A',0.8])"};
					style = 1;
					x = "0 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
					y = "0 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
					w = "10 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
					h = "1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
					sizeEx = "0.8 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
				};
				class CA_ModeTexture: RscPicture
				{
					idc = 187;
					colorText[] = {"(profilenamespace getvariable ['IGUI_TEXT_RGB_R',0])","(profilenamespace getvariable ['IGUI_TEXT_RGB_G',1])","(profilenamespace getvariable ['IGUI_TEXT_RGB_B',1])","(profilenamespace getvariable ['IGUI_TEXT_RGB_A',0.8])"};
					x = "0 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
					y = "1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
					w = "10 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
					h = "0.2 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
				};
				class CA_Mode: RscText
				{
					idc = 149;
					colorText[] = {"(profilenamespace getvariable ['IGUI_TEXT_RGB_R',0])","(profilenamespace getvariable ['IGUI_TEXT_RGB_G',1])","(profilenamespace getvariable ['IGUI_TEXT_RGB_B',1])","(profilenamespace getvariable ['IGUI_TEXT_RGB_A',0.8])"};
					y = -1;
					x = "-5 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
					w = "4.5 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
					h = "1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
					sizeEx = "0.8 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
				};
				class CA_AmmoCount: RscText
				{
					idc = 184;
					style = 1;
					colorText[] = {"(profilenamespace getvariable ['IGUI_TEXT_RGB_R',0])","(profilenamespace getvariable ['IGUI_TEXT_RGB_G',1])","(profilenamespace getvariable ['IGUI_TEXT_RGB_B',1])","(profilenamespace getvariable ['IGUI_TEXT_RGB_A',0.8])"};
					x = "4.5 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
					y = "1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
					w = "3.5 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
					h = "1.5 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
					sizeEx = "1.5 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
				};
				class CA_MagCount: RscText
				{
					colorText[] = {"(profilenamespace getvariable ['IGUI_TEXT_RGB_R',0])","(profilenamespace getvariable ['IGUI_TEXT_RGB_G',1])","(profilenamespace getvariable ['IGUI_TEXT_RGB_B',1])","(profilenamespace getvariable ['IGUI_TEXT_RGB_A',0.8])"};
					idc = 185;
					x = "8 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
					y = "1.5 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
					w = "2 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
					h = "1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
					sizeEx = "0.8 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
				};
				class CA_AmmoType: RscText
				{
					idc = 155;
					colorText[] = {"(profilenamespace getvariable ['IGUI_TEXT_RGB_R',0])","(profilenamespace getvariable ['IGUI_TEXT_RGB_G',1])","(profilenamespace getvariable ['IGUI_TEXT_RGB_B',1])","(profilenamespace getvariable ['IGUI_TEXT_RGB_A',0.8])"};
					x = "0 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
					y = "1.5 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
					w = "4.5 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
					h = "1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
					sizeEx = "0.8 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
				};
				class CA_GrenadeType: RscText
				{
					colorText[] = {"(profilenamespace getvariable ['IGUI_TEXT_RGB_R',0])","(profilenamespace getvariable ['IGUI_TEXT_RGB_G',1])","(profilenamespace getvariable ['IGUI_TEXT_RGB_B',1])","(profilenamespace getvariable ['IGUI_TEXT_RGB_A',0.8])"};
					style = 2;
					idc = 152;
					x = "3.5 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
					y = "2.5 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
					w = "4.5 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
					h = "1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
					sizeEx = "0.8 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
				};
				class CA_GrenadeCount: RscText
				{
					colorText[] = {"(profilenamespace getvariable ['IGUI_TEXT_RGB_R',0])","(profilenamespace getvariable ['IGUI_TEXT_RGB_G',1])","(profilenamespace getvariable ['IGUI_TEXT_RGB_B',1])","(profilenamespace getvariable ['IGUI_TEXT_RGB_A',0.8])"};
					style = 1;
					idc = 151;
					x = "8 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
					y = "2.5 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
					w = "2 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
					h = "1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
					sizeEx = "0.8 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
				};
				class CA_GunnerWeapon: RscText
				{
					idc = 150;
					colorText[] = {"(profilenamespace getvariable ['IGUI_TEXT_RGB_R',0])","(profilenamespace getvariable ['IGUI_TEXT_RGB_G',1])","(profilenamespace getvariable ['IGUI_TEXT_RGB_B',1])","(profilenamespace getvariable ['IGUI_TEXT_RGB_A',0.8])"};
					colorBackground[] = {"(profilenamespace getvariable ['IGUI_BCG_RGB_R',0])","(profilenamespace getvariable ['IGUI_BCG_RGB_G',1])","(profilenamespace getvariable ['IGUI_BCG_RGB_B',1])","(profilenamespace getvariable ['IGUI_BCG_RGB_A',0.8])"};
					style = 1;
					x = "0 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
					y = "4 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
					w = "10 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
					h = "1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
					sizeEx = "0.8 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
				};
			};
		};
		class CA_BackgroundVehicle: RscPicture
		{
			colorText[] = {"(profilenamespace getvariable ['IGUI_BCG_RGB_R',0])","(profilenamespace getvariable ['IGUI_BCG_RGB_G',1])","(profilenamespace getvariable ['IGUI_BCG_RGB_B',1])","(profilenamespace getvariable ['IGUI_BCG_RGB_A',0.8])"};
			idc = 1200;
			text = "\A3\ui_f\data\igui\rscingameui\rscunitinfo\gradient_ca.paa";
			x = "0 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(profilenamespace getvariable [""IGUI_GRID_VEHICLE_X"",		(safezoneX + 0.5 * 			(			((safezoneW / safezoneH) min 1.2) / 40))])";
			y = "1.2 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(profilenamespace getvariable [""IGUI_GRID_VEHICLE_Y"",		(safezoneY + 0.5 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25))])";
			w = "10 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "2.3 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
		};
		class CA_BackgroundVehicleTitle: RscText
		{
			colorBackground[] = {"(profilenamespace getvariable ['IGUI_BCG_RGB_R',0])","(profilenamespace getvariable ['IGUI_BCG_RGB_G',1])","(profilenamespace getvariable ['IGUI_BCG_RGB_B',1])","(profilenamespace getvariable ['IGUI_BCG_RGB_A',0.8])"};
			idc = 1000;
			x = "0 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(profilenamespace getvariable [""IGUI_GRID_VEHICLE_X"",		(safezoneX + 0.5 * 			(			((safezoneW / safezoneH) min 1.2) / 40))])";
			y = "0 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(profilenamespace getvariable [""IGUI_GRID_VEHICLE_Y"",		(safezoneY + 0.5 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25))])";
			w = "10 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			sizeEx = "0.8 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
		};
		class CA_BackgroundVehicleTitleDark: RscText
		{
			idc = 1013;
			x = "0 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(profilenamespace getvariable [""IGUI_GRID_VEHICLE_X"",		(safezoneX + 0.5 * 			(			((safezoneW / safezoneH) min 1.2) / 40))])";
			y = "0 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(profilenamespace getvariable [""IGUI_GRID_VEHICLE_Y"",		(safezoneY + 0.5 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25))])";
			w = "10 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			colorBackground[] = {0,0,0,0.1};
			sizeEx = "0.8 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
		};
		class CA_BackgroundFuel: RscPicture
		{
			colorText[] = {"(profilenamespace getvariable ['IGUI_BCG_RGB_R',0])","(profilenamespace getvariable ['IGUI_BCG_RGB_G',1])","(profilenamespace getvariable ['IGUI_BCG_RGB_B',1])","(profilenamespace getvariable ['IGUI_BCG_RGB_A',0.8])"};
			idc = 1202;
			text = "\A3\ui_f\data\igui\rscingameui\rscunitinfo\fuelBackground_ca.paa";
			x = "0 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(profilenamespace getvariable [""IGUI_GRID_VEHICLE_X"",		(safezoneX + 0.5 * 			(			((safezoneW / safezoneH) min 1.2) / 40))])";
			y = "1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(profilenamespace getvariable [""IGUI_GRID_VEHICLE_Y"",		(safezoneY + 0.5 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25))])";
			w = "10 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "0.2 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
		};
		class CA_Vehicle: RscText
		{
			colorText[] = {"(profilenamespace getvariable ['IGUI_TEXT_RGB_R',0])","(profilenamespace getvariable ['IGUI_TEXT_RGB_G',1])","(profilenamespace getvariable ['IGUI_TEXT_RGB_B',1])","(profilenamespace getvariable ['IGUI_TEXT_RGB_A',0.8])"};
			idc = 120;
			text = "AH-99 Blackfoot";
			x = "0 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(profilenamespace getvariable [""IGUI_GRID_VEHICLE_X"",		(safezoneX + 0.5 * 			(			((safezoneW / safezoneH) min 1.2) / 40))])";
			y = "0 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(profilenamespace getvariable [""IGUI_GRID_VEHICLE_Y"",		(safezoneY + 0.5 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25))])";
			w = "8.5 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			sizeEx = "0.8 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
		};
		class CA_VehicleRole: RscPicture
		{
			colorText[] = {"(profilenamespace getvariable ['IGUI_TEXT_RGB_R',0])","(profilenamespace getvariable ['IGUI_TEXT_RGB_G',1])","(profilenamespace getvariable ['IGUI_TEXT_RGB_B',1])","(profilenamespace getvariable ['IGUI_TEXT_RGB_A',0.8])"};
			shadow = 1;
			idc = 208;
			textureCargo = "\A3\ui_f\data\igui\rscingameui\rscunitinfo\role_cargo_ca.paa";
			textureCommander = "\A3\ui_f\data\igui\rscingameui\rscunitinfo\role_commander_ca.paa";
			textureDriver = "\A3\ui_f\data\igui\rscingameui\rscunitinfo\role_driver_ca.paa";
			textureGunner = "\A3\ui_f\data\igui\rscingameui\rscunitinfo\role_gunner_ca.paa";
			text = "#(argb,8,8,3)color(1,1,1,0)";
			x = "9 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(profilenamespace getvariable [""IGUI_GRID_VEHICLE_X"",		(safezoneX + 0.5 * 			(			((safezoneW / safezoneH) min 1.2) / 40))])";
			y = "0 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(profilenamespace getvariable [""IGUI_GRID_VEHICLE_Y"",		(safezoneY + 0.5 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25))])";
			w = "1 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
		};
		class CA_ValueFuel: RscProgress
		{
			idc = 113;
			texture = "#(argb,8,8,3)color(1,1,1,1)";
			text = "#(argb,8,8,3)color(1,1,1,1)";
			x = "0 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(profilenamespace getvariable [""IGUI_GRID_VEHICLE_X"",		(safezoneX + 0.5 * 			(			((safezoneW / safezoneH) min 1.2) / 40))])";
			y = "1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(profilenamespace getvariable [""IGUI_GRID_VEHICLE_Y"",		(safezoneY + 0.5 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25))])";
			w = "10 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "0.2 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
		};
		class CA_SpeedBackground: RscText
		{
			shadow = 0;
			font = "PuristaSemibold";
			idc = 1006;
			x = "5.5 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(profilenamespace getvariable [""IGUI_GRID_VEHICLE_X"",		(safezoneX + 0.5 * 			(			((safezoneW / safezoneH) min 1.2) / 40))])";
			y = "1.3 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(profilenamespace getvariable [""IGUI_GRID_VEHICLE_Y"",		(safezoneY + 0.5 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25))])";
			w = "4.4 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "0.9 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			colorText[] = {0,0,0,1};
			colorBackground[] = {1,1,1,0.1};
			sizeEx = "0.5 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
		};
		class CA_Speed: RscText
		{
			idc = 121;
			style = 1;
			colorText[] = {"(profilenamespace getvariable ['IGUI_TEXT_RGB_R',0])","(profilenamespace getvariable ['IGUI_TEXT_RGB_G',1])","(profilenamespace getvariable ['IGUI_TEXT_RGB_B',1])","(profilenamespace getvariable ['IGUI_TEXT_RGB_A',0.8])"};
			text = "9999";
			x = "6.3 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(profilenamespace getvariable [""IGUI_GRID_VEHICLE_X"",		(safezoneX + 0.5 * 			(			((safezoneW / safezoneH) min 1.2) / 40))])";
			y = "1.3 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(profilenamespace getvariable [""IGUI_GRID_VEHICLE_Y"",		(safezoneY + 0.5 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25))])";
			w = "2 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			sizeEx = "0.8 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
		};
		class CA_SpeedUnits: RscText
		{
			colorText[] = {"(profilenamespace getvariable ['IGUI_TEXT_RGB_R',0])","(profilenamespace getvariable ['IGUI_TEXT_RGB_G',1])","(profilenamespace getvariable ['IGUI_TEXT_RGB_B',1])","(profilenamespace getvariable ['IGUI_TEXT_RGB_A',0.8])"};
			idc = 1004;
			text = "km/h";
			x = "8 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(profilenamespace getvariable [""IGUI_GRID_VEHICLE_X"",		(safezoneX + 0.5 * 			(			((safezoneW / safezoneH) min 1.2) / 40))])";
			y = "1.3 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(profilenamespace getvariable [""IGUI_GRID_VEHICLE_Y"",		(safezoneY + 0.5 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25))])";
			w = "2 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			sizeEx = "0.8 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
		};
		class CA_AltBackground: RscText
		{
			shadow = 0;
			font = "PuristaSemibold";
			idc = 1014;
			x = "5.5 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(profilenamespace getvariable [""IGUI_GRID_VEHICLE_X"",		(safezoneX + 0.5 * 			(			((safezoneW / safezoneH) min 1.2) / 40))])";
			y = "2.3 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(profilenamespace getvariable [""IGUI_GRID_VEHICLE_Y"",		(safezoneY + 0.5 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25))])";
			w = "4.4 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "0.9 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			colorText[] = {0,0,0,1};
			colorBackground[] = {1,1,1,0.1};
			sizeEx = "0.5 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
		};
		class CA_Alt: RscText
		{
			idc = 122;
			style = 1;
			colorText[] = {"(profilenamespace getvariable ['IGUI_TEXT_RGB_R',0])","(profilenamespace getvariable ['IGUI_TEXT_RGB_G',1])","(profilenamespace getvariable ['IGUI_TEXT_RGB_B',1])","(profilenamespace getvariable ['IGUI_TEXT_RGB_A',0.8])"};
			text = "9999";
			x = "6.3 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(profilenamespace getvariable [""IGUI_GRID_VEHICLE_X"",		(safezoneX + 0.5 * 			(			((safezoneW / safezoneH) min 1.2) / 40))])";
			y = "2.3 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(profilenamespace getvariable [""IGUI_GRID_VEHICLE_Y"",		(safezoneY + 0.5 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25))])";
			w = "2 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			sizeEx = "0.8 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
		};
		class CA_AltUnits: RscText
		{
			colorText[] = {"(profilenamespace getvariable ['IGUI_TEXT_RGB_R',0])","(profilenamespace getvariable ['IGUI_TEXT_RGB_G',1])","(profilenamespace getvariable ['IGUI_TEXT_RGB_B',1])","(profilenamespace getvariable ['IGUI_TEXT_RGB_A',0.8])"};
			idc = 1005;
			text = "m";
			x = "8 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(profilenamespace getvariable [""IGUI_GRID_VEHICLE_X"",		(safezoneX + 0.5 * 			(			((safezoneW / safezoneH) min 1.2) / 40))])";
			y = "2.3 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(profilenamespace getvariable [""IGUI_GRID_VEHICLE_Y"",		(safezoneY + 0.5 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25))])";
			w = "2 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			sizeEx = "0.8 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
		};
		class CA_Depth: RscText
		{
			idc = 186;
			style = 1;
			colorText[] = {"(profilenamespace getvariable ['IGUI_TEXT_RGB_R',0])","(profilenamespace getvariable ['IGUI_TEXT_RGB_G',1])","(profilenamespace getvariable ['IGUI_TEXT_RGB_B',1])","(profilenamespace getvariable ['IGUI_TEXT_RGB_A',0.8])"};
			text = "9999";
			x = "6.3 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(profilenamespace getvariable [""IGUI_GRID_VEHICLE_X"",		(safezoneX + 0.5 * 			(			((safezoneW / safezoneH) min 1.2) / 40))])";
			y = "2.3 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(profilenamespace getvariable [""IGUI_GRID_VEHICLE_Y"",		(safezoneY + 0.5 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25))])";
			w = "2 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			sizeEx = "0.8 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
		};
		class CA_Stabilize: RscPicture
		{
			shadow = 1;
			idc = 1204;
			text = "\A3\Ui_f\data\IGUI\Cfg\Actions\autohover_ca.paa";
			x = "5.6 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(profilenamespace getvariable [""IGUI_GRID_VEHICLE_X"",		(safezoneX + 0.5 * 			(			((safezoneW / safezoneH) min 1.2) / 40))])";
			y = "2.4 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(profilenamespace getvariable [""IGUI_GRID_VEHICLE_Y"",		(safezoneY + 0.5 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25))])";
			w = "0.8 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "0.8 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
		};
		class CA_HitZones: RscHitZones
		{
			idc = 111;
			x = "0.1 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(profilenamespace getvariable [""IGUI_GRID_VEHICLE_X"",		(safezoneX + 0.5 * 			(			((safezoneW / safezoneH) min 1.2) / 40))])";
			y = "1.3 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(profilenamespace getvariable [""IGUI_GRID_VEHICLE_Y"",		(safezoneY + 0.5 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25))])";
			w = "5.3 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "1.9 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			xCount = 3;
			yCount = 2;
			xSpace = "0.1 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			ySpace = "0.1 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
		};
		class CA_Radar: RscControlsGroupNoScrollbars
		{
			idc = 2301;
			x = "0 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(profilenamespace getvariable [""IGUI_GRID_RADAR_X"",		(safezoneX + safezoneW / 2 - 2.8 * 			(			((safezoneW / safezoneH) min 1.2) / 40))])";
			y = "0 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(profilenamespace getvariable [""IGUI_GRID_RADAR_Y"",		(safezoneY + 0.5 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25))])";
			w = "5.6 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "5.6 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			class controls
			{
				class CA_RadarBackground: RscPicture
				{
					colorText[] = {"(profilenamespace getvariable ['IGUI_BCG_RGB_R',0])","(profilenamespace getvariable ['IGUI_BCG_RGB_G',1])","(profilenamespace getvariable ['IGUI_BCG_RGB_B',1])","(profilenamespace getvariable ['IGUI_BCG_RGB_A',0.8])"};
					idc = 1200;
					text = "A3\Ui_f\data\igui\cfg\radar\radarBackground_ca.paa";
					x = "0 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
					y = "0 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
					w = "5.6 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
					h = "5.6 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
				};
				class CA_RadarIcon: RscPicture
				{
					colorText[] = {"(profilenamespace getvariable ['IGUI_TEXT_RGB_R',0])","(profilenamespace getvariable ['IGUI_TEXT_RGB_G',1])","(profilenamespace getvariable ['IGUI_TEXT_RGB_B',1])","(profilenamespace getvariable ['IGUI_TEXT_RGB_A',0.8])"};
					idc = 250;
					x = "2.3 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
					y = "2.3 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
					w = "1 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
					h = "1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
				};
				class CA_Heading: RscText
				{
					idc = 148;
					style = 2;
					colorText[] = {"(profilenamespace getvariable ['IGUI_TEXT_RGB_R',0])","(profilenamespace getvariable ['IGUI_TEXT_RGB_G',1])","(profilenamespace getvariable ['IGUI_TEXT_RGB_B',1])","(profilenamespace getvariable ['IGUI_TEXT_RGB_A',0.8])"};
					text = " 359";
					x = "1.8 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
					y = "4.1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
					w = "2 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
					h = "1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
					sizeEx = "0.8 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
				};
			};
		};
		class CA_Zeroing: RscText
		{
			idc = 168;
			colorText[] = {"(profilenamespace getvariable ['IGUI_TEXT_RGB_R',0])","(profilenamespace getvariable ['IGUI_TEXT_RGB_G',1])","(profilenamespace getvariable ['IGUI_TEXT_RGB_B',1])","(profilenamespace getvariable ['IGUI_TEXT_RGB_A',0.8])"};
			x = "0 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(profilenamespace getvariable [""IGUI_GRID_WEAPON_X"",		((safezoneX + safezoneW) - 		(12.4 * 			(			((safezoneW / safezoneH) min 1.2) / 40)) - 0.5 * 			(			((safezoneW / safezoneH) min 1.2) / 40))])";
			y = "0 * 			(		(		((safezoneW / safezoneH) min 1.2) / 1.2) / 20) + 			(safezoneY + safezoneH - 		(		((safezoneW / safezoneH) min 1.2) / 1.2)) +  			18 * 			(		(		((safezoneW / safezoneH) min 1.2) / 1.2) / 20) - (1 * 			(		(		((safezoneW / safezoneH) min 1.2) / 1.2) / 20))";
			w = "3 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			sizeEx = "0.8 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
		};
		class CA_Speed_Freefall: RscIGUIValue
		{
			idc = 380;
			style = 1;
			colorText[] = {0.95,0.95,0.95,1};
			x = 0.258;
			y = "0.015 + SafeZoneY";
			w = 0.12;
		};
		class CA_Alt_Freefall: RscIGUIValue
		{
			idc = 382;
			style = 0;
			colorText[] = {0.95,0.95,0.95,1};
			x = 0.644;
			y = "0.015 + SafeZoneY";
			w = 0.12;
		};
		class CA_TextFlaresMode: RscIGUIText
		{
			idc = 152;
			style = 0;
			sizeEx = "(			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 0.8)";
			x = "0.078 + SafeZoneX";
			y = "0.012 + SafeZoneY";
			w = "0.161*SafezoneW";
		};
		class CA_TextFlares: RscIGUIValue
		{
			idc = 151;
			style = 1;
			sizeEx = "(			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 0.8)";
			x = "0.078  + SafeZoneX";
			y = "0.012 + SafeZoneY";
			w = "0.161*SafezoneW";
		};
	};
	class RscStanceInfo
	{
		idd = 303;
		onLoad = "[""onLoad"",_this,""RscStanceInfo"",'IGUI'] call compile preprocessfilelinenumbers ""A3\ui_f\scripts\initDisplay.sqf""";
		onUnload = "[""onUnload"",_this,""RscStanceInfo"",'IGUI'] call compile preprocessfilelinenumbers ""A3\ui_f\scripts\initDisplay.sqf""";
		controls[] = {"StanceIndicatorBackground","StanceIndicator"};
		class StanceIndicatorBackground: RscPicture
		{
			colorText[] = {"(profilenamespace getvariable ['IGUI_BCG_RGB_R',0])","(profilenamespace getvariable ['IGUI_BCG_RGB_G',1])","(profilenamespace getvariable ['IGUI_BCG_RGB_B',1])","(profilenamespace getvariable ['IGUI_BCG_RGB_A',0.8])"};
			idc = 1201;
			text = "\A3\Ui_f\data\IGUI\RscIngameUI\RscUnitInfo\gradient_ca.paa";
			x = "10 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(profilenamespace getvariable [""IGUI_GRID_WEAPON_X"",		((safezoneX + safezoneW) - 		(12.4 * 			(			((safezoneW / safezoneH) min 1.2) / 40)) - 0.5 * 			(			((safezoneW / safezoneH) min 1.2) / 40))])";
			y = "0 * 			(		(		((safezoneW / safezoneH) min 1.2) / 1.2) / 20) + 			(safezoneY + safezoneH - 		(		((safezoneW / safezoneH) min 1.2) / 1.2)) +  			18 * 			(		(		((safezoneW / safezoneH) min 1.2) / 1.2) / 20) - (1 * 			(		(		((safezoneW / safezoneH) min 1.2) / 1.2) / 20))";
			w = "2.3 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "3.7 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
		};
		class StanceIndicator: RscPictureKeepAspect
		{
			idc = 188;
			text = "\A3\Ui_f\data\IGUI\RscIngameUI\RscUnitInfo\SI_stand_ca.paa";
			x = "10 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(profilenamespace getvariable [""IGUI_GRID_WEAPON_X"",		((safezoneX + safezoneW) - 		(12.4 * 			(			((safezoneW / safezoneH) min 1.2) / 40)) - 0.5 * 			(			((safezoneW / safezoneH) min 1.2) / 40))])";
			y = "0 * 			(		(		((safezoneW / safezoneH) min 1.2) / 1.2) / 20) + 			(safezoneY + safezoneH - 		(		((safezoneW / safezoneH) min 1.2) / 1.2)) +  			18 * 			(		(		((safezoneW / safezoneH) min 1.2) / 1.2) / 20) - (1 * 			(		(		((safezoneW / safezoneH) min 1.2) / 1.2) / 20))";
			w = "2.3 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "2.3 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
		};
	};
	class RscUnitInfoNoHUD
	{
		idd = 300;
		movingEnable = 0;
	};
	class RscUnitInfoSoldier: RscUnitInfo
	{
		idd = 300;
		controls[] = {"WeaponInfoControlsGroupLeft","CA_Speed_Freefall","CA_Alt_Freefall"};
	};
	class RscUnitInfoTank: RscUnitInfo
	{
		idd = 300;
		updateWidthByWeapon = 0;
		updateHeightByCrew = 0;
		updateWidthByCrew = 0;
		controls[] = {"WeaponInfoControlsGroupRight","CA_Zeroing","CA_BackgroundVehicle","CA_BackgroundVehicleTitle","CA_BackgroundVehicleTitleDark","CA_BackgroundFuel","CA_Vehicle","CA_VehicleRole","CA_HitZones","CA_SpeedBackground","CA_SpeedUnits","CA_Speed","CA_ValueFuel","CA_Radar"};
	};
	class CA_HUDRscControlsGroup: RscControlsGroup
	{
		class VScrollbar: VScrollbar
		{
			autoScrollSpeed = -1;
			autoScrollDelay = 5;
			autoScrollRewind = 0;
			color[] = {"(profilenamespace getvariable ['IGUI_TEXT_RGB_R',0])","(profilenamespace getvariable ['IGUI_TEXT_RGB_G',1])","(profilenamespace getvariable ['IGUI_TEXT_RGB_B',1])","(profilenamespace getvariable ['IGUI_TEXT_RGB_A',0.8])"};
			width = 0.001;
		};
		class HScrollbar: HScrollbar
		{
			color[] = {"(profilenamespace getvariable ['IGUI_TEXT_RGB_R',0])","(profilenamespace getvariable ['IGUI_TEXT_RGB_G',1])","(profilenamespace getvariable ['IGUI_TEXT_RGB_B',1])","(profilenamespace getvariable ['IGUI_TEXT_RGB_A',0.8])"};
			height = 0.001;
		};
	};
	class RscUnitInfoAir: RscUnitInfo
	{
		controls[] = {"WeaponInfoControlsGroupRight","CA_BackgroundVehicle","CA_BackgroundVehicleTitle","CA_BackgroundVehicleTitleDark","CA_BackgroundFuel","CA_Vehicle","CA_VehicleRole","CA_HitZones","CA_SpeedBackground","CA_SpeedUnits","CA_Speed","CA_ValueFuel","CA_AltBackground","CA_AltUnits","CA_Alt","CA_Stabilize","CA_Radar"};
	};
	class RscUnitInfo_AH64D_gunner
	{
		idd = 300;
		controls[] = {"CA_Distance","CA_VisionMode","CA_FlirMode","CA_FOVMode","CA_Compass","CA_Heading","CA_Autohover","CA_BalisticComputer","CA_BallRange","CA_LaserMarker","CA_WeaponZeroingText","CA_WeaponZeroing"};
		class CA_Distance: RscOpticsValue
		{
			idc = 151;
			x = 0.438;
			y = 0.908;
			w = 0.123;
			style = 2;
		};
		class CA_LaserMarker: RscOpticsText
		{
			idc = 158;
			x = 0.27;
			y = 0.908;
			w = 0.154;
			text = "LASE TRGT";
		};
		class CA_BallRange: RscOpticsValue
		{
			idc = 164;
			x = 0.626;
			y = 0.908;
			w = 0.3;
		};
		class CA_BalisticComputer: RscOpticsText
		{
			idc = 165;
			x = 0.594;
			y = 0.908;
			text = "*";
			sizeEx = 0.06;
		};
		class CA_FOVMode: RscOpticsText
		{
			idc = 154;
			x = 0.052;
			y = 0.248;
		};
		class CA_VisionMode: RscOpticsText
		{
			idc = 152;
			x = 0.052;
			y = 0.296;
		};
		class CA_Autohover: RscOpticsText
		{
			idc = 157;
			x = 0.664;
			y = 0.248;
			style = 1;
			text = "HOV";
		};
		class CA_FlirMode: RscOpticsText
		{
			idc = 153;
			x = 0.664;
			y = 0.296;
			style = 1;
		};
		class CA_Compass: RscOpticsText
		{
			idc = 155;
			x = 0;
			y = 0.7;
			w = 0.3;
			h = 0.05;
		};
		class CA_Heading: RscOpticsText
		{
			idc = 156;
			x = 0;
			y = 0.75;
			w = 0.3;
			h = 0.05;
		};
	};
	class RscUnitVehicle
	{
		idd = 300;
		updateWidthByWeapon = 0;
		updateHeightByCrew = 0;
		updateWidthByCrew = 0;
		controls[] = {"WeaponInfoControlsGroupRight","CA_Zeroing","CA_BackgroundVehicle","CA_BackgroundVehicleTitle","CA_BackgroundVehicleTitleDark","CA_BackgroundFuel","CA_Vehicle","CA_VehicleRole","CA_HitZones","CA_SpeedBackground","CA_SpeedUnits","CA_Speed","CA_ValueFuel","CA_AltBackground","CA_AltUnits","CA_Alt","CA_Stabilize"};
	};
	class RscUnitInfoUAV
	{
		idd = 300;
		controls[] = {"WeaponInfoControlsGroupRight","CA_BackgroundVehicle","CA_BackgroundVehicleTitle","CA_BackgroundVehicleTitleDark","CA_BackgroundFuel","CA_Vehicle","CA_VehicleRole","CA_HitZones","CA_SpeedBackground","CA_SpeedUnits","CA_Speed","CA_ValueFuel","CA_AltBackground","CA_AltUnits","CA_Alt","CA_Stabilize","CA_Radar","RscTextUAV","TextPosition","Position","TextZoom","Zoom","Time","Date"};
		class RscTextUAV: RscText
		{
			x = "safezoneX";
			y = "safezoneY";
			w = "safezoneW";
			h = "safezoneH";
			colorbackground[] = {0,0,0,0};
			type = 0;
			IDC = 1004;
			linespacing = 1;
			text = "";
			style = "0x00 + 0x10 + 0x200";
		};
		class TextPosition: RscTextUAV
		{
			text = "GRID";
			x = "0.5 + 	0.13 * safezoneW * 2 + 	0.05 / 2";
			y = "SafeZoneY + SafezoneH - 0.12";
			h = 0.05;
			w = "safezoneW - ((safezoneW - 1) / 2 + (0.5 + 	0.13 * safezoneW * 2 + 	0.05 / 2))";
			style = "0x00 + 0x100 + 0x200";
			colortext[] = {1,1,1,1};
			font = "EtelkaMonospacePro";
			sizeEx = "(			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 0.8)*1";
		};
		class Position: TextPosition
		{
			idc = 130;
			x = "0.5 + 	0.13 * safezoneW * 2 + 	0.05 / 2";
			y = "SafeZoneY + SafezoneH - 0.12";
			style = "0x01 + 0x100";
		};
		class TextZoom: TextPosition
		{
			text = "ZOOM";
			y = "SafeZoneY + SafezoneH - 0.08";
		};
		class Zoom: Position
		{
			idc = 131;
			y = "SafeZoneY + SafezoneH - 0.08";
		};
		class Time: TextPosition
		{
			idc = 101;
			style = "0x02 + 0x100 + 0x200";
			x = "0.5 - 0.2";
			y = "SafeZoneY + SafezoneH - 0.12";
			w = 0.4;
			sizeEx = "(			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 0.8)*1 * 1.5";
		};
		class Date: Time
		{
			idc = 102;
			y = "SafeZoneY + SafezoneH - 0.09";
			sizeEx = "0.024*1.2";
		};
	};
	class RscUnitInfoSubmarine: RscUnitInfo
	{
		idd = 300;
		updateWidthByWeapon = 0;
		updateHeightByCrew = 0;
		updateWidthByCrew = 0;
		controls[] = {"WeaponInfoControlsGroupRight","CA_BackgroundVehicle","CA_BackgroundVehicleTitle","CA_BackgroundVehicleTitleDark","CA_BackgroundFuel","CA_Vehicle","CA_VehicleRole","CA_HitZones","CA_SpeedBackground","CA_SpeedUnits","CA_Speed","CA_ValueFuel","CA_AltBackground","CA_AltUnits","CA_Depth"};
	};
	class RscUnitInfoShip: RscUnitInfo
	{
		idd = 300;
		updateWidthByWeapon = 0;
		updateHeightByCrew = 0;
		updateWidthByCrew = 0;
		controls[] = {"WeaponInfoControlsGroupRight","CA_Zeroing","CA_BackgroundVehicle","CA_BackgroundVehicleTitle","CA_BackgroundVehicleTitleDark","CA_BackgroundFuel","CA_Vehicle","CA_VehicleRole","CA_HitZones","CA_SpeedBackground","CA_SpeedUnits","CA_Speed","CA_ValueFuel","CA_Radar"};
	};
	class RscWeaponEmpty
	{
		idd = 300;
		controls[] = {};
	};
	class RscWeaponRangeFinder
	{
		idd = 300;
		controls[] = {"CA_Distance"};
		class CA_Distance: RscOpticsValue
		{
			idc = 151;
			style = 2;
			sizeEx = "0.028*SafezoneH";
			colorText[] = {"(profilenamespace getvariable ['IGUI_TEXT_RGB_R',0])","(profilenamespace getvariable ['IGUI_TEXT_RGB_G',1])","(profilenamespace getvariable ['IGUI_TEXT_RGB_B',1])","(profilenamespace getvariable ['IGUI_TEXT_RGB_A',0.8])"};
			x = 0.4;
			y = "(SafezoneY+SafezoneH*0.665)";
			w = 0.2;
			h = "0.05*SafezoneH";
		};
	};
	class RscWeaponRangeArtillery
	{
		idd = 300;
		controls[] = {"CA_IGUI_elements_group","CA_RangeElements_group"};
		class CA_IGUI_elements_group: RscControlsGroup
		{
			idc = 170;
			class VScrollbar: VScrollbar
			{
				width = 0;
			};
			class HScrollbar: HScrollbar
			{
				height = 0;
			};
			x = "0 * 		(0.01875 * SafezoneH) + 		(SafezoneX + ((SafezoneW - SafezoneH) / 2))";
			y = "0 * 		(0.025 * SafezoneH) + 		(SafezoneY)";
			w = "53.5 * 		(0.01875 * SafezoneH)";
			h = "40 * 		(0.025 * SafezoneH)";
			class controls
			{
				class CA_Heading: RscText
				{
					idc = 156;
					style = 0;
					colorText[] = {0.706,0.0745,0.0196,1};
					sizeEx = "0.028*SafezoneH";
					shadow = 0;
					font = "EtelkaMonospacePro";
					text = "015";
					x = "25.3 * 		(0.01875 * SafezoneH)";
					y = "6.3 * 		(0.025 * SafezoneH)";
					w = "2.2 * 		(0.01875 * SafezoneH)";
					h = "1 * 		(0.025 * SafezoneH)";
				};
				class CA_OpticsPitch: RscText
				{
					idc = 182;
					style = 1;
					colorText[] = {0.706,0.0745,0.0196,1};
					sizeEx = "0.028*SafezoneH";
					shadow = 0;
					font = "EtelkaMonospacePro";
					text = "34.5";
					x = "11.8 * 		(0.01875 * SafezoneH)";
					y = "19.46 * 		(0.025 * SafezoneH)";
					w = "3.5 * 		(0.01875 * SafezoneH)";
					h = "1.1 * 		(0.025 * SafezoneH)";
				};
				class CA_OpticsZoom: RscText
				{
					idc = 180;
					style = 1;
					colorText[] = {0.706,0.0745,0.0196,1};
					sizeEx = "0.028*SafezoneH";
					shadow = 0;
					font = "EtelkaMonospacePro";
					text = "4.5";
					x = "38.3 * 		(0.01875 * SafezoneH)";
					y = "19.46 * 		(0.025 * SafezoneH)";
					w = "3.5 * 		(0.01875 * SafezoneH)";
					h = "1.1 * 		(0.025 * SafezoneH)";
				};
				class CA_Solution_text: RscText
				{
					style = 0;
					sizeEx = "0.028*SafezoneH";
					colorText[] = {0.95,0.95,0.95,1};
					shadow = 0;
					font = "EtelkaMonospacePro";
					idc = 1011;
					text = "SOLUTION";
					x = "10.8 * 		(0.01875 * SafezoneH)";
					y = "27.8 * 		(0.025 * SafezoneH)";
					w = "7.5 * 		(0.01875 * SafezoneH)";
					h = "1 * 		(0.025 * SafezoneH)";
				};
				class CA_distance_text: RscText
				{
					style = 0;
					sizeEx = "0.038*SafezoneH";
					colorText[] = {0.95,0.95,0.95,1};
					shadow = 0;
					font = "EtelkaMonospacePro";
					idc = 1010;
					text = "RNG";
					x = "10.8 * 		(0.01875 * SafezoneH)";
					y = "29.3 * 		(0.025 * SafezoneH)";
					w = "3 * 		(0.01875 * SafezoneH)";
					h = "1.2 * 		(0.025 * SafezoneH)";
				};
				class CA_Distance: RscText
				{
					idc = 173;
					style = 1;
					sizeEx = "0.038*SafezoneH";
					colorText[] = {0.706,0.0745,0.0196,1};
					shadow = 0;
					font = "EtelkaMonospacePro";
					text = "2456";
					x = "13.8 * 		(0.01875 * SafezoneH)";
					y = "29.3 * 		(0.025 * SafezoneH)";
					w = "5.2 * 		(0.01875 * SafezoneH)";
					h = "1.2 * 		(0.025 * SafezoneH)";
				};
				class CA_time_text: RscText
				{
					style = 0;
					sizeEx = "0.038*SafezoneH";
					colorText[] = {0.95,0.95,0.95,1};
					shadow = 0;
					font = "EtelkaMonospacePro";
					idc = 1012;
					text = "TRV";
					x = "10.8 * 		(0.01875 * SafezoneH)";
					y = "30.8 * 		(0.025 * SafezoneH)";
					w = "3 * 		(0.01875 * SafezoneH)";
					h = "1.2 * 		(0.025 * SafezoneH)";
				};
				class CA_Time: RscText
				{
					idc = 174;
					style = 1;
					sizeEx = "0.038*SafezoneH";
					colorText[] = {0.706,0.0745,0.0196,1};
					shadow = 0;
					font = "EtelkaMonospacePro";
					text = "25";
					x = "13.8 * 		(0.01875 * SafezoneH)";
					y = "30.8 * 		(0.025 * SafezoneH)";
					w = "5.2 * 		(0.01875 * SafezoneH)";
					h = "1.2 * 		(0.025 * SafezoneH)";
				};
				class CA_ElevCtrl_text: RscText
				{
					style = 0;
					sizeEx = "0.028*SafezoneH";
					colorText[] = {0.95,0.95,0.95,1};
					shadow = 0;
					font = "EtelkaMonospacePro";
					idc = 1015;
					text = "ELEV CTRL";
					x = "33.8 * 		(0.01875 * SafezoneH)";
					y = "27.8 * 		(0.025 * SafezoneH)";
					w = "7.5 * 		(0.01875 * SafezoneH)";
					h = "1 * 		(0.025 * SafezoneH)";
				};
				class CA_Elev_text: RscText
				{
					style = 0;
					sizeEx = "0.038*SafezoneH";
					colorText[] = {0.95,0.95,0.95,1};
					shadow = 0;
					font = "EtelkaMonospacePro";
					idc = 1013;
					text = "ELV";
					x = "33.8 * 		(0.01875 * SafezoneH)";
					y = "29.3 * 		(0.025 * SafezoneH)";
					w = "3 * 		(0.01875 * SafezoneH)";
					h = "1.2 * 		(0.025 * SafezoneH)";
				};
				class CA_Elev: RscText
				{
					idc = 175;
					style = 1;
					sizeEx = "0.038*SafezoneH";
					colorText[] = {0.706,0.0745,0.0196,1};
					shadow = 0;
					font = "EtelkaMonospacePro";
					text = "80.5";
					x = "36.8 * 		(0.01875 * SafezoneH)";
					y = "29.3 * 		(0.025 * SafezoneH)";
					w = "5.2 * 		(0.01875 * SafezoneH)";
					h = "1.2 * 		(0.025 * SafezoneH)";
				};
				class CA_Elev_Need_text: RscText
				{
					style = 0;
					sizeEx = "0.038*SafezoneH";
					colorText[] = {0.95,0.95,0.95,1};
					shadow = 0;
					font = "EtelkaMonospacePro";
					idc = 1014;
					text = "REL";
					x = "33.8 * 		(0.01875 * SafezoneH)";
					y = "30.8 * 		(0.025 * SafezoneH)";
					w = "3 * 		(0.01875 * SafezoneH)";
					h = "1.2 * 		(0.025 * SafezoneH)";
				};
				class CA_Elev_Need: RscText
				{
					idc = 176;
					style = 1;
					sizeEx = "0.038*SafezoneH";
					colorText[] = {0.706,0.0745,0.0196,1};
					shadow = 0;
					font = "EtelkaMonospacePro";
					text = "35.4";
					x = "36.8 * 		(0.01875 * SafezoneH)";
					y = "30.8 * 		(0.025 * SafezoneH)";
					w = "5.2 * 		(0.01875 * SafezoneH)";
					h = "1.2 * 		(0.025 * SafezoneH)";
				};
				class CA_VisionMode: RscText
				{
					idc = 179;
					style = 0;
					sizeEx = "0.028*SafezoneH";
					colorText[] = {0.706,0.0745,0.0196,1};
					shadow = 0;
					font = "EtelkaMonospacePro";
					text = "VIS";
					x = "10.5 * 		(0.01875 * SafezoneH)";
					y = "32.6 * 		(0.025 * SafezoneH)";
					w = "4.5 * 		(0.01875 * SafezoneH)";
					h = "1.2 * 		(0.025 * SafezoneH)";
				};
			};
		};
		class CA_RangeElements_group: RscControlsGroup
		{
			idc = 177;
			class VScrollbar: VScrollbar
			{
				width = 0;
			};
			class HScrollbar: HScrollbar
			{
				height = 0;
			};
			x = "0 * 		(0.01875 * SafezoneH) + 		(SafezoneX + ((SafezoneW - SafezoneH) / 2))";
			y = "0 * 		(0.025 * SafezoneH) + 		(SafezoneY)";
			w = "53.5 * 		(0.01875 * SafezoneH)";
			h = "40 * 		(0.025 * SafezoneH)";
			class controls
			{
				class CA_OORange: RscText
				{
					style = 2;
					sizeEx = "0.028*SafezoneH";
					colorText[] = {0.706,0.0745,0.0196,1};
					shadow = 0;
					font = "EtelkaMonospacePro";
					idc = 1007;
					text = "[RANGE]";
					x = "24.5 * 		(0.01875 * SafezoneH)";
					y = "32.6 * 		(0.025 * SafezoneH)";
					w = "4.5 * 		(0.01875 * SafezoneH)";
					h = "1.2 * 		(0.025 * SafezoneH)";
				};
				class CA_OORangeCross: RscText
				{
					style = "0x30 + 0x800";
					sizeEx = "0.36*SafezoneH";
					shadow = 0;
					idc = 1009;
					text = "A3\weapons_f\acc\Data\reticle_mk6_outofrange_CA.paa";
					x = "20.5 * 		(0.01875 * SafezoneH)";
					y = "14 * 		(0.025 * SafezoneH)";
					w = "12.5 * 		(0.01875 * SafezoneH)";
					h = "12 * 		(0.025 * SafezoneH)";
				};
			};
		};
	};
	class RscWeaponRangeArtilleryAuto
	{
		idd = 300;
		controls[] = {"CA_IGUI_elements_group","CA_RangeElements_group","CA_AutoElements_group"};
		class CA_IGUI_elements_group: RscControlsGroup
		{
			idc = 170;
			class VScrollbar: VScrollbar
			{
				width = 0;
			};
			class HScrollbar: HScrollbar
			{
				height = 0;
			};
			x = "0 * 		(0.01875 * SafezoneH) + 		(SafezoneX + ((SafezoneW - SafezoneH) / 2))";
			y = "0 * 		(0.025 * SafezoneH) + 		(SafezoneY)";
			w = "53.5 * 		(0.01875 * SafezoneH)";
			h = "40 * 		(0.025 * SafezoneH)";
			class controls
			{
				class CA_Heading: RscText
				{
					idc = 156;
					style = 0;
					colorText[] = {0.706,0.0745,0.0196,1};
					sizeEx = "0.028*SafezoneH";
					shadow = 0;
					font = "EtelkaMonospacePro";
					text = "015";
					x = "25.3 * 		(0.01875 * SafezoneH)";
					y = "6.3 * 		(0.025 * SafezoneH)";
					w = "2.2 * 		(0.01875 * SafezoneH)";
					h = "1 * 		(0.025 * SafezoneH)";
				};
				class CA_OpticsPitch: RscText
				{
					idc = 182;
					style = 1;
					colorText[] = {0.706,0.0745,0.0196,1};
					sizeEx = "0.028*SafezoneH";
					shadow = 0;
					font = "EtelkaMonospacePro";
					text = "34.5";
					x = "11.8 * 		(0.01875 * SafezoneH)";
					y = "19.46 * 		(0.025 * SafezoneH)";
					w = "3.5 * 		(0.01875 * SafezoneH)";
					h = "1.1 * 		(0.025 * SafezoneH)";
				};
				class CA_OpticsZoom: RscText
				{
					idc = 180;
					style = 1;
					colorText[] = {0.706,0.0745,0.0196,1};
					sizeEx = "0.028*SafezoneH";
					shadow = 0;
					font = "EtelkaMonospacePro";
					text = "4.5";
					x = "38.3 * 		(0.01875 * SafezoneH)";
					y = "19.46 * 		(0.025 * SafezoneH)";
					w = "3.5 * 		(0.01875 * SafezoneH)";
					h = "1.1 * 		(0.025 * SafezoneH)";
				};
				class CA_Solution_text: RscText
				{
					style = 0;
					sizeEx = "0.028*SafezoneH";
					colorText[] = {0.95,0.95,0.95,1};
					shadow = 0;
					font = "EtelkaMonospacePro";
					idc = 1011;
					text = "SOLUTION";
					x = "10.8 * 		(0.01875 * SafezoneH)";
					y = "27.8 * 		(0.025 * SafezoneH)";
					w = "7.5 * 		(0.01875 * SafezoneH)";
					h = "1 * 		(0.025 * SafezoneH)";
				};
				class CA_distance_text: RscText
				{
					style = 0;
					sizeEx = "0.038*SafezoneH";
					colorText[] = {0.95,0.95,0.95,1};
					shadow = 0;
					font = "EtelkaMonospacePro";
					idc = 1010;
					text = "RNG";
					x = "10.8 * 		(0.01875 * SafezoneH)";
					y = "29.3 * 		(0.025 * SafezoneH)";
					w = "3 * 		(0.01875 * SafezoneH)";
					h = "1.2 * 		(0.025 * SafezoneH)";
				};
				class CA_Distance: RscText
				{
					idc = 173;
					style = 1;
					sizeEx = "0.038*SafezoneH";
					colorText[] = {0.706,0.0745,0.0196,1};
					shadow = 0;
					font = "EtelkaMonospacePro";
					text = "2456";
					x = "13.8 * 		(0.01875 * SafezoneH)";
					y = "29.3 * 		(0.025 * SafezoneH)";
					w = "5.2 * 		(0.01875 * SafezoneH)";
					h = "1.2 * 		(0.025 * SafezoneH)";
				};
				class CA_time_text: RscText
				{
					style = 0;
					sizeEx = "0.038*SafezoneH";
					colorText[] = {0.95,0.95,0.95,1};
					shadow = 0;
					font = "EtelkaMonospacePro";
					idc = 1012;
					text = "TRV";
					x = "10.8 * 		(0.01875 * SafezoneH)";
					y = "30.8 * 		(0.025 * SafezoneH)";
					w = "3 * 		(0.01875 * SafezoneH)";
					h = "1.2 * 		(0.025 * SafezoneH)";
				};
				class CA_Time: RscText
				{
					idc = 174;
					style = 1;
					sizeEx = "0.038*SafezoneH";
					colorText[] = {0.706,0.0745,0.0196,1};
					shadow = 0;
					font = "EtelkaMonospacePro";
					text = "25";
					x = "13.8 * 		(0.01875 * SafezoneH)";
					y = "30.8 * 		(0.025 * SafezoneH)";
					w = "5.2 * 		(0.01875 * SafezoneH)";
					h = "1.2 * 		(0.025 * SafezoneH)";
				};
				class CA_ElevCtrl_text: RscText
				{
					style = 0;
					sizeEx = "0.028*SafezoneH";
					colorText[] = {0.95,0.95,0.95,1};
					shadow = 0;
					font = "EtelkaMonospacePro";
					idc = 1015;
					text = "ELEV CTRL";
					x = "33.8 * 		(0.01875 * SafezoneH)";
					y = "27.8 * 		(0.025 * SafezoneH)";
					w = "7.5 * 		(0.01875 * SafezoneH)";
					h = "1 * 		(0.025 * SafezoneH)";
				};
				class CA_Elev_text: RscText
				{
					style = 0;
					sizeEx = "0.038*SafezoneH";
					colorText[] = {0.95,0.95,0.95,1};
					shadow = 0;
					font = "EtelkaMonospacePro";
					idc = 1013;
					text = "ELV";
					x = "33.8 * 		(0.01875 * SafezoneH)";
					y = "29.3 * 		(0.025 * SafezoneH)";
					w = "3 * 		(0.01875 * SafezoneH)";
					h = "1.2 * 		(0.025 * SafezoneH)";
				};
				class CA_Elev: RscText
				{
					idc = 175;
					style = 1;
					sizeEx = "0.038*SafezoneH";
					colorText[] = {0.706,0.0745,0.0196,1};
					shadow = 0;
					font = "EtelkaMonospacePro";
					text = "-80.5";
					x = "36.8 * 		(0.01875 * SafezoneH)";
					y = "29.3 * 		(0.025 * SafezoneH)";
					w = "5.2 * 		(0.01875 * SafezoneH)";
					h = "1.2 * 		(0.025 * SafezoneH)";
				};
				class CA_Elev_Need_text: RscText
				{
					style = 0;
					sizeEx = "0.038*SafezoneH";
					colorText[] = {0.95,0.95,0.95,1};
					shadow = 0;
					font = "EtelkaMonospacePro";
					idc = 1014;
					text = "REL";
					x = "33.8 * 		(0.01875 * SafezoneH)";
					y = "30.8 * 		(0.025 * SafezoneH)";
					w = "3 * 		(0.01875 * SafezoneH)";
					h = "1.2 * 		(0.025 * SafezoneH)";
				};
				class CA_Elev_Need: RscText
				{
					idc = 176;
					style = 1;
					sizeEx = "0.038*SafezoneH";
					colorText[] = {0.706,0.0745,0.0196,1};
					shadow = 0;
					font = "EtelkaMonospacePro";
					text = "-35.4";
					x = "36.8 * 		(0.01875 * SafezoneH)";
					y = "30.8 * 		(0.025 * SafezoneH)";
					w = "5.2 * 		(0.01875 * SafezoneH)";
					h = "1.2 * 		(0.025 * SafezoneH)";
				};
				class CA_VisionMode: RscText
				{
					idc = 179;
					style = 0;
					sizeEx = "0.028*SafezoneH";
					colorText[] = {0.706,0.0745,0.0196,1};
					shadow = 0;
					font = "EtelkaMonospacePro";
					text = "VIS";
					x = "10.5 * 		(0.01875 * SafezoneH)";
					y = "32.6 * 		(0.025 * SafezoneH)";
					w = "4.5 * 		(0.01875 * SafezoneH)";
					h = "1.2 * 		(0.025 * SafezoneH)";
				};
			};
		};
		class CA_RangeElements_group: RscControlsGroup
		{
			idc = 177;
			class VScrollbar: VScrollbar
			{
				width = 0;
			};
			class HScrollbar: HScrollbar
			{
				height = 0;
			};
			x = "0 * 		(0.01875 * SafezoneH) + 		(SafezoneX + ((SafezoneW - SafezoneH) / 2))";
			y = "0 * 		(0.025 * SafezoneH) + 		(SafezoneY)";
			w = "53.5 * 		(0.01875 * SafezoneH)";
			h = "40 * 		(0.025 * SafezoneH)";
			class controls
			{
				class CA_OORange: RscText
				{
					style = 2;
					sizeEx = "0.028*SafezoneH";
					colorText[] = {0.706,0.0745,0.0196,1};
					shadow = 0;
					font = "EtelkaMonospacePro";
					idc = 1007;
					text = "[RANGE]";
					x = "24.5 * 		(0.01875 * SafezoneH)";
					y = "32.6 * 		(0.025 * SafezoneH)";
					w = "4.5 * 		(0.01875 * SafezoneH)";
					h = "1.2 * 		(0.025 * SafezoneH)";
				};
				class CA_OORangeCross: RscText
				{
					style = "0x30 + 0x800";
					sizeEx = "0.36*SafezoneH";
					shadow = 0;
					idc = 1009;
					text = "A3\weapons_f\acc\Data\reticle_mk6_outofrange_CA.paa";
					x = "20.5 * 		(0.01875 * SafezoneH)";
					y = "14 * 		(0.025 * SafezoneH)";
					w = "12.5 * 		(0.01875 * SafezoneH)";
					h = "12 * 		(0.025 * SafezoneH)";
				};
			};
		};
		class CA_AutoElements_group: RscControlsGroup
		{
			idc = 178;
			class VScrollbar: VScrollbar
			{
				width = 0;
			};
			class HScrollbar: HScrollbar
			{
				height = 0;
			};
			x = "0 * 		(0.01875 * SafezoneH) + 		(SafezoneX + ((SafezoneW - SafezoneH) / 2))";
			y = "0 * 		(0.025 * SafezoneH) + 		(SafezoneY)";
			w = "53.5 * 		(0.01875 * SafezoneH)";
			h = "40 * 		(0.025 * SafezoneH)";
			class controls
			{
				class CA_Auto: RscText
				{
					style = 1;
					sizeEx = "0.028*SafezoneH";
					colorText[] = {0.706,0.0745,0.0196,1};
					shadow = 0;
					font = "EtelkaMonospacePro";
					idc = 1016;
					text = "AUTO";
					x = "38.7 * 		(0.01875 * SafezoneH)";
					y = "32.6 * 		(0.025 * SafezoneH)";
					w = "4.5 * 		(0.01875 * SafezoneH)";
					h = "1.2 * 		(0.025 * SafezoneH)";
				};
			};
		};
	};
	class RscWeaponRangeFinderPAS13
	{
		idd = 300;
		controls[] = {"CA_Distance"};
		class CA_Distance: RscOpticsValue
		{
			idc = 151;
			style = 2;
			sizeEx = "0.038*SafezoneH";
			x = 0.4;
			y = "(SafezoneY+SafezoneH*0.8)";
			w = 0.207;
			h = "0.05*SafezoneH";
		};
	};
	class RscOptics_Rangefinder: RscUnitInfo
	{
		idd = 300;
		controls[] = {"CA_IGUI_elements_group"};
		class CA_IGUI_elements_group: RscControlsGroup
		{
			idc = 170;
			class VScrollbar: VScrollbar
			{
				width = 0;
			};
			class HScrollbar: HScrollbar
			{
				height = 0;
			};
			x = "0 * 		(0.01875 * SafezoneH) + 		(SafezoneX + ((SafezoneW - SafezoneH) / 2))";
			y = "0 * 		(0.025 * SafezoneH) + 		(SafezoneY)";
			w = "53.5 * 		(0.01875 * SafezoneH)";
			h = "40 * 		(0.025 * SafezoneH)";
			class controls
			{
				class CA_Distance: RscText
				{
					idc = 151;
					style = 1;
					sizeEx = "0.038*SafezoneH";
					colorText[] = {0.706,0.0745,0.0196,1};
					shadow = 0;
					font = "EtelkaMonospacePro";
					text = "2456";
					x = "45.5 * 		(0.01875 * SafezoneH)";
					y = "19.5 * 		(0.025 * SafezoneH)";
					w = "4 * 		(0.01875 * SafezoneH)";
					h = "1.2 * 		(0.025 * SafezoneH)";
				};
				class CA_VisionMode: RscText
				{
					idc = 179;
					style = 0;
					sizeEx = "0.038*SafezoneH";
					colorText[] = {0.706,0.0745,0.0196,1};
					shadow = 0;
					font = "EtelkaMonospacePro";
					text = "VIS";
					x = "6.7 * 		(0.01875 * SafezoneH)";
					y = "19.5 * 		(0.025 * SafezoneH)";
					w = "4 * 		(0.01875 * SafezoneH)";
					h = "1.2 * 		(0.025 * SafezoneH)";
				};
				class CA_Heading: RscText
				{
					idc = 156;
					style = 0;
					sizeEx = "0.0285*SafezoneH";
					colorText[] = {0.706,0.0745,0.0196,1};
					shadow = 0;
					font = "EtelkaMonospacePro";
					text = "023";
					x = "25.3 * 		(0.01875 * SafezoneH)";
					y = "9.5 * 		(0.025 * SafezoneH)";
					w = "3.5 * 		(0.01875 * SafezoneH)";
					h = "1.2 * 		(0.025 * SafezoneH)";
				};
			};
		};
	};
	class RscOptics_LaserDesignator
	{
		idd = 300;
		controls[] = {"CA_IGUI_elements_group"};
		class CA_IGUI_elements_group: RscControlsGroup
		{
			idc = 170;
			class VScrollbar: VScrollbar
			{
				width = 0;
			};
			class HScrollbar: HScrollbar
			{
				height = 0;
			};
			x = "0 * 		(0.01875 * SafezoneH) + 		(SafezoneX + ((SafezoneW - SafezoneH) / 2))";
			y = "0 * 		(0.025 * SafezoneH) + 		(SafezoneY)";
			w = "53.5 * 		(0.01875 * SafezoneH)";
			h = "40 * 		(0.025 * SafezoneH)";
			class controls
			{
				class CA_OpticsZoom: RscText
				{
					idc = 180;
					style = 1;
					colorText[] = {0.706,0.0745,0.0196,1};
					sizeEx = "0.038*SafezoneH";
					shadow = 0;
					font = "EtelkaMonospacePro";
					text = "4.5";
					x = "43.85 * 		(0.01875 * SafezoneH)";
					y = "19.6 * 		(0.025 * SafezoneH)";
					w = "4.5 * 		(0.01875 * SafezoneH)";
					h = "1.1 * 		(0.025 * SafezoneH)";
				};
				class CA_Distance: RscText
				{
					idc = 151;
					style = 0;
					sizeEx = "0.038*SafezoneH";
					colorText[] = {0.706,0.0745,0.0196,1};
					shadow = 0;
					font = "EtelkaMonospacePro";
					text = "2456";
					x = "24.5 * 		(0.01875 * SafezoneH)";
					y = "3 * 		(0.025 * SafezoneH)";
					w = "4 * 		(0.01875 * SafezoneH)";
					h = "1.5 * 		(0.025 * SafezoneH)";
				};
				class CA_Elev: RscText
				{
					idc = 175;
					style = 1;
					sizeEx = "0.038*SafezoneH";
					colorText[] = {0.706,0.0745,0.0196,1};
					shadow = 0;
					font = "EtelkaMonospacePro";
					text = "80.5";
					x = "32.7 * 		(0.01875 * SafezoneH)";
					y = "3 * 		(0.025 * SafezoneH)";
					w = "5 * 		(0.01875 * SafezoneH)";
					h = "1.5 * 		(0.025 * SafezoneH)";
				};
				class CA_VisionMode: RscText
				{
					idc = 179;
					style = 0;
					sizeEx = "0.038*SafezoneH";
					colorText[] = {0.706,0.0745,0.0196,1};
					shadow = 0;
					font = "EtelkaMonospacePro";
					text = "VIS";
					x = "6.5 * 		(0.01875 * SafezoneH)";
					y = "19.6 * 		(0.025 * SafezoneH)";
					w = "4 * 		(0.01875 * SafezoneH)";
					h = "1.1 * 		(0.025 * SafezoneH)";
				};
				class CA_Laser: RscText
				{
					idc = 158;
					style = "0x30 + 0x800";
					sizeEx = "0.038*SafezoneH";
					colorText[] = {0.706,0.0745,0.0196,1};
					shadow = 0;
					font = "EtelkaMonospacePro";
					text = "\A3\ui_f\data\igui\rscingameui\rscoptics\laser_designator_iconLaserOn.paa";
					x = "29.2 * 		(0.01875 * SafezoneH)";
					y = "3 * 		(0.025 * SafezoneH)";
					w = "3.5 * 		(0.01875 * SafezoneH)";
					h = "1.5 * 		(0.025 * SafezoneH)";
				};
				class CA_Heading: RscText
				{
					idc = 156;
					style = 0;
					sizeEx = "0.038*SafezoneH";
					colorText[] = {0.706,0.0745,0.0196,1};
					shadow = 0;
					font = "EtelkaMonospacePro";
					text = "023";
					x = "16.1 * 		(0.01875 * SafezoneH)";
					y = "3 * 		(0.025 * SafezoneH)";
					w = "3.5 * 		(0.01875 * SafezoneH)";
					h = "1.6 * 		(0.025 * SafezoneH)";
				};
			};
		};
	};
	class RscWeaponRangeFinderMAAWS
	{
		idd = 300;
		controls[] = {"CA_IGUI_elements_group"};
		class CA_IGUI_elements_group: RscControlsGroup
		{
			x = "SafezoneX";
			y = "SafezoneY";
			w = "SafezoneW";
			h = "SafezoneH";
			idc = 170;
			class VScrollbar: VScrollbar
			{
				autoScrollSpeed = -1;
				autoScrollDelay = 5;
				autoScrollRewind = 0;
				color[] = {1,1,1,0};
				width = 0.001;
			};
			class HScrollbar: HScrollbar
			{
				color[] = {1,1,1,0};
				height = 0.001;
			};
			class Controls
			{
				class CA_Distance: RscOpticsValue
				{
					idc = 151;
					style = 2;
					shadow = 0;
					colorText[] = {0.8196,0.1412,0.1412,1.0};
					sizeEx = "0.038*SafezoneH";
					x = "0.4-SafeZoneX";
					y = "SafezoneH*0.8";
					w = 0.207;
					h = "0.05*SafezoneH";
				};
			};
		};
	};
	class RscWeaponRangeFinderAbramsCom
	{
		idd = 300;
		controls[] = {"CA_Distance"};
		class CA_Distance: RscOpticsValue
		{
			idc = 151;
			style = 2;
			sizeEx = "0.038*SafezoneH";
			colorText[] = {0.8706,0.2275,0.2,1.0};
			x = 0.4;
			y = "(SafezoneY+SafezoneH*0.8)";
			w = 0.207;
			h = "0.05*SafezoneH";
		};
	};
	class RscWeaponRangeFinderAbramsGun
	{
		idd = 300;
		controls[] = {"CA_Distance"};
		class CA_Distance: RscOpticsValue
		{
			idc = 151;
			style = 2;
			sizeEx = "0.038*SafezoneH";
			x = 0.4;
			y = "(SafezoneY+SafezoneH*0.8)";
			w = 0.207;
			h = "0.05*SafezoneH";
		};
	};
	class RscWeaponRangeFinderStrykerMGSGun
	{
		idd = 300;
		controls[] = {"CA_Distance"};
		class CA_Distance: RscOpticsValue
		{
			idc = 151;
			style = 2;
			sizeEx = "0.038*SafezoneH";
			x = 0.4;
			y = "(SafezoneY+SafezoneH*0.8)";
			w = 0.207;
			h = "0.05*SafezoneH";
		};
	};
	class RscOptics_crows: RscUnitInfo
	{
		idd = 300;
		controls[] = {"CA_Zeroing","CA_IGUI_elements_group"};
		class CA_IGUI_elements_group: RscControlsGroup
		{
			idc = 170;
			class VScrollbar: VScrollbar
			{
				width = 0;
			};
			class HScrollbar: HScrollbar
			{
				height = 0;
			};
			x = "0 * 		(0.01875 * SafezoneH) + 		(SafezoneX + ((SafezoneW - SafezoneH) / 2))";
			y = "0 * 		(0.025 * SafezoneH) + 		(SafezoneY)";
			w = "53.5 * 		(0.01875 * SafezoneH)";
			h = "40 * 		(0.025 * SafezoneH)";
			class controls
			{
				class CA_Distance: RscText
				{
					idc = 151;
					style = 0;
					sizeEx = "0.03*SafezoneH";
					colorText[] = {0.706,0.0745,0.0196,0.6};
					shadow = 0;
					font = "EtelkaMonospacePro";
					text = "2456";
					x = "31.5 * 		(0.01875 * SafezoneH)";
					y = "28.2 * 		(0.025 * SafezoneH)";
					w = "4.5 * 		(0.01875 * SafezoneH)";
					h = "1 * 		(0.025 * SafezoneH)";
				};
				class CA_VisionMode: RscText
				{
					idc = 179;
					style = 0;
					sizeEx = "0.03*SafezoneH";
					colorText[] = {0.706,0.0745,0.0196,0.6};
					shadow = 0;
					font = "EtelkaMonospacePro";
					text = "VIS";
					x = "31.5 * 		(0.01875 * SafezoneH)";
					y = "29.5 * 		(0.025 * SafezoneH)";
					w = "4 * 		(0.01875 * SafezoneH)";
					h = "1 * 		(0.025 * SafezoneH)";
				};
				class CA_FlirMode: RscText
				{
					idc = 153;
					style = 0;
					sizeEx = "0.03*SafezoneH";
					colorText[] = {0.706,0.0745,0.0196,0.6};
					shadow = 0;
					font = "EtelkaMonospacePro";
					text = "BHOT";
					x = "33.5 * 		(0.01875 * SafezoneH)";
					y = "29.5 * 		(0.025 * SafezoneH)";
					w = "5 * 		(0.01875 * SafezoneH)";
					h = "1 * 		(0.025 * SafezoneH)";
				};
				class CA_distance_text: RscText
				{
					style = 0;
					sizeEx = "0.03*SafezoneH";
					colorText[] = {0.706,0.0745,0.0196,0.6};
					shadow = 0;
					font = "EtelkaMonospacePro";
					idc = 1003;
					text = "RANGE:";
					x = "27 * 		(0.01875 * SafezoneH)";
					y = "28.2 * 		(0.025 * SafezoneH)";
					w = "5.5 * 		(0.01875 * SafezoneH)";
					h = "1 * 		(0.025 * SafezoneH)";
				};
				class CA_VisionMode_text: RscText
				{
					style = 0;
					sizeEx = "0.03*SafezoneH";
					colorText[] = {0.706,0.0745,0.0196,0.6};
					shadow = 0;
					font = "EtelkaMonospacePro";
					idc = 1004;
					text = "MODE:";
					x = "27 * 		(0.01875 * SafezoneH)";
					y = "29.5 * 		(0.025 * SafezoneH)";
					w = "5.5 * 		(0.01875 * SafezoneH)";
					h = "1 * 		(0.025 * SafezoneH)";
				};
			};
		};
	};
	class RscOptics_strider_commander
	{
		idd = 300;
		controls[] = {"CA_IGUI_elements_group"};
		class CA_IGUI_elements_group: RscControlsGroup
		{
			idc = 170;
			class VScrollbar: VScrollbar
			{
				width = 0;
			};
			class HScrollbar: HScrollbar
			{
				height = 0;
			};
			x = "0 * 		(0.01875 * SafezoneH) + 		(SafezoneX + ((SafezoneW - SafezoneH) / 2))";
			y = "0 * 		(0.025 * SafezoneH) + 		(SafezoneY)";
			w = "53.5 * 		(0.01875 * SafezoneH)";
			h = "40 * 		(0.025 * SafezoneH)";
			class controls
			{
				class CA_OpticsZoom: RscText
				{
					idc = 180;
					style = 1;
					colorText[] = {0.706,0.0745,0.0196,1};
					sizeEx = "0.038*SafezoneH";
					shadow = 0;
					font = "EtelkaMonospacePro";
					text = "4.5";
					x = "43.85 * 		(0.01875 * SafezoneH)";
					y = "19.6 * 		(0.025 * SafezoneH)";
					w = "4.5 * 		(0.01875 * SafezoneH)";
					h = "1.1 * 		(0.025 * SafezoneH)";
				};
				class CA_Distance: RscText
				{
					idc = 151;
					style = 0;
					sizeEx = "0.038*SafezoneH";
					colorText[] = {0.706,0.0745,0.0196,1};
					shadow = 0;
					font = "EtelkaMonospacePro";
					text = "2456";
					x = "24.5 * 		(0.01875 * SafezoneH)";
					y = "3 * 		(0.025 * SafezoneH)";
					w = "4 * 		(0.01875 * SafezoneH)";
					h = "1.5 * 		(0.025 * SafezoneH)";
				};
				class CA_Elev: RscText
				{
					idc = 175;
					style = 1;
					sizeEx = "0.038*SafezoneH";
					colorText[] = {0.706,0.0745,0.0196,1};
					shadow = 0;
					font = "EtelkaMonospacePro";
					text = "80.5";
					x = "32.7 * 		(0.01875 * SafezoneH)";
					y = "3 * 		(0.025 * SafezoneH)";
					w = "5 * 		(0.01875 * SafezoneH)";
					h = "1.5 * 		(0.025 * SafezoneH)";
				};
				class CA_VisionMode: RscText
				{
					idc = 179;
					style = 0;
					sizeEx = "0.038*SafezoneH";
					colorText[] = {0.706,0.0745,0.0196,1};
					shadow = 0;
					font = "EtelkaMonospacePro";
					text = "VIS";
					x = "6.5 * 		(0.01875 * SafezoneH)";
					y = "19.6 * 		(0.025 * SafezoneH)";
					w = "4 * 		(0.01875 * SafezoneH)";
					h = "1.1 * 		(0.025 * SafezoneH)";
				};
				class CA_Laser: RscText
				{
					idc = 158;
					style = "0x30 + 0x800";
					sizeEx = "0.038*SafezoneH";
					colorText[] = {0.706,0.0745,0.0196,1};
					shadow = 0;
					font = "EtelkaMonospacePro";
					text = "\A3\ui_f\data\igui\rscingameui\rscoptics\laser_designator_iconLaserOn.paa";
					x = "29.2 * 		(0.01875 * SafezoneH)";
					y = "3 * 		(0.025 * SafezoneH)";
					w = "3.5 * 		(0.01875 * SafezoneH)";
					h = "1.5 * 		(0.025 * SafezoneH)";
				};
				class CA_Heading: RscText
				{
					idc = 156;
					style = 0;
					sizeEx = "0.038*SafezoneH";
					colorText[] = {0.706,0.0745,0.0196,1};
					shadow = 0;
					font = "EtelkaMonospacePro";
					text = "023";
					x = "16.1 * 		(0.01875 * SafezoneH)";
					y = "3 * 		(0.025 * SafezoneH)";
					w = "3.5 * 		(0.01875 * SafezoneH)";
					h = "1.6 * 		(0.025 * SafezoneH)";
				};
			};
		};
	};
	class RscWeaponZeroing: RscUnitInfo
	{
		idd = 300;
		controls[] = {"CA_Zeroing"};
		class CA_Zeroing: RscText
		{
			idc = 168;
			colorText[] = {"(profilenamespace getvariable ['IGUI_TEXT_RGB_R',0])","(profilenamespace getvariable ['IGUI_TEXT_RGB_G',1])","(profilenamespace getvariable ['IGUI_TEXT_RGB_B',1])","(profilenamespace getvariable ['IGUI_TEXT_RGB_A',0.8])"};
			x = "0 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(profilenamespace getvariable [""IGUI_GRID_WEAPON_X"",		((safezoneX + safezoneW) - 		(12.4 * 			(			((safezoneW / safezoneH) min 1.2) / 40)) - 0.5 * 			(			((safezoneW / safezoneH) min 1.2) / 40))])";
			y = "0 * 			(		(		((safezoneW / safezoneH) min 1.2) / 1.2) / 20) + 			(safezoneY + safezoneH - 		(		((safezoneW / safezoneH) min 1.2) / 1.2)) +  			18 * 			(		(		((safezoneW / safezoneH) min 1.2) / 1.2) / 20) - (1 * 			(		(		((safezoneW / safezoneH) min 1.2) / 1.2) / 20))";
			w = "3 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			sizeEx = "0.8 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
		};
	};
	class RscWeaponRangeZeroing: RscUnitInfo
	{
		idd = 300;
		controls[] = {"CA_Zeroing","CA_DistanceText","CA_Distance"};
		class CA_DistanceText: RscOpticsText
		{
			idc = -1;
			style = 2;
			colorText[] = {1,0,0,1};
			x = 0;
			y = "(SafezoneY+SafezoneH) - 0.05";
			w = 1;
			h = 0.05;
		};
		class CA_Distance: RscOpticsValue
		{
			idc = 151;
			style = 2;
			colorText[] = {1,0.15,0.15,0.65};
			shadow = 0;
			font = "EtelkaMonospacePro";
			x = 0;
			y = "(SafezoneY+SafezoneH) - 0.195";
			w = 1;
			h = 0.05;
		};
	};
	class RscOptics_sos: RscUnitInfo
	{
		idd = 300;
		controls[] = {"CA_IGUI_elements_group","CA_Sniper_WFOV_mode_group","CA_Sniper_NFOV_mode_group"};
		class CA_IGUI_elements_group: RscControlsGroup
		{
			idc = 170;
			class VScrollbar: VScrollbar
			{
				width = 0;
			};
			class HScrollbar: HScrollbar
			{
				height = 0;
			};
			x = "0 * 		(0.01875 * SafezoneH) + 		(SafezoneX + ((SafezoneW - SafezoneH) / 2))";
			y = "0 * 		(0.025 * SafezoneH) + 		(SafezoneY)";
			w = "53.5 * 		(0.01875 * SafezoneH)";
			h = "40 * 		(0.025 * SafezoneH)";
			class controls
			{
				class CA_Distance: RscText
				{
					idc = 151;
					style = 0;
					sizeEx = "0.036*SafezoneH";
					colorText[] = {0.706,0.0745,0.0196,1};
					shadow = 0;
					font = "EtelkaMonospacePro";
					x = "40.35 * 		(0.01875 * SafezoneH)";
					y = "19.7 * 		(0.025 * SafezoneH)";
					w = "4 * 		(0.01875 * SafezoneH)";
					h = "1 * 		(0.025 * SafezoneH)";
				};
			};
		};
		class CA_Sniper_NFOV_mode_group: RscControlsGroup
		{
			idc = 162;
			class VScrollbar: VScrollbar
			{
				width = 0;
			};
			class HScrollbar: HScrollbar
			{
				height = 0;
			};
			x = "0 * 		(0.01875 * SafezoneH) + 		(SafezoneX + ((SafezoneW - SafezoneH) / 2))";
			y = "0 * 		(0.025 * SafezoneH) + 		(SafezoneY)";
			w = "53.5 * 		(0.01875 * SafezoneH)";
			h = "40 * 		(0.025 * SafezoneH)";
			class controls
			{
				class CA_FOVModeNFOV: RscText
				{
					style = 1;
					sizeEx = "0.036*SafezoneH";
					colorText[] = {0.706,0.0745,0.0196,1};
					shadow = 0;
					font = "EtelkaMonospacePro";
					idc = 1002;
					text = "NFOV";
					x = "9.15 * 		(0.01875 * SafezoneH)";
					y = "19.7 * 		(0.025 * SafezoneH)";
					w = "3.9 * 		(0.01875 * SafezoneH)";
					h = "1 * 		(0.025 * SafezoneH)";
				};
			};
		};
		class CA_Sniper_WFOV_mode_group: RscControlsGroup
		{
			idc = 163;
			class VScrollbar: VScrollbar
			{
				width = 0;
			};
			class HScrollbar: HScrollbar
			{
				height = 0;
			};
			x = "0 * 		(0.01875 * SafezoneH) + 		(SafezoneX + ((SafezoneW - SafezoneH) / 2))";
			y = "0 * 		(0.025 * SafezoneH) + 		(SafezoneY)";
			w = "53.5 * 		(0.01875 * SafezoneH)";
			h = "40 * 		(0.025 * SafezoneH)";
			class controls
			{
				class CA_FOVModeWFOV: RscText
				{
					style = 1;
					sizeEx = "0.036*SafezoneH";
					colorText[] = {0.706,0.0745,0.0196,1};
					shadow = 0;
					font = "EtelkaMonospacePro";
					idc = 1001;
					text = "WFOV";
					x = "9.15 * 		(0.01875 * SafezoneH)";
					y = "19.7 * 		(0.025 * SafezoneH)";
					w = "3.9 * 		(0.01875 * SafezoneH)";
					h = "1 * 		(0.025 * SafezoneH)";
				};
			};
		};
	};
	class RscOptics_nightstalker: RscUnitInfo
	{
		idd = 300;
		controls[] = {"CA_IGUI_elements_group"};
		class CA_IGUI_elements_group: RscControlsGroup
		{
			idc = 170;
			class VScrollbar: VScrollbar
			{
				width = 0;
			};
			class HScrollbar: HScrollbar
			{
				height = 0;
			};
			x = "0 * 		(0.01875 * SafezoneH) + 		(SafezoneX + ((SafezoneW - SafezoneH) / 2))";
			y = "0 * 		(0.025 * SafezoneH) + 		(SafezoneY)";
			w = "53.5 * 		(0.01875 * SafezoneH)";
			h = "40 * 		(0.025 * SafezoneH)";
			class controls
			{
				class CA_Distance: RscText
				{
					idc = 151;
					style = 0;
					sizeEx = "0.045*SafezoneH";
					colorText[] = {0,1,0,0.5};
					shadow = 0;
					font = "EtelkaMonospacePro";
					text = "- - - -";
					x = "38 * 		(0.01875 * SafezoneH)";
					y = "19.1 * 		(0.025 * SafezoneH)";
					w = "5.6 * 		(0.01875 * SafezoneH)";
					h = "2 * 		(0.025 * SafezoneH)";
				};
				class CA_VisionMode: RscText
				{
					idc = 179;
					style = 0;
					sizeEx = "0.045*SafezoneH";
					colorText[] = {0,1,0,0.5};
					shadow = 0;
					font = "EtelkaMonospacePro";
					text = "VIS";
					x = "10.5 * 		(0.01875 * SafezoneH)";
					y = "19.1 * 		(0.025 * SafezoneH)";
					w = "5 * 		(0.01875 * SafezoneH)";
					h = "2 * 		(0.025 * SafezoneH)";
				};
				class CA_OpticsZoom: RscText
				{
					idc = 180;
					style = 1;
					sizeEx = "0.028*SafezoneH";
					colorText[] = {0,1,0,0.5};
					shadow = 0;
					font = "EtelkaMonospacePro";
					text = "5.5";
					x = "38.8 * 		(0.01875 * SafezoneH)";
					y = "20.8 * 		(0.025 * SafezoneH)";
					w = "4 * 		(0.01875 * SafezoneH)";
					h = "1.5 * 		(0.025 * SafezoneH)";
				};
				class CA_Bracket: RscText
				{
					idc = 181;
					style = "0x30 + 0x800";
					sizeEx = "0.035*SafezoneH";
					shadow = 0;
					font = "EtelkaMonospacePro";
					text = "A3\weapons_f\acc\Data\reticle_nightstalker_bracket_ca.paa";
					x = "16.5 * 		(0.01875 * SafezoneH)";
					y = "9.75 * 		(0.025 * SafezoneH)";
					w = "20.5 * 		(0.01875 * SafezoneH)";
					h = "20.5 * 		(0.025 * SafezoneH)";
				};
			};
		};
	};
	class RscOptics_tws: RscUnitInfo
	{
		idd = 300;
		controls[] = {"CA_IGUI_elements_group","CA_WFOV_mode_group","CA_NFOV_mode_group"};
		class CA_IGUI_elements_group: RscControlsGroup
		{
			idc = 170;
			class VScrollbar: VScrollbar
			{
				width = 0;
			};
			class HScrollbar: HScrollbar
			{
				height = 0;
			};
			x = "0 * 		(0.01875 * SafezoneH) + 		(SafezoneX + ((SafezoneW - SafezoneH) / 2))";
			y = "0 * 		(0.025 * SafezoneH) + 		(SafezoneY)";
			w = "53.5 * 		(0.01875 * SafezoneH)";
			h = "40 * 		(0.025 * SafezoneH)";
			class controls
			{
				class CA_Distance: RscText
				{
					idc = 151;
					style = 0;
					sizeEx = "0.036*SafezoneH";
					shadow = 0;
					font = "EtelkaMonospacePro";
					text = "- - - -";
					x = "24.75 * 		(0.01875 * SafezoneH)";
					y = "33.2 * 		(0.025 * SafezoneH)";
					w = "3.6 * 		(0.01875 * SafezoneH)";
					h = "1.3 * 		(0.025 * SafezoneH)";
				};
				class CA_VisionMode: RscText
				{
					idc = 152;
					style = 0;
					sizeEx = "0.028*SafezoneH";
					shadow = 0;
					font = "EtelkaMonospacePro";
					text = "FLIR";
					x = "8.8 * 		(0.01875 * SafezoneH)";
					y = "18.7 * 		(0.025 * SafezoneH)";
					w = "3.5 * 		(0.01875 * SafezoneH)";
					h = "1 * 		(0.025 * SafezoneH)";
				};
				class CA_FlirMode: RscText
				{
					idc = 153;
					style = 0;
					sizeEx = "0.028*SafezoneH";
					shadow = 0;
					font = "EtelkaMonospacePro";
					text = "BHOT";
					x = "11.8 * 		(0.01875 * SafezoneH)";
					y = "18.7 * 		(0.025 * SafezoneH)";
					w = "4.5 * 		(0.01875 * SafezoneH)";
					h = "1 * 		(0.025 * SafezoneH)";
				};
			};
		};
		class CA_NFOV_mode_group: RscControlsGroup
		{
			idc = 162;
			class VScrollbar: VScrollbar
			{
				width = 0;
			};
			class HScrollbar: HScrollbar
			{
				height = 0;
			};
			x = "0 * 		(0.01875 * SafezoneH) + 		(SafezoneX + ((SafezoneW - SafezoneH) / 2))";
			y = "0 * 		(0.025 * SafezoneH) + 		(SafezoneY)";
			w = "53.5 * 		(0.01875 * SafezoneH)";
			h = "40 * 		(0.025 * SafezoneH)";
			class controls
			{
				class CA_FOVModeNFOV: RscText
				{
					style = 1;
					sizeEx = "0.028*SafezoneH";
					shadow = 0;
					font = "EtelkaMonospacePro";
					idc = 1002;
					text = "NFOV";
					x = "41.7 * 		(0.01875 * SafezoneH)";
					y = "18.7 * 		(0.025 * SafezoneH)";
					w = "3 * 		(0.01875 * SafezoneH)";
					h = "1 * 		(0.025 * SafezoneH)";
				};
			};
		};
		class CA_WFOV_mode_group: RscControlsGroup
		{
			idc = 163;
			class VScrollbar: VScrollbar
			{
				width = 0;
			};
			class HScrollbar: HScrollbar
			{
				height = 0;
			};
			x = "0 * 		(0.01875 * SafezoneH) + 		(SafezoneX + ((SafezoneW - SafezoneH) / 2))";
			y = "0 * 		(0.025 * SafezoneH) + 		(SafezoneY)";
			w = "53.5 * 		(0.01875 * SafezoneH)";
			h = "40 * 		(0.025 * SafezoneH)";
			class controls
			{
				class CA_FOVModeWFOV: RscText
				{
					style = 1;
					sizeEx = "0.028*SafezoneH";
					shadow = 0;
					font = "EtelkaMonospacePro";
					idc = 1001;
					text = "WFOV";
					x = "41.7 * 		(0.01875 * SafezoneH)";
					y = "18.7 * 		(0.025 * SafezoneH)";
					w = "3 * 		(0.01875 * SafezoneH)";
					h = "1 * 		(0.025 * SafezoneH)";
				};
				class CA_BracketNFOV: RscText
				{
					style = "0x30 + 0x800";
					sizeEx = "0.028*SafezoneH";
					shadow = 0;
					font = "EtelkaMonospacePro";
					idc = 1005;
					text = "A3\weapons_f\acc\Data\reticle_tws_bracket_ca.paa";
					x = "17.75 * 		(0.01875 * SafezoneH)";
					y = "11 * 		(0.025 * SafezoneH)";
					w = "18 * 		(0.01875 * SafezoneH)";
					h = "18 * 		(0.025 * SafezoneH)";
				};
			};
		};
	};
	class RscOptics_cows: RscUnitInfo
	{
		idd = 300;
		controls[] = {"CA_WFOV_mode_group","CA_NFOV_mode_group"};
		class CA_IGUI_elements_group: RscControlsGroup
		{
			idc = 170;
			class VScrollbar: VScrollbar
			{
				width = 0;
			};
			class HScrollbar: HScrollbar
			{
				height = 0;
			};
			x = "0 * 		(0.01875 * SafezoneH) + 		(SafezoneX + ((SafezoneW - SafezoneH) / 2))";
			y = "0 * 		(0.025 * SafezoneH) + 		(SafezoneY)";
			w = "53.5 * 		(0.01875 * SafezoneH)";
			h = "40 * 		(0.025 * SafezoneH)";
			class controls{};
		};
		class CA_NFOV_mode_group: RscControlsGroup
		{
			idc = 162;
			class VScrollbar: VScrollbar
			{
				width = 0;
			};
			class HScrollbar: HScrollbar
			{
				height = 0;
			};
			x = "0 * 		(0.01875 * SafezoneH) + 		(SafezoneX + ((SafezoneW - SafezoneH) / 2))";
			y = "0 * 		(0.025 * SafezoneH) + 		(SafezoneY)";
			w = "53.5 * 		(0.01875 * SafezoneH)";
			h = "40 * 		(0.025 * SafezoneH)";
			class controls
			{
				class CA_Distance_NFOV: RscText
				{
					idc = 183;
					style = 0;
					sizeEx = "0.06*SafezoneH";
					colorText[] = {0.706,0.0745,0.0196,1};
					shadow = 0;
					font = "EtelkaMonospacePro";
					text = "0000";
					x = "38.2 * 		(0.01875 * SafezoneH)";
					y = "19.1 * 		(0.025 * SafezoneH)";
					w = "8 * 		(0.01875 * SafezoneH)";
					h = "2 * 		(0.025 * SafezoneH)";
				};
			};
		};
		class CA_WFOV_mode_group: RscControlsGroup
		{
			idc = 163;
			class VScrollbar: VScrollbar
			{
				width = 0;
			};
			class HScrollbar: HScrollbar
			{
				height = 0;
			};
			x = "0 * 		(0.01875 * SafezoneH) + 		(SafezoneX + ((SafezoneW - SafezoneH) / 2))";
			y = "0 * 		(0.025 * SafezoneH) + 		(SafezoneY)";
			w = "53.5 * 		(0.01875 * SafezoneH)";
			h = "40 * 		(0.025 * SafezoneH)";
			class controls
			{
				class CA_Distance_WFOV: RscText
				{
					idc = 151;
					style = 0;
					sizeEx = "0.03*SafezoneH";
					colorText[] = {0.706,0.0745,0.0196,1};
					shadow = 0;
					font = "EtelkaMonospacePro";
					text = "0000";
					x = "31.45 * 		(0.01875 * SafezoneH)";
					y = "19.6 * 		(0.025 * SafezoneH)";
					w = "4 * 		(0.01875 * SafezoneH)";
					h = "1 * 		(0.025 * SafezoneH)";
				};
			};
		};
	};
	class RscOptics_titan
	{
		idd = 300;
		controls[] = {"CA_javelin_elements_group"};
		class CA_javelin_elements_group: RscControlsGroup
		{
			x = "SafezoneX";
			y = "SafezoneY";
			w = "SafezoneW";
			h = "SafezoneH";
			idc = 170;
			class VScrollbar: VScrollbar
			{
				autoScrollSpeed = -1;
				autoScrollDelay = 5;
				autoScrollRewind = 0;
				color[] = {1,1,1,0};
				width = 0.001;
			};
			class HScrollbar: HScrollbar
			{
				color[] = {1,1,1,0};
				height = 0.001;
			};
			class Controls
			{
				class CA_Javelin_Day_mode_off: RscPicture
				{
					idc = 1001;
					x = "(SafezoneX+(SafezoneW -SafezoneH*3/4)/2)+ (0.03/4)*3*SafezoneH	- SafezoneX";
					y = "SafezoneY+SafezoneH*0.031 - SafezoneY";
					w = "0.1045752* (((SafezoneW*3)/4)/SafezoneW)/(1/SafezoneH)";
					h = "SafezoneH*0.1045752";
					colorText[] = {0.2941,0.2941,0.2941,1.0};
					text = "\A3\ui_f\data\igui\rscingameui\rscoptics_titan\day_co.paa";
				};
				class CA_Javelin_Day_mode: CA_Javelin_Day_mode_off
				{
					idc = 160;
					colorText[] = {0.2941,0.8745,0.2157,1.0};
				};
				class CA_Javelin_WFOV_mode_off: CA_Javelin_Day_mode_off
				{
					idc = 1004;
					x = "(SafezoneX+(SafezoneW -SafezoneH*3/4)/2)+ (0.307/4)*3*SafezoneH - SafezoneX";
					text = "\A3\ui_f\data\igui\rscingameui\rscoptics_titan\wfov_co.paa";
				};
				class CA_Javelin_WFOV_mode_group: RscControlsGroup
				{
					x = "SafezoneX";
					y = "SafezoneY";
					w = "SafezoneW";
					h = "SafezoneH";
					idc = 163;
					class VScrollbar: VScrollbar
					{
						autoScrollSpeed = -1;
						autoScrollDelay = 5;
						autoScrollRewind = 0;
						color[] = {1,1,1,0};
						width = 0.001;
					};
					class HScrollbar: HScrollbar
					{
						color[] = {1,1,1,0};
						height = 0.001;
					};
					class Controls
					{
						class CA_Javelin_WFOV_mode: CA_Javelin_WFOV_mode_off
						{
							idc = -1;
							y = "0.031*SafeZoneH - SafezoneY";
							x = "((SafezoneW -SafezoneH*3/4)/2)+ (0.307/4)*3*SafezoneH - SafezoneX";
							colorText[] = {0.2941,0.8745,0.2157,1.0};
						};
					};
				};
				class CA_Javelin_NFOV_mode_off: CA_Javelin_Day_mode_off
				{
					idc = 1003;
					x = "(SafezoneX+(SafezoneW -SafezoneH*3/4)/2)+ (0.586/4)*3*SafezoneH - SafezoneX";
					text = "\A3\ui_f\data\igui\rscingameui\rscoptics_titan\nfov_co.paa";
				};
				class CA_Javelin_NFOV_mode_group: RscControlsGroup
				{
					x = "SafezoneX";
					y = "SafezoneY";
					w = "SafezoneW-SafezoneX";
					h = "SafezoneH-SafezoneY";
					idc = 162;
					class VScrollbar: VScrollbar
					{
						autoScrollSpeed = -1;
						autoScrollDelay = 5;
						autoScrollRewind = 0;
						color[] = {1,1,1,0};
						width = 0.001;
					};
					class HScrollbar: HScrollbar
					{
						color[] = {1,1,1,0};
						height = 0.001;
					};
					class Controls
					{
						class CA_Javelin_NFOV_mode: CA_Javelin_NFOV_mode_off
						{
							idc = -1;
							x = "((SafezoneW -SafezoneH*3/4)/2)+ (0.586/4)*3*SafezoneH - SafezoneX";
							y = "0.031*SafeZoneH - SafezoneY";
							colorText[] = {0.2941,0.8745,0.2157,1.0};
						};
					};
				};
				class CA_Javelin_SEEK_off: CA_Javelin_Day_mode_off
				{
					x = "(SafezoneX+(SafezoneW -SafezoneH*3/4)/2)+ (0.863/4)*3*SafezoneH - SafezoneX";
					text = "\A3\ui_f\data\igui\rscingameui\rscoptics_titan\seek_co.paa";
				};
				class CA_Javelin_SEEK: CA_Javelin_SEEK_off
				{
					idc = 166;
					colorText[] = {0.2941,0.8745,0.2157,1.0};
				};
				class CA_Javelin_Missle_off: CA_Javelin_Day_mode_off
				{
					idc = 1032;
					x = "(SafezoneX+(SafezoneW -SafezoneH*3/4)/2)+ (-0.134/4)*3*SafezoneH - SafezoneX";
					y = "(SafezoneY + 0.208*SafezoneH) - SafezoneY";
					colorText[] = {0.2941,0.2941,0.2941,1.0};
					text = "\A3\ui_f\data\igui\rscingameui\rscoptics_titan\missle_co.paa";
				};
				class CA_Javelin_Missle: CA_Javelin_Missle_off
				{
					idc = 167;
					colorText[] = {0.9255,0.5216,0.1216,1.0};
				};
				class CA_Javelin_CLU_off: CA_Javelin_Missle_off
				{
					idc = 1027;
					y = "(SafezoneY + 0.436*SafezoneH) - SafezoneY";
					text = "\A3\ui_f\data\igui\rscingameui\rscoptics_titan\clu_co.paa";
				};
				class CA_Javelin_HangFire_off: CA_Javelin_Missle_off
				{
					idc = 1028;
					y = "(SafezoneY + 0.669*SafezoneH) - SafezoneY";
					text = "\A3\ui_f\data\igui\rscingameui\rscoptics_titan\hangfire_co.paa";
				};
				class CA_Javelin_TOP_off: CA_Javelin_Day_mode_off
				{
					idc = 1006;
					x = "(SafezoneX+(SafezoneW -SafezoneH*3/4)/2)+ (1.023/4)*3*SafezoneH - SafezoneX";
					y = "(SafezoneY + 0.208*SafezoneH) - SafezoneY";
					text = "\A3\ui_f\data\igui\rscingameui\rscoptics_titan\top_co.paa";
				};
				class CA_Javelin_DIR: CA_Javelin_Day_mode
				{
					idc = 1007;
					x = "(SafezoneX+(SafezoneW -SafezoneH*3/4)/2)+ (1.023/4)*3*SafezoneH - SafezoneX";
					y = "(SafezoneY + 0.436*SafezoneH)	- SafezoneY";
					text = "\A3\ui_f\data\igui\rscingameui\rscoptics_titan\dir_co.paa";
				};
				class CA_Javelin_FLTR_mode_off: CA_Javelin_Day_mode_off
				{
					idc = 1002;
					x = "(SafezoneX+(SafezoneW -SafezoneH*3/4)/2)+ (1.023/4)*3*SafezoneH - SafezoneX";
					y = "(SafezoneY + 0.669*SafezoneH)	- SafezoneY";
					text = "\A3\ui_f\data\igui\rscingameui\rscoptics_titan\fltr_co.paa";
				};
				class CA_Javelin_FLTR_mode: CA_Javelin_FLTR_mode_off
				{
					idc = 161;
					colorText[] = {0.2941,0.8745,0.2157,1.0};
				};
			};
		};
	};
	class RscOptics_punisher
	{
		idd = 300;
		controls[] = {"CA_IGUI_elements_group"};
		class CA_IGUI_elements_group: RscControlsGroup
		{
			idc = 170;
			x = "SafezoneX + ((SafezoneW - SafezoneH) / 2)";
			y = "SafezoneY";
			w = "SafezoneH";
			h = "SafezoneH";
			class VScrollbar: VScrollbar
			{
				autoScrollSpeed = -1;
				autoScrollDelay = 5;
				autoScrollRewind = 0;
				color[] = {1,1,1,0};
				width = 0.001;
			};
			class HScrollbar: HScrollbar
			{
				color[] = {1,1,1,0};
				height = 0.001;
			};
			class Controls
			{
				class CA_DistanceBackground: RscEdit
				{
					idc = -1;
					sizeEx = "0.038*SafezoneH";
					colorBackground[] = {0,0,0,0};
					colorText[] = {0,0,0,0};
					colorSelection[] = {0,0,0,0};
					style = "0x01 + 0x40";
					shadow = 0;
					type = 0;
					x = "0.3*SafezoneW";
					y = "0.05*SafezoneH";
					w = "0.112222 * safezoneH";
					h = "0.0676503 * safezoneH";
				};
				class CA_Distance: RscOpticsValue
				{
					idc = 151;
					style = 1;
					colorText[] = {0.706,0.0745,0.0196,1};
					sizeEx = "0.038*SafezoneH";
					shadow = 0;
					font = "EtelkaMonospacePro";
					x = "0.41 * safezoneH";
					y = "0.42 * safezoneH";
					w = "0.09 * safezoneH";
					h = "0.03 * safezoneH";
				};
				class CA_VisionMode: RscText
				{
					idc = 179;
					style = 1;
					colorText[] = {0.706,0.0745,0.0196,1};
					sizeEx = "0.038*SafezoneH";
					shadow = 0;
					font = "EtelkaMonospacePro";
					x = "0.72 * safezoneH";
					y = "0.25 * safezoneH";
					w = "0.12 * safezoneH";
					h = "0.03 * safezoneH";
				};
				class A3_DEG_text: RscText
				{
					idc = -1;
					style = 1;
					sizeEx = "0.038*SafezoneH";
					colorText[] = {0.706,0.0745,0.0196,1};
					shadow = 0;
					font = "EtelkaMonospacePro";
					x = "0.72 * safezoneH";
					y = "0.29 * safezoneH";
					w = "0.12 * safezoneH";
					h = "0.03 * safezoneH";
					text = "DEG";
				};
				class CA_Elev: RscOpticsValue
				{
					idc = 175;
					style = 1;
					colorText[] = {0.706,0.0745,0.0196,1};
					sizeEx = "0.038*SafezoneH";
					shadow = 0;
					font = "EtelkaMonospacePro";
					x = "0.72 * safezoneH";
					y = "0.33 * safezoneH";
					w = "0.12 * safezoneH";
					h = "0.03 * safezoneH";
				};
				class A3_FuseRange: RscText
				{
					idc = -1;
					style = 1;
					sizeEx = "0.038*SafezoneH";
					colorText[] = {0.706,0.0745,0.0196,1};
					shadow = 0;
					font = "EtelkaMonospacePro";
					x = "0.72 * safezoneH";
					y = "0.48 * safezoneH";
					w = "0.12 * safezoneH";
					h = "0.03 * safezoneH";
					text = "520";
				};
			};
		};
	};
	class RscUnitInfoParachute: RscUnitInfo
	{
		idd = 300;
		updateWidthByWeapon = 0;
		updateHeightByCrew = 0;
		updateWidthByCrew = 0;
		controls[] = {"WeaponInfoControlsGroupRight","CA_BackgroundVehicle","CA_BackgroundVehicleTitle","CA_BackgroundVehicleTitleDark","CA_BackgroundFuel","CA_Vehicle","CA_VehicleRole","CA_HitZones","CA_SpeedBackground","CA_SpeedUnits","CA_Speed","CA_ValueFuel","CA_AltBackground","CA_AltUnits","CA_Alt","CA_Stabilize"};
	};
	class RscOptics_tws_sniper: RscUnitInfo
	{
		idd = 300;
		controls[] = {"CA_IGUI_elements_group","CA_WFOV_mode_group","CA_NFOV_mode_group"};
		class CA_IGUI_elements_group: RscControlsGroup
		{
			idc = 170;
			class VScrollbar: VScrollbar
			{
				width = 0;
			};
			class HScrollbar: HScrollbar
			{
				height = 0;
			};
			x = "0 * 		(0.01875 * SafezoneH) + 		(SafezoneX + ((SafezoneW - SafezoneH) / 2))";
			y = "0 * 		(0.025 * SafezoneH) + 		(SafezoneY)";
			w = "53.5 * 		(0.01875 * SafezoneH)";
			h = "40 * 		(0.025 * SafezoneH)";
			class controls
			{
				class CA_Distance: RscText
				{
					idc = 151;
					style = 0;
					sizeEx = "0.036*SafezoneH";
					shadow = 0;
					font = "EtelkaMonospacePro";
					text = "- - - -";
					x = "24.75 * 		(0.01875 * SafezoneH)";
					y = "31.5 * 		(0.025 * SafezoneH)";
					w = "3.6 * 		(0.01875 * SafezoneH)";
					h = "1.3 * 		(0.025 * SafezoneH)";
				};
				class CA_VisionMode: RscText
				{
					idc = 152;
					style = 0;
					sizeEx = "0.028*SafezoneH";
					shadow = 0;
					font = "EtelkaMonospacePro";
					text = "FLIR";
					x = "8.8 * 		(0.01875 * SafezoneH)";
					y = "18.7 * 		(0.025 * SafezoneH)";
					w = "3.5 * 		(0.01875 * SafezoneH)";
					h = "1 * 		(0.025 * SafezoneH)";
				};
				class CA_FlirMode: RscText
				{
					idc = 153;
					style = 0;
					sizeEx = "0.028*SafezoneH";
					shadow = 0;
					font = "EtelkaMonospacePro";
					text = "BHOT";
					x = "11.8 * 		(0.01875 * SafezoneH)";
					y = "18.7 * 		(0.025 * SafezoneH)";
					w = "4.5 * 		(0.01875 * SafezoneH)";
					h = "1 * 		(0.025 * SafezoneH)";
				};
			};
		};
		class CA_NFOV_mode_group: RscControlsGroup
		{
			idc = 162;
			class VScrollbar: VScrollbar
			{
				width = 0;
			};
			class HScrollbar: HScrollbar
			{
				height = 0;
			};
			x = "0 * 		(0.01875 * SafezoneH) + 		(SafezoneX + ((SafezoneW - SafezoneH) / 2))";
			y = "0 * 		(0.025 * SafezoneH) + 		(SafezoneY)";
			w = "53.5 * 		(0.01875 * SafezoneH)";
			h = "40 * 		(0.025 * SafezoneH)";
			class controls
			{
				class CA_FOVModeNFOV: RscText
				{
					style = 1;
					sizeEx = "0.028*SafezoneH";
					shadow = 0;
					font = "EtelkaMonospacePro";
					idc = 1002;
					text = "NFOV";
					x = "41.7 * 		(0.01875 * SafezoneH)";
					y = "18.7 * 		(0.025 * SafezoneH)";
					w = "3 * 		(0.01875 * SafezoneH)";
					h = "1 * 		(0.025 * SafezoneH)";
				};
			};
		};
		class CA_WFOV_mode_group: RscControlsGroup
		{
			idc = 163;
			class VScrollbar: VScrollbar
			{
				width = 0;
			};
			class HScrollbar: HScrollbar
			{
				height = 0;
			};
			x = "0 * 		(0.01875 * SafezoneH) + 		(SafezoneX + ((SafezoneW - SafezoneH) / 2))";
			y = "0 * 		(0.025 * SafezoneH) + 		(SafezoneY)";
			w = "53.5 * 		(0.01875 * SafezoneH)";
			h = "40 * 		(0.025 * SafezoneH)";
			class controls
			{
				class CA_FOVModeWFOV: RscText
				{
					style = 1;
					sizeEx = "0.028*SafezoneH";
					shadow = 0;
					font = "EtelkaMonospacePro";
					idc = 1001;
					text = "WFOV";
					x = "41.7 * 		(0.01875 * SafezoneH)";
					y = "18.7 * 		(0.025 * SafezoneH)";
					w = "3 * 		(0.01875 * SafezoneH)";
					h = "1 * 		(0.025 * SafezoneH)";
				};
				class CA_BracketNFOV: RscText
				{
					style = "0x30 + 0x800";
					sizeEx = "0.028*SafezoneH";
					shadow = 0;
					font = "EtelkaMonospacePro";
					idc = 1005;
					text = "A3\weapons_f\acc\Data\reticle_tws_bracket_ca.paa";
					x = "17.75 * 		(0.01875 * SafezoneH)";
					y = "11 * 		(0.025 * SafezoneH)";
					w = "18 * 		(0.01875 * SafezoneH)";
					h = "18 * 		(0.025 * SafezoneH)";
				};
			};
		};
	};
	class RscOptics_tws_mg: RscUnitInfo
	{
		idd = 300;
		controls[] = {"CA_IGUI_elements_group","CA_WFOV_mode_group","CA_NFOV_mode_group"};
		class CA_IGUI_elements_group: RscControlsGroup
		{
			idc = 170;
			class VScrollbar: VScrollbar
			{
				width = 0;
			};
			class HScrollbar: HScrollbar
			{
				height = 0;
			};
			x = "0 * 		(0.01875 * SafezoneH) + 		(SafezoneX + ((SafezoneW - SafezoneH) / 2))";
			y = "0 * 		(0.025 * SafezoneH) + 		(SafezoneY)";
			w = "53.5 * 		(0.01875 * SafezoneH)";
			h = "40 * 		(0.025 * SafezoneH)";
			class controls
			{
				class CA_VisionMode: RscText
				{
					idc = 152;
					style = 0;
					sizeEx = "0.028*SafezoneH";
					shadow = 0;
					font = "EtelkaMonospacePro";
					text = "FLIR";
					x = "8.8 * 		(0.01875 * SafezoneH)";
					y = "18.7 * 		(0.025 * SafezoneH)";
					w = "3.5 * 		(0.01875 * SafezoneH)";
					h = "1 * 		(0.025 * SafezoneH)";
				};
				class CA_FlirMode: RscText
				{
					idc = 153;
					style = 0;
					sizeEx = "0.028*SafezoneH";
					shadow = 0;
					font = "EtelkaMonospacePro";
					text = "BHOT";
					x = "11.8 * 		(0.01875 * SafezoneH)";
					y = "18.7 * 		(0.025 * SafezoneH)";
					w = "4.5 * 		(0.01875 * SafezoneH)";
					h = "1 * 		(0.025 * SafezoneH)";
				};
			};
		};
		class CA_NFOV_mode_group: RscControlsGroup
		{
			idc = 162;
			class VScrollbar: VScrollbar
			{
				width = 0;
			};
			class HScrollbar: HScrollbar
			{
				height = 0;
			};
			x = "0 * 		(0.01875 * SafezoneH) + 		(SafezoneX + ((SafezoneW - SafezoneH) / 2))";
			y = "0 * 		(0.025 * SafezoneH) + 		(SafezoneY)";
			w = "53.5 * 		(0.01875 * SafezoneH)";
			h = "40 * 		(0.025 * SafezoneH)";
			class controls
			{
				class CA_FOVModeNFOV: RscText
				{
					style = 1;
					sizeEx = "0.028*SafezoneH";
					shadow = 0;
					font = "EtelkaMonospacePro";
					idc = 1002;
					text = "NFOV";
					x = "41.7 * 		(0.01875 * SafezoneH)";
					y = "18.7 * 		(0.025 * SafezoneH)";
					w = "3 * 		(0.01875 * SafezoneH)";
					h = "1 * 		(0.025 * SafezoneH)";
				};
			};
		};
		class CA_WFOV_mode_group: RscControlsGroup
		{
			idc = 163;
			class VScrollbar: VScrollbar
			{
				width = 0;
			};
			class HScrollbar: HScrollbar
			{
				height = 0;
			};
			x = "0 * 		(0.01875 * SafezoneH) + 		(SafezoneX + ((SafezoneW - SafezoneH) / 2))";
			y = "0 * 		(0.025 * SafezoneH) + 		(SafezoneY)";
			w = "53.5 * 		(0.01875 * SafezoneH)";
			h = "40 * 		(0.025 * SafezoneH)";
			class controls
			{
				class CA_FOVModeWFOV: RscText
				{
					style = 1;
					sizeEx = "0.028*SafezoneH";
					shadow = 0;
					font = "EtelkaMonospacePro";
					idc = 1001;
					text = "WFOV";
					x = "41.7 * 		(0.01875 * SafezoneH)";
					y = "18.7 * 		(0.025 * SafezoneH)";
					w = "3 * 		(0.01875 * SafezoneH)";
					h = "1 * 		(0.025 * SafezoneH)";
				};
				class CA_BracketNFOV: RscText
				{
					style = "0x30 + 0x800";
					sizeEx = "0.028*SafezoneH";
					shadow = 0;
					font = "EtelkaMonospacePro";
					idc = 1005;
					text = "A3\weapons_f\acc\Data\reticle_tws_bracket_ca.paa";
					x = "17.75 * 		(0.01875 * SafezoneH)";
					y = "11 * 		(0.025 * SafezoneH)";
					w = "18 * 		(0.01875 * SafezoneH)";
					h = "18 * 		(0.025 * SafezoneH)";
				};
			};
		};
	};
	class RscOptics_SDV_driver: RscUnitInfo
	{
		idd = 300;
		controls[] = {"DriverOpticsGroup","WeaponInfoControlsGroupRight","CA_BackgroundVehicle","CA_BackgroundVehicleTitle","CA_BackgroundVehicleTitleDark","CA_BackgroundFuel","CA_Vehicle","CA_VehicleRole","CA_HitZones","CA_SpeedBackground","CA_SpeedUnits","CA_Speed","CA_ValueFuel","CA_Radar","CA_AltBackground","CA_AltUnits","CA_Depth"};
		class DriverOpticsGroup: RscControlsGroup
		{
			idc = 392;
			class VScrollbar: VScrollbar
			{
				width = 0;
			};
			class HScrollbar: HScrollbar
			{
				height = 0;
			};
			x = "0 * 		(0.01875 * SafezoneH) + 		(SafezoneX + ((SafezoneW - SafezoneH) / 2))";
			y = "0 * 		(0.025 * SafezoneH) + 		(SafezoneY)";
			w = "53.5 * 		(0.01875 * SafezoneH)";
			h = "40 * 		(0.025 * SafezoneH)";
			class controls
			{
				class ValuePitch: RscText
				{
					idc = 393;
					style = 0;
					colorText[] = {0.706,0.0745,0.0196,1};
					sizeEx = "0.028*SafezoneH";
					shadow = 0;
					font = "EtelkaMonospacePro";
					x = "39 * 		(0.01875 * SafezoneH)";
					y = "19.54 * 		(0.025 * SafezoneH)";
					w = "3.5 * 		(0.01875 * SafezoneH)";
					h = "1 * 		(0.025 * SafezoneH)";
				};
				class AnalogueHorizon: RscLadderPicture
				{
					idc = 383;
					topValue = 90;
					bottomValue = -90;
					visibleRange = 0.25;
					text = "A3\weapons_F_Beta\reticle\data\reticle_horizon_CA.paa";
					x = "22.5 * 		(0.01875 * SafezoneH)";
					y = "11 * 		(0.025 * SafezoneH)";
					w = "8 * 		(0.01875 * SafezoneH)";
					h = "18 * 		(0.025 * SafezoneH)";
				};
			};
		};
	};
	class RscOptics_SDV_periscope
	{
		idd = 300;
		controls[] = {"CA_IGUI_elements_group"};
		class CA_IGUI_elements_group: RscControlsGroup
		{
			idc = 170;
			class VScrollbar: VScrollbar
			{
				width = 0;
			};
			class HScrollbar: HScrollbar
			{
				height = 0;
			};
			x = "0 * 		(0.01875 * SafezoneH) + 		(SafezoneX + ((SafezoneW - SafezoneH) / 2))";
			y = "0 * 		(0.025 * SafezoneH) + 		(SafezoneY)";
			w = "53.5 * 		(0.01875 * SafezoneH)";
			h = "40 * 		(0.025 * SafezoneH)";
			class controls
			{
				class CA_Elev: RscText
				{
					idc = 175;
					style = 1;
					sizeEx = "0.02*SafezoneH";
					colorText[] = {0.706,0.0745,0.0196,1};
					shadow = 0;
					font = "EtelkaMonospacePro";
					text = "80.5";
					x = "30.2 * 		(0.01875 * SafezoneH)";
					y = "21.2 * 		(0.025 * SafezoneH)";
					w = "2.5 * 		(0.01875 * SafezoneH)";
					h = "0.6 * 		(0.025 * SafezoneH)";
				};
				class CA_OpticsZoom: RscText
				{
					idc = 180;
					style = 1;
					colorText[] = {0.706,0.0745,0.0196,1};
					sizeEx = "0.02*SafezoneH";
					shadow = 0;
					font = "EtelkaMonospacePro";
					text = "4.5";
					x = "30.2 * 		(0.01875 * SafezoneH)";
					y = "22 * 		(0.025 * SafezoneH)";
					w = "2.5 * 		(0.01875 * SafezoneH)";
					h = "0.6 * 		(0.025 * SafezoneH)";
				};
				class CA_VisionMode: RscText
				{
					idc = 179;
					style = 1;
					sizeEx = "0.02*SafezoneH";
					colorText[] = {0.706,0.0745,0.0196,1};
					shadow = 0;
					font = "EtelkaMonospacePro";
					text = "VIS";
					x = "30.2 * 		(0.01875 * SafezoneH)";
					y = "22.8 * 		(0.025 * SafezoneH)";
					w = "2.5 * 		(0.01875 * SafezoneH)";
					h = "0.6 * 		(0.025 * SafezoneH)";
				};
				class CA_Distance: RscText
				{
					idc = 151;
					style = 0;
					sizeEx = "0.03*SafezoneH";
					colorText[] = {0.706,0.0745,0.0196,1};
					shadow = 0;
					font = "EtelkaMonospacePro";
					text = "2456";
					x = "28.75 * 		(0.01875 * SafezoneH)";
					y = "23.82 * 		(0.025 * SafezoneH)";
					w = "3.5 * 		(0.01875 * SafezoneH)";
					h = "1 * 		(0.025 * SafezoneH)";
				};
				class CA_Laser: RscPicture
				{
					idc = 158;
					style = "0x30 + 0x800";
					colorText[] = {0.706,0.0745,0.0196,1};
					shadow = 0;
					text = "A3\ui_f\data\igui\cfg\cursors\select_target_ca.paa";
					x = "25.05 * 		(0.01875 * SafezoneH)";
					y = "18.44 * 		(0.025 * SafezoneH)";
					w = "3.2 * 		(0.01875 * SafezoneH)";
					h = "3.2 * 		(0.025 * SafezoneH)";
				};
			};
		};
	};
	class RscOptics_Heli_Attack_02_gunner: RscUnitInfo
	{
		idd = 300;
		controls[] = {"CA_Zeroing","CA_IGUI_elements_group"};
		class CA_IGUI_elements_group: RscControlsGroup
		{
			idc = 170;
			class VScrollbar: VScrollbar
			{
				width = 0;
			};
			class HScrollbar: HScrollbar
			{
				height = 0;
			};
			x = "0 * 		(0.01875 * SafezoneH) + 		(SafezoneX + ((SafezoneW - SafezoneH) / 2))";
			y = "0 * 		(0.025 * SafezoneH) + 		(SafezoneY)";
			w = "53.5 * 		(0.01875 * SafezoneH)";
			h = "40 * 		(0.025 * SafezoneH)";
			class controls
			{
				class CA_Distance: RscText
				{
					idc = 151;
					style = 2;
					sizeEx = "0.024*SafezoneH";
					colorText[] = {0.706,0.0745,0.0196,1};
					shadow = 0;
					font = "EtelkaMonospacePro";
					text = "2456";
					x = "24.7 * 		(0.01875 * SafezoneH)";
					y = "29.3 * 		(0.025 * SafezoneH)";
					w = "4 * 		(0.01875 * SafezoneH)";
					h = "1.2 * 		(0.025 * SafezoneH)";
				};
				class CA_VisionMode: RscText
				{
					idc = 179;
					style = 0;
					sizeEx = "0.024*SafezoneH";
					colorText[] = {0.706,0.0745,0.0196,1};
					shadow = 0;
					font = "EtelkaMonospacePro";
					text = "VIS";
					x = "14.5 * 		(0.01875 * SafezoneH)";
					y = "18.8 * 		(0.025 * SafezoneH)";
					w = "4 * 		(0.01875 * SafezoneH)";
					h = "1.2 * 		(0.025 * SafezoneH)";
				};
			};
		};
	};
	class RscOptics_Heli_Attack_01_gunner: RscUnitInfo
	{
		idd = 300;
		controls[] = {"CA_Zeroing","CA_IGUI_elements_group"};
		class CA_IGUI_elements_group: RscControlsGroup
		{
			idc = 170;
			class VScrollbar: VScrollbar
			{
				width = 0;
			};
			class HScrollbar: HScrollbar
			{
				height = 0;
			};
			x = "0 * 		(0.01875 * SafezoneH) + 		(SafezoneX + ((SafezoneW - SafezoneH) / 2))";
			y = "0 * 		(0.025 * SafezoneH) + 		(SafezoneY)";
			w = "53.5 * 		(0.01875 * SafezoneH)";
			h = "40 * 		(0.025 * SafezoneH)";
			class controls
			{
				class CA_Distance: RscText
				{
					idc = 151;
					style = 2;
					sizeEx = "0.0295*SafezoneH";
					shadow = 0;
					font = "EtelkaMonospacePro";
					text = "2456";
					x = "24.78 * 		(0.01875 * SafezoneH)";
					y = "30.88 * 		(0.025 * SafezoneH)";
					w = "4 * 		(0.01875 * SafezoneH)";
					h = "1.2 * 		(0.025 * SafezoneH)";
				};
				class CA_VisionMode: RscText
				{
					idc = 179;
					style = 0;
					sizeEx = "0.0295*SafezoneH";
					shadow = 0;
					font = "EtelkaMonospacePro";
					text = "VIS";
					x = "9.3 * 		(0.01875 * SafezoneH)";
					y = "15.34 * 		(0.025 * SafezoneH)";
					w = "4 * 		(0.01875 * SafezoneH)";
					h = "1.2 * 		(0.025 * SafezoneH)";
				};
				class CA_FlirMode: RscText
				{
					idc = 153;
					style = 0;
					sizeEx = "0.0295*SafezoneH";
					shadow = 0;
					font = "EtelkaMonospacePro";
					text = "BHOT";
					x = "11.15 * 		(0.01875 * SafezoneH)";
					y = "15.34 * 		(0.025 * SafezoneH)";
					w = "4.5 * 		(0.01875 * SafezoneH)";
					h = "1.2 * 		(0.025 * SafezoneH)";
				};
			};
		};
	};
	class RscHint
	{
		idd = 301;
		movingEnable = 0;
		controls[] = {"Background","Hint"};
		class Background: RscText
		{
			idc = 101;
			style = 128;
			x = "((safezoneX + safezoneW) - 		(12 * 			(			((safezoneW / safezoneH) min 1.2) / 40)) - 1 * 			(			((safezoneW / safezoneH) min 1.2) / 40))";
			y = "(safezoneY + 6 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25))";
			w = "(12 * 			(			((safezoneW / safezoneH) min 1.2) / 40))";
			h = "(8 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25))";
			text = "";
			colorBackground[] = {0,0,0,0.7};
			shadow = 1;
		};
		class Hint: RscStructuredText
		{
			idc = 102;
			x = "((safezoneX + safezoneW) - 		(12 * 			(			((safezoneW / safezoneH) min 1.2) / 40)) - 1 * 			(			((safezoneW / safezoneH) min 1.2) / 40)) + 0.4*					(			((safezoneW / safezoneH) min 1.2) / 40)";
			y = "(safezoneY + 6 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)) + 0.3*					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			w = "(12 * 			(			((safezoneW / safezoneH) min 1.2) / 40)) - 0.8*					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "(8 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)) - 0.8*					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			style = 16;
			shadow = 1;
			size = "(			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 0.8)";
			class Attributes: Attributes{};
		};
	};
	class RscTaskHint
	{
		idd = 302;
		movingEnable = 0;
		class controlsBackground
		{
			class Background: RscText
			{
				type = 0;
				idc = 103;
				x = "(10 * 						(		((safezoneW / safezoneH) min 1.2) / 32) + 			(safezoneX + (safezoneW - 				((safezoneW / safezoneH) min 1.2)) / 2))";
				y = "(1 * 						(		(		((safezoneW / safezoneH) min 1.2) / 1.2) / 20) + safezoneY)";
				w = "10 * 								(		((safezoneW / safezoneH) min 1.2) / 32)";
				h = "2 * 								(		(		((safezoneW / safezoneH) min 1.2) / 1.2) / 20)";
				text = "";
				colorBackground[] = {"(profilenamespace getvariable ['IGUI_BCG_RGB_R',0])","(profilenamespace getvariable ['IGUI_BCG_RGB_G',1])","(profilenamespace getvariable ['IGUI_BCG_RGB_B',1])","(profilenamespace getvariable ['IGUI_BCG_RGB_A',0.8])"};
			};
			class Warning: RscText
			{
				x = "(10 * 						(		((safezoneW / safezoneH) min 1.2) / 32) + 			(safezoneX + (safezoneW - 				((safezoneW / safezoneH) min 1.2)) / 2)) - 2 * 								(		((safezoneW / safezoneH) min 1.2) / 32)";
				y = "(1 * 						(		(		((safezoneW / safezoneH) min 1.2) / 1.2) / 20) + safezoneY) + 2.1 * 								(		(		((safezoneW / safezoneH) min 1.2) / 1.2) / 20)";
				w = "14 * 								(		((safezoneW / safezoneH) min 1.2) / 32)";
				h = "1.5 * 								(		(		((safezoneW / safezoneH) min 1.2) / 1.2) / 20)";
				style = "0x10 + 0x200";
				text = "Designers, taskHint is obsolete, use new notifications:\nhttp://community.bistudio.com/wiki/Notification";
				colorText[] = {1,1,1,1};
				colorBackground[] = {"(profilenamespace getvariable ['IGUI_WARNING_RGB_R',0.8])","(profilenamespace getvariable ['IGUI_WARNING_RGB_G',0.5])","(profilenamespace getvariable ['IGUI_WARNING_RGB_B',0.0])",0.7};
				sizeEx = "0.6 * 								(		(		((safezoneW / safezoneH) min 1.2) / 1.2) / 20)";
			};
		};
		class Controls
		{
			class Hint: RscStructuredText
			{
				idc = 104;
				x = "1.5 * 								(		((safezoneW / safezoneH) min 1.2) / 32) + 				(10 * 						(		((safezoneW / safezoneH) min 1.2) / 32) + 			(safezoneX + (safezoneW - 				((safezoneW / safezoneH) min 1.2)) / 2))";
				y = "0.5 * 								(		(		((safezoneW / safezoneH) min 1.2) / 1.2) / 20) + 				(1 * 						(		(		((safezoneW / safezoneH) min 1.2) / 1.2) / 20) + safezoneY)";
				w = "8 * 								(		((safezoneW / safezoneH) min 1.2) / 32)";
				h = "1 * 								(		(		((safezoneW / safezoneH) min 1.2) / 1.2) / 20)";
				style = 16;
				lineSpacing = 1;
				sizeEx = "(			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 1)";
				colorText[] = {1,1,1,1};
				colorBackground[] = {0,0,0,0};
				font = "PuristaMedium";
				size = "(			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 1)";
				text = "$STR_DISP_ERROR";
				class Attributes: Attributes
				{
					color = "#ffffff";
					align = "left";
					shadow = 1;
				};
			};
		};
		class TaskIcon
		{
			x = "0.5 * 								(		((safezoneW / safezoneH) min 1.2) / 32) + 				(10 * 						(		((safezoneW / safezoneH) min 1.2) / 32) + 			(safezoneX + (safezoneW - 				((safezoneW / safezoneH) min 1.2)) / 2))";
			y = "0.5 * 								(		(		((safezoneW / safezoneH) min 1.2) / 1.2) / 20) + 				(1 * 						(		(		((safezoneW / safezoneH) min 1.2) / 1.2) / 20) + safezoneY)";
			w = "1 * 								(		((safezoneW / safezoneH) min 1.2) / 32)";
			h = "1 * 								(		(		((safezoneW / safezoneH) min 1.2) / 1.2) / 20)";
		};
	};
	class RscOptics_AV_pilot: RscUnitInfo
	{
		idd = 300;
		controls[] = {"WeaponInfoControlsGroupRight","CA_BackgroundVehicle","CA_BackgroundVehicleTitle","CA_BackgroundVehicleTitleDark","CA_BackgroundFuel","CA_Vehicle","CA_VehicleRole","CA_HitZones","CA_SpeedBackground","CA_SpeedUnits","CA_Speed","CA_ValueFuel","CA_AltBackground","CA_AltUnits","CA_Alt","CA_Stabilize","CA_Radar","DriverOpticsGroup"};
		class DriverOpticsGroup: RscControlsGroup
		{
			idc = 392;
			class VScrollbar: VScrollbar
			{
				width = 0;
			};
			class HScrollbar: HScrollbar
			{
				height = 0;
			};
			x = "0 * 		(0.01875 * SafezoneH) + 		(SafezoneX + ((SafezoneW - SafezoneH) / 2))";
			y = "0 * 		(0.025 * SafezoneH) + 		(SafezoneY)";
			w = "53.5 * 		(0.01875 * SafezoneH)";
			h = "40 * 		(0.025 * SafezoneH)";
			class controls
			{
				class TextGrid: RscText
				{
					style = 0;
					sizeEx = "0.02*SafezoneH";
					shadow = 0;
					font = "EtelkaMonospacePro";
					idc = 1005;
					text = "GRID:";
					x = "5.8 * 		(0.01875 * SafezoneH)";
					y = "31.8 * 		(0.025 * SafezoneH)";
					w = "5 * 		(0.01875 * SafezoneH)";
					h = "1 * 		(0.025 * SafezoneH)";
				};
				class ValueGrid: TextGrid
				{
					idc = 189;
					text = "382546";
					x = "10.3 * 		(0.01875 * SafezoneH)";
					y = "31.8 * 		(0.025 * SafezoneH)";
					w = "6 * 		(0.01875 * SafezoneH)";
					h = "1 * 		(0.025 * SafezoneH)";
				};
				class TextTime: TextGrid
				{
					idc = 1010;
					text = "TIME [UTC]:";
					x = "5.8 * 		(0.01875 * SafezoneH)";
					y = "32.6 * 		(0.025 * SafezoneH)";
					w = "5 * 		(0.01875 * SafezoneH)";
					h = "1 * 		(0.025 * SafezoneH)";
				};
				class ValueTime: TextGrid
				{
					idc = 101;
					text = "20:28:35";
					x = "10 * 		(0.01875 * SafezoneH)";
					y = "32.6 * 		(0.025 * SafezoneH)";
					w = "6 * 		(0.01875 * SafezoneH)";
					h = "1 * 		(0.025 * SafezoneH)";
				};
				class TextMag: TextGrid
				{
					idc = 1011;
					text = "CAM MAG:";
					x = "5.8 * 		(0.01875 * SafezoneH)";
					y = "7 * 		(0.025 * SafezoneH)";
					w = "5 * 		(0.01875 * SafezoneH)";
					h = "1 * 		(0.025 * SafezoneH)";
				};
				class OpticsZoom: TextGrid
				{
					idc = 192;
					text = "28x";
					x = "10.3 * 		(0.01875 * SafezoneH)";
					y = "7 * 		(0.025 * SafezoneH)";
					w = "6 * 		(0.01875 * SafezoneH)";
					h = "1 * 		(0.025 * SafezoneH)";
				};
				class BorderLineSpdTop: RscPicture
				{
					idc = 1203;
					text = "\A3\Ui_f\data\IGUI\Cfg\HelicopterHUD\border_line_ca.paa";
					x = "3.343 * 		(0.01875 * SafezoneH)";
					y = "12.4 * 		(0.025 * SafezoneH)";
					w = "3 * 		(0.01875 * SafezoneH)";
					h = "1 * 		(0.025 * SafezoneH)";
				};
				class BorderLineSpdBottom: RscPicture
				{
					idc = 1207;
					text = "\A3\Ui_f\data\IGUI\Cfg\HelicopterHUD\border_line_ca.paa";
					x = "3.343 * 		(0.01875 * SafezoneH)";
					y = "26.5 * 		(0.025 * SafezoneH)";
					w = "3 * 		(0.01875 * SafezoneH)";
					h = "1 * 		(0.025 * SafezoneH)";
				};
				class BorderLineAltTop: RscPicture
				{
					idc = 1205;
					text = "\A3\Ui_f\data\IGUI\Cfg\HelicopterHUD\border_line_ca.paa";
					x = "47.16 * 		(0.01875 * SafezoneH)";
					y = "12.4 * 		(0.025 * SafezoneH)";
					w = "3 * 		(0.01875 * SafezoneH)";
					h = "1 * 		(0.025 * SafezoneH)";
				};
				class BorderLineAltBottom: RscPicture
				{
					idc = 1206;
					text = "\A3\Ui_f\data\IGUI\Cfg\HelicopterHUD\border_line_ca.paa";
					x = "47.16 * 		(0.01875 * SafezoneH)";
					y = "26.5 * 		(0.025 * SafezoneH)";
					w = "3 * 		(0.01875 * SafezoneH)";
					h = "1 * 		(0.025 * SafezoneH)";
				};
				class TextSpd: TextGrid
				{
					idc = 1004;
					text = "SPD";
					x = "4.8 * 		(0.01875 * SafezoneH)";
					y = "11.8 * 		(0.025 * SafezoneH)";
					w = "5 * 		(0.01875 * SafezoneH)";
					h = "1.2 * 		(0.025 * SafezoneH)";
				};
				class SpeedValueBorder: RscPicture
				{
					idc = 1200;
					text = "\A3\Ui_f\data\IGUI\Cfg\HelicopterHUD\altimeter_value_ca.paa";
					x = "6.3 * 		(0.01875 * SafezoneH)";
					y = "19 * 		(0.025 * SafezoneH)";
					w = "5 * 		(0.01875 * SafezoneH)";
					h = "2 * 		(0.025 * SafezoneH)";
				};
				class CA_Speed: TextGrid
				{
					idc = 190;
					sizeEx = "0.03*SafezoneH";
					text = "120";
					x = "7.5 * 		(0.01875 * SafezoneH)";
					y = "19.5 * 		(0.025 * SafezoneH)";
					w = "6 * 		(0.01875 * SafezoneH)";
					h = "1.2 * 		(0.025 * SafezoneH)";
				};
				class AnalogueSpeed: RscLadderPicture
				{
					idc = 384;
					topValue = 1312;
					bottomValue = -345;
					visibleRange = -1;
					text = "\A3\Ui_f\data\IGUI\Cfg\HelicopterHUD\UAVspeedLadder_ca.paa";
					x = "1.5 * 		(0.01875 * SafezoneH)";
					y = "13 * 		(0.025 * SafezoneH)";
					w = "5 * 		(0.01875 * SafezoneH)";
					h = "14 * 		(0.025 * SafezoneH)";
				};
				class TextAlt: TextGrid
				{
					idc = 1006;
					text = "ALT";
					x = "46.9 * 		(0.01875 * SafezoneH)";
					y = "11.8 * 		(0.025 * SafezoneH)";
					w = "5 * 		(0.01875 * SafezoneH)";
					h = "1.2 * 		(0.025 * SafezoneH)";
				};
				class AltValueBorder: RscPicture
				{
					idc = 1201;
					text = "\A3\Ui_f\data\IGUI\Cfg\HelicopterHUD\airspeed_value_ca.paa";
					x = "42.25 * 		(0.01875 * SafezoneH)";
					y = "19 * 		(0.025 * SafezoneH)";
					w = "5 * 		(0.01875 * SafezoneH)";
					h = "2 * 		(0.025 * SafezoneH)";
				};
				class CA_Alt: TextGrid
				{
					idc = 191;
					sizeEx = "0.03*SafezoneH";
					style = 1;
					text = "3825";
					x = "43 * 		(0.01875 * SafezoneH)";
					y = "19.5 * 		(0.025 * SafezoneH)";
					w = "3.2 * 		(0.01875 * SafezoneH)";
					h = "1.2 * 		(0.025 * SafezoneH)";
				};
				class AnalogueAlt: RscLadderPicture
				{
					idc = 385;
					topValue = 14430;
					bottomValue = -2110;
					visibleRange = -1;
					text = "\A3\Ui_f\data\IGUI\Cfg\HelicopterHUD\UAValtLadder_ca.paa";
					x = "47 * 		(0.01875 * SafezoneH)";
					y = "13 * 		(0.025 * SafezoneH)";
					w = "2.5 * 		(0.01875 * SafezoneH)";
					h = "14 * 		(0.025 * SafezoneH)";
				};
				class AnalogueHorizon: RscLadderPicture
				{
					idc = 383;
					topValue = 90;
					bottomValue = -90;
					visibleRange = -1;
					text = "\A3\Ui_f\data\IGUI\Cfg\HelicopterHUD\horizon_ladder_ca.paa";
					x = "16.75 * 		(0.01875 * SafezoneH)";
					y = "5 * 		(0.025 * SafezoneH)";
					w = "20 * 		(0.01875 * SafezoneH)";
					h = "30 * 		(0.025 * SafezoneH)";
				};
				class HorizonCenter: RscPicture
				{
					idc = 1202;
					text = "\A3\Ui_f\data\IGUI\Cfg\HelicopterHUD\horizon_aircraft_ca.paa";
					x = "24.75 * 		(0.01875 * SafezoneH)";
					y = "19 * 		(0.025 * SafezoneH)";
					w = "4 * 		(0.01875 * SafezoneH)";
					h = "2 * 		(0.025 * SafezoneH)";
				};
			};
		};
	};
	class RscOptics_AV_driver: RscUnitInfo
	{
		idd = 300;
		controls[] = {"WeaponInfoControlsGroupRight","CA_Zeroing","CA_BackgroundVehicle","CA_BackgroundVehicleTitle","CA_BackgroundVehicleTitleDark","CA_BackgroundFuel","CA_Vehicle","CA_VehicleRole","CA_HitZones","CA_SpeedBackground","CA_SpeedUnits","CA_Speed","CA_ValueFuel","CA_Radar","DriverOpticsGroup"};
		class DriverOpticsGroup: RscControlsGroup
		{
			idc = 392;
			class VScrollbar: VScrollbar
			{
				width = 0;
			};
			class HScrollbar: HScrollbar
			{
				height = 0;
			};
			x = "0 * 		(0.01875 * SafezoneH) + 		(SafezoneX + ((SafezoneW - SafezoneH) / 2))";
			y = "0 * 		(0.025 * SafezoneH) + 		(SafezoneY)";
			w = "53.5 * 		(0.01875 * SafezoneH)";
			h = "40 * 		(0.025 * SafezoneH)";
			class controls
			{
				class TextGrid: RscText
				{
					style = 0;
					sizeEx = "0.02*SafezoneH";
					shadow = 0;
					font = "EtelkaMonospacePro";
					idc = 1006;
					text = "GRID:";
					x = "5.8 * 		(0.01875 * SafezoneH)";
					y = "31.8 * 		(0.025 * SafezoneH)";
					w = "5 * 		(0.01875 * SafezoneH)";
					h = "1 * 		(0.025 * SafezoneH)";
				};
				class TextTime: TextGrid
				{
					idc = 1010;
					text = "TIME [UTC]:";
					x = "5.8 * 		(0.01875 * SafezoneH)";
					y = "32.6 * 		(0.025 * SafezoneH)";
					w = "5 * 		(0.01875 * SafezoneH)";
					h = "1 * 		(0.025 * SafezoneH)";
				};
				class ValueTime: TextGrid
				{
					idc = 101;
					text = "20:28:35";
					x = "10 * 		(0.01875 * SafezoneH)";
					y = "32.6 * 		(0.025 * SafezoneH)";
					w = "6 * 		(0.01875 * SafezoneH)";
					h = "1 * 		(0.025 * SafezoneH)";
				};
				class TextMag: TextGrid
				{
					idc = 1011;
					text = "CAM MAG:";
					x = "5.8 * 		(0.01875 * SafezoneH)";
					y = "7 * 		(0.025 * SafezoneH)";
					w = "5 * 		(0.01875 * SafezoneH)";
					h = "1.2 * 		(0.025 * SafezoneH)";
				};
				class OpticsZoom: TextGrid
				{
					idc = 192;
					text = "28x";
					x = "10.3 * 		(0.01875 * SafezoneH)";
					y = "7 * 		(0.025 * SafezoneH)";
					w = "6 * 		(0.01875 * SafezoneH)";
					h = "1.2 * 		(0.025 * SafezoneH)";
				};
				class BorderLineSpdTop: RscPicture
				{
					idc = 1203;
					text = "\A3\Ui_f\data\IGUI\Cfg\HelicopterHUD\border_line_ca.paa";
					x = "3.343 * 		(0.01875 * SafezoneH)";
					y = "12.4 * 		(0.025 * SafezoneH)";
					w = "3 * 		(0.01875 * SafezoneH)";
					h = "1 * 		(0.025 * SafezoneH)";
				};
				class BorderLineSpdBottom: RscPicture
				{
					idc = 1207;
					text = "\A3\Ui_f\data\IGUI\Cfg\HelicopterHUD\border_line_ca.paa";
					x = "3.343 * 		(0.01875 * SafezoneH)";
					y = "26.5 * 		(0.025 * SafezoneH)";
					w = "3 * 		(0.01875 * SafezoneH)";
					h = "1 * 		(0.025 * SafezoneH)";
				};
				class TextSpd: TextGrid
				{
					idc = 1000;
					text = "SPD";
					x = "4.8 * 		(0.01875 * SafezoneH)";
					y = "11.8 * 		(0.025 * SafezoneH)";
					w = "5 * 		(0.01875 * SafezoneH)";
					h = "1.2 * 		(0.025 * SafezoneH)";
				};
				class SpeedValueBorder: RscPictureKeepAspect
				{
					idc = 1200;
					text = "\A3\Ui_f\data\IGUI\Cfg\HelicopterHUD\altimeter_value_ca.paa";
					x = "6.3 * 		(0.01875 * SafezoneH)";
					y = "19 * 		(0.025 * SafezoneH)";
					w = "4 * 		(0.01875 * SafezoneH)";
					h = "2 * 		(0.025 * SafezoneH)";
				};
				class CA_Speed: TextGrid
				{
					idc = 190;
					sizeEx = "0.03*SafezoneH";
					text = "120";
					x = "7.2 * 		(0.01875 * SafezoneH)";
					y = "19.5 * 		(0.025 * SafezoneH)";
					w = "6 * 		(0.01875 * SafezoneH)";
					h = "1.2 * 		(0.025 * SafezoneH)";
				};
				class AnalogueSpeed: RscLadderPicture
				{
					idc = 384;
					topValue = 82.5;
					bottomValue = -82.5;
					visibleRange = -1;
					text = "\A3\Ui_f\data\IGUI\Cfg\HelicopterHUD\UGVspeedLadder_ca.paa";
					x = "4 * 		(0.01875 * SafezoneH)";
					y = "13 * 		(0.025 * SafezoneH)";
					w = "2.5 * 		(0.01875 * SafezoneH)";
					h = "14 * 		(0.025 * SafezoneH)";
				};
				class ValueGrid: TextGrid
				{
					idc = 189;
					text = "382546";
					x = "10.3 * 		(0.01875 * SafezoneH)";
					y = "31.8 * 		(0.025 * SafezoneH)";
					w = "6 * 		(0.01875 * SafezoneH)";
					h = "1 * 		(0.025 * SafezoneH)";
				};
			};
		};
	};
	class RscOptics_UAV_gunner: RscUnitInfo
	{
		idd = 300;
		controls[] = {"CA_IGUI_elements_group"};
		class CA_IGUI_elements_group: RscControlsGroup
		{
			idc = 170;
			class VScrollbar: VScrollbar
			{
				width = 0;
			};
			class HScrollbar: HScrollbar
			{
				height = 0;
			};
			x = "0 * 		(0.01875 * SafezoneH) + 		(SafezoneX + ((SafezoneW - SafezoneH) / 2))";
			y = "0 * 		(0.025 * SafezoneH) + 		(SafezoneY)";
			w = "53.5 * 		(0.01875 * SafezoneH)";
			h = "40 * 		(0.025 * SafezoneH)";
			class controls
			{
				class RangeText: RscText
				{
					style = 0;
					sizeEx = "0.02*SafezoneH";
					shadow = 0;
					font = "EtelkaMonospacePro";
					idc = 1000;
					text = "RANGE:";
					x = "18.5 * 		(0.01875 * SafezoneH)";
					y = "13.2 * 		(0.025 * SafezoneH)";
					w = "3 * 		(0.01875 * SafezoneH)";
					h = "1.2 * 		(0.025 * SafezoneH)";
				};
				class CA_Distance: RangeText
				{
					idc = 151;
					text = "2456";
					x = "21.3 * 		(0.01875 * SafezoneH)";
					y = "13.2 * 		(0.025 * SafezoneH)";
					w = "4 * 		(0.01875 * SafezoneH)";
					h = "1.2 * 		(0.025 * SafezoneH)";
				};
				class ModeText: RangeText
				{
					idc = 1002;
					text = "MODE:";
					x = "18.5 * 		(0.01875 * SafezoneH)";
					y = "26.8 * 		(0.025 * SafezoneH)";
					w = "3 * 		(0.01875 * SafezoneH)";
					h = "1.2 * 		(0.025 * SafezoneH)";
				};
				class CA_VisionMode: RangeText
				{
					idc = 179;
					style = 0;
					text = "VIS";
					x = "22.2 * 		(0.01875 * SafezoneH)";
					y = "26.8 * 		(0.025 * SafezoneH)";
					w = "4 * 		(0.01875 * SafezoneH)";
					h = "1.2 * 		(0.025 * SafezoneH)";
				};
				class CA_FlirMode: RangeText
				{
					idc = 153;
					style = 0;
					text = "BHOT";
					x = "23.4 * 		(0.01875 * SafezoneH)";
					y = "26.8 * 		(0.025 * SafezoneH)";
					w = "4.5 * 		(0.01875 * SafezoneH)";
					h = "1.2 * 		(0.025 * SafezoneH)";
				};
				class TextSpd: RangeText
				{
					idc = 1009;
					text = "SPD [KM/H]:";
					x = "5.8 * 		(0.01875 * SafezoneH)";
					y = "12.4 * 		(0.025 * SafezoneH)";
					w = "5 * 		(0.01875 * SafezoneH)";
					h = "1.2 * 		(0.025 * SafezoneH)";
				};
				class CA_Speed: RangeText
				{
					idc = 188;
					text = "120";
					x = "10.3 * 		(0.01875 * SafezoneH)";
					y = "12.4 * 		(0.025 * SafezoneH)";
					w = "5 * 		(0.01875 * SafezoneH)";
					h = "1.2 * 		(0.025 * SafezoneH)";
				};
				class TextAlt: RangeText
				{
					idc = 1007;
					text = "ALT [AGL]:";
					x = "5.8 * 		(0.01875 * SafezoneH)";
					y = "13.2 * 		(0.025 * SafezoneH)";
					w = "5 * 		(0.01875 * SafezoneH)";
					h = "1.2 * 		(0.025 * SafezoneH)";
				};
				class CA_Alt: RangeText
				{
					idc = 189;
					text = "3825";
					x = "10.3 * 		(0.01875 * SafezoneH)";
					y = "13.2 * 		(0.025 * SafezoneH)";
					w = "5 * 		(0.01875 * SafezoneH)";
					h = "1.2 * 		(0.025 * SafezoneH)";
				};
				class TextGrid: RangeText
				{
					idc = 1005;
					text = "GRID:";
					x = "5.8 * 		(0.01875 * SafezoneH)";
					y = "31.8 * 		(0.025 * SafezoneH)";
					w = "5 * 		(0.01875 * SafezoneH)";
					h = "1.2 * 		(0.025 * SafezoneH)";
				};
				class ValueGrid: RangeText
				{
					idc = 171;
					text = "382546";
					x = "10.3 * 		(0.01875 * SafezoneH)";
					y = "31.8 * 		(0.025 * SafezoneH)";
					w = "6 * 		(0.01875 * SafezoneH)";
					h = "1 * 		(0.025 * SafezoneH)";
				};
				class TextTime: RangeText
				{
					idc = 1010;
					text = "TIME [UTC]:";
					x = "5.8 * 		(0.01875 * SafezoneH)";
					y = "32.6 * 		(0.025 * SafezoneH)";
					w = "5 * 		(0.01875 * SafezoneH)";
					h = "1 * 		(0.025 * SafezoneH)";
				};
				class ValueTime: RangeText
				{
					idc = 190;
					text = "20:28:35";
					x = "10 * 		(0.01875 * SafezoneH)";
					y = "32.6 * 		(0.025 * SafezoneH)";
					w = "6 * 		(0.01875 * SafezoneH)";
					h = "1 * 		(0.025 * SafezoneH)";
				};
				class TextMag: RangeText
				{
					idc = 1011;
					text = "CAM MAG:";
					x = "18.5 * 		(0.01875 * SafezoneH)";
					y = "26 * 		(0.025 * SafezoneH)";
					w = "5 * 		(0.01875 * SafezoneH)";
					h = "1.2 * 		(0.025 * SafezoneH)";
				};
				class CA_OpticsZoom: RangeText
				{
					idc = 180;
					text = "28x";
					x = "22.2 * 		(0.01875 * SafezoneH)";
					y = "26 * 		(0.025 * SafezoneH)";
					w = "6 * 		(0.01875 * SafezoneH)";
					h = "1.2 * 		(0.025 * SafezoneH)";
				};
				class CA_Laser: RscText
				{
					idc = 158;
					style = "0x30 + 0x800";
					sizeEx = "0.038*SafezoneH";
					colorText[] = {0.706,0.0745,0.0196,1};
					shadow = 0;
					font = "EtelkaMonospacePro";
					text = "\A3\ui_f\data\igui\rscingameui\rscoptics\laser_designator_iconLaserOn.paa";
					x = "31.1 * 		(0.01875 * SafezoneH)";
					y = "12.85 * 		(0.025 * SafezoneH)";
					w = "3.5 * 		(0.01875 * SafezoneH)";
					h = "1.5 * 		(0.025 * SafezoneH)";
				};
			};
		};
	};
	class RscOptics_UGV_gunner: RscUnitInfo
	{
		idd = 300;
		controls[] = {"CA_Zeroing","CA_IGUI_elements_group"};
		class CA_IGUI_elements_group: RscControlsGroup
		{
			idc = 170;
			class VScrollbar: VScrollbar
			{
				width = 0;
			};
			class HScrollbar: HScrollbar
			{
				height = 0;
			};
			x = "0 * 		(0.01875 * SafezoneH) + 		(SafezoneX + ((SafezoneW - SafezoneH) / 2))";
			y = "0 * 		(0.025 * SafezoneH) + 		(SafezoneY)";
			w = "53.5 * 		(0.01875 * SafezoneH)";
			h = "40 * 		(0.025 * SafezoneH)";
			class controls
			{
				class RangeText: RscText
				{
					style = 0;
					sizeEx = "0.02*SafezoneH";
					shadow = 0;
					font = "EtelkaMonospacePro";
					idc = 1000;
					text = "RANGE:";
					x = "26.6 * 		(0.01875 * SafezoneH)";
					y = "28.8 * 		(0.025 * SafezoneH)";
					w = "3 * 		(0.01875 * SafezoneH)";
					h = "1.2 * 		(0.025 * SafezoneH)";
				};
				class CA_Distance: RangeText
				{
					idc = 151;
					text = "2456";
					x = "29.4 * 		(0.01875 * SafezoneH)";
					y = "28.8 * 		(0.025 * SafezoneH)";
					w = "4 * 		(0.01875 * SafezoneH)";
					h = "1.2 * 		(0.025 * SafezoneH)";
				};
				class ModeText: RangeText
				{
					idc = 1002;
					text = "MODE:";
					x = "26.6 * 		(0.01875 * SafezoneH)";
					y = "29.6 * 		(0.025 * SafezoneH)";
					w = "3 * 		(0.01875 * SafezoneH)";
					h = "1.2 * 		(0.025 * SafezoneH)";
				};
				class CA_VisionMode: RangeText
				{
					idc = 179;
					style = 0;
					text = "VIS";
					x = "29.4 * 		(0.01875 * SafezoneH)";
					y = "29.6 * 		(0.025 * SafezoneH)";
					w = "4 * 		(0.01875 * SafezoneH)";
					h = "1.2 * 		(0.025 * SafezoneH)";
				};
				class CA_FlirMode: RangeText
				{
					idc = 153;
					style = 0;
					text = "BHOT";
					x = "30.6 * 		(0.01875 * SafezoneH)";
					y = "29.6 * 		(0.025 * SafezoneH)";
					w = "4.5 * 		(0.01875 * SafezoneH)";
					h = "1.2 * 		(0.025 * SafezoneH)";
				};
				class TextGrid: RangeText
				{
					idc = 1005;
					text = "GRID:";
					x = "5.8 * 		(0.01875 * SafezoneH)";
					y = "31.8 * 		(0.025 * SafezoneH)";
					w = "5 * 		(0.01875 * SafezoneH)";
					h = "1 * 		(0.025 * SafezoneH)";
				};
				class ValueGrid: RangeText
				{
					idc = 171;
					text = "382546";
					x = "10.3 * 		(0.01875 * SafezoneH)";
					y = "31.8 * 		(0.025 * SafezoneH)";
					w = "6 * 		(0.01875 * SafezoneH)";
					h = "1 * 		(0.025 * SafezoneH)";
				};
				class TextTime: RangeText
				{
					idc = 1010;
					text = "TIME [UTC]:";
					x = "5.8 * 		(0.01875 * SafezoneH)";
					y = "32.6 * 		(0.025 * SafezoneH)";
					w = "5 * 		(0.01875 * SafezoneH)";
					h = "1 * 		(0.025 * SafezoneH)";
				};
				class ValueTime: RangeText
				{
					idc = 190;
					text = "20:28:35";
					x = "10 * 		(0.01875 * SafezoneH)";
					y = "32.6 * 		(0.025 * SafezoneH)";
					w = "6 * 		(0.01875 * SafezoneH)";
					h = "1 * 		(0.025 * SafezoneH)";
				};
				class TextMag: RangeText
				{
					idc = 1011;
					text = "CAM MAG:";
					x = "5.8 * 		(0.01875 * SafezoneH)";
					y = "7 * 		(0.025 * SafezoneH)";
					w = "5 * 		(0.01875 * SafezoneH)";
					h = "1.2 * 		(0.025 * SafezoneH)";
				};
				class CA_OpticsZoom: RangeText
				{
					idc = 180;
					text = "28x";
					x = "10.3 * 		(0.01875 * SafezoneH)";
					y = "7 * 		(0.025 * SafezoneH)";
					w = "6 * 		(0.01875 * SafezoneH)";
					h = "1.2 * 		(0.025 * SafezoneH)";
				};
			};
		};
	};
	class RscOptics_APC_Tracked_01_gunner: RscUnitInfo
	{
		idd = 300;
		controls[] = {"CA_Zeroing","CA_IGUI_elements_group","CA_APC_WFOV_mode_group","CA_APC_NFOV_mode_group"};
		class CA_IGUI_elements_group: RscControlsGroup
		{
			idc = 170;
			class VScrollbar: VScrollbar
			{
				width = 0;
			};
			class HScrollbar: HScrollbar
			{
				height = 0;
			};
			x = "-4 * 		(0.01875 * SafezoneH) + 			(safezoneX)";
			y = "0 * 		(0.025 * SafezoneH) + 		(SafezoneY)";
			w = "61.5 * 		(0.01875 * SafezoneH)";
			h = "40 * 		(0.025 * SafezoneH)";
			class controls
			{
				class TextDist: RscText
				{
					shadow = 0;
					font = "EtelkaMonospacePro";
					sizeEx = "0.028*SafezoneH";
					idc = 1003;
					text = "DIST";
					x = "5.4 * 		(0.01875 * SafezoneH)";
					y = "19 * 		(0.025 * SafezoneH)";
					w = "5 * 		(0.01875 * SafezoneH)";
					h = "1 * 		(0.025 * SafezoneH)";
					colorBackground[] = {0,0,0,1};
				};
				class CA_Distance: RscText
				{
					idc = 151;
					style = 0;
					sizeEx = "0.028*SafezoneH";
					shadow = 0;
					font = "EtelkaMonospacePro";
					text = "2456";
					x = "10.1 * 		(0.01875 * SafezoneH)";
					y = "19 * 		(0.025 * SafezoneH)";
					w = "4 * 		(0.01875 * SafezoneH)";
					h = "1 * 		(0.025 * SafezoneH)";
					colorBackground[] = {0,0,0,1};
				};
				class TextColonDist: RscText
				{
					shadow = 0;
					font = "EtelkaMonospacePro";
					sizeEx = "0.028*SafezoneH";
					idc = 1008;
					text = ":";
					x = "9.3 * 		(0.01875 * SafezoneH)";
					y = "19 * 		(0.025 * SafezoneH)";
					w = "1 * 		(0.01875 * SafezoneH)";
					h = "1 * 		(0.025 * SafezoneH)";
					colorBackground[] = {0,0,0,1};
				};
				class TextEL: RscText
				{
					shadow = 0;
					font = "EtelkaMonospacePro";
					sizeEx = "0.028*SafezoneH";
					idc = 1010;
					text = "EL";
					x = "5.4 * 		(0.01875 * SafezoneH)";
					y = "20 * 		(0.025 * SafezoneH)";
					w = "5 * 		(0.01875 * SafezoneH)";
					h = "1 * 		(0.025 * SafezoneH)";
					colorBackground[] = {0,0,0,1};
				};
				class CA_OpticsPitch: RscText
				{
					idc = 182;
					style = 0;
					sizeEx = "0.028*SafezoneH";
					shadow = 0;
					font = "EtelkaMonospacePro";
					text = "36";
					x = "10.1 * 		(0.01875 * SafezoneH)";
					y = "20 * 		(0.025 * SafezoneH)";
					w = "4 * 		(0.01875 * SafezoneH)";
					h = "1 * 		(0.025 * SafezoneH)";
					colorBackground[] = {0,0,0,1};
				};
				class TextColonEL: RscText
				{
					shadow = 0;
					font = "EtelkaMonospacePro";
					sizeEx = "0.028*SafezoneH";
					idc = 1009;
					text = ":";
					x = "9.3 * 		(0.01875 * SafezoneH)";
					y = "20 * 		(0.025 * SafezoneH)";
					w = "1 * 		(0.01875 * SafezoneH)";
					h = "1 * 		(0.025 * SafezoneH)";
					colorBackground[] = {0,0,0,1};
				};
				class TextRadar: RscText
				{
					shadow = 0;
					font = "EtelkaMonospacePro";
					sizeEx = "0.028*SafezoneH";
					idc = 1011;
					text = "RADAR";
					x = "5.4 * 		(0.01875 * SafezoneH)";
					y = "20.98 * 		(0.025 * SafezoneH)";
					w = "4.5 * 		(0.01875 * SafezoneH)";
					h = "1 * 		(0.025 * SafezoneH)";
					colorBackground[] = {0,0,0,1};
				};
				class TextACQ: RscText
				{
					shadow = 0;
					font = "EtelkaMonospacePro";
					sizeEx = "0.028*SafezoneH";
					idc = 1012;
					text = "ACQ:CENT-Au";
					x = "5.4 * 		(0.01875 * SafezoneH)";
					y = "30 * 		(0.025 * SafezoneH)";
					w = "7.5 * 		(0.01875 * SafezoneH)";
					h = "1 * 		(0.025 * SafezoneH)";
					colorBackground[] = {0,0,0,1};
				};
				class TextCENT: RscText
				{
					shadow = 0;
					font = "EtelkaMonospacePro";
					sizeEx = "0.028*SafezoneH";
					idc = 1014;
					text = "CENT-Wt";
					x = "15.5 * 		(0.01875 * SafezoneH)";
					y = "30 * 		(0.025 * SafezoneH)";
					w = "5 * 		(0.01875 * SafezoneH)";
					h = "1 * 		(0.025 * SafezoneH)";
					colorBackground[] = {0,0,0,1};
				};
				class TextCST: RscText
				{
					shadow = 0;
					font = "EtelkaMonospacePro";
					sizeEx = "0.028*SafezoneH";
					idc = 1013;
					text = "CST:";
					x = "12.9 * 		(0.01875 * SafezoneH)";
					y = "30 * 		(0.025 * SafezoneH)";
					w = "2.8 * 		(0.01875 * SafezoneH)";
					h = "1 * 		(0.025 * SafezoneH)";
					colorText[] = {0,0,0,1};
					colorBackground[] = {1,1,1,1};
				};
			};
		};
		class CA_APC_WFOV_mode_group: RscControlsGroupNoScrollbars
		{
			idc = 163;
			x = "-4 * 		(0.01875 * SafezoneH) + 			(safezoneX)";
			y = "0 * 		(0.025 * SafezoneH) + 		(SafezoneY)";
			w = "61.5 * 		(0.01875 * SafezoneH)";
			h = "40 * 		(0.025 * SafezoneH)";
			class controls
			{
				class CA_FOVModeWFOV: RscText
				{
					shadow = 0;
					font = "EtelkaMonospacePro";
					sizeEx = "0.028*SafezoneH";
					idc = 1002;
					text = "WFOV";
					x = "5.4 * 		(0.01875 * SafezoneH)";
					y = "21.95 * 		(0.025 * SafezoneH)";
					w = "4.5 * 		(0.01875 * SafezoneH)";
					h = "1 * 		(0.025 * SafezoneH)";
					colorBackground[] = {0,0,0,1};
				};
			};
		};
		class CA_APC_NFOV_mode_group: RscControlsGroupNoScrollbars
		{
			idc = 162;
			x = "-4 * 		(0.01875 * SafezoneH) + 			(safezoneX)";
			y = "0 * 		(0.025 * SafezoneH) + 		(SafezoneY)";
			w = "61.5 * 		(0.01875 * SafezoneH)";
			h = "40 * 		(0.025 * SafezoneH)";
			class controls
			{
				class CA_FOVModeNFOV: RscText
				{
					shadow = 0;
					font = "EtelkaMonospacePro";
					sizeEx = "0.028*SafezoneH";
					idc = 1007;
					text = "NFOV";
					x = "5.4 * 		(0.01875 * SafezoneH)";
					y = "21.95 * 		(0.025 * SafezoneH)";
					w = "4.5 * 		(0.01875 * SafezoneH)";
					h = "1 * 		(0.025 * SafezoneH)";
					colorBackground[] = {0,0,0,1};
				};
			};
		};
	};
	class RscOptics_APC_Tracked_03_gunner: RscUnitInfo
	{
		idd = 300;
		controls[] = {"CA_Zeroing","CA_IGUI_elements_group","CA_APC_WFOV_mode_group","CA_APC_NFOV_mode_group"};
		class CA_IGUI_elements_group: RscControlsGroup
		{
			idc = 170;
			class VScrollbar: VScrollbar
			{
				width = 0;
			};
			class HScrollbar: HScrollbar
			{
				height = 0;
			};
			x = "0 * 		(0.01875 * SafezoneH) + 		(SafezoneX + ((SafezoneW - SafezoneH) / 2))";
			y = "0 * 		(0.025 * SafezoneH) + 		(SafezoneY)";
			w = "53.5 * 		(0.01875 * SafezoneH)";
			h = "40 * 		(0.025 * SafezoneH)";
			class controls
			{
				class CA_OpticsPitch: RscText
				{
					idc = 182;
					style = 1;
					sizeEx = "0.038*SafezoneH";
					shadow = 0;
					font = "EtelkaMonospacePro";
					text = "36";
					x = "1 * 		(0.01875 * SafezoneH)";
					y = "19.3 * 		(0.025 * SafezoneH)";
					w = "5.2 * 		(0.01875 * SafezoneH)";
					h = "1.2 * 		(0.025 * SafezoneH)";
				};
				class CA_Distance: RscText
				{
					idc = 151;
					style = 2;
					sizeEx = "0.038*SafezoneH";
					shadow = 0;
					font = "EtelkaMonospacePro";
					text = "2456";
					x = "24.3 * 		(0.01875 * SafezoneH)";
					y = "31.3 * 		(0.025 * SafezoneH)";
					w = "5 * 		(0.01875 * SafezoneH)";
					h = "1.2 * 		(0.025 * SafezoneH)";
				};
				class CA_VisionMode: RscText
				{
					idc = 152;
					style = 0;
					sizeEx = "0.038*SafezoneH";
					shadow = 0;
					font = "EtelkaMonospacePro";
					text = "FLIR";
					x = "40.2 * 		(0.01875 * SafezoneH)";
					y = "11 * 		(0.025 * SafezoneH)";
					w = "4.5 * 		(0.01875 * SafezoneH)";
					h = "1.2 * 		(0.025 * SafezoneH)";
				};
				class CA_FlirMode: RscText
				{
					idc = 153;
					style = 0;
					sizeEx = "0.038*SafezoneH";
					shadow = 0;
					font = "EtelkaMonospacePro";
					text = "BHOT";
					x = "44.2 * 		(0.01875 * SafezoneH)";
					y = "11 * 		(0.025 * SafezoneH)";
					w = "4.5 * 		(0.01875 * SafezoneH)";
					h = "1.2 * 		(0.025 * SafezoneH)";
				};
			};
		};
		class CA_APC_WFOV_mode_group: RscControlsGroupNoScrollbars
		{
			idc = 163;
			x = "0 * 		(0.01875 * SafezoneH) + 		(SafezoneX + ((SafezoneW - SafezoneH) / 2))";
			y = "0 * 		(0.025 * SafezoneH) + 		(SafezoneY)";
			w = "53.5 * 		(0.01875 * SafezoneH)";
			h = "40 * 		(0.025 * SafezoneH)";
			class controls
			{
				class CA_FOVModeWFOV: RscText
				{
					shadow = 0;
					font = "EtelkaMonospacePro";
					sizeEx = "0.038*SafezoneH";
					idc = 1002;
					text = "WFOV";
					x = "8 * 		(0.01875 * SafezoneH)";
					y = "11 * 		(0.025 * SafezoneH)";
					w = "5 * 		(0.01875 * SafezoneH)";
					h = "1.2 * 		(0.025 * SafezoneH)";
				};
			};
		};
		class CA_APC_NFOV_mode_group: RscControlsGroupNoScrollbars
		{
			idc = 162;
			x = "0 * 		(0.01875 * SafezoneH) + 		(SafezoneX + ((SafezoneW - SafezoneH) / 2))";
			y = "0 * 		(0.025 * SafezoneH) + 		(SafezoneY)";
			w = "53.5 * 		(0.01875 * SafezoneH)";
			h = "40 * 		(0.025 * SafezoneH)";
			class controls
			{
				class CA_FOVModeNFOV: RscText
				{
					shadow = 0;
					font = "EtelkaMonospacePro";
					sizeEx = "0.038*SafezoneH";
					idc = 1007;
					text = "NFOV";
					x = "8 * 		(0.01875 * SafezoneH)";
					y = "11 * 		(0.025 * SafezoneH)";
					w = "5 * 		(0.01875 * SafezoneH)";
					h = "1.2 * 		(0.025 * SafezoneH)";
				};
			};
		};
	};
	class RscOptics_APC_Wheeled_01_gunner: RscUnitInfo
	{
		idd = 300;
		controls[] = {"CA_Zeroing","CA_IGUI_elements_group","CA_APC_WFOV_mode_group","CA_APC_NFOV_mode_group"};
		class CA_IGUI_elements_group: RscControlsGroup
		{
			idc = 170;
			class VScrollbar: VScrollbar
			{
				width = 0;
			};
			class HScrollbar: HScrollbar
			{
				height = 0;
			};
			x = "0 * 		(0.01875 * SafezoneH) + 		(SafezoneX + ((SafezoneW - SafezoneH) / 2))";
			y = "0 * 		(0.025 * SafezoneH) + 		(SafezoneY)";
			w = "53.5 * 		(0.01875 * SafezoneH)";
			h = "40 * 		(0.025 * SafezoneH)";
			class controls
			{
				class CA_OpticsPitch: RscText
				{
					idc = 182;
					style = 1;
					colorText[] = {0.706,0.0745,0.0196,1};
					sizeEx = "0.038*SafezoneH";
					shadow = 0;
					font = "EtelkaMonospacePro";
					text = "36";
					x = "1 * 		(0.01875 * SafezoneH)";
					y = "19.3 * 		(0.025 * SafezoneH)";
					w = "5.2 * 		(0.01875 * SafezoneH)";
					h = "1.2 * 		(0.025 * SafezoneH)";
				};
				class CA_Distance: RscText
				{
					idc = 151;
					style = 2;
					sizeEx = "0.038*SafezoneH";
					colorText[] = {0.706,0.0745,0.0196,1};
					shadow = 0;
					font = "EtelkaMonospacePro";
					text = "2456";
					x = "24.3 * 		(0.01875 * SafezoneH)";
					y = "31.3 * 		(0.025 * SafezoneH)";
					w = "5 * 		(0.01875 * SafezoneH)";
					h = "1.2 * 		(0.025 * SafezoneH)";
				};
				class CA_VisionMode: RscText
				{
					idc = 152;
					style = 0;
					sizeEx = "0.038*SafezoneH";
					colorText[] = {0.706,0.0745,0.0196,1};
					shadow = 0;
					font = "EtelkaMonospacePro";
					text = "FLIR";
					x = "40.2 * 		(0.01875 * SafezoneH)";
					y = "11 * 		(0.025 * SafezoneH)";
					w = "4.5 * 		(0.01875 * SafezoneH)";
					h = "1.2 * 		(0.025 * SafezoneH)";
				};
				class CA_FlirMode: RscText
				{
					idc = 153;
					style = 0;
					sizeEx = "0.038*SafezoneH";
					colorText[] = {0.706,0.0745,0.0196,1};
					shadow = 0;
					font = "EtelkaMonospacePro";
					text = "BHOT";
					x = "44.2 * 		(0.01875 * SafezoneH)";
					y = "11 * 		(0.025 * SafezoneH)";
					w = "4.5 * 		(0.01875 * SafezoneH)";
					h = "1.2 * 		(0.025 * SafezoneH)";
				};
			};
		};
		class CA_APC_WFOV_mode_group: RscControlsGroupNoScrollbars
		{
			idc = 163;
			x = "0 * 		(0.01875 * SafezoneH) + 		(SafezoneX + ((SafezoneW - SafezoneH) / 2))";
			y = "0 * 		(0.025 * SafezoneH) + 		(SafezoneY)";
			w = "53.5 * 		(0.01875 * SafezoneH)";
			h = "40 * 		(0.025 * SafezoneH)";
			class controls
			{
				class CA_FOVModeWFOV: RscText
				{
					colorText[] = {0.706,0.0745,0.0196,1};
					shadow = 0;
					font = "EtelkaMonospacePro";
					sizeEx = "0.038*SafezoneH";
					idc = 1002;
					text = "WFOV";
					x = "8 * 		(0.01875 * SafezoneH)";
					y = "11 * 		(0.025 * SafezoneH)";
					w = "5 * 		(0.01875 * SafezoneH)";
					h = "1.2 * 		(0.025 * SafezoneH)";
				};
			};
		};
		class CA_APC_NFOV_mode_group: RscControlsGroupNoScrollbars
		{
			idc = 162;
			x = "0 * 		(0.01875 * SafezoneH) + 		(SafezoneX + ((SafezoneW - SafezoneH) / 2))";
			y = "0 * 		(0.025 * SafezoneH) + 		(SafezoneY)";
			w = "53.5 * 		(0.01875 * SafezoneH)";
			h = "40 * 		(0.025 * SafezoneH)";
			class controls
			{
				class CA_FOVModeNFOV: RscText
				{
					colorText[] = {0.706,0.0745,0.0196,1};
					shadow = 0;
					font = "EtelkaMonospacePro";
					sizeEx = "0.038*SafezoneH";
					idc = 1007;
					text = "NFOV";
					x = "8 * 		(0.01875 * SafezoneH)";
					y = "11 * 		(0.025 * SafezoneH)";
					w = "5 * 		(0.01875 * SafezoneH)";
					h = "1.2 * 		(0.025 * SafezoneH)";
				};
			};
		};
	};
	class RscOptics_APC_Wheeled_03_commander: RscUnitInfo
	{
		idd = 300;
		controls[] = {"CA_Zeroing","CA_IGUI_elements_group","CA_APC_WFOV_mode_group","CA_APC_NFOV_mode_group"};
		class CA_IGUI_elements_group: RscControlsGroup
		{
			idc = 170;
			class VScrollbar: VScrollbar
			{
				width = 0;
			};
			class HScrollbar: HScrollbar
			{
				height = 0;
			};
			x = "0 * 		(0.01875 * SafezoneH) + 		(SafezoneX + ((SafezoneW - SafezoneH) / 2))";
			y = "0 * 		(0.025 * SafezoneH) + 		(SafezoneY)";
			w = "53.5 * 		(0.01875 * SafezoneH)";
			h = "40 * 		(0.025 * SafezoneH)";
			class controls
			{
				class TextOpticsPitch: RscText
				{
					style = 0;
					sizeEx = "0.032*SafezoneH";
					shadow = 0;
					font = "EtelkaMonospacePro";
					idc = 1008;
					text = "E:";
					x = "7.8 * 		(0.01875 * SafezoneH)";
					y = "9.6 * 		(0.025 * SafezoneH)";
					w = "2 * 		(0.01875 * SafezoneH)";
					h = "1.2 * 		(0.025 * SafezoneH)";
				};
				class CA_OpticsPitch: RscText
				{
					idc = 182;
					style = 0;
					sizeEx = "0.032*SafezoneH";
					shadow = 0;
					font = "EtelkaMonospacePro";
					text = "36";
					x = "9 * 		(0.01875 * SafezoneH)";
					y = "9.6 * 		(0.025 * SafezoneH)";
					w = "5.2 * 		(0.01875 * SafezoneH)";
					h = "1.2 * 		(0.025 * SafezoneH)";
				};
				class CA_Distance: RscText
				{
					idc = 151;
					style = 0;
					sizeEx = "0.032*SafezoneH";
					shadow = 0;
					font = "EtelkaMonospacePro";
					text = "2456";
					x = "40.4 * 		(0.01875 * SafezoneH)";
					y = "9.6 * 		(0.025 * SafezoneH)";
					w = "5 * 		(0.01875 * SafezoneH)";
					h = "1.2 * 		(0.025 * SafezoneH)";
				};
				class CA_VisionMode: RscText
				{
					idc = 152;
					style = 0;
					sizeEx = "0.032*SafezoneH";
					shadow = 0;
					font = "EtelkaMonospacePro";
					text = "FLIR";
					x = "44 * 		(0.01875 * SafezoneH)";
					y = "29.2 * 		(0.025 * SafezoneH)";
					w = "4.5 * 		(0.01875 * SafezoneH)";
					h = "1.2 * 		(0.025 * SafezoneH)";
				};
				class CA_FlirMode: RscText
				{
					idc = 153;
					style = 0;
					sizeEx = "0.032*SafezoneH";
					shadow = 0;
					font = "EtelkaMonospacePro";
					text = "BHOT";
					x = "47.5 * 		(0.01875 * SafezoneH)";
					y = "29.2 * 		(0.025 * SafezoneH)";
					w = "4.5 * 		(0.01875 * SafezoneH)";
					h = "1.2 * 		(0.025 * SafezoneH)";
				};
			};
		};
		class CA_APC_WFOV_mode_group: RscControlsGroupNoScrollbars
		{
			idc = 163;
			x = "0 * 		(0.01875 * SafezoneH) + 		(SafezoneX + ((SafezoneW - SafezoneH) / 2))";
			y = "0 * 		(0.025 * SafezoneH) + 		(SafezoneY)";
			w = "53.5 * 		(0.01875 * SafezoneH)";
			h = "40 * 		(0.025 * SafezoneH)";
			class controls
			{
				class CA_FOVModeWFOV: RscText
				{
					shadow = 0;
					font = "EtelkaMonospacePro";
					sizeEx = "0.032*SafezoneH";
					idc = 1002;
					text = "WFOV";
					x = "40.4 * 		(0.01875 * SafezoneH)";
					y = "29.2 * 		(0.025 * SafezoneH)";
					w = "5 * 		(0.01875 * SafezoneH)";
					h = "1.2 * 		(0.025 * SafezoneH)";
				};
			};
		};
		class CA_APC_NFOV_mode_group: RscControlsGroupNoScrollbars
		{
			idc = 162;
			x = "0 * 		(0.01875 * SafezoneH) + 		(SafezoneX + ((SafezoneW - SafezoneH) / 2))";
			y = "0 * 		(0.025 * SafezoneH) + 		(SafezoneY)";
			w = "53.5 * 		(0.01875 * SafezoneH)";
			h = "40 * 		(0.025 * SafezoneH)";
			class controls
			{
				class CA_FOVModeNFOV: RscText
				{
					shadow = 0;
					font = "EtelkaMonospacePro";
					sizeEx = "0.032*SafezoneH";
					idc = 1007;
					text = "NFOV";
					x = "40.4 * 		(0.01875 * SafezoneH)";
					y = "29.2 * 		(0.025 * SafezoneH)";
					w = "5 * 		(0.01875 * SafezoneH)";
					h = "1.2 * 		(0.025 * SafezoneH)";
				};
			};
		};
	};
	class RscOptics_APC_Wheeled_03_gunner: RscUnitInfo
	{
		idd = 300;
		controls[] = {"CA_Zeroing","CA_IGUI_elements_group","CA_APC_WFOV_mode_group","CA_APC_NFOV_mode_group"};
		class CA_IGUI_elements_group: RscControlsGroup
		{
			idc = 170;
			class VScrollbar: VScrollbar
			{
				width = 0;
			};
			class HScrollbar: HScrollbar
			{
				height = 0;
			};
			x = "0 * 		(0.01875 * SafezoneH) + 		(SafezoneX + ((SafezoneW - SafezoneH) / 2))";
			y = "0 * 		(0.025 * SafezoneH) + 		(SafezoneY)";
			w = "53.5 * 		(0.01875 * SafezoneH)";
			h = "40 * 		(0.025 * SafezoneH)";
			class controls
			{
				class TextOpticsPitch: RscText
				{
					style = 0;
					sizeEx = "0.032*SafezoneH";
					shadow = 0;
					font = "EtelkaMonospacePro";
					idc = 1008;
					text = "E:";
					x = "7.8 * 		(0.01875 * SafezoneH)";
					y = "9.6 * 		(0.025 * SafezoneH)";
					w = "2 * 		(0.01875 * SafezoneH)";
					h = "1.2 * 		(0.025 * SafezoneH)";
				};
				class CA_OpticsPitch: RscText
				{
					idc = 182;
					style = 0;
					sizeEx = "0.032*SafezoneH";
					shadow = 0;
					font = "EtelkaMonospacePro";
					text = "36";
					x = "9 * 		(0.01875 * SafezoneH)";
					y = "9.6 * 		(0.025 * SafezoneH)";
					w = "5.2 * 		(0.01875 * SafezoneH)";
					h = "1.2 * 		(0.025 * SafezoneH)";
				};
				class CA_Distance: RscText
				{
					idc = 151;
					style = 0;
					sizeEx = "0.032*SafezoneH";
					shadow = 0;
					font = "EtelkaMonospacePro";
					text = "2456";
					x = "40.4 * 		(0.01875 * SafezoneH)";
					y = "9.6 * 		(0.025 * SafezoneH)";
					w = "5 * 		(0.01875 * SafezoneH)";
					h = "1.2 * 		(0.025 * SafezoneH)";
				};
				class CA_VisionMode: RscText
				{
					idc = 152;
					style = 0;
					sizeEx = "0.032*SafezoneH";
					shadow = 0;
					font = "EtelkaMonospacePro";
					text = "FLIR";
					x = "44 * 		(0.01875 * SafezoneH)";
					y = "29.2 * 		(0.025 * SafezoneH)";
					w = "4.5 * 		(0.01875 * SafezoneH)";
					h = "1.2 * 		(0.025 * SafezoneH)";
				};
				class CA_FlirMode: RscText
				{
					idc = 153;
					style = 0;
					sizeEx = "0.032*SafezoneH";
					shadow = 0;
					font = "EtelkaMonospacePro";
					text = "BHOT";
					x = "47.5 * 		(0.01875 * SafezoneH)";
					y = "29.2 * 		(0.025 * SafezoneH)";
					w = "4.5 * 		(0.01875 * SafezoneH)";
					h = "1.2 * 		(0.025 * SafezoneH)";
				};
			};
		};
		class CA_APC_WFOV_mode_group: RscControlsGroupNoScrollbars
		{
			idc = 163;
			x = "0 * 		(0.01875 * SafezoneH) + 		(SafezoneX + ((SafezoneW - SafezoneH) / 2))";
			y = "0 * 		(0.025 * SafezoneH) + 		(SafezoneY)";
			w = "53.5 * 		(0.01875 * SafezoneH)";
			h = "40 * 		(0.025 * SafezoneH)";
			class controls
			{
				class CA_FOVModeWFOV: RscText
				{
					shadow = 0;
					font = "EtelkaMonospacePro";
					sizeEx = "0.032*SafezoneH";
					idc = 1002;
					text = "WFOV";
					x = "40.4 * 		(0.01875 * SafezoneH)";
					y = "29.2 * 		(0.025 * SafezoneH)";
					w = "5 * 		(0.01875 * SafezoneH)";
					h = "1.2 * 		(0.025 * SafezoneH)";
				};
			};
		};
		class CA_APC_NFOV_mode_group: RscControlsGroupNoScrollbars
		{
			idc = 162;
			x = "0 * 		(0.01875 * SafezoneH) + 		(SafezoneX + ((SafezoneW - SafezoneH) / 2))";
			y = "0 * 		(0.025 * SafezoneH) + 		(SafezoneY)";
			w = "53.5 * 		(0.01875 * SafezoneH)";
			h = "40 * 		(0.025 * SafezoneH)";
			class controls
			{
				class CA_FOVModeNFOV: RscText
				{
					shadow = 0;
					font = "EtelkaMonospacePro";
					sizeEx = "0.032*SafezoneH";
					idc = 1007;
					text = "NFOV";
					x = "40.4 * 		(0.01875 * SafezoneH)";
					y = "29.2 * 		(0.025 * SafezoneH)";
					w = "5 * 		(0.01875 * SafezoneH)";
					h = "1.2 * 		(0.025 * SafezoneH)";
				};
			};
		};
	};
	class RscOptics_MBT_01_commander: RscUnitInfo
	{
		idd = 300;
		controls[] = {"CA_Zeroing","CA_IGUI_elements_group","CA_APC_WFOV_mode_group","CA_APC_NFOV_mode_group"};
		class CA_IGUI_elements_group: RscControlsGroup
		{
			idc = 170;
			class VScrollbar: VScrollbar
			{
				width = 0;
			};
			class HScrollbar: HScrollbar
			{
				height = 0;
			};
			x = "0 * 		(0.01875 * SafezoneH) + 		(SafezoneX + ((SafezoneW - SafezoneH) / 2))";
			y = "0 * 		(0.025 * SafezoneH) + 		(SafezoneY)";
			w = "53.5 * 		(0.01875 * SafezoneH)";
			h = "40 * 		(0.025 * SafezoneH)";
			class controls
			{
				class TextOpticsPitch: RscText
				{
					style = 0;
					sizeEx = "0.032*SafezoneH";
					shadow = 0;
					font = "EtelkaMonospacePro";
					colorText[] = {0.709,0.972,0.384,1};
					idc = 1008;
					text = "E:";
					x = "7.8 * 		(0.01875 * SafezoneH)";
					y = "9.6 * 		(0.025 * SafezoneH)";
					w = "2 * 		(0.01875 * SafezoneH)";
					h = "1.2 * 		(0.025 * SafezoneH)";
				};
				class CA_OpticsPitch: RscText
				{
					idc = 182;
					style = 0;
					sizeEx = "0.032*SafezoneH";
					shadow = 0;
					font = "EtelkaMonospacePro";
					colorText[] = {0.709,0.972,0.384,1};
					text = "36";
					x = "9 * 		(0.01875 * SafezoneH)";
					y = "9.6 * 		(0.025 * SafezoneH)";
					w = "5.2 * 		(0.01875 * SafezoneH)";
					h = "1.2 * 		(0.025 * SafezoneH)";
				};
				class CA_Distance: RscText
				{
					idc = 151;
					style = 0;
					sizeEx = "0.032*SafezoneH";
					shadow = 0;
					font = "EtelkaMonospacePro";
					colorText[] = {0.709,0.972,0.384,1};
					text = "2456";
					x = "40.4 * 		(0.01875 * SafezoneH)";
					y = "9.6 * 		(0.025 * SafezoneH)";
					w = "5 * 		(0.01875 * SafezoneH)";
					h = "1.2 * 		(0.025 * SafezoneH)";
				};
				class CA_VisionMode: RscText
				{
					idc = 152;
					style = 0;
					sizeEx = "0.032*SafezoneH";
					shadow = 0;
					font = "EtelkaMonospacePro";
					colorText[] = {0.709,0.972,0.384,1};
					text = "FLIR";
					x = "44 * 		(0.01875 * SafezoneH)";
					y = "29.2 * 		(0.025 * SafezoneH)";
					w = "4.5 * 		(0.01875 * SafezoneH)";
					h = "1.2 * 		(0.025 * SafezoneH)";
				};
				class CA_FlirMode: RscText
				{
					idc = 153;
					style = 0;
					sizeEx = "0.032*SafezoneH";
					shadow = 0;
					font = "EtelkaMonospacePro";
					colorText[] = {0.709,0.972,0.384,1};
					text = "BHOT";
					x = "47.5 * 		(0.01875 * SafezoneH)";
					y = "29.2 * 		(0.025 * SafezoneH)";
					w = "4.5 * 		(0.01875 * SafezoneH)";
					h = "1.2 * 		(0.025 * SafezoneH)";
				};
			};
		};
		class CA_APC_WFOV_mode_group: RscControlsGroupNoScrollbars
		{
			idc = 163;
			x = "0 * 		(0.01875 * SafezoneH) + 		(SafezoneX + ((SafezoneW - SafezoneH) / 2))";
			y = "0 * 		(0.025 * SafezoneH) + 		(SafezoneY)";
			w = "53.5 * 		(0.01875 * SafezoneH)";
			h = "40 * 		(0.025 * SafezoneH)";
			class controls
			{
				class CA_FOVModeWFOV: RscText
				{
					shadow = 0;
					font = "EtelkaMonospacePro";
					colorText[] = {0.709,0.972,0.384,1};
					sizeEx = "0.032*SafezoneH";
					idc = 1002;
					text = "WFOV";
					x = "40.4 * 		(0.01875 * SafezoneH)";
					y = "29.2 * 		(0.025 * SafezoneH)";
					w = "5 * 		(0.01875 * SafezoneH)";
					h = "1.2 * 		(0.025 * SafezoneH)";
				};
			};
		};
		class CA_APC_NFOV_mode_group: RscControlsGroupNoScrollbars
		{
			idc = 162;
			x = "0 * 		(0.01875 * SafezoneH) + 		(SafezoneX + ((SafezoneW - SafezoneH) / 2))";
			y = "0 * 		(0.025 * SafezoneH) + 		(SafezoneY)";
			w = "53.5 * 		(0.01875 * SafezoneH)";
			h = "40 * 		(0.025 * SafezoneH)";
			class controls
			{
				class CA_FOVModeNFOV: RscText
				{
					shadow = 0;
					font = "EtelkaMonospacePro";
					colorText[] = {0.709,0.972,0.384,1};
					sizeEx = "0.032*SafezoneH";
					idc = 1007;
					text = "NFOV";
					x = "40.4 * 		(0.01875 * SafezoneH)";
					y = "29.2 * 		(0.025 * SafezoneH)";
					w = "5 * 		(0.01875 * SafezoneH)";
					h = "1.2 * 		(0.025 * SafezoneH)";
				};
			};
		};
	};
	class RscOptics_MBT_01_gunner: RscUnitInfo
	{
		idd = 300;
		controls[] = {"CA_Zeroing","CA_IGUI_elements_group","CA_APC_WFOV_mode_group","CA_APC_NFOV_mode_group"};
		class CA_IGUI_elements_group: RscControlsGroup
		{
			idc = 170;
			class VScrollbar: VScrollbar
			{
				width = 0;
			};
			class HScrollbar: HScrollbar
			{
				height = 0;
			};
			x = "0 * 		(0.01875 * SafezoneH) + 		(SafezoneX + ((SafezoneW - SafezoneH) / 2))";
			y = "0 * 		(0.025 * SafezoneH) + 		(SafezoneY)";
			w = "53.5 * 		(0.01875 * SafezoneH)";
			h = "40 * 		(0.025 * SafezoneH)";
			class controls
			{
				class TextOpticsPitch: RscText
				{
					style = 0;
					sizeEx = "0.032*SafezoneH";
					shadow = 0;
					font = "EtelkaMonospacePro";
					colorText[] = {0.709,0.972,0.384,1};
					idc = 1008;
					text = "E:";
					x = "7.8 * 		(0.01875 * SafezoneH)";
					y = "9.6 * 		(0.025 * SafezoneH)";
					w = "2 * 		(0.01875 * SafezoneH)";
					h = "1.2 * 		(0.025 * SafezoneH)";
				};
				class CA_OpticsPitch: RscText
				{
					idc = 182;
					style = 0;
					sizeEx = "0.032*SafezoneH";
					shadow = 0;
					font = "EtelkaMonospacePro";
					colorText[] = {0.709,0.972,0.384,1};
					text = "36";
					x = "9 * 		(0.01875 * SafezoneH)";
					y = "9.6 * 		(0.025 * SafezoneH)";
					w = "5.2 * 		(0.01875 * SafezoneH)";
					h = "1.2 * 		(0.025 * SafezoneH)";
				};
				class CA_Distance: RscText
				{
					idc = 151;
					style = 0;
					sizeEx = "0.032*SafezoneH";
					shadow = 0;
					font = "EtelkaMonospacePro";
					colorText[] = {0.709,0.972,0.384,1};
					text = "2456";
					x = "40.4 * 		(0.01875 * SafezoneH)";
					y = "9.6 * 		(0.025 * SafezoneH)";
					w = "5 * 		(0.01875 * SafezoneH)";
					h = "1.2 * 		(0.025 * SafezoneH)";
				};
				class CA_VisionMode: RscText
				{
					idc = 152;
					style = 0;
					sizeEx = "0.032*SafezoneH";
					shadow = 0;
					font = "EtelkaMonospacePro";
					colorText[] = {0.709,0.972,0.384,1};
					text = "FLIR";
					x = "44 * 		(0.01875 * SafezoneH)";
					y = "29.2 * 		(0.025 * SafezoneH)";
					w = "4.5 * 		(0.01875 * SafezoneH)";
					h = "1.2 * 		(0.025 * SafezoneH)";
				};
				class CA_FlirMode: RscText
				{
					idc = 153;
					style = 0;
					sizeEx = "0.032*SafezoneH";
					shadow = 0;
					font = "EtelkaMonospacePro";
					colorText[] = {0.709,0.972,0.384,1};
					text = "BHOT";
					x = "47.5 * 		(0.01875 * SafezoneH)";
					y = "29.2 * 		(0.025 * SafezoneH)";
					w = "4.5 * 		(0.01875 * SafezoneH)";
					h = "1.2 * 		(0.025 * SafezoneH)";
				};
			};
		};
		class CA_APC_WFOV_mode_group: RscControlsGroupNoScrollbars
		{
			idc = 163;
			x = "0 * 		(0.01875 * SafezoneH) + 		(SafezoneX + ((SafezoneW - SafezoneH) / 2))";
			y = "0 * 		(0.025 * SafezoneH) + 		(SafezoneY)";
			w = "53.5 * 		(0.01875 * SafezoneH)";
			h = "40 * 		(0.025 * SafezoneH)";
			class controls
			{
				class CA_FOVModeWFOV: RscText
				{
					shadow = 0;
					font = "EtelkaMonospacePro";
					colorText[] = {0.709,0.972,0.384,1};
					sizeEx = "0.032*SafezoneH";
					idc = 1002;
					text = "WFOV";
					x = "40.4 * 		(0.01875 * SafezoneH)";
					y = "29.2 * 		(0.025 * SafezoneH)";
					w = "5 * 		(0.01875 * SafezoneH)";
					h = "1.2 * 		(0.025 * SafezoneH)";
				};
			};
		};
		class CA_APC_NFOV_mode_group: RscControlsGroupNoScrollbars
		{
			idc = 162;
			x = "0 * 		(0.01875 * SafezoneH) + 		(SafezoneX + ((SafezoneW - SafezoneH) / 2))";
			y = "0 * 		(0.025 * SafezoneH) + 		(SafezoneY)";
			w = "53.5 * 		(0.01875 * SafezoneH)";
			h = "40 * 		(0.025 * SafezoneH)";
			class controls
			{
				class CA_FOVModeNFOV: RscText
				{
					shadow = 0;
					font = "EtelkaMonospacePro";
					colorText[] = {0.709,0.972,0.384,1};
					sizeEx = "0.032*SafezoneH";
					idc = 1007;
					text = "NFOV";
					x = "40.4 * 		(0.01875 * SafezoneH)";
					y = "29.2 * 		(0.025 * SafezoneH)";
					w = "5 * 		(0.01875 * SafezoneH)";
					h = "1.2 * 		(0.025 * SafezoneH)";
				};
			};
		};
	};
	class RscOptics_MBT_02_commander: RscUnitInfo
	{
		idd = 300;
		controls[] = {"CA_Zeroing","CA_IGUI_elements_group"};
		class CA_IGUI_elements_group: RscControlsGroup
		{
			idc = 170;
			class VScrollbar: VScrollbar
			{
				width = 0;
			};
			class HScrollbar: HScrollbar
			{
				height = 0;
			};
			x = "0 * 		(0.01875 * SafezoneH) + 		(SafezoneX + ((SafezoneW - SafezoneH) / 2))";
			y = "0 * 		(0.025 * SafezoneH) + 		(SafezoneY)";
			w = "53.5 * 		(0.01875 * SafezoneH)";
			h = "40 * 		(0.025 * SafezoneH)";
			class controls
			{
				class CA_Distance: RscText
				{
					idc = 151;
					style = 2;
					sizeEx = "0.038*SafezoneH";
					shadow = 0;
					font = "EtelkaMonospacePro";
					text = "2456";
					x = "24.3 * 		(0.01875 * SafezoneH)";
					y = "31 * 		(0.025 * SafezoneH)";
					w = "5 * 		(0.01875 * SafezoneH)";
					h = "1.2 * 		(0.025 * SafezoneH)";
				};
			};
		};
	};
	class RscOptics_MBT_02_gunner: RscUnitInfo
	{
		idd = 300;
		controls[] = {"CA_Zeroing","CA_IGUI_elements_group"};
		class CA_IGUI_elements_group: RscControlsGroup
		{
			idc = 170;
			class VScrollbar: VScrollbar
			{
				width = 0;
			};
			class HScrollbar: HScrollbar
			{
				height = 0;
			};
			x = "0 * 		(0.01875 * SafezoneH) + 		(SafezoneX + ((SafezoneW - SafezoneH) / 2))";
			y = "0 * 		(0.025 * SafezoneH) + 		(SafezoneY)";
			w = "53.5 * 		(0.01875 * SafezoneH)";
			h = "40 * 		(0.025 * SafezoneH)";
			class controls
			{
				class CA_Distance: RscText
				{
					idc = 151;
					style = 2;
					sizeEx = "0.038*SafezoneH";
					shadow = 0;
					font = "EtelkaMonospacePro";
					text = "2456";
					x = "24.3 * 		(0.01875 * SafezoneH)";
					y = "31 * 		(0.025 * SafezoneH)";
					w = "5 * 		(0.01875 * SafezoneH)";
					h = "1.2 * 		(0.025 * SafezoneH)";
				};
			};
		};
	};
	class RscOptics_MBT_03_gunner: RscUnitInfo
	{
		idd = 300;
		controls[] = {"CA_Zeroing","CA_IGUI_elements_group"};
		class CA_IGUI_elements_group: RscControlsGroup
		{
			idc = 170;
			class VScrollbar: VScrollbar
			{
				width = 0;
			};
			class HScrollbar: HScrollbar
			{
				height = 0;
			};
			x = "0 * 		(0.01875 * SafezoneH) + 		(SafezoneX + ((SafezoneW - SafezoneH) / 2))";
			y = "0 * 		(0.025 * SafezoneH) + 		(SafezoneY)";
			w = "53.5 * 		(0.01875 * SafezoneH)";
			h = "40 * 		(0.025 * SafezoneH)";
			class controls
			{
				class CA_OpticsPitch: RscText
				{
					idc = 182;
					style = 1;
					sizeEx = "0.038*SafezoneH";
					shadow = 0;
					font = "EtelkaMonospacePro";
					text = "36";
					x = "1 * 		(0.01875 * SafezoneH)";
					y = "19.4 * 		(0.025 * SafezoneH)";
					w = "5.2 * 		(0.01875 * SafezoneH)";
					h = "1.1 * 		(0.025 * SafezoneH)";
				};
				class CA_Distance: RscText
				{
					idc = 151;
					style = 2;
					sizeEx = "0.038*SafezoneH";
					colorText[] = {0.706,0.0745,0.0196,1};
					shadow = 0;
					font = "EtelkaMonospacePro";
					text = "2456";
					x = "24.3 * 		(0.01875 * SafezoneH)";
					y = "30 * 		(0.025 * SafezoneH)";
					w = "5 * 		(0.01875 * SafezoneH)";
					h = "1.2 * 		(0.025 * SafezoneH)";
				};
			};
		};
	};
	class RscOptics_Offroad_01: RscUnitInfo
	{
		idd = 300;
		controls[] = {"CA_Zeroing"};
	};
	class RscUnitInfoAirRTDBasic: RscUnitInfoAir
	{
		onload = "uinamespace setvariable ['RscUnitInfoAir',_this select 0];";
		controls[] = {};
		controlsx[] = {"WeaponInfoControlsGroupRight","CA_SpeedBackground","CA_TextSpeed","CA_Speed","CA_AltBackground","CA_TextAlt","CA_Alt","CA_HeadingBackground","CA_Heading","CA_ValueColective"};
		class CA_Horizon: CA_HUDRscControlsGroup
		{
			idc = 540;
			x = 0.2;
			y = 0.2;
			w = 0.6;
			h = 0.6;
		};
		class CA_AirSpeedIndicator: CA_HUDRscControlsGroup
		{
			idc = 530;
			x = 0.1;
			y = 0.2;
			w = 0.15;
			h = 0.4;
			class ControlsBackground
			{
				class Bcg: RscText
				{
					x = 0;
					y = 0;
					w = 100;
					h = 100;
					colorbackground[] = {1,0,0,0.5};
				};
			};
			class Controls
			{
				class CA_AirSpeedIndicator_Axis: CA_HUDRscControlsGroup
				{
					idc = 531;
					x = 0.1;
					y = 0.0;
					w = 0.04;
					h = 0.4;
				};
				class CA_RadarAltmeterValue_Value: RscIGUIValue
				{
					idc = 532;
					style = 1;
					x = -0.01;
					y = 0.187;
					w = 0.1;
					shadow = 0;
					SizeEx = 0.035;
				};
				class CA_AltimeterBorder: RscPicture
				{
					x = 0.0;
					y = 0.182;
					w = 0.1;
					h = 0.05;
					colorText[] = {"(profilenamespace getvariable ['IGUI_TEXT_RGB_R',0])","(profilenamespace getvariable ['IGUI_TEXT_RGB_G',1])","(profilenamespace getvariable ['IGUI_TEXT_RGB_B',1])","(profilenamespace getvariable ['IGUI_TEXT_RGB_A',0.8])"};
					text = "\A3\ui_f\data\igui_airspeed_value_ca.paa";
				};
			};
		};
		class CA_Altimeter: CA_HUDRscControlsGroup
		{
			idc = 535;
			x = 0.8;
			y = 0.2;
			w = 0.28;
			h = 0.4;
			class ControlsBackground
			{
				class Bcg: RscText
				{
					x = 0;
					y = 0;
					w = 100;
					h = 100;
					colorbackground[] = {0,1,0,0.5};
				};
			};
			class Controls
			{
				class CA_AirSpeedIndicator_Axis: CA_HUDRscControlsGroup
				{
					idc = 536;
					x = 0.05;
					y = 0.0;
					w = 0.04;
					h = 0.4;
				};
				class CA_RadarAltmeterValue_Value: RscIGUIValue
				{
					idc = 537;
					style = 0;
					x = 0.102;
					y = 0.187;
					w = 0.1;
					shadow = 0;
					sizeEx = 0.035;
				};
				class CA_AltimeterBorder: RscPicture
				{
					x = 0.092;
					y = 0.182;
					w = 0.1;
					h = 0.05;
					colorText[] = {"(profilenamespace getvariable ['IGUI_TEXT_RGB_R',0])","(profilenamespace getvariable ['IGUI_TEXT_RGB_G',1])","(profilenamespace getvariable ['IGUI_TEXT_RGB_B',1])","(profilenamespace getvariable ['IGUI_TEXT_RGB_A',0.8])"};
					text = "\A3\ui_f\data\igui_altimeter_value_ca.paa";
				};
			};
		};
		class CA_RadarAltmeter: CA_HUDRscControlsGroup
		{
			idc = 505;
			x = 0.8;
			y = 0.6;
			w = 0.25;
			h = 0.25;
			shadow = 0;
			class ControlsBackground
			{
				class Bcg: RscText
				{
					x = 0;
					y = 0;
					w = 100;
					h = 100;
					colorbackground[] = {0,0,1,0.5};
				};
			};
			class Controls
			{
				class CA_RadarAltmeterBar: RscIGProgress
				{
					idc = 506;
					x = 0.05;
					y = 0.0;
					w = 0.01;
					h = 0.2;
					texture = "#(argb,8,8,3)color(1,1,1,1)";
				};
				class CA_RadarAltmeterValue: RscIGUIValue
				{
					idc = 507;
					style = 0;
					x = 0.065;
					y = 0.17;
					w = 0.1;
					shadow = 0;
					sizeEx = 0.035;
				};
			};
		};
		class CA_WindIndicator: CA_HUDRscControlsGroup
		{
			idc = 515;
			x = 0.1;
			y = 0.7;
			w = 0.1;
			h = 0.1;
		};
		class CA_StabilityIdicator: CA_HUDRscControlsGroup
		{
			idc = 520;
			x = 0.65;
			y = 0.7;
			w = 0.065;
			h = 0.1;
		};
		class CA_ValueColective: RscIGProgress
		{
			x = "0.018 + SafeZoneX";
			y = "0.01 + SafeZoneY";
			w = 0.0196078;
			h = 0.2091503;
			idc = 525;
			texture = "#(argb,8,8,3)color(1,1,1,1)";
			colorFrame[] = {"(profilenamespace getvariable ['IGUI_TEXT_RGB_R',0])","(profilenamespace getvariable ['IGUI_TEXT_RGB_G',1])","(profilenamespace getvariable ['IGUI_TEXT_RGB_B',1])","(profilenamespace getvariable ['IGUI_TEXT_RGB_A',0.8])"};
		};
		class CA_AutoTrim: RscIGUIValue
		{
			x = 0.85;
			y = 0.8;
			w = 0.05;
			h = 0.05;
			idc = 545;
			shadow = 0;
			SizeEx = 0.025;
			text = "TRIM";
		};
		class CA_AutoHover: RscIGUIValue
		{
			x = 0.8;
			y = 0.8;
			w = 0.05;
			h = 0.05;
			idc = 546;
			shadow = 0;
			SizeEx = 0.025;
			text = "HOVER";
		};
		class CA_Torque: RscIGUIValue
		{
			idc = 510;
			style = 1;
			x = 0.45;
			y = 0.75;
			w = 0.12;
			shadow = 0;
			SizeEx = 0.035;
		};
		class CA_GMeter: RscIGUIValue
		{
			idc = 501;
			style = 1;
			x = 0.45;
			y = 0.8;
			w = 0.12;
			shadow = 0;
			SizeEx = 0.035;
		};
		class Batteries: RscIGUIValue
		{
			idc = 11831;
			x = "0.08 + SafeZoneX";
			y = "0.036 + SafeZoneY";
			w = 0.3;
			h = 0.039;
			sizeEx = 0.02674;
			shadow = 2;
			text = "";
		};
		class Starter: Batteries
		{
			idc = 11833;
			y = "0.075 + SafeZoneY";
		};
		class Throttles: Batteries
		{
			idc = 11834;
			y = "0.114 + SafeZoneY";
		};
		class EnginesRPMs: Batteries
		{
			idc = 11835;
			y = "0.153 + SafeZoneY";
		};
		class APU: Batteries
		{
			idc = 11832;
			y = "0.192 + SafeZoneY";
		};
	};
	class RscUnitInfoAirRTDFull: RscUnitInfoAir
	{
		onload = "uinamespace setvariable ['RscUnitInfoAir',_this select 0];";
		controls[] = {"WeaponInfoControlsGroupRight","CA_Horizon_Lite","CA_Horizon_Analogue","CA_Speed_Analogue","CA_Compass_Analogue","CA_Altitude_Analogue","CA_Stability_Analogue","CA_Damage_Status"};
		class CA_Horizon_Lite: CA_HUDRscControlsGroup
		{
			idc = 541;
			x = "safezoneX";
			y = "safezoneY";
			w = "safezoneW";
			h = "safezoneH";
		};
		class CA_Speed_Analogue: CA_HUDRscControlsGroup
		{
			idc = 601;
			x = "0 * 								(		((safezoneW / safezoneH) min 1.2) / 32) + 			(1 * 								(		((safezoneW / safezoneH) min 1.2) / 32) + 		(safezoneX + (safezoneW - 					((safezoneW / safezoneH) min 1.2)) / 2))";
			y = "0 * 								(		(		((safezoneW / safezoneH) min 1.2) / 1.2) / 20) + 			(13.5 * 								(		(		((safezoneW / safezoneH) min 1.2) / 1.2) / 20) + 		(safezoneY + safezoneH - 					(		((safezoneW / safezoneH) min 1.2) / 1.2)))";
			w = "6 * 								(		((safezoneW / safezoneH) min 1.2) / 32)";
			h = "6 * 								(		(		((safezoneW / safezoneH) min 1.2) / 1.2) / 20)";
			class controls
			{
				class CA_Speed_Analogue_Background: RscPicture
				{
					idc = 607;
					text = "A3\ui_f\data\igui\rscingameui\RscUnitInfoAirRTDFull\analogue_background_speed_ca.paa";
					x = "0 * 								(		((safezoneW / safezoneH) min 1.2) / 32)";
					y = "0 * 								(		(		((safezoneW / safezoneH) min 1.2) / 1.2) / 20)";
					w = "6 * 								(		((safezoneW / safezoneH) min 1.2) / 32)";
					h = "6 * 								(		(		((safezoneW / safezoneH) min 1.2) / 1.2) / 20)";
				};
				class CA_Speed_Analogue_Background_Imperial: RscPicture
				{
					idc = 606;
					text = "A3\ui_f\data\igui\rscingameui\RscUnitInfoAirRTDFull\analogue_background_speed_imp_ca.paa";
					x = "0 * 								(		((safezoneW / safezoneH) min 1.2) / 32)";
					y = "0 * 								(		(		((safezoneW / safezoneH) min 1.2) / 1.2) / 20)";
					w = "6 * 								(		((safezoneW / safezoneH) min 1.2) / 32)";
					h = "6 * 								(		(		((safezoneW / safezoneH) min 1.2) / 1.2) / 20)";
				};
				class CA_Speed_Analogue_Needle: RscPicture
				{
					idc = 602;
					text = "\A3\ui_f\data\igui\rscingameui\RscUnitInfoAirRTDFull\analogue_arrow_ca.paa";
					x = "1 * 								(		((safezoneW / safezoneH) min 1.2) / 32)";
					y = "1 * 								(		(		((safezoneW / safezoneH) min 1.2) / 1.2) / 20)";
					w = "4 * 								(		((safezoneW / safezoneH) min 1.2) / 32)";
					h = "4 * 								(		(		((safezoneW / safezoneH) min 1.2) / 1.2) / 20)";
				};
				class CA_Speed_Analogue_Min: RscPicture
				{
					idc = 603;
					colorText[] = {"(profilenamespace getvariable ['IGUI_TEXT_RGB_R',0])","(profilenamespace getvariable ['IGUI_TEXT_RGB_G',1])","(profilenamespace getvariable ['IGUI_TEXT_RGB_B',1])",1};
					text = "\A3\ui_f\data\igui\rscingameui\RscUnitInfoAirRTDFull\MarkerMIN_CA.paa";
					x = "2.25 * 								(		((safezoneW / safezoneH) min 1.2) / 32)";
					y = "2.25 * 								(		(		((safezoneW / safezoneH) min 1.2) / 1.2) / 20)";
					w = "1 * 								(		((safezoneW / safezoneH) min 1.2) / 32)";
					h = "1 * 								(		(		((safezoneW / safezoneH) min 1.2) / 1.2) / 20)";
				};
				class CA_Speed_Analogue_Max: RscPicture
				{
					idc = 604;
					colorText[] = {"(profilenamespace getvariable ['IGUI_TEXT_RGB_R',0])","(profilenamespace getvariable ['IGUI_TEXT_RGB_G',1])","(profilenamespace getvariable ['IGUI_TEXT_RGB_B',1])",1};
					text = "\A3\ui_f\data\igui\rscingameui\RscUnitInfoAirRTDFull\MarkerMAX_CA.paa";
					x = "2.25 * 								(		((safezoneW / safezoneH) min 1.2) / 32)";
					y = "2.25 * 								(		(		((safezoneW / safezoneH) min 1.2) / 1.2) / 20)";
					w = "1 * 								(		((safezoneW / safezoneH) min 1.2) / 32)";
					h = "1 * 								(		(		((safezoneW / safezoneH) min 1.2) / 1.2) / 20)";
				};
				class CA_Speed_Analogue_Value: RscText
				{
					idc = 605;
					sizeEx = "(			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 0.8)";
					style = 2;
					x = "2 * 								(		((safezoneW / safezoneH) min 1.2) / 32)";
					y = "0 * 								(		(		((safezoneW / safezoneH) min 1.2) / 1.2) / 20)";
					w = "2 * 								(		((safezoneW / safezoneH) min 1.2) / 32)";
					h = "0.5 * 								(		(		((safezoneW / safezoneH) min 1.2) / 1.2) / 20)";
				};
			};
		};
		class CA_Altitude_Analogue: CA_HUDRscControlsGroup
		{
			idc = 611;
			x = "6 * 								(		((safezoneW / safezoneH) min 1.2) / 32) + 			(1 * 								(		((safezoneW / safezoneH) min 1.2) / 32) + 		(safezoneX + (safezoneW - 					((safezoneW / safezoneH) min 1.2)) / 2))";
			y = "0 * 								(		(		((safezoneW / safezoneH) min 1.2) / 1.2) / 20) + 			(13.5 * 								(		(		((safezoneW / safezoneH) min 1.2) / 1.2) / 20) + 		(safezoneY + safezoneH - 					(		((safezoneW / safezoneH) min 1.2) / 1.2)))";
			w = "6 * 								(		((safezoneW / safezoneH) min 1.2) / 32)";
			h = "6 * 								(		(		((safezoneW / safezoneH) min 1.2) / 1.2) / 20)";
			class controls
			{
				class CA_Altitude_Analogue_Background: RscPicture
				{
					idc = 617;
					text = "A3\ui_f\data\igui\rscingameui\RscUnitInfoAirRTDFull\analogue_background_altitude_ca.paa";
					x = "-3.37704e-007 * 								(		((safezoneW / safezoneH) min 1.2) / 32)";
					y = "0 * 								(		(		((safezoneW / safezoneH) min 1.2) / 1.2) / 20)";
					w = "6 * 								(		((safezoneW / safezoneH) min 1.2) / 32)";
					h = "6 * 								(		(		((safezoneW / safezoneH) min 1.2) / 1.2) / 20)";
				};
				class CA_Altitude_Analogue_Background_Imperial: RscPicture
				{
					idc = 616;
					text = "A3\ui_f\data\igui\rscingameui\RscUnitInfoAirRTDFull\analogue_background_altitude_imp_ca.paa";
					x = "0 * 								(		((safezoneW / safezoneH) min 1.2) / 32)";
					y = "0 * 								(		(		((safezoneW / safezoneH) min 1.2) / 1.2) / 20)";
					w = "6 * 								(		((safezoneW / safezoneH) min 1.2) / 32)";
					h = "6 * 								(		(		((safezoneW / safezoneH) min 1.2) / 1.2) / 20)";
				};
				class CA_Altitude_Analogue_Needle: RscPicture
				{
					idc = 612;
					text = "\A3\ui_f\data\igui\rscingameui\RscUnitInfoAirRTDFull\analogue_arrow_ca.paa";
					x = "1 * 								(		((safezoneW / safezoneH) min 1.2) / 32)";
					y = "1 * 								(		(		((safezoneW / safezoneH) min 1.2) / 1.2) / 20)";
					w = "4 * 								(		((safezoneW / safezoneH) min 1.2) / 32)";
					h = "4 * 								(		(		((safezoneW / safezoneH) min 1.2) / 1.2) / 20)";
				};
				class CA_Altitude_Analogue_Min: RscPicture
				{
					idc = 613;
					colorText[] = {"(profilenamespace getvariable ['IGUI_TEXT_RGB_R',0])","(profilenamespace getvariable ['IGUI_TEXT_RGB_G',1])","(profilenamespace getvariable ['IGUI_TEXT_RGB_B',1])",1};
					text = "\A3\ui_f\data\igui\rscingameui\RscUnitInfoAirRTDFull\MarkerMIN_CA.paa";
					x = "2.25 * 								(		((safezoneW / safezoneH) min 1.2) / 32)";
					y = "2.25 * 								(		(		((safezoneW / safezoneH) min 1.2) / 1.2) / 20)";
					w = "1 * 								(		((safezoneW / safezoneH) min 1.2) / 32)";
					h = "1 * 								(		(		((safezoneW / safezoneH) min 1.2) / 1.2) / 20)";
				};
				class CA_Altitude_Analogue_Max: RscPicture
				{
					idc = 614;
					colorText[] = {"(profilenamespace getvariable ['IGUI_TEXT_RGB_R',0])","(profilenamespace getvariable ['IGUI_TEXT_RGB_G',1])","(profilenamespace getvariable ['IGUI_TEXT_RGB_B',1])",1};
					text = "\A3\ui_f\data\igui\rscingameui\RscUnitInfoAirRTDFull\MarkerMAX_CA.paa";
					x = "2.25 * 								(		((safezoneW / safezoneH) min 1.2) / 32)";
					y = "2.25 * 								(		(		((safezoneW / safezoneH) min 1.2) / 1.2) / 20)";
					w = "1 * 								(		((safezoneW / safezoneH) min 1.2) / 32)";
					h = "1 * 								(		(		((safezoneW / safezoneH) min 1.2) / 1.2) / 20)";
				};
				class CA_Altitude_Analogue_Value: RscText
				{
					idc = 615;
					sizeEx = "(			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 0.8)";
					style = 2;
					x = "2 * 								(		((safezoneW / safezoneH) min 1.2) / 32)";
					y = "0 * 								(		(		((safezoneW / safezoneH) min 1.2) / 1.2) / 20)";
					w = "2 * 								(		((safezoneW / safezoneH) min 1.2) / 32)";
					h = "0.5 * 								(		(		((safezoneW / safezoneH) min 1.2) / 1.2) / 20)";
				};
			};
		};
		class CA_Horizon_Analogue: CA_HUDRscControlsGroup
		{
			idc = 621;
			x = "12 * 								(		((safezoneW / safezoneH) min 1.2) / 32) + 			(1 * 								(		((safezoneW / safezoneH) min 1.2) / 32) + 		(safezoneX + (safezoneW - 					((safezoneW / safezoneH) min 1.2)) / 2))";
			y = "0 * 								(		(		((safezoneW / safezoneH) min 1.2) / 1.2) / 20) + 			(13.5 * 								(		(		((safezoneW / safezoneH) min 1.2) / 1.2) / 20) + 		(safezoneY + safezoneH - 					(		((safezoneW / safezoneH) min 1.2) / 1.2)))";
			w = "6 * 								(		((safezoneW / safezoneH) min 1.2) / 32)";
			h = "6 * 								(		(		((safezoneW / safezoneH) min 1.2) / 1.2) / 20)";
			class controls
			{
				class CA_Horizon_Analogue_Background: RscPicture
				{
					idc = 1208;
					text = "A3\ui_f\data\igui\rscingameui\RscUnitInfoAirRTDFull\analogue_background_horizon_ca.paa";
					x = "0 * 								(		((safezoneW / safezoneH) min 1.2) / 32)";
					y = "0 * 								(		(		((safezoneW / safezoneH) min 1.2) / 1.2) / 20)";
					w = "6 * 								(		((safezoneW / safezoneH) min 1.2) / 32)";
					h = "6 * 								(		(		((safezoneW / safezoneH) min 1.2) / 1.2) / 20)";
				};
				class CA_Horizon_Analogue_Needle: RscPicture
				{
					idc = 622;
					text = "\A3\ui_f\data\igui_horizon_axes_ca.paa";
					x = "1.5 * 								(		((safezoneW / safezoneH) min 1.2) / 32)";
					y = "1.5 * 								(		(		((safezoneW / safezoneH) min 1.2) / 1.2) / 20)";
					w = "3 * 								(		((safezoneW / safezoneH) min 1.2) / 32)";
					h = "3 * 								(		(		((safezoneW / safezoneH) min 1.2) / 1.2) / 20)";
					colorText[] = {1,1,1,1};
				};
				class CA_Horizon_Analogue_Value: RscText
				{
					idc = 623;
					sizeEx = "(			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 0.8)";
					style = 2;
					x = "2 * 								(		((safezoneW / safezoneH) min 1.2) / 32)";
					y = "0 * 								(		(		((safezoneW / safezoneH) min 1.2) / 1.2) / 20)";
					w = "2 * 								(		((safezoneW / safezoneH) min 1.2) / 32)";
					h = "0.5 * 								(		(		((safezoneW / safezoneH) min 1.2) / 1.2) / 20)";
				};
				class CA_Horizon_Analogue_Aircraft: RscPicture
				{
					colorText[] = {"(profilenamespace getvariable ['IGUI_TEXT_RGB_R',0])","(profilenamespace getvariable ['IGUI_TEXT_RGB_G',1])","(profilenamespace getvariable ['IGUI_TEXT_RGB_B',1])",1};
					shadow = 2;
					idc = 1232;
					text = "\A3\ui_f\data\igui\rscingameui\RscUnitInfoAirRTDFull\analogue_horizon_aircraft_ca.paa";
					x = "1.5 * 								(		((safezoneW / safezoneH) min 1.2) / 32)";
					y = "1.5 * 								(		(		((safezoneW / safezoneH) min 1.2) / 1.2) / 20)";
					w = "3 * 								(		((safezoneW / safezoneH) min 1.2) / 32)";
					h = "3 * 								(		(		((safezoneW / safezoneH) min 1.2) / 1.2) / 20)";
				};
			};
		};
		class CA_Stability_Analogue: CA_HUDRscControlsGroup
		{
			idc = 641;
			x = "18 * 								(		((safezoneW / safezoneH) min 1.2) / 32) + 			(1 * 								(		((safezoneW / safezoneH) min 1.2) / 32) + 		(safezoneX + (safezoneW - 					((safezoneW / safezoneH) min 1.2)) / 2))";
			y = "0 * 								(		(		((safezoneW / safezoneH) min 1.2) / 1.2) / 20) + 			(13.5 * 								(		(		((safezoneW / safezoneH) min 1.2) / 1.2) / 20) + 		(safezoneY + safezoneH - 					(		((safezoneW / safezoneH) min 1.2) / 1.2)))";
			w = "6 * 								(		((safezoneW / safezoneH) min 1.2) / 32)";
			h = "6 * 								(		(		((safezoneW / safezoneH) min 1.2) / 1.2) / 20)";
			class controls
			{
				class CA_Stability_Analogue_Background: RscPicture
				{
					idc = 648;
					text = "A3\ui_f\data\igui\rscingameui\RscUnitInfoAirRTDFull\analogue_background_stability_ca.paa";
					x = "0 * 								(		((safezoneW / safezoneH) min 1.2) / 32)";
					y = "0 * 								(		(		((safezoneW / safezoneH) min 1.2) / 1.2) / 20)";
					w = "6 * 								(		((safezoneW / safezoneH) min 1.2) / 32)";
					h = "6 * 								(		(		((safezoneW / safezoneH) min 1.2) / 1.2) / 20)";
				};
				class CA_Stability_Analogue_Background_Imperial: RscPicture
				{
					idc = 647;
					text = "A3\ui_f\data\igui\rscingameui\RscUnitInfoAirRTDFull\analogue_background_stability_imp_ca.paa";
					x = "0 * 								(		((safezoneW / safezoneH) min 1.2) / 32)";
					y = "0 * 								(		(		((safezoneW / safezoneH) min 1.2) / 1.2) / 20)";
					w = "6 * 								(		((safezoneW / safezoneH) min 1.2) / 32)";
					h = "6 * 								(		(		((safezoneW / safezoneH) min 1.2) / 1.2) / 20)";
				};
				class CA_Stability_Analogue_Speed: RscPicture
				{
					idc = 642;
					text = "\A3\ui_f\data\igui\rscingameui\RscUnitInfoAirRTDFull\WhiteDot_CA.paa";
					x = "1.75 * 								(		((safezoneW / safezoneH) min 1.2) / 32)";
					y = "1.75 * 								(		(		((safezoneW / safezoneH) min 1.2) / 1.2) / 20)";
					w = "0.5 * 								(		((safezoneW / safezoneH) min 1.2) / 32)";
					h = "0.5 * 								(		(		((safezoneW / safezoneH) min 1.2) / 1.2) / 20)";
					colorText[] = {1,1,1,1};
				};
				class CA_Stability_Analogue_Autohover: RscPicture
				{
					idc = 546;
					colorText[] = {"(profilenamespace getvariable ['IGUI_TEXT_RGB_R',0])","(profilenamespace getvariable ['IGUI_TEXT_RGB_G',1])","(profilenamespace getvariable ['IGUI_TEXT_RGB_B',1])",1};
					text = "\A3\ui_f\data\igui\rscingameui\RscUnitInfoAirRTDFull\WhiteDot_CA.paa";
					x = "2.75 * 								(		((safezoneW / safezoneH) min 1.2) / 32)";
					y = "2.75 * 								(		(		((safezoneW / safezoneH) min 1.2) / 1.2) / 20)";
					w = "0.5 * 								(		((safezoneW / safezoneH) min 1.2) / 32)";
					h = "0.5 * 								(		(		((safezoneW / safezoneH) min 1.2) / 1.2) / 20)";
				};
				class CA_Stability_Analogue_Vertical_Speed_Needle: RscPicture
				{
					idc = 644;
					text = "\A3\ui_f\data\igui\rscingameui\RscUnitInfoAirRTDFull\analogue_arrow_VSI_ca.paa";
					x = "1 * 								(		((safezoneW / safezoneH) min 1.2) / 32)";
					y = "1 * 								(		(		((safezoneW / safezoneH) min 1.2) / 1.2) / 20)";
					w = "4 * 								(		((safezoneW / safezoneH) min 1.2) / 32)";
					h = "4 * 								(		(		((safezoneW / safezoneH) min 1.2) / 1.2) / 20)";
					colorText[] = {1,1,1,1};
				};
				class CA_Stability_Analogue_Collective: RscPicture
				{
					idc = 645;
					colorText[] = {"(profilenamespace getvariable ['IGUI_TEXT_RGB_R',0])","(profilenamespace getvariable ['IGUI_TEXT_RGB_G',1])","(profilenamespace getvariable ['IGUI_TEXT_RGB_B',1])",1};
					text = "A3\ui_f\data\igui\rscingameui\RscUnitInfoAirRTDFull\analogue_right_ca.paa";
					x = "3 * 								(		((safezoneW / safezoneH) min 1.2) / 32)";
					y = "0 * 								(		(		((safezoneW / safezoneH) min 1.2) / 1.2) / 20)";
					w = "3 * 								(		((safezoneW / safezoneH) min 1.2) / 32)";
					h = "6 * 								(		(		((safezoneW / safezoneH) min 1.2) / 1.2) / 20)";
				};
				class CA_Stability_Analogue_Value: RscText
				{
					idc = 643;
					sizeEx = "(			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 0.8)";
					style = 2;
					x = "2 * 								(		((safezoneW / safezoneH) min 1.2) / 32)";
					y = "0 * 								(		(		((safezoneW / safezoneH) min 1.2) / 1.2) / 20)";
					w = "2 * 								(		((safezoneW / safezoneH) min 1.2) / 32)";
					h = "0.5 * 								(		(		((safezoneW / safezoneH) min 1.2) / 1.2) / 20)";
				};
			};
		};
		class CA_Compass_Analogue: CA_HUDRscControlsGroup
		{
			idc = 631;
			x = "24 * 								(		((safezoneW / safezoneH) min 1.2) / 32) + 			(1 * 								(		((safezoneW / safezoneH) min 1.2) / 32) + 		(safezoneX + (safezoneW - 					((safezoneW / safezoneH) min 1.2)) / 2))";
			y = "0 * 								(		(		((safezoneW / safezoneH) min 1.2) / 1.2) / 20) + 			(13.5 * 								(		(		((safezoneW / safezoneH) min 1.2) / 1.2) / 20) + 		(safezoneY + safezoneH - 					(		((safezoneW / safezoneH) min 1.2) / 1.2)))";
			w = "6 * 								(		((safezoneW / safezoneH) min 1.2) / 32)";
			h = "6 * 								(		(		((safezoneW / safezoneH) min 1.2) / 1.2) / 20)";
			class controls
			{
				class CA_Compass_Analogue_Background: RscPicture
				{
					idc = 1215;
					text = "A3\ui_f\data\igui\rscingameui\RscUnitInfoAirRTDFull\analogue_background_compass_ca.paa";
					x = "0 * 								(		((safezoneW / safezoneH) min 1.2) / 32)";
					y = "0 * 								(		(		((safezoneW / safezoneH) min 1.2) / 1.2) / 20)";
					w = "6 * 								(		((safezoneW / safezoneH) min 1.2) / 32)";
					h = "6 * 								(		(		((safezoneW / safezoneH) min 1.2) / 1.2) / 20)";
				};
				class CA_Compass_Analogue_Needle: RscPicture
				{
					idc = 632;
					text = "\A3\ui_f\data\igui\rscingameui\RscUnitInfoAirRTDFull\analogue_compass_ca.paa";
					x = "0 * 								(		((safezoneW / safezoneH) min 1.2) / 32)";
					y = "0 * 								(		(		((safezoneW / safezoneH) min 1.2) / 1.2) / 20)";
					w = "6 * 								(		((safezoneW / safezoneH) min 1.2) / 32)";
					h = "6 * 								(		(		((safezoneW / safezoneH) min 1.2) / 1.2) / 20)";
				};
				class CA_Compass_Analogue_Wind: RscPicture
				{
					idc = 633;
					colorText[] = {"(profilenamespace getvariable ['IGUI_TEXT_RGB_R',0])","(profilenamespace getvariable ['IGUI_TEXT_RGB_G',1])","(profilenamespace getvariable ['IGUI_TEXT_RGB_B',1])",1};
					text = "\A3\ui_f\data\igui_wind_ca.paa";
					x = "1.5 * 								(		((safezoneW / safezoneH) min 1.2) / 32)";
					y = "1.5 * 								(		(		((safezoneW / safezoneH) min 1.2) / 1.2) / 20)";
					w = "3 * 								(		((safezoneW / safezoneH) min 1.2) / 32)";
					h = "3 * 								(		(		((safezoneW / safezoneH) min 1.2) / 1.2) / 20)";
				};
				class CA_Compass_Analogue_Waypoint: RscPicture
				{
					idc = 634;
					text = "\A3\ui_f\data\igui\rscingameui\RscUnitInfoAirRTDFull\MarkerWPT_CA.paa";
					x = "2.25 * 								(		((safezoneW / safezoneH) min 1.2) / 32)";
					y = "2.25 * 								(		(		((safezoneW / safezoneH) min 1.2) / 1.2) / 20)";
					w = "0.5 * 								(		((safezoneW / safezoneH) min 1.2) / 32)";
					h = "0.5 * 								(		(		((safezoneW / safezoneH) min 1.2) / 1.2) / 20)";
					colorText[] = {1,0.5,0,1};
				};
				class CA_Compass_Analogue_Min: RscPicture
				{
					idc = 635;
					colorText[] = {"(profilenamespace getvariable ['IGUI_TEXT_RGB_R',0])","(profilenamespace getvariable ['IGUI_TEXT_RGB_G',1])","(profilenamespace getvariable ['IGUI_TEXT_RGB_B',1])",1};
					text = "\A3\ui_f\data\igui\rscingameui\RscUnitInfoAirRTDFull\MarkerMIN_CA.paa";
					x = "2.25 * 								(		((safezoneW / safezoneH) min 1.2) / 32)";
					y = "2.25 * 								(		(		((safezoneW / safezoneH) min 1.2) / 1.2) / 20)";
					w = "1 * 								(		((safezoneW / safezoneH) min 1.2) / 32)";
					h = "1 * 								(		(		((safezoneW / safezoneH) min 1.2) / 1.2) / 20)";
				};
				class CA_Compass_Analogue_Max: RscPicture
				{
					idc = 636;
					colorText[] = {"(profilenamespace getvariable ['IGUI_TEXT_RGB_R',0])","(profilenamespace getvariable ['IGUI_TEXT_RGB_G',1])","(profilenamespace getvariable ['IGUI_TEXT_RGB_B',1])",1};
					text = "\A3\ui_f\data\igui\rscingameui\RscUnitInfoAirRTDFull\MarkerMAX_CA.paa";
					x = "2.25 * 								(		((safezoneW / safezoneH) min 1.2) / 32)";
					y = "2.25 * 								(		(		((safezoneW / safezoneH) min 1.2) / 1.2) / 20)";
					w = "1 * 								(		((safezoneW / safezoneH) min 1.2) / 32)";
					h = "1 * 								(		(		((safezoneW / safezoneH) min 1.2) / 1.2) / 20)";
				};
				class CA_Compass_Analogue_Value: RscText
				{
					idc = 637;
					sizeEx = "(			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 0.8)";
					style = 2;
					x = "2 * 								(		((safezoneW / safezoneH) min 1.2) / 32)";
					y = "0 * 								(		(		((safezoneW / safezoneH) min 1.2) / 1.2) / 20)";
					w = "2 * 								(		((safezoneW / safezoneH) min 1.2) / 32)";
					h = "0.5 * 								(		(		((safezoneW / safezoneH) min 1.2) / 1.2) / 20)";
				};
			};
		};
		class CA_Damage_Status: CA_HUDRscControlsGroup
		{
			idc = 660;
			class VScrollbar: VScrollbar
			{
				width = 0;
			};
			class HScrollbar: HScrollbar
			{
				height = 0;
			};
			x = "0 * 								(		((safezoneW / safezoneH) min 1.2) / 32) + 			(1 * 								(		((safezoneW / safezoneH) min 1.2) / 32) + 		(safezoneX + (safezoneW - 					((safezoneW / safezoneH) min 1.2)) / 2))";
			y = "0 * 								(		(		((safezoneW / safezoneH) min 1.2) / 1.2) / 20) + 			(13.5 * 								(		(		((safezoneW / safezoneH) min 1.2) / 1.2) / 20) + 		(safezoneY + safezoneH - 					(		((safezoneW / safezoneH) min 1.2) / 1.2)))";
			w = "30 * 								(		((safezoneW / safezoneH) min 1.2) / 32)";
			h = "6 * 								(		(		((safezoneW / safezoneH) min 1.2) / 1.2) / 20)";
			class controls
			{
				class CA_Damage_Temperature: RscPicture
				{
					idc = 667;
					text = "\A3\ui_f\data\igui\rscingameui\RscUnitInfoAirRTDFull\igui_WLight2_TEMP_CA.paa";
					x = "5.5 * 								(		((safezoneW / safezoneH) min 1.2) / 32)";
					y = "4 * 								(		(		((safezoneW / safezoneH) min 1.2) / 1.2) / 20)";
					w = "1 * 								(		((safezoneW / safezoneH) min 1.2) / 32)";
					h = "1 * 								(		(		((safezoneW / safezoneH) min 1.2) / 1.2) / 20)";
				};
				class CA_Damage_RPM: RscPicture
				{
					idc = 662;
					text = "\A3\ui_f\data\igui\rscingameui\RscUnitInfoAirRTDFull\igui_WLight2_RPM_CA.paa";
					x = "11.5 * 								(		((safezoneW / safezoneH) min 1.2) / 32)";
					y = "1 * 								(		(		((safezoneW / safezoneH) min 1.2) / 1.2) / 20)";
					w = "1 * 								(		((safezoneW / safezoneH) min 1.2) / 32)";
					h = "1 * 								(		(		((safezoneW / safezoneH) min 1.2) / 1.2) / 20)";
				};
				class CA_Damage_Torque: RscPicture
				{
					idc = 664;
					text = "\A3\ui_f\data\igui\rscingameui\RscUnitInfoAirRTDFull\igui_WLight2_TRQ_CA.paa";
					x = "17.5 * 								(		((safezoneW / safezoneH) min 1.2) / 32)";
					y = "1 * 								(		(		((safezoneW / safezoneH) min 1.2) / 1.2) / 20)";
					w = "1 * 								(		((safezoneW / safezoneH) min 1.2) / 32)";
					h = "1 * 								(		(		((safezoneW / safezoneH) min 1.2) / 1.2) / 20)";
				};
				class CA_Damage_Electricity: RscPicture
				{
					idc = 665;
					text = "\A3\ui_f\data\igui\rscingameui\RscUnitInfoAirRTDFull\igui_WLight2_DC_CA.paa";
					x = "23.5 * 								(		((safezoneW / safezoneH) min 1.2) / 32)";
					y = "1 * 								(		(		((safezoneW / safezoneH) min 1.2) / 1.2) / 20)";
					w = "1 * 								(		((safezoneW / safezoneH) min 1.2) / 32)";
					h = "1 * 								(		(		((safezoneW / safezoneH) min 1.2) / 1.2) / 20)";
				};
				class CA_Damage_Engine: RscPicture
				{
					idc = 663;
					text = "\A3\ui_f\data\igui\rscingameui\RscUnitInfoAirRTDFull\igui_WLight_ENG_CA.paa";
					x = "5.5 * 								(		((safezoneW / safezoneH) min 1.2) / 32)";
					y = "1 * 								(		(		((safezoneW / safezoneH) min 1.2) / 1.2) / 20)";
					w = "1 * 								(		((safezoneW / safezoneH) min 1.2) / 32)";
					h = "1 * 								(		(		((safezoneW / safezoneH) min 1.2) / 1.2) / 20)";
				};
				class CA_Damage_MainRotor: RscPicture
				{
					idc = 668;
					text = "\A3\ui_f\data\igui\rscingameui\RscUnitInfoAirRTDFull\igui_WLight_MROT_CA.paa";
					x = "11.5 * 								(		((safezoneW / safezoneH) min 1.2) / 32)";
					y = "4 * 								(		(		((safezoneW / safezoneH) min 1.2) / 1.2) / 20)";
					w = "1 * 								(		((safezoneW / safezoneH) min 1.2) / 32)";
					h = "1 * 								(		(		((safezoneW / safezoneH) min 1.2) / 1.2) / 20)";
				};
				class CA_Damage_Autohover: RscPicture
				{
					idc = 669;
					text = "\A3\ui_f\data\igui\rscingameui\RscUnitInfoAirRTDFull\igui_WLight_ATRQ_CA.paa";
					x = "17.5 * 								(		((safezoneW / safezoneH) min 1.2) / 32)";
					y = "4 * 								(		(		((safezoneW / safezoneH) min 1.2) / 1.2) / 20)";
					w = "1 * 								(		((safezoneW / safezoneH) min 1.2) / 32)";
					h = "1 * 								(		(		((safezoneW / safezoneH) min 1.2) / 1.2) / 20)";
				};
				class CA_Damage_Fuel: RscPicture
				{
					idc = 666;
					text = "\A3\ui_f\data\igui\rscingameui\RscUnitInfoAirRTDFull\igui_WLight_FUEL_CA.paa";
					x = "23.5 * 								(		((safezoneW / safezoneH) min 1.2) / 32)";
					y = "4 * 								(		(		((safezoneW / safezoneH) min 1.2) / 1.2) / 20)";
					w = "1 * 								(		((safezoneW / safezoneH) min 1.2) / 32)";
					h = "1 * 								(		(		((safezoneW / safezoneH) min 1.2) / 1.2) / 20)";
				};
			};
		};
	};
	class RscOptics_Gunner_AAA_01: RscWeaponRangeZeroing
	{
		class CA_Distance: CA_Distance
		{
			colorText[] = {1,1,1,0.8};
		};
	};
	class RscOptics_Gunner_APC_01: RscWeaponRangeZeroing
	{
		class CA_Distance: CA_Distance
		{
			colorText[] = {1,0,0,0.8};
		};
	};
	class RscOptics_Gunner_APC_02: RscWeaponRangeZeroing
	{
		class CA_Distance: CA_Distance
		{
			colorText[] = {1,1,1,0.8};
		};
	};
	class RscOptics_Gunner_APC_03: RscWeaponRangeZeroing
	{
		class CA_Distance: CA_Distance
		{
			colorText[] = {1,1,1,0.8};
		};
	};
	class RscOptics_Gunner_MBT_01: RscWeaponRangeZeroing
	{
		class CA_Distance: CA_Distance
		{
			colorText[] = {0.675,1,0.4,0.8};
		};
	};
	class RscOptics_Gunner_MBT_02: RscWeaponRangeZeroing
	{
		class CA_Distance: CA_Distance
		{
			colorText[] = {1,1,1,0.8};
		};
	};
	class RscOptics_Gunner_MBT_03: RscWeaponRangeZeroing
	{
		class CA_Distance: CA_Distance
		{
			colorText[] = {1,1,1,0.8};
		};
	};
	class RscOptics_Commander_01: RscWeaponRangeZeroing
	{
		class CA_Distance: CA_Distance
		{
			colorText[] = {0.675,1,0.4,0.8};
		};
	};
	class RscOptics_Commander_02: RscWeaponRangeZeroing
	{
		class CA_Distance: CA_Distance
		{
			colorText[] = {1,1,1,0.8};
		};
	};
	class RscOptics_Commander_03: RscWeaponRangeZeroing
	{
		class CA_Distance: CA_Distance
		{
			colorText[] = {1,1,1,0.8};
		};
	};
};
class EpochLoadingScreen
{
	idd = 13377;
	onLoad = "uiNamespace setVariable ['EPOCH_loadingScreen',_this select 0]";
	onUnload = "uiNamespace setVariable ['EPOCH_loadingScreen',displayNull]";
	//onLoad = "[""onLoad"",_this,""RscDisplayLoading"",'Loading'] call compile preprocessfilelinenumbers ""A3\ui_f\scripts\initDisplay.sqf""";
	//onUnload = "[""onUnload"",_this,""RscDisplayLoading"",'Loading'] call compile preprocessfilelinenumbers ""A3\ui_f\scripts\initDisplay.sqf""";

	class controls
	{
		class ProgressMap: RscProgress
		{
			idc = 104; // progress bar, has to have idc 104
			colorBar[] = {"(profilenamespace getvariable ['GUI_BCG_RGB_R',0.69])","(profilenamespace getvariable ['GUI_BCG_RGB_G',0.75])","(profilenamespace getvariable ['GUI_BCG_RGB_B',0.5])","(profilenamespace getvariable ['GUI_BCG_RGB_A',0.8])"};
			texture = "#(argb,8,8,3)color(1,1,1,1)";
			x = 0.295761 * safezoneW + safezoneX;
			y = 0.764 * safezoneH + safezoneY;
			w = 0.408477 * safezoneW;
			h = 0.0066 * safezoneH;
		};
		class EpochLogo: RscPicture
		{
			idc = 40;
			text = "\x\addons\a3_epoch_code\Data\EpochLogo.paa";
			x = 0.291635 * safezoneW + safezoneX;
			y = 0.214 * safezoneH + safezoneY;
			w = 0.417761 * safezoneW;
			h = 0.2046 * safezoneH;
		};
		class LoadingText: RscStructuredText
		{
			idc = 50;
			text = "";
			class Attributes
			{
				size = "0.8 * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
				align = "center";
			};
			x = 0.314328 * safezoneW + safezoneX;
			y = 0.709 * safezoneH + safezoneY;
			w = 0.350767 * safezoneW;
			h = 0.0396 * safezoneH;
			sizeEx = "0.8 *((((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
		};
	};



	/*
	class controls
	{
		class MapBackTop: RscText
		{
			x = "safezoneX";
			y = "safezoneY";
			w = "safezoneW";
			idc = 1000;
			h = "2.7 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			colorBackground[] = {0,0,0,1};
		};
		class MapName: RscText
		{
			x = "safezoneX + 0.2 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			y = "safezoneY";
			w = "safezoneW - 0.4 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			idc = 1001;
			h = "1.5 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			sizeEx = "1.5 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
		};
		class MapAuthor: RscText
		{
			x = "safezoneX + 0.2 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			y = "safezoneY + 1.3 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			font = "PuristaLight";
			idc = 1002;
			w = "16 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			colorText[] = {1,1,1,0.5};
			sizeEx = "0.8 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
		};
		class MapBackBottom: RscText
		{
			x = "safezoneX";
			y = "safezoneY + safezoneH - 2 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			w = "safezoneW";
			idc = 1003;
			h = "2 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			colorBackground[] = {0,0,0,0.6};
		};
		class MapDescription: RscStructuredText //Map Description
		{
			style = 2;
			x = 0;
			y = "safezoneY + safezoneH - 1.75 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			w = 1;
			class Attributes
			{
				size = "0.8 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
				align = "center";
			};
			idc = 1102;
			h = "1.75 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			sizeEx = "0.8 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
		};
		class ProgressMap: RscProgress
		{
			colorBar[] = {"(profilenamespace getvariable ['GUI_BCG_RGB_R',0.69])","(profilenamespace getvariable ['GUI_BCG_RGB_G',0.75])","(profilenamespace getvariable ['GUI_BCG_RGB_B',0.5])","(profilenamespace getvariable ['GUI_BCG_RGB_A',0.8])"};
			texture = "#(argb,8,8,3)color(1,1,1,1)";
			x = "safezoneX";
			y = "2.5 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + safezoneY";
			w = "safezoneW";
			idc = 104;
			h = "0.2 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
		};
		class ProgressMission: ProgressMap
		{
			idc = 1013;
			x = "1.5 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(safezoneX + (safezoneW - 					((safezoneW / safezoneH) min 1.2))/2)";
			y = "10 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(safezoneY + (safezoneH - 					(			((safezoneW / safezoneH) min 1.2) / 1.2))/2)";
			w = "16 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "0.2 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
		};
		class Disclaimer: RscControlsGroupNoScrollbars
		{
			x = "safezoneX + safezoneW - 19.5 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			y = "safezoneY + 3.5 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			idc = 2301;
			w = "18.5 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "3.7 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			class controls
			{
				class DisclaimerName: RscText
				{
					colorBackground[] = {"(profilenamespace getvariable ['GUI_BCG_RGB_R',0.69])","(profilenamespace getvariable ['GUI_BCG_RGB_G',0.75])","(profilenamespace getvariable ['GUI_BCG_RGB_B',0.5])","(profilenamespace getvariable ['GUI_BCG_RGB_A',0.8])"};
					idc = 1009;
					text = "BETA";
					x = "0 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
					y = "0 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
					w = "18.5 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
					h = "1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
				};
				class DisclaimerDescription: RscStructuredText
				{
					class Attributes
					{
						font = "PuristaLight";
						size = 0.8;
					};
					shadow = 0;
					colorBackground[] = {"(profilenamespace getvariable ['GUI_BCG_RGB_R',0.69])","(profilenamespace getvariable ['GUI_BCG_RGB_G',0.75])","(profilenamespace getvariable ['GUI_BCG_RGB_B',0.5])",0.3};
					colorText[] = {"(profilenamespace getvariable ['GUI_BCG_RGB_R',0.69])","(profilenamespace getvariable ['GUI_BCG_RGB_G',0.75])","(profilenamespace getvariable ['GUI_BCG_RGB_B',0.5])","(profilenamespace getvariable ['GUI_BCG_RGB_A',0.8])"};
					text = "This is <t color='#eeeeee'>not final software</t>; content and technology is <t color='#eeeeee'>subject to change</t> and may still contain errors / lack certain features.";
					idc = 1101;
					x = "0 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
					y = "1.1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
					w = "18.5 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
					h = "2.5 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
				};
			};
		};
		class LoadingStart: RscControlsGroup
		{
			idc = 2310;
			x = "0 * safezoneW + safezoneX";
			y = "0 * safezoneH + safezoneY";
			w = "1 * safezoneW";
			h = "1 * safezoneH";
			class controls
			{
				class Black: RscText
				{
					idc = 1000;
					x = "0 * safezoneW";
					y = "0 * safezoneH";
					w = "1 * safezoneW";
					h = "1 * safezoneH";
					colorBackground[] = {0,0,0,1};
				};
				class Noise: RscPicture
				{
					idc = 1201;
					text = "\A3\Ui_f\data\IGUI\RscTitles\SplashArma3\arma3_splashNoise_ca.paa";
					x = "0 * safezoneW";
					y = "0 * safezoneH";
					w = "1 * safezoneW";
					h = "1 * safezoneH";
				};
				class Logo: RscPictureKeepAspect
				{
					idc = 1200;
					text = "\A3\Ui_f\data\Logos\arma3_splash_ca.paa";
					x = "0.25 * safezoneW";
					y = "0.3125 * safezoneH";
					w = "0.5 * safezoneW";
					h = "0.25 * safezoneH";
				};
			};
		};
	};
	*/
	class controlsBackground
	{
		class Black: RscText
		{
			colorBackground[] = {0,0,0,1};
			x = "safezoneXAbs";
			y = "safezoneY";
			w = "safezoneWAbs";
			h = "safezoneH";
		};
		class Map: RscPicture
		{
			idc = 999;
			text = "#(argb,8,8,3)color(0,0,0,1)";
			colorText[] = {1,1,1,0.42};
			x = "safezoneX";
			y = "safezoneY - (safezoneW * 4/3) / 4";
			w = "safezoneW";
			h = "safezoneW * 4/3";
		};
		class CA_Vignette: RscVignette
		{
			colorText[] = {0,0,0,1};
		};
		class Noise: RscPicture
		{
			text = "\A3\Ui_f\data\GUI\Cfg\LoadingScreens\LoadingNoise_ca.paa";
			colorText[] = {1,1,1,1};
			x = "safezoneX";
			y = "safezoneY";
			w = "safezoneW";
			h = "safezoneH";
		};
	};
};
class EPOCH_createGrp {
	idd = -1200;
	movingEnable = 0;
	enableSimulation = 1;
	onLoad = "[] spawn { waitUntil {!isNull (findDisplay -1200)};_this call EPOCH_cGroup_onLoad}";
	class controlsBackground {
		class TopBG: IGUIBack
		{
			idc = 10;

			x = 0.334649 * safezoneW + safezoneX;
			y = 0.4076 * safezoneH + safezoneY;
			w = 0.319769 * safezoneW;
			h = 0.022 * safezoneH;
			colorBackground[] = {"(profilenamespace getvariable ['GUI_BCG_RGB_R',0.3843])","(profilenamespace getvariable ['GUI_BCG_RGB_G',0.7019])","(profilenamespace getvariable ['GUI_BCG_RGB_B',0.8862])","(profilenamespace getvariable ['GUI_BCG_RGB_A',0.7])"};
		};
		class MainBG: IGUIBack
		{
			idc = 11;

			x = 0.334959 * safezoneW + safezoneX;
			y = 0.4296 * safezoneH + safezoneY;
			w = 0.319767 * safezoneW;
			h = 0.0704 * safezoneH;
			colorBackground[] = {0,0,0,0.7};
		};
	};
	class controls {
		class MainText: RscText
		{
			idc = 20;

			text = "Epoch Group Menu";
			x = 0.333927 * safezoneW + safezoneX;
			y = 0.4076 * safezoneH + safezoneY;
			w = 0.128939 * safezoneW;
			h = 0.022 * safezoneH;
		};
		class GroupName: RscEdit
		{
			idc = 21;
			onKeyDown = "_this call EPOCH_cGroup_groupText";
			x = 0.392723 * safezoneW + safezoneX;
			y = 0.4384 * safezoneH + safezoneY;
			w = 0.192892 * safezoneW;
			h = 0.022 * safezoneH;
		};
		class InfoText: RscText
		{
			idc = 22;

			text = ""; //Dynamic, check onLoad!
			x = 0.340116 * safezoneW + safezoneX;
			y = 0.467 * safezoneH + safezoneY;
			w = 0.245499 * safezoneW;
			h = 0.022 * safezoneH;
		};
		class GroupNameText: RscText
		{
			idc = 23;
			text = "Groupname:";
			x = 0.340116 * safezoneW + safezoneX;
			y = 0.4362 * safezoneH + safezoneY;
			w = 0.0515754 * safezoneW;
			h = 0.022 * safezoneH;
		};
		class BtnCreateGroup: RscButton
		{
			idc = 30;

			text = "Create Group";
			action = "call EPOCH_cGroup_BtnCreate";
			x = 0.588297 * safezoneW + safezoneX;
			y = 0.43686 * safezoneH + safezoneY;
			w = 0.0618905 * safezoneW;
			h = 0.022 * safezoneH;
		};
		class BtnClose: RscButton
		{
			idc = 31;
			action = "closeDialog 0";
			text = "Close";
			x = 0.588297 * safezoneW + safezoneX;
			y = 0.4681 * safezoneH + safezoneY;
			w = 0.0619394 * safezoneW;
			h = 0.0221111 * safezoneH;
		};
	};
};
class Epoch_myGroup {
	idd = -1300;
	movingEnable = 0;
	enableSimulation = 1;
	onLoad = "[] spawn { waitUntil {!isNull (findDisplay -1300)};_this call EPOCH_Group_onLoad}";
	class controlsBackground {
		class TopBG: IGUIBack
		{
			idc = 10;

			x = 0.334649 * safezoneW + safezoneX;
			y = 0.3174 * safezoneH + safezoneY;
			w = 0.319769 * safezoneW;
			h = 0.022 * safezoneH;
			colorBackground[] = {"(profilenamespace getvariable ['GUI_BCG_RGB_R',0.3843])","(profilenamespace getvariable ['GUI_BCG_RGB_G',0.7019])","(profilenamespace getvariable ['GUI_BCG_RGB_B',0.8862])","(profilenamespace getvariable ['GUI_BCG_RGB_A',0.7])"};
		};
		class MainBG: IGUIBack
		{
			idc = 11;

			x = 0.334959 * safezoneW + safezoneX;
			y = 0.3394 * safezoneH + safezoneY;
			w = 0.319767 * safezoneW;
			h = 0.319 * safezoneH;
			colorBackground[] = {0,0,0,0.7};
		};
	};
	class controls {
		class MainText: RscText
		{
			idc = 20;

			text = "Epoch Group Menu";
			x = 0.334959 * safezoneW + safezoneX;
			y = 0.3174 * safezoneH + safezoneY;
			w = 0.128939 * safezoneW;
			h = 0.022 * safezoneH;
		};
		class GroupNameText: RscText
		{
			idc = 21;

			text = "Groupname:";
			x = 0.341149 * safezoneW + safezoneX;
			y = 0.3526 * safezoneH + safezoneY;
			w = 0.307403 * safezoneW;
			h = 0.022 * safezoneH;
		};
		class InviteText: RscText
		{
			idc = 22;

			text = "Invite Player";
			x = 0.494843 * safezoneW + safezoneX;
			y = 0.3966 * safezoneH + safezoneY;
			w = 0.153712 * safezoneW;
			h = 0.022 * safezoneH;
		};
		class BtnInvite: RscButton
		{
			idc = 30;

			text = "";
			action = "call EPOCH_Group_BtnInvite";
			x = 0.492783 * safezoneW + safezoneX;
			y = 0.5968 * safezoneH + safezoneY;
			w = 0.157841 * safezoneW;
			h = 0.022 * safezoneH;
		};
		class BtnClose: RscButton
		{
			idc = 34;
			action = "closeDialog 0";

			text = "Close";
			x = 0.574269 * safezoneW + safezoneX;
			y = 0.6276 * safezoneH + safezoneY;
			w = 0.075349 * safezoneW;
			h = 0.0221111 * safezoneH;
		};
		class BtnSetMod: RscButton
		{
			idc = 32;

			text = "Set Mod";
			tooltip = "Moderators can Invite or Kick Groupmember but can't set other player to Moderator";
			action = "call EPOCH_Group_BtnMod";
			x = 0.417476 * safezoneW + safezoneX;
			y = 0.6276 * safezoneH + safezoneY;
			w = 0.0701425 * safezoneW;
			h = 0.022 * safezoneH;
		};
		class BtnKick: RscButton
		{
			idc = 33;

			text = "Kick Member";
			action = "call EPOCH_Group_BtnKick";
			x = 0.340116 * safezoneW + safezoneX;
			y = 0.6276 * safezoneH + safezoneY;
			w = 0.0701425 * safezoneW;
			h = 0.022 * safezoneH;
		};
		class BtnLeave: RscButton
		{
			idc = 31;
			text = "Leave Group";
			action = "call EPOCH_Group_BtnLeave";
			x = 0.492779 * safezoneW + safezoneX;
			y = 0.6276 * safezoneH + safezoneY;
			w = 0.075349 * safezoneW;
			h = 0.0221111 * safezoneH;
		};
		class GroupMemberList: RscListbox
		{
			idc = 40;
			onLBSelChanged = "_this call EPOCH_Group_List";
			x = 0.340116 * safezoneW + safezoneX;
			y = 0.3922 * safezoneH + safezoneY;
			w = 0.148556 * safezoneW;
			h = 0.2266 * safezoneH;
		};
		class InvitePlayerCombo: RscCombo
		{
			idc = 41;
			onLBSelChanged = "_this call EPOCH_Group_Combo";
			x = 0.492779 * safezoneW + safezoneX;
			y = 0.4296 * safezoneH + safezoneY;
			w = 0.156793 * safezoneW;
			h = 0.022 * safezoneH;
		};
	};
};

class Epoch_GroupInvite {
	idd = -1400;
	movingEnable = 0;
	enableSimulation = 1;
	onLoad = "[] spawn { waitUntil {!isNull (findDisplay -1400)};_this call EPOCH_iGroup_onLoad}";
	class controlsBackground {
		class TopBG: IGUIBack
		{
			idc = 10;

			x = 0.334649 * safezoneW + safezoneX;
			y = 0.4076 * safezoneH + safezoneY;
			w = 0.319769 * safezoneW;
			h = 0.022 * safezoneH;
			colorBackground[] = {"(profilenamespace getvariable ['GUI_BCG_RGB_R',0.3843])","(profilenamespace getvariable ['GUI_BCG_RGB_G',0.7019])","(profilenamespace getvariable ['GUI_BCG_RGB_B',0.8862])","(profilenamespace getvariable ['GUI_BCG_RGB_A',0.7])"};
		};
		class MainBG: IGUIBack
		{
			idc = 11;

			x = 0.334959 * safezoneW + safezoneX;
			y = 0.4296 * safezoneH + safezoneY;
			w = 0.319767 * safezoneW;
			h = 0.1056 * safezoneH;
			colorBackground[] = {0,0,0,0.7};
		};
	};
	class controls {
		class MainText: RscText
		{
			idc = 20;

			text = "Epoch Group Menu";
			x = 0.333927 * safezoneW + safezoneX;
			y = 0.4076 * safezoneH + safezoneY;
			w = 0.128939 * safezoneW;
			h = 0.022 * safezoneH;
		};
		class InfoText: RscText
		{
			idc = 21;
			text = "";
			x = 0.340116 * safezoneW + safezoneX;
			y = 0.4384 * safezoneH + safezoneY;
			w = 0.309452 * safezoneW;
			h = 0.0594 * safezoneH;
		};
		class BtnAccept: RscButton
		{
			idc = 30;
			action = "call EPOCH_iGroup_acceptInvite";

			text = "Accept Invite";
			x = 0.432952 * safezoneW + safezoneX;
			y = 0.5066 * safezoneH + safezoneY;
			w = 0.0618905 * safezoneW;
			h = 0.022 * safezoneH;
		};
		class BtnRefuse: RscButton
		{
			idc = 31;
			action = "Epoch_invited_GroupUID = """";Epoch_invited_GroupName = """"; closeDialog 0"; //Should work but not sure about the script scope

			text = "Refuse Invite";
			x = 0.505158 * safezoneW + safezoneX;
			y = 0.5066 * safezoneH + safezoneY;
			w = 0.0619394 * safezoneW;
			h = 0.0221111 * safezoneH;
		};
	};
};
class SKN_RscShortcutButton {
	idc = -1;
	style = 0;
	default = 0;
	shadow = 1;
	w = 0.183825;
	h = "(		(		((safezoneW / safezoneH) min 1.2) / 1.2) / 20)";
	color[] = {1,1,1,1.0};
	colorFocused[] = {1,1,1,1.0};
	color2[] = {0.95,0.95,0.95,1};
	colorDisabled[] = {1,1,1,0.25};
	colorBackground[] = {"(profilenamespace getvariable ['GUI_BCG_RGB_R',0.69])","(profilenamespace getvariable ['GUI_BCG_RGB_G',0.75])","(profilenamespace getvariable ['GUI_BCG_RGB_B',0.5])",1};
	colorBackgroundFocused[] = {"(profilenamespace getvariable ['GUI_BCG_RGB_R',0.69])","(profilenamespace getvariable ['GUI_BCG_RGB_G',0.75])","(profilenamespace getvariable ['GUI_BCG_RGB_B',0.5])",1};
	colorBackground2[] = {1,1,1,1};
	animTextureDefault = "\A3\ui_f\data\GUI\RscCommon\RscShortcutButton\normal_ca.paa";
	animTextureNormal = "\A3\ui_f\data\GUI\RscCommon\RscShortcutButton\normal_ca.paa";
	animTextureDisabled = "\A3\ui_f\data\GUI\RscCommon\RscShortcutButton\normal_ca.paa";
	animTextureOver = "\A3\ui_f\data\GUI\RscCommon\RscShortcutButton\over_ca.paa";
	animTextureFocused = "\A3\ui_f\data\GUI\RscCommon\RscShortcutButton\focus_ca.paa";
	animTexturePressed = "\A3\ui_f\data\GUI\RscCommon\RscShortcutButton\down_ca.paa";
	periodFocus = 1.2;
	periodOver = 0.8;
	class HitZone
	{
		left = 0.0;
		top = 0.0;
		right = 0.0;
		bottom = 0.0;
	};
	class ShortcutPos
	{
		left = 0;
		top = "(			(		(		((safezoneW / safezoneH) min 1.2) / 1.2) / 20) - 		(			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 1)) / 2";
		w = "(			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 1) * (3/4)";
		h = "(			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 1)";
	};
	class TextPos
	{
		left = "(			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 1) * (3/4)";
		top = "(			(		(		((safezoneW / safezoneH) min 1.2) / 1.2) / 20) - 		(			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 1)) / 2";
		right = 0.005;
		bottom = 0.0;
	};
	period = 0.4;
	font = "PuristaMedium";
	size = "(			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 1)";
	sizeEx = "(			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 1)";
	text = "";
	soundEnter[] = {"\A3\ui_f\data\sound\RscButton\soundEnter",0.09,1};
	soundPush[] = {"\A3\ui_f\data\sound\RscButton\soundPush",0.09,1};
	soundClick[] = {"\A3\ui_f\data\sound\RscButton\soundClick",0.09,1};
	soundEscape[] = {"\A3\ui_f\data\sound\RscButton\soundEscape",0.09,1};
	action = "";
	class Attributes
	{
		font = "PuristaMedium";
		color = "#E5E5E5";
		align = "left";
		shadow = "true";
	};
	class AttributesImage
	{
		font = "PuristaMedium";
		color = "#E5E5E5";
		align = "left";
	};
};

class SKN_RscButtonMenu : SKN_RscShortcutButton {
	idc = -1;
	type = 16;
	onButtonClick = "_this spawn Skaronator_fnc_handleButton;";
	style = "0x02 + 0xC0";
	default = 0;
	shadow = 0;
	x = 0;
	y = 0;
	w = 0.095589;
	h = 0.039216;
	animTextureNormal = "#(argb,8,8,3)color(1,1,1,1)";
	animTextureDisabled = "#(argb,8,8,3)color(1,1,1,1)";
	animTextureOver = "#(argb,8,8,3)color(1,1,1,1)";
	animTextureFocused = "#(argb,8,8,3)color(1,1,1,1)";
	animTexturePressed = "#(argb,8,8,3)color(1,1,1,1)";
	animTextureDefault = "#(argb,8,8,3)color(1,1,1,1)";
	colorBackground[] = {0,0,0,0.8};
	colorBackgroundFocused[] = {1,1,1,1};
	colorBackground2[] = {0.75,0.75,0.75,1};
	color[] = {1,1,1,1};
	colorFocused[] = {0,0,0,1};
	color2[] = {0,0,0,1};
	colorText[] = {1,1,1,1};
	colorDisabled[] = {1,1,1,0.25};
	period = 0;
	periodFocus = 1.2;
	periodOver = 1.2;
	size = "(			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 1)";
	sizeEx = "(			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 1)";
	tooltipColorText[] = {1,1,1,1};
	tooltipColorBox[] = {1,1,1,1};
	tooltipColorShade[] = {0,0,0,0.65};
	class TextPos
	{
		left = "0.25 * 			(			((safezoneW / safezoneH) min 1.2) / 40)";
		top = "(			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) - 		(			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 1)) / 2";
		right = 0.005;
		bottom = 0.0;
	};
	class Attributes
	{
		font = "PuristaLight";
		color = "#E5E5E5";
		align = "left";
		shadow = "false";
	};
	class ShortcutPos
	{
		left = "(6.25 * 			(			((safezoneW / safezoneH) min 1.2) / 40)) - 0.0225 - 0.005";
		top = 0.005;
		w = 0.0225;
		h = 0.03;
	};
	soundEnter[] = {"\A3\ui_f\data\sound\RscButtonMenu\soundEnter",0.09,1};
	soundPush[] = {"\A3\ui_f\data\sound\RscButtonMenu\soundPush",0.09,1};
	soundClick[] = {"\A3\ui_f\data\sound\RscButtonMenu\soundClick",0.09,1};
	soundEscape[] = {"\A3\ui_f\data\sound\RscButtonMenu\soundEscape",0.09,1};
	textureNoShortcut = "";
};

class SKN_RscListBox
{
	access = 0;
	type = 5;
	w = 0.4;
	h = 0.4;
	rowHeight = 0;
	colorText[] = {1,1,1,1};
	colorDisabled[] = {1,1,1,0.25};
	colorScrollbar[] = {1,0,0,0};
	colorSelect[] = {0,0,0,1};
	colorSelect2[] = {0,0,0,1};
	colorSelectBackground[] = {1,1,1,0.25};
	colorSelectBackground2[] = {1,1,1,0.25};
	colorBackground[] = {0,0,0,0.25};
	colorPicture[] = { 1, 1, 1, 1 };
	colorPictureSelected[] = { 1, 1, 1, 1 };
	colorPictureDisabled[] = { 1, 1, 1, 1 };
	soundSelect[] = {"\A3\ui_f\data\sound\RscListbox\soundSelect",0.09,1};
	autoScrollSpeed = -1;
	autoScrollDelay = 5;
	autoScrollRewind = 0;
	arrowEmpty = "#(argb,8,8,3)color(1,1,1,1)";
	arrowFull = "#(argb,8,8,3)color(1,1,1,1)";
	class ListScrollBar: ScrollBar
	{
		color[] = {1,1,1,1};
		autoScrollEnabled = 1;
	};
	style = 16;
	font = "PuristaMedium";
	sizeEx = "(			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 1)";
	shadow = 0;
	colorShadow[] = {0,0,0,0.5};
	period = 0;
	maxHistoryDelay = 1;
	tooltipColorText[] = {1,1,1,1};
	tooltipColorBox[] = {1,1,1,1};
	tooltipColorShade[] = {0,0,0,0.65};
};

class SKN_RscListNBox
{
	style = 16;
	access = 0;
	type = 102;
	w = 0.4;
	h = 0.4;
	rowHeight = 0;
	colorText[] = {1,1,1,1};
	colorScrollbar[] = {0.95,0.95,0.95,1};
	colorSelect[] = {0,0,0,1};
	colorSelect2[] = {0,0,0,1};
	colorSelectBackground[] = {0.95,0.95,0.95,1};
	colorSelectBackground2[] = {1,1,1,0.5};
	colorBackground[] = {0,0,0,1};
	colorPicture[] = { 1, 1, 1, 1 };
	colorPictureSelected[] = { 1, 1, 1, 1 };
	colorPictureDisabled[] = { 1, 1, 1, 1 };
	maxHistoryDelay = 1;
	soundSelect[] = {"",0.1,1};
	autoScrollSpeed = -1;
	autoScrollDelay = 5;
	autoScrollRewind = 0;
	arrowEmpty = "#(argb,8,8,3)color(1,1,1,1)";
	arrowFull = "#(argb,8,8,3)color(1,1,1,1)";
	drawSideArrows = 0;
	columns[] = {0, 0.06,0.2,0.26};
	idcLeft = -1;
	idcRight = -1;
	class ListScrollBar: ScrollBar{};
	shadow = 0;
	font = "PuristaMedium";
	sizeEx = "(			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 1)";
	color[] = {0.95,0.95,0.95,1};
	colorDisabled[] = {1,1,1,0.25};
	period = 1.2;
	class ScrollBar: ScrollBar{	};
};

class SKN_RscMapControl
{
	access = 0;
	type = 101;
	idc = 51;
	style = 48;
	colorBackground[] = {0.969,0.957,0.949,1};
	colorOutside[] = {0,0,0,1};
	colorText[] = {0,0,0,1};
	font = "TahomaB";
	sizeEx = 0.04;
	colorSea[] = {0.467,0.631,0.851,0.5};
	colorForest[] = {0.624,0.78,0.388,0.5};
	colorRocks[] = {0,0,0,0.3};
	colorCountlines[] = {0.572,0.354,0.188,0.25};
	colorMainCountlines[] = {0.572,0.354,0.188,0.5};
	colorCountlinesWater[] = {0.491,0.577,0.702,0.3};
	colorMainCountlinesWater[] = {0.491,0.577,0.702,0.6};
	colorForestBorder[] = {0,0,0,0};
	colorRocksBorder[] = {0,0,0,0};
	colorPowerLines[] = {0.1,0.1,0.1,1};
	colorRailWay[] = {0.8,0.2,0,1};
	colorNames[] = {0.1,0.1,0.1,0.9};
	colorInactive[] = {1,1,1,0.5};
	colorLevels[] = {0.286,0.177,0.094,0.5};
	colorTracks[] = {0.84,0.76,0.65,0.15};
	colorRoads[] = {0.7,0.7,0.7,1};
	colorMainRoads[] = {0.9,0.5,0.3,1};
	colorTracksFill[] = {0.84,0.76,0.65,1};
	colorRoadsFill[] = {1,1,1,1};
	colorMainRoadsFill[] = {1,0.6,0.4,1};
	colorGrid[] = {0.1,0.1,0.1,0.6};
	colorGridMap[] = {0.1,0.1,0.1,0.6};
	stickX[] = {0.2,{"Gamma",1,1.5}};
	stickY[] = {0.2,{"Gamma",1,1.5}};
	moveOnEdges = 0;//1;
	x = "SafeZoneXAbs";
	y = "SafeZoneY + 1.5 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
	w = "SafeZoneWAbs";
	h = "SafeZoneH - 1.5 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
	shadow = 0;
	ptsPerSquareSea = 5;
	ptsPerSquareTxt = 3;
	ptsPerSquareCLn = 10;
	ptsPerSquareExp = 10;
	ptsPerSquareCost = 10;
	ptsPerSquareFor = 9;
	ptsPerSquareForEdge = 9;
	ptsPerSquareRoad = 6;
	ptsPerSquareObj = 9;
	showCountourInterval = 0;
	scaleMin = 0.001;
	scaleMax = 1.9; //Default: 1
	scaleDefault = 0.2;
	maxSatelliteAlpha = 0.85;
	//alphaFadeStartScale = 0.35;
	//alphaFadeEndScale = 0.4;
	alphaFadeStartScale = 1.9;
	alphaFadeEndScale = 2;
	fontLabel = "PuristaMedium";
	sizeExLabel = "(			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 0.8)";
	fontGrid = "TahomaB";
	sizeExGrid = 0.02;
	fontUnits = "TahomaB";
	sizeExUnits = "(			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 0.8)";
	fontNames = "PuristaMedium";
	sizeExNames = "(			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 0.8) * 2";
	fontInfo = "PuristaMedium";
	sizeExInfo = "(			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 0.8)";
	fontLevel = "TahomaB";
	sizeExLevel = 0.02;
	text = "#(argb,8,8,3)color(1,1,1,1)";
	//text = "\a3\ui_f\data\map_background2_co.paa";
	class Legend
	{
		colorBackground[] = {1,1,1,0.5};
		color[] = {0,0,0,1};
		x = "SafeZoneX + 					(			((safezoneW / safezoneH) min 1.2) / 40)";
		y = "SafeZoneY + safezoneH - 4.5 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
		w = "10 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
		h = "3.5 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
		font = "PuristaMedium";
		sizeEx = "(			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 0.8)";
	};
	class ActiveMarker
	{
		color[] = {0.3,0.1,0.9,1};
		size = 50;
	};
	class Command
	{
		color[] = {1,1,1,1};
		icon = "\A3\ui_f\data\map\mapcontrol\waypoint_ca.paa";
		size = 18;
		importance = 1;
		coefMin = 1;
		coefMax = 1;
	};
	class Task
	{
		colorCreated[] = {1,1,1,1};
		colorCanceled[] = {0.7,0.7,0.7,1};
		colorDone[] = {0.7,1,0.3,1};
		colorFailed[] = {1,0.3,0.2,1};
		color[] = {"(profilenamespace getvariable ['IGUI_TEXT_RGB_R',0])","(profilenamespace getvariable ['IGUI_TEXT_RGB_G',1])","(profilenamespace getvariable ['IGUI_TEXT_RGB_B',1])","(profilenamespace getvariable ['IGUI_TEXT_RGB_A',0.8])"};
		icon = "\A3\ui_f\data\map\mapcontrol\taskIcon_CA.paa";
		iconCreated = "\A3\ui_f\data\map\mapcontrol\taskIconCreated_CA.paa";
		iconCanceled = "\A3\ui_f\data\map\mapcontrol\taskIconCanceled_CA.paa";
		iconDone = "\A3\ui_f\data\map\mapcontrol\taskIconDone_CA.paa";
		iconFailed = "\A3\ui_f\data\map\mapcontrol\taskIconFailed_CA.paa";
		size = 27;
		importance = 1;
		coefMin = 1;
		coefMax = 1;
	};
	class CustomMark
	{
		color[] = {0,0,0,1};
		icon = "\A3\ui_f\data\map\mapcontrol\custommark_ca.paa";
		size = 24;
		importance = 1;
		coefMin = 1;
		coefMax = 1;
	};
	class Tree
	{
		color[] = {0.45,0.64,0.33,0.4};
		icon = "\A3\ui_f\data\map\mapcontrol\bush_ca.paa";
		size = 12;
		importance = "0.9 * 16 * 0.05";
		coefMin = 0.25;
		coefMax = 4;
	};
	class SmallTree
	{
		color[] = {0.45,0.64,0.33,0.4};
		icon = "\A3\ui_f\data\map\mapcontrol\bush_ca.paa";
		size = 12;
		importance = "0.6 * 12 * 0.05";
		coefMin = 0.25;
		coefMax = 4;
	};
	class Bush
	{
		color[] = {0.45,0.64,0.33,0.4};
		icon = "\A3\ui_f\data\map\mapcontrol\bush_ca.paa";
		size = "14/2";
		importance = "0.2 * 14 * 0.05 * 0.05";
		coefMin = 0.25;
		coefMax = 4;
	};
	class Church
	{
		color[] = {1,1,1,1};
		icon = "\A3\ui_f\data\map\mapcontrol\church_CA.paa";
		size = 24;
		importance = 1;
		coefMin = 0.85;
		coefMax = 1;
	};
	class Chapel
	{
		color[] = {0,0,0,1};
		icon = "\A3\ui_f\data\map\mapcontrol\Chapel_CA.paa";
		size = 24;
		importance = 1;
		coefMin = 0.85;
		coefMax = 1;
	};
	class Cross
	{
		color[] = {0,0,0,1};
		icon = "\A3\ui_f\data\map\mapcontrol\Cross_CA.paa";
		size = 24;
		importance = 1;
		coefMin = 0.85;
		coefMax = 1;
	};
	class Rock
	{
		color[] = {0.1,0.1,0.1,0.8};
		icon = "\A3\ui_f\data\map\mapcontrol\rock_ca.paa";
		size = 12;
		importance = "0.5 * 12 * 0.05";
		coefMin = 0.25;
		coefMax = 4;
	};
	class Bunker
	{
		color[] = {0,0,0,1};
		icon = "\A3\ui_f\data\map\mapcontrol\bunker_ca.paa";
		size = 14;
		importance = "1.5 * 14 * 0.05";
		coefMin = 0.25;
		coefMax = 4;
	};
	class Fortress
	{
		color[] = {0,0,0,1};
		icon = "\A3\ui_f\data\map\mapcontrol\bunker_ca.paa";
		size = 16;
		importance = "2 * 16 * 0.05";
		coefMin = 0.25;
		coefMax = 4;
	};
	class Fountain
	{
		color[] = {0,0,0,1};
		icon = "\A3\ui_f\data\map\mapcontrol\fountain_ca.paa";
		size = 11;
		importance = "1 * 12 * 0.05";
		coefMin = 0.25;
		coefMax = 4;
	};
	class ViewTower
	{
		color[] = {0,0,0,1};
		icon = "\A3\ui_f\data\map\mapcontrol\viewtower_ca.paa";
		size = 16;
		importance = "2.5 * 16 * 0.05";
		coefMin = 0.5;
		coefMax = 4;
	};
	class Lighthouse
	{
		color[] = {1,1,1,1};
		icon = "\A3\ui_f\data\map\mapcontrol\lighthouse_CA.paa";
		size = 24;
		importance = 1;
		coefMin = 0.85;
		coefMax = 1;
	};
	class Quay
	{
		color[] = {1,1,1,1};
		icon = "\A3\ui_f\data\map\mapcontrol\quay_CA.paa";
		size = 24;
		importance = 1;
		coefMin = 0.85;
		coefMax = 1;
	};
	class Fuelstation
	{
		color[] = {1,1,1,1};
		icon = "\A3\ui_f\data\map\mapcontrol\fuelstation_CA.paa";
		size = 24;
		importance = 1;
		coefMin = 0.85;
		coefMax = 1;
	};
	class Hospital
	{
		color[] = {1,1,1,1};
		icon = "\A3\ui_f\data\map\mapcontrol\hospital_CA.paa";
		size = 24;
		importance = 1;
		coefMin = 0.85;
		coefMax = 1;
	};
	class BusStop
	{
		color[] = {1,1,1,1};
		icon = "\A3\ui_f\data\map\mapcontrol\busstop_CA.paa";
		size = 24;
		importance = 1;
		coefMin = 0.85;
		coefMax = 1;
	};
	class Transmitter
	{
		color[] = {1,1,1,1};
		icon = "\A3\ui_f\data\map\mapcontrol\transmitter_CA.paa";
		size = 24;
		importance = 1;
		coefMin = 0.85;
		coefMax = 1;
	};
	class Stack
	{
		color[] = {0,0,0,1};
		icon = "\A3\ui_f\data\map\mapcontrol\stack_ca.paa";
		size = 20;
		importance = "2 * 16 * 0.05";
		coefMin = 0.9;
		coefMax = 4;
	};
	class Ruin
	{
		color[] = {0,0,0,1};
		icon = "\A3\ui_f\data\map\mapcontrol\ruin_ca.paa";
		size = 16;
		importance = "1.2 * 16 * 0.05";
		coefMin = 1;
		coefMax = 4;
	};
	class Tourism
	{
		color[] = {0,0,0,1};
		icon = "\A3\ui_f\data\map\mapcontrol\tourism_ca.paa";
		size = 16;
		importance = "1 * 16 * 0.05";
		coefMin = 0.7;
		coefMax = 4;
	};
	class Watertower
	{
		color[] = {1,1,1,1};
		icon = "\A3\ui_f\data\map\mapcontrol\watertower_CA.paa";
		size = 24;
		importance = 1;
		coefMin = 0.85;
		coefMax = 1;
	};
	class Waypoint
	{
		color[] = {0,0,0,1};
		size = 24;
		importance = 1;
		coefMin = 1;
		coefMax = 1;
		icon = "\A3\ui_f\data\map\mapcontrol\waypoint_ca.paa";
	};
	class WaypointCompleted
	{
		color[] = {0,0,0,1};
		size = 24;
		importance = 1;
		coefMin = 1;
		coefMax = 1;
		icon = "\A3\ui_f\data\map\mapcontrol\waypointCompleted_ca.paa";
	};
	class power
	{
		icon = "\A3\ui_f\data\map\mapcontrol\power_CA.paa";
		size = 24;
		importance = 1;
		coefMin = 0.85;
		coefMax = 1;
		color[] = {1,1,1,1};
	};
	class powersolar
	{
		icon = "\A3\ui_f\data\map\mapcontrol\powersolar_CA.paa";
		size = 24;
		importance = 1;
		coefMin = 0.85;
		coefMax = 1;
		color[] = {1,1,1,1};
	};
	class powerwave
	{
		icon = "\A3\ui_f\data\map\mapcontrol\powerwave_CA.paa";
		size = 24;
		importance = 1;
		coefMin = 0.85;
		coefMax = 1;
		color[] = {1,1,1,1};
	};
	class powerwind
	{
		icon = "\A3\ui_f\data\map\mapcontrol\powerwind_CA.paa";
		size = 24;
		importance = 1;
		coefMin = 0.85;
		coefMax = 1;
		color[] = {1,1,1,1};
	};
	class shipwreck
	{
		icon = "\A3\ui_f\data\map\mapcontrol\shipwreck_CA.paa";
		size = 24;
		importance = 1;
		coefMin = 0.85;
		coefMax = 1;
		color[] = {1,1,1,1};
	};
};

class Skaronator_AdminMenu
{
	idd = -1337;
	onload = "setMousePosition [0.5, 0.5];";
	// onLoad = "[] spawn {disableSerialization;waitUntil {!isNull (findDisplay -1337)};_e0=findDisplay -1337;_e1=_e0 displayCtrl 10;_e2=_e0 displayCtrl 11;_e3=_e0 displayCtrl 20;_e4=_e0 displayCtrl 21;_e5=_e0 displayCtrl 22;_e6=_e0 displayCtrl 1;_sw=safezoneW;_sx=safezoneX;_sy=safezoneY;_sh=safezoneH;waitUntil {_e7=toArray(ctrlText 2);_e7 resize 38;if (ctrlText _e1!='Range'||ctrlText _e2!='Alphabet'||ctrlText _e3!='Main Menu'||ctrlText _e4!='Spawn Menu'||ctrlText _e5!='Server Menu'||!ctrlShown _e1||!ctrlShown _e2||!ctrlShown _e3||!ctrlShown _e4||!ctrlShown _e5||!ctrlShown _e6||!(ctrlPosition _e1 isEqualTo[0.180954*_sw+_sx,0.25844*_sh+_sy,0.0526068*_sw,0.022*_sh])||!(ctrlPosition _e2 isEqualTo[0.236966*_sw+_sx,0.258*_sh+_sy,0.0536383*_sw,0.022*_sh])||!(ctrlPosition _e3 isEqualTo[0.296277*_sw+_sx,0.258*_sh+_sy,0.0649849*_sw,0.022*_sh])||!(ctrlPosition _e4 isEqualTo[0.364253*_sw+_sx,0.258*_sh+_sy,0.0649849*_sw,0.022*_sh])||!(ctrlPosition _e5 isEqualTo[0.431714*_sw+_sx,0.258*_sh+_sy,0.0649849*_sw,0.022*_sh])||!(ctrlPosition _e6 isEqualTo[0.179201*_sw+_sx,0.225*_sh+_sy,0.113573*_sw,0.0242*_sh])||!(_e7 isEqualTo[69,112,111,99,104,32,77,111,100,32,65,100,109,105,110,32,77,101,110,117,32,98,121,32,83,107,97,114,111,110,97,116,111,114,46,99,111,109])) exitWith {if (!isNull (findDisplay -1337)) then {(findDisplay -1337) closeDisplay 0;true}};uiSleep 0.2;isNull (findDisplay -1337)}}";
	onUnload = "";
	movingEnable = 1;
	class Controls {
		class PlayerBar: RscText
		{
			idc = 1;
			x = 0.179201 * safezoneW + safezoneX;
			y = 0.225 * safezoneH + safezoneY;
			w = 0.113573 * safezoneW;
			h = 0.0242 * safezoneH;
			colorBackground[] = {0.78,0.37,0,1};
			colorActive[] = {0.78,0.37,0,1};
		};
		class MainBar: RscText
		{
			idc = 2;
			text = "Epoch Mod Admin Menu by Skaronator.com";
			x = 0.293698 * safezoneW + safezoneX;
			y = 0.225 * safezoneH + safezoneY;
			w = 0.412705 * safezoneW;
			h = 0.0242 * safezoneH;
			colorBackground[] = {0.78,0.37,0,1};
			colorActive[] = {0.78,0.37,0,1};
		};
		class PlayerBtnBackground: IGUIBack
		{
			idc = 3;
			x = 0.178995 * safezoneW + safezoneX;
			y = 0.25206 * safezoneH + safezoneY;
			w = 0.113466 * safezoneW;
			h = 0.0352 * safezoneH;
			colorBackground[] = {0,0,0,0.75};
			colorActive[] = {0,0,0,0.75};
		};
		class BtnMainBackground: IGUIBack
		{
			idc = 4;
			x = 0.293698 * safezoneW + safezoneX;
			y = 0.2514 * safezoneH + safezoneY;
			w = 0.412629 * safezoneW;
			h = 0.0352 * safezoneH;
			colorBackground[] = {0,0,0,0.75};
			colorActive[] = {0,0,0,0.75};
		};
		class PlayerList: SKN_RscListBox
		{
			idc = 5;
			sizeEx = 0.035;
			x = 0.179201 * safezoneW + safezoneX;
			y = 0.2888 * safezoneH + safezoneY;
			w = 0.113466 * safezoneW;
			h = 0.4862 * safezoneH;
			colorBackground[] = {0,0,0,0.75};
			colorActive[] = {0,0,0,0.75};
		};
		class MainList: SKN_RscListBox
		{
			idc = 6;
			sizeEx = 0.035;
			x = 0.293698 * safezoneW + safezoneX;
			y = 0.2888 * safezoneH + safezoneY;
			w = 0.206297 * safezoneW;
			h = 0.4862 * safezoneH;
			colorBackground[] = {0,0,0,0.75};
			colorActive[] = {0,0,0,0.75};
		};
		class BtnRange: SKN_RscButtonMenu
		{
			idc = 10;
			size = 0.037;

			text = "Range";
			x = 0.180954 * safezoneW + safezoneX;
			y = 0.25844 * safezoneH + safezoneY;
			w = 0.0526068 * safezoneW;
			h = 0.022 * safezoneH;
			colorText[] = {1,1,1,1};
			colorBackground[] = {0,0,0,0.9};
			colorActive[] = {0,0,0,0.9};
		};
		class BtnAlphabet: SKN_RscButtonMenu
		{
			idc = 11;
			size = 0.037;

			text = "Alphabet";
			x = 0.236966 * safezoneW + safezoneX;
			y = 0.258 * safezoneH + safezoneY;
			w = 0.0536383 * safezoneW;
			h = 0.022 * safezoneH;
			colorText[] = {1,1,1,1};
			colorBackground[] = {0,0,0,0.9};
			colorActive[] = {0,0,0,0.9};
		};
		class BtnMainMenu: SKN_RscButtonMenu
		{
			idc = 20;
			size = 0.037;

			text = "Main Menu";
			x = 0.296277 * safezoneW + safezoneX;
			y = 0.258 * safezoneH + safezoneY;
			w = 0.0649849 * safezoneW;
			h = 0.022 * safezoneH;
			colorText[] = {1,1,1,1};
			colorBackground[] = {0,0,0,0.9};
			colorActive[] = {0,0,0,0.9};
		};
		class BtnSpawnMenu: SKN_RscButtonMenu
		{
			idc = 21;
			size = 0.037;

			text = "Spawn Menu";
			x = 0.364253 * safezoneW + safezoneX;
			y = 0.258 * safezoneH + safezoneY;
			w = 0.0649849 * safezoneW;
			h = 0.022 * safezoneH;
			colorText[] = {1,1,1,1};
			colorBackground[] = {0,0,0,0.9};
			colorActive[] = {0,0,0,0.9};
		};
		class BtnServerMenu: SKN_RscButtonMenu
		{
			idc = 22;
			size = 0.037;

			text = "Server Menu";
			x = 0.431714 * safezoneW + safezoneX;
			y = 0.258 * safezoneH + safezoneY;
			w = 0.0649849 * safezoneW;
			h = 0.022 * safezoneH;
			colorText[] = {1,1,1,1};
			colorBackground[] = {0,0,0,0.9};
			colorActive[] = {0,0,0,0.9};
		};
		class BtnAntihackLog: SKN_RscButtonMenu
		{
			idc = 23;

			text = "Antihack Log (666)";
			x = 0.503094 * safezoneW + safezoneX;
			y = 0.258 * safezoneH + safezoneY;
			w = 0.0990245 * safezoneW;
			h = 0.022 * safezoneH;
			colorText[] = {1,1,1,1};
			colorBackground[] = {0,0,0,0.9};
			colorActive[] = {0,0,0,0.9};
		};
		class BtnAdminLog: SKN_RscButtonMenu
		{
			idc = 24;

			text = "Admin Log (666)";
			x = 0.605008 * safezoneW + safezoneX;
			y = 0.258 * safezoneH + safezoneY;
			w = 0.0979928 * safezoneW;
			h = 0.022 * safezoneH;
			colorText[] = {1,1,1,1};
			colorBackground[] = {0,0,0,0.9};
			colorActive[] = {0,0,0,0.9};
		};
		class BackgroundInputbox: IGUIBack
		{
			idc = 30;

			x = 0.501031 * safezoneW + safezoneX;
			y = 0.2888 * safezoneH + safezoneY;
			w = 0.205296 * safezoneW;
			h = 0.1276 * safezoneH;
			colorBackground[] = {0,0,0,0.75};
			colorActive[] = {0,0,0,0.75};
		};
		class RscText: RscText
		{
			idc = 34;
			text = "Ban reason for";
			x = 0.509283 * safezoneW + safezoneX;
			y = 0.3108 * safezoneH + safezoneY;
			w = 0.182603 * safezoneW;
			h = 0.0176 * safezoneH;
		};
		class RscInputBox: SKN_RscEdit
		{
			idc = 31;
			x = 0.513415 * safezoneW + safezoneX;
			y = 0.3438 * safezoneH + safezoneY;
			w = 0.161969 * safezoneW;
			h = 0.0198 * safezoneH;
		};
		class RscButtonMenuOK: SKN_RscButtonMenu
		{
			text = "OK";
			idc = 32;
			x = 0.639254 * safezoneW + safezoneX;
			y = 0.4186 * safezoneH + safezoneY;
			w = 0.067048 * safezoneW;
			h = 0.022 * safezoneH;
		};
		class RscButtonMenuCancel: SKN_RscButtonMenu
		{
			text = "CANCEL";
			idc = 33;
			x = 0.501031 * safezoneW + safezoneX;
			y = 0.4186 * safezoneH + safezoneY;
			w = 0.067048 * safezoneW;
			h = 0.022 * safezoneH;
		};
		class MapView: SKN_RscMapControl
		{
			idc = 7;
			x = 0.501031 * safezoneW + safezoneX;
			y = 0.28836 * safezoneH + safezoneY;
			w = 0.205265 * safezoneW;
			h = 0.486548 * safezoneH;
		};
		class MainListNBox: SKN_RscListNBox
		{
			idc = 8;
			sizeEx = 0.035;
			x = 0.293698 * safezoneW + safezoneX;
			y = 0.2888 * safezoneH + safezoneY;
			w = 0.206297 * safezoneW;
			h = 0.4862 * safezoneH;
			colorBackground[] = {0,0,0,0.75};
			colorActive[] = {0,0,0,0.75};
		};
		class BtnClear: SKN_RscButtonMenu
		{
			idc = 50;
			size = 0.037;

			text = "CLEAR";
			x = 0.504126 * safezoneW + safezoneX;
			y = 0.753 * safezoneH + safezoneY;
			w = 0.0361028 * safezoneW;
			h = 0.022 * safezoneH;
			colorText[] = {1,1,1,1};
			colorBackground[] = {0,0,0,0.9};
			colorActive[] = {0,0,0,0.9};
		};
		class BtnGiveTrgt: SKN_RscButtonMenu
		{
			idc = 51;
			size = 0.037;

			text = "Give to Target";
			x = 0.542292 * safezoneW + safezoneX;
			y = 0.7783 * safezoneH + safezoneY;
			w = 0.0804576 * safezoneW;
			h = 0.022 * safezoneH;
			colorText[] = {1,1,1,1};
			colorBackground[] = {0,0,0,0.9};
			colorActive[] = {0,0,0,0.9};
		};
		class BtnGiveMySelf: SKN_RscButtonMenu
		{
			idc = 52;
			size = 0.037;

			text = "GIVE TO SELF";
			x = 0.626257 * safezoneW + safezoneX;
			y = 0.7783 * safezoneH + safezoneY;
			w = 0.0804576 * safezoneW;
			h = 0.022 * safezoneH;
			colorText[] = {1,1,1,1};
			colorBackground[] = {0,0,0,0.9};
			colorActive[] = {0,0,0,0.9};
		};
		class LeftSide: RscText
		{
			idc = 40;

			text = "Available Items";
			x = 0.29473 * safezoneW + safezoneX;
			y = 0.291 * safezoneH + safezoneY;
			w = 0.164117 * safezoneW;
			h = 0.0242 * safezoneH;
			colorBackground[] = {0.78,0.37,0,1};
			colorActive[] = {0.78,0.37,0,1};
		};
		class ListBoxLeft: SKN_RscListBox
		{
			idc = 41;

			x = 0.294627 * safezoneW + safezoneX;
			y = 0.3174 * safezoneH + safezoneY;
			w = 0.16401 * safezoneW;
			h = 0.4576 * safezoneH;
			colorBackground[] = {0,0,0,0.75};
			colorActive[] = {0,0,0,0.75};
		};
		class RightSide: RscText
		{
			idc = 42;

			text = "Adding to Gear";
			x = 0.542292 * safezoneW + safezoneX;
			y = 0.291 * safezoneH + safezoneY;
			w = 0.164117 * safezoneW;
			h = 0.0242 * safezoneH;
			colorBackground[] = {0.78,0.37,0,1};
			colorActive[] = {0.78,0.37,0,1};
		};
		class ListBoxRight: SKN_RscListBox
		{
			idc = 43;

			x = 0.542292 * safezoneW + safezoneX;
			y = 0.31652 * safezoneH + safezoneY;
			w = 0.163892 * safezoneW;
			h = 0.458993 * safezoneH;
			colorBackground[] = {0,0,0,0.75};
			colorActive[] = {0,0,0,0.75};
		};
		class CenterTitle: RscText
		{
			idc = 60;

			text = "Categories";
			x = 0.46596 * safezoneW + safezoneX;
			y = 0.291 * safezoneH + safezoneY;
			w = 0.0670479 * safezoneW;
			h = 0.0242 * safezoneH;
			colorBackground[] = {0.78,0.37,0,1};
			colorActive[] = {0.78,0.37,0,1};
		};
		class BtnSpawnVehicleAir: SKN_RscButtonMenu
		{
			idc = 61;
			size = 0.037;

			text = "V: AIR";
			x = 0.46596 * safezoneW + safezoneX;
			y = 0.3196 * safezoneH + safezoneY;
			w = 0.0670479 * safezoneW;
			h = 0.022 * safezoneH;
			colorText[] = {1,1,1,1};
			colorBackground[] = {0,0,0,0.9};
			colorActive[] = {0,0,0,0.9};
		};
		class BtnSpawnVehicleLand: SKN_RscButtonMenu
		{
			idc = 62;
			size = 0.037;

			text = "V: LAND";
			x = 0.46596 * safezoneW + safezoneX;
			y = 0.346 * safezoneH + safezoneY;
			w = 0.0670479 * safezoneW;
			h = 0.022 * safezoneH;
			colorText[] = {1,1,1,1};
			colorBackground[] = {0,0,0,0.9};
			colorActive[] = {0,0,0,0.9};
		};
		class BtnSpawnVehicleShip: SKN_RscButtonMenu
		{
			idc = 63;
			size = 0.037;

			text = "V: SHIP";
			x = 0.46596 * safezoneW + safezoneX;
			y = 0.3724 * safezoneH + safezoneY;
			w = 0.0670479 * safezoneW;
			h = 0.022 * safezoneH;
			colorText[] = {1,1,1,1};
			colorBackground[] = {0,0,0,0.9};
			colorActive[] = {0,0,0,0.9};
		};
		class BtnSpawnWeapons: SKN_RscButtonMenu
		{
			idc = 64;
			size = 0.037;

			text = "WEAPONS";
			x = 0.46596 * safezoneW + safezoneX;
			y = 0.3988 * safezoneH + safezoneY;
			w = 0.0670479 * safezoneW;
			h = 0.022 * safezoneH;
			colorText[] = {1,1,1,1};
			colorBackground[] = {0,0,0,0.9};
			colorActive[] = {0,0,0,0.9};
		};
		class BtnSpawnMagazines: SKN_RscButtonMenu
		{
			idc = 65;
			size = 0.037;

			text = "MAGAZINES";
			x = 0.46596 * safezoneW + safezoneX;
			y = 0.4252 * safezoneH + safezoneY;
			w = 0.0670479 * safezoneW;
			h = 0.022 * safezoneH;
			colorText[] = {1,1,1,1};
			colorBackground[] = {0,0,0,0.9};
			colorActive[] = {0,0,0,0.9};
		};
		class BtnSpawnItems: SKN_RscButtonMenu
		{
			idc = 66;
			size = 0.037;

			text = "ITEMS";
			x = 0.46596 * safezoneW + safezoneX;
			y = 0.4516 * safezoneH + safezoneY;
			w = 0.0670479 * safezoneW;
			h = 0.022 * safezoneH;
			colorText[] = {1,1,1,1};
			colorBackground[] = {0,0,0,0.9};
			colorActive[] = {0,0,0,0.9};
		};
		class BtnSpawnBackpacks: SKN_RscButtonMenu
		{
			idc = 67;
			size = 0.037;

			text = "BACKPACKS";
			x = 0.46596 * safezoneW + safezoneX;
			y = 0.478 * safezoneH + safezoneY;
			w = 0.0670479 * safezoneW;
			h = 0.022 * safezoneH;
			colorText[] = {1,1,1,1};
			colorBackground[] = {0,0,0,0.9};
			colorActive[] = {0,0,0,0.9};
		};
		class BtnSpawnUniforms: SKN_RscButtonMenu
		{
			idc = 68;
			size = 0.037;

			text = "UNIFORMS";
			x = 0.46596 * safezoneW + safezoneX;
			y = 0.5044 * safezoneH + safezoneY;
			w = 0.0670479 * safezoneW;
			h = 0.022 * safezoneH;
			colorText[] = {1,1,1,1};
			colorBackground[] = {0,0,0,0.9};
			colorActive[] = {0,0,0,0.9};
		};
		class BtnSpawnAttachments: SKN_RscButtonMenu
		{
			idc = 69;
			size = 0.037;

			text = "ATTACHMENTS";
			x = 0.46596 * safezoneW + safezoneX;
			y = 0.5308 * safezoneH + safezoneY;
			w = 0.0670479 * safezoneW;
			h = 0.022 * safezoneH;
			colorText[] = {1,1,1,1};
			colorBackground[] = {0,0,0,0.9};
			colorActive[] = {0,0,0,0.9};
		};
		class BtnSpawnHeadGear : SKN_RscButtonMenu
		{
			idc = 70;
			size = 0.037;

			text = "HEADGEAR";
			x = 0.46596 * safezoneW + safezoneX;
			y = 0.5572 * safezoneH + safezoneY;
			w = 0.0670479 * safezoneW;
			h = 0.022 * safezoneH;
			colorText[] = { 1, 1, 1, 1 };
			colorBackground[] = { 0, 0, 0, 0.9 };
			colorActive[] = { 0, 0, 0, 0.9 };
		};
		class BtnSpawnVests : SKN_RscButtonMenu
		{
			idc = 71;
			size = 0.037;

			text = "VESTS";
			x = 0.46596 * safezoneW + safezoneX;
			y = 0.5836 * safezoneH + safezoneY;
			w = 0.0670479 * safezoneW;
			h = 0.022 * safezoneH;
			colorText[] = { 1, 1, 1, 1 };
			colorBackground[] = { 0, 0, 0, 0.9 };
			colorActive[] = { 0, 0, 0, 0.9 };
		};

	};
};
