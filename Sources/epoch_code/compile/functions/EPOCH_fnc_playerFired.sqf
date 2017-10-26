/*
	Author: Aaron Clark - EpochMod.com

    Contributors:

	Description:
	Weapon fired handler

    Licence:
    Arma Public License Share Alike (APL-SA) - https://www.bistudio.com/community/licenses/arma-public-license-share-alike

    Github:
    https://github.com/EpochModTeam/Epoch/tree/release/Sources/epoch_code/compile/functions/EPOCH_fnc_playerFired.sqf

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
//[[[cog import generate_private_arrays ]]]
private ["_ammoConfig","_attachments","_currentDMG","_currentHIT","_cursorTarget","_gesture","_heal","_highestDMG","_newDMG","_nuisanceLevel","_playerNuisanceKeyFinal","_repaired"];
//[[[end]]]
params ["_unit","_weapon","_muzzle","_mode","_ammo","_magazine","_projectile"];
EPOCH_lastFiredLocation = getPosATL player;
switch true do {
	case (_ammo isKindOf "B_EnergyPack"): {
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
							[_cursorTarget,player,Epoch_personalToken] remoteExec ["EPOCH_server_revivePlayer",2];
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
						if (EPOCH_AdvancedVehicleRepair_Enabled) then {
							if (_cursorTarget iskindof "Landvehicle" || _cursorTarget iskindof "SHIP" || _cursorTarget iskindof "AIR" || _cursorTarget iskindof "TANK") then {
								if (_currentDMG > 0.9) then {
									_currentDMG = 0;
								};
							};
						};
						if (_currentDMG > _highestDMG) then{
							_highestDMG = _currentDMG;
							_currentHIT = _forEachIndex;
						};
					}forEach((getAllHitPointsDamage _cursorTarget) param[2,[]]);
					if (_highestDMG > 0) then {
						_newDMG = ((_highestDMG - 0.5) max 0);
						if (local _cursorTarget) then {
							[_cursorTarget,[[_currentHIT,_newDMG]]] call EPOCH_client_repairVehicle;
						} else {
							[_cursorTarget,[[_currentHIT,_newDMG]],player,Epoch_personalToken] remoteExec ["EPOCH_server_repairVehicle",2];
						};
					} else {
						if ((damage _cursorTarget) > 0) then {
							[_cursorTarget,["ALL",0],player,Epoch_personalToken] remoteExec ["EPOCH_server_repairVehicle",2];
						};
					};
				};
			};
		};
	};
	case (_ammo isKindOf "B_Hatchet"): {
		_gesture = selectRandom ["GestureSwing0", "GestureSwing1", "GestureSwing2"];
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
		_ammoConfig = (configFile >> "CfgAmmo" >> _ammo);
		_nuisanceLevel = ceil(getNumber (_ammoConfig >> "audibleFire") * getNumber (_ammoConfig >> "caliber"));
		// reduce when not in a city or town
		if (EPOCH_nearestLocations isEqualTo[]) then{
			_nuisanceLevel = _nuisanceLevel / 2;
		};
		// reduce if using a silencer
		if (((player weaponAccessories _muzzle) select 0) != "") then{
			_nuisanceLevel = _nuisanceLevel / 2;
		};
		// Nuisance System 0.1
		(EPOCH_customVarLimits select (EPOCH_customVars find "Nuisance")) params [["_playerLimitMax",100],["_playerLimitMin",0]];
		_playerNuisanceKeyFinal = "EPOCH_playerNuisance";
		if !(isNil "_playerNuisanceKey") then {_playerNuisanceKeyFinal = _playerNuisanceKey};
		[_playerNuisanceKeyFinal,_nuisanceLevel,_playerLimitMax,_playerLimitMin] call EPOCH_fnc_setVariableLimited;
	};
};
