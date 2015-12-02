/*
Player Revive

Epoch Mod - EpochMod.com
All Rights Reserved.
*/
private["_plyr", "_plyrUID", "_items", "_class", "_dir", "_location", "_type", "_weapon", "_attachments", "_currWeap", "_itemSlot", "_itemqtys", "_goggles", "_headgear", "_vest", "_backpack", "_uniform", "_weapons", "_magazinesAmmo", "_itemsplayer", "_weaponsplayer", "_group", "_primaryWeapon", "_secondaryWeapon", "_attachment", "_equipped", "_wMags", "_plyrGroup", "_droppedWeapons", "_newPlyr", "_token", "_owner", "_reviver"];

_plyr = _this select 0;
_owner = owner _plyr;
_reviver = _this select 1;

if !([_reviver, _this select 2] call EPOCH_server_getPToken) exitWith{};
if (isNull _plyr) exitWith{};
if (_plyr distance _reviver > 20) exitWith{};

if (!local _plyr) then {
	_plyrUID = getPlayerUID _plyr;
	if (!isNil "_plyrUID" && !alive _plyr) then {

		if (_plyr == _reviver) exitWith {
			'epochserver' callExtension format['820|%1|EpochMod.com Autoban #R1',getPlayerUID _reviver];
			['ahb', format['%1 (%2): Tried to Revive yourself (%3)', name _reviver, getPlayerUID _reviver, _this]] call EPOCH_fnc_server_hiveLog;
		};

		_class = typeOf _plyr;

		if (_class in ["Epoch_Male_F", "Epoch_Female_F"]) then {


			if (_plyr getVariable["REVIVE", true]) then {

				diag_log format["DEBUG server_revivePlayer : %1", _this];

				_location = getPosATL _plyr;
				_dir = getDir _plyr;
				_plyrGroup = _plyr getVariable["GROUP", ""];

				_goggles = goggles _plyr;
				_headgear = headgear _plyr;
				_vest = vest _plyr;
				_backpack = backpack _plyr;
				_uniform = uniform _plyr;

				_items = assignedItems _plyr;
				_magazinesAmmo = magazinesAmmo _plyr;

				_primaryWeapon = "";
				_secondaryWeapon = "";

				_droppedWeapons = [];
				{
					{
						_droppedWeapons pushBack _x;
						_type = getNumber(configfile >> "cfgweapons" >> (_x select 0) >> "type");
						switch _type do {
							case 1: { _primaryWeapon = _x select 0 };
							case 4: { _secondaryWeapon = _x select 0 };
						};
					} forEach (weaponsItemsCargo _x);

				} forEach nearestObjects[_plyr, ["WeaponHolderSimulated"], 12];

				// diag_log ["DEBUG: _droppedWeapons %1", _droppedWeapons];

				_itemsplayer = [getItemCargo(uniformContainer _plyr), getItemCargo(vestContainer _plyr), getItemCargo(backpackContainer _plyr)];
				_weaponsplayer = [getWeaponCargo(uniformContainer _plyr), getWeaponCargo(vestContainer _plyr), getWeaponCargo(backpackContainer _plyr)];
				_weapons = [currentWeapon _plyr, ((weaponsItems _plyr) + _droppedWeapons), [_primaryWeapon, _secondaryWeapon, handgunWeapon _plyr]];

				hideObjectGlobal _plyr;

				// create new player unit change this class later
				_group = grpNull;
				if (_plyrGroup != "") then {
					{
						if ((_x getVariable["GROUP",""]) == _plyrGroup) exitWith {
							_group = group _x;
						};
					}forEach playableUnits;

					if (isNull _group) then {
						_group = createGroup west;
					};

					diag_log format["DEBUG Group Found: %1", _group];
				} else {
					_group = createGroup west;
					diag_log format["DEBUG Group Created: %1", _group];
				};

				_newPlyr = _group createUnit[_class, _location, [], 0, "CAN_COLLIDE"];

				addToRemainsCollector[_newPlyr];

				_newPlyr allowDammage false;
				{
					_newPlyr disableAI _x;
				}forEach["FSM", "MOVE", "AUTOTARGET", "TARGET"];

				_newPlyr setVariable ["SETUP", true];
				_newPlyr setVariable ["PUID", _plyrUID];
				_newPlyr setVariable ["GROUP", _plyrGroup];
				_newPlyr setVariable ["REVIVE", false];

				// _plyr playActionNow "Die";

				_newPlyr setDir _dir;
				_newPlyr setPosATL _location;

				// Medical
				_newPlyr setFatigue 1;
				_newPlyr setDamage 0.25;

				// Apperance
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
				if (count _weapons >= 2) then {

					_equipped = _weapons select 2;
					{
						_weapon = _x select 0;
						_type = getNumber(configfile >> "cfgweapons" >> _weapon >> "type");

						_attachments = [];
						// suppressor, laser, optics
						for "_a" from 1 to 3 do {
							_attachment = _x select _a;
							if (_attachment != "") then {
								_attachments pushBack _attachment;
							};
						};
						_wMags = (count _x) == 5;

						// add weapon if equiped

						if (_weapon in _equipped) then {
							_equipped = _equipped - [_weapon];

							if (_wMags) then {
								_newPlyr addMagazine(_x select 4);
							};

							if (_weapon != "") then {
								_newPlyr addWeapon _weapon;
							};

							switch _type do {
								case 1: { // primary
									removeAllPrimaryWeaponItems _newPlyr;
									{ _newPlyr addPrimaryWeaponItem _x }forEach _attachments;
								};
								case 2:	{ // handgun
									removeAllHandgunItems _newPlyr;
									{ _newPlyr addHandgunItem _x }forEach _attachments;
								};
								case 4:	{ // secondary
									// removeAllSecondaryWeaponItems player; does not exist ?
									{
										_newPlyr removeSecondaryWeaponItem _x;
									} forEach(secondaryWeaponItems _newPlyr);
									{ _newPlyr addSecondaryWeaponItem _x }forEach _attachments;
								};
							};
						} else {
							{
								_newPlyr addItem _x;
							}forEach _attachments;

							if (_wMags) then {
								_newPlyr addMagazine(_x select 4);
							};
						};

					} forEach (_weapons select 1);

					_currWeap = (_weapons select 0);

				};

				// Linked items
				{
					if (_x in ["Binocular","Rangefinder"]) then {
						_newPlyr addWeapon _x;
					} else {
						_newPlyr linkItem _x;
					};
				}forEach _items;


				// add items to containers
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
							//diag_log format["DEBUG additemtoVest: %1", _x];
						};

					}forEach (_x select 0);
				}forEach _itemsplayer;

				// add weapons to containers
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
							//diag_log format["DEBUG additemtoVest: %1", _x];
						};

					}forEach (_x select 0);
				}forEach _weaponsplayer;

				// Add magazines
				{
					_newPlyr addMagazine _x;
					//diag_log format["DEBUG addMagazine: %1", _x];
				}forEach _magazinesAmmo;

				// Final Push
				_token = _newPlyr call EPOCH_server_setPToken;

				[["clientRevive", [_newPlyr, _token]], _owner] call EPOCH_sendPublicVariableClient;
			};
		};
	};
};
