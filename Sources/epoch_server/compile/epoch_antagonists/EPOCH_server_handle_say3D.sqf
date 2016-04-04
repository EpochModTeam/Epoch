/*
	Author: Aaron Clark - EpochMod.com

    Contributors:

	Description:
    3d Sound System

    Licence:
    Arma Public License Share Alike (APL-SA) - https://www.bistudio.com/community/licenses/arma-public-license-share-alike

    Github:
    https://github.com/EpochModTeam/Epoch/tree/master/Sources/epoch_server/compile/epoch_antagonists/EPOCH_server_handle_say3D.sqf
*/
private["_range", "_nearBy", "_sound"];
params ["_player",["_target",objNull],["_soundIndex",-1], ["_token","",[""]]];

if !([_player, _token] call EPOCH_server_getPToken) exitWith{};
if (isNull _target) exitWith {};

_sound = EPOCH_sounds param [_soundIndex,-1];
if !(_sound isEqualTo -1) then {
	_range = getNumber(configFile >> "CfgSay3Dhandler" >> _sound >> "distance");
	_nearBy = _target nearEntities [["Epoch_Male_F","Epoch_Female_F","LandVehicle","Ship","Air","Tank"], _range];
	{
		if (isPlayer _x) then {
			[_target,_sound] remoteExec ['say3D',_x];
		}
	}forEach (_nearBy - [_player]); //_this select 0 == the caller, play the sound already locally!
};
