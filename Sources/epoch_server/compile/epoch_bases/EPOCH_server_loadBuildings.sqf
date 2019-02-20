/*
	Author: Aaron Clark - EpochMod.com

    Contributors: Skaronator

	Description:
	Load Buildings from Epoch Hive

    Licence:
    Arma Public License Share Alike (APL-SA) - https://www.bistudio.com/community/licenses/arma-public-license-share-alike

    Github:
    https://github.com/EpochModTeam/Epoch/tree/release/Sources/epoch_server/compile/epoch_bases/EPOCH_server_loadBuildings.sqf
*/
//[[[cog import generate_private_arrays ]]]
private ["_Simulated","_DamageAllowed","_ExceptedBaseObjects","_IndestructibleBaseObjects","_UseIndestructible","_VAL","_ammoClass","_ammoObj","_anims","_animsData","_arr","_arrCount","_baseObj","_cfgBaseBuilding","_class","_color","_damage","_location","_marker","_maxTTL","_owner","_response","_serverSettingsConfig","_storageSlot","_textureSlot","_ttl","_vehHiveKey","_worldspace"];
//[[[end]]]
EPOCH_BaseCams = [];
EPOCH_Plotpoles = [];
_maxTTL = parseNumber EPOCH_expiresBuilding;
_serverSettingsConfig = configFile >> "CfgEpochServer";
_baseDynamicSimulationSystem = [_serverSettingsConfig, "baseDynamicSimulationSystem", true] call EPOCH_fnc_returnConfigEntry;
_UseIndestructible = [_serverSettingsConfig, "UseIndestructible", false] call EPOCH_fnc_returnConfigEntry;
_IndestructibleBaseObjects = [_serverSettingsConfig, "IndestructibleBaseObjects", []] call EPOCH_fnc_returnConfigEntry;
_ExceptedBaseObjects = [_serverSettingsConfig, "ExceptedBaseObjects", []] call EPOCH_fnc_returnConfigEntry;
_UseDeSimulateObjects = [_serverSettingsConfig, "UseDeSimulateObjects", true] call EPOCH_fnc_returnConfigEntry;
_DeSimulateObjects = [_serverSettingsConfig, "DeSimulateObjects", []] call EPOCH_fnc_returnConfigEntry;
_ExceptedDeSymObjects = [_serverSettingsConfig, "ExceptedDeSymObjects", []] call EPOCH_fnc_returnConfigEntry;
_DisableDoorsOnObj = [_serverSettingsConfig, "DisableDoorsOnObj", []] call EPOCH_fnc_returnConfigEntry;
_cfgBaseBuilding = 'CfgBaseBuilding' call EPOCH_returnConfig;

_VAL = ["", [], "", "", 0, []];

