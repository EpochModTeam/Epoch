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
        _return pushBack _string;    
    } forEach toArray(format['%1',_this]);
    _return = toString _return; 
    _return 
};
 
EPOCH_dbg_savePropsPosWhitelist = {
 
    _disallowedTypes      = ["ThingEffectLight","ThingEffect","ThingEffectFeather"];
    _isAllowed = {
        _return = true;
        {
            if (_this isKindOf _x) exitWith {_return = false};
        } forEach _disallowedTypes;
        _return
    };
 
    _br         = toString [13,10];
    _types      = ["Thing","Building"];
    _config_str = "propsPos[] = {" + _br;
    _array = [];
    {
        _array append allMissionObjects _x;
    } foreach _types;
    if !(_array isEqualTo []) then {
        
        _countArray = (count _array) - 1;
        {
            if (_x call _isAllowed) then {
                _worldSpaceNtype     = [typeOf _x, getposATL _x, getDir _x];
                _config_str = _config_str +  format['    { "%1", %2, %3, true }%4', typeOf _x,  (getposATL _x) call EPOCH_dbg_replaceBrackets, [vectordir _x, vectorup _x] call EPOCH_dbg_replaceBrackets, if (_forEachIndex isEqualTo _countArray) then {_br} else {("," + _br)}];
            };
        } foreach _array;
    };
    _config_str = _config_str + "};" + _br;
    _config_str
};
copyToClipboard call EPOCH_dbg_savePropsPosWhitelist;
