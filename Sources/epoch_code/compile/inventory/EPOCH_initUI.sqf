/*
	Author: Aaron Clark - EpochMod.com

    Contributors:

	Description:
	Init epoch gear armor stats.

    Licence:
    Arma Public License Share Alike (APL-SA) - https://www.bistudio.com/community/licenses/arma-public-license-share-alike

    Github:
    https://github.com/EpochModTeam/Epoch/tree/master/Sources/epoch_code/compile/inventory/EPOCH_initUI.sqf

    Example:
    player addEventHandler ["InventoryOpened", {
        _this spawn EPOCH_initUI;
    }];

    Parameter(s):
        None

	Returns:
	NOHTING
*/
private ["_display","_color","_colorCompare","_bar","_bar_compare"];
disableSerialization;

EPOCH_InteractedItem = [];
EPOCH_lastContainer = _this select 1;

waitUntil {!isNull findDisplay 602};
_display = (findDisplay 602);

(_display displayCtrl -13) ctrlEnable false;

_color = [0.6,0.6,0.6,1];
_colorCompare = [0.4,0.6,1,0.4];

_bar = _display displayCtrl 7304;
uiNameSpace setVariable ["RscCustomProgressUniform", _bar];
_bar ctrlSetTextColor _color;

_bar = _display displayCtrl 7305;
uiNameSpace setVariable ["RscCustomProgressVest", _bar];
_bar ctrlSetTextColor _color;

_bar = _display displayCtrl 7240;
uiNameSpace setVariable ["RscCustomProgressHeadgear", _bar];
_bar ctrlSetTextColor _color;

_bar = _display displayCtrl 7308;
_bar ctrlSetTextColor _color;

_bar_compare = _display displayCtrl 7309;
_bar_compare ctrlSetTextColor _colorCompare;

uiNameSpace setVariable ["RscCustomProgressTotal", [_bar,_bar_compare]];

0 call EPOCH_refeshUI;
