private["_return", "_config"];
_return = (configfile >> _this);
_config = (getMissionConfig _this);
if (isClass _config) then{
    _return = _config;
};
_return
