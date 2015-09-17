if (typename _this != "ARRAY") then {
	_this = [_this];
};

{
	if (!isNull _x) then {
		_x addEventHandler["local", {
			if (_this select 1) then {
				private "_unit";
				_unit = _this select 0;
				{
					_unit removeAllMPEventHandlers _x;
				}forEach ["mpkilled","mphit","mprespawn"];
				{
					_unit removeAllEventHandlers _x;
				}forEach ["FiredNear","HandleDamage","Killed","Fired","GetOut","GetIn","Local"];
				deleteVehicle _unit;
				deleteGroup (group _unit);
			};
		}];
	};
}forEach _this;
