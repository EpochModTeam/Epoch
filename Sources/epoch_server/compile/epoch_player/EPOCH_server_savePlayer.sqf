/*
Player Save

Epoch Mod - EpochMod.com
All Rights Reserved.
*/
private["_return", "_pos", "_medical", "_plyrUID", "_weapons", "_vars", "_itemsplayer", "_weaponsplayer", "_appearance", "_plyr", "_dmg", "_allowSave", "_cIndex", "_Svars", "_current_crypto", "_group", "_revive", "_vehiclePlyr","_server_vars"];

_plyr = _this select 0;
_vars = _this select 1;

if (isNull _plyr) exitWith {
	diag_log "DEBUG SAVE ABORT null player object";
};

if !(_plyr getVariable ["SETUP", false]) exitWith {
	diag_log format ["DEBUG SAVE ABORT not setup: %1", _plyr]
};
_plyrUID = _plyr getVariable ["PUID", ""]; // getPlayerUID _plyr
if (_plyrUID == "") exitWith {
	diag_log format ["DEBUG SAVE ABORT %1", _plyrUID]
};

if !(alive _plyr) exitWith{
	// Dead Stat bit index 0
	_return = ["PlayerStats", _plyrUID, 0, 1] call EPOCH_fnc_server_hiveSETBIT;
};

// add vehicle to update queue
_vehiclePlyr = vehicle _plyr;
if (_vehiclePlyr != _plyr) then {
	if !(_vehiclePlyr in EPOCH_saveVehQueue) then {
		EPOCH_saveVehQueue pushBack _vehiclePlyr;
	};
};

if (typeName _vars == "ARRAY") then {
	if (count _vars == EPOCH_customVarCount) then{
		_allowSave = true;
		{
			if (typeName (_vars select _forEachIndex) != typeName _x) exitWith { _allowSave = false };
		} forEach EPOCH_defaultVars;

		if (_allowSave) then{

			if !(_vars isEqualTo EPOCH_defaultVars_SEPXVar) then{
				_serverOnly = ["Crypto"];
				_Svars = _plyr getVariable["VARS", [] + EPOCH_defaultVars_SEPXVar];
				{
					_cIndex = EPOCH_customVars find _x;
					if (_cIndex != -1) then{
						_vars set[_cIndex, (_Svars select _cIndex)];
					};
				} forEach _serverOnly;
			};

			// Server Only Stats
			_server_vars = _plyr getVariable["SERVER_VARS", []];

			_group = _plyr getVariable ["GROUP", ""];
			_revive = _plyr getVariable ["REVIVE", true];

			_pos = (getposATL _plyr call EPOCH_precisionPos);

			if (vehicle _plyr != _plyr) then {

				_staticTraderLocationsDistances = [];
				{
					_staticTraderLocationsDistances pushBack [_x distance player, _x]
				} forEach EPOCH_staticTraderLocations;

				if !(_staticTraderLocationsDistances isEqualTo []) then{
					_staticTraderLocationsDistances sort true;
					_pos = _staticTraderLocationsDistances select 0 select 1;
					_pos set[2, 0];
				};
			};

			_dmg = damage _plyr;
			_medical = [getBleedingRemaining _plyr, 0, getOxygenRemaining _plyr, _dmg];
			_appearance = [goggles _plyr, headgear _plyr, vest _plyr, backpack _plyr, uniform _plyr, typeOf _plyr];
			_itemsplayer = [getItemCargo(uniformContainer _plyr), getItemCargo(vestContainer _plyr), getItemCargo(backpackContainer _plyr)];
			_weaponsplayer = [getWeaponCargo(uniformContainer _plyr), getWeaponCargo(vestContainer _plyr), getWeaponCargo(backpackContainer _plyr)];
			_weapons = [currentWeapon _plyr, weaponsItems _plyr, [primaryWeapon _plyr, secondaryWeapon _plyr, handgunWeapon _plyr]];

			if (count _this >= 4) then {
				_plyr setVariable ["VARS", nil];
			} else {
				_plyr setVariable ["VARS", _vars];
			};

			// save player
			_return = ["Player", _plyrUID, EPOCH_expiresPlayer, [[getDir _plyr, _pos, (call EPOCH_fn_InstanceID)], _medical, _appearance, _server_vars, _vars, _weapons, assignedItems _plyr, magazinesAmmo _plyr, _itemsplayer, _weaponsplayer, _group, _revive]] call EPOCH_fnc_server_hiveSETEX;

			// kill player if blood pressure >= 180
			if (_vars select 12 >= 180) then {
				_plyr setDamage 1;
			} else {
				// set player alive bit
				["PlayerStats", _plyrUID, 0, 0] call EPOCH_fnc_server_hiveSETBIT;
			};
		};
	};
};
