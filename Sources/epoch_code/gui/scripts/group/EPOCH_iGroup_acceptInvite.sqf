if (Epoch_invited_GroupUID != "") then {
	EPOCH_GROUP_Player_PVS = [Epoch_invited_GroupUID,getPlayerUID player,true,false,player,Epoch_personalToken];
	publicVariableServer "EPOCH_GROUP_Player_PVS";
};
(findDisplay -1500) closeDisplay 0;