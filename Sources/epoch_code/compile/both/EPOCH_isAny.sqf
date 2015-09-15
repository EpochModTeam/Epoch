private ["_item","_return"];
_item = _this select 0;
_type = _this select 1;
_return = str(configFile >> _type >> _item) != "";
_return
