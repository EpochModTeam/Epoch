/*
	Author: Aaron Clark - EpochMod.com

    Contributors:

	Description:
    Load Vehicles

    Licence:
    Arma Public License Share Alike (APL-SA) - https://www.bistudio.com/community/licenses/arma-public-license-share-alike

    Github:
    https://github.com/EpochModTeam/Epoch/tree/master/Sources/epoch_server/compile/epoch_vehicle/EPOCH_load_vehicles.sqf
*/
private ["_removeweapons","_removemagazinesturret","_location","_class","_dmg","_actualHitpoints","_hitpoints","_textures","_color","_colors","_textureSelectionIndex","_selections","_count","_objTypes","_objQty","_wMags","_wMagsArray","_attachments","_magazineSizeMax","_magazineName","_magazineSize","_qty","_objType","_marker","_found","_vehicle","_allHitpoints","_config","_worldspace","_damage","_arr","_arrNum","_vehicleSlotIndex","_vehHiveKey","_response","_immuneVehicleSpawnTime","_diag","_dataFormat","_dataFormatCount","_allVehicles","_serverSettingsConfig","_simulationHandler","_immuneVehicleSpawn"];
params [["_maxVehicleLimit",0]];

_diag = diag_tickTime;
_dataFormat = ["", [], 0, [], 0, [], [], 0];
_dataFormatCount = count _dataFormat;
EPOCH_VehicleSlots = [];
_allVehicles = [];

_serverSettingsConfig = configFile >> "CfgEpochServer";
_simulationHandler = [_serverSettingsConfig, "simulationHandlerOld", false] call EPOCH_fnc_returnConfigEntry;
_immuneVehicleSpawn = [_serverSettingsConfig, "immuneVehicleSpawn", false] call EPOCH_fnc_returnConfigEntry;
_removeweapons = [_serverSettingsConfig, "removevehweapons", []] call EPOCH_fnc_returnConfigEntry;
_removemagazinesturret = [_serverSettingsConfig, "removevehmagazinesturret", []] call EPOCH_fnc_returnConfigEntry;

