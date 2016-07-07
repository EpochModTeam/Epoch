
EP_notSetup = [];
EP_setup = [];

_all = nearestTerrainObjects [player, [], 40000, false];
{
	_typeOf = typeof _x;
		if !(isClass(getMissionConfig "CfgBuildingLootPos" >> _typeOf)) then {
			if !(_typeOf in EP_notSetup) then {
				EP_notSetup pushBack _typeOf;
			};
		} else {
			if !(_typeOf in EP_notSetup) then {
				EP_setup pushBack _typeOf;
			};
		}
		
} foreach _all;