/*
	Author: Raimonds Virtoss - EpochMod.com

    Contributors:

	Description:
	Destroys single or multiple post process effects

    Licence:
    Arma Public License Share Alike (APL-SA) - https://www.bistudio.com/community/licenses/arma-public-license-share-alike

    Github:
    https://github.com/EpochModTeam/Epoch/blob/release/Sources/epoch_code/gui/scripts/post_process/EPOCH_postprocessDestroy.sqf



	Params:		single handle or array of handles

	Usage:		_handle call epoch_postprocessDestroy; //single
				[_handle] call epoch_postprocessDestroy; //array of handles
				[_hndl_1,_hndl_2,_hndl_3,_hndl_4] call epoch_postprocessDestroy; //array of singles
*/

if !(_this isEqualType []) then {
	_this = [_this]
};
ppEffectDestroy _this;
