private["_trgt","_obj","_unit","_safeUnits","_obj2"];
_obj  = _this select 0;
_trgt = _this select 1;

if !([_trgt,_this select 2]call EPOCH_server_getPToken)exitWith{};
diag_log format["DEBUG: Calling Sapper Detonate Player:%1 | Bomb: %2 | PToken: %3 ",_trgt,_obj,_this select 2];

_safeUnits = ["Epoch_Sapper_F","Epoch_SapperB_F"];

_unit = _this select 3;
//diag_log format ["DEBUG: Performing Sapper Detonate with %1 for %2",_unit,_trgt];

_obj2 = objNull;
if(count _this > 4)then{
    _obj2 = _this select 4;
};

if!(typeOf _unit in _safeUnits)exitWith{};

_obj setDamage 1;
if!(isNull _obj2)then{
    _obj2 setDamage 1;
};
