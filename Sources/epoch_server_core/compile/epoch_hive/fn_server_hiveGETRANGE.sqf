/*
	Author: Aaron Clark - EpochMod.com

    Contributors:

	Description:
	Hive Get Getrange

    Licence:
    Arma Public License Share Alike (APL-SA) - https://www.bistudio.com/community/licenses/arma-public-license-share-alike

    Github:
    https://github.com/EpochModTeam/Epoch/tree/release/Sources/epoch_server_core/compile/epoch_hive/fn_server_hiveGETRANGE.sqf
*/
private["_hiveResponse", "_hiveStatus", "_hiveMessage", "_currentIndex", "_hiveMakeCall", "_data"];
params ["_prefix","_key"];

_hiveMessage = "";
_hiveStatus = 0;
_currentIndex = 0;
_hiveMakeCall = true;
_hiveCharCount = 10000; // get 10k chars
while {_hiveMakeCall} do {
    _hiveMakeCall = false;
	// get 10k chars
	_currentIndexMax = _currentIndex + _hiveCharCount;
	_hiveResponse = "epochserver" callExtension format["220|%1:%2|%3|%4", _prefix, _key, _currentIndex, (_currentIndexMax-1)];
    if !(_hiveResponse isEqualTo "") then {
        _hiveResponse = call compile _hiveResponse;
        _hiveResponse params [
            ["_status", 0],
            ["_data", []]
        ];
        if (_status isEqualTo 1 && !(_data isEqualTo [])) then{
            // add data to string
            _hiveStatus = _status;
            _hiveMessage = _hiveMessage + _data;
            // if data returned matches exactly _hiveCharCount then we likely need to make another call
            if (count _data == _hiveCharCount) then{
                _currentIndex = _currentIndexMax;
                _hiveMakeCall = true;
            };
        };
    };
};

// avoid parse if data is blank and return empty array
_hiveMessage = if (_hiveMessage isEqualTo "") then {[]} else {parseSimpleArray _hiveMessage};

[_hiveStatus, _hiveMessage]
