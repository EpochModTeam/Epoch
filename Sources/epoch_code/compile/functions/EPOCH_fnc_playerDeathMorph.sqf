/*
	Author: Andrew Gregory - EpochMod.com

    Contributors:

	Description:
	Morph dead player body into an antagonist, called from player death GUI. Dead player camera will attach to antagonist.

    Licence:
    Arma Public License Share Alike (APL-SA) - https://www.bistudio.com/community/licenses/arma-public-license-share-alike

    Github:
    https://github.com/EpochModTeam/Epoch/tree/release/Sources/epoch_code/compile/functions/EPOCH_fnc_playerDeathMorph.sqf

    Example:
    [] call EPOCH_fnc_playerDeathMorph;

    Parameter(s):
	_this select 0: STRING - Antagonist class
	_this select 1: OBJECT - Player (Victim)
	_this select 2: OBJECT - Target Player (Killer)

	Returns:
*/
params ["_antagonistClass", "_player", "_killer"];

openmap [false,false];
[_killer,_antagonistClass,true,_player, Epoch_personalToken] remoteExec ["EPOCH_server_triggerAntagonist",2];

[_killer,_player] spawn{
_killer2 = _this select 0;
_player2 = _this select 1;
	while {!alive player} do {
		if (isObjectHidden _player2) then {closeDialog 2;};
		if!(isNull (_killer2 getVariable["EPOCH_antagObj",objNull])) exitWith {closeDialog 2;[_player2,(_killer2 getVariable["EPOCH_antagObj",objNull]),(_killer2 getVariable["EPOCH_antagBomb",objNull]),_killer2] call EPOCH_fnc_playerAttachToAntagonist;};
		uiSleep 0.1;
	};
};
