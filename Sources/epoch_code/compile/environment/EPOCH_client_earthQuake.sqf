/*
	Author: Aaron Clark - EpochMod.com

    Contributors:

	Description:
	Triggers earthquake with increasing intensity the closer the player

    Licence:
    Arma Public License Share Alike (APL-SA) - https://www.bistudio.com/community/licenses/arma-public-license-share-alike

    Github:
    https://github.com/EpochModTeam/Epoch/tree/release/Sources/epoch_code/compile/environment/EPOCH_client_earthQuake.sqf

    Example:
    [_location] call EPOCH_client_earthQuake

    Parameter(s):
		_this: ARRAY - Locaton of epicenter

	Returns:
	Script handle
*/
//[[[cog import generate_private_arrays ]]]
private ["_distance","_intensity"];
//[[[end]]]
params [["_epicenter",[0,0,0],[[]] ] ];
_distance = player distance _epicenter;
_intensity = 1;
if (_distance < 250) then {
	_intensity = 4;
} else {
	if (_distance < 500) then {
		_intensity = 3;
	} else {
		if (_distance < 750) then {
			_intensity = 2;
		};
	};
};
_intensity spawn BIS_fnc_earthQuake;
