private ["_result","_object","_newOwner"];
_object = _this select 0;
_newOwner = owner (_this select 1);
_result = false;
if (!isNull _object) then {
	if (local _object) then {
		if ((owner _object) != _newOwner) then {
			_result = _object setOwner _newOwner;
			diag_log format["DEBUG CHANGEOWNER: %1 OWNER: %2 PLAYER: %3 RESULT: %4", _object,owner(_object),_newOwner,_result];
		};
	};
};
_result