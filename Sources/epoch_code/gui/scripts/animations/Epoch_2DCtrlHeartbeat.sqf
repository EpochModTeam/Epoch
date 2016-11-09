/*
	Author: Raimonds Virtoss - EpochMod.com

    Contributors:

	Description:
	Gives (imploding) heartbeat animation to your 2D GUI element along it's center.
	
	_control (mandatory):  control to animate;
	_scale (optional): scale of the beat 0.1 - 0.9
		Safe values: 0.1 - 0.7
		Best values: 0.55, 0.7
	_times (optional): Repeat animation N times
	_delay (optional): Delay between animation repeats
	_beats (optional): amount of heart beats per animation cycle
		Best value: 2 (default)
	_speed (optional): speed of animation, higher speed = longer animation
		Best value: 0.04 (default)
	
    Licence:
    Arma Public License Share Alike (APL-SA) - https://www.bistudio.com/community/licenses/arma-public-license-share-alike

    Github:
    https://github.com/EpochModTeam/Epoch/tree/release/Sources/epoch_code/gui/scripts/animations/Epoch_2DCtrlHeartbeat.sqf

	Usage:
	[_control] call epoch_2DCtrlHeartbeat; //default (best values) 2x fast heartbeats
	[_control, 0.55] call epoch_2DCtrlHeartbeat; // 2x deep heartbeats (also really nice, has a growing/breathing effect after 2 beats)
	[_control, 0.7, 5, 2] call epoch_2DCtrlHeartbeat; // 2x fast normal beats repeated 5 times every 2 seconds
	[_control, 0.7, 1, 1, 3, 0.01] call epoch_2DCtrlHeartbeat; // 3x super fast beats played once

*/
_this spawn {
	disableSerialization;
	private ["_ctrl","_scale","_times","_delay","_beats","_speed","_t","_b"];

	_ctrl = 	param [0, controlNull,[controlNull]];
	_scale = 	param [1,0.7,[0]];
	_times = 	param [2,1,[0]];
	_delay = 	param [3,1.2,[0]];
	_beats = 	param [4,2,[0]];
	_speed = 	param [5,0.04,[0]];
	
	if (_ctrl isEqualTo controlNull) exitWith {false};
	_speed = 0.1;
	for "_t" from 0 to (_times - 1) do {
		[_ctrl,_scale + _scale/2,_speed] call BIS_fnc_ctrlSetScale;
		uiSleep _speed;
		for "_b" from 0 to (_beats - 1) do {
			[_ctrl,_scale,_speed] call BIS_fnc_ctrlSetScale;
			uiSleep _speed;
			[_ctrl,_scale + _scale/2,_speed] call BIS_fnc_ctrlSetScale;
			uiSleep _speed;
		};
		[_ctrl,1,_delay] call BIS_fnc_ctrlSetScale;
		uiSleep _delay;
	};
	
	true
};

true
