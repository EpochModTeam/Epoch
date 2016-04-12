/*
	Author: Aaron Clark - EpochMod.com

    Contributors:

	Description:
	Player Login

    Licence:
    Arma Public License Share Alike (APL-SA) - https://www.bistudio.com/community/licenses/arma-public-license-share-alike

    Github:
    https://github.com/EpochModTeam/Epoch/tree/master/Sources/epoch_server/compile/epoch_player/EPOCH_server_loadPlayer.sqf
*/

private ["_arr","_uniform","_class","_vest","_vars","_canBeRevived","_dir","_location","_group","_apperance","_goggles","_headgear","_backpack","_weaponsAndItems","_linkedItems","_normalMagazines","_itemsInContainers","_weaponsInContainers","_wMags","_wMagsArray","_equipped","_weapon","_type","_attachments","_currWeap","_found","_playerGroupArray","_playerGroup","_response","_reject","_fnc_addItemToX","_worldspace","_prevInstance","_medical","_server_vars","_hitpoints","_deadPlayer","_alreadyDead","_newPlyr","_playerUID","_serverSettingsConfig","_player","_instanceID","_playerNetID"];
_reject = true;
_playerGroupArray = [];
_fnc_addItemToX = {
	private ["_itemSlot","_itemqtys","_newPlyr"];
	_newPlyr = _this select 0;
	{
		_itemSlot = _forEachIndex;
		_itemqtys = _x select 1;
		{
			for "_i" from 1 to (_itemqtys select _forEachIndex) do {
				switch _itemSlot do {
					case 0: { _newPlyr addItemToUniform _x };
					case 1: { _newPlyr addItemToVest _x };
					case 2: { _newPlyr addItemToBackpack _x };
				};
			};
		} forEach(_x select 0);
	} forEach (_this select 1);
};

