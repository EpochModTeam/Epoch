/*
	Author: Aaron Clark - EpochMod.com

    Contributors:

	Description:
	Performs damage related effects

    Licence:
    Arma Public License Share Alike (APL-SA) - https://www.bistudio.com/community/licenses/arma-public-license-share-alike

    Github:
    https://github.com/EpochModTeam/Epoch/tree/master/Sources/epoch_code/compile/environment/EPOCH_client_bitePlayer.sqf

    Example:
    [cursorTarget,_index] call EPOCH_upgradeBUILD;

    Parameter(s):
		_this: OBJECT - Player

	Returns:
	NOTHING
*/
private ["_distance","_toxicChance","_bloodpChance","_fatigueChance","_bleedAmount","_bloodpAmount","_soundEffect","_canSee","_ppEffect","_bleedChance","_soundEffectIndex","_soundEffectGlobal"];
if !(isNull _this && alive _this) then {

	_distance = 5;
	_toxicChance = 0.1;
	_bleedChance = 1;
	_bloodpChance = 0;
	_fatigueChance = 0.1;

	_bleedAmount = 30;
	_bloodpAmount = 2;

	_soundEffect = -1;
	_soundEffectGlobal = false;
	_canSee = false;
	_ppEffect = 0;

	switch (typeOf _this) do {
		case "Snake_random_EPOCH": {
			_distance = 3;
			_toxicChance = 0.2;
			_bloodpChance = 1;
			_fatigueChance = 0.5;
			_bleedAmount = 30;
			_bloodpAmount = 3;
			_soundEffect = "snake_bite0";
			_canSee = !(lineIntersects[eyePos _this, aimPos player, _this, player]);
			_ppEffect = 0;
		};
		case "Snake2_random_EPOCH": {
			_distance = 3;
			_toxicChance = 0.1;
			_bloodpChance = 1;
			_fatigueChance = 0.5;
			_bleedAmount = 30;
			_bloodpAmount = 3;
			_soundEffect = "snake_bite0";
			_canSee = !(lineIntersects[eyePos _this, aimPos player, _this, player]);
			_ppEffect = 0;
		};
		case "GreatWhite_F": {
			_distance = 6;
			_toxicChance = 0;
			_bleedChance = 1;
			_bloodpChance = 1;
			_fatigueChance = 1;
			_bleedAmount = 100;
			_bloodpAmount = 3;
			_canSee = true;
			_ppEffect = 0;
		};
		case "SmokeShellCustom": {
			_distance = 6;
			_toxicChance = 1;
			_bleedChance = 0;
			_bloodpChance = 1;
			_fatigueChance = 1;
			_bleedAmount = 0;
			_bloodpAmount = 3;
			_canSee = true;
			_ppEffect = 0;
		};
		case "Epoch_Cloak_F": {
			_distance = 30;
			_toxicChance = 0;
			_bloodpChance = 0.9;
			_fatigueChance = 0.5;
			_bleedAmount = 66;
			_bloodpAmount = 3;
			_soundEffect = "cultist_nearby";
			_canSee = !(lineIntersects[eyePos _this, aimPos player, _this, player]);
			_ppEffect = 1;
		};
	};

	if ((_this distance player) < _distance && _canSee) then {
		_soundEffectIndex = EPOCH_sounds find _soundEffect;
		if (_soundEffectIndex != -1) then {
			_this say3D _soundEffect;
			if (_soundEffectGlobal) then {
				_say3D_PVS = [player, _this, _soundEffectIndex, Epoch_personalToken];
				_say3D_PVS remoteExec ["EPOCH_server_handle_say3D",2];
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
