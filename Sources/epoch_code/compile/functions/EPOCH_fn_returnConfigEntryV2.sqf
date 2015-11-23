private["_defaultData", "_config", "_varData","_missionconfig","_finalconfig"];
_defaultData = _this select 2;
_config = (configfile >> (_this select 0));
_missionconfig = (missionConfigFile >> (_this select 0));
if (isClass _missionconfig) then{
	if (configName(_missionconfig >> (_this select 1)) == (_this select 1)) then{
		_config = _missionconfig;
	};
};
if (isClass(_config)) then{
	_finalconfig = _config >> (_this select 1);
	if (configName(_finalconfig) == (_this select 1)) then{
		_varData = switch (typeName _defaultData) do {
			case "SCALAR": {if (isNumber (_finalconfig)) then { getNumber _finalconfig } else {_defaultData} };
			case "BOOL": {if (isText (_finalconfig)) then { (getText _finalconfig) isEqualTo "true" } else {_defaultData} };
			case "ARRAY": {if (isArray (_finalconfig)) then { getArray _finalconfig } else {_defaultData} };
			case "STRING": {if (isText (_finalconfig)) then { getText _finalconfig } else {_defaultData} };
			default {_defaultData};
		};
	} else {
		_varData = _defaultData;
	};
} else {
	_varData = _defaultData;
};
_varData
