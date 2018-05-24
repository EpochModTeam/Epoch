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
private ["_loadabs","_loadout","_CorpseCrypto","_PlayerCrypto","_attachments","_cIndex","_class","_currwh","_deleteprimary","_deletesecondary","_dir","_droppedPrimary","_droppedSecondary","_droppedWeapons","_equipped","_group","_garbage","_location","_newPlyr","_playerGroup","_playerUID","_token","_type","_vars","_wMags","_wMagsArray","_weapon","_wh","_kIndex","_reviver","_reviverCStats","_reviverKarma","_reviverKarmaAdj"];
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

				_wh = nearestObjects[_player, ["WeaponHolderSimulated"], 12];
				_droppedPrimary = [];
				_droppedSecondary = [];
				_deleteprimary = [];
				_deletesecondary = [];
				reverse _wh;
				{
					_currwh = _x;
					{
						_type = getNumber(configfile >> "cfgweapons" >> (_x select 0) >> "type");
						switch _type do {
							case 1: {_droppedPrimary = _x; _deleteprimary = [_currwh]};
							case 4: {_droppedSecondary = _x; _deletesecondary = [_currwh]};
						};
					} forEach (weaponsItemsCargo _x);
				} foreach _wh;
				{
					if (!isnull _x) then {deletevehicle _x};
				} foreach (_deleteprimary+_deletesecondary);
				if (count _droppedPrimary == 6) then {
					_droppedPrimary set [6,_droppedPrimary select 5];
					_droppedPrimary set [5,[]];
				
				};
				if (count _droppedSecondary == 6) then {
					_droppedSecondary set [6,_droppedSecondary select 5];
					_droppedSecondary set [5,[]];
				};

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
				if([configFile >> "CfgEpochServer", "playerDynamicSimulationSystem", true] call EPOCH_fnc_returnConfigEntry)then
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
				_newPlyr setVariable ["SERVER_VARS",_player getVariable ["SERVER_VARS",[]]];

				// _player playActionNow "Die";

				_newPlyr setDir _dir;
				_newPlyr setPosATL _location;

				// Medical
				_newPlyr setFatigue 1;
				_newPlyr setDamage 0.25;

				// Add inventory
				_loadout set [0,_droppedPrimary];
				_loadout set [1,_droppedSecondary];
//				_newPlyr setUnitLoadout [_loadout, false];

				// Workaround for Client / Server synchronizing issue in SetUnitLoadout
				_loadabs = [_newPlyr,_loadout] call Epoch_server_SetUnitLoadout;
				if (_loadabs isequalto -1) exitwith {
					removeFromRemainsCollector [_newPlyr];
					deletevehicle _newPlyr;
					_player setvariable ['Reviving',false];
					_player hideObjectGlobal false;
				};

				_garbage = createVehicle [selectrandom ["MedicalGarbage_01_1x1_v1_F","MedicalGarbage_01_1x1_v3_F","MedicalGarbage_01_1x1_v2_F"], _location, [], 0, "CAN_COLLIDE"];
				EPOCH_cleanupQueue pushBack _garbage;

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
				[_newPlyr, _token, _loadabs] remoteExec ['EPOCH_clientRevive',_player];

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
