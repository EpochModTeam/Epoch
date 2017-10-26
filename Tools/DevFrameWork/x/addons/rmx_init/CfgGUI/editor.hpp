/* #Wekeqo
$[
	1.063,
	["console",[[0,0,1,1],0.025,0.04,"GUI_GRID"],0,0,0],
	[-2200,"bgrnd",[0,"",[0,-3.72529e-009,0.95,1],[-1,-1,-1,-1],[0.2,0.2,0.2,0.2],[-1,-1,-1,-1],"","-1"],[]],
	[-1000,"title",[0,"Code Editor",[0,0,0.95,0.04],[-1,-1,-1,-1],[1,0.5,0,1],[-1,-1,-1,-1],"","-1"],[]],
	[1400,"",[0,"",[0.025,0.12,0.9025,0.8],[-1,-1,-1,-1],[0.5,0.5,0.5,1],[-1,-1,-1,-1],"","-1"],[]],
	[1600,"tab1",[0,"Tab1",[0.025,0.08,0.0975,0.04],[1,0.5,0,1],[-1,-1,-1,-1],[-1,-1,-1,-1],"","-1"],[]],
	[1601,"tab2",[0,"Tab2",[0.125,0.08,0.0975,0.04],[1,0.5,0,1],[-1,-1,-1,-1],[-1,-1,-1,-1],"","-1"],[]],
	[1602,"tab3",[0,"Tab3",[0.225,0.08,0.0975,0.04],[1,0.5,0,1],[-1,-1,-1,-1],[-1,-1,-1,-1],"","-1"],[]],
	[1603,"",[0,"Tab4",[0.325,0.08,0.0985,0.04],[1,0.5,0,1],[-1,-1,-1,-1],[-1,-1,-1,-1],"","-1"],[]],
	[1604,"",[0,"Tab5",[0.425,0.08,0.0975,0.04],[1,0.5,0,1],[-1,-1,-1,-1],[-1,-1,-1,-1],"","-1"],[]],
	[1605,"",[0,"Tab6",[0.525,0.08,0.0975,0.04],[1,0.5,0,1],[-1,-1,-1,-1],[-1,-1,-1,-1],"","-1"],[]],
	[1606,"",[0,"Tab7",[0.625,0.08,0.0975,0.04],[1,0.5,0,1],[-1,-1,-1,-1],[-1,-1,-1,-1],"","-1"],[]],
	[1607,"",[0,"Tab8",[0.725,0.08,0.0975,0.04],[1,0.5,0,1],[-1,-1,-1,-1],[-1,-1,-1,-1],"","-1"],[]],
	[1608,"",[0,"Tab9",[0.825,0.08,0.1025,0.04],[1,0.5,0,1],[-1,-1,-1,-1],[-1,-1,-1,-1],"","-1"],[]],
	[1001,"txt",[0,"Transparency",[0.005,0.94,0.14,0.036],[-1,-1,-1,-1],[-1,-1,-1,-1],[-1,-1,-1,-1],"","-1"],[]],
	[1900,"",[0,"",[0.155,0.928,0.39,0.068],[-1,-1,-1,-1],[-1,-1,-1,-1],[-1,-1,-1,-1],"","-1"],[]],
	[1609,"hide",[0,"_",[0.875,0,0.075,0.04],[1,0.5,0,1],[-1,-1,-1,-1],[-1,-1,-1,-1],"","-1"],[]],
	[1610,"Execute",[0,"Execute",[0.825,0.92,0.1025,0.08],[1,0.5,0,1],[-1,-1,-1,-1],[-1,-1,-1,-1],"","-1"],[]],
	[1611,"save",[0,"Save Tabs",[0.7,0.92,0.1025,0.08],[1,0.5,0,1],[-1,-1,-1,-1],[-1,-1,-1,-1],"","-1"],[]],
	[1612,"clear",[0,"Clear Tab",[0.575,0.92,0.1025,0.08],[1,0.5,0,1],[-1,-1,-1,-1],[-1,-1,-1,-1],"","-1"],[]]
]
*/

