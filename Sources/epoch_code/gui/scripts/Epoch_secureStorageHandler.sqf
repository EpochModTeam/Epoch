_in = param [0,false];

_out = switch (typeName _in) do {
	case "STRING":
	{
		if !(isNull dyna_cursorTarget) then {
			dyna_cursorTarget getVariable ["EPOCH_Locked",false]
		};
	};
	case "OBJECT":
	{
		[_in,(_in getVariable ["EPOCH_Locked",false]),player,Epoch_personalToken] remoteExec ["EPOCH_server_lockStorage",2];
		true
	};
	default {false};
};

_out
