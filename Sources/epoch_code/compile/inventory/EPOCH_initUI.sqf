/*
	Author: Aaron Clark - EpochMod.com

    Contributors:

	Description:
	Init epoch gear armor stats.

    Licence:
    Arma Public License Share Alike (APL-SA) - https://www.bistudio.com/community/licenses/arma-public-license-share-alike

    Github:
    https://github.com/EpochModTeam/Epoch/tree/release/Sources/epoch_code/compile/inventory/EPOCH_initUI.sqf

    Example:
    player addEventHandler ["InventoryOpened", {
        _this spawn EPOCH_initUI;
    }];

    Parameter(s):
        None

	Returns:
	NOHTING
*/
//[[[cog import generate_private_arrays ]]]
private ["_bar","_bar_compare","_color","_colorCompare","_container","_display","_existing_bar","_height","_pos","_remoteContainer","_small_height"];
//[[[end]]]
disableSerialization;

[] spawn epoch_favBar_inventory;

EPOCH_InteractedItem = [];
params ["_unit","_targetContainer","_secondaryContainer"];
EPOCH_targetContainer = _targetContainer;
EPOCH_secondaryContainer = _secondaryContainer;

waitUntil {!isNull findDisplay 602};
_display = (findDisplay 602);

// init custom sub menu handler
{
    _container = _display displayCtrl _x;
    _container ctrlAddEventHandler ["LBDblClick","_this call EPOCH_itemInteractClick"];
} forEach [619,633,638];
// armor stats init
{
    _remoteContainer = _display displayCtrl _x;
    _remoteContainer ctrlAddEventHandler ["LBDrag","_this call EPOCH_selectInventoryItem; _this call EPOCH_refeshUI"];
    _remoteContainer ctrlAddEventHandler ["LBSelChanged","_this call EPOCH_selectInventoryItem; _this call EPOCH_refeshUI"];
} forEach [632,640];

_color = [0.6,0.6,0.6,1];
_colorCompare = [0.4,0.6,1,0.4];

// UniformLoad
_bar = _display ctrlCreate ["RscCustomProgress", 7304];
uiNameSpace setVariable ["RscCustomProgressUniform", _bar];
_bar ctrlSetTextColor _color;

_existing_bar = _display displayCtrl 6304;
_pos = ctrlPosition _existing_bar;
_height = (_pos select 3) / 2;
_existing_bar ctrlSetPosition [_pos select 0,(_pos select 1)+_height,_pos select 2,_height];
_existing_bar ctrlCommit 0;
_bar ctrlSetPosition [_pos select 0,_pos select 1,_pos select 2,_height];
_bar ctrlCommit 0;

// VestLoad
_bar = _display ctrlCreate ["RscCustomProgress", 7305];
uiNameSpace setVariable ["RscCustomProgressVest", _bar];
_bar ctrlSetTextColor _color;

_existing_bar = _display displayCtrl 6305;
_pos = ctrlPosition _existing_bar;
_height = (_pos select 3) / 2;
_small_height = _height;
_existing_bar ctrlSetPosition [_pos select 0,(_pos select 1)+_height,_pos select 2,_height];
_existing_bar ctrlCommit 0;
_bar ctrlSetPosition [_pos select 0,_pos select 1,_pos select 2,_height];
_bar ctrlCommit 0;

// SlotHeadgear
_bar = _display ctrlCreate ["RscCustomProgress", 7240];
uiNameSpace setVariable ["RscCustomProgressHeadgear", _bar];
_bar ctrlSetTextColor _color;

_existing_bar = _display displayCtrl 6240;
_pos = ctrlPosition _existing_bar;
_height = _pos select 3;

_bar ctrlSetPosition [_pos select 0,(_pos select 1)+_height,_pos select 2,_small_height];
_bar ctrlCommit 0;

// TotalLoad;
_existing_bar = _display displayCtrl 6308;
_pos = ctrlPosition _existing_bar;
_height = (_pos select 3) / 2;

_existing_bar ctrlSetPosition [_pos select 0,(_pos select 1)+_height,_pos select 2,_height];
_existing_bar ctrlCommit 0;

// TotalLoad compare;
_bar = _display ctrlCreate ["RscTotalArmorProgress", 7308];
_bar ctrlSetTextColor _color;

_bar ctrlSetPosition [_pos select 0,_pos select 1,_pos select 2,_height];
_bar ctrlCommit 0;

_bar_compare = _display ctrlCreate ["RscCustomProgress", 7309];
_bar_compare ctrlSetTextColor _colorCompare;

_bar_compare ctrlSetPosition [_pos select 0,_pos select 1,_pos select 2,_height];
_bar_compare ctrlCommit 0;

uiNameSpace setVariable ["RscCustomProgressTotal", [_bar,_bar_compare]];

0 call EPOCH_refeshUI;
