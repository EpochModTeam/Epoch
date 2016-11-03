/*
	Author: Aaron Clark - EpochMod.com

    Contributors:

	Description:
	spawn Effects over time based on array

    Licence:
    Arma Public License Share Alike (APL-SA) - https://www.bistudio.com/community/licenses/arma-public-license-share-alike

    Github:
    https://github.com/EpochModTeam/Epoch/tree/release/Sources/epoch_code/compile/functions/EPOCH_fnc_spawnEffects.sqf

    Example:
    [] spawn EPOCH_fnc_spawnEffects;

    Parameter(s):
		_this select 0: ARRAY - effects array
*/
//[[[cog import generate_private_arrays ]]]
private ["_firstArray","_fx","_handle","_handles"];
//[[[end]]]
params [["_ppEffects",[],[[]] ] ];
_handles = [];
{
    _fx = _x;
    if (_fx isEqualType []) then {
        if (_fx isEqualTo []) then {
            ppEffectDestroy _handles;
        } else {
            {
                if !(_x isEqualTo []) then {
                    if (count _x == 4) then {
                        _x params ["_type","_proi","_effect","_speed"];
                        _handle = [_type,_proi] call epoch_postProcessCreate;
                        _handles pushBack _handle;
                        [_handle, _speed, _effect, true] call epoch_postprocessAdjust;
                    } else {
                        _x params ["_effect","_speed"];
                        [_handles select _forEachIndex, _speed, _effect, true] call epoch_postprocessAdjust;
                    };
                };
            } forEach _fx;
        };
    } else {
        // sleep
        if (_fx isEqualType 0) then {
            uiSleep _fx;
        };
    };
} forEach _ppEffects;
