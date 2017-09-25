// _newObj = [_class,_object] call EPOCH_swapBuilding;
//[[[cog import generate_private_arrays ]]]
private ["_newObj","_objectPos","_playersNear"];
//[[[end]]]
params [["_class",""],["_object",objNull],["_method",0]];
_newObj = objNull;
if (!isNull _object && !(_class isEqualTo "")) then {
    _objectPos = getPosWorld _object;
    _newObj = createVehicle [_class, ASLtoAGL _objectPos, [], 0, "CAN_COLLIDE"];
    if (!isNull _newObj) then {
        _object hideObjectGlobal true;

		// new Dynamicsimulation
		if(["CfgDynamicSimulation", "baseDynamicSimulationSystem", true] call EPOCH_fnc_returnConfigEntryV2)then
		{
			_newObj enableDynamicSimulation true;
			_newObj triggerDynamicSimulation false; // this object doesnt need to turn anything on in the server
		};

        switch (_method) do {
            case 0: {
                _newObj setPosWorld _objectPos;
                _newObj setVectorDirAndUp [vectordir _object, vectorup _object];
            };
            case 1: {
                _newObj attachTo [_object,[0,0,0]];
            };
        };
        deleteVehicle _object;

        // force nearby players to reveal new object faster
        _playersNear = _newObj nearEntities[["Epoch_Male_F", "Epoch_Female_F"], 300];
        {
            [_x, _newObj] remoteExec ['reveal',_x];
        }forEach _playersNear;

    };
};
_newObj
