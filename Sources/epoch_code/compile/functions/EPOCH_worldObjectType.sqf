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
    _isTree = [_object, "tree"] call EPOCH_worldObjectType;

    Parameter(s):
		_this select 0: STRING or OBJECT - string name or world object
		_this select 1: STRING or ARRAY - type names ("tree","bush")

	Returns:
	BOOL or ARRAY of BOOLs
*/
//[[[cog import generate_private_arrays ]]]
private ["_config","_end","_finalConfig","_findStart","_isTree","_modelInfo","_p3dName","_return","_selectedConfig","_start"];
//[[[end]]]
params ["_object","_checkType"];
_return = false;
_config = ('CfgEpochClient' call EPOCH_returnConfig) >> "CfgWorldInteractions";

_selectedConfig = "";
if (_object isEqualType objNull && !(isNull _object)) then {
    if !(_object isKindOf "All") then {
        (getModelInfo _object) params [["_modelName",""]];
        // replace spaces and periods with underscores
        _selectedConfig = (_modelName splitString " .") joinString "_";
    } else {
        _selectedConfig = typeOf _object;
    };
} else {
    // find start of p3d name - OLD UNUSED TBR
    if (_object isEqualType "") then {
        _findStart = _object find ": ";
        if (_findStart != -1) then{
            _start = _findStart + 2;
            // replace spaces and periods with underscores
            _selectedConfig = ((_object select [_start]) splitString " .") joinString "_";
        };
    };
};

// Do checks
_finalConfig = (_config >> _selectedConfig);
if (_checkType isEqualType []) then {
    _return = [];
    {
        _return pushBack (getNumber(_finalConfig >> _x) == 1);
    } forEach _checkType;
} else {
    _return = (getNumber(_finalConfig >> _checkType) == 1);
};

_return
