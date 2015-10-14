class rmx_dynamenu {
	idd = 66600;
	enableSimulation = 1;
	movingEnable = 1;
	onLoad = "setMousePosition [0.5, 0.5];";
	class controls {};
};

class rmx_rscPicture: RscPicture {
	idc = -1;
	x = 0.425; y = 0.4; w = 0.15; h = 0.2;
	text = "";
};

class rmx_rscObject
{
 
	idd = 77770;
	movingEnable = 0;
	enableSimulation = 1;
 
	class Objects 
	{
		class randomItem //pref less polies for starting item
		{

			idc = 77771; 
			type = 82;
			model = "\x\addons\a3_epoch_assets\models\logo.p3d";
			scale = 1;
			
			direction[] = {0, -0.35, -0.65};
			up[] = {0, 0.65, -0.35}; 

			x = 0.5;
			y = 0.5;
			z = 0.2;

			xBack = 0.5;
			yBack = 0.5;
			zBack = 1.2;

			inBack = 1;
			enableZoom = 0;
			zoomDuration = 0.001;
		};
	};
};

class rmx_rscControlsGroup: RscControlsGroup
{
	idc = -1;

	x = 0; y = 0; w = 0; h = 0;
	colorBackground[] = {0,0,0,0};
	
	class VScrollbar: VScrollbar
	{
		width = 0;
	};
	class HScrollbar: VScrollbar
	{
		height = 0;
	};
	class controls {};
};

class rmx_craftingUI {
	idd = 77700;
	enableSimulation = 1;
	movingEnable = 1;
	onUnload = "call EPOCH_crafting_unload;";
	onLoad = "setMousePosition [0.5, 0.5];";
	
	class Objects 
	{
		class randomItem2 //pref less polies for starting item
		{

			idc = 77701; 
			type = 82;
			model = "\x\addons\a3_epoch_assets\models\logo.p3d";
			scale = 1;
			
			direction[] = {0, -0.35, -0.65};
			up[] = {0, 0.65, -0.35}; 

			x = 0.8125;
			y = 0.287782;
			z = 1;

			xBack = 0.8125;
			yBack = 0.287782;
			zBack = 1.2;

			inBack = 1;
			enableZoom = 0;
			zoomDuration = 0.001;
		};
	};
	
	class controls
	{
		//Developer menu (DISABLE ON RELEASE)
		
		//background
		class dev_backgrnd: IGUIBack
		{
			idc = 77703;
			x = 0.710375 * safezoneW + safezoneX;
			y = 0.224906 * safezoneH + safezoneY;
			w = 0.0845625 * safezoneW;
			h = 0.22001 * safezoneH;
			colorBackground[] = {0,0,0,0.5};
			onLoad = "(_this select 0) ctrlShow false";
		};
		
		//buttons
		class dev_btn_pic: RscPicture
		{
			idc = 77702;

			text = "x\addons\a3_epoch_code\Data\UI\dev_mode_off.paa";
			x = 0.795;
			y = -0.064;
			w = 0.2;
			h = 0.075;
			onLoad = "(_this select 0) ctrlShow false";
			onMouseButtonDown = "call EPOCH_crafting_dev_toggle;";
		};
		class dev_btn_set: RscButton
		{
			idc = 77704;
			text = "Set"; //--- ToDo: Localize;
			x = 0.770187 * safezoneW + safezoneX;
			y = 0.2316 * safezoneH + safezoneY;
			w = 0.020625 * safezoneW;
			h = 0.022 * safezoneH;
			onLoad = "(_this select 0) ctrlShow false";
		};
		class dev_btn_rpt: RscButton
		{
			idc = 77705;
			text = "Export"; //--- ToDo: Localize;
			x = 0.712437 * safezoneW + safezoneX;
			y = 0.414171 * safezoneH + safezoneY;
			w = 0.0804375 * safezoneW;
			h = 0.022 * safezoneH;
			onLoad = "(_this select 0) ctrlShow false";
		};
		class dev_btn_setPos: RscButton
		{
			idc = 77706;
			onLoad = "(_this select 0) ctrlShow false";

			text = "Set Position"; //--- ToDo: Localize;
			x = 0.712575 * safezoneW + safezoneX;
			y = 0.384407 * safezoneH + safezoneY;
			w = 0.0804375 * safezoneW;
			h = 0.022 * safezoneH;
		};
		class dev_btn_vectorPlus: RscButton
		{
			idc = 77707;
			onLoad = "(_this select 0) ctrlShow false";

