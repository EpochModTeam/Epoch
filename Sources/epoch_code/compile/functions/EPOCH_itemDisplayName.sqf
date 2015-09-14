
private ["_item"];
_item = _this;
_return = "";

if ([_item, "CfgVehicles"] call EPOCH_fnc_isAny) then {
  _return = getText(configfile >> "CfgVehicles" >> _item >> "DisplayName");
} else {
	if ([_item, "CfgWeapons"] call EPOCH_fnc_isAny) then {
	  _return = getText(configfile >> "CfgWeapons" >> _item >> "DisplayName");
	} else {
		if ([_item, "CfgMagazines"] call EPOCH_fnc_isAny) then {
		  _return = getText(configfile >> "CfgMagazines" >> _item >> "DisplayName");
		};
	};
};
_return;
