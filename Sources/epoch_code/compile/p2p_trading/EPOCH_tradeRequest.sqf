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
private ["_dt"];
if !(isNull _this) then {
	// ignore request if either player is in a vehicle
	if (vehicle player == player && vehicle _this == _this) then {
		_dt = ["<t size='0.8' shadow='0' color='#99ffffff'>Trade request received, press 'T' to accept</t>", 0, 1, 5, 2, 0, 1] spawn bis_fnc_dynamictext;
		EPOCH_pendingP2ptradeTarget = _this;
	};
};
