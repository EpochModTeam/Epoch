/*
	Author: Aaron Clark - EpochMod.com

    Contributors:

	Description:
	Epoch Chopwood function

    Licence:
    Arma Public License Share Alike (APL-SA) - https://www.bistudio.com/community/licenses/arma-public-license-share-alike

    Github:
    https://github.com/EpochModTeam/Epoch/tree/release/Sources/epoch_code/compile/EPOCH_chopWood.sqf
*/
//[[[cog import generate_private_arrays ]]]
private ["_currentPos","_getWorldTypes","_object","_objects","_sel_object","_type","_worldTypes"];
//[[[end]]]

_currentPos = player modelToWorld[0, 5, 0];
if !(surfaceIsWater _currentPos) then {
    _currentPos = ATLtoASL _currentPos;
};

_objects = lineIntersectsObjs[eyePos player, _currentPos, player, objNull, true, 2];
_object  = objNull;
_type    = 0;

{
    _sel_object = _x;
    _worldTypes = ["tree","bush"];
    _getWorldTypes = [_x, _worldTypes] call EPOCH_worldObjectType;
    {
        if (_getWorldTypes param [_worldTypes find _x, false]) exitWith {
            _type = _forEachIndex;
            _object = _sel_object;
        };
    } forEach _worldTypes;

    if !(isNull _object) exitWith {};
}foreach _objects;

if (!isNull _object) then {
    if (alive _object) then {
        [_object,_type,player,EPOCH_personalToken] remoteExec ["EPOCH_server_knockDownTree",2];
    };
};
