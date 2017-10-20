EPOCH_dbg_replaceBrackets = {
    _return = [];
    {
        _string = _x;
        if (_string == 93) then {
            _string = 125;
        };
        if (_string == 91) then {
            _string = 123;
        };
        _return pushBack _string;
    } forEach toArray(format['%1',_this]);
    _return = toString _return;
    _return
};


_memoryPoints = [];
_points = ["NF2","SF2","EF2","WF2","C","CB","CinN","CinE","CinS","CinW","N","E","S","W","NE","NW","SE","SW","NF","SF","EF","WF"];
{
	_memoryPos = cursorObject selectionPosition [_x,"Memory"];
	if !(_memoryPos isEqualTo [0,0,0]) then {
		_memoryPoints pushBack [_x,_memoryPos];
	};
} forEach _points;


_configStr = "// snap points for " + typeOf cursorObject + "
";
{
	_configStr = _configStr + format['%1[] = %2;
',_x select 0,(_x select 1) call EPOCH_dbg_replaceBrackets];
} forEach _memoryPoints;


copyToClipboard _configStr;
