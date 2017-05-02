//[[[cog import generate_private_arrays ]]]
private ["_hour","_min"];
//[[[end]]]
_hour = str(date select 3);
_min = str(date select 4);

if(count _hour < 2)then{
_hour = "0" + _hour;
};

if(count _min < 2)then{
_min = "0" + _min;
};

[format ["The time is %1:%2.",_hour, _min], 5] call Epoch_message;
