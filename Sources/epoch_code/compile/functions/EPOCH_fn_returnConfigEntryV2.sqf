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
			case "SCALAR": {getNumber _finalconfig};
			case "BOOL": {(getNumber _finalconfig) == 1};
			case "ARRAY": {getArray _finalconfig};
			case "STRING": {getText _finalconfig};
			default {_defaultData};
		};
	} else {
		_varData = _defaultData;
	};
} else {
	_varData = _defaultData;
};
_varData
