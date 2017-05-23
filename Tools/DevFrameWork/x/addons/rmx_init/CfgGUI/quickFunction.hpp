class dUI_quickFunction {
	idd = 9400;
	enableSimulation = 1;
	movingEnable = 1;
	onKeyDown = "_this call rmx_fnc_keyDown;";
	class controls {
		class dUI_qf_back: IGUIBack
		{
			idc = 9401;
			x = 0.386562 * safezoneW + safezoneX;
			y = 0.269 * safezoneH + safezoneY;
			w = 0.226875 * safezoneW;
			h = 0.462 * safezoneH;
			colorBackground[] = {0,0,0,0.5};
		};
		class dUI_qf_title: RscText
		{
			idc = 9402;
			text = "Quick function"; //--- ToDo: Localize;
			x = 0.386562 * safezoneW + safezoneX;
			y = 0.269 * safezoneH + safezoneY;
			w = 0.226875 * safezoneW;
			h = 0.022 * safezoneH;
			colorBackground[] = {1,0,0,1};
		};
		class dUI_qf_lb: RscListbox
		{
			idc = 9403;
			x = 0.396875 * safezoneW + safezoneX;
			y = 0.357 * safezoneH + safezoneY;
			w = 0.207282 * safezoneW;
			h = 0.33 * safezoneH;
			colorBackground[] = {0,0,0,0.8};
		};
		class dUI_qf_params: RscEdit
		{
			idc = 9404;
			text = "'Params are saved into profileNamespace'"; //--- ToDo: Localize;
			x = 0.396875 * safezoneW + safezoneX;
			y = 0.313 * safezoneH + safezoneY;
			w = 0.207281 * safezoneW;
			h = 0.0242 * safezoneH;
			colorBackground[] = {0,0,0,0.8};
		};
		class dUI_qf_hint: RscText
		{
			idc = 9405;
			text = "Double click listbox item to Execute"; //--- ToDo: Localize;
			x = 0.422656 * safezoneW + safezoneX;
			y = 0.698 * safezoneH + safezoneY;
			w = 0.155731 * safezoneW;
			h = 0.022 * safezoneH;
			colorBackground[] = {0,0,0,0};
		};
	};
};