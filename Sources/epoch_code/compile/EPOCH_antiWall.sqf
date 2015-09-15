/*
	A3 Epoch Anti-Vehicle Wall glitch
*/
_vehicle = _this select 0;
_position = _this select 1;
_unit = _this select 2;

if (_unit == player) then {

	_vehicle removeAllEventHandlers "GetOut";
	EPOCH_currentVehicle = objNull;

	_worldPos = getPosATLVisual _vehicle;
	_worldPos set[2, (_worldPos select 2) + 1];

	_front = _worldPos;

	_dirTo = [_vehicle, player] call BIS_fnc_dirTo;
	_front2 = [_worldPos, (_vehicle distance player) + 1, _dirTo] call BIS_fnc_relPos;

	{
		if (_x isKindOf "Const_All_Walls_F") exitWith{
			player moveInAny _vehicle;
			EPOCH_antiWallCount = EPOCH_antiWallCount + 1;
		};
	} forEach lineintersectsobjs[ATLToASL _front, ATLToASL _front2, player, _vehicle, true, 2];
};


/*
onEachFrame{ drawLine3D[EP_front, EP_front2, [1, 0, 0, 1]]; };


[] spawn {
	while {true} do {
		if (vehicle player != player) then {
			if (isNull EPOCH_currentVehicle) then {
				EPOCH_currentVehicle = (vehicle player);
				EPOCH_currentVehicle addEventHandler ["GetOut", "_this call EPOCH_antiWall"];	
				hint format ['selected %1',EPOCH_currentVehicle];
			};
		};
		uiSleep 0.2;
	};
};

// older stuff
EP = getText (configFile >> "cfgVehicles" >> typeOf cursortarget >> "memoryPointsGetInDriver");    
EP_modelPos = cursortarget selectionPosition EP;      
EP_worldPos = cursorTarget modelToWorld EP_modelPos;
EP1 = getText (configFile >> "cfgVehicles" >> typeOf cursortarget >> "memoryPointsGetInDriverDir");  

EP1_modelPos = cursortarget selectionPosition EP1;     
EP1_worldPos = cursorTarget modelToWorld EP1_modelPos;                                                                                                              

EP_worldPos set [2, 1];
EP1_worldPos set [2, 1];

onEachFrame {   drawLine3D [EP_worldPos, EP1_worldPos, [1,0,0,1]];  };


EP = getText (configFile >> "cfgVehicles" >> typeOf cursortarget >> "memoryPointsGetInCargo");    
EP_modelPos = cursortarget selectionPosition EP;      
EP_worldPos = cursorTarget modelToWorld EP_modelPos;
EP1 = getText (configFile >> "cfgVehicles" >> typeOf cursortarget >> "memoryPointsGetInCargoDir");  

EP1_modelPos = cursortarget selectionPosition EP1;     
EP1_worldPos = cursorTarget modelToWorld EP1_modelPos;                                                                                                              

EP_worldPos set [2, 1];
EP1_worldPos set [2, 1];

onEachFrame {   drawLine3D [EP_worldPos, EP1_worldPos, [1,0,0,1]];  };


*/