			text = "+"; //--- ToDo: Localize;
			x = 0.778437 * safezoneW + safezoneX;
			y = 0.266721 * safezoneH + safezoneY;
			w = 0.012375 * safezoneW;
			h = 0.022 * safezoneH;
			action = "rmx_var_3dCtrlSpin_Vector = rmx_var_3dCtrlSpin_Vector + 0.1; (rmx_var_crafting_ctrl_DEV select 10) ctrlSetText str rmx_var_3dCtrlSpin_Vector;";
		};
		class dev_btn_vectorMinus: RscButton
		{
			idc = 77708;
			onLoad = "(_this select 0) ctrlShow false";

			text = "-"; //--- ToDo: Localize;
			x = 0.73925 * safezoneW + safezoneX;
			y = 0.266721 * safezoneH + safezoneY;
			w = 0.012375 * safezoneW;
			h = 0.022 * safezoneH;
			action = "rmx_var_3dCtrlSpin_Vector = rmx_var_3dCtrlSpin_Vector - 0.1; (rmx_var_crafting_ctrl_DEV select 10) ctrlSetText str rmx_var_3dCtrlSpin_Vector;";
		};
		//edit

		class dev_edit_scale: RscEdit
		{
			idc = 77709;
			text = "1"; //--- ToDo: Localize;
			x = 0.743375 * safezoneW + safezoneX;
			y = 0.2316 * safezoneH + safezoneY;
			w = 0.02475 * safezoneW;
			h = 0.022 * safezoneH;
			onLoad = "(_this select 0) ctrlShow false";
		};
		class dev_edit_x: RscEdit
		{
			idc = 77710;
			onLoad = "(_this select 0) ctrlShow false";

			text = "0.123456"; //--- ToDo: Localize;
			x = 0.748524 * safezoneW + safezoneX;
			y = 0.2998 * safezoneH + safezoneY;
			w = 0.0443435 * safezoneW;
			h = 0.022 * safezoneH;
		};
		class dev_edit_z: RscEdit
		{
			idc = 77711;
			onLoad = "(_this select 0) ctrlShow false";

			text = "0.123456"; //--- ToDo: Localize;
			x = 0.748948 * safezoneW + safezoneX;
			y = 0.325807 * safezoneH + safezoneY;
			w = 0.0443435 * safezoneW;
			h = 0.022 * safezoneH;
		};
		class dev_edit_y: RscEdit
		{
			idc = 77712;
			onLoad = "(_this select 0) ctrlShow false";

			text = "0.123456"; //--- ToDo: Localize;
			x = 0.749458 * safezoneW + safezoneX;
			y = 0.352082 * safezoneH + safezoneY;
			w = 0.0443435 * safezoneW;
			h = 0.022 * safezoneH;
		};
		class dev_edit_vector: RscEdit
		{
			idc = 77713;
			onLoad = "(_this select 0) ctrlShow false";

			text = "0"; //--- ToDo: Localize;
			x = 0.755234 * safezoneW + safezoneX;
			y = 0.267601 * safezoneH + safezoneY;
			w = 0.0195937 * safezoneW;
			h = 0.022 * safezoneH;
		};
		//text
		class dev_txt_scale: RscText
		{
			idc = 77714;
			text = "Scale:"; //--- ToDo: Localize;
			x = 0.712437 * safezoneW + safezoneX;
			y = 0.2338 * safezoneH + safezoneY;
			w = 0.028875 * safezoneW;
			h = 0.0154 * safezoneH;
			onLoad = "(_this select 0) ctrlShow false";
		};
		class dev_txt_X: RscText
		{
			idc = 77715;
			onLoad = "(_this select 0) ctrlShow false";

			text = "X:"; //--- ToDo: Localize;
			x = 0.712703 * safezoneW + safezoneX;
			y = 0.303578 * safezoneH + safezoneY;
			w = 0.028875 * safezoneW;
			h = 0.0154 * safezoneH;
		};
		class dev_txt_z: RscText
		{
			idc = 77716;
			onLoad = "(_this select 0) ctrlShow false";

			text = "Z:"; //--- ToDo: Localize;
			x = 0.712543 * safezoneW + safezoneX;
			y = 0.329511 * safezoneH + safezoneY;
			w = 0.028875 * safezoneW;
			h = 0.0154 * safezoneH;
		};
		class dev_txt_y: RscText
		{
			idc = 77717;
			onLoad = "(_this select 0) ctrlShow false";

