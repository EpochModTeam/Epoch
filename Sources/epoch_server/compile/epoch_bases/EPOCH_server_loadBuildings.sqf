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
private ["_ExceptedBaseObjects","_IndestructibleBaseObjects","_UseIndestructible","_VAL","_ammoClass","_ammoObj","_anims","_animsData","_arr","_arrCount","_baseObj","_buildingJammerRange","_cfgBaseBuilding","_cfgEpochClient","_class","_color","_damage","_location","_marker","_maxTTL","_owner","_response","_serverSettingsConfig","_storageSlot","_textureSlot","_ttl","_vehHiveKey","_worldspace"];
//[[[end]]]
_maxTTL = parseNumber EPOCH_expiresBuilding;
_serverSettingsConfig = configFile >> "CfgEpochServer";
_UseIndestructible = [_serverSettingsConfig, "UseIndestructible", false] call EPOCH_fnc_returnConfigEntry;
_IndestructibleBaseObjects = [_serverSettingsConfig, "IndestructibleBaseObjects", []] call EPOCH_fnc_returnConfigEntry;
_ExceptedBaseObjects = [_serverSettingsConfig, "ExceptedBaseObjects", []] call EPOCH_fnc_returnConfigEntry;
_cfgEpochClient = 'CfgEpochClient' call EPOCH_returnConfig;
_cfgBaseBuilding = 'CfgBaseBuilding' call EPOCH_returnConfig;
_buildingJammerRange = getNumber(_cfgEpochClient >> "buildingJammerRange");
if (_buildingJammerRange == 0) then { _buildingJammerRange = 75; };

_VAL = ["", [], "", "", 0, []];

for "_i" from 0 to _this do {
	_vehHiveKey = format ["%1:%2", (call EPOCH_fn_InstanceID),_i];
	_response = ["Building", _vehHiveKey] call EPOCH_fnc_server_hiveGETTTL;

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
			if (_UseIndestructible) then {
				if ({_baseObj iskindof _x} count _ExceptedBaseObjects == 0) then {
					{
						if (_baseObj iskindof _x) exitwith {
							_baseObj allowdamage false;
						};
					} foreach _IndestructibleBaseObjects;
				};
			};
			_baseObj setVectorDirAndUp _worldspace;
			_baseObj setposATL _location;


			// spawn additional object for trap
			_ammoClass = (_cfgBaseBuilding >> _class >> "ammoClass");
			if(isText _ammoClass) then {
				_ammoClass = getText _ammoClass;
				_ammoObj = createVehicle [_ammoClass, [0,0,0], [], 0, "CAN_COLLIDE"];
				_ammoObj setVectorDirAndUp _worldspace;
				_ammoObj setposATL _location;
				_baseObj setVariable ["EPOCH_TRAP_OBJ",_ammoObj];
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
			if (_class isKindOf "PlotPole_EPOCH") then {
				if (EPOCH_SHOW_JAMMERS) then {
					_marker = createMarker [str(_location), _location];
					_marker setMarkerShape "ICON";
					// TODO allow players to change this per base
					_marker setMarkerType "mil_dot";
					// _marker setMarkerText _class;
					_marker setMarkerColor "ColorBlue";
				};
			};

			_baseObj setDamage _damage;
			_baseObj call EPOCH_server_buildingInit;
			_baseObj setVariable ["BUILD_SLOT", _i, true];

			if (_owner != "-1") then {
				_baseObj setVariable ["BUILD_OWNER", _owner, true];
			};

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
missionNamespace setVariable ["EPOCH_BuildingSlotCount", {_x == 0} count EPOCH_BuildingSlots, true];
true
