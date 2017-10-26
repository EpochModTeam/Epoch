/*
	Author: Raimonds Virtoss - EpochMod.com

    Contributors:

	Description: Returns className of an item or weapon from inventory IDC
				This function has no practical use outside of Favorite Bar menu due to IDC used as a case

    Licence:
    Arma Public License Share Alike (APL-SA) - https://www.bistudio.com/community/licenses/arma-public-license-share-alike

    Github:
    https://github.com/EpochModTeam/Epoch/tree/release/Sources/epoch_code/gui/scripts/favBar/epoch_favBar_getItemByIDC.sqf

	Usage: none
*/
private ["_item","_ammo","_cnt"];
//switch

_item = switch (_this) do {
	case 610: //Primary
	{
		primaryWeapon player
	};
	case 620: //Primary silencer
	{
		(primaryWeaponItems player) select 0
	};
	case 621: //Primary Optic (TWS)
	{
		(primaryWeaponItems player) select 2
	};
	case 622: //Primary Flashlight/Laser
	{
		(primaryWeaponItems player) select 1
	};
	case 641: //Primary bipod
	{
		(primaryWeaponItems player) select 3
	};
	case 644: //Primary Grenade shell
	{
		_ammo = primaryWeaponMagazine player;
		_cnt = count _ammo;
		if (_cnt > 0) then {
			if (_cnt > 1) then {
				_ammo select 1
			} else {
				_ammo select 0
			};
		} else {""};
	};
	case 623: //Primary Magazine
	{
		_ammo = primaryWeaponMagazine player;
		_cnt = count _ammo;
		if (_cnt > 0) then {
			_ammo select 0
		} else {""};
	};
	case 611: //Secondary
	{
		secondaryWeapon player
	};
	case 624: //Secondary silencer
	{
		(secondaryWeaponItems  player) select 0
	};
	case 625: //Secondary Optic (TWS)
	{
		(secondaryWeaponItems  player) select 2
	};
	case 626: //Secondary Flashlight/Laser
	{
		(secondaryWeaponItems  player) select 1
	};
	case 642: //Secondary bipod
	{
		(secondaryWeaponItems  player) select 3
	};
	case 627: //Secondary Magazine
	{
		_ammo = secondaryWeaponMagazine player;
		_cnt = count _ammo;
		if (_cnt > 0) then {
			_ammo select 0
		} else {""};
	};
	case 612: //Handgun
	{
		handgunWeapon player
	};
	case 628: //Handgun silencer
	{
		(handgunItems player) select 0
	};
	case 629: //Handgun Optic (TWS)
	{
		(handgunItems player) select 2
	};
	case 630: //Handgun Flashlight/Laser
	{
		(handgunItems player) select 1
	};
	case 643: //Handgun bipod
	{
		(handgunItems player) select 3
	};
	case 631: //Handgun Magazine
	{
		_ammo = handgunMagazine player;
		_cnt = count _ammo;
		if (_cnt > 0) then {
			_ammo select 0
		} else {""};
	};
	case 6240: //headgear
	{
		headgear player;
	};
	case 6216: //goggles
	{
		goggles player;
	};
	case 6217: //hmd
	{
		hmd player;
	};
	case 6238: //goggles
	{
		binocular player;
	};
	default {""};
};

_item
