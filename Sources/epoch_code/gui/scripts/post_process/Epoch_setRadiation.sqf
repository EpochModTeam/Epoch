/*
	Author: Raimonds Virtoss - EpochMod.com

    Contributors:

	Description:
	Radiation effects [Temporary test]

    Licence:
    Arma Public License Share Alike (APL-SA) - https://www.bistudio.com/community/licenses/arma-public-license-share-alike

    Github:
    https://github.com/EpochModTeam/Epoch/blob/release/Sources/epoch_code/gui/scripts/post_process/Epoch_setRadiation.sqf

	Usage:
			0.5 call epoch_setRadiation;
			[0.2, _time] call epoch_setRadiation;
	Notes:
			Radiation levels 1-9, 0 to disable
			To reuse code in a new PP function, adjust _priority so they don't overwrite each other
*/
//[[[cog import generate_private_arrays ]]]
private ["_cc","_ci","_fg","_priority"];
//[[[end]]]
params [["_level",0,[0]],["_speed",0,[0]] ];

if (isNil "rmx_var_RadiationHandles") then {

	_priority = 16;
	_fg = ["filmGrain",_priority] call epoch_postProcessCreate;
	_cc = ["colorCorrections",_priority] call epoch_postProcessCreate;
	_ci = ["colorInversion",_priority] call epoch_postProcessCreate;

	rmx_var_RadiationHandles = [_fg,_cc,_ci];
};

switch _level do {
	case 0:
	{
		rmx_var_RadiationHandles call epoch_postprocessDestroy;
		rmx_var_RadiationHandles = nil;
	};
	case 0.1:
	{
		[(rmx_var_RadiationHandles select 0), _speed, [0.185533,1,1,1,0,true]] call epoch_postprocessAdjust;
		[(rmx_var_RadiationHandles select 1), _speed, [1,1,0,0,0,0,0,0,0,0,1,0,0,0,0]] call epoch_postprocessAdjust;
		[(rmx_var_RadiationHandles select 2), _speed, [0,0,0]] call epoch_postprocessAdjust;
	};
	case 0.2:
	{
		[(rmx_var_RadiationHandles select 0), _speed, [0.185533,1,1,1,1,true]] call epoch_postprocessAdjust;
		[(rmx_var_RadiationHandles select 1), _speed, [1,1,0,0,0,0,0,0,0,0,1,0,0,0,0]] call epoch_postprocessAdjust;
		[(rmx_var_RadiationHandles select 2), _speed, [0,0,0]] call epoch_postprocessAdjust;
	};
	case 0.3:
	{
		[(rmx_var_RadiationHandles select 0), _speed, [0.330168,1,1,1,1,true]] call epoch_postprocessAdjust;
		[(rmx_var_RadiationHandles select 1), _speed, [1,1,0,0,0,0,0,0,0,0,1,0,0,0,0]] call epoch_postprocessAdjust;
		[(rmx_var_RadiationHandles select 2), _speed, [0,0,0]] call epoch_postprocessAdjust;
	};
	case 0.4:
	{
		[(rmx_var_RadiationHandles select 0), _speed, [0.330168,1,1,1,1,true]] call epoch_postprocessAdjust;
		[(rmx_var_RadiationHandles select 1), _speed, [1,1,0,1,0,0,0.32542,1,0,0,1,0,0,0,0.486561,0.710738,0.848138,0,0,0,0.231408,1]] call epoch_postprocessAdjust;
		[(rmx_var_RadiationHandles select 2), _speed, [0,0,0]] call epoch_postprocessAdjust;
	};
	case 0.5:
	{
		[(rmx_var_RadiationHandles select 0), _speed, [0.330168,1,1,1,1,true]] call epoch_postprocessAdjust;
		[(rmx_var_RadiationHandles select 1), _speed, [1,1,0,1,0,0,0.32542,1,0,0,1,0,0,0,0.486561,0.710738,0.848138,0,0,0,0.231408,1]] call epoch_postprocessAdjust;
		[(rmx_var_RadiationHandles select 2), _speed, [0,0,0.130168]] call epoch_postprocessAdjust;
	};
	case 0.6:
	{
		[(rmx_var_RadiationHandles select 0), _speed, [0.330168,1,1,1,1,true]] call epoch_postprocessAdjust;
		[(rmx_var_RadiationHandles select 1), _speed, [1,1,0,1,0,0,0.32542,1,0,0,1,0,0,0,0.486561,0.710738,0.848138,0,0,0,0,1]] call epoch_postprocessAdjust;
		[(rmx_var_RadiationHandles select 2), _speed, [0,0,0.216946]] call epoch_postprocessAdjust;
	};
	case 0.7:
	{
		[(rmx_var_RadiationHandles select 0), _speed, [0.330168,1,1,1,1,true]] call epoch_postprocessAdjust;
		[(rmx_var_RadiationHandles select 1), _speed, [1,0.493791,0,1,0,0,0.32542,1,0,0,1,0,0,0,0.486561,0.710738,0.848138,0,0,0,0,1]] call epoch_postprocessAdjust;
		[(rmx_var_RadiationHandles select 2), _speed, [0,0,0.368809]] call epoch_postprocessAdjust;
	};
	case 0.8:
	{
		[(rmx_var_RadiationHandles select 0), _speed, [0.330168,1,1,1,1,true]] call epoch_postprocessAdjust;
		[(rmx_var_RadiationHandles select 1), _speed, [1,0.247919,0,1,0,0,0.32542,1,0,0,1,0,0,0,0.486561,0.710738,0.848138,0,0,0,0,1]] call epoch_postprocessAdjust;
		[(rmx_var_RadiationHandles select 2), _speed, [0,0.108473,0.46282]] call epoch_postprocessAdjust;
	};
	case 0.9:
	{
		[(rmx_var_RadiationHandles select 0), _speed, [0.330168,1,1,1,1,true]] call epoch_postprocessAdjust;
		[(rmx_var_RadiationHandles select 1), _speed, [1,0,0,1,0,0,0.32542,1,0,0,1,0,0,0,0.486561,0.710738,0.848138,0,0,0,0,1]] call epoch_postprocessAdjust;
		[(rmx_var_RadiationHandles select 2), _speed, [0,0.245873,0.368809]] call epoch_postprocessAdjust;
	};
	case 1:
	{
		[(rmx_var_RadiationHandles select 0), _speed, [0.330168,1,1,1,1,true]] call epoch_postprocessAdjust;
		[(rmx_var_RadiationHandles select 1), _speed, [1,0,0,1,0,0,0.32542,1,0,0,1,0,0,0,0.486561,0.710738,0.848138,0,0,0,0,0.41943]] call epoch_postprocessAdjust;
		[(rmx_var_RadiationHandles select 2), _speed, [0,0.361578,0.368809]] call epoch_postprocessAdjust;
	};
};
