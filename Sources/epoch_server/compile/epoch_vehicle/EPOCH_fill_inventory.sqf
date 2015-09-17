private ["_vehicle","_class","_qty"];
_vehicle = _this select 0;
if (!isNull _vehicle) then {
	//_type = _this select 1;
	_class = _this select 2;
	_qty = _this select 3;
	switch (_this select 1) do {
		case 0: { _vehicle addWeaponCargoGlobal[_class, _qty] };
		case 1: { _vehicle addBackpackCargoGlobal[_class, _qty] };
		case 2: { _vehicle addMagazineCargoGlobal[_class, _qty] };
		case 3: { _vehicle addItemCargoGlobal[_class, _qty] };
	};
};