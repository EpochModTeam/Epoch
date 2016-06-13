/*
	Author: Raimonds Virtoss - EpochMod.com

    Contributors:

	Description:
	DESC-TBA

    Licence:
    Arma Public License Share Alike (APL-SA) - https://www.bistudio.com/community/licenses/arma-public-license-share-alike

    Github:
    https://github.com/EpochModTeam/Epoch/tree/release/Sources/epoch_code/gui/scripts/craftingv2/EPOCH_crafting_animate.sqf
*/
params ["_ctrl","_first","_second",["_speed",0.5]];

_ctrl ctrlSetPosition _first;
_ctrl ctrlCommit 0;
_ctrl ctrlSetPosition _second;
_ctrl ctrlCommit _speed;

true
