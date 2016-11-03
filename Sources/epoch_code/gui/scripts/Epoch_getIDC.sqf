/*
	Author: Raimonds Virtoss - EpochMod.com

    Contributors: Aaron Clark

	Description:
	Used to register and unregister IDC used in dynamic menus.
	Pass the control to unregister or just call fnc to get a unique IDC

    Licence:
    Arma Public License Share Alike (APL-SA) - https://www.bistudio.com/community/licenses/arma-public-license-share-alike

    Github:
    https://github.com/EpochModTeam/Epoch/tree/release/Sources/epoch_code/gui/scripts/Epoch_getIDC.sqf
*/
//[[[cog import generate_private_arrays ]]]
private ["_find","_in","_list","_out"];
//[[[end]]]
_in = [_this, 0, controlNull, [controlNull]] call BIS_fnc_param;

_list = missionNamespace getVariable ["rmx_var_uniqueIDC",[]];

if (ctrlIDC _in isEqualTo -1) then {
	_out = -90000 - (count _list);
	_list pushBack _out;
} else {
	_find = _list find (ctrlIDC _in);
	_list deleteAt _find;
	_out = true;
};
missionNamespace setVariable ["rmx_var_uniqueIDC",_list];

_out
