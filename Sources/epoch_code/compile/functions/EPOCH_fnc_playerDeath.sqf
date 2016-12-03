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
private ["_Epoch_PlayerRespawnTime","_config","_doRevenge","_playerDeathScreen","_playerKilledScreen","_playerRevengeMinAliveTime","_tapDiag"];
//[[[end]]]
params [["_unit",objNull,[objNull]],["_killer",objNull,[objNull]] ];
_config = 'CfgEpochClient' call EPOCH_returnConfig;
_playerDeathScreen = getText(_config >> "playerDeathScreen");
_playerRevengeMinAliveTime = getNumber(_config >> "playerRevengeMinAliveTime");
if (_playerDeathScreen isEqualTo "") then {_playerDeathScreen = "TapOut"};
_tapDiag = _playerDeathScreen;
// diag_log format ["DEBUG: EPOCH_playerAliveTime %1",EPOCH_playerAliveTime];
_doRevenge = ((getNumber(_config >> "playerDisableRevenge") isEqualTo 0) && EPOCH_playerAliveTime >= _playerRevengeMinAliveTime);
 
// test ejecting unit from vehicle if dead client side
if (vehicle _unit != _unit) then {
    _unit action["Eject", vehicle _unit];
};
 
[player,_killer,toArray profileName,Epoch_personalToken] remoteExec ["EPOCH_server_deadPlayer",2];
 
// disable build mode
EPOCH_buildMode = 0;
EPOCH_snapDirection = 0;
EPOCH_Target = objNull;
 
// playerKilledScreen
_playerKilledScreen = getText(_config >> "playerKilledScreen");
if (_playerKilledScreen isEqualTo "") then {_playerKilledScreen = "TapOut2"};
if(_doRevenge && player != _killer && (isPlayer _killer || isPlayer (effectiveCommander _killer)))then{_tapDiag = _playerKilledScreen};//TODO: vehicle check may not always be reliable
 
if (Epoch_canBeRevived) then {
	setPlayerRespawnTime 600;
    _Epoch_PlayerRespawnTime = 600;
    createDialog _tapDiag;
} else {
	setPlayerRespawnTime 15;
    _Epoch_PlayerRespawnTime = 15;
    ["You can be just revived once per life!", 5] call Epoch_message;
};
 
[_killer, _tapDiag, _Epoch_PlayerRespawnTime] spawn{
    params ["_killer2","_tapDiag2","_Epoch_PlayerRespawnTime"];
    while {!alive player} do {
        _Epoch_PlayerRespawnTime = _Epoch_PlayerRespawnTime - 0.1;
        if (playerRespawnTime < 0) then {
            _Layer = 'RespawnTimer' call BIS_fnc_rscLayer;
            _txt = format ["<t color='#FFFFFF' align = 'center' size = '1'>Respawn in %1 seconds</t>",round _Epoch_PlayerRespawnTime];
            [_txt,0,0.75*safezoneH+safezoneY,0,0,0,_Layer] spawn bis_fnc_dynamicText;
        };
        if (_Epoch_PlayerRespawnTime <= 1) exitWith{ (findDisplay 46) closeDisplay 0; };
        if (_Epoch_PlayerRespawnTime > 15 && !dialog) then {createDialog _tapDiag2;};
        if (isObjectHidden player) then {closeDialog 2;};
        if(player getVariable["EPOCH_doBoom",false])exitWith{player setVariable ["EPOCH_doBoom",nil]; call EPOCH_fnc_playerDeathDetonate;};
        if(player getVariable["EPOCH_doMorph",false])exitWith{player setVariable ["EPOCH_doMorph",nil];[selectRandom (getArray (getMissionConfig "CfgEpochClient" >> "deathMorphClass")),player,_killer2] call EPOCH_fnc_playerDeathMorph;};
        uiSleep 0.1;
    };
};
if(!isNil'BIS_DeathBlur')then{ppEffectDestroy BIS_DeathBlur;};
