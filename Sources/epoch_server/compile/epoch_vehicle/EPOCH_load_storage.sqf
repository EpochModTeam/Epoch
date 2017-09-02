/*
	Author: Aaron Clark - EpochMod.com

    Contributors:

	Description:
    Fill vehicle inventory

    Licence:
    Arma Public License Share Alike (APL-SA) - https://www.bistudio.com/community/licenses/arma-public-license-share-alike

    Github:
    https://github.com/EpochModTeam/Epoch/tree/release/Sources/epoch_server/compile/epoch_vehicle/EPOCH_load_storage.sqf
*/
//[[[cog import generate_private_arrays ]]]
private ["_ExceptedBaseObjects","_IndestructibleBaseObjects","_UseIndestructible","_arr","_attachments","_availableColorsConfig","_cfgBaseBuilding","_class","_class_raw","_color","_colors","_count","_damage","_diag","_dir","_inventory","_location","_magazineName","_magazineSize","_magazineSizeMax","_marker","_objQty","_objType","_objTypes","_qty","_response","_selections","_serverSettingsConfig","_storageSlotIndex","_textureSelectionIndex","_textures","_vehHiveKey","_vehicle","_wMags","_wMagsArray","_worldspace","_wsCount"];
//[[[end]]]
params [["_maxStorageLimit",0]];

_serverSettingsConfig = configFile >> "CfgEpochServer";
_UseIndestructible = [_serverSettingsConfig, "UseIndestructible", false] call EPOCH_fnc_returnConfigEntry;
_IndestructibleBaseObjects = [_serverSettingsConfig, "IndestructibleBaseObjects", []] call EPOCH_fnc_returnConfigEntry;
_ExceptedBaseObjects = [_serverSettingsConfig, "ExceptedBaseObjects", []] call EPOCH_fnc_returnConfigEntry;

_diag = diag_tickTime;
EPOCH_StorageSlots = [];
for "_i" from 1 to _maxStorageLimit do {
	_storageSlotIndex = EPOCH_StorageSlots pushBack str(_i);
	_vehHiveKey = format ["%1:%2", (call EPOCH_fn_InstanceID), _i];
	_response = ["Storage", _vehHiveKey] call EPOCH_fnc_server_hiveGETRANGE;
	if ((_response select 0) == 1 && (_response select 1) isEqualType []) then {
		_arr = _response select 1;
		if !(_arr isEqualTo []) then {
			EPOCH_StorageSlots deleteAt _storageSlotIndex;
			_class_raw = _arr select 0;
			_damage = _arr select 2;
			_inventory = _arr select 3;

			// legacy change class
			_class = switch (_class_raw) do {
				case "LockBoxProxy_EPOCH": { "LockBox_EPOCH" };
				case "SafeProxy_EPOCH": { "Safe_EPOCH" };
				default { _class_raw };
			};

			if !(_inventory isEqualType []) then { _inventory = []; };

			_worldspace = _arr select 1;
			_wsCount = count _worldspace;

			// new worldspace format
			if (_wsCount == 3) then {
				_location = _worldspace deleteAt 0;
				_dir = _worldspace;
			} else {
				_dir = _worldspace select 0;
				_location = _worldspace select 1;
			};

			// increased position precision
			if (count _location == 2) then{
				_location = (_location select 0) vectorAdd(_location select 1);
			};

			// set to ground if only x,y
			if (count _location == 2) then {
				_location set [2, 0];
			};

 			// try to recover from negitive z
			if ((_location select 2) < 0) then {
				_location set [2, 0];
			};

			_vehicle = createVehicle[_class, [0,0,0], [], 0, "CAN_COLLIDE"];

			if (_UseIndestructible) then {
				if ({_vehicle iskindof _x} count _ExceptedBaseObjects == 0) then {
					{
						if (_vehicle iskindof _x) exitwith {
							_vehicle allowdamage false;
						};
					} foreach _IndestructibleBaseObjects;
				};
			};

			if (_dir isEqualType []) then {
				_vehicle setVectorDirAndUp _dir;
				_vehicle setposATL _location;
			} else {
				_vehicle setDir _dir;
				_vehicle setposATL _location;
			};

			// temp set damage to mark for maint
			_vehicle setDamage 0.01;



			_vehicle setVariable ["STORAGE_SLOT", str(_i), true];

			_vehicle call EPOCH_server_storageInit;

			if (count _arr >= 5) then {
				_color = _arr select 4;
				_cfgBaseBuilding = 'CfgBaseBuilding' call EPOCH_returnConfig;
				_availableColorsConfig = _cfgBaseBuilding >> _class >> "availableColors";
				if (isArray _availableColorsConfig) then {
					_colors = getArray(_availableColorsConfig);
					_textureSelectionIndex = _cfgBaseBuilding >> _class >> "textureSelectionIndex";
					_selections = if (isArray(_textureSelectionIndex)) then { getArray(_textureSelectionIndex) } else { [0] };
					_count = (count _colors)-1;
					{
						_textures = _colors select 0;
						if (_count >= _forEachIndex) then {
							_textures = _colors select _forEachIndex;
						};
						_vehicle setObjectTextureGlobal [_x, (_textures  select _color)];
					} forEach _selections;
					_vehicle setVariable ["STORAGE_TEXTURE", _color];
				};
			};

			if (count _arr >= 6) then {
				_vehicle setVariable ["STORAGE_OWNERS", _arr select 5];
				if (_class isKindOf 'Constructions_lockedstatic_F') then{
					// set locked state of secure storage
					if ((_arr select 6) != -1) then {
						_vehicle setVariable["EPOCH_Locked", true, true];
						//_vehicle enableSimulationGlobal false;
					};
				};
			};

			clearWeaponCargoGlobal    _vehicle;
			clearMagazineCargoGlobal  _vehicle;
			clearBackpackCargoGlobal  _vehicle;
			clearItemCargoGlobal	  _vehicle;

			if !(_inventory isEqualTo []) then {
				[_vehicle,_inventory] call EPOCH_server_CargoFill;
			};

			if (EPOCH_DEBUG_VEH) then {
				_marker = createMarker [str(_location) , _location];
				_marker setMarkerShape "ICON";
				_marker setMarkerType "mil_dot";
				_marker setMarkerText _class;
				_marker setMarkerColor "ColorBlue";
			};
		};
	};
};

missionNamespace setVariable ['EPOCH_StorageSlotsCount', count EPOCH_StorageSlots, true];

diag_log format ["Epoch: Storage SPAWN TIMER %1 slots left: %2", diag_tickTime - _diag, EPOCH_StorageSlotsCount];

true
