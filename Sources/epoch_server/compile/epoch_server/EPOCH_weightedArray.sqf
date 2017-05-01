/*
	Author: Aaron Clark - EpochMod.com

    Contributors:

	Description:
    Uses Epoch server extension to perform various functions like: kick, ban, shutdown, message, unlock/lock

    Licence:
    Arma Public License Share Alike (APL-SA) - https://www.bistudio.com/community/licenses/arma-public-license-share-alike

    Github:
    https://github.com/EpochModTeam/Epoch/tree/release/Sources/epoch_server/compile/epoch_server/EPOCH_weightedArray.sqf
*/
//[[[cog import generate_private_arrays ]]]
private ["_lootIndex","_lootTableArray","_return","_weightedArray"];
//[[[end]]]
params ["_keyName","_configName","_arrayName"];
_return = missionNamespace getVariable[format["EPOCH_LT_%1_%2_%3",_configName,_keyName,_arrayName],[]];
if(_return isEqualTo[]) then {
    _lootTableArray = [];
    _weightedArray  = [];
    _lootIndex = 0;
    {
        if(_x isEqualType []) then {
            _x params ["_tname","_tqty"];
            if (!(_tname isEqualTo "Zombie") || (_tname isEqualTo "Zombie") && EPOCH_mod_Ryanzombies_Enabled) then {
                _lootTableArray pushBack _tname;
                for "_i" from 1 to _tqty do {
                    _weightedArray pushBack _lootIndex;
                };
                _lootIndex = _lootIndex + 1;
            };
        } else {
            if (!(_x isEqualTo "Zombie") || (_x isEqualTo "Zombie") && EPOCH_mod_Ryanzombies_Enabled) then {
                _lootTableArray pushBack _x;
                _weightedArray pushBack _lootIndex;
                _lootIndex = _lootIndex + 1;
            };
        };
    }forEach getArray(configFile >> _configName >> _keyName >> _arrayName);
    _return = [_lootTableArray,_weightedArray];
    missionNamespace setVariable[format["EPOCH_LT_%1_%2_%3",_configName,_keyName,_arrayName],_return];
    // diag_log format["EPOCH_LT_%1_%2_%3 = %4",_configName,_keyName,_arrayName,_return];
};
_return
