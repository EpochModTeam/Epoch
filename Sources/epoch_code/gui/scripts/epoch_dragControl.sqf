/*
	Author: Raimonds Virtoss - EpochMod.com

    Contributors:

	Description:
	Gives ability to move active controls like RscActivePicture (see Epoch_GUI_rmx.hpp for an example).

    Licence:
    Arma Public License Share Alike (APL-SA) - https://www.bistudio.com/community/licenses/arma-public-license-share-alike

    Github:
    https://github.com/EpochModTeam/Epoch/tree/release/Sources/epoch_code/gui/scripts/Epoch_dragControl.sqf

	Usage:
	No direct usage, simply create your control in configs following example in HPP mentioned in description
*/
//[[[cog import generate_private_arrays ]]]
private ["_ctrl","_curr","_mpos"];
//[[[end]]]
_ctrl = param [0];
_curr = ctrlPosition _Ctrl;
_mpos = getmousePosition;

if (rmx_var_drag_MouseDown) then {
	_ctrl ctrlSetPosition [(_mpos select 0) - (_curr select 2) / 2, (_mpos select 1) - (_curr select 3) / 2 ];
	_ctrl ctrlCommit 0;
};
