if (Epoch_invited_GroupUID != "") then {
	[Epoch_invited_GroupUID,getPlayerUID player,true,false,player,Epoch_personalToken] remoteExec ["EPOCH_server_updatePlayerGroup",2];
};
(findDisplay -1500) closeDisplay 0;
