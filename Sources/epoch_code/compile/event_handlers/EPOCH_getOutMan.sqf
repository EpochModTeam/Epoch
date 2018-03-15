/*
	Author: Aaron Clark - EpochMod.com

    Contributors:

	Description:
	Get out handler for A3 Epoch
	Includes Anti-Vehicle Wall glitch checks

    Licence:
    Arma Public License Share Alike (APL-SA) - https://www.bistudio.com/community/licenses/arma-public-license-share-alike

    Github:
    https://github.com/EpochModTeam/Epoch/tree/release/Sources/epoch_code/compile/EPOCH_getOutMan_EH.sqf
*/

params ["_unit","_position","_vehicle"];
call EPOCH_niteLight;
if (_unit == player) then {
	_this spawn {
		private ["_animationstate","_StartTime","_eyepos","_dirTo","_end","_start"];
		params ["_unit","_position","_vehicle"];
		_animationstate = animationstate player;
		_StartTime = diag_ticktime;
		waituntil {diag_ticktime - _StartTime > 5 || _animationstate != (animationstate player)};
		if (diag_ticktime - _StartTime > 5) exitwith {};
		_start = getPosWorld _vehicle;
		_eyepos = eyepos player;
		_dirTo = _start getDir _eyepos;
		_end = _start getPos [(_start distance _eyepos) + 0.5, _dirTo];
		_end set [2,_eyepos select 2];
		{
			if (_x isKindOf "Building") exitWith{
				player moveInAny _vehicle;
				EPOCH_antiWallCount = EPOCH_antiWallCount + 1;
			};
		} forEach lineintersectsobjs [_start, _end, player, _vehicle, true, 2];
	};
};
