/*
	Author: He-Man

    Contributors:

	Description: Check, if Player can Autorun

    Licence:
    Arma Public License Share Alike (APL-SA) - https://www.bistudio.com/community/licenses/arma-public-license-share-alike

    Github:
    https://github.com/EpochModTeam/Epoch/tree/release/Sources/epoch_code/compile/EPOCH_AutoRun_Check.sqf

	Usage: call EPOCH_AutoRun_Check;
	
	Returns:
	BOOL
*/

private["_canAutoRun","_currentPos"];
_canAutoRun = true;
if !(alive player) exitwith {
	false
};
if !(istouchingground player) exitwith {
	false
};
if !((vehicle player) == player) exitwith {
	false
};
if ((getPosasl player) select 2 < -0.5) exitwith {
	false
};
if ((player getHitPointDamage "HitLegs") >= 0.5) exitwith {
	["Can not AutoRun - Your legs are Broken!",5] call Epoch_Message;
	false
};
if !(player nearObjects["Const_All_Walls_F", 6] isEqualTo[]) then {
	_currentPos = player modelToWorld [0, 1, 1];
	if !(surfaceIsWater _currentPos) then {
		_currentPos = ATLtoASL _currentPos;
	};
	if (lineIntersects[eyePos player, _currentPos, player, objNull]) then {
		_canAutoRun = false;
	};
};
_canAutoRun
