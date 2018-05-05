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
private ["_Primary","_CheckLocation","_allGroupMembers","_alreadyDead","_assignedItems","_attachments","_backpack","_backpackItems","_canBeRevived","_class","_communityStats","_communityStatsArray","_currentWeapon","_deadPlayer","_defaultData","_dir","_equipped","_found","_goggles","_group","_handgunWeapon","_headgear","_instanceID","_jammer","_jammers","_linkedItems","_loadout","_location","_newLocation","_newPlyr","_playerData","_playerGroup","_playerGroupArray","_playerNetID","_playerUID","_primaryWeapon","_reject","_secondaryWeapon","_serverSettingsConfig","_type","_uniform","_uniformItems","_vars","_vest","_vestItems","_wMags","_wMagsArray","_weapon"];
//[[[end]]]
_reject = true;

params [["_player",objNull,[objNull]],["_isMale",true],["_fsmHandle",0],["_playerData",[]]];

if (!isNull _player) then {

	// load server settings
	_serverSettingsConfig = configFile >> "CfgEpochServer";
	_instanceID = call EPOCH_fn_InstanceID;

	_playerNetID = owner _player;
	_playerUID = getPlayerUID _player;

	if (_playerUID != "") then {

		if (_playerdata isequalto []) then {
			// Make Hive call
			(["Player", _playerUID] call EPOCH_fnc_server_hiveGETRANGE) params [
				["_status", 0 ],
				["_playerDataTmp", [] ]
			];
			if (_status == 1 && _playerDataTmp isEqualType []) then {
				_playerData = _playerDataTmp;
			};
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
		_primaryWeapon = [_serverSettingsConfig, "defaultprimaryWeapon", []] call EPOCH_fnc_returnConfigEntry;	// ["arifle_MX_pointer_F","","acc_pointer_IR","",["30Rnd_65x39_caseless_mag",29],[],""];
		_secondaryWeapon = [_serverSettingsConfig, "defaultsecondaryWeapon", []] call EPOCH_fnc_returnConfigEntry;  // ["launch_NLAW_F","","","",["NLAW_F",1],[],""];
		_handgunWeapon = [_serverSettingsConfig, "defaulthandgunWeapon", []] call EPOCH_fnc_returnConfigEntry;	// ["hgun_P07_F","","","",["16Rnd_9x21_Mag",16],[],""];
		_uniformItems = [_serverSettingsConfig, "defaultuniformItems", []] call EPOCH_fnc_returnConfigEntry;	 // [["FAK",1],["30Rnd_65x39_caseless_mag",2,30],["Chemlight_green",1,1]];
		_vestItems = [_serverSettingsConfig, "defaultvestItems", []] call EPOCH_fnc_returnConfigEntry;		// [["30Rnd_65x39_caseless_mag",3,30],["16Rnd_9x21_Mag",2,16],["SmokeShell",1,1],["SmokeShellGreen",1,1],["SmokeShellBlue",1,1],["SmokeShellOrange",1,1],["Chemlight_green",1,1]];
		_backpackItems = [_serverSettingsConfig, "defaultbackpackItems", []] call EPOCH_fnc_returnConfigEntry;	// [["Medikit",1],["FAK",10],[["hgun_P07_F","","","",["16Rnd_9x21_Mag",16],[],""],1]];
		_assignedItems = [_serverSettingsConfig, "defaultassignedItems", ["","","","",[],[],""]] call EPOCH_fnc_returnConfigEntry; // ["Rangefinder","","","",[],[],""]
		_linkedItems = [_serverSettingsConfig, "defaultlinkedItems", ["ItemMap","","EpochRadio0","","",""]] call EPOCH_fnc_returnConfigEntry; // ["ItemMap","ItemGPS","ItemRadio","ItemCompass","ItemWatch","NVGoggles"]
		_currentWeapon = [_serverSettingsConfig, "defaultSelectedWeapon", ""] call EPOCH_fnc_returnConfigEntry; // class of selected weapon

		_loadout = [
			_primaryWeapon,
			_secondaryWeapon,
			_handgunWeapon,
			[_uniform,_uniformItems],
			[_vest,_vestItems],
			[_backpack,_backpackItems],
			_headgear,
			_goggles,
			_assignedItems,
			_linkedItems
		];

		// default data, if "Player" data format is changed update this array!
		_defaultData = [[0, [], _instanceID, 1.0], [0, 0, 1, 0, [0,0,0,0,0,0,0,0,0,0,0]], ["", "", "", "", _currentWeapon, _class], [], call EPOCH_defaultVars_SEPXVar, _loadout, [], [], [], [], "", true];

		// If data does not validate against default or is too short, override with default data.
		if !(_playerData isEqualTypeParams _defaultData) then {
			diag_log format["DEBUG: Invaild player data %1, defaults used instead.", _playerData];
			_playerData = _defaultData;
		};

		_playerData params ["_worldspace","_medical","","_server_vars","_vars","","","","","","_playerGroup","_canBeRevived"];

		// Load world space and previous instance id
		_worldspace params ["_dir","_location","_prevInstance",["_schemaVersion",0.5]];

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

		_medical params ["_bleedingRemaining","_fatigue","_oxygenRemaining","_damage",["_hitpoints",[0,0,0,0,0,0,0,0,0,0,0]] ];

		_deadPlayer = ["PlayerStats", _playerUID, 0] call EPOCH_fnc_server_hiveGETBIT;

		// check if player is already dead or was critically hit HitHead = 2 or HitBody = 7 and if blood pressure too high.
		_alreadyDead = (_deadPlayer || (_damage == 1) || (_hitpoints select 2 == 1) || (_hitpoints select 7 == 1) || (_vars select 12 >= 180));

		if (_alreadyDead || _prevInstance != _instanceID || (count _location) < 3 || !(_location isEqualType [])) then {
			// reset hitpoints
			_hitpoints = [0,0,0,0,0,0,0,0,0,0,0];
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

		_newPlyr = _group createUnit[_class, getMarkerPos "respawn_west", [], 0, "CAN_COLLIDE"];
		_newPlyr hideobjectglobal true;
		if !(isNull _newPlyr) then {

			// disable AI on temp unit
			_newPlyr disableAI "ALL";

			if (!_alreadyDead) then {
				// Medical
				_newPlyr setBleedingRemaining _bleedingRemaining;
				// _newPlyr setFatigue _fatigue;
				_newPlyr setOxygenRemaining _oxygenRemaining;
				_newPlyr setDamage _damage;
			} else {
				// player dead use default Data for appearance and loadout data
				_playerData = _defaultData;
			};

			// disable further damage server side
			_newPlyr allowDamage false;

			// set player loadout
			_playerData params ["","","_appearance","","","_loadout"];
			// get current weapon to send to param for selectWeapon
			_currentWeapon = _appearance param [4,""];
//				_newPlyr setUnitLoadout [_loadout, false];

			// Workaround for Client / Server synchronizing issue in SetUnitLoadout
			[_newPlyr,_loadout] call Epoch_server_SetUnitLoadout;
			_loadabs = loadabs _newPlyr;

			// Final Push
			if (isNull _player) then {
				deleteVehicle _newPlyr;
				diag_log "Epoch: DEBUG: _player object was null reject connection";
			} else {

				// add to cleanup
				addToRemainsCollector[_newPlyr];

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

				// load community stats
				_communityStatsArray = ["CommunityStats", _playerUID] call EPOCH_fnc_server_hiveGETRANGE;
				_communityStats = (_communityStatsArray param [1,[]]) param [0,[]];
				_newPlyr setVariable["COMMUNITY_STATS", _communityStats];

				// Flag new body as ready for use.
				_newPlyr setVariable["FinalDest", [_location,_dir], true];

				// Send message to player so they can take over the new body.
				[_playerNetID, _playerUID, [_newPlyr, _vars, _currentWeapon, _loadabs, _playerGroup, _canBeRevived, _newPlyr call EPOCH_server_setPToken,_playerGroupArray, _communityStats, _hitpoints], _fsmHandle, _player] call EPOCH_server_pushPlayer;

				// revive test
				_newPlyr setVariable ['#rev_enabled', true, true];
				// [] remoteExec ["bis_fnc_reviveInit",_player];

				// new Dynamicsimulation
				if([configFile >> "CfgEpochServer", "playerDynamicSimulationSystem", true] call EPOCH_fnc_returnConfigEntry)then
				{
					_newPlyr enableDynamicSimulation true;
					_newPlyr triggerDynamicSimulation true;
				};
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
