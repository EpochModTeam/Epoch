/*
	Author: Aaron Clark - EpochMod.com

    Contributors:

	Description:
    Uses Epoch server extension to perform various functions like: kick, ban, shutdown, message, unlock/lock

    Licence:
    Arma Public License Share Alike (APL-SA) - https://www.bistudio.com/community/licenses/arma-public-license-share-alike

    Github:
    https://github.com/EpochModTeam/Epoch/tree/master/Sources/epoch_server/compile/epoch_server/EPOCH_weightedArray.sqf
*/
private["_return","_lootTableArray","_weightedArray"];
params ["_keyName","_configName","_arrayName"];
_return = missionNamespace getVariable[format["EPOCH_LT_%1_%2_%3",_configName,_keyName,_arrayName],[]];
if(_return isEqualTo[]) then {
    _lootTableArray = [];
    _weightedArray  = [];
    {
        if(_x isEqualType []) then {
            _lootTableArray pushBack(_x select 0);
            for "_i" from 1 to(_x select 1) do {
                _weightedArray pushBack _forEachIndex;
            };
        } else {
            _lootTableArray pushBack _x;
            _weightedArray pushBack _forEachIndex;
        };
    }forEach getArray(configFile >> _configName >> _keyName >> _arrayName);
    _return = [_lootTableArray,_weightedArray];
    missionNamespace setVariable[format["EPOCH_LT_%1_%2_%3",_configName,_keyName,_arrayName],_return];
};
_return