			text = "Y:"; //--- ToDo: Localize;
			x = 0.712564 * safezoneW + safezoneX;
			y = 0.356482 * safezoneH + safezoneY;
			w = 0.028875 * safezoneW;
			h = 0.0154 * safezoneH;
		};
		class dev_txt_3D: RscText //3d preview red
		{
			idc = 77718;

			text = "";
			x = 0.6;
			y = 0.04;
			w = 0.4;
			h = 0.44;
			colorBackground[] = {1,0,0,0.3};
			onLoad = "(_this select 0) ctrlShow false";
		};
		class dev_txt_Vector: RscText
		{
			idc = 77719;
			onLoad = "(_this select 0) ctrlShow false";

			text = "vUP:"; //--- ToDo: Localize;
			x = 0.712437 * safezoneW + safezoneX;
			y = 0.268921 * safezoneH + safezoneY;
			w = 0.0226875 * safezoneW;
			h = 0.0154 * safezoneH;
		};
		// ----------- MAIN GUI PART ----------- //
		//background
		class rmx_cUI_back: IGUIBack
		{
			idc = 77800;

			x = 0;
			y = 0;
			w = 1;
			h = 1;
			colorBackground[] = {0,0,0,0.1};
			onLoad = "_cl = _this select 0; _cl ctrlSetFade 1; _cl ctrlCommit 0; _cl ctrlSetFade 0; _cl ctrlCommit 1;";
		};
		//Buttons
		class rmx_cUI_btn_craft: RscPicture
		{
			idc = 77801;
			text = "\x\addons\a3_epoch_code\Data\UI\crafting\close.paa";
			x = 0.9;
			y = 0.92;
			w = 0.1;
			h = 0.08;
			onLoad = "[(_this select 0),[1,0.92,0,0.08],[0.9,0.92,0.1,0.08]] call EPOCH_crafting_animate;";
			onMouseButtonUp = "call epoch_crafting_craft;";
		};
		class rmx_cUI_btn_clear: RscButton
		{
			idc = 77802;
			text = "X"; //--- ToDo: Localize;
			x = 0.26;
			y = 0.04;
			w = 0.04;
			h = 0.052;
			onLoad = "[(_this select 0),[0.26,0.04,0,0],[0.26,0.04,0.04,0.052]] call EPOCH_crafting_animate;";
			action = "(rmx_var_crafting_ctrl_Interact select 4) ctrlSetText ''; lbClear (rmx_var_crafting_ctrl_main select 1);";
		};
		//Progressbar
		class rmx_cUI_pb: RscProgress
		{
			idc = 77803;
			texture = "#(argb,8,8,3)color(1,1,1,1)";
			textureExt = "";
			colorBar[] = {1, 1, 1, 0.1};
			colorExtBar[] = {1, 1, 1, 1};
			colorFrame[] = {1, 1, 1, 1};
			x = 0.6;
			y = 0.92;
			w = 0.3;
			h = 0.08;
			
			onLoad = "[(_this select 0),[0.6,0.92,0,0.08],[0.6,0.92,0.3,0.08]] call EPOCH_crafting_animate; (_this select 0) ctrlEnable true;";
			onMouseMoving = "if (rmx_var_crafting_progressClicked && rmx_var_craftQTY != 0) then {_c = _this select 0; _p = ctrlPosition _c; _c progressSetPosition (linearConversion [_p select 0, (_p select 0)+ (_p select 2), (_this select 1), 0, 1, false]);};";
			onMouseHolding = "if (rmx_var_crafting_progressClicked && rmx_var_craftQTY != 0) then {_c = _this select 0; _p = ctrlPosition _c; _c progressSetPosition (linearConversion [_p select 0, (_p select 0)+ (_p select 2), (_this select 1), 0, 1, false]);};";
			onMouseButtonDown = "rmx_var_crafting_progressClicked = true;";
			onMouseButtonUp = "rmx_var_crafting_progressClicked = false;";
		};
		//progressbar QTY
		class rmx_cUI_txt_QTY: RscText
		{
			idc = 77804;
			style = 0x02; //vcenter = 0x0c
			text = "";
			x = 0.6;
			y = 0.92;
			w = 0.3;
			h = 0.08;
			colorBackground[] = {0,0,0,0.2};
			colorText[] = {1,0.6,0.01,1};
			onLoad = "[(_this select 0),[0.6,0.92,0,0.08],[0.6,0.92,0.3,0.08]] call EPOCH_crafting_animate;";
		};

