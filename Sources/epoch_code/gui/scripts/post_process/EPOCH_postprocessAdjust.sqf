/*
	Author: Raimonds Virtoss - EpochMod.com

    Contributors: Aaron Clark

	Description:
	Adjusts PP created elsewhere (or by epoch_postprocessCreate)

    Licence:
    Arma Public License Share Alike (APL-SA) - https://www.bistudio.com/community/licenses/arma-public-license-share-alike

    Github:
    https://github.com/EpochModTeam/Epoch/blob/release/Sources/epoch_code/gui/scripts/post_process/EPOCH_postprocessAdjust.sqf

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
params [["_handle",666],["_animSpeed",666],["_effect",[]],["_fixBool",false]];
//needed because PPs have variable array sizes
if ((_handle isEqualTo 666) || (_animSpeed isEqualTo 666) || (_effect isEqualTo [])) exitWith {hint "Wrong PPAdjust input"; false};

// fix any strings to bool
if (_fixBool) then {
	_effect = _effect call EPOCH_fnc_arrayStringToBool;
};

_handle ppEffectEnable true;
_handle ppEffectAdjust _effect;
_handle ppEffectCommit _animSpeed;
