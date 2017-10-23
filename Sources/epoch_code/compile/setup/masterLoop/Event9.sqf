if ('ItemGeigerCounter_EPOCH' in assignedItems player) then {
	if (!EPOCH_geiger_mute_counter || !EPOCH_geiger_mute_warning || EPOCH_geiger_shown) then { //only run if geiger activated
		_radiatedObjMaxRange call epoch_geiger_simulate;
	};
} else {
	if (EPOCH_geiger_shown) then {
		call epoch_geiger_show_hide;
	};
};