/*
    Load Buildings
    by Aaron Clark - EpochMod.com

    This work is licensed under a Creative Commons Attribution-NonCommercial-NoDerivatives 4.0 International License.
    http://creativecommons.org/licenses/by-nc-nd/4.0/

    Improvements and or bugfixes and other contributions are welcome via the github:
    https://github.com/EpochModTeam/Epoch/tree/master/Sources/epoch_server/compile/epoch_bases/EPOCH_server_loadBuildings.sqf
*/

_maxTTL = parseNumber EPOCH_expiresBuilding;
_config = 'CfgEpochClient' call EPOCH_returnConfig;
_buildingJammerRange = getNumber(_config >> "buildingJammerRange");
if (_buildingJammerRange == 0) then { _buildingJammerRange = 75; };

for "_i" from 0 to _this do {
	_vehHiveKey = format ["%1:%2", (call EPOCH_fn_InstanceID),_i];
	_response = ["Building", _vehHiveKey] call EPOCH_fnc_server_hiveGETTTL;

	if ((_response select 0) == 1 && typeName (_response select 1) == "ARRAY" && !((_response select 1) isEqualTo [])) then {
		_arr = _response select 1;
		_ttl = _response select 2;

		_arrCount = count _arr;

		_class = _arr select 0;
		_worldspace = _arr select 1;

		_storageSlot = "-1";
		if (_arrCount >= 3) then {
			if ((typeName (_arr select 2)) == "SCALAR") then {
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

		if (isClass (configFile >> "CfgVehicles" >> _class) && (_damage < 1)) then {
			_baseObj = createVehicle [_class, _location, [], 0, "CAN_COLLIDE"];

			_baseObj setVectorDirAndUp _worldspace;
			_baseObj setposATL _location;

			if (_arrCount >= 6) then{
				_anims = _arr param[5, [], [[]]];
				{
					_baseObj animate [_x, _anims param [_forEachIndex,0], true]
				} foreach(getArray(configFile >> "CfgVehicles" >> _class >> "persistAnimations"));
			};

			// TODO make config based
			if (_class == "PlotPole_EPOCH") then {
				if (EPOCH_SHOW_JAMMERS) then {
					_marker = createMarker[str(_location), _location];
					_marker setMarkerShape "ICON";
					// TODO allow players to change this per base
					_marker setMarkerType "mil_dot";
					// _marker setMarkerText _class;
					_marker setMarkerColor "ColorBlue";
				};
			};

			if (_class isKindOf 'Constructions_lockedstatic_F') then{
				if ((_location select 2) < 0) then {
					_location set [2, 0];
					_baseObj setposATL _location;
				};

				if (_storageSlot != "-1") then {
					_baseObj setVariable ["EPOCH_secureStorage", _storageSlot];
					_baseObj setVariable ["EPOCH_Locked", true, true];
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
				_color = getArray (configFile >> "CfgVehicles" >> _class >> "availableTextures");
				if !(_color isEqualTo []) then {
					_baseObj setObjectTextureGlobal [0, (_color select _textureSlot)];
					_baseObj setVariable ["TEXTURE_SLOT", _textureSlot, true];
				};
			};

			missionNamespace setVariable [format ["EPOCH_BUILD_%1",_i], _baseObj];

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
EPOCH_BuildingSlotCount = {_x == 0} count EPOCH_BuildingSlots;
publicVariable "EPOCH_BuildingSlotCount";
true
