/*
Building Save

Epoch Mod - EpochMod.com
All Rights Reserved.
*/
private["_objSlot", "_findnextslot", "_worldspace", "_objHiveKey", "_VAL", "_config", "_slot", "_storageObj", "_pos", "_buildClass", "_newVehicle", "_textureSlot", "_staticClass", "_vehicle", "_plyr", "_plyrUID", "_oemType"];

_vehicle =  _this select 0;
_plyr = _this select 1;

if (isNull _vehicle || isNull _plyr) exitWith{};
if !([_plyr,_this select 2] call EPOCH_server_getPToken) exitWith {};

_plyrUID = getPlayerUID _plyr;

if (!isNull ropeAttachedTo _vehicle) exitWith{};

_oemType = typeOf _vehicle;

_config = (configFile >> "CfgVehicles" >> _oemType >> "staticClass");
if (isText _config) then {

	_staticClass = getText(_config);

	if (_staticClass isKindOf "Buildable_Storage" || _staticClass isKindOf "Constructions_lockedstatic_F") then{

		if !(EPOCH_StorageSlots isEqualTo[]) then {

			_slot = EPOCH_StorageSlots deleteAt 0;
			EPOCH_StorageSlotsCount = count EPOCH_StorageSlots;
			publicVariable "EPOCH_StorageSlotsCount";

			// Secure and insecure storage
			_vehiclePos = getposATL _vehicle;
			_vectorDirAndUp = [vectordir _vehicle, vectorup _vehicle];
			deleteVehicle _vehicle;

			_storageObj = createVehicle[_staticClass, _vehiclePos, [], 0, "CAN_COLLIDE"];
			_storageObj setVectorDirAndUp _vectorDirAndUp;
			_storageObj setposATL _vehiclePos;

			if (getNumber(configFile >> "CfgVehicles" >> _staticClass >> "isSecureStorage") == 1) then{
				_storageObj setVariable["EPOCH_Locked", false, true];
			};

			_storageObj setVariable["STORAGE_OWNERS", [_plyrUID]];

			_storageObj setVariable["STORAGE_SLOT", _slot, true];

			_storageObj call EPOCH_server_save_storage;
			_storageObj call EPOCH_server_storageInit;

			diag_log format["STORAGE: %1 created storage %2 at %3 with slot %4", _plyrUID, _staticClass, _vehiclePos, _slot];
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

			EPOCH_BuildingSlotCount = { _x == 0 } count EPOCH_BuildingSlots;
			publicVariable "EPOCH_BuildingSlotCount";

			if (_objSlot != -1) then {
				_newVehicle = [_vehicle, false] call EPOCH_server_simulSwap;
				_newVehicle setVariable["BUILD_OWNER", _plyrUID, true];
				_newVehicle call EPOCH_fnc_saveBuilding;
			};

		} else {
			diag_log format["DEBUG BUILD SAVE ABORT TYPE ERROR: %1", _this]
		};

	};
};
true
