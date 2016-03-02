/*
	Author: Aaron Clark - EpochMod.com

    Contributors:

	Description:
	Return configFile or missionConfigFile data if exists else return default variable

    Licence:
    Arma Public License Share Alike (APL-SA) - https://www.bistudio.com/community/licenses/arma-public-license-share-alike

    Github:
    https://github.com/EpochModTeam/Epoch/tree/master/Sources/epoch_code/compile/functions/EPOCH_fn_returnConfigEntryV2.sqf

    Example:
    _sapperRndChance = ["CfgEpochClient", "sapperRngChance", 100] call EPOCH_fnc_returnConfigEntryV2;

    Parameter(s):
		_this select 0: STRING - Config Class
        _this select 1: STRING - Variable Name
		_this select 2: STRING - Default Variable

	Returns:
	MIXED
*/
private["_config", "_varData","_missionconfig","_finalconfig"];
params ["_configClass","_variableName","_defaultData"];
_varData = _defaultData;
_config = (configfile >> _configClass);
_missionconfig = (getMissionConfig _configClass);
if (isClass _missionconfig) then{
	if (configName(_missionconfig >> _variableName) == _variableName) then{
		_config = _missionconfig;
	};
};
if (isClass(_config)) then{
	_finalconfig = _config >> _variableName;
	if (configName(_finalconfig) == _variableName) then{
		_varData = switch (typeName _defaultData) do {
			case "SCALAR": {if (isNumber (_finalconfig)) then { getNumber _finalconfig } else {_defaultData} };
			case "BOOL": {if (isText (_finalconfig)) then { (getText _finalconfig) isEqualTo "true" } else {_defaultData} };
			case "ARRAY": {if (isArray (_finalconfig)) then { getArray _finalconfig } else {_defaultData} };
			case "STRING": {if (isText (_finalconfig)) then { getText _finalconfig } else {_defaultData} };
			default {_defaultData};
		};
	};
};
_varData