for "_i" from 0 to _this do {
	_vehHiveKey = format ["%1:%2", (call EPOCH_fn_InstanceID),_i];
	_response = ["Building", _vehHiveKey] call EPOCH_fnc_server_hiveGETTTL;
	_Simulated = true;
	_DamageAllowed = true;

	if ((_response select 0) == 1 && (_response select 1) isEqualType [] && !((_response select 1) isEqualTo [])) then {
		_arr = _response select 1;
		_ttl = _response select 2;

		// DEBUG to see if this command works
		if !(_arr isEqualTypeParams _VAL) then {
			diag_log format["DEBUG: Data does not match schema: %1 vs %2",_arr,_VAL];
		};

		_arrCount = count _arr;

		_class = _arr select 0;
		_worldspace = _arr select 1;

		_storageSlot = "-1";
		if (_arrCount >= 3) then {
			if ((_arr select 2) isEqualType 0) then {
				_storageSlot = str(_arr select 2);
			} else {
				_storageSlot = _arr select 2;
			};
			// diag_log format ["DEBUG _class: %1 _worldspace: %2 _storageSlot: %3", _class, _worldspace, _storageSlot];
		};

		_owner = "-1";
		if (_arrCount >= 4) then {
			_owner = _arr select 3;
		};

		// load texture index
		_textureSlot = 0;
		if (_arrCount >= 5) then {
			_textureSlot = _arr select 4;
		};

		// experiment with damage factor based on time only for now.
		_damage = ((1 - (_ttl / _maxTTL)) min 1) max 0;

		_location = _worldspace deleteAt 0;

		// increased position precision
		if (count _location == 2) then{
			_location = (_location select 0) vectorAdd (_location select 1);
		};

		// remove old safes on && !(_class isKindOf 'Constructions_lockedstatic_F')
		if (isClass (configFile >> "CfgVehicles" >> _class) && (_damage < 1) && !(_class isKindOf 'Constructions_lockedstatic_F')) then {

			_baseObj = createVehicle [_class, [0,0,0], [], 0, "CAN_COLLIDE"];
			{
				_x params ["_ClassX",["_VarsX",[]]];
				if ((tolower _class) isequalto (tolower _ClassX)) exitwith {
					{
						_x params ["_VarNameX","_ValueX"];
						_baseObj setvariable [_VarNameX,_ValueX,true];
					} foreach _VarsX;
				};
			} foreach _DisableDoorsOnObj;
			if (_UseIndestructible) then {
				if ({_class iskindof _x} count _ExceptedBaseObjects == 0) then {
					{
						if (_class iskindof _x) exitwith {
							_baseObj allowdamage false;
							_DamageAllowed = false;
						};
					} foreach _IndestructibleBaseObjects;
				};
			};
			if (_UseDeSimulateObjects) then {
				if ({_class iskindof _x} count _ExceptedDeSymObjects == 0) then {
					{
						if (_class iskindof _x) exitwith {
							_baseObj enablesimulationglobal false;
							_Simulated = false;
						};
					} foreach _DeSimulateObjects;
				};
			};
			_baseObj setposATL _location;
			_baseObj setVectorDirAndUp _worldspace;

			if (_Simulated && _baseDynamicSimulationSystem) then {		// Only needed, if simulation is not disabled
				// new Dynamicsimulation
				_baseObj enableSimulationGlobal false; // turn off sim on server start, let dynSim activate it to true
				_baseObj enableDynamicSimulation true;
				_baseObj triggerDynamicSimulation false; // this object doesnt need to turn anything on in the server
			};

			// spawn additional object for trap
			_ammoClass = (_cfgBaseBuilding >> _class >> "ammoClass");
			if(isText _ammoClass) then {
				_ammoClass = getText _ammoClass;
				_ammoObj = createVehicle [_ammoClass, [0,0,0], [], 0, "CAN_COLLIDE"];
				_ammoObj setVectorDirAndUp _worldspace;
				_ammoObj setposATL _location;
				_baseObj setVariable ["EPOCH_TRAP_OBJ",_ammoObj];
				_baseObj addEventHandler ["Explosion", {(_this select 0) setDamage 1}];
			};

			// set persistent Animations
			if (_arrCount >= 6) then {
				_anims = [];
				_animsData = _arr select 5;
				// check that we have an array to prevent any errors
				if (_animsData isEqualType _anims) then {
					_anims = _animsData;
				};

				{
					_baseObj animate [_x, _anims param [_forEachIndex,0], true]
				} foreach(getArray(_cfgBaseBuilding >> _class >> "persistAnimations"));
			};

			// Handle Jammers and create marker if EPOCH_SHOW_JAMMERS set true.
			if (_class in ((call EPOCH_JammerClasses) + ["BaseCam_EPOCH"])) then {
				if (_owner != "-1") then {
					_baseObj setVariable ["BUILD_OWNER", _owner, true];
				};

				// add BaseCam to public array
				if (_class isequalto "BaseCam_EPOCH") then {
					EPOCH_BaseCams pushBackUnique _baseObj;
					// Set PubVar later after all Cams are loaded in
				};

				if (_class in (call EPOCH_JammerClasses)) then {
					EPOCH_Plotpoles pushbackunique _baseObj;
					if (EPOCH_SHOW_JAMMERS) then {
						_marker = createMarker [str(_location), _location];
						_marker setMarkerShape "ICON";
						// TODO allow players to change this per base
						_marker setMarkerType "mil_dot";
						// _marker setMarkerText _class;
						_marker setMarkerColor "ColorBlue";
					};
				};
			};

			_baseObj setDamage _damage;
			if (_DamageAllowed) then {		// Only needed, if damage is allowed
				_baseObj call EPOCH_server_buildingInit;
			};
			_baseObj setVariable ["BUILD_SLOT", _i, true];

			if (_textureSlot != 0) then {
				// get texture path from index
				_color = getArray (_cfgBaseBuilding >> _class >> "availableTextures");
				if !(_color isEqualTo []) then {
					_baseObj setObjectTextureGlobal [0, (_color select _textureSlot)];
					_baseObj setVariable ["TEXTURE_SLOT", _textureSlot, true];
				};
			};

			EPOCH_BuildingSlots set [_i,1];
			if (EPOCH_DEBUG_VEH) then {
				_marker = createMarker [str(_location) , _location];
				_marker setMarkerShape "ICON";
				_marker setMarkerType "mil_dot";
				_marker setMarkerText _class;
				_marker setMarkerColor "ColorRed";
			};
		} else { //Need Hivecall to delete the object out of the DB!
			EPOCH_BuildingSlots set [_i,0];
		};
	}
	else {
		EPOCH_BuildingSlots set [_i,0];
	};
};
publicvariable "EPOCH_BaseCams";
publicvariable "EPOCH_Plotpoles";
missionNamespace setVariable ["EPOCH_BuildingSlotCount", {_x == 0} count EPOCH_BuildingSlots, true];
true
