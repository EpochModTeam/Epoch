params ["_command","_param1","_param2","_param3"];
switch (_command) do {
	case 'shutdown': { 'epochserver' callExtension '991' };
	case 'message': { 'epochserver' callExtension format['901|%1', _param1] };
	case 'lock': { 'epochserver' callExtension '931' };
	case 'unlock': { 'epochserver' callExtension '930' };
	case 'kick': {
		_playerUID = _param1;
		if (_playerUID isEqualType objNull) then{
			if (!isNull(_playerUID)) then{
				_playerUID = getPlayerUID _playerUID;
			};
		};
		if (_playerUID != '') then{
			'epochserver' callExtension format['911|%1|%2', _playerUID, _param2];
		};
	};
	case 'ban': {
		_playerUID = _param1;
		if (_playerUID isEqualType objNull) then{
			if (!isNull(_playerUID)) then{
				_playerUID = getPlayerUID _playerUID;
			};
		};
		if (_playerUID != '') then{
			'epochserver' callExtension format['921|%1|%2|%3', _playerUID, _param2, _param3];
		};
	};
};
