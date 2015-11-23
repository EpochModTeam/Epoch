/*
3d sound system

Epoch Mod - EpochMod.com
All Rights Reserved.
*/
private["_range", "_nearBy", "_target", "_soundIndex", "_sound"];

if !([_this select 0, _this select 3] call EPOCH_server_getPToken) exitWith{};

_target = param [1,objNull];
if (isNull _target) exitWith {};
_soundIndex =  param [2,-1];
_sound = EPOCH_sounds param [_soundIndex,-1];

if !(_sound isEqualTo -1) then {
	_range = getNumber(configFile >> "CfgSay3Dhandler" >> _sound >> "distance");
	_nearBy = _target nearEntities [["Epoch_Male_F","Epoch_Female_F","LandVehicle","Ship","Air","Tank"], _range];
	{
		if (isPlayer _x) then {
			[["say3D", [_target, _soundIndex]], owner _x] call EPOCH_sendPublicVariableClient
		}
	}forEach (_nearBy - [_this select 0]); //_this select 0 == the caller, play the sound already locally!
};
