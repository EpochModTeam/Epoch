_control = _this select 0;
_textArr = toArray(ctrlText(_control select 0));
{
	if !(_x in [48,49,50,51,52,53,54,55,56,57]) then {
		_textArr = _textArr - [_x];
	};
} forEach _textArr;
if (count _textArr > 10) then {
	_textArr resize 10;
};
_num = parseNumber(toString _textArr) min (_this select 1);
(_control select 0) ctrlSetText str(_num);