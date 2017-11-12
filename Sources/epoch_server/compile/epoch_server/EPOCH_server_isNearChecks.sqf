/*
	EPOCH_server_isNearChecks
	
	Author: DirtySanchez
	
	Description:
	Checks the position provided against distances configured for Traders, Jammers and Players.

	_position - position on map
	_traderCheck - BOOL - check _position distance near ProtectionZone_Invisible_F
	_jammerCheck - BOOL - check _position distance near PlotPole_EPOCH
	_playerCheck - BOOL - check _position distance near other Players
	_others - ARRAY - positions to check with _distFromOthers
	_distFromOthers - NUMBER - How far away from _others array in meters
*/

params [ ["_position",[]], ["_traderCheck",true], ["_jammerCheck",true], ["_playerCheck",true], ["_others",[[0,0,0]]], ["_distFromOthers",2000] ];
_distFromTraders = getNumber(_cfgEpoch >> "spawnDistanceFromTraders");
_distFromJammers = getNumber(_cfgEpoch >> "spawnDistanceFromJammers");
_distFromPlayers = getNumber(_cfgEpoch >> "spawnDistanceFromPlayers");
_return = true;

//CHECK FOR PROTECTED AREA WITIN CONFIG RANGE
if(_traderCheck)then{
	_restricted = nearestObjects [_position, ["ProtectionZone_Invisible_F"], _distFromTraders];
	if(count _restricted > 0) then {
		_return = false;
	};
};

//CHECK FOR JAMMERS IN THE AREA WITHIN CONFIG RANGE
if(_jammerCheck)then{
	_jammers = nearestObjects[_position, ["PlotPole_EPOCH"], _distFromJammers];
	if(count _jammers > 0) then {
		_return = false;
	};
};

//CHECK TO SEE IF PLAYERS WITHIN CONFIG RANGE
if(_playerCheck)then{
	_playersNearby = _position nearEntities[["Epoch_Male_F", "Epoch_Female_F"], _distFromPlayers];
	if(count _playersNearby > 0) then {
		_return = false;
	};
};

//CHECK FOR OTHERS
if!(_others isEqualTo [[0,0,0]])then{
	{
		if!(_x distance _position > _distFromOthers)then{
			_return = false;
		};
	}forEach _others;
};
_return