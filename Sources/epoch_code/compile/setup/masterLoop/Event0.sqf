// runs every 0.4 seconds

if (EPOCH_IsAutoRunning) then {
	if (call EPOCH_AutoRun_Check) then {
		call EPOCH_AutoRun;
	}
	else {
		EPOCH_IsAutoRunning = false;
		player switchMove "";
	};
};

if (animationstate player in ['aadjpknlmstpsraswpstddown','aadjpknlmstpsraswrflddown'] && cameraview == 'GUNNER' && (player weapondirection (currentweapon player)) select 2 < -0.88) then {
	_fadedblack = true;
	TitleText ['Stop BugUsing!','BLACK FADED'];
}
else {
	if(_fadedblack) then {
		[] spawn {
			uisleep 2;
			TitleText ['','PLAIN DOWN'];
		};
		_fadedblack = false;
	};
};