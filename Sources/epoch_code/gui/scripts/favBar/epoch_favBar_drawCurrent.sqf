for "_i" from 0 to 4 do {
	_c = (["fav_pic", _i+1] call epoch_getHUDCtrl);
	_c ctrlSetText ((rmx_var_favBar_current select _i) call EPOCH_itemPicture);
};
true 