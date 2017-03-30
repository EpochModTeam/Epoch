/*
	Author: Aaron Clark - EpochMod.com

    Contributors:

	Description:
	Hive Get Data

    Licence:
    Arma Public License Share Alike (APL-SA) - https://www.bistudio.com/community/licenses/arma-public-license-share-alike

    Github:
    https://github.com/EpochModTeam/Epoch/tree/release/Sources/epoch_server_core/compile/epoch_hive/fn_server_hiveGET.sqf
*/

private ["_hiveResponse","_hiveStatus","_hiveMessage"];
params ["_prefix","_key"];

_hiveStatus = -1;
_hiveMessage = "";

while {_hiveStatus < 0 || _hiveStatus == 2} do {
	_hiveResponse = "epochserver" callExtension format ["200|%1:%2", _prefix, _key];
	_hiveStatus = 0;
	if (_hiveResponse != "") then {
		_hiveResponse = call compile _hiveResponse;
        _hiveResponse params [
            ["_status", 0],
            ["_data", ""]
        ];
		_hiveStatus = _status;
		if (_hiveStatus >= 1) then {
			_hiveMessage = _hiveMessage + _data;
		};
	};
};

// note: removed check for null in array _hiveMessage find "<null>" == -1
_hiveMessage = if (_hiveMessage isEqualTo "") then {[]} else {parseSimpleArray _hiveMessage};

[_hiveStatus, _hiveMessage]
