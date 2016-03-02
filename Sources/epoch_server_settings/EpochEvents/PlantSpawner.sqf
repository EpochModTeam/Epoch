/*
  Plant Spawn Event
	by Aaron Clark - EpochMod.com
	This work is licensed under a Creative Commons Attribution-NonCommercial-NoDerivatives 4.0 International License.
	http://creativecommons.org/licenses/by-nc-nd/4.0/
	Improvements and or bugfixes and other contributions are welcome via the github:
	https://github.com/EpochModTeam/Epoch/tree/master/Sources/epoch_server_settings/EpochEvents/PlantSpawner.sqf
*/
private ["_displayName","_marker","_plants","_plant","_item","_plantPosition"];

_serverMapConfig = configFile >> "CfgEpoch" >> worldName;
_plantLimit = [_serverMapConfig, "plantLimit", 10] call EPOCH_fnc_returnConfigEntry;
if (isNil "EPOCH_plantCounter") then {
	EPOCH_plantCounter = 0;
} else {
	EPOCH_plantCounter = EPOCH_plantCounter + 1;
};
if (EPOCH_plantCounter >= _plantLimit) exitWith {diag_log "DEBUG: suppressed plant spawn over limit"};

_plantPosition = [epoch_centerMarkerPosition, 0, EPOCH_dynamicVehicleArea, 10, 0, 4000, 0] call BIS_fnc_findSafePos;

if ((count _plantPosition) == 2) then{
	_plants = ["Goldenseal_EPOCH", "Poppy_EPOCH", "Pumpkin_EPOCH"];
	_plant = selectRandom _plants;
	_item = createVehicle[_plant, _plantPosition, [], 0.0, "CAN_COLLIDE"];
	if (EPOCH_showShippingContainers) then{
		_displayName = getText(configfile >> "CfgVehicles" >> typeOf _item >> "DisplayName");
		_marker = createMarker[str(_plantPosition), _plantPosition];
		_marker setMarkerShape "ICON";
		_marker setMarkerType "mil_triangle";
		// _marker setMarkerText _displayName;
		_marker setMarkerColor "ColorGreen";
	};
};
