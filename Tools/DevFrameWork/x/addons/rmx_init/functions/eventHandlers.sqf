/*
	Function Name:			rmx_fnc_eventHandlers
	Author:					Raimonds Virtoss | Raymix
	Description:			Bunch of EHs
	
	License:				---
*/

[] spawn {
	if !(isServer) then {
		waitUntil { uiSleep 0.1; (!isNull (findDisplay 46) && (!isNil "EPOCH_loadingScreenDone")) };
	};
	uiSleep 2; //increase if EH is not getting applied
	(findDisplay 46) displayAddEventHandler ["KeyDown","_this call rmx_fnc_keyDown"];
	//(findDisplay 46) displayAddEventHandler ["KeyUp","_this call rmx_fnc_keyUp"];
};

true
