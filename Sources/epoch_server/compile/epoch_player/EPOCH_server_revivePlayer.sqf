/*
	Author: Aaron Clark - EpochMod.com

    Contributors:

	Description:
	Player Revive

    Licence:
    Arma Public License Share Alike (APL-SA) - https://www.bistudio.com/community/licenses/arma-public-license-share-alike

    Github:
    https://github.com/EpochModTeam/Epoch/tree/master/Sources/epoch_server/compile/epoch_player/EPOCH_server_revivePlayer.sqf
*/
private["_player", "_playerUID", "_items", "_class", "_dir", "_location", "_type", "_weapon", "_attachments", "_currWeap", "_itemSlot", "_itemqtys", "_goggles", "_headgear", "_vest", "_backpack", "_uniform", "_weapons", "_magazinesAmmo", "_itemsplayer", "_weaponsplayer", "_group", "_primaryWeapon", "_secondaryWeapon", "_attachment", "_equipped", "_wMags", "_playerGroup", "_droppedWeapons", "_newPlyr", "_token", "_owner", "_reviver"];
params ["_player","_reviver","_token"];

if !([_reviver, _token] call EPOCH_server_getPToken) exitWith{};
if (isNull _player) exitWith{};
if (_player distance _reviver > 20) exitWith{};

if (!local _player) then {
	_playerUID = getPlayerUID _player;
	if (!isNil "_playerUID" && !alive _player) then {

		if (_player == _reviver) exitWith {
			'epochserver' callExtension format['820|%1|EpochMod.com Autoban #R1',getPlayerUID _reviver];
			['ahb', format['%1 (%2): Tried to Revive yourself (%3)', name _reviver, getPlayerUID _reviver, _this]] call EPOCH_fnc_server_hiveLog;
		};

		_class = typeOf _player;

		if (_class in ["Epoch_Male_F", "Epoch_Female_F"]) then {

			if (_player getVariable["REVIVE", true]) then {

				diag_log format["DEBUG server_revivePlayer : %1", _this];

				_location = getPosATL _player;
				_dir = getDir _player;
				_playerGroup = _player getVariable["GROUP", ""];

				_goggles = goggles _player;
				_headgear = headgear _player;
				_vest = vest _player;
				_backpack = backpack _player;
				_uniform = uniform _player;

				_items = assignedItems _player;
				_magazinesAmmo = magazinesAmmo _player;

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

				} forEach nearestObjects[_player, ["WeaponHolderSimulated"], 12];

				// diag_log ["DEBUG: _droppedWeapons %1", _droppedWeapons];

				_itemsplayer = [getItemCargo(uniformContainer _player), getItemCargo(vestContainer _player), getItemCargo(backpackContainer _player)];
				_weaponsplayer = [getWeaponCargo(uniformContainer _player), getWeaponCargo(vestContainer _player), getWeaponCargo(backpackContainer _player)];
				_weapons = [currentWeapon _player, ((weaponsItems _player) + _droppedWeapons), [_primaryWeapon, _secondaryWeapon, handgunWeapon _player]];

				hideObjectGlobal _player;

				// create new player unit change this class later
				_group = grpNull;
				if (_playerGroup != "") then {
					{
						if ((_x getVariable["GROUP",""]) == _playerGroup) exitWith {
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
				_newPlyr setVariable ["PUID", _playerUID];
				_newPlyr setVariable ["GROUP", _playerGroup];
				_newPlyr setVariable ["REVIVE", false];

				// _player playActionNow "Die";

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

				// send to player
				[_newPlyr, _token] remoteExec ['EPOCH_clientRevive',_player];
			};
		};
	};
};
