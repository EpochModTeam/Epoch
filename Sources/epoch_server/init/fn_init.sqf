if !(isNil "Epoch_SStart1") exitWith { false };
Epoch_SStart1 = true;

diag_log "Epoch: Init Compiles";

_returnConfig = {
	private["_return", "_config"];
	_return = (configfile >> _this);
	_config = (getMissionConfig _this);
	if (isClass _config) then{
	  _return = _config;
	};
	_return
};

_config = 'CfgServerFunctions' call _returnConfig;
_version = getNumber(_config >> "version");
if (_version == 1) then {
	{
		if (isClass(_x)) then {
			_tag = getText(_x >> "tag");
			_file = getText(_x >> "file");
			_file_tag = _file;
			_cat = "";
			{
				if (isClass(_x)) then {
					_file = _file_tag;
					_file_raw = getText(_x >> "file");
					if (_file_raw == "") then {
						_cat = configName _x;
						_file = _file + "\" + _cat;
					} else {
						_file = _file_raw;
					};
					{
						_var_name = _tag + "_" + configName _x;
						_fnc_path = _file + "\" + _var_name + ".sqf";
						_file_raw = getText(_x >> "file");
						if (_file_raw != "") then {
							_fnc_path = _file_raw;
						};
						_itemCompile = compileFinal preprocessFileLineNumbers _fnc_path;
						missionNamespace setvariable [_var_name,_itemCompile];
					} forEach ("isclass _x" configClasses (_x));
				}
			} forEach ("isclass _x" configClasses (_x));
		};
	} forEach ("isclass _x" configClasses (_config));
} else {
	diag_log "Error: CfgServerFunctions out of date.";
};

true
