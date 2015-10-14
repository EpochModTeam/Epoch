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

	if (_staticClass isKindOf "Buildable_Storage") then {

		if !(EPOCH_StorageSlots isEqualTo[]) then {

			_config = (configFile >> "CfgVehicles" >> _oemType >> "staticClass");
			if (isText(_config)) then {

				_slot = EPOCH_StorageSlots select 0;
				EPOCH_StorageSlots = EPOCH_StorageSlots - [_slot];

				_vehiclePos = getposATL _vehicle;
				_worldspace = [(_vehiclePos call EPOCH_precisionPos), vectordir _vehicle, vectorup _vehicle];
				deleteVehicle _vehicle;

				_storageObj = createVehicle[_staticClass, _vehiclePos, [], 0, "CAN_COLLIDE"];
				_storageObj setVariable["STORAGE_SLOT", _slot, true];

				_storageObj setVectorDirAndUp[_worldspace select 1, _worldspace select 2];
				_storageObj setposATL _vehiclePos;

				_storageObj call EPOCH_server_save_storage;
				_storageObj call EPOCH_server_storageInit;

				diag_log format["STORAGE: %1 created storage %2 at %3", getPlayerUID _plyr, _staticClass, _vehiclePos];

				EPOCH_StorageSlotsCount = count EPOCH_StorageSlots;
				publicVariable "EPOCH_StorageSlotsCount";
			};
		};

	} else {

		// TODO: optimize by using config var
		if (_vehicle isKindOf "ThingX" || _vehicle isKindOf "Const_Ghost_EPOCH" || _vehicle isKindOf "PlotPole_EPOCH") then {

			_objSlot = _vehicle getVariable["BUILD_SLOT", -1];
			if (_objSlot == -1) then {
				_findnextslot = EPOCH_BuildingSlots find 0;
				if (_findnextslot != -1) then {
					_objSlot = _findnextslot;
					EPOCH_BuildingSlots set [_findnextslot,1];
					_vehicle setVariable["BUILD_SLOT", _findnextslot, true];
				};
			};

			// get texture slot index
			_textureSlot = _vehicle getVariable["TEXTURE_SLOT", 0];

			EPOCH_BuildingSlotCount = { _x == 0 } count EPOCH_BuildingSlots;
			publicVariable "EPOCH_BuildingSlotCount";


			if (_objSlot != -1) then {
				_vehiclePos = getposATL _vehicle;
				// _worldspace = [(_vehiclePos call EPOCH_precisionPos), vectordir _vehicle, vectorup _vehicle];
				// _objHiveKey = format["%1:%2", (call EPOCH_fn_InstanceID), _objSlot];

				_newVehicle = [_vehicle, false] call EPOCH_server_simulSwap;

				_newVehicle setVariable["BUILD_OWNER", _plyrUID, true];

				_slot = "-1";
				if (getNumber(configFile >> "CfgVehicles" >> _staticClass >> "isSecureStorage") == 1) then{

					//diag_log format["building lockbox %1", _oemType];

					_buildClass = getText(configFile >> "CfgVehicles" >> _staticClass >> "weaponHolderProxy");

					if (!isNull _newVehicle) then {

						//diag_log format["building lockbox !isnull %1", _newVehicle];

						if !(EPOCH_StorageSlots isEqualTo []) then {

							//diag_log format["building lockbox findslot %1", _newVehicle];
							if (_buildClass != "") then{

								// TODO need some sanity checks here
								_storageObj = createVehicle[_buildClass, _vehiclePos, [], 0.0, "CAN_COLLIDE"];

								_slot = EPOCH_StorageSlots select 0;
								EPOCH_StorageSlots = EPOCH_StorageSlots - [_slot];

								//diag_log format["building lockbox found slot %1", _slot];

								// missionNamespace setVariable[format["EPOCH_STORAGE_%1", _slot], _storageObj];

								_newVehicle setVariable["EPOCH_secureStorage", _slot];

								_newVehicle setVariable["EPOCH_Locked", false, true];

								_storageObj setVariable["STORAGE_OWNERS", [_plyrUID]];

								// _storageObj setVariable["EPOCH_secStorParent", _objSlot];
								_storageObj setVariable["STORAGE_SLOT", _slot, true];

								_storageObj call EPOCH_server_save_storage;

								_storageObj call EPOCH_server_storageInit;

								diag_log format["STORAGE: %1 created storage %2 at %3", _plyrUID, _buildClass, _pos];

								EPOCH_StorageSlotsCount = count EPOCH_StorageSlots;
								publicVariable "EPOCH_StorageSlotsCount";
							};
						};
					};
				} else {
					_newVehicle call EPOCH_fnc_saveBuilding;
				};

			};

		} else {
			diag_log format["DEBUG BUILD SAVE ABORT TYPE ERROR: %1", _this]
		};

	};
};
true
