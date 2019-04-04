/*
	Author: He-Man - EpochMod.com

    Contributors:

	Description:
	HandleDamage Eventhandler for A3 Epoch

    Licence:
    Arma Public License Share Alike (APL-SA) - https://www.bistudio.com/community/licenses/arma-public-license-share-alike

    Github:
    https://github.com/EpochModTeam/Epoch/tree/release/Sources/epoch_code/compile/EPOCH_HandleDamage.sqf
*/
params ["_unit", "_selection", "_damage", "_source", "_projectile", "_hitIndex", "_instigator", "_hitPoint"];
if !(_source isEqualTo _unit) then {
	switch _projectile do {
		case "B_EnergyPack": {
			if (_source distance _unit > 10) exitwith {};
			if (missionnamespace getvariable ["EPOCH_OldRevive",false]) exitwith {};
			if ((missionnamespace getvariable ["EPOCH_HandleDamageTimeOut",diag_ticktime]) > diag_ticktime) exitwith {};	// prevent multiple actions here
			EPOCH_HandleDamageTimeOut = diag_ticktime + 0.1;
			_attachments = handgunItems _source;
			if ("Heal_EPOCH" in _attachments) then {
				if (lifeState _unit == "INCAPACITATED") exitwith {
					EPOCH_HandleDamageTimeOut = diag_ticktime + 1;
					_unit setUnconscious false;
					_unit playMoveNow 'AmovPercMstpSnonWnonDnon';
				};
				_highestDMG = 0;
				_currentHIT = -1;
				_currentDMG = 0;
				{
					_currentDMG = _x;
					if (_currentDMG > _highestDMG) then{
						_highestDMG = _currentDMG;
						_currentHIT = _forEachIndex;
					};
				}forEach((getAllHitPointsDamage _unit) param[2,[]]);
				if (_highestDMG > 0) then {
					_newDMG = 0; 
					[_unit,[[_currentHIT,_newDMG]]] call EPOCH_client_repairVehicle;
				} else {
					if ((damage _unit) > 0) then {
						[_unit,["ALL",0],player,Epoch_personalToken] remoteExec ["EPOCH_server_repairVehicle",2];
					};
				};
			};
			if ("Defib_EPOCH" in _attachments) then {
				if !(alive _unit) then {
					EPOCH_HandleDamageTimeOut = diag_ticktime + 1;
					[_unit,_source,Epoch_personalToken] remoteExec ["EPOCH_server_revivePlayer",2];
				};
			};
		};
		case "B_KnockOut": {
			_unit setUnconscious true;
		};
	};
};
_damage
