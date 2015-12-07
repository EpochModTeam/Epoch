/*
	Adjusts PP created elsewhere (or by epoch_postprocessCreate)

	Params:		[Handle, speed integer, Effect array]

	Usage: 		[_handle, 2, [1]] call epoch_postprocessAdjust; //apply dynamic blur with animation of 2 seconds
				[_handle, _speed, _effect] call epoch_postprocessAdjust;

	Default Engine values:
							colorCorrections >> [1,1,0,0,0,0,0,0,0,0,1,0,0,0,0]
							chromAberration >> [0,0,false]
							filmGrain >> [0,0,1,0,0,false]
							radialBlur >> [0,0,0,0]
							wetdistortion >> [0,0,0,0,0,0,0,0,0,0,0,0,0,0,0]
							dynamicBlur >> [0]
							colorInversion >> [0,0,0]
*/

_handle = param [0,666];
_animSpeed = param [1,666];
_effect = param [2,[]];

//needed because PPs have variable array sizes
if ((_handle isEqualTo 666) || (_animSpeed isEqualTo 666) || (_effect isEqualTo [])) exitWith {hint "Wrong PPAdjust input"; false};

_handle ppEffectEnable true;
_handle ppEffectAdjust _effect;
_handle ppEffectCommit _animSpeed;
