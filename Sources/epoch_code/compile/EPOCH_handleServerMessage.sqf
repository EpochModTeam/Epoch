if (isLocalized (_this select 0)) then{
 _dt = [format["<t size = ""0.8"" shadow = ""0"" color = ""#99ffffff"">%1</t>", format[localize (_this select 0), _this select 1]], 0, 1, 5, 2, 0, 1] spawn bis_fnc_dynamictext;
};
