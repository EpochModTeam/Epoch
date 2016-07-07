/*
	Author: Aaron Clark - EpochMod.com

    Contributors:

	Description:
    Building - Converts to static all simulated objects that have not moved since last check

    Licence:
    Arma Public License Share Alike (APL-SA) - https://www.bistudio.com/community/licenses/arma-public-license-share-alike

    Github:
    https://github.com/EpochModTeam/Epoch/tree/release/Sources/epoch_server/compile/epoch_bases/EPOCH_server_simToStatic.sqf
*/
private ["_newObj","_class","_objSlot","_cfgBaseBuilding","_lastPosition","_currentPosition","_entities"];
_entities = allMissionObjects "Constructions_modular_F";
{
	_lastPosition = _x getVariable["LAST_POS", []];
	_currentPosition = getposATL _x;
	if (_lastPosition isEqualTo _currentPosition) then {
		_cfgBaseBuilding = 'CfgBaseBuilding' call EPOCH_returnConfig;
		_staticClassConfig = (_cfgBaseBuilding >> (typeOf _x) >> "staticClass");
		if (isText(_staticClassConfig)) then {
			_class = getText(_staticClassConfig);
			_objSlot = _x getVariable["BUILD_SLOT", -1];
			if (_objSlot != -1) then {
				_newObj = [_class,_x] call EPOCH_swapBuilding;
				_newObj setVariable ["BUILD_SLOT",_objSlot,true];
				_newObj call EPOCH_server_buildingInit;
			};
		};
	};
	_x setVariable ["LAST_POS",_currentPosition];
	uiSleep 1;
} forEach _entities;
