
EP_notSetup = [];
EP_setup = [];

_all = nearestObjects [player, ["building"], 20000];
{
	_typeOf = typeof _x;
	

		if !(isClass(configfile >> "CfgBuildingLootPos" >> _typeOf)) then {
			if !(_typeOf in EP_notSetup) then {
				EP_notSetup pushBack _typeOf;
			};
		} else {
			if !(_typeOf in EP_notSetup) then {
				EP_setup pushBack _typeOf;
			};
		}
		
	
} foreach _all;