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
//[[[cog import generate_private_arrays ]]]
private ["_dirTo","_end","_start"];
//[[[end]]]
params ["_unit","_position","_vehicle"];
if (_unit == player) then {
	_start = getPosWorld _vehicle;
	// _worldPos set[2, (_worldPos select 2) + 1];
	_dirTo = _vehicle getDir player;
	_end = _vehicle getPos [(_vehicle distance player) + 1, _dirTo];
	{
		if (_x isKindOf "Const_All_Walls_F") exitWith{
			player moveInAny _vehicle;
			EPOCH_antiWallCount = EPOCH_antiWallCount + 1;
		};
	} forEach lineintersectsobjs[_start, AGLToASL _end, player, _vehicle, true, 2];
};
