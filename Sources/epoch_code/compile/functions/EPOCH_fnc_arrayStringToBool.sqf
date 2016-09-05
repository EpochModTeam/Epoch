// fix strings to bool
_this apply {if (_x isEqualType "true") then {_x isEqualTo "true"} else {_x}}
