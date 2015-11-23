params [["_distance",10], ["_lod1", "VIEW"], ["_lod2","FIRE"], ["_sort",true]];
_ins = lineIntersectsSurfaces [AGLToASL positionCameraToWorld [0,0,0],AGLToASL positionCameraToWorld [0,0,_distance],player,objNull,_sort,1,_lod1,_lod2];
if (_ins isEqualTo []) exitWith { objNull };
(_ins select 0 param [3,objNull])
