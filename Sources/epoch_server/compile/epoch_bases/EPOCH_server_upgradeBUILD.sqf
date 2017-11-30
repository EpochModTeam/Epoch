/*
	Author: Aaron Clark - EpochMod.com

    Contributors:

	Description:
    Building Upgrades

    Licence:
    Arma Public License Share Alike (APL-SA) - https://www.bistudio.com/community/licenses/arma-public-license-share-alike

    Github:
    https://github.com/EpochModTeam/Epoch/tree/release/Sources/epoch_server/compile/epoch_bases/EPOCH_server_upgradeBUILD.sqf
*/
//[[[cog import generate_private_arrays ]]]
private ["_cfgBaseBuilding","_class","_newObj","_objSlot","_objType","_upgrade","_upgrades"];
//[[[end]]]
params ["_object","_player",["_index",0],["_token","",[""]] ];

if (isNull _object) exitWith{};
if !([_player, _token] call EPOCH_server_getPToken) exitWith{};

_objSlot = _object getVariable["BUILD_SLOT", -1];
_cfgBaseBuilding = 'CfgBaseBuilding' call EPOCH_returnConfig;
if (_objSlot != -1) then {
	_upgrades = getArray(_cfgBaseBuilding >> (typeOf _object) >> "upgradeBuilding");
	if !(_upgrades isEqualTo []) then {
		_upgrade = _upgrades param [_index,[]];
		_class = _upgrade select 0;
		_newObj = [_class,_object] call EPOCH_swapBuilding;
		_newObj setVariable ["BUILD_SLOT",_objSlot,true];
		if (isDamageAllowed _newObj) then {		// Only needed, if damage is allowed
			_newObj call EPOCH_server_buildingInit;
		};
		_newObj call EPOCH_saveBuilding;
	};
} else {
	_objType = typeOf _object;
	if (getNumber(_cfgBaseBuilding >> _objType >> "isTemporary") == 1) then{
		_upgrades = getArray(_cfgBaseBuilding >> (typeOf _object) >> "upgradeBuilding");
		if !(_upgrades isEqualTo []) then {
			_upgrade = _upgrades param [_index,[]];
			_class = _upgrade select 0;
			_newObj = [_class,_object] call EPOCH_swapBuilding;
		};
	};
};
