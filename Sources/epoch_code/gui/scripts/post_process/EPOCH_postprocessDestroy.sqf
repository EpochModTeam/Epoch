/*
	Destroys single or multiple post process effects

	Params:		single handle or array of handles

	Usage:		_handle call epoch_postprocessDestroy; //single
				[_handle] call epoch_postprocessDestroy; //array of handles
				[_hndl_1,_hndl_2,_hndl_3,_hndl_4] call epoch_postprocessDestroy; //array of singles
*/

if !(_this isEqualType []) then {
	_this = [_this]
};
ppEffectDestroy _this;
