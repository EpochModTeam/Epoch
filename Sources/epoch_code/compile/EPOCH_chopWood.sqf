/*
	Author: Aaron Clark - EpochMod.com

    Contributors:

	Description:
	Epoch Chopwood function

    Licence:
    Arma Public License Share Alike (APL-SA) - https://www.bistudio.com/community/licenses/arma-public-license-share-alike

    Github:
    https://github.com/EpochModTeam/Epoch/tree/master/Sources/epoch_code/compile/EPOCH_chopWood.sqf
*/
private ["_currentPos","_object","_type","_start","_end","_p3dName","_finalConfig","_str","_sel_object","_findStart","_objects","_config"];

_currentPos = player modelToWorld[0, 5, 0];
if !(surfaceIsWater _currentPos) then {
    _currentPos = ATLtoASL _currentPos;
};

_objects = lineIntersectsObjs[eyePos player, _currentPos, player, objNull, true, 2];
_object  = objNull;
_type    = 0;

_config = 'CfgEpochClient' call EPOCH_returnConfig;

{
    _str = str _x;
	_sel_object = _x;
	_findStart = _str find ": ";
	if (_findStart != -1) then{
        _start = _findStart + 2;
        _end = (_str find ".") - _start;
        _p3dName = _str select[_start, _end];
        if (_p3dName find " " != -1) then {
            (_p3dName splitString " ") joinString "_"; // replace spaces with underscores
        };
        _finalConfig = (_config >> "WorldInteractions" >> (_p3dName + "_p3d"));
		if (getNumber(_finalConfig >> "tree") == 1) then{
			_object = _sel_object;
		};
		if (getNumber(_finalConfig >> "bush") == 1) then{
			_type = 1;
			_object = _sel_object;
		};
	};
    if !(isNull _object) exitWith {};
}foreach _objects;

if (!isNull _object) then {
    if (alive _object) then {
        [_object,_type,player,EPOCH_personalToken] remoteExec ["EPOCH_server_knockDownTree",2];
    };
};
