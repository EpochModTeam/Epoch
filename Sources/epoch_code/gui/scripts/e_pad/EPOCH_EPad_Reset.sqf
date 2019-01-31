_cfg = "e_pad_config" call EPOCH_returnConfig;
_startvars = getarray (_cfg >> "LoadVarsFromProfile");
{
	_x params ["_varname",["_default","false",[""]]];
	if (_varname isequaltype "" && !(_varname isequalto "")) then {
		_value = if ((tolower _default) isequalto "true") then {true} else {false};
		missionnamespace setvariable [_varname,_value];
	};
} foreach _startvars;
profilenamespace setvariable ["Epoch_ToggleVars",nil];
saveprofilenamespace;
hintsilent "";
["E-Pad settings resetted",5] call epoch_message;
