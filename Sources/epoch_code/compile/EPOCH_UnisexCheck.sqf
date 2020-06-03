/*
	Author: Aaron Clark - EpochMod.com

    Contributors:

	Description:
	Unisex check for vests, gives swing ammo and performs radio changed check

    Licence:
    Arma Public License Share Alike (APL-SA) - https://www.bistudio.com/community/licenses/arma-public-license-share-alike

    Github:
    https://github.com/EpochModTeam/Epoch/tree/release/Sources/epoch_code/compile/EPOCH_UnisexCheck.sqf
*/
//[[[cog import generate_private_arrays ]]]
private ["_config","_femaleVariant","_mags","_maleVariant","_vest","_vestItems","_woman"];
//[[[end]]]
params ["_unit","_container","_item"];

// check for access of a locked container
if (_container getVariable['EPOCH_Locked', false]) then {
	// kick player, TODO: temp ban?
	EPOCH_kicked = format ["%1 attempted to access a locked %2 with %3",_unit,_container,_item];
	publicVariableServer "EPOCH_kicked";
};

_mags = (magazines player) + (handgunMagazine player);
// TODO optimize
if (_item in ["Hatchet","CrudeHatchet"]) then {
	if !("Hatchet_swing" in _mags) then {
		player addMagazine "Hatchet_swing";
	};
};
if (_item in ["MeleeSledge","MeleeMaul","MeleeSword","Power_Sword"]) then {
	if !("sledge_swing" in _mags) then {
		player addMagazine "sledge_swing";
	};
};
if (_item in ["WoodClub","Plunger","MeleeRod"]) then {
	if !("stick_swing" in _mags) then {
		player addMagazine "stick_swing";
	};
};

//Radio Check
if (configName(inheritsFrom(configFile >> "CfgWeapons" >> _item)) == "ItemRadio") then {
	if (_item in(assignedItems player)) then {
		EPOCH_equippedItem_PVS = [_item,true,player];
	};
};

if (_item in ["EnergyPack","EnergyPackLg"] && (typeof _container) in ["SolarCharger_EPOCH","SolarChargerXL_EPOCH"]) then {
	["Stop Charging ...",5,[[1,0,0,0.2],[1,1,1,1]]] call Epoch_Message;
};

// Unisex vest check
_woman = getNumber(configFile >> "CfgVehicles" >> (typeOf player) >> "woman");
_config = configfile >> "cfgweapons" >> _item;
if (_woman == 1) then {
	if (isClass _config) then {
		if (isText (_config >> "femaleVest")) then {
			_femaleVariant = getText (_config >> "femaleVest");
			_vest = vest player;
			if (_item == _vest) then {
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
			if (_item == _vest) then {
				if (_maleVariant != _vest) then {
					removeVest player;
					player addVest _maleVariant;
				};
			};
		};
	};
};

_tocheckfor = switch _item do {
	case (uniform player): {uniformcontainer player};
	case (vest player): {vestcontainer player};
	case (backpack player): {backpackcontainer player};
	default {objnull};
};
if (!isnull _tocheckfor) then {
	{
		_target = _x;
		_subcontainers = everyContainer _target;
		{
			_subcontainer = _x;
			if (_tocheckfor == (_subcontainer select 1)) then {
				switch _item do {
					case (uniform player): {removeUniform player;};
					case (vest player): {removeVest player;};
					case (backpack player): {removeBackpack player;};
				};
			};
		} foreach _subcontainers;
	} foreach (nearestobjects [player,['WeaponHolder','WeaponHolderSimulated','MAN','Landvehicle','SHIP','AIR','ReammoBox_F'],10]);
};
