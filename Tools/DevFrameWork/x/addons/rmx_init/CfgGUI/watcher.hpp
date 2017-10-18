/* #Rubowe
$[
	1.063,
	["dsa",[[0,0,1,1],0.025,0.04,"GUI_GRID"],0,0,0],
	[2200,"vw_bckgrnd",[0,"",[0,0.04,0.465,0.08],[-1,-1,-1,-1],[0.2,0.2,0.2,0.4],[-1,-1,-1,-1],"","-1"],["idc = 7501;"]],
	[1000,"vw_title",[0,"Drag to move",[0,0,0.465,0.04],[-1,-1,-1,-1],[0.2,0.2,0.2,1],[-1,-1,-1,-1],"","-1"],["idc = 7502;","style = 2;","moving = 1;","onMouseButtonUp = |^savePos^ call rmx_fnc_watcherActions;|;"]],
	[1001,"vw_pin: RscActivePictureKeepAspect",[0,"x\addons\rmx_init\data\retardedPinUp.paa",[0.429999,0,0.03,0.04],[-1,-1,-1,-1],[-1,-1,-1,-1],[1,1,1,1],"","-1"],["idc = 7503;","onMouseButtonUp = |^pin^ call rmx_fnc_watcherActions;|;"]],
	[1400,"vw_code",[0,"",[0,0.04,0.465,0.04],[-1,-1,-1,-1],[-1,-1,-1,-1],[-1,-1,-1,-1],"","-1"],["idc = 7504;"]],
	[2100,"vw_combo",[0,"",[0.115,0.08,0.275,0.04],[-1,-1,-1,-1],[-1,-1,-1,-1],[-1,-1,-1,-1],"","-1"],["idc = 7505;"]],
	[1600,"vw_btnAdd",[0,"Add",[0.390001,0.08,0.075,0.04],[-1,-1,-1,-1],[-1,-1,-1,-1],[-1,-1,-1,-1],"","-1"],["idc = 7506;","action = |^execute^ call rmx_fnc_watcherActions;|;"]],
	[2300,"vw_grp",[0,"",[0,0.12,0.465,0.044],[-1,-1,-1,-1],[-1,-1,-1,-1],[-1,-1,-1,-1],"","-1"],["idc = 7507;"]],
	[2101,"vw_combo_transparency",[0,"",[0,0.08,0.115,0.04],[-1,-1,-1,-1],[-1,-1,-1,-1],[-1,-1,-1,-1],"","-1"],["idc = 7505;"]]
]
*/



class dUI_watcher {
	idd = 7500;
	enableSimulation = 1;
	movingEnable = 1;
	onUnload = "'unload' call rmx_fnc_watcherActions;";
	onLoad = "'load' call rmx_fnc_watcherActions;";
	class controls {
		class vw_bckgrnd: IGUIBack
		{
			idc = 7501;
			x = 0;
			y = 0.04;
			w = 0.465;
			h = 0.08;
			colorBackground[] = {0.2,0.2,0.2,0.4};
		};
		class vw_title: RscText
		{
			idc = 7502;
			text = "Drag to move"; //--- ToDo: Localize;
			x = 0;
			y = 0;
			w = 0.465;
			h = 0.04;
			colorBackground[] = {0.2,0.2,0.2,1};
			style = 0x02; //center
			moving = 1;
		};
		class vw_pin: RscActivePictureKeepAspect
		{
			idc = 7503;
			text = "x\addons\rmx_init\data\retardedPinUp.paa";
			x = 0.43;
			y = 0;
			w = 0.03;
			h = 0.04;
			onMouseButtonUp = "'pin' call rmx_fnc_watcherActions;";
		};
		class vw_code: RscEdit
		{
			idc = 7504;
			text = "";
			x = 0;
			y = 0.04;
			w = 0.465;
			h = 0.04;
		};
		class vw_combo: RscCombo
		{
			idc = 7505;
			x = 0.115;
			y = 0.08;
			w = 0.275;
			h = 0.04;
		};
		class vw_btnAdd: RscButton
		{
			idc = 7506;
			text = "Add"; //--- ToDo: Localize;
			x = 0.390001;
			y = 0.08;
			w = 0.075;
			h = 0.04;
			colorText[] = {1,1,1,1};
			action = "'execute' call rmx_fnc_watcherActions;";
		};
		class vw_grp: RscControlsGroup
		{
			idc = 7507;
			x = 0;
			y = 0.12;
			w = 0.465;
			h = 0;
			class VScrollbar: VScrollbar
			{
				width = 0;
			};
			class HScrollbar: VScrollbar
			{
				height = 0;
			};
			class controls{};
		};
		class vw_comboTransparency: RscCombo
		{
			idc = 7508;
			x = 0;
			y = 0.08;
			w = 0.115;
			h = 0.04;
		};
		onLBSelChanged = "'fade' call rmx_fnc_watcherActions;";
	};
};
