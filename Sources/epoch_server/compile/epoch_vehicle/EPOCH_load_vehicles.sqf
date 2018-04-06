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
//[[[cog import generate_private_arrays ]]]
private ["_actualHitpoints","_allHitpoints","_allVehicles","_allowDamage","_arr","_arrNum","_availableColorsConfig","_cfgEpochVehicles","_check","_class","_colors","_config","_count","_dataFormat","_dataFormatCount","_diag","_dmg","_found","_immuneIfStartInBase","_jammerOwner","_jammerRange","_jammers","_location","_lockedOwner","_marker","_nearestJammer","_removemagazinesturret","_removeweapons","_response","_selections","_serverSettingsConfig","_textureSelectionIndex","_textures","_vehHiveKey","_vehLockHiveKey","_vehicle","_vehicleSlotIndex"];
//[[[end]]]
params [["_maxVehicleLimit",0]];

_diag = diag_tickTime;
_dataFormat = ["", [], 0, [], 0, [], [], 0, ""];
_dataFormatCount = count _dataFormat;
EPOCH_VehicleSlots = [];
_allVehicles = [];


_config = 'CfgEpochClient' call EPOCH_returnConfig;
_jammerRange = getNumber(_config >> "buildingJammerRange");

_serverSettingsConfig = configFile >> "CfgEpochServer";
_immuneIfStartInBase = [_serverSettingsConfig, "immuneIfStartInBase", true] call EPOCH_fnc_returnConfigEntry;
_vehicleDynamicSimulationSystem = [_serverSettingsConfig, "vehicleDynamicSimulationSystem", true] call EPOCH_fnc_returnConfigEntry;

_removeweapons = [_serverSettingsConfig, "removevehweapons", []] call EPOCH_fnc_returnConfigEntry;
_removemagazinesturret = [_serverSettingsConfig, "removevehmagazinesturret", []] call EPOCH_fnc_returnConfigEntry;
_disableVehicleTIE = [_serverSettingsConfig, "disableVehicleTIE", true] call EPOCH_fnc_returnConfigEntry;

for "_i" from 1 to _maxVehicleLimit do {
	_vehicleSlotIndex = EPOCH_VehicleSlots pushBack str(_i);

	_vehHiveKey = format ["%1:%2", call EPOCH_fn_InstanceID,_i];
	_response = ["Vehicle", _vehHiveKey] call EPOCH_fnc_server_hiveGETRANGE;

	if ((_response select 0) == 1 && (_response select 1) isEqualType []) then {
		_arr = _response select 1;
		_arrNum = count _arr;

		// New Upgrade System adds to DB array, check and correct older saved vehicles
		if (_arrNum < _dataFormatCount) then {
			{
				_check = _arr select _foreachindex;
				if (isnil '_check') then {
					_arr pushback (_dataFormat select _foreachindex);
				};
			} foreach _dataFormat;
			// recount array
			_arrNum = count _arr;
		};

		if (_arrNum == _dataFormatCount) then {

			// Validate and replace invaild data
			{
				if !((_arr select _forEachIndex) isEqualType _x) then {_arr set[_forEachIndex, _x]};
			} forEach _dataFormat;

			_arr params ["_class","_worldspace","_damage","_hitpoints","_fuel","_inventory","_ammo","_color","_baseClass"];

			if (_class != "" && _damage < 1) then {
				// remove location from worldspace and set to new var
				_worldspace params [["_location",[]],["_VectorDir",[0,0,0]],["_VectorUp",[0,0,1]],["_useposworld",false]];
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
					_vehicle = createVehicle [_class, [random 500, random 500,500], [], 0, "CAN_COLLIDE"];
					// turn off BIS randomization
					_vehicle setVariable ["BIS_enableRandomization", false];
					if !(isNull _vehicle) then {

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

						// make vehicle immune from further damage.
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
						_vehicle setVectorDirAndUp [_VectorDir,_VectorUp];
						if (_useposworld) then {
							_vehicle setposWorld _location;
						}
						else {
							_vehicle setposATL _location;
						};
						// set fuel level
						_vehicle setFuel _fuel;
						// apply persistent textures
						_cfgEpochVehicles = 'CfgEpochVehicles' call EPOCH_returnConfig;
						_availableColorsConfig = (_cfgEpochVehicles >> _class >> "availableColors");
						if (isArray(_availableColorsConfig)) then {
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
						if !(_baseClass isequalto "") then {
							_vehicle setvariable ["VEHICLE_BASECLASS",_baseClass];
						};
						// disable thermal imaging equipment
						if (_disableVehicleTIE) then {
							_vehicle disableTIEquipment true;
						};
						// lock all vehicles
						_vehicle lock true;
						// load vehicle inventory
						clearWeaponCargoGlobal _vehicle;
						clearMagazineCargoGlobal _vehicle;
						clearBackpackCargoGlobal _vehicle;
						clearItemCargoGlobal _vehicle;

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

						// utilize He-Man's new Cargo functions
						[_vehicle,_inventory] call EPOCH_server_CargoFill;

						// remove and add back magazines
						if !(_ammo isequalto []) then {
							if ((_ammo select 0) isequaltype true) then {
								{
									_vehicle removeMagazinesTurret [_x select 0, _x select 1];
								} foreach magazinesAllTurrets _vehicle;
								{
									if ((_x select 2) > 0) then {
										_vehicle addMagazineTurret [_x select 0,_x select 1,_x select 2];
									};
								} foreach (_ammo select 1);
							}
							else {
								{_vehicle removeMagazineGlobal _x}count (magazines _vehicle);
								{_vehicle addMagazine _x}count _ammo;
							};
						};

						// allow damage
						_allowDamage = true;
						if (_immuneIfStartInBase) then {
							_jammers = nearestObjects[_vehicle, ["PlotPole_EPOCH"], _jammerRange];
							if!(_jammers isEqualTo [])then {
								// get jammer owner
								_nearestJammer = _jammers select 0;
								_jammerOwner = _nearestJammer getVariable["BUILD_OWNER", "-2"];
								// get vehicle lock owner
								_lockedOwner = "-1";
								_vehLockHiveKey = format["%1:%2", (call EPOCH_fn_InstanceID), str(_i)];
								(["VehicleLock", _vehLockHiveKey] call EPOCH_fnc_server_hiveGETRANGE) params [["_status", 0 ],["_payload", [] ]];
								if (_status isEqualTo 1) then {
									_lockedOwner = _payload param [0,"-1"];
								};
								// if match keep vehicle immune till first unlock
								if (_jammerOwner isEqualTo _lockedOwner) then {
									_vehicle setVariable ["EPOCH_disallowedDamage", true];
									_allowDamage = false;
								};
							};
						};

						if (_allowDamage) then {
							_vehicle allowDamage true;
						};

						// new Dynamicsimulation
						if(_vehicleDynamicSimulationSystem)then
						{
							_vehicle enableSimulationGlobal false; // turn it off until activated by dynamicSim
							_vehicle enableDynamicSimulation true;
						};

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
		};
	} else {
		diag_log format["DEBUG: invalid vehicle data: %1",_response];
	};
};
// add all spawned vehicles to remains collector.
addToRemainsCollector _allVehicles;
diag_log format ["Epoch: Vehicle SPAWN TIMER %1, LOADED %2 VEHICLES", diag_tickTime - _diag, count _allVehicles];
true
