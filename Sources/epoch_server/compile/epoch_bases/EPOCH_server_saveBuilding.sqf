/*
	Author: Aaron Clark - EpochMod.com

    Contributors:

	Description:
    Building Save

    Licence:
    Arma Public License Share Alike (APL-SA) - https://www.bistudio.com/community/licenses/arma-public-license-share-alike

    Github:
    https://github.com/EpochModTeam/Epoch/tree/release/Sources/epoch_server/compile/epoch_bases/EPOCH_server_saveBuilding.sqf
*/
//[[[cog import generate_private_arrays ]]]
private ["_cfgBaseBuilding","_findnextslot","_newVehicle","_objSlot","_oemType","_playerUID","_serverSettingsConfig","_slot","_staticClass","_staticClassConfig","_storageObj","_vehiclePos"];
//[[[end]]]
params ["_vehicle", "_player", ["_token","",[""]] ];

if (isNull _vehicle) exitWith{};
if !([_player,_token] call EPOCH_server_getPToken) exitWith {};

_playerUID = getPlayerUID _player;

if (!isNull ropeAttachedTo _vehicle) exitWith{};

_oemType = typeOf _vehicle;
_cfgBaseBuilding = 'CfgBaseBuilding' call EPOCH_returnConfig;
_staticClassConfig = (_cfgBaseBuilding >> _oemType >> "staticClass");
if (isText _staticClassConfig) then {

	_staticClass = getText(_staticClassConfig);
	if (_staticClass isKindOf "Buildable_Storage" || _staticClass isKindOf "Constructions_lockedstatic_F") then{

		if !(EPOCH_StorageSlots isEqualTo[]) then {

			_slot = EPOCH_StorageSlots deleteAt 0;
			missionNamespace setVariable ["EPOCH_StorageSlotsCount",count EPOCH_StorageSlots, true];

			// Secure and insecure storage
			_vehiclePos = getposATL _vehicle;

			_storageObj = [_staticClass,_vehicle] call EPOCH_swapBuilding;

			// add new gardens to manager
			if (_staticClass isEqualTo "Garden_EPOCH") then {
				EPOCH_activeGardens pushBackUnique _storageObj;
			};
			
			if (_staticClass in ["SolarCharger_EPOCH","SolarChargerXL_EPOCH"]) then {
				EPOCH_activeSolars pushBackUnique _storageObj;
			};

			if (getNumber(_cfgBaseBuilding >> _staticClass >> "isSecureStorage") == 1) then{
				_storageObj setVariable["EPOCH_Locked", false, true];
			};

			_storageObj setVariable["STORAGE_OWNERS", [_playerUID]];

			_storageObj setVariable["STORAGE_SLOT", _slot, true];

			_storageObj call EPOCH_server_save_storage;
			if (isDamageAllowed _storageObj) then {		// Only needed, if damage is allowed
				_storageObj call EPOCH_server_storageInit;
			};
			diag_log format["Epoch: STORAGE: %1 created storage %2 at %3 with slot %4", _playerUID, _staticClass, _vehiclePos, _slot];
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
				
				// add BaseCam to public array
				if (_newVehicle iskindof "BaseCam_EPOCH") then {
					_playerGroup = _player getVariable["GROUP", ""];
					_Owner = _playerUID;
					if (_playerGroup != "") then {
						_Owner = _playerGroup;
					};
					_newVehicle setVariable["BUILD_OWNER", _Owner, true];
					EPOCH_BaseCams pushBackUnique _newVehicle;
					publicvariable "EPOCH_BaseCams";
				}
				else {
					_newVehicle setVariable["BUILD_OWNER", _playerUID, true];
				};
				_newVehicle call EPOCH_saveBuilding;
			};

		} else {
			diag_log format["DEBUG BUILD SAVE ABORT TYPE ERROR: %1", _this]
		};

	};
};
true
