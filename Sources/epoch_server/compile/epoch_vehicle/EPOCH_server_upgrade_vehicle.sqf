/*
	Author: Aaron Clark - EpochMod.com

    Contributors: He-Man and DirtySanchez

	Description:
    Upgrade vehicle

    Licence:
    Arma Public License Share Alike (APL-SA) - https://www.bistudio.com/community/licenses/arma-public-license-share-alike
*/
params [["_array",[]],["_player",objnull],["_token","",[""]]];
if (_array isequalto []) exitwith {
	diag_log "Array is empty";
};
if !([_player, _token] call EPOCH_server_getPToken) exitWith{
	diag_log "Tokencheck failed";
};
_array params [["_veh",objnull],["_UpgradeVeh",""],["_removeCrypto",[]]];
if (isnull _veh) exitwith {
	diag_log "Vehicle is null";
};
if (_UpgradeVeh isequalto "") exitwith {
	diag_log "No Upgrade Vehicle Class";
};
if (!(_removeCrypto isequalto []) && !(_removeCrypto isEqualTo 0)) then {
	[_player,-_removeCrypto] call EPOCH_server_effectCrypto;
};
_slot = _veh getvariable ["vehicle_slot","-1"];
if (_slot isequalto "-1") exitwith {
	diag_log "Vehicle has no Slot";
};

_pos = getposasl _veh;
_dir = getdir _veh;
_cargo = _veh call EPOCH_server_CargoSave;
_damage = damage _veh;
_hitPoints = getAllHitPointsDamage _veh;
_baseVeh = _veh getVariable ["VEHICLE_BASECLASS",""];
_typeVeh = typeOf _veh;
_colorVeh = _veh getVariable ["VEHICLE_TEXTURE",""];
_fuel = fuel _veh;
deletevehicle _veh;
waituntil {isnull _veh};
_pos set [2,(_pos select 2)+0.5];
_newVeh = createVehicle [_UpgradeVeh, [random 500, random 500,500], [], 0, "CAN_COLLIDE"];		
_newVeh setVariable ["VEHICLE_SLOT", _slot, true];
if!(_baseVeh isEqualTo "")then
{
	_newVeh setVariable["VEHICLE_BASECLASS", _baseVeh];
}else{
	_newVeh setVariable["VEHICLE_BASECLASS", _typeVeh];
};
_newVeh call EPOCH_server_setVToken;
_newVeh call EPOCH_server_vehicleInit;
_newVeh setdir _dir;
_newVeh setposasl _pos;

// set fuel level
_newVeh setFuel _fuel;
			
// apply persistent textures
_cfgEpochVehicles = 'CfgEpochVehicles' call EPOCH_returnConfig;
_newbaseVeh = _veh getVariable ["VEHICLE_BASECLASS",""];
_availableColorsConfig = (_cfgEpochVehicles >> _newbaseVeh >> "availableColors");
if (isArray(_availableColorsConfig)) then {
	_color = _colorVeh;
	_colors = getArray(_availableColorsConfig);
	_textureSelectionIndex = (_cfgEpochVehicles >> _newbaseVeh >> "textureSelectionIndex");
	_selections = if (isArray(_textureSelectionIndex)) then { getArray(_textureSelectionIndex) } else { [0] };
	_count = (count _colors) - 1;
	{
		_textures = _colors select 0;
		if (_count >= _forEachIndex) then {
			_textures = _colors select _forEachIndex;
		};
		_newVeh setObjectTextureGlobal [_x, _textures  select _color];
	} forEach _selections;
	_newVeh setVariable ["VEHICLE_TEXTURE", _color];
};
			
// disable thermal imaging equipment
_newVeh disableTIEquipment true;

// set damage and hitpoints
_newVeh setDamage _damage;
_allHitpoints = getAllHitPointsDamage _newVeh;
if !(_allHitpoints isEqualTo []) then{
	_actualHitpoints = _allHitpoints select 0;
	if ((count _actualHitpoints) == (count _hitpoints)) then{
		{
			_dmg = _hitpoints param [_forEachIndex,0];
			if (_x in ["HitFuel", "HitEngine"]) then {
				_dmg = _dmg min 0.9;
			};
			_newVeh setHitIndex [_forEachIndex, _dmg];
		} forEach _actualHitpoints;
	};
};

// add back old inventory
[_newveh,_cargo] call EPOCH_server_CargoFill;

// save new vehicle to db
_newveh call EPOCH_Server_Save_Vehicle;