for "_i" from 1 to _maxVehicleLimit do {
	_vehicleSlotIndex = EPOCH_VehicleSlots pushBack str(_i);

	_vehHiveKey = format ["%1:%2", call EPOCH_fn_InstanceID,_i];
	_response = ["Vehicle", _vehHiveKey] call EPOCH_fnc_server_hiveGETRANGE;

	if ((_response select 0) == 1 && (_response select 1) isEqualType []) then {
		_arr = _response select 1;
		_arrNum = count _arr;

		if (_arrNum == _dataFormatCount) then {

			// Validate and replace invaild data
			{
				if !((_arr select _forEachIndex) isEqualType _x) then {_arr set[_forEachIndex, _x]};
			} forEach _dataFormat;

			_class = _arr select 0;
			_worldspace = _arr select 1;
			_damage = _arr select 2;

			if (_class != "" && _damage < 1) then {
				_location = _worldspace deleteAt 0;

				if !(_location isEqualTo []) then {

					// increased position precision
					if (count _location == 2) then{
						_location = (_location select 0) vectorAdd (_location select 1);
					};

					EPOCH_VehicleSlots deleteAt _vehicleSlotIndex;

					// temp for changes in class names
					_found = ["O_Heli_Transport_04_F","O_Heli_Transport_04_bench_F","O_Heli_Transport_04_box_F","O_Heli_Transport_04_covered_F","B_Heli_Transport_03_unarmed_F","O_Truck_03_covered_F"] find _class;
					if (_found != -1) then {
						_class = ["O_Heli_Transport_04_EPOCH","O_Heli_Transport_04_bench_EPOCH","O_Heli_Transport_04_box_EPOCH","O_Heli_Transport_04_covered_EPOCH","B_Heli_Transport_03_unarmed_EPOCH","O_Truck_03_covered_EPOCH"] select _found;
					};

					_vehicle = createVehicle [_class, _location, [], 0, "CAN_COLLIDE"];
					_allVehicles pushBack _vehicle;
					_vehicle call EPOCH_server_setVToken;
					_vehicle setVectorDirAndUp _worldspace;
					_vehicle setposATL _location;
					_vehicle setDamage _damage;

					_allHitpoints = getAllHitPointsDamage _vehicle;
					if !(_allHitpoints isEqualTo []) then{
						_actualHitpoints = _allHitpoints select 0;
						_hitpoints = _arr select 3;
						if ((count _actualHitpoints) == (count _hitpoints)) then{
							{
								_dmg = _hitpoints param [_forEachIndex,0];
								if (_x in ["HitFuel", "HitEngine"]) then {
									_dmg = _dmg min 0.9;
								};
								_vehicle setHitIndex [_forEachIndex, _dmg];
							} forEach _actualHitpoints;
						};
					};

					if (_immuneVehicleSpawn) then{
						_vehicle allowDamage false;
					};

					_vehicle setFuel (_arr select 4);

					_vehicle call EPOCH_server_vehicleInit;

					_config = configFile >> "CfgVehicles" >> _class >> "availableColors";
					if (isArray(_config)) then {
						_color = _arr select 7;
						_colors = getArray(_config);
						_textureSelectionIndex = configFile >> "CfgVehicles" >> _class >> "textureSelectionIndex";
						_selections = if (isArray(_textureSelectionIndex)) then { getArray(_textureSelectionIndex) } else { [0] };
						_count = (count _colors) - 1;
						{
							_textures = _colors select 0;
							if (_count >= _forEachIndex) then {
								_textures = _colors select _forEachIndex;
							};
							_vehicle setObjectTextureGlobal [_x, _textures  select _color];
						} forEach _selections;
						_vehicle setVariable ["VEHICLE_TEXTURE", _color];
					};

					clearWeaponCargoGlobal    _vehicle;
					clearMagazineCargoGlobal  _vehicle;
					clearBackpackCargoGlobal  _vehicle;
					clearItemCargoGlobal      _vehicle;

					if !(_removeweapons isequalto []) then {
						{
							_vehicle removeWeaponGlobal _x;
						} foreach _removeweapons;
					};
					if !(_removemagazinesturret isequalto []) then {
						{
							_vehicle removeMagazinesTurret _x;
						} foreach _removemagazinesturret;
					};

					_vehicle disableTIEquipment true;

					_vehicle lock true;

					_vehicle setVariable ["VEHICLE_SLOT", str(_i), true];

					//diag_log format ["FILLING: _vehicle %1 pos: %2", _vehicle, (getPosATL _vehicle)];
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
									if (_x isEqualType []) then {
										if ((count _x) >= 4) then {

											_vehicle addWeaponCargoGlobal[_x deleteAt 0, 1];

											_attachments = [];
											_wMags = false;
											_wMagsArray = [];
											// suppressor, laser, optics, magazines(array), bipods
											{
												// magazines
												if (_x isEqualType []) then{
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
												if (_wMagsArray isEqualType [] && (count _wMagsArray) >= 2) then{
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

									if ((_magazineName isEqualType "STRING") && (_magazineSize isEqualType 0)) then {
										_magazineSizeMax = getNumber (configFile >> "CfgMagazines" >> _magazineName >> "count");
										if (_magazineSizeMax >= 1) then {
											// Add full magazines cargo
											_vehicle addMagazineAmmoCargo [_magazineName, floor (_magazineSize / _magazineSizeMax), _magazineSizeMax];

											// Add last non full magazine
											if ((_magazineSize % _magazineSizeMax) > 0) then {
												_vehicle addMagazineAmmoCargo [_magazineName, 1, floor (_magazineSize % _magazineSizeMax)];
											};
										};
									};
								};
								// Backpack cargo
								case 2: {
									if (_x isEqualType "STRING") then {
										_qty = _objQty select _forEachIndex;
										_vehicle addBackpackCargoGlobal [_x, _qty];
									};
								};
								// Item cargo
								case 3: {
									if (_x isEqualType "STRING") then {
										_qty = _objQty select _forEachIndex;
										_vehicle addItemCargoGlobal [_x, _qty];
									};
								};
							};
						} forEach _objTypes;
					} forEach (_arr select 5);

					// remove and add back magazines
					if !((_arr select 6) isequalto []) then {
						if ((_arr select 6 select 0) isequaltype true) then {
							{
								_vehicle removeMagazinesTurret [_x select 0, _x select 1];
							} foreach magazinesAllTurrets _vehicle;
							{
								if ((_x select 2) > 0) then {
									_vehicle addMagazineTurret [_x select 0,_x select 1,_x select 2];
								};
							} foreach (_arr select 6 select 1);
						}
						else {
							{_vehicle removeMagazineGlobal _x}count (magazines _vehicle);
							{_vehicle addMagazine _x}count (_arr select 6);
						};
					};

					if (EPOCH_DEBUG_VEH) then {
						_marker = createMarker [str(_location) , _location];
						_marker setMarkerShape "ICON";
						_marker setMarkerType "mil_dot";
						_marker setMarkerText _class;
						_marker setMarkerColor "ColorGreen";
					};

					if (_simulationHandler) then{
						_vehicle enableSimulationGlobal false;
					};
				};
			};
		};
	};
};

// re-enable damage to vehicles after we wait
if (_immuneVehicleSpawn) then{
	_immuneVehicleSpawnTime = [_serverSettingsConfig, "immuneVehicleSpawnTime", 120] call EPOCH_fnc_returnConfigEntry;
	[_allVehicles,_immuneVehicleSpawnTime] spawn{
		sleep (_this select 1);
		{_x allowDamage true} count (_this select 0);
	};
};

addToRemainsCollector _allVehicles;

diag_log format ["Epoch: Vehicle SPAWN TIMER %1, LOADED %2 VEHICLES", diag_tickTime - _diag, count _allVehicles];

true
