/*
	Author: Aaron Clark - EpochMod.com

    Contributors:

	Description:
	Initalize both init and run custom client function compiler

    Licence:
    Arma Public License Share Alike (APL-SA) - https://www.bistudio.com/community/licenses/arma-public-license-share-alike

    Github:
    https://github.com/EpochModTeam/Epoch/tree/master/Sources/epoch_code/init/fn_init.sqf
*/

if !(isNil "Epoch_CStart") exitWith { false };
Epoch_CStart = true;

if (!isDedicated && hasInterface) then {
	call compile preprocessFileLineNumbers "\x\addons\a3_epoch_code\init\both_init.sqf";

	// Epoch Client Only function compiler
	_config = (configFile >> "CfgClientFunctions");
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
							diag_log format["CfgClientFunctions compileFinal: %1", _var_name];
						} forEach ("isclass _x" configClasses (_x));
					}
				} forEach ("isclass _x" configClasses (_x));
			};
		} forEach ("isclass _x" configClasses (_config));
	} else {
		diag_log "Error: CfgClientFunctions out of date.";
	};
};
true
