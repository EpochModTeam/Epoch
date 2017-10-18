/*
	Function Name:			rmx_fnc_atmosFear
	Author:					Raimonds Virtoss | Raymix
	Description:			Atmosphere control dialog
	
	License:				---
*/
#include <\x\Addons\rmx_init\defines.inc>
private ["_display","_diag","_listBox"];
disableSerialization;

switch (rmx_var_atmosFearEnabled) do {
	case false: 
	{
		_diag = createDialog "dUI_atmosFear";
		_display = findDisplay 8100;
		
		for "_i" from 8110 to 8119 do {
			rmx_var_afProgress set [count rmx_var_afProgress,_display displayCtrl _i];
		};
		
		for "_i" from 8130 to 8144 do {
			rmx_var_afInput set [count rmx_var_afInput,_display displayCtrl _i];
		};
		
		for "_i" from 8150 to 8161 do {
			rmx_var_afSliders set [count rmx_var_afSliders,_display displayCtrl _i];
		};
		rmx_var_afMisc = [_display displayCtrl 8170, _display displayCtrl 8180]; //cb, combo
		rmx_var_afText = [_display displayCtrl 8101, _display displayCtrl 8102];
		
		["load"] call rmx_fnc_atmosFearActions;
		[] spawn rmx_fnc_atmosFearUpdate;
		rmx_var_atmosFearEnabled = true;
	};
	case true:
	{
		rmx_var_atmosFearEnabled = false;
		closeDialog 0;
	};
};

true

/*
main dialog - 8100

Dynamic text:
	A2 winds		8101
	wind direction	8102

progress bars:
	lightnings		8110
	overcst			8111
	rainbow			8112
	gusts			8113
	rain			8114
	fog density		8115
	fog decay		8116
	fog altitude	8117
	wind str		8118
	waves			8119
	
Input fields:
	rain			8130
	fog				8131
	wind			8132
	force			8133 //3
	waves			8134
	direction		8135 //select 5
	wind a2 x		8136
	wind a2 y		8137
	export			8138
	day				8139 //select 9
	month			8140
	year			8141
	hours			8142
	minutes			8143
	skiptime		8144
	
Sliders:
	lightnings		8150
	overcast		8151
	rainbow			8152
	gusts			8153
	rain			8154
	fog decay		8155 //5
	fog density		8156
	fog altitude	8157 //select 7
	wind str		8158
	wind frc		8159 //9
	waves			8160
	direction		8161
	
Checkboxes:
	wind a2			8170
	
combo box:
	import			8180

buttons:
	rpt				8190
	apply			8191
	load			8192
	save			8193
*/