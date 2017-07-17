/*
	Author: Aaron Clark - EpochMod.com

    Contributors: He-Man

	Description:
	Player Login

    Licence:
    Arma Public License Share Alike (APL-SA) - https://www.bistudio.com/community/licenses/arma-public-license-share-alike

    Github:
    https://github.com/EpochModTeam/Epoch/tree/release/Sources/epoch_server/compile/epoch_player/EPOCH_server_loadPlayer.sqf
*/
//[[[cog import generate_private_arrays ]]]
private ["_CheckLocation","_allGroupMembers","_alreadyDead","_attachments","_backpack","_canBeRevived","_class","_currWeap","_deadPlayer","_defaultData","_dir","_equipped","_found","_goggles","_group","_headgear","_hitpoints","_instanceID","_itemsInContainers","_jammer","_jammers","_linkedItems","_location","_newLocation","_newPlyr","_normalMagazines","_playerData","_playerGroup","_playerGroupArray","_playerNetID","_playerUID","_reject","_serverSettingsConfig","_type","_uniform","_vars","_vest","_wMags","_wMagsArray","_weapon","_weaponsAndItems","_weaponsInContainers"];
//[[[end]]]
_reject = true;

params [["_player",objNull,[objNull]],["_isMale",true]];

if (!isNull _player) then {

    // load server settings
    _serverSettingsConfig = configFile >> "CfgEpochServer";
    _instanceID = call EPOCH_fn_InstanceID;

    _playerNetID = owner _player;
	_playerUID = getPlayerUID _player;

	if (_playerUID != "") then {

		// Make Hive call
		_playerData = [];
        (["Player", _playerUID] call EPOCH_fnc_server_hiveGETRANGE) params [
            ["_status", 0 ],
            ["_playerDataTmp", [] ]
        ];
        if (_status == 1 && _playerDataTmp isEqualType []) then {
            _playerData = _playerDataTmp;
        };

		// Apperance defaults
		_uniform = [_serverSettingsConfig, "defaultUniformFemale", "U_Test_uniform"] call EPOCH_fnc_returnConfigEntry;
		_class = "Epoch_Female_F";
		_vest = [_serverSettingsConfig, "defaultVestFemale", "V_F41_EPOCH"] call EPOCH_fnc_returnConfigEntry;
		if (_isMale) then {
			_uniform = [_serverSettingsConfig, "defaultUniformMale", "U_Test1_uniform"] call EPOCH_fnc_returnConfigEntry;
			_class = "Epoch_Male_F";
			_vest = [_serverSettingsConfig, "defaultVestMale", "V_41_EPOCH"] call EPOCH_fnc_returnConfigEntry;
		};
		_goggles = [_serverSettingsConfig, "defaultGoggles", ""] call EPOCH_fnc_returnConfigEntry;
		_headgear = [_serverSettingsConfig, "defaultHeadgear", ""] call EPOCH_fnc_returnConfigEntry;
		_backpack = [_serverSettingsConfig, "defaultBackpack", ""] call EPOCH_fnc_returnConfigEntry;

		// Inventory defaults
		_linkedItems = [_serverSettingsConfig, "linkedItems", ["ItemMap","EpochRadio0"]] call EPOCH_fnc_returnConfigEntry;
		_itemsInContainers = [_serverSettingsConfig, "itemsInContainers", []] call EPOCH_fnc_returnConfigEntry;
		_weaponsInContainers = [_serverSettingsConfig, "weaponsInContainers", []] call EPOCH_fnc_returnConfigEntry;
		_normalMagazines = [_serverSettingsConfig, "normalMagazines", []] call EPOCH_fnc_returnConfigEntry;
		_weaponsAndItems = [_serverSettingsConfig, "weaponsAndItems", ["", []] ] call EPOCH_fnc_returnConfigEntry;

        // default data
        _defaultData = [[0, [], _instanceID], [0, 0, 1, 0, []], [_goggles, _headgear, _vest, _backpack, _uniform, _class], [], call EPOCH_defaultVars_SEPXVar, _weaponsAndItems, _linkedItems, _normalMagazines, _itemsInContainers, _weaponsInContainers, "", true];

        // todo make dynamic
		if (count _playerData < 11) then { // invaild format attempt to override
			_playerData = _defaultData;
		};

        _playerData params ["_worldspace","_medical","","_server_vars","_vars","","","","","","_playerGroup","_canBeRevived"];

		// Load world space and previous instance id
        _worldspace params ["_dir","_location","_prevInstance"];

		if (count _location == 2) then{
			_location = (_location select 0) vectorAdd (_location select 1);
		};

        // Get player group
        _playerGroupArray = [];
        // check players group
        if (_playerGroup != "") then {
            _found = false;
            (["Group", _playerGroup] call EPOCH_fnc_server_hiveGETRANGE) params [
                ["_status", 0 ],
                ["_playerGroupArrayTmp", [] ]
            ];
            if (_status == 1 && !(_playerGroupArrayTmp isEqualTo[])) then {
                _playerGroupArrayTmp params ["","","","_modArray","_memberArray"];
                _found = _playerGroup == _playerUID;
                if (!_found) then {
                    _allGroupMembers = (_modArray + _memberArray) apply {_x select 0};
                    _found = _playerUID in _allGroupMembers;
                };
                if (_found) then {
                    _playerGroupArray = _playerGroupArrayTmp;
                };
            };
            if (!_found) then {
                _playerGroup = "";
            };
            // diag_log format["DEBUG (Load Player) Set Group: %1", _playerGroup];
        };

		_hitpoints = _vars select 11;

		_deadPlayer = ["PlayerStats", _playerUID, 0] call EPOCH_fnc_server_hiveGETBIT;
		_alreadyDead = (_deadPlayer || (_medical select 3 == 1) || (_hitpoints select 2 == 1) || (_hitpoints select 3 == 1) || (_vars select 12 >= 180));


		if (_alreadyDead || _prevInstance != _instanceID || (count _location) < 3 || !(_location isEqualType [])) then {
			_dir = random 360;
            // try to find respawn point by position
            _newLocation = _server_vars param [0,[]]; // 0 = RESPAWN POS
            // normal respawn location
            _location = getMarkerPos "respawn_west";
            _location set[2, 0];
            if (_newLocation isEqualType [] && {(count _newLocation) == 3}) then {
				_CheckLocation = _newLocation;
				if (surfaceiswater _newLocation) then {
					_CheckLocation = ATLToASL _newLocation;
				};
                _jammers = nearestObjects[_CheckLocation, ["PlotPole_EPOCH"], 6];
                if !(_jammers isEqualTo[]) then {
                    // get nearby object
                    _jammer = _jammers param [0,objNull];
                    // check if object is not null and is alive.
                    if (!isNull _jammer && {alive _jammer}) then {
                        // check if player is still a member of object group.
                        if ((_jammer getVariable["BUILD_OWNER", "-1"]) in [_playerUID, _playerGroup]) then {
                            // Override location with that of object
                            _location = _newLocation;
                        };
                    };
                };
            };
			if (_alreadyDead) then {
				_vars = call EPOCH_defaultVars_SEPXVar;
				_canBeRevived = true;
			};
		};

		_group = grpNull;

		// find existing group
		if (_playerGroup != "") then {
			{
				if ((_x getVariable["GROUP", ""]) == _playerGroup) exitWith{
					_group = group _x;
				};
			} forEach (allPlayers select {alive _x});
		};

		if (isNull _group) then {
			_group = createGroup [west, true];
		};

		_player setPosATL _location;

		_newPlyr = _group createUnit[_class, _location, [], 0, "CAN_COLLIDE"];
		if !(isNull _newPlyr) then {
			addToRemainsCollector[_newPlyr];
			{
				_newPlyr disableAI _x;
			} forEach["FSM", "MOVE", "AUTOTARGET", "TARGET"];

			_newPlyr setDir _dir;
			_newPlyr setPosATL _location;

			if (!_alreadyDead) then {
				// Medical
                _medical params ["_bleedingRemaining","_fatigue","_oxygenRemaining","_damage"];
				_newPlyr setBleedingRemaining _bleedingRemaining;
				// _newPlyr setFatigue _fatigue;
				_newPlyr setOxygenRemaining _oxygenRemaining;
				_newPlyr setDamage _damage;
			} else {
                // player dead use default Data for appearance and loadout data
                _playerData = _defaultData;
            };

            // Apperance + Weapons
            _playerData params ["","","_apperance","","","_weaponsAndItems","_linkedItems","_normalMagazines","_itemsInContainers","_weaponsInContainers"];
            // load Apperance
            _apperance params ["_goggles","_headgear","_vest","_backpack","_uniform"];

			// Load Apperance START
			if (_uniform != "") then {
				_newPlyr addUniform _uniform;
			};
			if (_backpack != "") then {
				_newPlyr addBackpack _backpack;
			};
			if (_goggles != "") then {
				_newPlyr addGoggles _goggles;
			};
			if (_headgear != "") then {
				_newPlyr addHeadgear _headgear;
			};
			if (_vest != "") then {
				_newPlyr addVest _vest;
			};
			// Load Apperance END

            _currWeap = "";
			// Load inventory + defaults START
			if (count _weaponsAndItems >= 3) then {
                _weaponsAndItems params ["_currWeapTmp","_weaponsAndItemsArray","_equipped"];
                _currWeap = _currWeapTmp;
				{
					_weapon = _x deleteAt 0;
					_type = getNumber(configfile >> "cfgweapons" >> _weapon >> "type");
					_attachments = [];
					_wMags = false;
					_wMagsArray = [];
					// suppressor, laser, optics, magazines(array), bipods
					{
						// magazines
						if (_x isEqualType []) then{
							_wMags = true;
							_wMagsArray pushback _x;
						} else {
							// attachments
							if (_x != "") then{
								_attachments pushBack _x;
							};
						};
					} forEach _x;
					if (_wMags) then {
						{
							_newPlyr addMagazine _x;
						} foreach _wMagsArray;
					};
					// add weapon if equiped
					if (_weapon in _equipped) then {
						_equipped = _equipped - [_weapon];
						if (_weapon != "") then {
							_newPlyr addWeapon _weapon;
						};
						switch (_type) do {
							case 1: { // primary
								removeAllPrimaryWeaponItems _newPlyr;
								{ _newPlyr addPrimaryWeaponItem _x } forEach _attachments;
							};
							case 2:	{ // handgun
								removeAllHandgunItems _newPlyr;
								{ _newPlyr addHandgunItem _x } forEach _attachments;
							};
							case 4:	{ // secondary
								// removeAllSecondaryWeaponItems player; does not exist ?
								{
									_newPlyr removeSecondaryWeaponItem _x;
								} forEach (secondaryWeaponItems _newPlyr);
								{ _newPlyr addSecondaryWeaponItem _x } forEach _attachments;
							};
						};
					}else{
						{
							_newPlyr addItem _x;
						} forEach _attachments;
					};
				} forEach _weaponsAndItemsArray;
			};
			// Linked items
			{
				if (_x in["Binocular", "Rangefinder","Laserdesignator","Laserdesignator_02","Laserdesignator_03","Laserdesignator_01_khk_F","Laserdesignator_02_ghex_F"]) then {
					_newPlyr addWeapon _x;
				} else {
					_newPlyr linkItem _x;
				};
			} forEach _linkedItems;

			// add items to containers
			[_newPlyr, _itemsInContainers] call EPOCH_fnc_addItemToX;

			// add weapons to containers
			[_newPlyr, _weaponsInContainers] call EPOCH_fnc_addItemToX;

			// Add magazines
			{_newPlyr addMagazine _x} forEach _normalMagazines;
			// Load inventory + defaults END

			// Final Push
			if (isNull _player) then {
				deleteVehicle _newPlyr;
				diag_log "Epoch: DEBUG: _player object was null reject connection";
			} else {
                _reject = false;

                if (_playerGroup != "") then {
                    _newPlyr setVariable["GROUP", _playerGroup];
                };

				_newPlyr setVariable["PUID", _playerUID];

				if !(_vars isEqualTo[]) then {
					_newPlyr setVariable["VARS", _vars];
				};

				if !(_server_vars isEqualTo[]) then{
					_newPlyr setVariable["SERVER_VARS", _server_vars];
				};

				if (!_canBeRevived) then {
					_newPlyr setVariable["REVIVE", _canBeRevived];
				};

				[_playerNetID, _playerUID, [_newPlyr, _vars, _currWeap, loadAbs _newPlyr, _playerGroup, _canBeRevived, _newPlyr call EPOCH_server_setPToken,_playerGroupArray]] call EPOCH_server_pushPlayer;
                //diag_log format["DEBUG (Load Player) Sent Group: %1 %2", _playerGroup, _playerGroupArray];

				_newPlyr setVariable["SETUP", true, true];

                // revive
                _newPlyr setVariable ['#rev_enabled', true, true];

                // [] remoteExec ["bis_fnc_reviveInit",_player];

                // This is a test to see setUnitLoadout can force propagation of unit loadout.
                _newPlyr setUnitLoadout (getUnitLoadout _newPlyr); // if this works, possibly replace all inventory code with with get|setUnitLoadout

			};
		} else {
			diag_log format["LOGIN FAILED UNIT NULL: %1 [%2|%3]", _player, _group, count allgroups];
		};
	};
};


if (_reject) then {
	diag_log format ["DEBUG PLAYER NOT SETUP OR INVAILD: %1", _player];
	true remoteExec ['EPOCH_client_rejectPlayer',_player];
};

true
