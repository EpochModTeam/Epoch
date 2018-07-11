params [["_EnergyRequired",250],["_radius",250]];
if (missionnamespace getvariable ["Epoch_PlayerScanActive",false]) exitwith {};
if (EPOCH_playerEnergy - _EnergyRequired < 0) exitwith {
	[format ['You need %1 Energy to scan for near Players',_EnergyRequired], 5,[[0,0,0,0.5],[1,0.5,0,1]]] call Epoch_message;
};
Epoch_PlayerScanActive = true;
["Energy",-_EnergyRequired] call Epoch_GiveAttributes;
_radius spawn {
	private ["_plyr","_plyrs","_trdrMsg"];
	["Scanning for near Players... Please wait...", 10,[[0,0,0,0.5],[1,0.5,0,1]]] call Epoch_message;
	uisleep (5 + random 3);
	_trdrMsg = "";
	_plyrs = (player nearEntities _this) select {isplayer _x};
	if (count _plyrs < 2) then {
		_trdrMsg = format["Apart from you %1. %2",name player, selectRandom ["I haven't seen any round these parts for a long while.","It has been very quiet around here,","There is not much to report !"]];
	} else {
		_plyrs deleteAt 0;
		_plyr = selectRandom _plyrs;
		_trdrMsg = format["%2 %1.",name _plyr, selectRandom ["The last person picked up by the UAV was","I did spot someone earlier, their name was","I heard there was somebody new in the area, "]];
	};
	[_trdrMsg, 5,[[0,0,0,0.5],[1,0.5,0,1]]] call Epoch_message;
	Epoch_PlayerScanActive = nil;
};