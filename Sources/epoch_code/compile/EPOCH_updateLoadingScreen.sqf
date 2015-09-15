disableSerialization;
_display = uiNameSpace getVariable ["EPOCH_loadingScreen",displayNull];
if (!isNull _display) then {
  (_display displayCtrl 50) ctrlSetText _this;
};
