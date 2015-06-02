EPOCH_dbg_replaceBrackets = {
    _return = [];
    {
        _string = _x;
        if (_string == 93) then {
            _string = 125;
        };
        if (_string == 91) then {
            _string = 123;
        };
        _return set [(count _return),_string];
        
    } forEach toArray(format['%1',_this]);
    _return = toString _return; 
    _return 
};
 
EPOCH_dbg_saveVehiclePosWhitelist = {
    _br         = toString [13,10];
    _types      = ["LandVehicle","Ship","Air","Tank"];
    _config_str = "class whitelistedVehiclePos {" + _br;
    _classes    = [];
    {
        {
            if !(typeOf _x in _classes) then {
                _classes pushBack (typeOf _x);
            };
            _getExistingPos = missionNamespace getVariable [typeOf _x, []];
            _worldSpace     = [getposATL _x,[vectordir _x,vectorup _x]];
            
            if !(_worldSpace in _getExistingPos) then {
                _getExistingPos pushBack _worldSpace;
            };
            
            if !(_x getVariable ["Logged" , false]) then {
                missionNamespace setVariable [typeOf _x, _getExistingPos];
                _x setVariable ["Logged" , true];
            };
        } foreach allMissionObjects _x;
    } foreach _types;
    {
        _getExistingArray = missionNamespace getVariable [_x, []];
        _config_str       = _config_str +  format[' %1[] = {',_x];
        {
            _next       = _getExistingArray select (_forEachIndex + 1);
            _useComma   = if (isNil "_next") then {""} else {","};
            _config_str = _config_str + format['%1%2', _x call EPOCH_dbg_replaceBrackets,_useComma];
        }
        foreach _getExistingArray;
        _config_str = _config_str + "};" + _br ;
    } foreach _classes;
    _config_str = _config_str + "};" + _br;
    _config_str
};
EP_DEBUG = call EPOCH_dbg_saveVehiclePosWhitelist;
copyToClipboard EP_DEBUG;
