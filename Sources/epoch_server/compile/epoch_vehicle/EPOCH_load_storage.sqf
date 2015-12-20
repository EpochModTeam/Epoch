private [
	"_storageSlotIndex","_vehHiveKey","_response","_arr"
	,"_objType","_objTypes","_objQty"
	,"_class","_damage","_hitpoints","_fuel","_count","_inventory","_dir","_location","_vehicle","_actualHitpoints","_marker","_isAir","_isShip","_config","_magazines","_colors","_color"
];

_diag = diag_tickTime;

EPOCH_StorageSlots = [];
for "_i" from 1 to _this do {

	_storageSlotIndex = EPOCH_StorageSlots pushBack str(_i);

	_vehHiveKey = format ["%1:%2", (call EPOCH_fn_InstanceID), _i];
	_response = ["Storage", _vehHiveKey] call EPOCH_fnc_server_hiveGETRANGE;

	// diag_log format["STORAGE _response %1",_response];

	if ((_response select 0) == 1 && typeName (_response select 1) == "ARRAY") then {

		_arr = _response select 1;
		if !(_arr isEqualTo []) then {

			EPOCH_StorageSlots deleteAt _storageSlotIndex;

			_class_raw = _arr select 0;
			_damage = _arr select 2;
			_inventory = _arr select 3;

			_class = switch (_class_raw) do {
			    case "LockBoxProxy_EPOCH": { "LockBox_EPOCH" };
			    case "SafeProxy_EPOCH": { "Safe_EPOCH" };
			    default { _class_raw };
			};

			if (typeName(_inventory) != "ARRAY") then { _inventory = []; };

			_worldspace = _arr select 1;
			_wsCount = count _worldspace;
			//diag_log format ["DEBUG: _wsCount %1 _worldspace %2", _wsCount, _worldspace];

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

			_vehicle = createVehicle[_class, _location, [], 0, "CAN_COLLIDE"];

			if (typeName _dir == "ARRAY") then {
				_vehicle setVectorDirAndUp _dir;
			} else {
				_vehicle setDir _dir;
			};

			// temp set damage to mark for maint
			_vehicle setDamage 0.01;

			_vehicle setposATL _location;

			_vehicle setVariable ["STORAGE_SLOT", str(_i), true];

			// missionNamespace setVariable [format ["EPOCH_STORAGE_%1", _i], _vehicle];

			// diag_log format ["STORAGE: created storage %1 at %2", _class, _location];

			_vehicle call EPOCH_server_storageInit;

			if (count _arr >= 5) then {
				_color = _arr select 4;
				_config = configFile >> "CfgVehicles" >> _class >> "availableColors";
				if (isArray _config) then {
					_colors = getArray(_config);
					_textureSelectionIndex = configFile >> "CfgVehicles" >> _class >> "textureSelectionIndex";
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

				//diag_log format ["FILLING: storage %1 pos: %2", _vehicle, (getPosATL _vehicle)];
				{
					_objType = _forEachIndex;

					_objTypes = _x;
					_objQty = [];

					if (_objType in [1, 2, 3]) then {
						_objTypes = _x select 0;
						_objQty = _x select 1;
					};

					{
						switch _objType do {
							// Weapon cargo
							case 0: {
								if (typeName _x == "ARRAY") then {
									if ((count _x) >= 4) then {
										_vehicle addWeaponCargoGlobal[_x deleteAt 0, 1];

										_attachments = [];
										_wMags = false;
										_wMagsArray = [];
										// suppressor, laser, optics, magazines(array), bipods
										{
											// magazines
											if (typeName(_x) == "ARRAY") then{
												_wMags = true;
												_wMagsArray = _x;
											}
											else {
												// attachments
												if (_x != "") then{
													_attachments pushBack _x;
												};
											};
										} forEach _x;

										// add all attachments to vehicle
										// TODO replace with adding attachments directly to gun (Arma feature dependant)
										{
											_vehicle addItemCargoGlobal[_x, 1];
										} forEach _attachments;

										if (_wMags) then{
											if (typeName _wMagsArray == "ARRAY" && (count _wMagsArray) >= 2) then{
												_vehicle addMagazineAmmoCargo[_wMagsArray select 0, 1, _wMagsArray select 1];
											};
										};

									};
								};
							};
							// Magazine cargo
							case 1: {
								_magazineName = _x;
								_magazineSize = _objQty select _forEachIndex;

								if ((typeName _magazineName == "STRING") && (typeName _magazineSize == "SCALAR")) then {
									_magazineSizeMax = getNumber (configFile >> "CfgMagazines" >> _magazineName >> "count");

									// Add full magazines cargo
									_vehicle addMagazineAmmoCargo [_magazineName, floor (_magazineSize / _magazineSizeMax), _magazineSizeMax];

									// Add last non full magazine
									if ((_magazineSize % _magazineSizeMax) > 0) then {
										_vehicle addMagazineAmmoCargo [_magazineName, 1, floor (_magazineSize % _magazineSizeMax)];
									};
								};
							};
							// Backpack cargo
							case 2: {
								if (typeName _x == "STRING") then {
									_qty = _objQty select _forEachIndex;
									_vehicle addBackpackCargoGlobal [_x, _qty];
								};
							};
							// Item cargo
							case 3: {
								if (typeName _x == "STRING") then {
									_qty = _objQty select _forEachIndex;
									_vehicle addItemCargoGlobal [_x, _qty];
								};
							};
						};
					}forEach _objTypes;
				}forEach _inventory;
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

EPOCH_StorageSlotsCount = count EPOCH_StorageSlots;
publicVariable "EPOCH_StorageSlotsCount";

diag_log format ["Storage SPAWN TIMER: %1 slots left: %2", diag_tickTime - _diag, EPOCH_StorageSlotsCount];

true
