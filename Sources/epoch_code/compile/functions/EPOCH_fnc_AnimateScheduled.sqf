/*
	Author: Aaron Clark - EpochMod.com

    Contributors:

	Description:
	Run scheduled animations on objects

    Licence:
    Arma Public License Share Alike (APL-SA) - https://www.bistudio.com/community/licenses/arma-public-license-share-alike

    Github:
    https://github.com/EpochModTeam/Epoch/tree/release/Sources/epoch_code/compile/functions/EPOCH_fnc_AnimateScheduled.sqf

    Example:
		[
			_object,				// object
			[						// animationarray
				['door1',1],
				['door2',1],
				['handle1',1],
				['handle2',1]
			],
			[0,1,0]					// delays
		] remoteexec ['EPOCH_fnc_AnimateScheduled',_player];

    Parameter(s):
		_this select 0: OBJ - Object for the animations
        _this select 1: ARRAY - Array of animations and their final state
        _this select 2: ARRAY - Array of delays between each animation

	Returns:
	NOTHING
*/

private ["_ins","_target"];
params [["_object",objnull], ["_animarray",[]], ["_delays",[]]];
if (isnull _object) exitwith {};
if !(_animarray isEqualType []) exitwith {};
if !(_delays isEqualType []) exitwith {};
{
	if (_x isEqualType []) then {
		_x params [["_animation",""],["_state",0]];
		_object animate [_animation,_state];
		uisleep (_delays param [_foreachindex,0]);
	};
} foreach _animarray;
