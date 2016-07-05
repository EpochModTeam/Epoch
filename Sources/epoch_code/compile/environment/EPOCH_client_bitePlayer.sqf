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
private ["_distance","_toxicChance","_bloodpChance","_fatigueChance","_bleedAmount","_bloodpAmount","_soundEffect","_canSee","_ppEffect","_bleedChance","_soundEffectIndex","_soundEffectGlobal","_animationEffect","_animationEffectGlobal","_cfgObjectInteraction"];
params [["_unit",objNull],["_target",player]];
if (isNull _unit && isNull _target) exitWith {};
if !(_target isEqualTo player) then {
	// re to other player
	[_unit,_target] remoteExec ["EPOCH_client_bitePlayer", _target];
} else {

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

			_soundConfigArray = getArray (_cfgObjectInteraction >> "soundEffect");
			if !(_soundConfigArray isEqualTo []) then {
				_soundEffect = selectRandom _soundConfigArray;
			};
			_soundEffectGlobal = getNumber (_cfgObjectInteraction >> "soundEffectGlobal");
			_animConfigArray = getArray (_cfgObjectInteraction >> "animationEffect");
			if !(_animConfigArray isEqualTo []) then {
				_animationEffect = selectRandom _animConfigArray;
			};
			_animationEffectGlobal = getNumber (_cfgObjectInteraction >> "animationEffectGlobal");
			_canSee = call compile (getText (_cfgObjectInteraction >> "canSee"));
			_ppEffect = getNumber (_cfgObjectInteraction >> "ppEffect");

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
					EPOCH_playerToxicity = (EPOCH_playerToxicity + (random(100 - EPOCH_playerImmunity))) min 100;
				};
				if (random 1 < _bleedChance) then {
					player setBleedingRemaining((getBleedingRemaining player) + _bleedAmount);
				};
				if (random 1 < _bloodpChance) then {
					EPOCH_playerBloodP = (EPOCH_playerBloodP + (_bloodpAmount + (EPOCH_playerBloodP - 100))) min 190;
					// todo configize
					if (_ppEffect == 1) then {
						[] spawn{
							_ppGrain = ppEffectCreate["filmGrain", 2005];
							_ppChrom = ppEffectCreate["chromAberration", 2006];
							_ppColor = ppEffectCreate["colorCorrections", 2007];
							_ppBlur = ppEffectCreate["radialBlur", 2008];
							_ppColor ppEffectAdjust[1, 1, 0, [1.5, -1, -1.5, 0.5], [5, 3.5, -5, -0.5], [-3, 5, -5, -0.5]];
							_ppColor ppEffectCommit 5;
							_ppChrom ppEffectAdjust[0.01, 0.01, true];
							_ppChrom ppEffectCommit 5;
							_ppBlur ppEffectAdjust[0.02, 0.02, 0.15, 0.15];
							_ppBlur ppEffectCommit 5;
							_ppGrain ppEffectAdjust[0.1, -1, 0.05, 0.05, 2, false];
							_ppGrain ppEffectCommit 1;
							_ppGrain ppEffectEnable true;
							_ppChrom ppEffectEnable true;
							_ppColor ppEffectEnable true;
							_ppBlur ppEffectEnable true;
							uiSleep 2;
							_ppColor ppEffectAdjust[1, 1, -0.01, [0.0, 0.0, 0.0, 0.0], [1.5, 1, 1.2, 0.6], [0.199, 0.587, 0.114, 0.20]];
							_ppColor ppEffectCommit 5;
							_ppChrom ppEffectAdjust[0, 0, true];
							_ppChrom ppEffectCommit 5;
							_ppBlur ppEffectAdjust[0, 0, 0, 0];
							_ppBlur ppEffectCommit 5;
							uiSleep 5;
							ppEffectDestroy[_ppGrain, _ppChrom, _ppColor, _ppBlur];
						};
					};
				};
				if (random 1 < _fatigueChance) then {
					player setFatigue 1;
				};
			};
		};
	};
};
