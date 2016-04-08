/*
	Author: Aaron Clark - EpochMod.com

    Contributors:

	Description:
	Hive Get Data

    Licence:
    Arma Public License Share Alike (APL-SA) - https://www.bistudio.com/community/licenses/arma-public-license-share-alike

    Github:
    https://github.com/EpochModTeam/Epoch/tree/master/Sources/epoch_server_core/compile/epoch_hive/fn_server_hiveGET.sqf
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
		if !(isNil "_hiveResponse") then {

			if (_hiveResponse isEqualType [] && !(_hiveResponse isEqualTo [])) then {
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
