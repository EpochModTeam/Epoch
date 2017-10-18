/*
	Author: Aaron Clark - EpochMod.com

    Contributors: He-Man and DirtySanchez

	Description:
    Upgrade vehicle

    Licence:
    Arma Public License Share Alike (APL-SA) - https://www.bistudio.com/community/licenses/arma-public-license-share-alike
*/

private ["_slot","_pos","_dir","_cargo","_damage","_OldHitPoints","_typeVeh","_baseVeh","_color","_fuel","_newVeh","_checkclass","_cfgEpochVehicles","_availableColorsConfig","_colors","_textureSelectionIndex","_selections","_textures","_count","_newHitpoints","_idx","_dmg"];
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
_OldHitPoints = getAllHitPointsDamage _veh;
_typeVeh = typeOf _veh;
_baseVeh = _veh getVariable ["VEHICLE_BASECLASS",_typeVeh];
_color = _veh getVariable ["VEHICLE_TEXTURE",""];
_fuel = fuel _veh;
deletevehicle _veh;
waituntil {isnull _veh};
_pos set [2,(_pos select 2)+0.5];
_newVeh = createVehicle [_UpgradeVeh, [random 500, random 500,500], [], 0, "CAN_COLLIDE"];
_newVeh setVariable ["VEHICLE_SLOT", _slot, true];
_newVeh setVariable ["VEHICLE_BASECLASS", _baseVeh];
_newVeh call EPOCH_server_setVToken;
_newVeh call EPOCH_server_vehicleInit;
_newVeh setdir _dir;
_newVeh setposasl _pos;

// set fuel level
_newVeh setFuel _fuel;

// apply persistent textures
_checkclass = _typeVeh;
if !(_newVeh iskindof _typeVeh) then {
	_checkclass = _UpgradeVeh;
};
_cfgEpochVehicles = 'CfgEpochVehicles' call EPOCH_returnConfig;
_availableColorsConfig = (_cfgEpochVehicles >> _checkclass >> "availableColors");
if (isArray(_availableColorsConfig)) then{
	_colors = getArray (_availableColorsConfig);
	_textureSelectionIndex = (_cfgEpochVehicles >> _checkclass >> "textureSelectionIndex");
	_selections = if (isArray(_textureSelectionIndex)) then{ getArray(_textureSelectionIndex) } else { [0] };
	_textures = _colors select 0;
	if (!(_newVeh iskindof _typeVeh) || _color isequalto "") then {
		_color = floor(random(count _textures));
	};
	_count = (count _colors) - 1;
	{
		if (_count >= _forEachIndex) then{
			_textures = _colors select _forEachIndex;
		};
		_newVeh setObjectTextureGlobal[_x, (_textures select _color)];
	} forEach _selections;
	_newVeh setVariable["VEHICLE_TEXTURE", _color];
};

// disable thermal imaging equipment
_newVeh disableTIEquipment true;

// set damage and hitpoints
_newVeh setDamage _damage;
_newHitpoints = getAllHitPointsDamage _newVeh;
{
	_idx = (_newHitpoints select 0) find _x;
	if (_idx > -1) then {
		_dmg = _OldHitPoints select 2 select _foreachindex;
		if (_x in ["HitFuel", "HitEngine"]) then {
			_dmg = _dmg min 0.9;
		};
		_newVeh setHitPointDamage [_x, _dmg];
	};
} foreach (_OldHitPoints select 0);

// new Dynamicsimulation
if(["CfgDynamicSimulation", "vehicleDynamicSimulationSystem", true] call EPOCH_fnc_returnConfigEntryV2)then
{
	_newveh enableSimulationGlobal false; // turn it off until activated by dynamicSim
	_newveh enableDynamicSimulation true;
};

// add back old inventory
clearWeaponCargoGlobal    _newveh;
clearMagazineCargoGlobal  _newveh;
clearBackpackCargoGlobal  _newveh;
clearItemCargoGlobal	  _newveh;
[_newveh,_cargo] call EPOCH_server_CargoFill;

// Remove forbidden Weapons and Ammo
_serverSettingsConfig = configFile >> "CfgEpochServer";
_removeweapons = [_serverSettingsConfig, "removevehweapons", []] call EPOCH_fnc_returnConfigEntry;
_removemagazinesturret = [_serverSettingsConfig, "removevehmagazinesturret", []] call EPOCH_fnc_returnConfigEntry;
if !(_removeweapons isequalto []) then {
	{
		_newVeh removeWeaponGlobal _x;
	} foreach _removeweapons;
};
if !(_removemagazinesturret isequalto []) then {
	{
		_newVeh removeMagazinesTurret _x;
	} foreach _removemagazinesturret;
};

// save new vehicle to db
_newveh call EPOCH_Server_Save_Vehicle;
