/*
	Author: Aaron Clark - EpochMod.com

    Contributors:

	Description:
	Custom functions compiler

    Licence:
    Arma Public License Share Alike (APL-SA) - https://www.bistudio.com/community/licenses/arma-public-license-share-alike

    Github:
    https://github.com/EpochModTeam/Epoch/tree/release/Sources/epoch_code/compile/both/EPOCH_compiler.sqf

    Example:
    "CfgServerFunctions" call EPOCH_fnc_compiler;
    or
    "CfgClientFunctions" call EPOCH_fnc_compiler;

    Parameter(s):
		_this: STRING - Config class name

	Returns:
	BOOL
*/
//[[[cog import generate_private_arrays ]]]
private ["_code","_config","_config_name","_customVarNames","_customVarsInit","_file","_file_raw","_file_tag","_fnc_path","_header","_missionConfig","_randomValues","_rng","_tag","_var_name","_version"];
//[[[end]]]
params [["_configName","",[""] ] ];

_config = (configfile >> _configName);
_missionConfig = (getMissionConfig _configName);
if (isClass _missionConfig) then{
	_config = _missionConfig;
};

// custom header for interscript communications
_customVarsInit = getArray(getMissionConfig "CfgEpochClient" >> "customVarsDefaults");
_customVarNames = _customVarsInit apply {_x param [0,""]};
_randomValues = [];
_header = "";
{
	while {true} do {
		_rng = round(diag_tickTime + random 99999);
		if !(_rng in _randomValues) exitWith {
			_randomValues pushBack _rng;
			_header = _header + format["_player%1Key = 'EPOCH_%2';",_x, _rng];
		};
	};
} forEach _customVarNames;

_version = getNumber(_config >> "version");
if (_version >= 1) then {
	{
		if (isClass(_x)) then {
			_tag = getText(_x >> "tag");
			_file = getText(_x >> "file");
			_file_tag = _file;
			{
				if (isClass(_x)) then {
					_file = _file_tag;
					_file_raw = getText(_x >> "file");
					if (_file_raw == "") then {
						_file = format["%1\%2", _file, configName _x];
					} else {
						_file = _file_raw;
					};
					{
						_config_name = configName _x;
						//version 2 More like BI standard fnc / fn_
						_var_name = format["%1_fnc_%2", _tag, _config_name];
						_fnc_path = format["%1\fn_%2.sqf", _file, _config_name];
						if (_version == 1) then {
							//version 1 TAG + _ + configName
							_var_name = format["%1_%2", _tag, _config_name];
							_fnc_path = format["%1\%2.sqf", _file, _var_name];
						};
						_file_raw = getText(_x >> "file");
						if (_file_raw != "") then {
							_fnc_path = _file_raw;
						};
						_code = "";
						if (getNumber(_x >> "customHeader") == 1) then {
							_code = _header + (preprocessFileLineNumbers _fnc_path);
						} else {
							_code = (preprocessFileLineNumbers _fnc_path);
						};

						missionNamespace setvariable [_var_name,compileFinal _code];
						if (getNumber(_x >> "preInit") == 1) then {
							call (missionNamespace getvariable _var_name);
						};
					} forEach (configProperties [_x, "isClass _x", true]);
				}
			} forEach (configProperties [_x, "isClass _x", true]);
		};
	} forEach (configProperties [_config, "isClass _x", true]);
};
