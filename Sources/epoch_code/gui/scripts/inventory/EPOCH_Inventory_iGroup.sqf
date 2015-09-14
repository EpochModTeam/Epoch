disableSerialization;
(findDisplay 602) closeDisplay 0;
if !(Epoch_invited_GroupUIDs isEqualTo[]) exitWith {
	createDialog "GroupRequests";
};
_dt = ["<t size = '0.8' shadow = '0' color = '#99ffffff'>No pending requests< / t>", 0, 1, 5, 2, 0, 1] spawn bis_fnc_dynamictext;
