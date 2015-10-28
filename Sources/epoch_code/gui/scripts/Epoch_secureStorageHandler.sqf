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
		EPOCH_lockStorage_PVS = [_in,(_in getVariable ["EPOCH_Locked",false]),player,Epoch_personalToken];
		publicVariableServer "EPOCH_lockStorage_PVS";
		true
	};
	default {false};
};

_out
