disableSerialization;
(findDisplay 602) closeDisplay 0;
if !(Epoch_invited_GroupUIDs isEqualTo[]) exitWith {
	createDialog "GroupRequests";
};
["<t size = '1.6' color = '#99ffffff'>No pending requests< / t>", 5] call Epoch_dynamicText;
