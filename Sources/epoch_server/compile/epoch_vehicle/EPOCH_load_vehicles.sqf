/*
	Author: Aaron Clark - EpochMod.com

    Contributors:

	Description:
    Load Vehicles

    Licence:
    Arma Public License Share Alike (APL-SA) - https://www.bistudio.com/community/licenses/arma-public-license-share-alike

    Github:
    https://github.com/EpochModTeam/Epoch/tree/release/Sources/epoch_server/compile/epoch_vehicle/EPOCH_load_vehicles.sqf
*/
private ["_availableColorsConfig","_location","_class","_dmg","_actualHitpoints","_hitpoints","_textures","_color","_colors","_textureSelectionIndex","_selections","_count","_objTypes","_objQty","_wMags","_wMagsArray","_attachments","_magazineSizeMax","_magazineName","_magazineSize","_qty","_objType","_marker","_found","_vehicle","_allHitpoints","_cfgEpochVehicles","_worldspace","_damage","_arr","_arrNum","_vehicleSlotIndex","_vehHiveKey","_response","_diag","_dataFormat","_dataFormatCount","_allVehicles","_serverSettingsConfig"];
params [["_maxVehicleLimit",0]];

_diag = diag_tickTime;
_dataFormat = ["", [], 0, [], 0, [], [], 0];
_dataFormatCount = count _dataFormat;
EPOCH_VehicleSlots = [];
_allVehicles = [];
_vehicleDamages = [];

_serverSettingsConfig = configFile >> "CfgEpochServer";
_simulationHandler = [_serverSettingsConfig, "simulationHandlerOld", false] call EPOCH_fnc_returnConfigEntry;

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

					// temp for changes in class names
					_found = ["O_Heli_Transport_04_F","O_Heli_Transport_04_bench_F","O_Heli_Transport_04_box_F","O_Heli_Transport_04_covered_F","B_Heli_Transport_03_unarmed_F","O_Truck_03_covered_F"] find _class;
					if (_found != -1) then {
						_class = ["O_Heli_Transport_04_EPOCH","O_Heli_Transport_04_bench_EPOCH","O_Heli_Transport_04_box_EPOCH","O_Heli_Transport_04_covered_EPOCH","B_Heli_Transport_03_unarmed_EPOCH","O_Truck_03_covered_EPOCH"] select _found;
					};

					// spawn vehicle at temp location.
					_vehicle = createVehicle [_class, _location, [], 0, "CAN_COLLIDE"];
					if !(isNull _vehicle) then {
						// make vehicle immune from damage.
						_vehicle allowDamage false;
						// store spawned vehicles in array to make one call to remains handler
						_allVehicles pushBack _vehicle;
						// remove selected slot from array and set on vehicle
						EPOCH_VehicleSlots deleteAt _vehicleSlotIndex;
						_vehicle setVariable ["VEHICLE_SLOT", str(_i), true];
						// set server side token and init vehicle event handlers.
						_vehicle call EPOCH_server_setVToken;
						_vehicle call EPOCH_server_vehicleInit;
						// set final direction and postion of vehicle
						_vehicle setVectorDirAndUp _worldspace;
						_vehicle setposATL _location;
						// push damage to temp array to apply damage after some delay
						_vehicleDamages pushBack [_vehicle,_damage,(_arr select 3)];
						// set fuel level
						_vehicle setFuel (_arr select 4);
						// apply persistent textures
						_cfgEpochVehicles = 'CfgEpochVehicles' call EPOCH_returnConfig;
						_availableColorsConfig = (_cfgEpochVehicles >> _class >> "availableColors");
						if (isArray(_availableColorsConfig)) then {
							_color = _arr select 7;
							_colors = getArray(_availableColorsConfig);
							_textureSelectionIndex = (_cfgEpochVehicles >> _class >> "textureSelectionIndex");
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
						// disable thermal imaging equipment
						_vehicle disableTIEquipment true;
						// lock all vehicles
						_vehicle lock true;
						// load vehicle inventory
						clearWeaponCargoGlobal    _vehicle;
						clearMagazineCargoGlobal  _vehicle;
						clearBackpackCargoGlobal  _vehicle;
						clearItemCargoGlobal      _vehicle;
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
													} else {
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
						// remove and add back magazines works for armed trucks but not helis ATM
						{_vehicle removeMagazineGlobal _x}count (magazines _vehicle);
						{_vehicle addMagazine _x}count (_arr select 6);

						// set damage and hitpoints
						_vehicle setDamage _damage;
						_allHitpoints = getAllHitPointsDamage _vehicle;
						if !(_allHitpoints isEqualTo []) then{
							_actualHitpoints = _allHitpoints select 0;
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
						_vehicle allowDamage true;
						// vehicle simulation handler
						if (_simulationHandler) then{
							_vehicle enableSimulationGlobal false;
						};
						// turrets
						/*
						_mags = _vehicle magazinesTurret [0];
						{
							_object removeMagazinesTurret [_x, [0]];
						} forEach _mags;
						_mags = _vehicle magazinesTurret [-1];
						{
							_object removeMagazinesTurret [_x, [-1]];
						} forEach _mags;
						*/
						if (EPOCH_DEBUG_VEH) then {
							_marker = createMarker [str(_location) , _location];
							_marker setMarkerShape "ICON";
							_marker setMarkerType "mil_dot";
							_marker setMarkerText _class;
							_marker setMarkerColor "ColorGreen";
						};
					} else {
						diag_log format["DEBUG: vehicle object Null: class: %1, loc: %2, slot: %3",_class, _location,str(_i)];
					};
				} else {
					diag_log format["DEBUG: invalid vehicle position array %1",_location];
				};
			} else {
				diag_log format["DEBUG: vehicle destroyed already (%2) or invalid vehicle class: %1",_class, _damage];
			};
		} else {
			diag_log format["DEBUG: invalid vehicle data count: %1 != %2",_arrNum,_dataFormatCount];
		};
	} else {
		diag_log format["DEBUG: invalid vehicle data: %1",_response];
	};
};
// add all spawned vehicles to remains collector.
addToRemainsCollector _allVehicles;
diag_log format ["Epoch: Vehicle SPAWN TIMER %1, LOADED %2 VEHICLES", diag_tickTime - _diag, count _allVehicles];
true
