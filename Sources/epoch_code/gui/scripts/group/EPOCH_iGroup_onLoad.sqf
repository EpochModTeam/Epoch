disableSerialization;
_display = findDisplay -1400;
if (Epoch_invited_GroupUID == "" || Epoch_invited_GroupName == "") exitWith { _display closeDisplay 0};
_text = _display displayCtrl 21;
_text ctrlSetText format ["Join the group called %1?",Epoch_invited_GroupName];