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
	if ((missionnamespace getvariable ["EPOCH_HandleDamageTimeOut",diag_ticktime]) > diag_ticktime) exitwith {};	// prevent multiple actions here
	switch _projectile do {
		case "B_EnergyPack": {
			EPOCH_HandleDamageTimeOut = diag_ticktime + 0.1;
			if (_source distance _unit > 10) exitwith {};
			if !(missionnamespace getvariable ["EPOCH_OldRevive",false]) then {
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
		};
		case "shell_12g_bb";
		case "bbag_pvc";
		case "xbow_tranq";
		case "tranq_dart": {
			if !(lifeState _unit == "INCAPACITATED") then {
				EPOCH_HandleDamageTimeOut = diag_ticktime + 1;
				_unit setUnconscious true;
				(["CfgEpochClient", "UnconsciousTime", [60,180]] call EPOCH_fnc_returnConfigEntryV2) params [["_mintime",60],["_maxtime",180]];
				EPOCH_UnconsciousTime = diag_ticktime + _mintime + (random (_maxtime - _mintime));
				["You are Knocked out for a while...",5] call Epoch_Message;
			};
		};
		case "B_Swing";
		case "B_Stick";
		case "B_Hatchet": {
			if !(lifeState _unit == "INCAPACITATED") then {
				if ((random 100) < (["CfgEpochClient", "UnconsciousChance", 30] call EPOCH_fnc_returnConfigEntryV2)) then {
					EPOCH_HandleDamageTimeOut = diag_ticktime + 1;
					_unit setUnconscious true;
					(["CfgEpochClient", "UnconsciousTime", [60,180]] call EPOCH_fnc_returnConfigEntryV2) params [["_mintime",60],["_maxtime",180]];
					EPOCH_UnconsciousTime = diag_ticktime + _mintime + (random (_maxtime - _mintime));
					["You are Knocked out for a while...",5] call Epoch_Message;
				};
			};
		};
	};
};
_damage
