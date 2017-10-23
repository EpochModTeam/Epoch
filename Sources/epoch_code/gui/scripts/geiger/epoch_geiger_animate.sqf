disableSerialization;
_rads = param [0,0,[0]];
_lcd = uiNamespace getVariable ["EPOCH_geiger_LCD",controlNull];
_led = uiNamespace getVariable ["EPOCH_geiger_LED",controlNull];

if (_rads >= 10) then {
	if (!EPOCH_geiger_mute_warning) then {
		playSound "geiger_epoch_alarm";
	};
	[] spawn {
		disableSerialization;
		_lcd = uiNamespace getVariable ["EPOCH_geiger_LCD",controlNull];
		_lcd ctrlSetFade 1;
		_lcd ctrlCommit 1;
		uiSleep 1;
		if (EPOCH_playerEnergy <= 100) then {
		_lcd ctrlSetFade 1-(EPOCH_playerEnergy / 100);
		} else {
		_lcd ctrlSetFade 0;
		};
		_lcd ctrlCommit 1;
	};
};	
	
for "_i" from 1 to (ceil _rads) do {
	if (!EPOCH_geiger_mute_counter) then {
		playSound "geiger_epoch_tick";
		//playSound "geiger_epoch_tick"; //makes geiger louder, remove if affects performance
	};
	_led ctrlSetText "x\addons\a3_epoch_assets_1\pictures\geiger\geiger_4on";
	uiSleep (random 0.5);
	_led ctrlSetText "";
};

if (EPOCH_playerEnergy <= 100) then {
	_lcd ctrlSetFade 1-(EPOCH_playerEnergy / 100);
	_lcd ctrlCommit 1;
	_led ctrlSetFade 1-(EPOCH_playerEnergy / 100);
	_led ctrlCommit 1;
} else {
	_lcd ctrlSetFade 0;
	_lcd ctrlCommit 1;
	_led ctrlSetFade 0;
	_led ctrlCommit 1;
};