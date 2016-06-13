/*
	Author: Aaron Clark - EpochMod.com

    Contributors:

	Description:
	Converts numbers between fahrenheit and celsius

    Licence:
    Arma Public License Share Alike (APL-SA) - https://www.bistudio.com/community/licenses/arma-public-license-share-alike

    Github:
    https://github.com/EpochModTeam/Epoch/tree/release/Sources/epoch_code/compile/functions/EPOCH_convertTemp.sqf

    Example:
    _celsius = [75,true] call EPOCH_convertTemp; // 24
    _fahrenheit = [0,false] call EPOCH_convertTemp; // 32

    Parameter(s):
		_this select 0: NUMBER - Temp
        _this select 1: BOOL - False to convert from C to F
	Returns:
	MIXED
*/
params [["_data",0,[0]],["_convertToC",true]];
if (_convertToC) then {
    // F to C
    round (((_data - 32) * 5) / 9)
} else {
    // C to F
    round (((_data * 9)/ 5 ) + 32)
}
