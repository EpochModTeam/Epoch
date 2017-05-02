//[[[cog import generate_private_arrays ]]]
private ["_plyr","_plyrs","_trdrMsg"];
//[[[end]]]
_trdrMsg = "Do I look like the local Neighbourhood Watch..? No, I do not !";
_plyrs = [];
_plyrs = player nearEntities [["Epoch_Man_base_F","Epoch_Female_base_F"], 250];
if (count _plyrs < 2) then {
	_trdrMsg = format["Apart from you %1. %2",name player, selectRandom ["I haven't seen any round these parts for a long while.","It has been very quiet around here,","There is not much to report !"]];
} else {
	_plyrs deleteAt 0;
	_plyr = selectRandom _plyrs;
	_trdrMsg = format["%2 %1.",name _plyr, selectRandom ["The last person picked up by the UAV was","I did spot someone earlier, their name was","I heard there was somebody new in the area, "]];
};
[_trdrMsg, 5] call Epoch_message;
