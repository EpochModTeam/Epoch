class dUI_atmosFear {
	idd = 8100;
	enableSimulation = 1;
	movingEnable = 1;
	onKeyDown = "_this call rmx_fnc_keyDown;";
	onUnload = "['unload'] call rmx_fnc_atmosFearActions;";
	
	class controls {
		
		//Background
		class dUI_af_background: IGUIBack
		{
			idc = -1;
			x = 0.304062 * safezoneW + safezoneX;
			y = 0.1898 * safezoneH + safezoneY;
			w = 0.39184 * safezoneW;
			h = 0.671 * safezoneH;
			colorBackground[] = {0,0,0,0.5};
		};
		
		//Frames
		class dUI_af_f_generics: RscFrame
		{
			idc = -1;
			x = 0.31336 * safezoneW + safezoneX;
			y = 0.225 * safezoneH + safezoneY;
			w = 0.370186 * safezoneW;
			h = 0.1694 * safezoneH;
			colorText[] = {1,1,1,1};
		};	
		class dUI_af_f_fog: RscFrame
		{
			idc = -1;
			text = "Fog"; //--- ToDo: Localize;
			x = 0.313344 * safezoneW + safezoneX;
			y = 0.4032 * safezoneH + safezoneY;
			w = 0.37125 * safezoneW;
			h = 0.1188 * safezoneH;
		};
		class dUI_af_f_wind: RscFrame
		{
			idc = -1;
			text = "Wind"; //--- ToDo: Localize;
			x = 0.313344 * safezoneW + safezoneX;
			y = 0.5308 * safezoneH + safezoneY;
			w = 0.37125 * safezoneW;
			h = 0.242 * safezoneH;
		};

		//Text
		class dUI_af_txt_winda2_array: RscText
		{
			idc = 8101;
			text = "[100, 100, true]"; //--- ToDo: Localize;
			x = 0.315406 * safezoneW + safezoneX;
			y = 0.7112 * safezoneH + safezoneY;
			w = 0.133031 * safezoneW;
			h = 0.0198 * safezoneH;
			colorText[] = {0.79,0.46,0,1};
		};
		class dUI_af_txt_wind_dir_val: RscText
		{
			idc = 8102;
			text = "360"; //--- ToDo: Localize;
			x = 0.380375 * safezoneW + safezoneX;
			y = 0.6452 * safezoneH + safezoneY;
			w = 0.0505318 * safezoneW;
			h = 0.0198 * safezoneH;
			colorText[] = {0.79,0.46,0,1};
		};
		class dUI_af_title: RscText
		{
			idc = -1;
			text = "AtmosFEAR"; //--- ToDo: Localize;
			x = 0.298925 * safezoneW + safezoneX;
			y = 0.1986 * safezoneH + safezoneY;
			w = 0.0721875 * safezoneW;
			h = 0.022 * safezoneH;
			colorText[] = {0.75,0.34,0,1};
			colorBackground[] = {0,0,0,0.8};
		};
		class dUI_af_txt_gusts: RscText
		{
			idc = -1;
			text = "Gusts"; //--- ToDo: Localize;
			x = 0.315407 * safezoneW + safezoneX;
			y = 0.3306 * safezoneH + safezoneY;
			w = 0.0360937 * safezoneW;
			h = 0.0198 * safezoneH;
		};
		class dUI_af_txt_Lightnings: RscText
		{
			idc = -1;
			text = "Lightnings"; //--- ToDo: Localize;
			x = 0.315413 * safezoneW + safezoneX;
			y = 0.2382 * safezoneH + safezoneY;
			w = 0.0453749 * safezoneW;
			h = 0.0198 * safezoneH;
		};
		class dUI_af_txt_Overcast: RscText
		{
			idc = -1;
			text = "Overcast"; //--- ToDo: Localize;
			x = 0.315406 * safezoneW + safezoneX;
			y = 0.269 * safezoneH + safezoneY;
			w = 0.0453749 * safezoneW;
			h = 0.0198 * safezoneH;
		};
		class dUI_af_txt_rain: RscText
		{
			idc = -1;
			text = "Rain"; //--- ToDo: Localize;
			x = 0.315407 * safezoneW + safezoneX;
			y = 0.3636 * safezoneH + safezoneY;
			w = 0.0453749 * safezoneW;
			h = 0.0198 * safezoneH;
		};
		class dUI_af_txt_rainbow: RscText
		{
			idc = -1;
			text = "Rainbow"; //--- ToDo: Localize;
			x = 0.315407 * safezoneW + safezoneX;
			y = 0.2998 * safezoneH + safezoneY;
			w = 0.0453749 * safezoneW;
			h = 0.0198 * safezoneH;
		};
		class dUI_af_txt_fog_density: RscText
		{
			idc = -1;
			text = "Density"; //--- ToDo: Localize;
			x = 0.315408 * safezoneW + safezoneX;
			y = 0.4208 * safezoneH + safezoneY;
			w = 0.0453749 * safezoneW;
			h = 0.0198 * safezoneH;
		};
		class dUI_af_txt_fog_decay: RscText
		{
			idc = -1;
			text = "Decay"; //--- ToDo: Localize;
			x = 0.315407 * safezoneW + safezoneX;
			y = 0.4538 * safezoneH + safezoneY;
			w = 0.0453749 * safezoneW;
			h = 0.0198 * safezoneH;
		};
		class dUI_af_txt_fog_altitude: RscText
		{
			idc = -1;
			text = "Altitude"; //--- ToDo: Localize;
			x = 0.315408 * safezoneW + safezoneX;
			y = 0.4868 * safezoneH + safezoneY;
			w = 0.0453749 * safezoneW;
			h = 0.0198 * safezoneH;
		};
		class dUI_af_txt_wind_str: RscText
		{
			idc = -1;
			text = "Strength"; //--- ToDo: Localize;
			x = 0.315407 * safezoneW + safezoneX;
			y = 0.5462 * safezoneH + safezoneY;
			w = 0.0453749 * safezoneW;
			h = 0.0198 * safezoneH;
		};
		class dUI_af_txt_wind_dir: RscText
		{
			idc = -1;
			text = "Direction"; //--- ToDo: Localize;
			x = 0.31519 * safezoneW + safezoneX;
			y = 0.644667 * safezoneH + safezoneY;
			w = 0.0453749 * safezoneW;
			h = 0.0198 * safezoneH;
		};
		class dUI_af_txt_wind_frc: RscText
		{
			idc = -1;
			text = "Force"; //--- ToDo: Localize;
			x = 0.315407 * safezoneW + safezoneX;
			y = 0.5792 * safezoneH + safezoneY;
			w = 0.0453749 * safezoneW;
			h = 0.0198 * safezoneH;
		};
		class dUI_af_txt_waves: RscText
		{
			idc = -1;
			text = "Waves"; //--- ToDo: Localize;
			x = 0.315407 * safezoneW + safezoneX;
			y = 0.6122 * safezoneH + safezoneY;
			w = 0.0453749 * safezoneW;
			h = 0.0198 * safezoneH;
		};
		class dUI_af_txt_winda2: RscText
		{
			idc = -1;
			text = "Wind (A2)"; //--- ToDo: Localize;
			x = 0.315732 * safezoneW + safezoneX;
			y = 0.686667 * safezoneH + safezoneY;
			w = 0.0453749 * safezoneW;
			h = 0.0198 * safezoneH;
		};
		class dUI_af_txt_help1: RscText
		{
			idc = -1;
			text = "m/s     Positive: EAST | Negative: WEST"; //--- ToDo: Localize;
			x = 0.483501 * safezoneW + safezoneX;
			y = 0.6826 * safezoneH + safezoneY;
			w = 0.197976 * safezoneW;
			h = 0.0198 * safezoneH;
		};
		class dUI_af_txt_help2: RscText
		{
			idc = -1;
			text = "m/s     Positive: NORTH | Negative: SOUTH"; //--- ToDo: Localize;
			x = 0.482876 * safezoneW + safezoneX;
			y = 0.713519 * safezoneH + safezoneY;
			w = 0.197976 * safezoneW;
			h = 0.0198 * safezoneH;
		};
		class dUI_af_txt_help3: RscText
		{
			idc = -1;
			text = "Force?"; //--- ToDo: Localize;
			x = 0.483501 * safezoneW + safezoneX;
			y = 0.7442 * safezoneH + safezoneY;
			w = 0.0453749 * safezoneW;
			h = 0.0198 * safezoneH;
		};

		//Progress Bar
		class dUI_af_p_lightning: RscProgress
		{
			idc = 8110;
			texture = "";
			textureExt = "";
			colorBar[] = {0.9, 0.9, 0.9, 0.9};
			colorExtBar[] = {1, 1, 1, 1};
			colorFrame[] = {1, 1, 1, 1};
			x = 0.362842 * safezoneW + safezoneX;
			y = 0.236 * safezoneH + safezoneY;
			w = 0.0876563 * safezoneW;
			h = 0.022 * safezoneH;
		};
		class dUI_af_p_overcast: dUI_af_p_lightning
		{
			idc = 8111;
			x = 0.362844 * safezoneW + safezoneX;
			y = 0.2668 * safezoneH + safezoneY;
			w = 0.0876563 * safezoneW;
			h = 0.022 * safezoneH;
		};
		class dUI_af_p_rainbow: dUI_af_p_lightning
		{
			idc = 8112;
			x = 0.362844 * safezoneW + safezoneX;
			y = 0.2976 * safezoneH + safezoneY;
			w = 0.0876563 * safezoneW;
			h = 0.022 * safezoneH;
		};
		class dUI_af_p_gusts: dUI_af_p_lightning
		{
			idc = 8113;
			x = 0.362844 * safezoneW + safezoneX;
			y = 0.3284 * safezoneH + safezoneY;
			w = 0.0876563 * safezoneW;
			h = 0.022 * safezoneH;
		};
		class dUI_af_p_rain: dUI_af_p_lightning
		{
			idc = 8114;
			x = 0.362844 * safezoneW + safezoneX;
			y = 0.3614 * safezoneH + safezoneY;
			w = 0.0876563 * safezoneW;
			h = 0.022 * safezoneH;
		};

		class dUI_af_p_fog_density: dUI_af_p_lightning
		{
			idc = 8115;
			x = 0.362843 * safezoneW + safezoneX;
			y = 0.4186 * safezoneH + safezoneY;
			w = 0.0876563 * safezoneW;
			h = 0.022 * safezoneH;
		};

		class dUI_af_p_fog_decay: dUI_af_p_lightning
		{
			idc = 8116;
			x = 0.362844 * safezoneW + safezoneX;
			y = 0.4538 * safezoneH + safezoneY;
			w = 0.0876563 * safezoneW;
			h = 0.022 * safezoneH;
		};
		class dUI_af_p_fog_altitude: dUI_af_p_lightning
		{
			idc = 8117;
			x = 0.362844 * safezoneW + safezoneX;
			y = 0.4868 * safezoneH + safezoneY;
			w = 0.0876563 * safezoneW;
			h = 0.022 * safezoneH;
		};

		class dUI_af_p_wind_str: dUI_af_p_lightning
		{
			idc = 8118;
			x = 0.362842 * safezoneW + safezoneX;
			y = 0.5462 * safezoneH + safezoneY;
			w = 0.0876563 * safezoneW;
			h = 0.022 * safezoneH;
		};

		class dUI_af_p_waves: dUI_af_p_lightning
		{
			idc = 8119;
			x = 0.362844 * safezoneW + safezoneX;
			y = 0.61 * safezoneH + safezoneY;
			w = 0.0876563 * safezoneW;
			h = 0.022 * safezoneH;
		};
/*
		class dUI_af_p_wind_frc: dUI_af_p_lightning //not implemented yet
		{
			idc = 8120;
			x = 0.363234 * safezoneW + safezoneX;
			y = 0.577985 * safezoneH + safezoneY;
			w = 0.0876563 * safezoneW;
			h = 0.022 * safezoneH;
		};
*/
		//Input fields

		class dUI_af_t_rain: RscEdit
		{
			idc = 8130;
			text = "0"; //--- ToDo: Localize;
			x = 0.453595 * safezoneW + safezoneX;
			y = 0.3592 * safezoneH + safezoneY;
			w = 0.0268126 * safezoneW;
			h = 0.0242 * safezoneH;
			colorText[] = {0.79,0.46,0,1};
		};
		class dUI_af_t_fog: RscEdit
		{
			idc = 8131;
			text = "0"; //--- ToDo: Localize;
			x = 0.454626 * safezoneW + safezoneX;
			y = 0.4538 * safezoneH + safezoneY;
			w = 0.0268126 * safezoneW;
			h = 0.0242 * safezoneH;
			colorText[] = {0.79,0.46,0,1};
		};
		class dUI_af_t_wind: RscEdit
		{
			idc = 8132;
			text = "0"; //--- ToDo: Localize;
			x = 0.453594 * safezoneW + safezoneX;
			y = 0.5462 * safezoneH + safezoneY;
			w = 0.0268126 * safezoneW;
			h = 0.0242 * safezoneH;
			colorText[] = {0.79,0.46,0,1};
		};
		class dUI_af_t_force: RscEdit
		{
			idc = 8133;
			text = "0"; //--- ToDo: Localize;
			x = 0.45422 * safezoneW + safezoneX;
			y = 0.577748 * safezoneH + safezoneY;
			w = 0.0268126 * safezoneW;
			h = 0.0242 * safezoneH;
			colorText[] = {0.79,0.46,0,1};
		};
		class dUI_af_t_waves: RscEdit
		{
			idc = 8134;
			text = "0"; //--- ToDo: Localize;
			x = 0.454625 * safezoneW + safezoneX;
			y = 0.61 * safezoneH + safezoneY;
			w = 0.0268126 * safezoneW;
			h = 0.0242 * safezoneH;
			colorText[] = {0.79,0.46,0,1};
		};

		class dUI_af_t_dir: RscEdit
		{
			idc = 8135;
			text = "0"; //--- ToDo: Localize;
			x = 0.454625 * safezoneW + safezoneX;
			y = 0.643 * safezoneH + safezoneY;
			w = 0.0268126 * safezoneW;
			h = 0.0242 * safezoneH;
			colorText[] = {0.79,0.46,0,1};
		};
		class dUI_af_t_winda2_x: RscEdit
		{
			idc = 8136;
			text = "x"; //--- ToDo: Localize;
			x = 0.454625 * safezoneW + safezoneX;
			y = 0.6804 * safezoneH + safezoneY;
			w = 0.0268126 * safezoneW;
			h = 0.0242 * safezoneH;
		};

		class dUI_af_t_winda2_y: RscEdit
		{
			idc = 8137;
			text = "y"; //--- ToDo: Localize;
			x = 0.454626 * safezoneW + safezoneX;
			y = 0.7112 * safezoneH + safezoneY;
			w = 0.0268126 * safezoneW;
			h = 0.0242 * safezoneH;
		};
		class dUI_af_t_export: RscEdit
		{
			idc = 8138;
			x = 0.312343 * safezoneW + safezoneX;
			y = 0.8234 * safezoneH + safezoneY;
			w = 0.0948749 * safezoneW;
			h = 0.0264 * safezoneH;
		};
		class dUI_af_t_day: RscEdit
		{
			idc = 8139;
			text = "26"; //--- ToDo: Localize;
			x = 0.48762 * safezoneW + safezoneX;
			y = 0.7882 * safezoneH + safezoneY;
			w = 0.0268124 * safezoneW;
			h = 0.0242 * safezoneH;
			colorText[] = {0.79,0.46,0,1};
		};
		class dUI_af_t_month: RscEdit
		{
			idc = 8140;
			text = "1"; //--- ToDo: Localize;
			x = 0.516495 * safezoneW + safezoneX;
			y = 0.7882 * safezoneH + safezoneY;
			w = 0.0268124 * safezoneW;
			h = 0.0242 * safezoneH;
			colorText[] = {0.79,0.46,0,1};
		};
		class dUI_af_t_year: RscEdit
		{
			idc = 8141;
			text = "1985"; //--- ToDo: Localize;
			x = 0.54537 * safezoneW + safezoneX;
			y = 0.7882 * safezoneH + safezoneY;
			w = 0.0268124 * safezoneW;
			h = 0.0242 * safezoneH;
			colorText[] = {0.79,0.46,0,1};
		};
		class dUI_af_t_hours: RscEdit
		{
			idc = 8142;
			text = "24"; //--- ToDo: Localize;
			x = 0.48731 * safezoneW + safezoneX;
			y = 0.8245 * safezoneH + safezoneY;
			w = 0.0268124 * safezoneW;
			h = 0.0242 * safezoneH;
			colorText[] = {0.79,0.46,0,1};
		};
		class dUI_af_t_minutes: RscEdit
		{
			idc = 8143;
			text = "00"; //--- ToDo: Localize;
			x = 0.516082 * safezoneW + safezoneX;
			y = 0.8245 * safezoneH + safezoneY;
			w = 0.0268124 * safezoneW;
			h = 0.0242 * safezoneH;
			colorText[] = {0.79,0.46,0,1};
		};
		class dUI_af_t_skipTime: RscEdit
		{
			idc = 8144;
			text = "0.5"; //--- ToDo: Localize;
			x = 0.637155 * safezoneW + safezoneX;
			y = 0.7794 * safezoneH + safezoneY;
			w = 0.0278435 * safezoneW;
			h = 0.0286 * safezoneH;
			colorText[] = {0.79,0.46,0,1};
		};
		//Sliders
		class dUI_af_s_lightnings: RscSlider
		{
			idc = 8150;
			x = 0.483519 * safezoneW + safezoneX;
			y = 0.2382 * safezoneH + safezoneY;
			w = 0.195919 * safezoneW;
			h = 0.022 * safezoneH;
		};
		class dUI_af_s_overcast: RscSlider
		{
			idc = 8151;
			x = 0.4835 * safezoneW + safezoneX;
			y = 0.269 * safezoneH + safezoneY;
			w = 0.195919 * safezoneW;
			h = 0.022 * safezoneH;
		};
		class dUI_af_s_rainbow: RscSlider
		{
			idc = 8152;
			x = 0.483501 * safezoneW + safezoneX;
			y = 0.2976 * safezoneH + safezoneY;
			w = 0.195919 * safezoneW;
			h = 0.022 * safezoneH;
		};
		class dUI_af_s_gusts: RscSlider
		{
			idc = 8153;
			x = 0.4835 * safezoneW + safezoneX;
			y = 0.3284 * safezoneH + safezoneY;
			w = 0.195919 * safezoneW;
			h = 0.022 * safezoneH;
		};
		class dUI_af_s_rain: RscSlider
		{
			idc = 8154;
			x = 0.483501 * safezoneW + safezoneX;
			y = 0.3614 * safezoneH + safezoneY;
			w = 0.195919 * safezoneW;
			h = 0.022 * safezoneH;
		};
		class dUI_af_s_fog_Decay: RscSlider
		{
			idc = 8155;
			x = 0.484532 * safezoneW + safezoneX;
			y = 0.4538 * safezoneH + safezoneY;
			w = 0.195919 * safezoneW;
			h = 0.022 * safezoneH;
		};
		class dUI_af_s_fog_density: RscSlider
		{
			idc = 8156;
			x = 0.484531 * safezoneW + safezoneX;
			y = 0.4208 * safezoneH + safezoneY;
			w = 0.195919 * safezoneW;
			h = 0.022 * safezoneH;
		};
		class dUI_af_s_fog_altitude: RscSlider
		{
			idc = 8157;
			x = 0.484046 * safezoneW + safezoneX;
			y = 0.48817 * safezoneH + safezoneY;
			w = 0.195919 * safezoneW;
			h = 0.022 * safezoneH;
		};
		class dUI_af_s_wind_str: RscSlider
		{
			idc = 8158;
			x = 0.483501 * safezoneW + safezoneX;
			y = 0.5462 * safezoneH + safezoneY;
			w = 0.195919 * safezoneW;
			h = 0.022 * safezoneH;
		};
		class dUI_af_s_wind_frc: RscSlider
		{
			idc = 8159;
			x = 0.483499 * safezoneW + safezoneX;
			y = 0.5792 * safezoneH + safezoneY;
			w = 0.195919 * safezoneW;
			h = 0.022 * safezoneH;
		};
		class dUI_af_s_waves: RscSlider
		{
			idc = 8160;
			x = 0.483501 * safezoneW + safezoneX;
			y = 0.6122 * safezoneH + safezoneY;
			w = 0.195919 * safezoneW;
			h = 0.022 * safezoneH;
		};
		class dUI_af_s_dir: RscSlider
		{
			idc = 8161;
			x = 0.4835 * safezoneW + safezoneX;
			y = 0.6452 * safezoneH + safezoneY;
			w = 0.195919 * safezoneW;
			h = 0.022 * safezoneH;
		};

		//Checkboxes
		class dUI_af_b_winda2: RscCheckbox
		{
			idc = 8170;
			x = 0.452564 * safezoneW + safezoneX;
			y = 0.742 * safezoneH + safezoneY;
			w = 0.0144373 * safezoneW;
			h = 0.0264 * safezoneH;
		};
		
		//Combo
		class dUI_af_c_import: RscCombo
		{
			idc = 8180;
			x = 0.312318 * safezoneW + safezoneX;
			y = 0.786 * safezoneH + safezoneY;
			w = 0.0948858 * safezoneW;
			h = 0.0264 * safezoneH;
			onLBSelChanged = "_this call rmx_fnc_atmosFearActions;";
		};
		
		//Buttons
		class dUI_af_btn_rpt: RscShortcutButton
		{
			idc = 8190;
			text = "RPT"; //--- ToDo: Localize;
			x = 0.647438 * safezoneW + safezoneX;
			y = 0.8168 * safezoneH + safezoneY;
			w = 0.0422814 * safezoneW;
			h = 0.033 * safezoneH;
			onButtonClick = "_this call rmx_fnc_atmosFearActions;";
			tooltip = "Apply changes before exporting to RPT";
		};
		class dUI_af_btn_apply: RscShortcutButton
		{
			idc = 8191;
			text = "Apply"; //--- ToDo: Localize;
			x = 0.59175 * safezoneW + safezoneX;
			y = 0.8168 * safezoneH + safezoneY;
			w = 0.0515625 * safezoneW;
			h = 0.033 * safezoneH;
			onButtonClick = "_this call rmx_fnc_atmosFearActions;";
		};
		class dUI_af_btn_import: RscButton
		{
			idc = 8192;
			text = "Load"; //--- ToDo: Localize;
			x = 0.410281 * safezoneW + safezoneX;
			y = 0.786 * safezoneH + safezoneY;
			w = 0.0257811 * safezoneW;
			h = 0.0264 * safezoneH;
			onButtonClick = "_this call rmx_fnc_atmosFearActions;";
		};
		class dUI_af_btn_export: RscButton
		{
			idc = 8193;
			text = "Save"; //--- ToDo: Localize;
			x = 0.410281 * safezoneW + safezoneX;
			y = 0.8234 * safezoneH + safezoneY;
			w = 0.0567187 * safezoneW;
			h = 0.0264 * safezoneH;
			onButtonClick = "_this call rmx_fnc_atmosFearActions;";
			tooltip = "Apply changes before saving";
		};
		class dUI_af_btn_set: RscButton
		{
			idc = 8194;
			text = "set"; //--- ToDo: Localize;
			x = 0.544957 * safezoneW + safezoneX;
			y = 0.8245 * safezoneH + safezoneY;
			w = 0.0268124 * safezoneW;
			h = 0.0242 * safezoneH;
			onButtonClick = "_this call rmx_fnc_atmosFearActions;";
		};
		class dUI_af_btn_plus: RscButton
		{
			idc = 8195;
			text = "+"; //--- ToDo: Localize;
			x = 0.666031 * safezoneW + safezoneX;
			y = 0.7816 * safezoneH + safezoneY;
			w = 0.0185621 * safezoneW;
			h = 0.0242 * safezoneH;
			onButtonClick = "_this call rmx_fnc_atmosFearActions;";
		};
		class dUI_af_btn_minus: RscButton
		{
			idc = 8196;
			text = "-"; //--- ToDo: Localize;
			x = 0.615499 * safezoneW + safezoneX;
			y = 0.7816 * safezoneH + safezoneY;
			w = 0.0185621 * safezoneW;
			h = 0.0242 * safezoneH;
			onButtonClick = "_this call rmx_fnc_atmosFearActions;";
		};
		class dUI_af_btn_del: RscButton
		{
			idc = 8197;
			text = "Delete"; //--- ToDo: Localize;
			x = 0.437093 * safezoneW + safezoneX;
			y = 0.786 * safezoneH + safezoneY;
			w = 0.0309372 * safezoneW;
			h = 0.0264 * safezoneH;
			onButtonClick = "_this call rmx_fnc_atmosFearActions;";
		};
	};
};