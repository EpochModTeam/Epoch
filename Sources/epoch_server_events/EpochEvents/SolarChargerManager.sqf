/*
	Garden Manager
	by Aaron Clark - EpochMod.com

	Improvements and or bugfixes and other contributions are welcome via the github:
	https://github.com/EpochModTeam/Epoch/tree/release/Sources/epoch_server_settings/EpochEvents/GardenManager.sqf
*/
//[[[cog import generate_private_arrays ]]]
private ["_ChargeClasses","_MaxRounds","_ChargeValue","_modifiedSolars","_changed","_solar","_chargeables","_idx","_MaxRoundsTmp"];
//[[[end]]]

_ChargeClasses = ["EnergyPack","EnergyPackLg"];
_MaxRounds = [];
{
	_MaxRounds pushback (getnumber (configfile >> "cfgMagazines" >> _x >> "count"));
} foreach _ChargeClasses;

_ChargeValue = 1;

if (isNil "EPOCH_activeSolars") then {EPOCH_activeSolars = []};
EPOCH_activeSolars = EPOCH_activeSolars - [objNull];

_modifiedSolars = [];
{
	_changed = false;
	_solar = _x;
	_chargeables = (magazinesAmmoCargo _solar) select {(_x select 0) in _ChargeClasses};
	if !(_chargeables isequalto []) then {
		_return = [];
		{
			_x params ["_type","_rounds"];
			_idx = _ChargeClasses find _type;
			if (_idx > -1) then {
				_MaxRoundsTmp = _MaxRounds select _idx;
				if (_MaxRoundsTmp > _rounds) then {
					_changed = true;
					_x set [1, (_rounds + _ChargeValue) min _MaxRoundsTmp];
				};
			};
		} foreach _chargeables;
		if (_changed) then {
			clearWeaponCargoGlobal _solar;
			clearMagazineCargoGlobal _solar;
			clearBackpackCargoGlobal _solar;
			clearItemCargoGlobal _solar;
			{
				_solar addmagazineammocargo [_x select 0,1,_x select 1];
			} foreach _chargeables;
			_modifiedSolars pushBack _solar;
		};
	};
} forEach EPOCH_activeSolars;

if !(_modifiedSolars isEqualTo []) then {
	[_modifiedSolars] call EPOCH_server_save_vehicles;
};
