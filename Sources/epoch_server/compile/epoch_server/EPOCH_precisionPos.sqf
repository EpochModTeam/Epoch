/*
	Author: Aaron Clark - EpochMod.com

    Contributors:

	Description:
    Splits a position into two arrays: Whole number array and decimal array.

    Licence:
    Arma Public License Share Alike (APL-SA) - https://www.bistudio.com/community/licenses/arma-public-license-share-alike

    Github:
    https://github.com/EpochModTeam/Epoch/tree/master/Sources/epoch_server/compile/epoch_server/EPOCH_precisionPos.sqf
*/
private["_low"];
params ["_x","_y","_z"];
_low = [_x - (_x % 1),_y - (_y % 1),_z - (_z % 1)];
[_low, _this vectorDiff _low]
