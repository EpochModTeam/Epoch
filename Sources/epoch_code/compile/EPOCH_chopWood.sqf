private["_currentPos", "_object", "_type", "_objects", "_sel_object"]; 

_currentPos = player modelToWorld[0, 5, 0];
if !(surfaceIsWater _currentPos) then {
    _currentPos = ATLtoASL _currentPos;
};

_objects = lineIntersectsObjs[eyePos player, _currentPos, player, objNull, true, 2];
_object  = objNull;
_type    = 0;

_config = 'CfgEpochClient' call EPOCH_returnConfig;
_treesLootList = getArray(_config >> worldname >> "Trees");
_bushesLootList = getArray(_config >> worldname >> "Bushes");

{
    _strObj = str _x;
	_sel_object = _x;	
	_findStart = _strObj find ": ";
	if (_findStart != -1) then{
		_p3dName = _strObj select[_findStart + 2, 999];
		if (_p3dName in _treesLootList) then{
			_object = _sel_object;
		};
		if (_p3dName in _bushesLootList) then{
			_type = 1;
			_object = _sel_object;
		};
	};
    if !(isNull _object) exitWith {};
}foreach _objects;

if (!isNull _object) then {
    if (alive _object) then {
        EPOCH_knockDownTree = [_object,_type,player,EPOCH_personalToken];
        publicVariableServer "EPOCH_knockDownTree";
    };
};