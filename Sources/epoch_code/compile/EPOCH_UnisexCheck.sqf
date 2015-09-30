private ["_femaleVariant","_vest","_class","_config","_woman","_maleVariant"];
_woman = getNumber(configFile >> "CfgVehicles" >> (typeOf player) >> "woman");
_class = _this select 2;
_config = configfile >> "cfgweapons" >> _class;

/*
_sleepAndCheck = {
	_good = true;
	_failcount = 0;
	switch _this do {
		case 0: {
			while {true} do {
				if !(local(backpackContainer player)) then {
					_good = false;
					_failcount = _failcount + 1;
				} else {
					_good = true;
				};
				if (_good) exitWith {};
				if (_failcount > 5) exitWith { removeBackpack player; };
				sleep 0.5;
			};
		};
		case 1: {
			while {true} do {
				if !(local(vestContainer player)) then {
					_good = false;
					_failcount = _failcount + 1;
				} else {
					_good = true;
				};
				if (_good) exitWith{};
				if (_failcount > 5) exitWith{ removeVest player; };
				sleep 0.5;
			};
		};
		case 2: {
			while {true} do {
				if !(local(uniformContainer player)) then {
					_good = false;
					_failcount = _failcount + 1;
				} else {
					_good = true;
				};
				if (_good) exitWith{};
				if (_failcount > 5) exitWith{ removeUniform player; };
				sleep 0.5;
			};
		};
	};
};


if (isclass _config) then {
	_infoType = getnumber(_config >> "itemInfo" >> "type");
	switch _infoType do {
		case 701: { 1 spawn _sleepAndCheck; };
		case 801: { 2 spawn _sleepAndCheck; };
	};
} else {
	if (getNumber(configFile >> "CfgVehicles" >> _class >> "isbackpack") == 1) then {
		0 spawn _sleepAndCheck;
	};
};
*/

_mags = (magazines player) + (handgunMagazine player);

// TODO optimize
if (_class in ["Hatchet","CrudeHatchet"]) then {
	if !("Hatchet_swing" in _mags) then {
		player addMagazine "Hatchet_swing";
	};
};
if (_class in ["MeleeSledge","MeleeMaul","MeleeSword"]) then {
	if !("sledge_swing" in _mags) then {
		player addMagazine "sledge_swing";
	};
};
if (_class in ["WoodClub","Plunger","MeleeRod"]) then {
	if !("stick_swing" in _mags) then {
		player addMagazine "stick_swing";
	};
};

//Radio Check
if (configName(inheritsFrom(configFile >> "CfgWeapons" >> _class)) == "ItemRadio") then {
	if (_class in(assignedItems player)) then {
		//diag_log "EQUPPED RADIO";
		EPOCH_equippedItem_PVS = [_class,true,player];
	};
};

if (_woman == 1) then {
	if (isClass _config) then {

		//diag_log format["DEBUG EPOCH_UnisexCheck: %1", _this];

		if (isText (_config >> "femaleVest")) then {
			_femaleVariant = getText (_config >> "femaleVest");
			_vest = vest player;
			if (_class == _vest) then {
				if (_femaleVariant != _vest) then {

					/* // everyContainer not working in 1.20
					_holder = _this select 1;
					_containers = (everyContainer _holder) select 0;
					_mags = magazinesAmmoFull _container;
					_weps = weaponCargo vestContainer _container;
					_item = itemCargo vestContainer _container;
					*/
					removeVest player;
					player addVest _femaleVariant;
					/*
					{
						if ((_x select 4) == "Vest") then {
							player addMagazine [(_x select 0),(_x select 1)]
						}
					} forEach _mags;

					{
						player addItemToVest _x;
					} forEach (_weps+_item);
					*/

				};
			};
		};
	};
} else {
	if (isClass _config) then {
		//diag_log format["DEBUG EPOCH_UnisexCheck: %1", _this];

		if (isText (_config >> "maleVest")) then {
			_maleVariant = getText (_config >> "maleVest");
			_vest = vest player;
			if (_class == _vest) then {
				if (_maleVariant != _vest) then {
					removeVest player;
					player addVest _maleVariant;
				};
			};
		};
	};
};
