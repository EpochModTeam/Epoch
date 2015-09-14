_dikCode =  _this select 1;
_shift =  _this select 2;
_ctrl =  _this select 3;
_alt =  _this select 4;

if (_ctrl && _dikCode == 0x39) then { call EPOCH_lootTrash; };