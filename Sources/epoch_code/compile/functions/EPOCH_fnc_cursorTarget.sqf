/*
	Author: Aaron Clark - EpochMod.com

    Contributors:

	Description:
	Epoch cursorTarget anywhere

    Licence:
    Arma Public License Share Alike (APL-SA) - https://www.bistudio.com/community/licenses/arma-public-license-share-alike

    Github:
    https://github.com/EpochModTeam/Epoch/tree/release/Sources/epoch_code/compile/functions/EPOCH_fnc_addItemOverflow.sqf

    Example:
    _target = [10] call EPOCH_fnc_cursorTarget;

    Parameter(s):
		_this select 0: SCALAR - Distance in meters
        _this select 1: STRING - lod1
        _this select 3: STRING - lod2
        _this select 4: BOOL - sort

	Returns:
	(OBJECT or objNull)
*/
//[[[cog import generate_private_arrays ]]]
private ["_ins","_target"];
//[[[end]]]
params [["_distance",10], ["_lod1", "VIEW"], ["_lod2","FIRE"], ["_sort",true]];
if (underwater player) then {
	_ins = lineIntersectsSurfaces [AGLToASL positionCameraToWorld [0,0,0],AGLToASL positionCameraToWorld [0,0,_distance],player,objNull,_sort,1,_lod1,_lod2];
	if (_ins isEqualTo []) exitWith { objNull };
	(_ins select 0 param [3,objNull])
} else {
	cursorTarget
}
