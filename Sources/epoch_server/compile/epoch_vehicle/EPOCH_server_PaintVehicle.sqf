private ["_ok"];
_ok = true;
params [["_vehicle",objnull],["_PaintingCosts",0],["_textures",[]],["_player",objnull],["_token","",[""]]];
if !([_player,_token] call EPOCH_server_getPToken) exitWith {};
if (isnull _vehicle) exitwith {};
if (_Textures isEqualTo []) exitwith {};
if(_PaintingCosts > 0)then{
	_cIndex = EPOCH_customVars find "Crypto";
	_vars = _player getVariable["VARS", call EPOCH_defaultVars_SEPXVar];
	_current_crypto = _vars select _cIndex;
	if (_current_crypto < _PaintingCosts) exitwith {
		_ok = false;
	};
	_playerCryptoLimit = EPOCH_customVarLimits select _cIndex;
	_playerCryptoLimit params ["_playerCryptoLimitMax","_playerCryptoLimitMin"];
	_current_crypto = ((_current_crypto - _PaintingCosts) min _playerCryptoLimitMax) max _playerCryptoLimitMin;
	_current_crypto remoteExec ['EPOCH_effectCrypto',_player];
	_vars set[_cIndex, _current_crypto];
	_player setVariable["VARS", _vars];
};
if (_ok) then {
	{
		_vehicle SetObjectTextureGlobal _x;
	} foreach _Textures;
	_vehicle setVariable ["VEHICLE_TEXTURE", -1];
	EPOCH_saveVehQueue pushBackUnique _vehicle;
};
