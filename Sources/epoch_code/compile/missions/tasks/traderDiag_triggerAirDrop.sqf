if((random 100) < 6)then{
[] execFSM "\x\addons\a3_epoch_code\System\Event_Air_Drop.fsm";
["<t size='1.6' color='#99ffffff'>Air Drop Incoming !</t>", 5] call Epoch_dynamicText;
}else{
["<t size='1.6' color='#99ffffff'>Sorry, None Available!</t>", 5] call Epoch_dynamicText;
};