/*
 Made for A3 Epoch Mod
 EpochMod.com
 by Aaron Clark - [VB]AWOL

 This work is licensed under a Creative Commons Attribution-ShareAlike 4.0 International License.
 http://creativecommons.org/licenses/by-sa/4.0/

 USAGE: you must create a protection zone and give it the VariableName of MIDDLE
        then simply run the below code in debug console and your clipboard will contain the config

        the telePos position needs to match the array variable in the example it is called "custom"
        so your telePos array would look like:

        { "Transport_C_EPOCH", { 13.5127,0.410156,-10.3098 }, "", "custom" },

*/


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

EPOCH_dbg_saveBaseTemplate = {
    _br = toString [13,10];
    _classes = [];
    _config_str = "custom[] = {"+ _br;
    _staticTraders = [];
    _middleClass = (typeof MIDDLE);
    _classes pushBack _middleClass;
    _range = 400;
    _array = allMissionObjects "ALL";
    _newArray = [];

    {
        if (_x distance MIDDLE <= _range) then {
            _type = typeof _x;
            if (_middleClass != _type) then {
                _newArray pushBack _x
            };
        };
    } forEach _array;

    _countArray = (count _newArray) - 1;
    {
        if (!(isPlayer _x)) then {
            _type = typeof _x;
            _classes pushBack [_type,getposATL _x, ([vectorDir _x, vectorUp _x]) call EPOCH_dbg_replaceBrackets];
            _config_str = _config_str +  format['    { "%1", %2, %3, %4 }%5', _type,  (getposATL _x) call EPOCH_dbg_replaceBrackets, ([vectorDir _x, vectorUp _x]) call EPOCH_dbg_replaceBrackets, !(simulationEnabled _x), if (_forEachIndex isEqualTo _countArray) then {_br} else {("," + _br)}];

        };
    } forEach _newArray;


    _config_str = _config_str + "};";

    if (_this) then {
        _config_str
    } else {
        _classes
    }
};
copyToClipboard (true call EPOCH_dbg_saveBaseTemplate);
