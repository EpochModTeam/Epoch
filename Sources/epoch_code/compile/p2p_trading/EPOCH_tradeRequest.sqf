/*
	Author: Aaron Clark - EpochMod.com

    Contributors:

	Description:
	P2P trade request received

    Licence:
    Arma Public License Share Alike (APL-SA) - https://www.bistudio.com/community/licenses/arma-public-license-share-alike

    Github:
    https://github.com/EpochModTeam/Epoch/tree/release/Sources/epoch_code/compile/p2p_trading/EPOCH_tradeRequest.sqf
*/
if !(isNull _this) then {
	// ignore request if either player is in a vehicle
	if (vehicle player == player && vehicle _this == _this) then {
		[format ["Trade request received, Hold (%1)",EPOCH_keysAction call BIS_fnc_keyCode], 5] call Epoch_message;
		EPOCH_pendingP2ptradeTarget = _this;
	};
};
