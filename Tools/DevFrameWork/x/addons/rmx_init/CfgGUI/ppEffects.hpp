class dUI_ppEffects {
	idd = 6100;
	enableSimulation = 1;
	movingEnable = 1;
	onKeyDown = "_this call rmx_fnc_keyDown;";
	onUnload = "['unload'] call rmx_fnc_ppViewerUpdate;";
	
	class controls {
		//category background
		class cat_bckgrnd: IGUIBack
		{
			idc = -1;
			x = 0.33499 * safezoneW + safezoneX;
			y = 0.247 * safezoneH + safezoneY;
			w = 0.331031 * safezoneW;
			h = 0.0704 * safezoneH;
			colorBackground[] = {0,0,0,0.5};
		};

		//category text
		class cat_logo: RscText
		{
			idc = -1;
			text = "ppEffects Viewer"; //--- ToDo: Localize;
			x = 0.33499 * safezoneW + safezoneX;
			y = 0.225 * safezoneH + safezoneY;
			w = 0.331051 * safezoneW;
			h = 0.022 * safezoneH;
			colorText[] = {0.76,0.98,0.27,1};
			colorBackground[] = {0,0,0,1};
		};
		class cat_txt: RscText
		{
			idc = -1;
			text = "Category:"; //--- ToDo: Localize;
			x = 0.337052 * safezoneW + safezoneX;
			y = 0.2602 * safezoneH + safezoneY;
			w = 0.0422813 * safezoneW;
			h = 0.0198 * safezoneH;
		};


		//category combo
		class cat_combo: RscCombo
		{
			idc = 6110;
			x = 0.385523 * safezoneW + safezoneX;
			y = 0.258 * safezoneH + safezoneY;
			w = 0.0938438 * safezoneW;
			h = 0.022 * safezoneH;
			onLBSelChanged = "_this call rmx_fnc_ppViewerUpdate;";
		};
		class cat_load_combo: RscCombo
		{
			idc = 6111;
			x = 0.484529 * safezoneW + safezoneX;
			y = 0.258 * safezoneH + safezoneY;
			w = 0.0938436 * safezoneW;
			h = 0.022 * safezoneH;
			onLBSelChanged = "_this call rmx_fnc_ppViewerUpdate;";
		};

		//category edit
		class cat_edit: RscEdit
		{
			idc = 6120;
			x = 0.484544 * safezoneW + safezoneX;
			y = 0.291 * safezoneH + safezoneY;
			w = 0.0938436 * safezoneW;
			h = 0.0242 * safezoneH;
		};

		//category buttons
		class cat_btn_Load: RscShortcutButton
		{
			idc = 6130;
			text = "Load"; //--- ToDo: Localize;
			x = 0.581386 * safezoneW + safezoneX;
			y = 0.2558 * safezoneH + safezoneY;
			w = 0.0433128 * safezoneW;
			h = 0.0286 * safezoneH;
			onButtonClick = "'import' call rmx_fnc_ppViewerGetSet;";
		};
		class cat_btn_save: RscShortcutButton
		{
			idc = 6131;
			text = "Save"; //--- ToDo: Localize;
			x = 0.581481 * safezoneW + safezoneX;
			y = 0.2888 * safezoneH + safezoneY;
			w = 0.0433128 * safezoneW;
			h = 0.0286 * safezoneH;
			onButtonClick = "'export' call rmx_fnc_ppViewerGetSet;";
		};
		class cat_btn_disable: RscShortcutButton
		{
			idc = 6132;
			text = "Disable"; //--- ToDo: Localize;
			x = 0.335057 * safezoneW + safezoneX;
			y = 0.2888 * safezoneH + safezoneY;
			w = 0.048469 * safezoneW;
			h = 0.0286 * safezoneH;
			onButtonClick = "_this call rmx_fnc_ppViewerUpdate;";
		};
		class cat_btn_random: RscShortcutButton
		{
			idc = 6133;
			text = "RND"; //--- ToDo: Localize;
			x = 0.444295 * safezoneW + safezoneX;
			y = 0.2888 * safezoneH + safezoneY;
			w = 0.0350628 * safezoneW;
			h = 0.0286 * safezoneH;
			onButtonClick = "_this call rmx_fnc_ppViewerUpdate;";
		};
		class cat_btn_del: RscShortcutButton
		{
			idc = 6134;
			text = "DEL"; //--- ToDo: Localize;
			x = 0.626845 * safezoneW + safezoneX;
			y = 0.2558 * safezoneH + safezoneY;
			w = 0.0391878 * safezoneW;
			h = 0.0286 * safezoneH;
			onButtonClick = "_this call rmx_fnc_ppViewerUpdate;";
		};
		class cat_btn_rpt: RscShortcutButton
		{
			idc = 6135;
			text = "RPT"; //--- ToDo: Localize;
			x = 0.626847 * safezoneW + safezoneX;
			y = 0.2888 * safezoneH + safezoneY;
			w = 0.0391878 * safezoneW;
			h = 0.0286 * safezoneH;
			onButtonClick = "_this call rmx_fnc_ppViewerUpdate;";
		};
		class cat_btn_resetALL: RscShortcutButton
		{
			idc = 6136;
			text = "Reset ALL"; //--- ToDo: Localize;
			x = 0.383726 * safezoneW + safezoneX;
			y = 0.288652 * safezoneH + safezoneY;
			w = 0.0598124 * safezoneW;
			h = 0.0286 * safezoneH;
			onButtonClick = "_this call rmx_fnc_ppViewerUpdate;";
		};
		
		//color correction
		//background
		class cc_bckgrnd: IGUIBack
		{
			idc = 6210;

			x = 0.335 * safezoneW + safezoneX;
			y = 0.335 * safezoneH + safezoneY;
			w = 0.33 * safezoneW;
			h = 0.33 * safezoneH;
			colorBackground[] = {0,0,0,0.5};
		};

		//text
		class cc_txt_brightness: RscText
		{
			idc = 6220;

			text = "Brightness"; //--- ToDo: Localize;
			x = 0.362838 * safezoneW + safezoneX;
			y = 0.357 * safezoneH + safezoneY;
			w = 0.048469 * safezoneW;
			h = 0.0176 * safezoneH;
		};
		class cc_txt_contrast: RscText
		{
			idc = 6221;

			text = "Contrast"; //--- ToDo: Localize;
			x = 0.480516 * safezoneW + safezoneX;
			y = 0.356711 * safezoneH + safezoneY;
			w = 0.0391878 * safezoneW;
			h = 0.0176 * safezoneH;
		};
		class cc_txt_offset: RscText
		{
			idc = 6222;

			text = "Offset"; //--- ToDo: Localize;
			x = 0.597874 * safezoneW + safezoneX;
			y = 0.358333 * safezoneH + safezoneY;
			w = 0.0360941 * safezoneW;
			h = 0.0176 * safezoneH;
		};
		class cc_txt_blend: RscText
		{
			idc = 6223;

			text = "Blend (RGBA)"; //--- ToDo: Localize;
			x = 0.353565 * safezoneW + safezoneX;
			y = 0.445 * safezoneH + safezoneY;
			w = 0.0690937 * safezoneW;
			h = 0.0176 * safezoneH;
		};
		class cc_txt_colorize1: RscText
		{
			idc = 6224;

			text = "Colorize (RGBA)"; //--- ToDo: Localize;
			x = 0.463909 * safezoneW + safezoneX;
			y = 0.445 * safezoneH + safezoneY;
			w = 0.0690937 * safezoneW;
			h = 0.0176 * safezoneH;
		};
		class cc_txt_colorize2: RscText
		{
			idc = 6225;

			text = "Colorize (RGBA)"; //--- ToDo: Localize;
			x = 0.577344 * safezoneW + safezoneX;
			y = 0.445 * safezoneH + safezoneY;
			w = 0.0690937 * safezoneW;
			h = 0.0176 * safezoneH;
		};

		//Sliders
		class cc_slider_brightness: RscSlider
		{
			idc = 6230;

			x = 0.337062 * safezoneW + safezoneX;
			y = 0.3834 * safezoneH + safezoneY;
			w = 0.0989998 * safezoneW;
			h = 0.0308 * safezoneH;
			onSliderPosChanged = "_this call rmx_fnc_ppViewerEffects;";
		};

		class cc_slider_contrast: RscSlider
		{
			idc = 6231;

			x = 0.450501 * safezoneW + safezoneX;
			y = 0.3834 * safezoneH + safezoneY;
			w = 0.0989998 * safezoneW;
			h = 0.0308 * safezoneH;
			onSliderPosChanged = "_this call rmx_fnc_ppViewerEffects;";
		};
		class cc_slider_offset: RscSlider
		{
			idc = 6232;

			x = 0.563939 * safezoneW + safezoneX;
			y = 0.3834 * safezoneH + safezoneY;
			w = 0.0989998 * safezoneW;
			h = 0.0308 * safezoneH;
			onSliderPosChanged = "_this call rmx_fnc_ppViewerEffects;";
		};
		class cc_slider_bR: RscSlider
		{
			idc = 6233;

			x = 0.337063 * safezoneW + safezoneX;
			y = 0.4714 * safezoneH + safezoneY;
			w = 0.0989998 * safezoneW;
			h = 0.0308 * safezoneH;
			onSliderPosChanged = "_this call rmx_fnc_ppViewerEffects;";
		};
		class cc_slider_bG: RscSlider
		{
			idc = 6234;

			x = 0.337062 * safezoneW + safezoneX;
			y = 0.5154 * safezoneH + safezoneY;
			w = 0.0989998 * safezoneW;
			h = 0.0308 * safezoneH;
			onSliderPosChanged = "_this call rmx_fnc_ppViewerEffects;";
		};
		class cc_slider_bB: RscSlider
		{
			idc = 6235;

			x = 0.337062 * safezoneW + safezoneX;
			y = 0.5594 * safezoneH + safezoneY;
			w = 0.0989998 * safezoneW;
			h = 0.0308 * safezoneH;
			onSliderPosChanged = "_this call rmx_fnc_ppViewerEffects;";
		};
		class cc_slider_bA: RscSlider
		{
			idc = 6236;

			x = 0.337062 * safezoneW + safezoneX;
			y = 0.6034 * safezoneH + safezoneY;
			w = 0.0989998 * safezoneW;
			h = 0.0308 * safezoneH;
			onSliderPosChanged = "_this call rmx_fnc_ppViewerEffects;";
		};
		class cc_slider_c1R: RscSlider
		{
			idc = 6237;

			x = 0.4505 * safezoneW + safezoneX;
			y = 0.4714 * safezoneH + safezoneY;
			w = 0.0989998 * safezoneW;
			h = 0.0308 * safezoneH;
			onSliderPosChanged = "_this call rmx_fnc_ppViewerEffects;";
		};
		class cc_slider_c1G: RscSlider
		{
			idc = 6238;

			x = 0.450501 * safezoneW + safezoneX;
			y = 0.5154 * safezoneH + safezoneY;
			w = 0.0989998 * safezoneW;
			h = 0.0308 * safezoneH;
			onSliderPosChanged = "_this call rmx_fnc_ppViewerEffects;";
		};
		class cc_slider_c1B: RscSlider
		{
			idc = 6239;

			x = 0.4505 * safezoneW + safezoneX;
			y = 0.5594 * safezoneH + safezoneY;
			w = 0.0989998 * safezoneW;
			h = 0.0308 * safezoneH;
			onSliderPosChanged = "_this call rmx_fnc_ppViewerEffects;";
		};
		class cc_slider_c1A: RscSlider
		{
			idc = 6240;

			x = 0.450501 * safezoneW + safezoneX;
			y = 0.6034 * safezoneH + safezoneY;
			w = 0.0989998 * safezoneW;
			h = 0.0308 * safezoneH;
			onSliderPosChanged = "_this call rmx_fnc_ppViewerEffects;";
		};
		class cc_slider_c2R: RscSlider
		{
			idc = 6241;

			x = 0.563938 * safezoneW + safezoneX;
			y = 0.4714 * safezoneH + safezoneY;
			w = 0.0989998 * safezoneW;
			h = 0.0308 * safezoneH;
			onSliderPosChanged = "_this call rmx_fnc_ppViewerEffects;";
		};
		class cc_slider_c2G: RscSlider
		{
			idc = 6242;

			x = 0.564551 * safezoneW + safezoneX;
			y = 0.516089 * safezoneH + safezoneY;
			w = 0.0989998 * safezoneW;
			h = 0.0308 * safezoneH;
			onSliderPosChanged = "_this call rmx_fnc_ppViewerEffects;";
		};
		class cc_slider_c2B: RscSlider
		{
			idc = 6243;

			x = 0.56403 * safezoneW + safezoneX;
			y = 0.559607 * safezoneH + safezoneY;
			w = 0.0989998 * safezoneW;
			h = 0.0308 * safezoneH;
			onSliderPosChanged = "_this call rmx_fnc_ppViewerEffects;";
		};
		class cc_slider_c2A: RscSlider
		{
			idc = 6244;

			x = 0.564562 * safezoneW + safezoneX;
			y = 0.602896 * safezoneH + safezoneY;
			w = 0.0989998 * safezoneW;
			h = 0.0308 * safezoneH;
			onSliderPosChanged = "_this call rmx_fnc_ppViewerEffects;";
		};

		//vignette pre
		//text
		class cc_txt_vignette: RscText
		{
			idc = 6250;

			text = "Vignette effect"; //--- ToDo: Localize;
			x = 0.358722 * safezoneW + safezoneX;
			y = 0.6452 * safezoneH + safezoneY;
			w = 0.0690937 * safezoneW;
			h = 0.0176 * safezoneH;
		};

		//checkbox
		class cc_bool_vignette: RscCheckbox
		{
			idc = 6251;
			x = 0.342218 * safezoneW + safezoneX;
			y = 0.6386 * safezoneH + safezoneY;
			w = 0.0175312 * safezoneW;
			h = 0.0308 * safezoneH;
			onCheckedChanged = "_this call rmx_fnc_ppViewerUpdate;";
		};

		//CC vignette
		//background
		class cc_v_bckgrnd: IGUIBack
		{
			idc = 6260;

			x = 0.335 * safezoneW + safezoneX;
			y = 0.687 * safezoneH + safezoneY;
			w = 0.33 * safezoneW;
			h = 0.187 * safezoneH;
			colorBackground[] = {0,0,0,0.5};
		};

		//text
		class cc_txt_vHS: RscText
		{
			idc = 6270;

			text = "H Size:"; //--- ToDo: Localize;
			x = 0.337062 * safezoneW + safezoneX;
			y = 0.6914 * safezoneH + safezoneY;
			w = 0.0474377 * safezoneW;
			h = 0.0176 * safezoneH;
		};
		class cc_txt_vVS: RscText
		{
			idc = 6271;

			text = "V Size:"; //--- ToDo: Localize;
			x = 0.337062 * safezoneW + safezoneX;
			y = 0.7354 * safezoneH + safezoneY;
			w = 0.048469 * safezoneW;
			h = 0.0176 * safezoneH;
		};
		class cc_txt_vUnknown: RscText
		{
			idc = 6272;

			text = "?"; //--- ToDo: Localize;
			x = 0.337062 * safezoneW + safezoneX;
			y = 0.7794 * safezoneH + safezoneY;
			w = 0.0680624 * safezoneW;
			h = 0.0176 * safezoneH;
		};
		class cc_txt_vhP: RscText
		{
			idc = 6273;

			text = "H Pos:"; //--- ToDo: Localize;
			x = 0.512372 * safezoneW + safezoneX;
			y = 0.6914 * safezoneH + safezoneY;
			w = 0.0474377 * safezoneW;
			h = 0.0176 * safezoneH;
		};
		class cc_txt_vVP: RscText
		{
			idc = 6274;

			text = "V Pos:"; //--- ToDo: Localize;
			x = 0.512372 * safezoneW + safezoneX;
			y = 0.734607 * safezoneH + safezoneY;
			w = 0.048469 * safezoneW;
			h = 0.0176 * safezoneH;
		};
		class cc_txt_vSTR: RscText
		{
			idc = 6275;

			text = "Strength:"; //--- ToDo: Localize;
			x = 0.512374 * safezoneW + safezoneX;
			y = 0.7794 * safezoneH + safezoneY;
			w = 0.048469 * safezoneW;
			h = 0.0176 * safezoneH;
		};
		class cc_txt_vA: RscText
		{
			idc = 6276;

			text = "Alpha:"; //--- ToDo: Localize;
			x = 0.441215 * safezoneW + safezoneX;
			y = 0.8256 * safezoneH + safezoneY;
			w = 0.0319691 * safezoneW;
			h = 0.0176 * safezoneH;
		};

		//sliders
		class cc_slider_vHS: RscSlider
		{
			idc = 6280;

			x = 0.388629 * safezoneW + safezoneX;
			y = 0.6914 * safezoneH + safezoneY;
			w = 0.0989998 * safezoneW;
			h = 0.0308 * safezoneH;
			onSliderPosChanged = "_this call rmx_fnc_ppViewerEffects;";
		};

		class cc_slider_vVS: RscSlider
		{
			idc = 6281;

			x = 0.388631 * safezoneW + safezoneX;
			y = 0.7354 * safezoneH + safezoneY;
			w = 0.0989998 * safezoneW;
			h = 0.0308 * safezoneH;
			onSliderPosChanged = "_this call rmx_fnc_ppViewerEffects;";
		};

		class cc_slider_vUnknown: RscSlider
		{
			idc = 6282;

			x = 0.388629 * safezoneW + safezoneX;
			y = 0.7794 * safezoneH + safezoneY;
			w = 0.0989998 * safezoneW;
			h = 0.0308 * safezoneH;
			onSliderPosChanged = "_this call rmx_fnc_ppViewerEffects;";
		};
		class cc_slider_vHP: RscSlider
		{
			idc = 6283;

			x = 0.564969 * safezoneW + safezoneX;
			y = 0.6914 * safezoneH + safezoneY;
			w = 0.0989998 * safezoneW;
			h = 0.0308 * safezoneH;
			onSliderPosChanged = "_this call rmx_fnc_ppViewerEffects;";
		};
		class cc_slider_vVP: RscSlider
		{
			idc = 6284;

			x = 0.563937 * safezoneW + safezoneX;
			y = 0.7354 * safezoneH + safezoneY;
			w = 0.0989998 * safezoneW;
			h = 0.0308 * safezoneH;
			onSliderPosChanged = "_this call rmx_fnc_ppViewerEffects;";
		};

		class cc_slider_vSTR: RscSlider
		{
			idc = 6285;

			x = 0.564052 * safezoneW + safezoneX;
			y = 0.7794 * safezoneH + safezoneY;
			w = 0.0989998 * safezoneW;
			h = 0.0308 * safezoneH;
			onSliderPosChanged = "_this call rmx_fnc_ppViewerEffects;";
		};

		class cc_slider_vA: RscSlider
		{
			idc = 6286;

			x = 0.476281 * safezoneW + safezoneX;
			y = 0.8256 * safezoneH + safezoneY;
			w = 0.0989998 * safezoneW;
			h = 0.0308 * safezoneH;
			onSliderPosChanged = "_this call rmx_fnc_ppViewerEffects;";
		};

		//Chromatic aberation
		//background
		
		class ca_bckgrnd: IGUIBack
		{
			idc = 6310;

			x = 0.335 * safezoneW + safezoneX;
			y = 0.335 * safezoneH + safezoneY;
			w = 0.33 * safezoneW;
			h = 0.066 * safezoneH;
			colorBackground[] = {0,0,0,0.5};
		};

		//text
		class ca_txt_X: RscText
		{
			idc = 6320;

			text = "X:"; //--- ToDo: Localize;
			x = 0.337064 * safezoneW + safezoneX;
			y = 0.3614 * safezoneH + safezoneY;
			w = 0.0134063 * safezoneW;
			h = 0.0176 * safezoneH;
		};
		class ca_txt_Y: RscText
		{
			idc = 6321;

			text = "Y:"; //--- ToDo: Localize;
			x = 0.461012 * safezoneW + safezoneX;
			y = 0.362037 * safezoneH + safezoneY;
			w = 0.0134063 * safezoneW;
			h = 0.0176 * safezoneH;
		};
		class ca_txt_AR: RscText
		{
			idc = 6322;

			text = "Aspect Ratio:"; //--- ToDo: Localize;
			x = 0.584562 * safezoneW + safezoneX;
			y = 0.3614 * safezoneH + safezoneY;
			w = 0.0587812 * safezoneW;
			h = 0.0176 * safezoneH;
		};
		//sliders
		class ca_slider_x: RscSlider
		{
			idc = 6330;

			x = 0.357687 * safezoneW + safezoneX;
			y = 0.3614 * safezoneH + safezoneY;
			w = 0.0989998 * safezoneW;
			h = 0.0308 * safezoneH;
			onSliderPosChanged = "_this call rmx_fnc_ppViewerEffects;";
		};
		class ca_slider_y: RscSlider
		{
			idc = 6331;

			x = 0.481439 * safezoneW + safezoneX;
			y = 0.3614 * safezoneH + safezoneY;
			w = 0.0989998 * safezoneW;
			h = 0.0308 * safezoneH;
			onSliderPosChanged = "_this call rmx_fnc_ppViewerEffects;";
		};
		//checkbox
		class ca_cb: RscCheckbox
		{
			idc = 6340;
			x = 0.645406 * safezoneW + safezoneX;
			y = 0.3548 * safezoneH + safezoneY;
			w = 0.0175312 * safezoneW;
			h = 0.0308 * safezoneH;
			onCheckedChanged = "_this call rmx_fnc_ppViewerEffects;";
		};
		
		
		//Film grain
		//background
		class fg_bckgrnd: IGUIBack
		{
			idc = 6410;

			x = 0.335 * safezoneW + safezoneX;
			y = 0.335 * safezoneH + safezoneY;
			w = 0.33 * safezoneW;
			h = 0.154 * safezoneH;
			colorBackground[] = {0,0,0,0.5};
		};

		//text
		class fg_txt_sharpness: RscText
		{
			idc = 6420;

			text = "Sharpness"; //--- ToDo: Localize;
			x = 0.476279 * safezoneW + safezoneX;
			y = 0.3614 * safezoneH + safezoneY;
			w = 0.0464065 * safezoneW;
			h = 0.0176 * safezoneH;
		};
		class fg_txt_intensity: RscText
		{
			idc = 6421;

			text = "Intensity"; //--- ToDo: Localize;
			x = 0.368002 * safezoneW + safezoneX;
			y = 0.3614 * safezoneH + safezoneY;
			w = 0.0464065 * safezoneW;
			h = 0.0176 * safezoneH;
		};
		class fg_txt_GS: RscText
		{
			idc = 6422;

			text = "Grain Size"; //--- ToDo: Localize;
			x = 0.588687 * safezoneW + safezoneX;
			y = 0.3614 * safezoneH + safezoneY;
			w = 0.0464065 * safezoneW;
			h = 0.0176 * safezoneH;
		};
		class fg_txt_intensityx0: RscText
		{
			idc = 6423;

			text = "Intensity X0"; //--- ToDo: Localize;
			x = 0.357688 * safezoneW + safezoneX;
			y = 0.4274 * safezoneH + safezoneY;
			w = 0.0546564 * safezoneW;
			h = 0.0176 * safezoneH;
		};
		class fg_txt_intensityx1: RscText
		{
			idc = 6424;

			text = "Intensity X1"; //--- ToDo: Localize;
			x = 0.471122 * safezoneW + safezoneX;
			y = 0.4274 * safezoneH + safezoneY;
			w = 0.0546564 * safezoneW;
			h = 0.0176 * safezoneH;
		};
		class fg_txt_mono: RscText
		{
			idc = 6425;

			text = "Monochromic:"; //--- ToDo: Localize;
			x = 0.572185 * safezoneW + safezoneX;
			y = 0.4494 * safezoneH + safezoneY;
			w = 0.0587812 * safezoneW;
			h = 0.0176 * safezoneH;
		};
		//sliders
		class fg_slider_sharpness: RscSlider
		{
			idc = 6430;

			x = 0.450501 * safezoneW + safezoneX;
			y = 0.3834 * safezoneH + safezoneY;
			w = 0.0989998 * safezoneW;
			h = 0.0308 * safezoneH;
			onSliderPosChanged = "_this call rmx_fnc_ppViewerEffects;";
		};
		class fg_slider_intensity: RscSlider
		{
			idc = 6431;

			x = 0.337062 * safezoneW + safezoneX;
			y = 0.3834 * safezoneH + safezoneY;
			w = 0.0989998 * safezoneW;
			h = 0.0308 * safezoneH;
			onSliderPosChanged = "_this call rmx_fnc_ppViewerEffects;";
		};
		class fg_slider_gs: RscSlider
		{
			idc = 6432;

			x = 0.563937 * safezoneW + safezoneX;
			y = 0.3834 * safezoneH + safezoneY;
			w = 0.0989998 * safezoneW;
			h = 0.0308 * safezoneH;
			onSliderPosChanged = "_this call rmx_fnc_ppViewerEffects;";
		};

		class fg_slider_intensityx0: RscSlider
		{
			idc = 6433;

			x = 0.337064 * safezoneW + safezoneX;
			y = 0.4494 * safezoneH + safezoneY;
			w = 0.0989998 * safezoneW;
			h = 0.0308 * safezoneH;
			onSliderPosChanged = "_this call rmx_fnc_ppViewerEffects;";
		};

		class fg_slider_intensityx1: RscSlider
		{
			idc = 6434;

			x = 0.450489 * safezoneW + safezoneX;
			y = 0.44977 * safezoneH + safezoneY;
			w = 0.0989998 * safezoneW;
			h = 0.0308 * safezoneH;
			onSliderPosChanged = "_this call rmx_fnc_ppViewerEffects;";
		};

		//checkbox
		class fg_bool: RscCheckbox
		{
			idc = 6440;
			x = 0.630971 * safezoneW + safezoneX;
			y = 0.4428 * safezoneH + safezoneY;
			w = 0.0175312 * safezoneW;
			h = 0.0308 * safezoneH;
			onCheckedChanged = "_this call rmx_fnc_ppViewerEffects;";
		};

		//Radial blur
		//background
		class rb_bckgrnd: IGUIBack
		{
			idc = 6510;

			x = 0.335 * safezoneW + safezoneX;
			y = 0.335 * safezoneH + safezoneY;
			w = 0.33 * safezoneW;
			h = 0.11 * safezoneH;
			colorBackground[] = {0,0,0,0.5};
		};

		//text
		class rb_txt_rX: RscText
		{
			idc = 6520;

			text = "Relative X:"; //--- ToDo: Localize;
			x = 0.337064 * safezoneW + safezoneX;
			y = 0.3614 * safezoneH + safezoneY;
			w = 0.0505312 * safezoneW;
			h = 0.0176 * safezoneH;
		};
		class rb_txt_rY: RscText
		{
			idc = 6521;

			text = "Relative Y:"; //--- ToDo: Localize;
			x = 0.502066 * safezoneW + safezoneX;
			y = 0.3614 * safezoneH + safezoneY;
			w = 0.0505312 * safezoneW;
			h = 0.0176 * safezoneH;
		};
		class rb_txt_cX: RscText
		{
			idc = 6522;

			text = "Centre X:"; //--- ToDo: Localize;
			x = 0.337064 * safezoneW + safezoneX;
			y = 0.4054 * safezoneH + safezoneY;
			w = 0.0505312 * safezoneW;
			h = 0.0176 * safezoneH;
		};
		class rb_txt_cY: RscText
		{
			idc = 6523;

			text = "Centre Y:"; //--- ToDo: Localize;
			x = 0.502063 * safezoneW + safezoneX;
			y = 0.4054 * safezoneH + safezoneY;
			w = 0.0505312 * safezoneW;
			h = 0.0176 * safezoneH;
		};

		//sliders
		class rb_slider_rX: RscSlider
		{
			idc = 6530;

			x = 0.398937 * safezoneW + safezoneX;
			y = 0.3614 * safezoneH + safezoneY;
			w = 0.0989998 * safezoneW;
			h = 0.0308 * safezoneH;
			onSliderPosChanged = "_this call rmx_fnc_ppViewerEffects;";
		};

		class rb_slider_rY: RscSlider
		{
			idc = 6531;

			x = 0.563938 * safezoneW + safezoneX;
			y = 0.3614 * safezoneH + safezoneY;
			w = 0.0989998 * safezoneW;
			h = 0.0308 * safezoneH;
			onSliderPosChanged = "_this call rmx_fnc_ppViewerEffects;";
		};
		class rb_slider_cX: RscSlider
		{
			idc = 6532;

			x = 0.398937 * safezoneW + safezoneX;
			y = 0.4054 * safezoneH + safezoneY;
			w = 0.0989998 * safezoneW;
			h = 0.0308 * safezoneH;
			onSliderPosChanged = "_this call rmx_fnc_ppViewerEffects;";
		};
		class rb_slider_cY: RscSlider
		{
			idc = 6533;

			x = 0.563937 * safezoneW + safezoneX;
			y = 0.4054 * safezoneH + safezoneY;
			w = 0.0989998 * safezoneW;
			h = 0.0308 * safezoneH;
			onSliderPosChanged = "_this call rmx_fnc_ppViewerEffects;";
		};

		//Water distrortion
		//background
		class wd_bckgrnd: IGUIBack
		{
			idc = 6610;

			x = 0.335 * safezoneW + safezoneX;
			y = 0.335 * safezoneH + safezoneY;
			w = 0.33 * safezoneW;
			h = 0.308 * safezoneH;
			colorBackground[] = {0,0,0,0.5};
		};

		//text
		class wd_txt_blur: RscText
		{
			idc = 6620;

			text = "Blurriness"; //--- ToDo: Localize;
			x = 0.365935 * safezoneW + safezoneX;
			y = 0.3614 * safezoneH + safezoneY;
			w = 0.0505312 * safezoneW;
			h = 0.0176 * safezoneH;
		};
		class wd_txt_sT: RscText
		{
			idc = 6621;

			text = "Strength Top"; //--- ToDo: Localize;
			x = 0.469066 * safezoneW + safezoneX;
			y = 0.3614 * safezoneH + safezoneY;
			w = 0.0598124 * safezoneW;
			h = 0.0176 * safezoneH;
		};
		class wd_txt_sB: RscText
		{
			idc = 6622;

			text = "Strength Bottom"; //--- ToDo: Localize;
			x = 0.575282 * safezoneW + safezoneX;
			y = 0.3614 * safezoneH + safezoneY;
			w = 0.0732187 * safezoneW;
			h = 0.0176 * safezoneH;
		};
		class wd_txt_wS: RscText
		{
			idc = 6623;

			text = "Wave speed"; //--- ToDo: Localize;
			x = 0.357687 * safezoneW + safezoneX;
			y = 0.4494 * safezoneH + safezoneY;
			w = 0.0567186 * safezoneW;
			h = 0.0176 * safezoneH;
		};
		class wd_txt_wA: RscText
		{
			idc = 6624;

			text = "Wave amplitudes"; //--- ToDo: Localize;
			x = 0.461842 * safezoneW + safezoneX;
			y = 0.4494 * safezoneH + safezoneY;
			w = 0.0763125 * safezoneW;
			h = 0.0176 * safezoneH;
		};
		class wd_txt_PC: RscText
		{
			idc = 6625;

			text = "Phase Coefficients"; //--- ToDo: Localize;
			x = 0.572189 * safezoneW + safezoneX;
			y = 0.4494 * safezoneH + safezoneY;
			w = 0.0835313 * safezoneW;
			h = 0.0176 * safezoneH;
		};

		//sliders
		class wd_slider_blur: RscSlider
		{
			idc = 6630;

			x = 0.337064 * safezoneW + safezoneX;
			y = 0.3834 * safezoneH + safezoneY;
			w = 0.0989998 * safezoneW;
			h = 0.0308 * safezoneH;
			onSliderPosChanged = "_this call rmx_fnc_ppViewerEffects;";
		};

		class wd_slider_sT: RscSlider
		{
			idc = 6631;

			x = 0.4505 * safezoneW + safezoneX;
			y = 0.383333 * safezoneH + safezoneY;
			w = 0.0989998 * safezoneW;
			h = 0.0308 * safezoneH;
			onSliderPosChanged = "_this call rmx_fnc_ppViewerEffects;";
		};
		class wd_slider_sB: RscSlider
		{
			idc = 6632;

			x = 0.564041 * safezoneW + safezoneX;
			y = 0.382756 * safezoneH + safezoneY;
			w = 0.0989998 * safezoneW;
			h = 0.0308 * safezoneH;
			onSliderPosChanged = "_this call rmx_fnc_ppViewerEffects;";
		};

		class wd_slider_wS1: RscSlider
		{
			idc = 6633;

			x = 0.337063 * safezoneW + safezoneX;
			y = 0.4714 * safezoneH + safezoneY;
			w = 0.0989998 * safezoneW;
			h = 0.0308 * safezoneH;
			onSliderPosChanged = "_this call rmx_fnc_ppViewerEffects;";
		};
		class wd_slider_wS2: RscSlider
		{
			idc = 6634;

			x = 0.337468 * safezoneW + safezoneX;
			y = 0.515511 * safezoneH + safezoneY;
			w = 0.0989998 * safezoneW;
			h = 0.0308 * safezoneH;
			onSliderPosChanged = "_this call rmx_fnc_ppViewerEffects;";
		};
		class wd_slider_wS3: RscSlider
		{
			idc = 6635;

			x = 0.336958 * safezoneW + safezoneX;
			y = 0.55903 * safezoneH + safezoneY;
			w = 0.0989998 * safezoneW;
			h = 0.0308 * safezoneH;
			onSliderPosChanged = "_this call rmx_fnc_ppViewerEffects;";
		};
		class wd_slider_wS4: RscSlider
		{
			idc = 6636;

			x = 0.336958 * safezoneW + safezoneX;
			y = 0.602896 * safezoneH + safezoneY;
			w = 0.0989998 * safezoneW;
			h = 0.0308 * safezoneH;
			onSliderPosChanged = "_this call rmx_fnc_ppViewerEffects;";
		};
		class wd_slider_wA1: RscSlider
		{
			idc = 6637;

			x = 0.45051 * safezoneW + safezoneX;
			y = 0.470719 * safezoneH + safezoneY;
			w = 0.0989998 * safezoneW;
			h = 0.0308 * safezoneH;
			onSliderPosChanged = "_this call rmx_fnc_ppViewerEffects;";
		};
		class wd_slider_wA2: RscSlider
		{
			idc = 6638;

			x = 0.4505 * safezoneW + safezoneX;
			y = 0.5154 * safezoneH + safezoneY;
			w = 0.0989998 * safezoneW;
			h = 0.0308 * safezoneH;
			onSliderPosChanged = "_this call rmx_fnc_ppViewerEffects;";
		};
		class wd_slider_wA3: RscSlider
		{
			idc = 6639;

			x = 0.45102 * safezoneW + safezoneX;
			y = 0.55903 * safezoneH + safezoneY;
			w = 0.0989998 * safezoneW;
			h = 0.0308 * safezoneH;
			onSliderPosChanged = "_this call rmx_fnc_ppViewerEffects;";
		};
		class wd_slider_wA4: RscSlider
		{
			idc = 6640;

			x = 0.4505 * safezoneW + safezoneX;
			y = 0.603704 * safezoneH + safezoneY;
			w = 0.0989998 * safezoneW;
			h = 0.0308 * safezoneH;
			onSliderPosChanged = "_this call rmx_fnc_ppViewerEffects;";
		};
		class wd_slider_pC1: RscSlider
		{
			idc = 6641;

			x = 0.563938 * safezoneW + safezoneX;
			y = 0.4714 * safezoneH + safezoneY;
			w = 0.0989998 * safezoneW;
			h = 0.0308 * safezoneH;
			onSliderPosChanged = "_this call rmx_fnc_ppViewerEffects;";
		};
		class wd_slider_pC2: RscSlider
		{
			idc = 6642;

			x = 0.563937 * safezoneW + safezoneX;
			y = 0.5154 * safezoneH + safezoneY;
			w = 0.0989998 * safezoneW;
			h = 0.0308 * safezoneH;
			onSliderPosChanged = "_this call rmx_fnc_ppViewerEffects;";
		};
		class wd_slider_pC3: RscSlider
		{
			idc = 6643;

			x = 0.563937 * safezoneW + safezoneX;
			y = 0.5594 * safezoneH + safezoneY;
			w = 0.0989998 * safezoneW;
			h = 0.0308 * safezoneH;
			onSliderPosChanged = "_this call rmx_fnc_ppViewerEffects;";
		};
		class wd_slider_pC4: RscSlider
		{
			idc = 6644;

			x = 0.563938 * safezoneW + safezoneX;
			y = 0.6034 * safezoneH + safezoneY;
			w = 0.0989998 * safezoneW;
			h = 0.0308 * safezoneH;
			onSliderPosChanged = "_this call rmx_fnc_ppViewerEffects;";
		};

		//Dynamic blur
		//background
		class db_bckgrnd: IGUIBack
		{
			idc = 6710;

			x = 0.335 * safezoneW + safezoneX;
			y = 0.335 * safezoneH + safezoneY;
			w = 0.33 * safezoneW;
			h = 0.088 * safezoneH;
			colorBackground[] = {0,0,0,0.5};
		};

		//text
		class db_txt_blur: RscText
		{
			idc = 6720;

			text = "Bluriness"; //--- ToDo: Localize;
			x = 0.478344 * safezoneW + safezoneX;
			y = 0.3614 * safezoneH + safezoneY;
			w = 0.0598124 * safezoneW;
			h = 0.0176 * safezoneH;
		};
		//slider
		class db_slider_blur: RscSlider
		{
			idc = 6730;

			x = 0.4505 * safezoneW + safezoneX;
			y = 0.3834 * safezoneH + safezoneY;
			w = 0.0989998 * safezoneW;
			h = 0.0308 * safezoneH;
			onSliderPosChanged = "_this call rmx_fnc_ppViewerEffects;";
		};

		//Color Inversion
		//background
		class ci_bckgrnd: IGUIBack
		{
			idc = 6810;

			x = 0.335 * safezoneW + safezoneX;
			y = 0.335 * safezoneH + safezoneY;
			w = 0.33 * safezoneW;
			h = 0.088 * safezoneH;
			colorBackground[] = {0,0,0,0.5};
		};
		//text
		class ci_txt_red: RscText
		{
			idc = 6820;

			text = "Red"; //--- ToDo: Localize;
			x = 0.378309 * safezoneW + safezoneX;
			y = 0.3614 * safezoneH + safezoneY;
			w = 0.022688 * safezoneW;
			h = 0.0176 * safezoneH;
		};
		class ci_txt_green: RscText
		{
			idc = 6821;

			text = "Green"; //--- ToDo: Localize;
			x = 0.485561 * safezoneW + safezoneX;
			y = 0.3614 * safezoneH + safezoneY;
			w = 0.0288754 * safezoneW;
			h = 0.0176 * safezoneH;
		};
		class ci_txt_blue: RscText
		{
			idc = 6822;

			text = "Blue"; //--- ToDo: Localize;
			x = 0.601987 * safezoneW + safezoneX;
			y = 0.361807 * safezoneH + safezoneY;
			w = 0.0247506 * safezoneW;
			h = 0.0176 * safezoneH;
		};
		//sliders
		class ci_slider_red: RscSlider
		{
			idc = 6830;

			x = 0.337064 * safezoneW + safezoneX;
			y = 0.3834 * safezoneH + safezoneY;
			w = 0.0989998 * safezoneW;
			h = 0.0308 * safezoneH;
			onSliderPosChanged = "_this call rmx_fnc_ppViewerEffects;";
		};
		class ci_slider_green: RscSlider
		{
			idc = 6831;

			x = 0.450501 * safezoneW + safezoneX;
			y = 0.3834 * safezoneH + safezoneY;
			w = 0.0989998 * safezoneW;
			h = 0.0308 * safezoneH;
			onSliderPosChanged = "_this call rmx_fnc_ppViewerEffects;";
		};
		class ci_slider_blue: RscSlider
		{
			idc = 6832;

			x = 0.563938 * safezoneW + safezoneX;
			y = 0.3834 * safezoneH + safezoneY;
			w = 0.0989998 * safezoneW;
			h = 0.0308 * safezoneH;
			onSliderPosChanged = "_this call rmx_fnc_ppViewerEffects;";
		};
	};
};