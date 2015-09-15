if (typeName _this == "SCALAR") then {
  EPOCH_playerCrypto = _this;
  9992 cutRsc["EpochGameUI2", "PLAIN", 2, false];
  ((uiNamespace getVariable "EPOCH_EpochGameUI2") displayCtrl 21208) ctrlSetText format["%1", EPOCH_playerCrypto];
};
