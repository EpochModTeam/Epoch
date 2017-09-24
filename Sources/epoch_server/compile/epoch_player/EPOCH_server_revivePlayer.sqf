/*
	Author: Aaron Clark - EpochMod.com

    Contributors: He-Man

	Description:
	Player Revive

    Licence:
    Arma Public License Share Alike (APL-SA) - https://www.bistudio.com/community/licenses/arma-public-license-share-alike

    Github:
    https://github.com/EpochModTeam/Epoch/tree/release/Sources/epoch_server/compile/epoch_player/EPOCH_server_revivePlayer.sqf
*/
//[[[cog import generate_private_arrays ]]]
private ["_loadout","_CorpseCrypto","_PlayerCrypto","_attachments","_cIndex","_class","_currwh","_deleteprimary","_deletesecondary","_dir","_droppedPrimary","_droppedSecondary","_droppedWeapons","_equipped","_group","_location","_newPlyr","_playerGroup","_playerUID","_primaryWeapon","_secondaryWeapon","_token","_type","_vars","_wMags","_wMagsArray","_weapon","_wh","_kIndex","_reviver","_reviverCStats","_reviverKarma","_reviverKarmaAdj"];
//[[[end]]]
params ["_player","_reviver",["_token","",[""]] ];

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
				if (_player getvariable ['Reviving', false]) exitwith {
					diag_log format['DEBUG Reviving skipped - Player already reviving : %1', _this];
				};
				_player setvariable ['Reviving',true];

				diag_log format["DEBUG server_revivePlayer : %1", _this];

				_location = getPosATL _player;
				_dir = getDir _player;
				_playerGroup = _player getVariable["GROUP", ""];

				// Load Inventory
				_loadout = getUnitLoadout _player;

				_primaryWeapon = "";
				_secondaryWeapon = "";
				_wh = nearestObjects[_player, ["WeaponHolderSimulated"], 12];
				_droppedPrimary = [];
				_droppedSecondary = [];
				_droppedWeapons = [];
				_deleteprimary = [];
				_deletesecondary = [];
				reverse _wh;
				{
					_currwh = _x;
					{
						_type = getNumber(configfile >> "cfgweapons" >> (_x select 0) >> "type");
						switch _type do {
							case 1: {_droppedPrimary = _x; _primaryWeapon = _x select 0; _deleteprimary = [_currwh]};
							case 4: {_droppedSecondary = _x; _secondaryWeapon = _x select 0;_deletesecondary = [_currwh]};
						};
					} forEach (weaponsItemsCargo _x);
				} foreach _wh;
				{
					if (!isnull _x) then {deletevehicle _x};
				} foreach (_deleteprimary+_deletesecondary);

				if !(_droppedPrimary isequalto []) then {_droppedWeapons pushback _droppedPrimary};
				if !(_droppedSecondary isequalto []) then {_droppedWeapons pushback _droppedSecondary};
				// diag_log ["DEBUG: _droppedWeapons %1", _droppedWeapons];

				hideObjectGlobal _player;

				// create new player unit change this class later
				_group = grpNull;
				if (_playerGroup != "") then {
					{
						if ((_x getVariable["GROUP",""]) == _playerGroup) exitWith {
							_group = group _x;
						};
					}forEach (allPlayers select {alive _x});

					if (isNull _group) then {
						_group = createGroup [west, true];
					};

					diag_log format["DEBUG Group Found: %1", _group];
				} else {
					_group = createGroup [west, true];
					diag_log format["DEBUG Group Created: %1", _group];
				};

				_newPlyr = _group createUnit[_class, _location, [], 0, "CAN_COLLIDE"];

				// new Dynamicsimulation
				if(["CfgDynamicSimulation", "playerDynamicSimulationSystem", true] call EPOCH_fnc_returnConfigEntryV2)then
				{
					_newPlyr enableDynamicSimulation true;
					_newPlyr triggerDynamicSimulation true;
				};

				addToRemainsCollector[_newPlyr];

				_newPlyr disableAI "ALL";

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

				// Add inventory
				_newPlyr setUnitLoadout [_loadout, false];

				// Dropped Weapons
				if !(_droppedWeapons isequalto []) then {
					_equipped = [_primaryWeapon,_secondaryWeapon];
					{
						_weapon = _x deleteAt 0;
						_type = getNumber(configfile >> "cfgweapons" >> _weapon >> "type");
						_attachments = [];
						_wMags = false;
						_wMagsArray = [];
						// suppressor, laser, optics
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
						}else{
							{
								_newPlyr addItem _x;
							}forEach _attachments;
						};
					} forEach _droppedWeapons;
				};

				// Final Push
				_token = _newPlyr call EPOCH_server_setPToken;

				_CorpseCrypto = _player getVariable['Crypto', 0];
				if (_CorpseCrypto > 0) then {
					_cIndex = EPOCH_customVars find 'Crypto';
					_vars = _player getVariable['VARS', call EPOCH_defaultVars_SEPXVar];
					_PlayerCrypto = _CorpseCrypto;
					_PlayerCrypto remoteExec ['EPOCH_effectCrypto',_player];
					_vars set[_cIndex, _PlayerCrypto];
					_newPlyr setVariable['VARS', _vars];
				};

				// send to player
				[_newPlyr, _token, loadAbs _newPlyr] remoteExec ['EPOCH_clientRevive',_player];

				// send stat to reviver
				[_reviver, "Revives", 1, true] call EPOCH_server_updatePlayerStats;
				
				// send karma stat to reviver
				_kIndex = EPOCH_communityStats find "Karma";
				_reviverCStats = _reviver getVariable["COMMUNITY_STATS", EPOCH_defaultStatVars];
				_reviverKarma = _reviverCStats select _kIndex;
				_reviverKarmaAdj = 5;
				if(_reviverKarma < 0)then{_reviverKarmaAdj = -5};
				[_reviver, "Karma", _reviverKarmaAdj, true] call EPOCH_server_updatePlayerStats;
			};
		};
	};
};
