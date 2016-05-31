
_hour = str(date select 3);
_min = str(date select 4);

if(count _hour < 2)then{
_hour = "0" + _hour;
};

if(count _min < 2)then{
_min = "0" + _min;
};

[format ["<t size='1.6' color='#99ffffff'>The time is %1:%2.</t>",_hour, _min], 5] call Epoch_dynamicText;