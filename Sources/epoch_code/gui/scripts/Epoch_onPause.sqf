private ["_fieldManual","_btnAbort"];
disableSerialization;
params ["_display"];

_fieldManual = _display displayCtrl 122;
_fieldManual ctrlEnable false;
_btnSave = _display displayCtrl 103;
_btnSave ctrlEnable false;
_btnAbort = _display displayCtrl 104;
_btnAbort ctrlEnable false;
_respawnButton = _display displayCtrl 1010;
_respawnButton ctrlEnable false;

//Change to a scheduled environment
[_btnAbort,_display] spawn {
	disableSerialization;
	params ["_btnAbort","_display"];
	_startTime = diag_tickTime+10;
	waitUntil {
		_time = _startTime - diag_tickTime;
		if (isNull _display || _time <= 0) exitWith {true};
		_btnAbort ctrlSetText format[localize "str_epoch_abort",[_time,"SS.MS"] call BIS_fnc_secondsToString];
		false
	};
	if (!isNull _display) then {
		_btnAbort ctrlSetText localize "str_disp_int_abort";
		_btnAbort ctrlEnable true;
	};
};
[_display,_btnAbort,_fieldManual,_btnSave] spawn {
	disableSerialization;
	params ["_display","_btnAbort","_fieldManual","_btnSave"];
	_profilName = _display displayctrl 109;
	_pauseText = _display displayctrl 523;
	_pauseSetText = toUpper(localize "str_a3_cfguigrids_gui_0");
	_fieldManualText = toUpper(localize "str_a3_rscdisplaywelcome_pare_list3_title");
	_btnSaveText = toUpper(localize "str_disp_int_save");

	waitUntil {
		_fieldManual ctrlShow true;
		_fieldManual ctrlEnable false;
		_fieldManual ctrlSetText _fieldManualText;

		_btnSave ctrlShow true;
		_btnSave ctrlSetText _btnSaveText;

		_pauseText ctrlSetText _pauseSetText;
		_profilName ctrlSetText profileName;

		uiSleep 0.2;
		isNull _display
	};
};
[_display] spawn {
	disableSerialization;
	params ["_display"];
	with missionNamespace do {
		false call EPOCH_pushCustomVar;
	};
	_startTime = diag_tickTime+5;
	waitUntil {
		uiSleep 0.2;
	   (isNull _display) || ((_startTime - diag_tickTime) <= 0)
	};
	if (!isNull _display) then {
		with missionNamespace do {
			true call EPOCH_pushCustomVar;
		};
	};
};

// init epoch configurator
with missionNamespace do {
	_display call EPOCH_InterruptConfig;
};


true
