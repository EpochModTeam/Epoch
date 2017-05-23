_tempPos = true;

while {rmx_var_traderMenuActive} do {

	_mpos = getMousePosition;
	_onLeft = if ((_mpos select 0) < 0.5) then {true} else {false};
	
	if !(_tempPos isEqualTo _onLeft) then {
		_tempPos = _onLeft;
		
		if _onLeft then {
			['left','enter'] call Epoch_tradeMouseEvents;
			['right','exit'] call Epoch_tradeMouseEvents;
		} else {
			['left','exit'] call Epoch_tradeMouseEvents;
			['right','enter'] call Epoch_tradeMouseEvents;
		};
	};
}; 