class dUI_editor {
	idd = 7100;
	enableSimulation = 1;
	movingEnable = 1;
	onLoad = "'load' call rmx_fnc_codeEditorActions";
	onUnload = "'unload' call rmx_fnc_codeEditorActions";
	class controls {
		class ce_bgrnd: IGUIBack
		{
			idc = 7200;
			x = 0;
			y = -3.72529e-009;
			w = 0.95;
			h = 1;
			colorBackground[] = {0.2,0.2,0.2,1};
			moving = 1;
		};
		class ce_title: RscText
		{
			idc = 7300;
			text = "Code Editor"; //--- ToDo: Localize;
			x = 0;
			y = 0;
			w = 0.95;
			h = 0.04;
			colorBackground[] = {1,0.5,0,1};
			moving = 1;
		};
		class ce_editBox: RscEdit
		{
			idc = 7201;
			x = 0.025;
			y = 0.125;
			w = 0.9025;
			h = 0.7925;
			colorBackground[] = {0.3,0.3,0.3,0.1};
			style = 16;
            lineSpacing = 1;
            colorText[] = {1,1,1,1};
            sizeEx = 0.05;
		};
		class ce_tab0: RscButton
		{
			idc = 7202;
			text = "Alfa"; //--- ToDo: Localize;
			x = 0.025;
			y = 0.08;
			w = 0.0975;
			h = 0.04;
			colorText[] = {0.2,0.2,0.2,0.4};
			action = "['tabs', 0] call rmx_fnc_codeEditorActions";
		};
		class ce_tab1: RscButton
		{
			idc = 7203;
			text = "Bravo"; //--- ToDo: Localize;
			x = 0.125;
			y = 0.08;
			w = 0.0975;
			h = 0.04;
			colorText[] = {0.2,0.2,0.2,0.4};
			action = "['tabs', 1] call rmx_fnc_codeEditorActions";
		};
		class ce_tab2: RscButton
		{
			idc = 7204;
			text = "Charlie"; //--- ToDo: Localize;
			x = 0.225;
			y = 0.08;
			w = 0.0975;
			h = 0.04;
			colorText[] = {0.2,0.2,0.2,0.4};
			action = "['tabs', 2] call rmx_fnc_codeEditorActions";
		};
		class ce_tab3: RscButton
		{
			idc = 7205;
			text = "Delta"; //--- ToDo: Localize;
			x = 0.325;
			y = 0.08;
			w = 0.0985;
			h = 0.04;
			colorText[] = {0.2,0.2,0.2,0.4};
			action = "['tabs', 3] call rmx_fnc_codeEditorActions";
		};
		class ce_tab4: RscButton
		{
			idc = 7206;
			text = "Echo"; //--- ToDo: Localize;
			x = 0.425;
			y = 0.08;
			w = 0.0975;
			h = 0.04;
			colorText[] = {0.2,0.2,0.2,0.4};
			action = "['tabs', 4] call rmx_fnc_codeEditorActions";
		};
		class ce_tab5: RscButton
		{
			idc = 7207;
			text = "Foxtrot"; //--- ToDo: Localize;
			x = 0.525;
			y = 0.08;
			w = 0.0975;
			h = 0.04;
			colorText[] = {0.2,0.2,0.2,0.4};
			action = "['tabs', 5] call rmx_fnc_codeEditorActions";
		};
		class ce_tab6: RscButton
		{
			idc = 7208;
			text = "Golf"; //--- ToDo: Localize;
			x = 0.625;
			y = 0.08;
			w = 0.0975;
			h = 0.04;
			colorText[] = {0.2,0.2,0.2,0.4};
			action = "['tabs', 6] call rmx_fnc_codeEditorActions";
		};
		class ce_tab7: RscButton
		{
			idc = 7209;
			text = "Hotel"; //--- ToDo: Localize;
			x = 0.725;
			y = 0.08;
			w = 0.0975;
			h = 0.04;
			colorText[] = {0.2,0.2,0.2,0.4};
			action = "['tabs', 7] call rmx_fnc_codeEditorActions";
		};
		class ce_tab8: RscButton
		{
			idc = 7210;
			text = "India"; //--- ToDo: Localize;
			x = 0.825;
			y = 0.08;
			w = 0.1025;
			h = 0.04;
			colorText[] = {0.2,0.2,0.2,0.4};
			action = "['tabs', 8] call rmx_fnc_codeEditorActions";
		};
		class ce_txt: RscText
		{
			idc = 7211;
			text = "Transparency"; //--- ToDo: Localize;
			x = 0.005;
			y = 0.94;
			w = 0.14;
			h = 0.036;
		};
		class ce_slidhur: RscSlider
		{
			idc = 7212;
			x = 0.155;
			y = 0.928;
			w = 0.265;
			h = 0.068;
			onMouseButtonUp = "'slider' call rmx_fnc_codeEditorActions";
		};
		class ce_btn_Client: RscButton
		{
			idc = 7213;
			text = "Client"; //--- ToDo: Localize;
			x = 0.825;
			y = 0.92;
			w = 0.1025;
			h = 0.08;
			colorText[] = {1,0.5,0,1};
			action = "'exec_client' call rmx_fnc_codeEditorActions";
		};
		class ce_btn_save: RscButton
		{
			idc = 7214;
			text = "Save Tab"; //--- ToDo: Localize;
			x = 0.5725;
			y = 0.92;
			w = 0.1025;
			h = 0.08;
			colorText[] = {1,0.5,0,1};
			action = "'save' call rmx_fnc_codeEditorActions";
		};
		class ce_btn_clear: RscButton
		{
			idc = 7215;
			text = "Clear Tab"; //--- ToDo: Localize;
			x = 0.4475;
			y = 0.92;
			w = 0.1025;
			h = 0.08;
			colorText[] = {1,0.5,0,1};
			action = "'clear' call rmx_fnc_codeEditorActions";
		};
		class ce_btn_Server: RscButton
		{
			idc = 7216;
			text = "Server"; //--- ToDo: Localize;
			x = 0.6975;
			y = 0.92;
			w = 0.1025;
			h = 0.08;
			colorText[] = {1,0.5,0,1};
			action = "'exec_server' call rmx_fnc_codeEditorActions";
		};
	};
};