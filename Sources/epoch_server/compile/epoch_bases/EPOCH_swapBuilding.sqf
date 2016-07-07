// _newObj = [_class,_object] call EPOCH_swapBuilding;
private ["_objectPos","_newObj"];
params [["_class",""],["_object",objNull],["_method",0]];
_newObj = objNull;
if (!isNull _object && !(_class isEqualTo "")) then {
    _objectPos = getPosWorld _object;
    _newObj = createVehicle [_class, ASLtoAGL _objectPos, [], 0, "CAN_COLLIDE"];
    if (!isNull _newObj) then {
        _object hideObjectGlobal true;

        switch (_method) do {
            case 0: {
                _newObj setVectorDirAndUp [vectordir _object, vectorup _object];
                _newObj setPosWorld _objectPos;
            };
            case 1: {
                _newObj attachTo [_object,[0,0,0]];
            };
        };

        deleteVehicle _object;
    };
};
_newObj
