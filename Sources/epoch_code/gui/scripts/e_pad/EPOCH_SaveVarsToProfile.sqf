params ["_type","_var","_value"];
_arr = profilenamespace getvariable [_type,[[],[]]];
_find = (_arr select 0) find _var;
if (_find > -1) then {
	(_arr select 1) set [_find, _value];
}
else {
	(_arr select 0) pushback _var;
	(_arr select 1) pushback _value;
};
profilenamespace setvariable [_type,_arr];
saveprofilenamespace;
