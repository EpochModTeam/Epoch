/*
	Author: Aaron Clark - EpochMod.com

    Contributors:

	Description:
	Player Save

    Licence:
    Arma Public License Share Alike (APL-SA) - https://www.bistudio.com/community/licenses/arma-public-license-share-alike

    Github:
    https://github.com/EpochModTeam/Epoch/tree/release/Sources/epoch_server/compile/epoch_player/EPOCH_server_savePlayer.sqf
*/
private["_return", "_pos", "_medical", "_playerUID", "_weapons", "_itemsplayer", "_weaponsplayer", "_appearance", "_dmg", "_allowSave", "_cIndex", "_Svars", "_current_crypto", "_group", "_revive", "_vehiclePlyr","_server_vars"];
params [["_player",objNull], ["_vars",[]]];

if (isNull _player) exitWith {
	diag_log "DEBUG SAVE ABORT null player object";
};

if !(_player getVariable ["SETUP", false]) exitWith {
	diag_log format ["DEBUG SAVE ABORT not setup: %1", _player]
};

_playerUID = _player getVariable ["PUID", ""]; // getPlayerUID _player
if (_playerUID == "") exitWith {
	diag_log format ["DEBUG SAVE ABORT %1", _playerUID]
};

if !(alive _player) exitWith{
	// Dead Stat bit index 0
	_return = ["PlayerStats", _playerUID, 0, 1] call EPOCH_fnc_server_hiveSETBIT;
};

// add vehicle to update queue
_vehiclePlyr = vehicle _player;
if (_vehiclePlyr != _player) then {
	EPOCH_saveVehQueue pushBackUnique  _vehiclePlyr;
};

_allowSave = _vars isEqualTypeParams EPOCH_defaultVars;
if (_allowSave) then{

	if !(_vars isEqualTo EPOCH_defaultVars_SEPXVar) then{
		_serverOnly = ["Crypto"];
		_Svars = _player getVariable["VARS", call EPOCH_defaultVars_SEPXVar];
		{
			_cIndex = EPOCH_customVars find _x;
			if (_cIndex != -1) then{
				_vars set[_cIndex, (_Svars select _cIndex)];
			};
		} forEach _serverOnly;
	};
	_player setVariable ["VARS", _vars];

    /* SERVER_VARS INUSE INDEX:
        0 = RESPAWN POS
    */
	_server_vars = _player getVariable["SERVER_VARS", []];

	_group = _player getVariable ["GROUP", ""];
	_revive = _player getVariable ["REVIVE", true];

	_pos = (getposATL _player call EPOCH_precisionPos);

	if (vehicle _player != _player) then {

		_staticTraderLocationsDistances = [];
		{
			_staticTraderLocationsDistances pushBack [_x distance _player, _x]
		} forEach EPOCH_staticTraderLocations;

		if !(_staticTraderLocationsDistances isEqualTo []) then{
			_staticTraderLocationsDistances sort true;
			_pos = _staticTraderLocationsDistances select 0 select 1;
			_pos set[2, 0];
		};
	};

	_dmg = damage _player;
	_medical = [getBleedingRemaining _player, 0, getOxygenRemaining _player, _dmg];
	_appearance = [goggles _player, headgear _player, vest _player, backpack _player, uniform _player, typeOf _player];
	_itemsplayer = [getItemCargo(uniformContainer _player), getItemCargo(vestContainer _player), getItemCargo(backpackContainer _player)];
	_weaponsplayer = [getWeaponCargo(uniformContainer _player), getWeaponCargo(vestContainer _player), getWeaponCargo(backpackContainer _player)];
	_weapons = [currentWeapon _player, weaponsItems _player, [primaryWeapon _player, secondaryWeapon _player, handgunWeapon _player]];

	// save player
	_return = ["Player", _playerUID, EPOCH_expiresPlayer, [[getDir _player, _pos, (call EPOCH_fn_InstanceID)], _medical, _appearance, _server_vars, _vars, _weapons, assignedItems _player, magazinesAmmo _player, _itemsplayer, _weaponsplayer, _group, _revive]] call EPOCH_fnc_server_hiveSETEX;

	// kill player if blood pressure >= 180
	if (_vars select 12 >= 180) then {
		_player setDamage 1;
	} else {
		// set player alive bit
		["PlayerStats", _playerUID, 0, 0] call EPOCH_fnc_server_hiveSETBIT;
	};
};
