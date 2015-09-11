/*
    Hive Expire
    by Aaron Clark - EpochMod.com

    This work is licensed under a Creative Commons Attribution-NonCommercial-NoDerivatives 4.0 International License.
    http://creativecommons.org/licenses/by-nc-nd/4.0/

    Improvements and or bugfixes and other contributions are welcome via the github:
    https://github.com/EpochModTeam/Epoch/tree/master/Sources/epoch_server_core/compile/epoch_hive/fn_server_hiveGET.sqf
*/

private ["_hiveResponse","_hiveStatus","_hiveMessage"];
//_PREFIX = _this select 0;
//_KEY = _this select 1;

_hiveStatus = -1;
_hiveMessage = "";

while {_hiveStatus < 0 || _hiveStatus == 2} do {
	_hiveResponse = "epochserver" callExtension format ["200|%1:%2", _this select 0, _this select 1];
	_hiveStatus = 0;
	if (_hiveResponse != "") then {
		_hiveResponse = call compile _hiveResponse;
		if !(isNil "_hiveResponse") then {
			if (typeName _hiveResponse == "ARRAY" && !(_hiveResponse isEqualTo [])) then {
				_hiveStatus = _hiveResponse select 0;
				if (_hiveStatus >= 1) then {
					_hiveMessage = _hiveMessage + (_hiveResponse select 1);
				};
			};
		};
	};
};

if (_hiveStatus > 0 && _hiveMessage find "<null>" == -1) then {
	_hiveMessage = call compile _hiveMessage;
	if (isNil "_hiveMessage") then { _hiveMessage = [];}
}
else {
	_hiveMessage = [];
};

[_hiveStatus, _hiveMessage]
