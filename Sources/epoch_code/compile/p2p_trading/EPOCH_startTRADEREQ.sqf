/*
	Author: Aaron Clark - EpochMod.com

    Contributors:

	Description:
	P2P trade request

    Licence:
    Arma Public License Share Alike (APL-SA) - https://www.bistudio.com/community/licenses/arma-public-license-share-alike

    Github:
    https://github.com/EpochModTeam/Epoch/tree/release/Sources/epoch_code/compile/p2p_trading/EPOCH_startTRADEREQ.sqf
*/
//[[[cog import generate_private_arrays ]]]
private ["_distance"];
//[[[end]]]
params ["_otherPlyr"];
if (!isNull _otherPlyr) then {
	_distance = player distance _otherPlyr;
	if (_distance < 10) then  {
		if (vehicle player == player && vehicle _otherPlyr == _otherPlyr) then {
			_this remoteExec ["EPOCH_server_tradeRequest",2];
			EPOCH_p2ptradeTarget = _otherPlyr;
			call EPOCH_startTrade;
		};
	};
};
