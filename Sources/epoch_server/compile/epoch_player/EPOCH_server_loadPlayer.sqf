/*
	Player Login

	Epoch Mod - EpochMod.com
	All Rights Reserved.
*/
private["_reject", "_plyr", "_instanceID", "_plyrNetID", "_plyrUID", "_response", "_arr", "_defaultUniform", "_class", "_vest", "_medical", "_alreadyDead", "_worldspace", "_dir", "_location", "_prevInstance", "_plyrGroup", "_canBeRevived", "_vars", "_hitpoints", "_group", "_newPlyr", "_currWeap", "_apperance", "_goggles", "_headgear", "_backpack", "_uniform", "_weaponsAndItems", "_equipped", "_weapon", "_type", "_attachments", "_attachment", "_wMags", "_itemSlot", "_itemqtys", "_found", "_contentArray", "_deadPlayer"];

_reject = true;

if (typename _this == "ARRAY") then {

	_plyr = _this select 0;

	_instanceID = call EPOCH_fn_InstanceID;

	_plyrNetID = owner _plyr;
	if (!isNull _plyr) then {

		_plyrUID = getPlayerUID _plyr;
		if (_plyrUID != "") then {

			// Make Hive call
			_response = ["Player", _plyrUID] call EPOCH_fnc_server_hiveGETRANGE;
			_arr = [];
			if ((_response select 0) == 1 && typeName(_response select 1) == "ARRAY") then {
				_arr = (_response select 1);
			};
			_defaultUniform = "U_Test_uniform";
			_class = "Epoch_Female_F";
			_vest = "V_F41_EPOCH";
			if (_this select 1) then { //true == male
				_defaultUniform = "U_Test1_uniform";
				_class = "Epoch_Male_F";
				_vest = "V_41_EPOCH";
			};

			if (count _arr < 11) then { // invaild format attempt to override
				_arr = [[0, [], _instanceID], [0, 0, 1, 0, []], ["", "", _vest, "", _defaultUniform, _class], [""], [] + EPOCH_defaultVars_SEPXVar, ["", []], ["ItemMap"], [], [], [], "", true];
			};

			_worldspace = _arr select 0;
			_dir = _worldspace select 0;
			_location = _worldspace select 1;
			_prevInstance = _worldspace select 2;

			_medical = _arr select 1;

			_plyrGroup = _arr select 10;
			_canBeRevived = _arr select 11;
			
			_server_vars = _arr select 3;
			_vars = _arr select 4;

			_hitpoints = _vars select 11;

			_deadPlayer = ["PlayerStats", _plyrUID, 0] call EPOCH_fnc_server_hiveGETBIT;
			_alreadyDead = (_deadPlayer || (_medical select 3 == 1) || (_hitpoints select 2 == 1) || (_hitpoints select 3 == 1) || (_vars select 12 >= 180));

			if (_alreadyDead || _prevInstance != _instanceID || (count _location) < 3 || typeName _location != "ARRAY") then {
				_dir = random 360;
				_location = getMarkerPos "respawn_west";
				_location set[2, 0];
				if (_alreadyDead) then {
					_vars = [] + EPOCH_defaultVars_SEPXVar;
					_canBeRevived = true;
				};
			};

			_group = grpNull;

			// Delete any left over units with same PUID
			{
				if ((_x getVariable["PUID", "0"]) == _plyrUID) then {
					deleteVehicle _x;
				};
			} forEach allUnits;

			if (_plyrGroup != "") then {
					{
						if ((_x getVariable["GROUP", ""]) == _plyrGroup) exitWith{
							_group = group _x;
						};
					} forEach playableUnits;
			};

			if (isNull _group) then {
				_group = createGroup west;
			};

			_newPlyr = _group createUnit[_class, _location, [], 0, "CAN_COLLIDE"];

			if !(isNull _newPlyr) then {

				//diag_log format ["DEBUG Created New Player: %1", _newPlyr];
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

					// Weapons
					_weaponsAndItems = _arr select 5;
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
							} 
							else { // overflow need to add these items to storage
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
						}
						else {
							_newPlyr linkItem _x;
						};
					} forEach(_arr select 6);

					// add items to containers
					{
						_itemSlot = _forEachIndex;
						_itemqtys = _x select 1;
						{
							for "_i" from 1 to(_itemqtys select _forEachIndex) do {
								switch _itemSlot do {
								case 0: { _newPlyr addItemToUniform _x };
								case 1: { _newPlyr addItemToVest _x };
								case 2: { _newPlyr addItemToBackpack _x };
								};
							};
						} forEach(_x select 0);
					} forEach(_arr select 8);

					// add weapons to containers
					{
						_itemSlot = _forEachIndex;
						_itemqtys = _x select 1;
						{
							for "_i" from 1 to(_itemqtys select _forEachIndex) do {
								switch _itemSlot do {
								case 0: { _newPlyr addItemToUniform _x };
								case 1: { _newPlyr addItemToVest _x };
								case 2: { _newPlyr addItemToBackpack _x };
								};
							};
						} forEach(_x select 0);
					} forEach(_arr select 9);

					// Add magazines
					{
						_newPlyr addMagazine _x;
					} forEach(_arr select 7);
				};

				// Final Push
				if (isNull _plyr) then {
					deleteVehicle _newPlyr;
					diag_log "DEBUG: _plyr object was null reject connection";
				} else {

					_reject = false;

					if (_plyrGroup != "") then {
						_response = ["Group", _plyrGroup] call EPOCH_fnc_server_hiveGETRANGE;
						diag_log format["DEBUG (Load Player) Group Content: %1", _response];
						_found = false;
						if ((_response select 0) == 1 && typeName(_response select 1) == "ARRAY" && !((_response select 1) isEqualTo[])) then {
							_contentArray = _response select 1;
							_found = _plyrGroup == _plyrUID;
							if (!_found) then {
									{
										if (_x select 0 == _plyrUID) exitWith{
											_found = true;
										};
									}forEach(_contentArray select 4);
							};
							if (!_found) then {
									{
										if (_x select 0 == _plyrUID) exitWith{
											_found = true;
										};
									}forEach(_contentArray select 3);
							};
							if (_found) then {
								Epoch_my_Group = _contentArray;
								_plyrNetID publicVariableClient "Epoch_my_Group";
								_newPlyr setVariable["GROUP", _plyrGroup];
							};
						};

						if (!_found) then {
							_plyrGroup = "";
						};
						diag_log format["DEBUG (Load Player) Set Group: %1", _plyrGroup];
					};
					
					// may not be needed, just here to see if we can force the data to sync quicker
					// _plyr setPosATL _location;

					_newPlyr setVariable["SETUP", true];
					_newPlyr setVariable["PUID", _plyrUID];


					if !(_vars isEqualTo[]) then {
						_newPlyr setVariable["VARS", _vars];
					};

					if !(_server_vars isEqualTo[]) then{
						_newPlyr setVariable["SERVER_VARS", _server_vars];
					};

					if (!_canBeRevived) then {
						_newPlyr setVariable["REVIVE", _canBeRevived]
					};
					[_plyrNetID, _plyrUID, [_newPlyr, _vars, _currWeap, count(magazines _newPlyr), _plyrGroup, _canBeRevived, _newPlyr call EPOCH_server_setPToken]] call EPOCH_server_pushPlayer;
				};
			} else {
				diag_log format["LOGIN FAILED UNIT NULL: %1 [%2|%3]", _plyr, _group, count allgroups];
			};
		};
	};
};

if (_reject) then {
	diag_log format ["DEBUG PLAYER NOT SETUP OR INVAILD: %1", _plyr];
	BAD_HIVE = true;
	_plyrNetID publicVariableClient "BAD_HIVE";
};

true