		//Progressbar + / -
		class rmx_cUI_img_plus: RscPicture
		{
			idc = 77805;
			text = "x\addons\a3_epoch_code\Data\UI\craftqty_arr_right.paa";
			x = 0.84;
			y = 0.92;
			w = 0.06;
			h = 0.08;
			onLoad = "_c = _this select 0; _c ctrlSetFade 1; _c ctrlCommit 0; _c ctrlSetFade 0; _c ctrlCommit 1;";
		};
		class rmx_cUI_img_minus: RscPicture
		{
			idc = 77806;
			text = "x\addons\a3_epoch_code\Data\UI\craftqty_arr_left.paa";
			x = 0.6;
			y = 0.92;
			w = 0.06;
			h = 0.08;
			onLoad = "_c = _this select 0; _c ctrlSetFade 1; _c ctrlCommit 0; _c ctrlSetFade 0; _c ctrlCommit 1;";
		};

		//edit
		class rmx_cUI_edit_searchField: RscEdit
		{
			idc = 77810;
			text = ""; //--- ToDo: Localize;
			x = 0.0025;
			y = 0.04;
			w = 0.2575;
			h = 0.052;
			colorBackground[] = {0,0,0,0.5};
			onLoad = "[(_this select 0),[0.0025,0.04,0,0.052],[0.0025,0.04,0.2575,0.052]] call EPOCH_crafting_animate;";
		};

		//listboxes
		class rmx_cUI_LB_recipes: RscListbox
		{
			idc = 77811;
			x = 0;
			y = 0.092;
			w = 0.3;
			h = 0.908;
			onLoad = "[(_this select 0),[0,0.092,0.3,0],[0,0.092,0.3,0.908]] call EPOCH_crafting_animate;";
			onLBSelChanged = "call EPOCH_crafting_LB_click;";
		};
		class rmx_cUI_LB_ingredients: RscListbox
		{
			idc = 77812;
			x = 0.3;
			y = 0.04;
			w = 0.3;
			h = 0.96;
			onLoad = "[(_this select 0),[0.3,0.04,0.3,0],[0.3,0.04,0.3,0.96]] call EPOCH_crafting_animate;";
			onLBDblClick = "call EPOCH_crafting_LB_doubleClick;";
		};
		
		//Structured Text

		class rmx_cUI_st_description: RscStructuredText
		{
			idc = 77820;
			text = "..............................."; //--- ToDo: Localize;
			x = 0.6;
			y = 0.524;
			w = 0.4;
			h = 0.392;
			colorBackground[] = {0,0,0,0};
		};

		//Text
		class rmx_cUI_txt_recipes: RscText
		{
			idc = 77840;

			text = "Recipes"; //--- ToDo: Localize;
			x = 0;
			y = 0;
			w = 0.3;
			h = 0.04;
			colorBackground[] = {0,0,0,0.8};
			onLoad = "[(_this select 0),[0,0,0,0.04],[0,0,0.3,0.04]] call EPOCH_crafting_animate;";
		};

		class rmx_cUI_txt_ingredients: RscText
		{
			idc = 77841;

			text = "Ingredients"; //--- ToDo: Localize;
			x = 0.3;
			y = 0;
			w = 0.2975;
			h = 0.04;
			colorBackground[] = {0,0,0,0.8};
			onLoad = "[(_this select 0),[0.3,0,0,0.04],[0.3,0,0.2975,0.04]] call EPOCH_crafting_animate;";
		};
		class rmx_cUI_txt_preview: RscText
		{
			idc = 77842;

			text = "Preview"; //--- ToDo: Localize;
			x = 0.6;
			y = 0;
			w = 0.3975;
			h = 0.04;
			colorBackground[] = {1,0.6,0.01,0.8};
			onLoad = "[(_this select 0),[0.6,0,0,0.04],[0.6,0,0.3975,0.04]] call EPOCH_crafting_animate;";
		};
		class rmx_cUI_txt_resources: RscText
		{
			idc = 77843;

