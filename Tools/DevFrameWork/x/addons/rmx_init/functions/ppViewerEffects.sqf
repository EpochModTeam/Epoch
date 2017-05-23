/*
	Function Name:			rmx_fnc_ppViewerEffects
	Author:					Raimonds Virtoss | Raymix
	Description:			PPV Effects, responsible for all the math and applying effects
	
	License:				---
*/
#include <\x\Addons\rmx_init\defines.inc>
private ["_currEffect","_handle","_adjust"];
disableSerialization;

_currEffect = rmx_var_ppTemplate select rmx_var_ppSelected select 0;
_handle = rmx_var_ppHandles select rmx_var_ppSelected;

//hintSilent format ["E: %1",_this];

switch (_currEffect) do {
	case "colorCorrections":
	{
		rmx_var_ppCcPos = [];
		for "_i" from 8 to 22 do {
			rmx_var_ppCcPos pushBack (sliderPosition (rmx_var_ppCatCC select _i));
		};
		if (cbChecked (rmx_var_ppCatCC select 23)) then {
			rmx_var_ppCcvPos = [];
			for "_i" from 8 to 14 do {
				rmx_var_ppCcvPos pushBack (sliderPosition (rmx_var_ppCatCCV select _i));
			};
			rmx_var_ppCcPos append rmx_var_ppCcvPos;
		};
		_adjust = rmx_var_ppCcPos;
	};
	case "chromAberration":
	{
		rmx_var_ppCaPos = [
			sliderPosition (rmx_var_ppCatCA select 4),
			sliderPosition (rmx_var_ppCatCA select 5),
			cbChecked (rmx_var_ppCatCA select 6)
		];
		_adjust = rmx_var_ppCaPos;
	};
	case "filmGrain":
	{
		rmx_var_ppFgPos = [];
		for "_i" from 7 to 11 do {
			rmx_var_ppFgPos pushBack (sliderPosition (rmx_var_ppCatFG select _i));
		};
		rmx_var_ppFgPos pushBack (cbChecked (rmx_var_ppCatFG select 12));
		_adjust = rmx_var_ppFgPos;
	};
	case "radialBlur":
	{
		rmx_var_ppRbPos = [];
		for "_i" from 5 to 8 do {
			rmx_var_ppRbPos pushBack (sliderPosition (rmx_var_ppCatRB select _i));
		};
		_adjust = rmx_var_ppRbPos;
	};
	case "wetdistortion":
	{
		rmx_var_ppWdPos = [];
		for "_i" from 7 to 21 do {
			rmx_var_ppWdPos pushBack (sliderPosition (rmx_var_ppCatWD select _i));
		};
		_adjust = rmx_var_ppWdPos;
	}; 
	case "dynamicBlur":
	{
		rmx_var_ppDbPos = [sliderPosition (rmx_var_ppCatDB select 2)];
		_adjust = rmx_var_ppDbPos;
	};
	case "colorInversion":
	{
		rmx_var_ppCiPos = [];
		for "_i" from 4 to 6 do {
			rmx_var_ppCiPos pushBack (sliderPosition (rmx_var_ppCatCI select _i));
		};
		_adjust = rmx_var_ppCiPos;
	};
};
//(format ["%1 >> %2",_currEffect,_adjust]) info;
_handle ppEffectEnable true;
_handle ppEffectAdjust _adjust;
_handle ppEffectCommit 0;

true
