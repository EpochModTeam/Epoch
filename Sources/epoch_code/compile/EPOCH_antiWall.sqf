/*
	Author: Aaron Clark - EpochMod.com

    Contributors:

	Description:
	A3 Epoch Anti-Vehicle Wall glitch

    Licence:
    Arma Public License Share Alike (APL-SA) - https://www.bistudio.com/community/licenses/arma-public-license-share-alike

    Github:
    https://github.com/EpochModTeam/Epoch/tree/master/Sources/epoch_code/compile/EPOCH_antiWall.sqf
*/
private ["_worldPos","_front","_dirTo","_front2"];
params ["_unit","_position","_vehicle"];
if (_unit == player) then {
	_worldPos = getPosATLVisual _vehicle;
	_worldPos set[2, (_worldPos select 2) + 1];
	_front = _worldPos;
	_dirTo = _vehicle getDir player;
	_front2 = _vehicle getPos [(_vehicle distance player) + 1, _dirTo];
	{
		if (_x isKindOf "Const_All_Walls_F") exitWith{
			player moveInAny _vehicle;
			EPOCH_antiWallCount = EPOCH_antiWallCount + 1;
		};
	} forEach lineintersectsobjs[ATLToASL _front, ATLToASL _front2, player, _vehicle, true, 2];
};
