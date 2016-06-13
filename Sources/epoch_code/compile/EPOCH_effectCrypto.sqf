/*
	Author: Aaron Clark - EpochMod.com

    Contributors:

	Description:
	Epoch display kyrpto changes

    Licence:
    Arma Public License Share Alike (APL-SA) - https://www.bistudio.com/community/licenses/arma-public-license-share-alike

    Github:
    https://github.com/EpochModTeam/Epoch/tree/release/Sources/epoch_code/compile/EPOCH_effectCrypto.sqf
*/
if (_this isEqualType 0) then {
  EPOCH_playerCrypto = _this;
  9992 cutRsc["EpochGameUI2", "PLAIN", 2, false];
  ((uiNamespace getVariable "EPOCH_EpochGameUI2") displayCtrl 21208) ctrlSetText format["%1", EPOCH_playerCrypto];
};
