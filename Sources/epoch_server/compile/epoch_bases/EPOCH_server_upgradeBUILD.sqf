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
private["_cfgBaseBuilding","_worldspace", "_class", "_newObj", "_objHiveKey", "_VAL", "_return", "_upgrade", "_objSlot", "_objType"];
params ["_object","_player",["_index",0],["_token","",[""]]];

if (isNull _object) exitWith{};
if !([_player, _token] call EPOCH_server_getPToken) exitWith{};

_objSlot = _object getVariable["BUILD_SLOT", -1];
_cfgBaseBuilding = 'CfgBaseBuilding' call EPOCH_returnConfig;
if (_objSlot != -1) then {
	_upgrades = getArray(_cfgBaseBuilding >> (typeOf _object) >> "upgradeBuilding");
	if !(_upgrades isEqualTo []) then {
		_upgrade = _upgrades param [_index,[]];
		_objectPos = getposATL _object;
		_worldspace = [(_objectPos call EPOCH_precisionPos), vectordir _object, vectorup _object];
		deleteVehicle _object;
		_class = _upgrade select 0;
		_newObj = createVehicle [_class, [0,0,0], [], 0, "CAN_COLLIDE"];
		_newObj setVariable ["BUILD_SLOT",_objSlot,true];
		_newObj call EPOCH_server_buildingInit;
		_newObj setVectorDirAndUp [(_worldspace select 1),(_worldspace select 2)];
		_newObj setposATL _objectPos;
		_newObj call EPOCH_saveBuilding;
	};
} else {
	_objType = typeOf _object;
	if (getNumber(_cfgBaseBuilding >> _objType >> "isTemporary") == 1) then{
		_upgrades = getArray(_cfgBaseBuilding >> (typeOf _object) >> "upgradeBuilding");
		if !(_upgrades isEqualTo []) then {
			_upgrade = _upgrades param [_index,[]];
			_worldspace = [getposATL _object, vectordir _object, vectorup _object];
			deleteVehicle _object;
			_class = _upgrade select 0;
			_newObj = createVehicle[_class, [0,0,0], [], 0, "CAN_COLLIDE"];
			_newObj setVectorDirAndUp[(_worldspace select 1), (_worldspace select 2)];
			_newObj setposATL(_worldspace select 0);
		};
	};
};
