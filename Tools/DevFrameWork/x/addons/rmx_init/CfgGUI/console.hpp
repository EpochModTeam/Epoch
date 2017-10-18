class dUI_console {
	idd = 9100;
	enableSimulation = 1;
	movingEnable = 1;
	class controls {

		class dUI_consoleFrame: RscFrame
		{
			idc = 9200;
			x = 0.00211241 * safezoneW + safezoneX;
			y = 0 * safezoneH + safezoneY;
			w = 0.244332 * safezoneW;
			h = 0.03 * safezoneH;
		};
		class dUI_console_text_plain_0: RscText
		{
			idc = 9201;
			text = "Info";
			x = 0.0699683 * safezoneW + safezoneX;
			y = 0 * safezoneH + safezoneY;
			w = 0.0216566 * safezoneW;
			h = 0.0286 * safezoneH;
		};
		class dUI_console_text_plain_1: RscText
		{
			idc = 9202;
			text = "Critical"; 
			x = 0.155556 * safezoneW + safezoneX;
			y = 0 * safezoneH + safezoneY;
			w = 0.0340316 * safezoneW;
			h = 0.0286 * safezoneH;
		};
		class dUI_console_text_plain_2: RscText
		{
			idc = 9203;
			text = "Warnings"; 
			x = 0.101936 * safezoneW + safezoneX;
			y = 0 * safezoneH + safezoneY;
			w = 0.0433128 * safezoneW;
			h = 0.0286 * safezoneH;
		};
		class dUI_console_text_plain_3: RscText
		{
			idc = 9204;
			text = "Pause";
			x = 0.200936 * safezoneW + safezoneX;
			y = 0 * safezoneH + safezoneY;
			w = 0.0340316 * safezoneW;
			h = 0.0286 * safezoneH;
		};
		class dUI_console_checkbox_0: RscCheckbox
		{
			idc = 9205;
			x = 0.0905927 * safezoneW + safezoneX;
			y = 0.0022 * safezoneH + safezoneY;
			w = 0.0123751 * safezoneW;
			h = 0.022 * safezoneH;
			onCheckedChanged = "_this call rmx_fnc_consoleFilters;";
		};
		class dUI_console_checkbox_1: RscCheckbox
		{
			idc = 9206;
			x = 0.144212 * safezoneW + safezoneX;
			y = 0.0022 * safezoneH + safezoneY;
			w = 0.0123751 * safezoneW;
			h = 0.022 * safezoneH;
			onCheckedChanged = "_this call rmx_fnc_consoleFilters;";
		};
		class dUI_console_checkbox_2: RscCheckbox
		{
			idc = 9207;
			x = 0.189587 * safezoneW + safezoneX;
			y = 0.0022 * safezoneH + safezoneY;
			w = 0.0123751 * safezoneW;
			h = 0.022 * safezoneH;
			onCheckedChanged = "_this call rmx_fnc_consoleFilters;";
		};
		class dUI_console_checkbox_3: RscCheckbox
		{
			idc = 9208;
			x = 0.229813 * safezoneW + safezoneX;
			y = 0.0021 * safezoneH + safezoneY;
			w = 0.0123751 * safezoneW;
			h = 0.022 * safezoneH;
			onCheckedChanged = "_this call rmx_fnc_consoleFilters;";
		};
		class dUI_console_button_0: RscButton
		{
			idc = 9209;
			text = "-"; 
			x = 0.0320173 * safezoneW + safezoneX;
			y = 0.0022 * safezoneH + safezoneY;
			w = 0.0175308 * safezoneW;
			h = 0.0264 * safezoneH;
			onButtonClick = "_this call rmx_fnc_consoleFilters;";
		};
		class dUI_console_button_1: RscButton
		{
			idc = 9210;
			text = "+"; 
			x = 0.0503738 * safezoneW + safezoneX;
			y = 0.0022 * safezoneH + safezoneY;
			w = 0.0175308 * safezoneW;
			h = 0.0264 * safezoneH;
			onButtonClick = "_this call rmx_fnc_consoleFilters;";
		};
		class dUI_console_button_3: RscButton
		{
			idc = 9211;
			text = "Clear"; 
			x = 0.00396872 * safezoneW + safezoneX;
			y = 0.0021 * safezoneH + safezoneY;
			w = 0.0268124 * safezoneW;
			h = 0.0264 * safezoneH;
			onButtonClick = "_this call rmx_fnc_consoleFilters;";
		};
	
		class dUI_consoleGroup: RscControlsGroup
		{
			idc = 9050;
			x = 0 * safezoneW + safezoneX;
			y = 0 * safezoneH + safezoneY;
			w = 1 * safezoneW;
			h = 0 * safezoneH;
			colorBackground[] = {0,0,0,0};
			shadow=0;

			class VScrollbar 
			{
				width = 0.02;
				autoScrollSpeed = 1;
				autoScrollDelay = 2;
				autoScrollRewind = 0;
				shadow=0;
			};
			
			class HScrollbar 
			{
				height = 0;
				shadow=0;
			};
			
			class ScrollBar
			{
				color[] = {1,1,1,0.6};
				colorActive[] = {1,1,1,1};
				colorDisabled[] = {1,1,1,0.3};
				thumb = "#(argb,8,8,3)color(1,1,1,1)";
				arrowEmpty = "#(argb,8,8,3)color(1,1,1,1)";
				arrowFull = "#(argb,8,8,3)color(1,1,1,1)";
				border = "#(argb,8,8,3)color(1,1,1,1)";
			};
			
			class controls
			{
				class dUI_console_text_0: dUI_ConsoleText
				{
					idc = 9000;
					y = 0 * safeZoneH;
					colorBackground[] = {0.2,0.2,0.2,0.31};
				};
				class dUI_console_text_1: dUI_ConsoleText
				{
					idc = 9001;
					y = 0.025 * safeZoneH;
					colorBackground[] = {0.3,0.3,0.3,0.31};
				};
				class dUI_console_text_2: dUI_ConsoleText
				{
					idc = 9002;
					y = 0.05 * safeZoneH;
					colorBackground[] = {0.2,0.2,0.2,0.31};
				};
				class dUI_console_text_3: dUI_ConsoleText
				{
					idc = 9003;
					y = 0.075 * safeZoneH;
					colorBackground[] = {0.3,0.3,0.3,0.31};
				};
				class dUI_console_text_4: dUI_ConsoleText
				{
					idc = 9004;
					y = 0.1 * safeZoneH;
					colorBackground[] = {0.2,0.2,0.2,0.31};
				};
				class dUI_console_text_5: dUI_ConsoleText
				{
					idc = 9005;
					y = 0.125 * safeZoneH;
					colorBackground[] = {0.3,0.3,0.3,0.31};
				};
				class dUI_console_text_6: dUI_ConsoleText
				{
					idc = 9006;
					y = 0.15 * safeZoneH;
					colorBackground[] = {0.2,0.2,0.2,0.31};
				};
				class dUI_console_text_7: dUI_ConsoleText
				{
					idc = 9007;
					y = 0.175 * safeZoneH;
					colorBackground[] = {0.3,0.3,0.3,0.31};
				};
				class dUI_console_text_8: dUI_ConsoleText
				{
					idc = 9008;
					y = 0.2 * safeZoneH;
					colorBackground[] = {0.2,0.2,0.2,0.31};
				};
				class dUI_console_text_9: dUI_ConsoleText
				{
					idc = 9009;
					y = 0.225 * safeZoneH;
					colorBackground[] = {0.3,0.3,0.3,0.31};
				};
				class dUI_console_text_10: dUI_ConsoleText
				{
					idc = 9010;
					y = 0.25 * safeZoneH;
					colorBackground[] = {0.2,0.2,0.2,0.31};
				};
				class dUI_console_text_11: dUI_ConsoleText
				{
					idc = 9011;
					y = 0.275 * safeZoneH;
					colorBackground[] = {0.3,0.3,0.3,0.31};
				};
				class dUI_console_text_12: dUI_ConsoleText
				{
					idc = 9012;
					y = 0.3 * safeZoneH;
					colorBackground[] = {0.2,0.2,0.2,0.31};
				};
				class dUI_console_text_13: dUI_ConsoleText
				{
					idc = 9013;
					y = 0.325 * safeZoneH;
					colorBackground[] = {0.3,0.3,0.3,0.31};
				};
				class dUI_console_text_14: dUI_ConsoleText
				{
					idc = 9014;
					y = 0.35 * safeZoneH;
					colorBackground[] = {0.2,0.2,0.2,0.31};
				};
				class dUI_console_text_15: dUI_ConsoleText
				{
					idc = 9015;
					y = 0.375 * safeZoneH;
					colorBackground[] = {0.3,0.3,0.3,0.31};
				};
				class dUI_console_text_16: dUI_ConsoleText
				{
					idc = 9016;
					y = 0.4 * safeZoneH;
					colorBackground[] = {0.2,0.2,0.2,0.31};
				};
				class dUI_console_text_17: dUI_ConsoleText
				{
					idc = 9017;
					y = 0.425 * safeZoneH;
					colorBackground[] = {0.3,0.3,0.3,0.31};
				};
				class dUI_console_text_18: dUI_ConsoleText
				{
					idc = 9018;
					y = 0.45 * safeZoneH;
					colorBackground[] = {0.2,0.2,0.2,0.31};
				};
				class dUI_console_text_19: dUI_ConsoleText
				{
					idc = 9019;
					y = 0.475 * safeZoneH;
					colorBackground[] = {0.3,0.3,0.3,0.31};
				};
				class dUI_console_text_20: dUI_ConsoleText
				{
					idc = 9020;
					y = 0.5 * safeZoneH;
					colorBackground[] = {0.2,0.2,0.2,0.31};
				};
				class dUI_console_text_21: dUI_ConsoleText
				{
					idc = 9021;
					y = 0.525 * safeZoneH;
					colorBackground[] = {0.3,0.3,0.3,0.31};
				};
				class dUI_console_text_22: dUI_ConsoleText
				{
					idc = 9022;
					y = 0.55 * safeZoneH;
					colorBackground[] = {0.2,0.2,0.2,0.31};
				};
				class dUI_console_text_23: dUI_ConsoleText
				{
					idc = 9023;
					y = 0.575 * safeZoneH;
					colorBackground[] = {0.3,0.3,0.3,0.31};
				};
				class dUI_console_text_24: dUI_ConsoleText
				{
					idc = 9024;
					y = 0.6 * safeZoneH;
					colorBackground[] = {0.2,0.2,0.2,0.31};
				};
				class dUI_console_text_25: dUI_ConsoleText
				{
					idc = 9025;
					y = 0.625 * safeZoneH;
					colorBackground[] = {0.3,0.3,0.3,0.31};
				};
				class dUI_console_text_26: dUI_ConsoleText
				{
					idc = 9026;
					y = 0.65 * safeZoneH;
					colorBackground[] = {0.2,0.2,0.2,0.31};
				};
				class dUI_console_text_27: dUI_ConsoleText
				{
					idc = 9027;
					y = 0.675 * safeZoneH;
					colorBackground[] = {0.3,0.3,0.3,0.31};
				};
				class dUI_console_text_28: dUI_ConsoleText
				{
					idc = 9028;
					y = 0.7 * safeZoneH;
					colorBackground[] = {0.2,0.2,0.2,0.31};
				};
				class dUI_console_text_29: dUI_ConsoleText
				{
					idc = 9029;
					y = 0.725 * safeZoneH;
					colorBackground[] = {0.3,0.3,0.3,0.31};
				};
				class dUI_console_text_30: dUI_ConsoleText
				{
					idc = 9030;
					y = 0.75 * safeZoneH;
					colorBackground[] = {0.2,0.2,0.2,0.31};
				};
				class dUI_console_text_31: dUI_ConsoleText
				{
					idc = 9031;
					y = 0.775 * safeZoneH;
					colorBackground[] = {0.3,0.3,0.3,0.31};
				};
				class dUI_console_text_32: dUI_ConsoleText
				{
					idc = 9032;
					y = 0.8 * safeZoneH;
					colorBackground[] = {0.2,0.2,0.2,0.31};
				};
				class dUI_console_text_33: dUI_ConsoleText
				{
					idc = 9033;
					y = 0.825 * safeZoneH;
					colorBackground[] = {0.3,0.3,0.3,0.31};
				};
				class dUI_console_text_34: dUI_ConsoleText
				{
					idc = 9034;
					y = 0.85 * safeZoneH;
					colorBackground[] = {0.2,0.2,0.2,0.31};
				};
				class dUI_console_text_35: dUI_ConsoleText
				{
					idc = 9035;
					y = 0.875 * safeZoneH;
					colorBackground[] = {0.3,0.3,0.3,0.31};
				};
				class dUI_console_text_36: dUI_ConsoleText
				{
					idc = 9036;
					y = 0.9 * safeZoneH;
					colorBackground[] = {0.2,0.2,0.2,0.31};
				};
				class dUI_console_text_37: dUI_ConsoleText
				{
					idc = 9037;
					y = 0.925 * safeZoneH;
					colorBackground[] = {0.3,0.3,0.3,0.31};
				};
				class dUI_console_text_38: dUI_ConsoleText
				{
					idc = 9038;
					y = 0.95 * safeZoneH;
					colorBackground[] = {0.2,0.2,0.2,0.31};
				};
				class dUI_console_text_39: dUI_ConsoleText
				{
					idc = 9039;
					y = 0.975 * safeZoneH;
					colorBackground[] = {0.3,0.3,0.3,0.31};
				};
			};
		};
	};
};