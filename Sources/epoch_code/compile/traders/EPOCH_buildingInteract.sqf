

lbClear 1550;

_class = configFile >> "CfgVehicles" >> (typeOf EPCH);

if (isclass _class) then {

	_useractions = _class >> "UserActions";
	if (isclass _useractions) then {

		_uniqueActions = [];

		for "_u" from 0 to (count _useractions - 1) do {

			_action = _useractions select _u;
			_displayname = gettext (_action >> "displayname");

			_position = gettext (_action >> "position");

			_uniqueActions pushBackUnique _position;


			_condition = gettext (_action >> "condition");
			_statement = gettext (_action >> "statement");

			_condition = [_condition,"this","EPCH"] call EPOCH_replaceWord;
			_statement = [_statement,"this","EPCH"] call EPOCH_replaceWord;

			if (call compile _condition) then {
				_index = lbAdd[1550,_displayname];
				lbSetData [1550, _index,_statement];
			};
		};

		{
			_doorIndex = _forEachIndex + 1;
			_disabledDoor = EPCH getVariable [format["bis_disabled_Door_%1",_doorIndex],0];

			//diag_log format["DEBUG DOORS: %1 %2", _doorIndex, _disabledDoor];

			if (_disabledDoor == 0) then {
				_index = lbAdd[1550,"Lock Door"];
				_unlock = format["EPCH setVariable ['bis_disabled_Door_%1',1,true];",_doorIndex];
				lbSetData [1550, _index,_unlock];
			} else {
				_index = lbAdd[1550,"Unlock Door"];
				_unlock = format["EPCH setVariable ['bis_disabled_Door_%1',0,true];",_doorIndex];
				lbSetData [1550, _index,_unlock];
			};

		} foreach _uniqueActions;

	};
};
