/*
	Author: Aaron Clark - EpochMod.com

    Contributors: Andrew Gregory

	Description:
	Player death handler

    Licence:
    Arma Public License Share Alike (APL-SA) - https://www.bistudio.com/community/licenses/arma-public-license-share-alike

    Github:
    https://github.com/EpochModTeam/Epoch/tree/release/Sources/epoch_code/compile/functions/EPOCH_fnc_playerDeath.sqf

    Example:
    player addEventHandler ["Killed", {_this call EPOCH_fnc_playerDeath}];

    Parameter(s):
		_this select 0: OBJECT - player
		_this select 1: OBJECT - killer

	Returns:
	BOOL
*/
//[[[cog import generate_private_arrays ]]]
private ["_config","_doRevenge","_playerAliveTime","_playerAliveTimeKeyFinal","_playerDeathScreen","_playerKilledScreen","_playerRevengeMinAliveTime","_tapDiag"];
//[[[end]]]
params [["_unit",objNull,[objNull]],["_killer",objNull,[objNull]] ];
_config = 'CfgEpochClient' call EPOCH_returnConfig;
_playerDeathScreen = getText(_config >> "playerDeathScreen");
_playerRevengeMinAliveTime = getNumber(_config >> "playerRevengeMinAliveTime");
if (_playerDeathScreen isEqualTo "") then {_playerDeathScreen = "TapOut"};
_tapDiag = _playerDeathScreen;

_playerAliveTimeKeyFinal = "EPOCH_playerAliveTime";
if !(isNil "_playerAliveTimeKey") then {_playerAliveTimeKeyFinal = _playerAliveTimeKey};
_playerAliveTime = missionNamespace getVariable [_playerAliveTimeKeyFinal,0];

_doRevenge = ((getNumber(_config >> "playerDisableRevenge") isEqualTo 0) && _playerAliveTime >= _playerRevengeMinAliveTime);

// test ejecting unit from vehicle if dead client side
if (vehicle _unit != _unit) then {
	_unit action["Eject", vehicle _unit];
};

// Close display 999 (BIS_fnc_guiMessage), as it prevent display 46 from closing -> kick to lobby
if (!isnull (finddisplay 999)) then {
	(finddisplay 999) closedisplay 0;
};

// save death position
profileNameSpace setVariable["EPOCHLastKnownDeath",[]];
_deathMarkerON = (getNumber(_config >> "playerDeathMarkerGPSOnly") isEqualTo 1);
if(_deathMarkerON && ('ItemGPS' in (assignedItems _unit)))then{
	profileNameSpace setVariable["EPOCHLastKnownDeath",getPos _unit];
};

// Check, if Player got killed by another Player (opponent) in his Base
_homekill = false;
if (_unit !=_killer) then {
	if (isplayer _killer) then {
		if !(_killer in (units (group Player))) then {
			_SupressBaseSpawnOnHomekillTime = ["CfgEpochClient", "SupressBaseSpawnOnHomekillTime", 0] call EPOCH_fnc_returnConfigEntryV2;
			if (_SupressBaseSpawnOnHomekillTime > 0) then {
				_jammer = nearestObjects[player, call EPOCH_JammerClasses, ["CfgEpochClient", "minJammerDistance", 650] call EPOCH_fnc_returnConfigEntryV2];
				if !(_jammer isEqualTo []) then {
					_nearestJammer = _jammer select 0;
					if ((_nearestJammer getVariable["BUILD_OWNER", "-1"]) in[getPlayerUID player, Epoch_my_GroupUID]) then {
						_CfgEpochClient = 'CfgEpochClient' call EPOCH_returnConfig;
						_JammerConfig = (_CfgEpochClient >> "CfgJammers" >> (typeof _nearestJammer));
						_buildingJammerRange = getnumber (_JammerConfig >> "buildingJammerRange");
						if (_unit distance _nearestJammer < _buildingJammerRange) then {
							_homekill = true;
							[format ["Base Spawn disabled for %1 minutes (killed in your Territory)",(_SupressBaseSpawnOnHomekillTime/60) tofixed 1],5] call Epoch_Message;
						};
					};
				};
			};
		};
	};
};

[player,_killer,toArray profileName,Epoch_personalToken,_homekill] remoteExec ["EPOCH_server_deadPlayer",2];

// disable build mode
EPOCH_buildMode = 0;
EPOCH_snapDirection = 0;
EPOCH_Target = objNull;

EPOCH_IsAutoRunning = false;

// playerKilledScreen
_playerKilledScreen = getText(_config >> "playerKilledScreen");
if (_playerKilledScreen isEqualTo "") then {_playerKilledScreen = "TapOut2"};
if(_doRevenge && player != _killer && (isPlayer _killer || isPlayer (effectiveCommander _killer)))then{_tapDiag = _playerKilledScreen};//TODO: vehicle check may not always be reliable

if (Epoch_canBeRevived) then {
	setPlayerRespawnTime 600;
	createDialog _tapDiag;
} else {
	setPlayerRespawnTime 15;
	["You can be just revived once per life!", 5,[[0,0,0,0.5],[1,0,0,1]]] call Epoch_message;
};

[_killer, _tapDiag] spawn{
	params ["_killer2","_tapDiag2"];
	while {!alive player} do {
		if (playerRespawnTime <= 1) exitWith{ (findDisplay 46) closeDisplay 0; };
		if (playerRespawnTime > 15 && !dialog) then {createDialog _tapDiag2;};
		if (isObjectHidden player) then {closeDialog 2;};
		if(player getVariable["EPOCH_doBoom",false])exitWith{player setVariable ["EPOCH_doBoom",nil]; call EPOCH_fnc_playerDeathDetonate;};
		if(player getVariable["EPOCH_doMorph",false])exitWith{player setVariable ["EPOCH_doMorph",nil];[selectRandom (getArray (getMissionConfig "CfgEpochClient" >> "deathMorphClass")),player,_killer2] call EPOCH_fnc_playerDeathMorph;};
		uiSleep 0.1;
	};
};
