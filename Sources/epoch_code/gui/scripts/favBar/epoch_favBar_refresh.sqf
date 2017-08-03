/*
	Author: Raimonds Virtoss - EpochMod.com

    Contributors:

	Description: This is called by event1.sqf every 1 second as well as every time mod key is pressed.

    Licence:
    Arma Public License Share Alike (APL-SA) - https://www.bistudio.com/community/licenses/arma-public-license-share-alike

    Github:
    https://github.com/EpochModTeam/Epoch/tree/release/Sources/epoch_code/gui/scripts/favBar/epoch_favBar_refresh.sqf

	Usage: none
*/

if !(["CfgEpochClient", "Fav_enableFavoriteBar", true] call EPOCH_fnc_returnConfigEntryV2) exitWith {false};
private ["_playerItems","_equipped","_mod","_txt"];

_playerItems = itemsWithMagazines  player;
_equipped = [primaryWeapon player, secondaryWeapon player, handgunWeapon player, headgear player, goggles player, hmd player, binocular player];
_equipped append (primaryWeaponItems player + primaryWeaponMagazine player + secondaryWeaponItems  player + secondaryWeaponMagazine  player + handgunItems player + handgunMagazine player);
_equipped append (assignedItems player);

_mod = switch EPOCH_modKeys do {
	case [true,false,false]: {"Shift + "};
	case [false,true,false]: {"Ctrl + "};
	case [false,false,true]: {"Alt + "};
	default {""};
};

for "_i" from 1 to 5 do {
	_txt = missionNamespace getVariable [format["EPOCH_keysfav%1",_i],"N/A"];
	(["fav_keymap", _i] call epoch_getHUDCtrl) ctrlSetText (_mod + (_txt call BIS_fnc_keyCode));
};

{
	if (_x != "") then {
		(["fav_pic_bg", _forEachIndex + 1] call epoch_getHUDCtrl) ctrlShow true;
		(["fav_keymap", _forEachIndex + 1] call epoch_getHUDCtrl) ctrlShow true;
		
		if (_x in _playerItems) then {
			(["fav_pic", _forEachIndex + 1] call epoch_getHUDCtrl) ctrlSetTextColor [1,1,1,1];
		} else {
			(["fav_pic", _forEachIndex + 1] call epoch_getHUDCtrl) ctrlSetTextColor [1,0,0,1];
		};
		
		if (_x in _equipped) then {
			(["fav_pic", _forEachIndex + 1] call epoch_getHUDCtrl) ctrlSetTextColor [1,1,1,1];
			(["fav_equipped", _forEachIndex + 1] call epoch_getHUDCtrl) ctrlShow true;
		} else {
			(["fav_equipped", _forEachIndex + 1] call epoch_getHUDCtrl) ctrlShow false;
		};
	} else {
		(["fav_equipped", _forEachIndex + 1] call epoch_getHUDCtrl) ctrlShow false;
		
		if (isNull findDisplay 602) then {
			(["fav_pic_bg", _forEachIndex + 1] call epoch_getHUDCtrl) ctrlShow false;
			(["fav_keymap", _forEachIndex + 1] call epoch_getHUDCtrl) ctrlShow false;
		};
	};
}forEach rmx_var_favBar_current;
true 