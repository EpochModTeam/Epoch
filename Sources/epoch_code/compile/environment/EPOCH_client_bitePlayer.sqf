/*
	Author: Aaron Clark - EpochMod.com

    Contributors:

	Description:
	Performs damage related effects

    Licence:
    Arma Public License Share Alike (APL-SA) - https://www.bistudio.com/community/licenses/arma-public-license-share-alike

    Github:
    https://github.com/EpochModTeam/Epoch/tree/release/Sources/epoch_code/compile/environment/EPOCH_client_bitePlayer.sqf

    Example:
    _dog call EPOCH_client_bitePlayer;

    Parameter(s):
		_unit: OBJECT - attacker

	Returns:
	NOTHING
*/
//[[[cog import generate_private_arrays ]]]
private ["_animConfigArray","_animationEffect","_animationEffectGlobal","_bleedAmount","_bleedChance","_bloodpAmount","_bloodpChance","_canSee","_cfgObjectInteraction","_distance","_doAttack","_fatigueChance","_playerBloodPKeyFinal","_playerImmunityKeyFinal","_playerToxicityKeyFinal","_ppEffect","_say3dsoundsConfig","_selectedMove","_selectedSound","_soundConfigArray","_soundEffect","_soundEffectGlobal","_switchMovehandlerConfig","_target","_toxicAmount","_toxicChance"];
//[[[end]]]
params [["_unit",objNull],["_target",player]];
if (isNull _unit && isNull _target) exitWith {};
_doAttack = false;

// check if target is on foot
if (isNull objectParent _target) then {
	if (_target isEqualTo player) then {
		// handle attack for local player
		_doAttack = true;
	} else {
		// send attack to other player
		if (isPlayer _target) then {
			[_unit] remoteExec ["EPOCH_client_bitePlayer", _target];
		};
	};
} else {
	// target is inside a vehicle, target entire vehicle crew
	private _targets = [];
	{
		if (_x isEqualTo player) then {
			// handle attack for local player if inside vehicle
			_target = _x;
			_doAttack = true;
		} else {
			// send attack to other players
			if (isPlayer _x) then {
				_targets pushBack _x;
			};
		};
	} forEach (crew _target);
	if !(_targets isEqualTo []) then {
		[_unit] remoteExec ["EPOCH_client_bitePlayer", _targets];
	};
};

if (_doAttack) then {

	if !(isNull _unit && alive _unit) then {

		_cfgObjectInteraction = (('CfgObjectInteractions' call EPOCH_returnConfig) >> (typeOf _unit));
		if (isClass _cfgObjectInteraction) then {

			_distance = getNumber (_cfgObjectInteraction >> "distance");
			_toxicChance = getNumber (_cfgObjectInteraction >> "toxicChance");
			_bleedChance = getNumber (_cfgObjectInteraction >> "bleedChance");
			_bloodpChance = getNumber (_cfgObjectInteraction >> "bloodpChance");
			_fatigueChance = getNumber (_cfgObjectInteraction >> "fatigueChance");
			_bleedAmount = getNumber (_cfgObjectInteraction >> "bleedAmount");
			_bloodpAmount = getNumber (_cfgObjectInteraction >> "bloodpAmount");
			_toxicAmount = getNumber (_cfgObjectInteraction >> "toxicAmount");

			_soundConfigArray = getArray (_cfgObjectInteraction >> "soundEffect");
			_soundEffect = "";
			if !(_soundConfigArray isEqualTo []) then {
				_soundEffect = selectRandom _soundConfigArray;
			};
			_soundEffectGlobal = getNumber (_cfgObjectInteraction >> "soundEffectGlobal");
			_animConfigArray = getArray (_cfgObjectInteraction >> "animationEffect");
			_animationEffect = "";
			if !(_animConfigArray isEqualTo []) then {
				_animationEffect = selectRandom _animConfigArray;
			};
			_animationEffectGlobal = getNumber (_cfgObjectInteraction >> "animationEffectGlobal");
			_canSee = call compile (getText (_cfgObjectInteraction >> "canSee"));
			_ppEffect = getArray (_cfgObjectInteraction >> "ppEffect");

			if ((_unit distance player) < _distance && _canSee) then {

				_say3dsoundsConfig = 'CfgSay3Dhandler' call EPOCH_returnConfig;
				_switchMovehandlerConfig = 'CfgSwitchMovehandler' call EPOCH_returnConfig;

				if (_soundEffect isEqualType []) then {
					_soundEffect params ["_soundEffectFinal",["_soundEffectRange",0]];
					playSound3D [_soundEffectFinal, _unit, false, getPosASL _unit, 1, 1, _soundEffectRange];
				} else {
					_selectedSound = (_say3dsoundsConfig >> _soundEffect);
					if (isClass _selectedSound) then {
						_unit say3D _soundEffect;
						if (_soundEffectGlobal isEqualTo 1) then {
							[player, _unit, _soundEffect, Epoch_personalToken] remoteExec ["EPOCH_server_handle_say3D",2];
						};
					};
				};

				_selectedMove = (_switchMovehandlerConfig >> _animationEffect);
				if (isClass _selectedMove) then {
					_unit switchMove _animationEffect;
					if (_animationEffectGlobal isEqualTo 1) then {
						[player, _animationEffect, Epoch_personalToken, _unit] remoteExec ["EPOCH_server_handle_switchMove",2];
					};
				};

				if (random 1 < _toxicChance) then {
					_playerToxicityKeyFinal = "EPOCH_playerToxicity";
					_playerImmunityKeyFinal = "EPOCH_playerImmunity";
					if !(isNil "_playerToxicityKey") then {_playerToxicityKeyFinal = _playerToxicityKey};
					if !(isNil "_playerImmunityKey") then {_playerImmunityKeyFinal = _playerImmunityKey};
					[_playerToxicityKeyFinal,random(_toxicAmount - (missionNamespace getVariable [_playerImmunityKeyFinal, 0])),100,0] call EPOCH_fnc_setVariableLimited;
				};
				if (random 1 < _bleedChance) then {
					player setBleedingRemaining((getBleedingRemaining player) + _bleedAmount);
				};
				if (random 1 < _bloodpChance) then {
					_playerBloodPKeyFinal = "EPOCH_playerBloodP";
					if !(isNil "_playerBloodPKey") then {_playerBloodPKeyFinal = _playerBloodPKey};
					[_playerBloodPKeyFinal,_bloodpAmount,190,0] call EPOCH_fnc_setVariableLimited;
					if !(_ppEffect isEqualTo []) then {
						[_ppEffect] spawn EPOCH_fnc_spawnEffects;
					};
				};
				if (random 1 < _fatigueChance) then {
					player setFatigue 1;
				};
			};
		};
	};
};
