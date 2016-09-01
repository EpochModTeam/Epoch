/*
	Author: Raimonds Virtoss - EpochMod.com

    Contributors:

	Description:
	Returns Control from Dynamic HUD to be manipulated externally. See CfgDynamicHUD.hpp on how to create your own HUD groups.

    Licence:
    Arma Public License Share Alike (APL-SA) - https://www.bistudio.com/community/licenses/arma-public-license-share-alike

    Github:
    https://github.com/EpochModTeam/Epoch/tree/release/Sources/epoch_code/gui/scripts/dynamicHUD/Epoch_getHUDCtrl.sqf

	Usage:
	[_configName, _index] call epoch_getHUDCtrl;
	["myHudName", 2] call epoch_getHUDCtrl;
*/
//[[[cog import generate_private_arrays ]]]
private ["_gIdx"];
//[[[end]]]
if !(_this isEqualTypeArray ["",0]) exitWith {controlNull};
params ["_gName","_cIdx"];
_gIdx = -1;
{
	if ((_x select 0) isEqualTo _gName) exitWith {_gIdx = _forEachIndex};
} forEach rmx_var_dynamicHUD_groupCTRL;
if (_gIdx == -1) exitWith {controlNull};
(rmx_var_dynamicHUD_groupCTRL select _gIdx) select _cIdx
