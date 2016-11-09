/*
	Author: Raimonds Virtoss - EpochMod.com

    Contributors:

	Description:
	Gives shake animation to your 2D GUI element along it's center.
	
	_control (mandatory):  control to animate;
	_speed (optional): speed of animation, higher values equals to faster animation. Should be less than degrees to avoid glitches!
	_shakes (optional): amount of shakes, more shakes = longer animation.
	_degrees (optional): rotation degrees 0 to 360.
	
	Shake animation sequence:
		0 > -degrees
		-degrees > +degrees
		+degrees > 0
	
    Licence:
    Arma Public License Share Alike (APL-SA) - https://www.bistudio.com/community/licenses/arma-public-license-share-alike

    Github:
    https://github.com/EpochModTeam/Epoch/tree/release/Sources/epoch_code/gui/scripts/animations/Epoch_2DCtrlShake.sqf

	Usage:
	[_control] call epoch_2DCtrlShake; //default 3 fast shakes
	[_control, 10, 12] call epoch_2DCtrlShake; //12 very fast shakes
	[_control, 2, 5, 90] call epoch_2DCtrlShake; // 5 very slow 90 degree shakes

*/
_this spawn {
	disableSerialization;
	private ["_ctrl","_speed","_shakes","_degrees","_s","_d"];
	_ctrl = 	param [0, controlNull,[controlNull]];
	_speed = 	param [1,5,[0]];
	_shakes = 	param [2,3,[0]];
	_degrees = 	param [3,10,[0]];

	if (_ctrl isEqualTo controlNull) exitWith {false};

	for "_s" from 0 to (_shakes - 1) do {

		for "_d" from 0 to _degrees step _speed do {
			_ctrl ctrlSetAngle [_d * -1,0.5,0.5];
			uiSleep 0.01;
		};
		for "_d" from (_degrees * -1) to _degrees step _speed do {
			_ctrl ctrlSetAngle [_d,0.5,0.5];
			uiSleep 0.01;
		};
		for "_d" from 0 to _degrees step _speed do {
			_ctrl ctrlSetAngle [_degrees - _d,0.5,0.5];
			uiSleep 0.01;
		};
		_ctrl ctrlSetAngle [0,0.5,0.5]; // just in case given params are not balanced
	};
	
	true
};

true
