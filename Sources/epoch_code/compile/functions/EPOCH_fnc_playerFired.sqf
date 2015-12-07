/*
	Author: Aaron Clark - EpochMod.com

    Contributors:

	Description:
	Weapon fired handler

    Licence:
    Arma Public License Share Alike (APL-SA) - https://www.bistudio.com/community/licenses/arma-public-license-share-alike

    Github:
    https://github.com/EpochModTeam/Epoch/tree/master/Sources/epoch_code/compile/functions/EPOCH_fnc_playerFired.sqf

    Example:
    player addEventHandler ["Fired", {_this call EPOCH_fnc_playerFired}];

    Parameter(s):
		_this select 0: unit: Object - Object the event handler is assigned to
		_this select 1: weapon: String - Fired weapon
		_this select 2: muzzle: String - Muzzle that was used
		_this select 3: mode: String - Current mode of the fired weapon
		_this select 4: ammo: String - Ammo used
		_this select 5: magazine: String - magazine name which was used
		_this select 6: projectile: Object - Object of the projectile that was shot (Arma 2: OA and onwards)

	Returns:
	NOTHING
*/

private ["_highestDMG","_currentHIT","_currentDMG","_attachments","_newDMG","_cursorTarget","_repaired","_unit","_weapon","_ammo","_projectile"];
_unit = 		_this select 0;
_weapon = 		_this select 1;
_muzzle =		_this select 2;
_mode =			_this select 3;
_ammo = 		_this select 4;
_magazine =		_this select 5;
_projectile = 	_this select 6;

switch true do {
	case (_ammo isKindOf "B_EnergyPack"): {
		// diag_log format["DEBUG AMMO: %1", _ammo];
		if (!isNull cursorTarget) then {
			_cursorTarget = cursorTarget;
			_repaired = false;
			if ((player distance _cursorTarget) <= 6) then {

				_attachments = handgunItems player;
				_heal = false;

				if (_cursorTarget isKindOf "Man") then {
					if ("Heal_EPOCH" in _attachments) then {
						_heal = true;
					};

					if ("Defib_EPOCH" in _attachments) then {
						if (!alive _cursorTarget) then {
							EPOCH_revivePlayer_PVS = [_cursorTarget,player,Epoch_personalToken];
							publicVariableServer "EPOCH_revivePlayer_PVS";
						};
					};
				} else {
					if ("Repair_EPOCH" in _attachments) then {
						_heal = true;
					};
				};
				if (_heal) then {
					_highestDMG = 0;
					_currentHIT = -1;
					_currentDMG = 0;
					{
						_currentDMG = _x;
						if (_currentDMG > _highestDMG) then{
							_highestDMG = _currentDMG;
							_currentHIT = _forEachIndex;
						};
					}forEach((getAllHitPointsDamage _cursorTarget) param[2,[]]);

					if (_highestDMG > 0) then {

						_newDMG = ((_highestDMG - 0.5) max 0);

						if (local _cursorTarget) then {
							[_cursorTarget,[_currentHIT,_newDMG]] call EPOCH_client_repairVehicle;
						} else {
							EPOCH_repairVehicle_PVS = [_cursorTarget,[_currentHIT,_newDMG],player,Epoch_personalToken];
							publicVariableServer "EPOCH_repairVehicle_PVS";
						};

						//diag_log format["DEBUG HITPOINT REPAIRED: %1 %2 %3", _currentHIT, _newDMG, _attachments];
					} else {
						if ((damage _cursorTarget) > 0) then {
							EPOCH_repairVehicle_PVS = [_cursorTarget,["ALL",0],player,Epoch_personalToken];
							publicVariableServer "EPOCH_repairVehicle_PVS";
						};
					};
				};
			};
		};
	};

	case (_ammo isKindOf "B_Hatchet"): {
		_gesture = ["GestureSwing0", "GestureSwing1", "GestureSwing2"] select (floor(random 3));
		player playActionNow _gesture;
		call EPOCH_chopWood;
	};

	case (_ammo isKindOf "B_Swing" || _ammo isKindOf "B_Stick") : {
		player playActionNow "SledgeSwing";
		call EPOCH_mineRocks;
		if (_weapon isEqualTo "MeleeSword") then {
			call EPOCH_chopWood;
		};
		if (_weapon isEqualTo "MeleeRod") then {
			call EPOCH_fish;
		};
	};

	case (_ammo isKindOf "ChainSaw_Bullet"): {
		call EPOCH_chopWood;
	};

	default {
		_droneChance = 2;
		if !(EPOCH_nearestLocations isEqualTo[]) then{
			_droneChance = _droneChance * 2;
		};
		// reduce chance to spawn by 50% if weapon has silencer
		if (((player weaponAccessories _muzzle) select 0) != "") then{
			_droneChance = _droneChance / 2;
		};
		// 2% chance (+ 4% chance if in city) to spawn drone if shot fired (1% - 2% Half if using silencer)
		if (random EPOCH_droneRndChance < _droneChance) then{
			"I_UAV_01_F" call EPOCH_unitSpawnIncrease;
		};
	};
};
