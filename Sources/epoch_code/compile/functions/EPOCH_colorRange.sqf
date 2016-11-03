/*
	Author: Aaron Clark - EpochMod.com

    Contributors:

	Description:
	Returns color based on range

    Licence:
    Arma Public License Share Alike (APL-SA) - https://www.bistudio.com/community/licenses/arma-public-license-share-alike

    Github:
    https://github.com/EpochModTeam/Epoch/tree/release/Sources/epoch_code/compile/functions/EPOCH_colorRange.sqf

    Example:
    _color = [_min,_max,_value] call EPOCH_colorRange;

    Parameter(s):
		_this select 0: NUMBER - Config Class
        _this select 1: NUMBER - Variable Name
		_this select 2: NUMBER - Default Variable
        _this select 3: NUMBER - passthou alpha var
	Returns:
	MIXED
*/
//[[[cog import generate_private_arrays ]]]
private ["_b","_color","_g","_r","_ratio","_return"];
//[[[end]]]
params ["_minimum", "_maximum", "_value", "_alpha"];
_ratio = 2 * (_value-_minimum) / (_maximum - _minimum);
_b = 0 max (255*(1 - _ratio));
_r = 0 max (255*(_ratio - 1));
_g = (255 - _b - _r);
_return = [_r, _g, _b] apply {linearConversion [0, 255, _x, 0, 1, true]};
_return pushBack _alpha;
_return
