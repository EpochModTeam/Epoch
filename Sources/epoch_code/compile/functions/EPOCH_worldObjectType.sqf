/*
	Author: Aaron Clark - EpochMod.com

    Contributors:

	Description:
	Returns type of world object based on CfgWorldInteractions config

    Licence:
    Arma Public License Share Alike (APL-SA) - https://www.bistudio.com/community/licenses/arma-public-license-share-alike

    Github:
    https://github.com/EpochModTeam/Epoch/tree/release/Sources/epoch_code/compile/functions/EPOCH_worldObjectType.sqf

    Example:
    _isTree = [_objectSting, "tree"] call EPOCH_worldObjectType;

    Parameter(s):
		_this select 0: STRING - string name of world object
		_this select 1: STRING or ARRAY - type names ("tree","bush")

	Returns:
	BOOL or ARRAY of BOOLs
*/
params ["_str","_checkType"];
_return = false;
_config = 'CfgEpochClient' call EPOCH_returnConfig;
// find start of p3d name
_findStart = _str find ": ";
if (_findStart != -1) then{
    _start = _findStart + 2;
    _end = (_str find ".") - _start;
    _p3dName = _str select[_start, _end];

    // replace spaces with underscores
    if (_p3dName find " " != -1) then {
        (_p3dName splitString " ") joinString "_";
    };
    _finalConfig = (_config >> "CfgWorldInteractions" >> (_p3dName + "_p3d"));

    if (_checkType isEqualType []) then {
        _return = [];
        {
            _return pushBack (getNumber(_finalConfig >> _x) == 1);
        } forEach _checkType;
    } else {
        _return = (getNumber(_finalConfig >> _checkType) == 1);
    };
};
_return
