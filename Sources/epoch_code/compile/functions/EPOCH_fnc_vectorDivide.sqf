/*
	Author: Andrew Gregory - EpochMod.com

    Contributors:

	Description:
	Divide a Vector (Average Position / Vector).

    Licence:
    Arma Public License Share Alike (APL-SA) - https://www.bistudio.com/community/licenses/arma-public-license-share-alike

    Github:
    https://github.com/EpochModTeam/Epoch/tree/master/Sources/epoch_code/compile/functions/EPOCH_fnc_vectorDivide.sqf

    Example:
    _averageVector = [[15,15,3],3] call EPOCH_fnc_vectorDivide;

    Parameter(s):
		_this select 0: ARRAY - Vector / Position
        _this select 1: INT - Divide by

	Returns:
	ARRAY - Averag Vector
*/
params ["_vec","_div",["_doZ",true],["_out",[0,0,0]]];
_out set [0,_vec select 0 / _div];
_out set [1,_vec select 1 / _div];
_out set [2,0];
if(_doZ)then{_out set [2,_vec select 2 / _div];};
_out
