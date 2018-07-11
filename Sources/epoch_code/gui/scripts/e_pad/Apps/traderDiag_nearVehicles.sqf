params [["_EnergyRequired",250],["_radius",250]];
if (missionnamespace getvariable ["Epoch_VehicleScanActive",false]) exitwith {};
if (EPOCH_playerEnergy - _EnergyRequired < 0) exitwith {
	[format ['You need %1 Energy to scan for near Players',_EnergyRequired], 5,[[0,0,0,0.5],[1,0.5,0,1]]] call Epoch_message;
};
Epoch_VehicleScanActive = true;
["Energy",-_EnergyRequired] call Epoch_GiveAttributes;
_radius spawn {
	private ["_dist","_trdrMsg","_veh","_vehs"];
	["Scanning for near Vehicles... Please wait...", 10,[[0,0,0,0.5],[1,0.5,0,1]]] call Epoch_message;
	uisleep (5 + random 3);
	_trdrMsg = "";
	_vehs = player nearEntities [["Landvehicle","SHIP","AIR","TANK"],_this];
	if (count _vehs < 1) then {
		_trdrMsg = format["%2 %1.",name player,selectRandom["I haven't seen anything lately","There is nothing around here","The last time the UAV went out it found nothing"]];
	} else {
		_veh = selectrandom _vehs;
		_dist = ceil ((_veh distance player) / 100) * 100;
		_trdrMsg = format["I know of at least one vehicle within about %1m. It looks like a %2.",_dist, (typeof _veh) call EPOCH_itemDisplayName];
	};
	[_trdrMsg, 5,[[0,0,0,0.5],[1,0.5,0,1]]] call Epoch_message;
	Epoch_VehicleScanActive = nil;
};
