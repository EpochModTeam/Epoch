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
while {_hiveMakeCall} do {

	_hiveMakeCall = false;

	// get 8k chars
	_currentIndexMax = _currentIndex + 8000;
	_hiveResponse = "epochserver" callExtension format["220|%1:%2|%3|%4", _prefix, _key, _currentIndex, (_currentIndexMax-1)];

	if (_hiveResponse != "") then {

		_hiveResponse = call compile _hiveResponse;
		if !(isNil "_hiveResponse") then{

			if (_hiveResponse isEqualType [] && !(_hiveResponse isEqualTo[])) then{

				_hiveStatus = _hiveResponse select 0;
				if (_hiveStatus == 1) then{

					_data = _hiveResponse select 1;

					if !(_data isEqualTo []) then{

						// add data to string
						_hiveMessage = _hiveMessage + _data;

						// if data returned is exactly 8k chars then we likely need to make another call
						if (count _data == 8000) then{
							_currentIndex = _currentIndexMax;
							_hiveMakeCall = true;
						};
					};
				};
			};
		};
	};
};

if (_hiveStatus == 1) then{
	_hiveMessage = call compile _hiveMessage;
	if (isNil "_hiveMessage") then{ _hiveMessage = []; }
};

[_hiveStatus, _hiveMessage]
