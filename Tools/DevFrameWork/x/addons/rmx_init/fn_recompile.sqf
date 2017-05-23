//todo use param
private ["_fnc"];
_fnc = gettext (configfile >> "devFunctions" >> "init");
if (_fnc != "") then {
	if (typeName _this isEqualTo typeName "") then {
		_this call compile preprocessfilelinenumbers _fnc;
	} else {
		call compile preprocessfilelinenumbers _fnc;
	};
	true
} else {
	diag_log "Init param not found, check config pbo";
	false
};


