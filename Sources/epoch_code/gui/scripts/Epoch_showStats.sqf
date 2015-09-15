disableSerialization;

9992 cutRsc["EpochGameUI2", "PLAIN", 2, false];
_display = uiNamespace getVariable "EPOCH_EpochGameUI2";
(_display displayCtrl 21208) ctrlSetText format["%1", EPOCH_playerCrypto];

9993 cutRsc["EpochGameUI3", "PLAIN", 2, false];
_display3 = uiNamespace getVariable "EPOCH_EpochGameUI3";
(_display3 displayCtrl 21210) ctrlSetText format["%1/%2", round(EPOCH_playerEnergy), EPOCH_playerEnergyMax];