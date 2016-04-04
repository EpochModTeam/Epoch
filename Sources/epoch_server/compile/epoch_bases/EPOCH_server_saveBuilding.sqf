/*
	Author: Aaron Clark - EpochMod.com

    Contributors:

	Description:
    Building Save

    Licence:
    Arma Public License Share Alike (APL-SA) - https://www.bistudio.com/community/licenses/arma-public-license-share-alike

    Github:
    https://github.com/EpochModTeam/Epoch/tree/master/Sources/epoch_server/compile/epoch_bases/EPOCH_server_saveBuilding.sqf
*/
private["_objSlot", "_findnextslot", "_worldspace", "_objHiveKey", "_VAL", "_config", "_slot", "_storageObj", "_pos", "_buildClass", "_newVehicle", "_textureSlot", "_staticClass", "_playerUID", "_oemType"];
params ["_vehicle", "_player", ["_token","",[""]]];

if (isNull _vehicle) exitWith{};
if !([_player,_token] call EPOCH_server_getPToken) exitWith {};

_playerUID = getPlayerUID _player;

if (!isNull ropeAttachedTo _vehicle) exitWith{};

_oemType = typeOf _vehicle;

_config = (configFile >> "CfgVehicles" >> _oemType >> "staticClass");
if (isText _config) then {

	_staticClass = getText(_config);

	if (_staticClass isKindOf "Buildable_Storage" || _staticClass isKindOf "Constructions_lockedstatic_F") then{

		if !(EPOCH_StorageSlots isEqualTo[]) then {

			_slot = EPOCH_StorageSlots deleteAt 0;
			missionNamespace setVariable ["EPOCH_StorageSlotsCount",count EPOCH_StorageSlots, true];

			// Secure and insecure storage
			_vehiclePos = getposATL _vehicle;
			_vectorDirAndUp = [vectordir _vehicle, vectorup _vehicle];
			deleteVehicle _vehicle;

			_storageObj = createVehicle[_staticClass, _vehiclePos, [], 0, "CAN_COLLIDE"];

			_storageObj setposATL _vehiclePos;
			_storageObj setVectorDirAndUp _vectorDirAndUp;

			if (getNumber(configFile >> "CfgVehicles" >> _staticClass >> "isSecureStorage") == 1) then{
				_storageObj setVariable["EPOCH_Locked", false, true];
			};

			_storageObj setVariable["STORAGE_OWNERS", [_playerUID]];

			_storageObj setVariable["STORAGE_SLOT", _slot, true];

			_storageObj call EPOCH_server_save_storage;
			_storageObj call EPOCH_server_storageInit;

			diag_log format["STORAGE: %1 created storage %2 at %3 with slot %4", _playerUID, _staticClass, _vehiclePos, _slot];
		};

	} else {

		// TODO: optimize by using config var
		if (_vehicle isKindOf "ThingX" || _vehicle isKindOf "Const_Ghost_EPOCH" || _vehicle isKindOf "PlotPole_EPOCH") then {

			_objSlot = _vehicle getVariable["BUILD_SLOT", -1];
			if (_objSlot == -1) then{
				_findnextslot = EPOCH_BuildingSlots find 0;
				if (_findnextslot != -1) then{
					_objSlot = _findnextslot;
					EPOCH_BuildingSlots set[_findnextslot, 1];
					_vehicle setVariable["BUILD_SLOT", _findnextslot, true];
				};
			};

			missionNamespace setVariable ['EPOCH_BuildingSlotCount', { _x == 0 } count EPOCH_BuildingSlots, true];

			if (_objSlot != -1) then {
				_newVehicle = [_vehicle, false] call EPOCH_server_simulSwap;
				_newVehicle setVariable["BUILD_OWNER", _playerUID, true];
				_newVehicle call EPOCH_saveBuilding;
			};

		} else {
			diag_log format["DEBUG BUILD SAVE ABORT TYPE ERROR: %1", _this]
		};

	};
};
true