			text = "Resources"; //--- ToDo: Localize;
			x = 0.3;
			y = 0.96;
			w = 0.2975;
			h = 0.04;
			colorBackground[] = {0,0,0,0.8};
			onLoad = "(_this select 0) ctrlShow false";
		};
		class rmx_cUI_txt_description: RscText
		{
			idc = 77844;

			text = "Description"; //--- ToDo: Localize;
			x = 0.6;
			y = 0.48;
			w = 0.3975;
			h = 0.04;
			colorBackground[] = {0,0,0,0.8};
			onLoad = "[(_this select 0),[0.6,0.48,0,0.04],[0.6,0.48,0.3975,0.04]] call EPOCH_crafting_animate;";
		};
		//frames
		class rmx_cUI_frame_recipes: RscFrame
		{
			idc = 77830;
			x = 0;
			y = 0;
			w = 0.3;
			h = 1;
		};
		class rmx_cUI_frame_craft: RscFrame
		{
			idc = 77831;
			x = 0.3;
			y = 0;
			w = 0.3;
			h = 1;
		};

		class rmx_cUI_frame_preview: RscFrame
		{
			idc = 77832;
			x = 0.6;
			y = 0;
			w = 0.4;
			h = 0.48;
		};
		class rmx_cUI_frame_resources: RscFrame
		{
			idc = 77833;
			x = 0.3;
			y = 0.92;
			w = 0.3;
			h = 0.08;
			onLoad = "(_this select 0) ctrlShow false";
		};
		class rmx_cUI_frame_description: RscFrame
		{
			idc = 77834;
			x = 0.6;
			y = 0.48;
			w = 0.4;
			h = 0.44;
		};
		class rmx_cUI_frame_qty: RscFrame
		{
			idc = 77835;
			x = 0.6;
			y = 0.92;
			w = 0.4;
			h = 0.08;
		};
	};
};

class Epoch_main_config_group: RscControlsGroupNoScrollbars
{
	idc = -1;
	x = 17 * GUI_GRID_W + GUI_GRID_X;
	y = 2.5 * GUI_GRID_H + GUI_GRID_Y;
	w = 40 * GUI_GRID_W;
	h = 19.5 * GUI_GRID_H;
	class controls{};
};
class Epoch_main_config_title: RscText
{
	idc = -1;
	x = 17 * GUI_GRID_W + GUI_GRID_X;
	y = 0.5 * GUI_GRID_H + GUI_GRID_Y;
	w = 40 * GUI_GRID_W;
	h = 1 * GUI_GRID_H;
	text = "Epoch Configuration";
	colorBackground[] = {0.76,0.5,0.07,0.8};
	colorText[] = {1,1,1,1};
	shadow = 1;
};

class Epoch_main_config_combo: RscCombo
{
	idc = -1;
	x = 17 * GUI_GRID_W + GUI_GRID_X;
	y = 1.5 * GUI_GRID_H + GUI_GRID_Y;
	w = 40 * GUI_GRID_W;
	h = 1 * GUI_GRID_H;
	colorSelect[] = {0.1,0.1,0.1,1};
	colorText[] = {1,1,1,1.0};
	colorBackground[] = {0.1,0.1,0.1,1};
	colorSelectBackground[] = {0.76,0.5,0.07,1};
	colorScrollbar[] = {1,0,0,1};
	
	wholeHeight = 5 * GUI_GRID_CENTER_H;
	colorActive[] = {1,0,0,1};

	colorTextRight[] = {1,1,1,1};
	colorSelectRight[] = {0,0,0,1};
	colorSelect2Right[] = {0,0,0,1};
	
	class ComboScrollBar: ScrollBar
	{
		width = 0; // width of ComboScrollBar
		height = 0; // height of ComboScrollBar
		scrollSpeed = 0.01; // scrollSpeed of ComboScrollBar

		arrowEmpty = "\A3\ui_f\data\gui\cfg\scrollbar\arrowEmpty_ca.paa"; // Arrow
		arrowFull = "\A3\ui_f\data\gui\cfg\scrollbar\arrowFull_ca.paa"; // Arrow when clicked on
		border = "\A3\ui_f\data\gui\cfg\scrollbar\border_ca.paa"; // Slider background (stretched vertically)
		thumb = "\A3\ui_f\data\gui\cfg\scrollbar\thumb_ca.paa"; // Dragging element (stretched vertically)

		color[] = {1,1,1,1};
	};

	onLBSelChanged = "_this call EPOCH_InterruptConfigActions;";
};