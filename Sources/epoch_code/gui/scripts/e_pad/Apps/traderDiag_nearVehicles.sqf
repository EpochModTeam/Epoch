//[[[cog import generate_private_arrays ]]]
private ["_dist","_plyr","_trdrMsg","_veh","_vehs"];
//[[[end]]]
_trdrMsg = "Hey, there is a garage down the road.. Well, there used to be.";
_vehs = [];
_plyr = player;
_vehs = nearestObjects [_plyr, ["CAR","AIR"], 1000];
if (count _vehs < 1) then {
	_trdrMsg = format["%2 %1.",name _plyr,selectRandom["I haven't seen anything lately","There is nothing around here","The last time the UAV went out it found nothing"]];
} else {
	_veh = _vehs select (floor (random count _vehs));
	_dist = _veh distance _plyr;
	_trdrMsg = format["I know of at least one vehicle within about %1m. It looks like a %2.",round (_dist/2 + (random _dist)) , (typeof _veh) call EPOCH_itemDisplayName];
};
[_trdrMsg, 5,[[0,0,0,0.5],[1,0.5,0,1]]] call Epoch_message;
