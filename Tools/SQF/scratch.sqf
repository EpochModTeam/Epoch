_dynamicEvents = _missionNamespace getVariable ["EPOCH_dynamicEvents", []];
missionNamespace setVariable ["EPOCH_dynamicEvents", _dynamicEvents + [
	[
		2700, // SECOND <scalar>
		[[123,"mockpayload"] "call", "EPOCH_mockServerFunction"], // EVENT <string> for execVM or <array> [ payload, ("call" or "spawn"), name of already compiled missionNamespace function]
		0,  // INIT <scalar> 1 = run script at startup or 0 normal delay
		1,  // PREPOSTFIX <scalar> 1 = use pre/postfix path (inside epoch settings pbo) 0 = use full file path (Ignored if not using execVM)
		-1, // RUNNUMTIMES <scalar> -1 infinite
		[], // execVM payload <array> (Ignored if not using execVM)
		[] 	// disallowed worlds <array>
	],
	[
		300,
		[[456,"mockpayload2"] "spawn", "EPOCH_mockServerFunction2"],
		0,
		1,
		-1,
		[],
		[]
	],

]];
