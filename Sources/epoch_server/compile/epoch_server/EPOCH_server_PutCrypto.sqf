/*
	Author: He-Man - EpochMod.com

    Contributors:

	Description: Puts Crypto Items on the Ground

    Licence:
    Arma Public License Share Alike (APL-SA) - https://www.bistudio.com/community/licenses/arma-public-license-share-alike

    Github:
    https://github.com/EpochModTeam/Epoch/tree/release/Sources/epoch_server\compile\epoch_server\EPOCH_server_PutCrypto.sqf

	Usage:
	[player,_value,Epoch_personalToken] remoteexec ['EPOCH_server_PutCrypto',2]

	RETURNS: NOTHING
*/

private ["_cIndex","_vars","_current_crypto","_pos","_dist","_direction","_randomPos","_itemclass","_var","_item"];
params ["_player","_Putcrypto",["_token","",[""]]];
diag_log format ["PutCrypto Server Side - %1",_this];
if !([_player, _token] call EPOCH_server_getPToken) exitWith{};
_cIndex = EPOCH_customVars find 'Crypto';
_vars = _player getVariable['VARS', call EPOCH_defaultVars_SEPXVar];
_current_crypto = _vars select _cIndex;
if (_current_crypto < _Putcrypto) exitwith {
	["Not enough money",5] remoteexec ["Epoch_Message",_player];
};
_current_crypto = _current_crypto - _Putcrypto;
_vars set[_cIndex, _current_crypto];
_player setVariable['VARS', _vars];
_current_crypto remoteExec ['EPOCH_effectCrypto',_player];
[format ["You put %1 Crypto on the Ground",_Putcrypto],5] remoteexec ["Epoch_Message",_player];
[_player,_vars,_token] call EPOCH_fnc_savePlayer;
_pos = getposatl _player;
while {_Putcrypto > 0} do {
	_itemclass = if (_Putcrypto >= 1000) then {"Land_Suitcase_F"} else {"Land_Money_F"};
	_var = if (_Putcrypto >= 1000) then {1000} else {_Putcrypto min 100};
	_Putcrypto = _Putcrypto - _var;
	_item = createVehicle [_itemclass,_pos,[],1,"CAN_COLLIDE"];
	_item setvariable ["RemoveOnTake",true];
	_item allowdamage false;
	_item enablesimulationglobal false;
	_item setvariable ["Crypto",_var,true];
};
