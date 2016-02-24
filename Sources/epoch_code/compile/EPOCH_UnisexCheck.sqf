/*
	Author: Aaron Clark - EpochMod.com

    Contributors:

	Description:
	Unisex check for vests, gives swing ammo and performs radio changed check

    Licence:
    Arma Public License Share Alike (APL-SA) - https://www.bistudio.com/community/licenses/arma-public-license-share-alike

    Github:
    https://github.com/EpochModTeam/Epoch/tree/master/Sources/epoch_code/compile/EPOCH_UnisexCheck.sqf
*/
private ["_femaleVariant","_vest","_class","_config","_woman","_maleVariant"];
_woman = getNumber(configFile >> "CfgVehicles" >> (typeOf player) >> "woman");
_class = _this select 2;
_config = configfile >> "cfgweapons" >> _class;

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
		EPOCH_equippedItem_PVS = [_class,true,player];
	};
};

if (_woman == 1) then {
	if (isClass _config) then {
		if (isText (_config >> "femaleVest")) then {
			_femaleVariant = getText (_config >> "femaleVest");
			_vest = vest player;
			if (_class == _vest) then {
				if (_femaleVariant != _vest) then {
					// get items in existing vest
					_vestItems = vestItems player;
					// remove vest
					removeVest player;
					// replace with female variant
					player addVest _femaleVariant;
					// readd items to players vest
					{player addItemToVest _x} forEach _vestItems;
				};
			};
		};
	};
} else {
	if (isClass _config) then {
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
