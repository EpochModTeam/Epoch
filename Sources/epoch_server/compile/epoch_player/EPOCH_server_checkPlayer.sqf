/*
Player Check

Epoch Mod - EpochMod.com
All Rights Reserved.
*/
private["_arr", "_dead", "_isMale", "_medical", "_apperance", "_class", "_vars", "_hitpoints", "_deadPlayer", "_response", "_plyrUID", "_plyrObj"];

if (typename _this == "OBJECT") then {
	_plyrObj = _this;
	if (!isNull _plyrObj) then {
		_plyrUID = getPlayerUID _plyrObj;
		if (_plyrUID != "") then {

			_response = ["Player", _plyrUID] call EPOCH_fnc_server_hiveGETRANGE;

			_dead = false;
			_isMale = true;

			_arr = [];
			if ((_response select 0) == 1 && typeName(_response select 1) == "ARRAY") then {
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

				_deadPlayer = ["PlayerStats", _plyrUID, 0] call EPOCH_fnc_server_hiveGETBIT;

				if (_deadPlayer || (_medical select 3 == 1) || (_hitpoints select 2 == 1) || (_hitpoints select 3 == 1) || (_vars select 12 >= 180)) then {
					_dead = true;
				};
			};
			/* true => New Char
			   false => load old Char */
			EPOCH_checkPlayer_PVC = _dead;
			(owner _plyrObj) publicVariableClient "EPOCH_checkPlayer_PVC";

			if (!_dead) then { //Load old Char
				[_plyrObj, _isMale] call EPOCH_server_loadPlayer;
			};
		};
	};
};