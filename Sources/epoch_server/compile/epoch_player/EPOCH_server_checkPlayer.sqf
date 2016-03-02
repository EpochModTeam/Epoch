/*
Player Check

Epoch Mod - EpochMod.com
All Rights Reserved.
*/
private["_arr", "_dead", "_isMale", "_medical", "_apperance", "_class", "_vars", "_hitpoints", "_deadPlayer", "_response", "_playerUID", "_playerObj"];

if (_this isEqualType objNull) then {
	_playerObj = _this;
	if (!isNull _playerObj) then {
		_playerUID = getPlayerUID _playerObj;
		if (_playerUID != "") then {

			_response = ["Player", _playerUID] call EPOCH_fnc_server_hiveGETRANGE;

			_dead = false;
			_isMale = true;

			_arr = [];
			if ((_response select 0) == 1 && (_response select 1) isEqualType []) then {
				_arr = (_response select 1);
			};

			if (count _arr < 11) then {
				_dead = true;
			} else {
				_medical = _arr select 1;
				_apperance = _arr select 2;
				_class = _apperance select 5;
				if (_class == "Epoch_Female_F") then {
					_isMale = false;
				};

				_vars = _arr select 4;
				_hitpoints = _vars select 11;

				_deadPlayer = ["PlayerStats", _playerUID, 0] call EPOCH_fnc_server_hiveGETBIT;

				if (_deadPlayer || (_medical select 3 == 1) || (_hitpoints select 2 == 1) || (_hitpoints select 3 == 1) || (_vars select 12 >= 180)) then {
					_dead = true;
				};
			};
			/* true => New Char
			   false => load old Char */
			['_checkPlayer_PVC', _dead] remoteExec ['EPOCH_playerLoginInit',_playerObj];

			if (!_dead) then { //Load old Char
				[_playerObj, _isMale] call EPOCH_server_loadPlayer;
			};
		};
	};
};
