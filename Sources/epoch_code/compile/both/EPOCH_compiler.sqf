/*
	Author: Aaron Clark - EpochMod.com

    Contributors:

	Description:
	Custom functions compiler

    Licence:
    Arma Public License Share Alike (APL-SA) - https://www.bistudio.com/community/licenses/arma-public-license-share-alike

    Github:
    https://github.com/EpochModTeam/Epoch/tree/master/Sources/epoch_code/compile/both/EPOCH_compiler.sqf

    Example:
    "CfgServerFunctions" call EPOCH_fnc_compiler;
    or
    "CfgClientFunctions" call EPOCH_fnc_compiler;

    Parameter(s):
		_this: STRING - Config class name

	Returns:
	BOOL
*/
private ["_cat","_file","_fnc_path","_var_name","_file_raw","_itemCompile","_tag","_file_tag","_config","_returnConfig","_version"];
params [["_configName","",[""]]];

_returnConfig = {
	private["_return", "_config"];
	_return = (configfile >> _this);
	_config = (getMissionConfig _this);
	if (isClass _config) then{
	  _return = _config;
	};
	_return
};

_config = _configName call _returnConfig;
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
	diag_log format["Error: Compiler format for %1 is out of date.",_configName];
};
