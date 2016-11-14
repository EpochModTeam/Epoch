/*
	Author: Raimonds Virtoss - EpochMod.com

    Contributors:

	Description:
	Drunk effects

    Licence:
    Arma Public License Share Alike (APL-SA) - https://www.bistudio.com/community/licenses/arma-public-license-share-alike

    Github:
    https://github.com/EpochModTeam/Epoch/blob/release/Sources/epoch_code/gui/scripts/post_process/Epoch_setDrunk.sqf

	Usage:
			0.5 call epoch_setDrunk;
			[0.2, _time] call epoch_setDrunk;
	Notes:
			Drunk levels 1-9, 0 to disable
			Use low times, wet distortion does not work well when animated over time
			To reuse code in a new PP function, adjust _priority so they don't overwrite each other
*/
private ["_priority","_wd","_db"];
params [["_level",0,[0]],["_speed",0,[0]]];

if (isNil "rmx_var_drunkHandles") then {

	_priority = 15;
	_wd = ["wetdistortion",_priority] call epoch_postProcessCreate;
	_db = ["dynamicBlur",_priority] call epoch_postProcessCreate;

	rmx_var_drunkHandles = [_wd,_db];
};

switch _level do {
	case 0:
	{
		rmx_var_drunkHandles call epoch_postprocessDestroy;
		rmx_var_drunkHandles = nil;
	};
	case 0.1:
	{
		[(rmx_var_drunkHandles select 0), _speed, [-1,0.0144629,0,1,0,-0.551644,0.0309715,0.202484,0,0,-0.161139,0,0,1,1]] call epoch_postprocessAdjust;
		[(rmx_var_drunkHandles select 1), _speed, [0]] call epoch_postprocessAdjust;
	};
	case 0.2:
	{
		[(rmx_var_drunkHandles select 0), _speed, [-1,0.0144629,0,1,0,-0.551644,0.0309715,0.390503,0,0,-0.161139,0,0,1,1]] call epoch_postprocessAdjust;
		[(rmx_var_drunkHandles select 1), _speed, [0]] call epoch_postprocessAdjust;
	};
	case 0.3:
	{
		[(rmx_var_drunkHandles select 0), _speed, [-1,0.0144629,0,1,0,-0.53718,-0.157049,0.390503,-1,0,-0.161139,0,0,1,1]] call epoch_postprocessAdjust;
		[(rmx_var_drunkHandles select 1), _speed, [0]] call epoch_postprocessAdjust;
	};
	case 0.4:
	{
		[(rmx_var_drunkHandles select 0), _speed, [-1,0.0144629,0,1,0,-0.53718,-0.157049,0.390503,-1,1,-0.161139,0,0,1,1]] call epoch_postprocessAdjust;
		[(rmx_var_drunkHandles select 1), _speed, [0]] call epoch_postprocessAdjust;
	};
	case 0.5:
	{
		[(rmx_var_drunkHandles select 0), _speed, [1,0.0144616,0.0144629,1,0,-0.53718,-0.157049,0.390503,-1,1,-0.161139,0,0,1,1]] call epoch_postprocessAdjust;
		[(rmx_var_drunkHandles select 1), _speed, [0.146676]] call epoch_postprocessAdjust;
	};
	case 0.6:
	{
		[(rmx_var_drunkHandles select 0), _speed, [1,0.0144616,0.0144629,1,0,-0.53718,-0.157049,0.390503,-1,1,-0.161139,0,0,1,1]] call epoch_postprocessAdjust;
		[(rmx_var_drunkHandles select 1), _speed, [0.334697]] call epoch_postprocessAdjust;
	};
	case 0.7:
	{
		[(rmx_var_drunkHandles select 0), _speed, [1,0.0144616,0.0289258,1,0,-0.53718,-0.157049,0.390503,-1,1,-0.161139,0,0,1,1]] call epoch_postprocessAdjust;
		[(rmx_var_drunkHandles select 1), _speed, [0.334697]] call epoch_postprocessAdjust;
	};
	case 0.8:
	{
		[(rmx_var_drunkHandles select 0), _speed, [1,0.0289245,0.0289258,1,0,-0.53718,-0.157049,0.390503,-1,1,-0.161139,0,0,1,1]] call epoch_postprocessAdjust;
		[(rmx_var_drunkHandles select 1), _speed, [0.334697]] call epoch_postprocessAdjust;
	};
	case 0.9:
	{
		[(rmx_var_drunkHandles select 0), _speed, [1,0,-0.0867792,0.435939,-0.592987,-0.739664,-1,0.144629,-1,0.103286,0.247918,0,0,1,-0.378086]] call epoch_postprocessAdjust;
		[(rmx_var_drunkHandles select 1), _speed, [0.0940112]] call epoch_postprocessAdjust;
	};
	case 1:
	{
		[(rmx_var_drunkHandles select 0), _speed, [1,0.0723131,-0.0433885,1,-0.592987,-0.811979,-1,0.882248,-1,1,1,0,0,0.373996,-1]] call epoch_postprocessAdjust;
		[(rmx_var_drunkHandles select 1), _speed, [0.151864]] call epoch_postprocessAdjust;
	};
};
