_removeControls = {
	EPOCH_geiger_shown = false;
	for "_i" from 1 to 8 do{
		(["geigerCounter", _i] call epoch_getHUDCtrl) ctrlSetText "";
	};
	ctrlDelete (uiNamespace getVariable ["EPOCH_geiger_LCD",controlNull]);
	ctrlDelete (uiNamespace getVariable ["EPOCH_geiger_LED",controlNull]);
};

if !('ItemGeigerCounter_EPOCH' in assignedItems player) exitWith {call _removeControls; false};

if (ctrlText(["geigerCounter", 1] call epoch_getHUDCtrl) isEqualTo "") then {
	EPOCH_geiger_shown = true;
	
	for "_i" from 1 to 8 do{
		(["geigerCounter", _i] call epoch_getHUDCtrl) ctrlSetText format ["x\addons\a3_epoch_assets_1\pictures\geiger\geiger_%1",_i];
	};
	_ledBG = (["geigerCounter", 4] call epoch_getHUDCtrl);
	_lcdBG = (["geigerCounter", 5] call epoch_getHUDCtrl);
	_lcdPos = ctrlPosition _lcdBG;
	_ledPos = ctrlPosition _ledBG;
	_parent = ctrlParentControlsGroup _lcdBG;

	_lcdPos set [0,(_lcdPos select 2) / 3.35];
	_lcdPos set [2,(_lcdPos select 2) * 43 / 100];

	_lcd = (findDisplay 46) ctrlCreate ["rmx_geigerTXT",65765,_parent];
	_lcd ctrlSetPosition _lcdPos;
	_lcd ctrlCommit 0;
	_lcd ctrlSetText ""; //(random 1000 toFixed 1);
	
	_led = (findDisplay 46) ctrlCreate ["RscPicture",65766,_parent];
	_led ctrlSetPosition _ledPos;
	_led ctrlCommit 0;
	_led ctrlSetText ""; //"x\addons\a3_epoch_assets_1\pictures\geiger\geiger_4on";
	
	uiNamespace setVariable ["EPOCH_geiger_LCD",_lcd];
	uiNamespace setVariable ["EPOCH_geiger_LED",_led];
	if (EPOCH_playerEnergy <= 20) then {"Low Energy!" call epoch_message;};
} else {
	call _removeControls;
};

true 