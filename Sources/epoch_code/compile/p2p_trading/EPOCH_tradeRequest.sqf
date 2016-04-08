/*
	Author: Aaron Clark - EpochMod.com

    Contributors:

	Description:
	P2P trade request received

    Licence:
    Arma Public License Share Alike (APL-SA) - https://www.bistudio.com/community/licenses/arma-public-license-share-alike

    Github:
    https://github.com/EpochModTeam/Epoch/tree/master/Sources/epoch_code/compile/p2p_trading/EPOCH_tradeRequest.sqf
*/
if !(isNull _this) then {
	// ignore request if either player is in a vehicle
	if (vehicle player == player && vehicle _this == _this) then {
		["<t size='1.6' color='#99ffffff'>Trade request received, press 'T' to accept</t>", 5] call Epoch_dynamicText;
		EPOCH_pendingP2ptradeTarget = _this;
	};
};
