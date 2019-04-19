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

if (player == vehicle player && {getPosATL player select 2 > 0.4} && {cameraview == 'GUNNER'}) then {
	_weapondir = player weapondirection (currentweapon player);
	if (animationstate player in ['aadjpknlmstpsraswpstddown','aadjpknlmstpsraswrflddown'] && {_weapondir select 2 < -0.88}) then {
		player switchCamera "EXTERNAL";
		player playAction "AdjustF";
		_fadedblack = true;
		TitleText ['Stop BugUsing!','BLACK FADED'];
	}
	else {
		_eyePos = eyepos player;
		_eyedist = 0.25;
		_end = [((_eyePos select 0)+_eyedist*(_weapondir select 0)),((_eyePos select 1)+_eyedist*(_weapondir select 1)),((_eyePos select 2)+_eyedist*(_weapondir select 2))];
		_objects = lineintersectswith [_eyePos,_end,player];
		_objects = _objects select {_x iskindof "Constructions_static_F"};
		if !(_objects isequalto []) then {
			player switchCamera "EXTERNAL";
			_fadedblack = true;
			TitleText ['Stop BugUsing!','BLACK FADED'];
		}
		else {
			call _UnFadeCheck;
		};
	};
}
else {
	call _UnFadeCheck;
};