if (_this isEqualType []) then {

	// load server settings
	_serverSettingsConfig = configFile >> "CfgEpochServer";

	_player = _this select 0;

	_instanceID = call EPOCH_fn_InstanceID;

	_playerNetID = owner _player;
	if (!isNull _player) then {

		_playerUID = getPlayerUID _player;
		if (_playerUID != "") then {

			// Make Hive call
			_response = ["Player", _playerUID] call EPOCH_fnc_server_hiveGETRANGE;
			_arr = [];
			if ((_response select 0) == 1 && (_response select 1) isEqualType []) then {
				_arr = (_response select 1);
			};

			// Apperance defaults
			_uniform = [_serverSettingsConfig, "defaultUniformFemale", "U_Test_uniform"] call EPOCH_fnc_returnConfigEntry;
			_class = "Epoch_Female_F";
			_vest = [_serverSettingsConfig, "defaultVestFemale", "V_F41_EPOCH"] call EPOCH_fnc_returnConfigEntry;
			if (_this select 1) then { //true == male
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
			_weaponsAndItems = [_serverSettingsConfig, "weaponsAndItems", ["", []]] call EPOCH_fnc_returnConfigEntry;



			if (count _arr < 11) then { // invaild format attempt to override
				_arr = [[0, [], _instanceID], [0, 0, 1, 0, []], [_goggles, _headgear, _vest, _backpack, _uniform, _class], [""], call EPOCH_defaultVars_SEPXVar, _weaponsAndItems, _linkedItems, _normalMagazines, _itemsInContainers, _weaponsInContainers, "", true];
			};

			_worldspace = _arr select 0;
			_dir = _worldspace select 0;
			_location = _worldspace select 1;

			diag_log format["DEBUG: _worldspace %1",_worldspace];

			if (count _location == 2) then{
				_location = (_location select 0) vectorAdd (_location select 1);
			};

			diag_log format["DEBUG: _location %1",_location];

			_prevInstance = _worldspace select 2;
			_medical = _arr select 1;
			_server_vars = _arr select 3;
			_vars = _arr select 4;

			_playerGroup = _arr select 10;
			_canBeRevived = _arr select 11;

			_hitpoints = _vars select 11;

			_deadPlayer = ["PlayerStats", _playerUID, 0] call EPOCH_fnc_server_hiveGETBIT;
			_alreadyDead = (_deadPlayer || (_medical select 3 == 1) || (_hitpoints select 2 == 1) || (_hitpoints select 3 == 1) || (_vars select 12 >= 180));

			if (_alreadyDead || _prevInstance != _instanceID || (count _location) < 3 || !(_location isEqualType [])) then {
				_dir = random 360;
				_location = getMarkerPos "respawn_west";
				_location set[2, 0];
				if (_alreadyDead) then {
					_vars = call EPOCH_defaultVars_SEPXVar;
					_canBeRevived = true;
				};
			};

			_group = grpNull;

			// Delete any left over units with same PUID
			{
				if ((_x getVariable["PUID", "0"]) == _playerUID) then {
					deleteVehicle _x;
				};
			} forEach allUnits;

			// find existing group
			if (_playerGroup != "") then {
				{
					if ((_x getVariable["GROUP", ""]) == _playerGroup) exitWith{
						_group = group _x;
					};
				} forEach playableUnits;
			};

			if (isNull _group) then {
				_group = createGroup west;
			};

			_player setPosATL _location;

			_newPlyr = _group createUnit[_class, _location, [], 0, "CAN_COLLIDE"];
			diag_log format["DEBUG: _newPlyr %1 %2 %3",_newPlyr, _location, getPosATL _newPlyr];

			if !(isNull _newPlyr) then {

				addToRemainsCollector[_newPlyr];

				{
					_newPlyr disableAI _x;
				} forEach["FSM", "MOVE", "AUTOTARGET", "TARGET"];

				_newPlyr setDir _dir;
				_newPlyr setPosATL _location;

				_currWeap = "";

				if (!_alreadyDead) then {
					// Medical
					_newPlyr setBleedingRemaining(_medical select 0);
					// _newPlyr setFatigue (_medical select 1);
					_newPlyr setOxygenRemaining(_medical select 2);
					_newPlyr setDamage(_medical select 3);

					// Apperance
					_apperance = _arr select 2;
					_goggles = _apperance select 0;
					_headgear = _apperance select 1;
					_vest = _apperance select 2;
					_backpack = _apperance select 3;
					_uniform = _apperance select 4;

					// Weapons
					_weaponsAndItems = _arr select 5;
					_linkedItems = _arr select 6;
					_normalMagazines = _arr select 7;
					_itemsInContainers = _arr select 8;
					_weaponsInContainers = _arr select 9;
				};

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

				// Load inventory + defaults START
				if (count _weaponsAndItems >= 2) then {
					_equipped = _weaponsAndItems select 2;
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
								_wMagsArray = _x;
							} else {
								// attachments
								if (_x != "") then{
									_attachments pushBack _x;
								};
							};
						} forEach _x;
						// add weapon if equiped
						if (_weapon in _equipped) then {
							_equipped = _equipped - [_weapon];
							if (_wMags) then {
								_newPlyr addMagazine _wMagsArray;
							};
							if (_weapon != "") then {
								_newPlyr addWeapon _weapon;
							};
							switch _type do {
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
						} else {
							// overflow need to add these items to storage
							{
								_newPlyr addItem _x;
							} forEach _attachments;
							if (_wMags) then {
								_newPlyr addMagazine _wMagsArray;
							};
						};
					} forEach(_weaponsAndItems select 1);
					_currWeap = _weaponsAndItems select 0;
				};
				// Linked items
				{
					if (_x in["Binocular", "Rangefinder"]) then {
						_newPlyr addWeapon _x;
					} else {
						_newPlyr linkItem _x;
					};
				} forEach _linkedItems;

				// add items to containers
				[_newPlyr, _itemsInContainers] call _fnc_addItemToX;

				// add weapons to containers
				[_newPlyr, _weaponsInContainers] call _fnc_addItemToX;

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
						_response = ["Group", _playerGroup] call EPOCH_fnc_server_hiveGETRANGE;
						_found = false;
						if ((_response select 0) == 1 && (_response select 1) isEqualType [] && !((_response select 1) isEqualTo[])) then {
							_playerGroupArray = _response select 1;
							_found = _playerGroup == _playerUID;
							if (!_found) then {
									{
										if (_x select 0 == _playerUID) exitWith{
											_found = true;
										};
									}forEach(_playerGroupArray select 4);
							};
							if (!_found) then {
									{
										if (_x select 0 == _playerUID) exitWith{
											_found = true;
										};
									}forEach(_playerGroupArray select 3);
							};
							if (_found) then {
								_newPlyr setVariable["GROUP", _playerGroup];
							};
						};
						if (!_found) then {
							_playerGroup = "";
						};
						diag_log format["DEBUG (Load Player) Set Group: %1", _playerGroup];
					};


					_newPlyr setVariable["PUID", _playerUID];

					if !(_vars isEqualTo[]) then {
						_newPlyr setVariable["VARS", _vars];
					};

					if !(_server_vars isEqualTo[]) then{
						_newPlyr setVariable["SERVER_VARS", _server_vars];
					};

					if (!_canBeRevived) then {
						_newPlyr setVariable["REVIVE", _canBeRevived]
					};

					[_playerNetID, _playerUID, [_newPlyr, _vars, _currWeap, loadAbs _newPlyr, _playerGroup, _canBeRevived, _newPlyr call EPOCH_server_setPToken,_playerGroupArray]] call EPOCH_server_pushPlayer;

					_newPlyr setVariable["SETUP", true, true];

					diag_log format["DEBUG: _newPlyr SETUP %1",_newPlyr];
				};
			} else {
				diag_log format["LOGIN FAILED UNIT NULL: %1 [%2|%3]", _player, _group, count allgroups];
			};
		};
	};
};

if (_reject) then {
	diag_log format ["DEBUG PLAYER NOT SETUP OR INVAILD: %1", _player];
	true remoteExec ['EPOCH_client_rejectPlayer',_player];
};

true
