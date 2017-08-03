/*
	Author: Raimonds Virtoss - EpochMod.com

    Contributors:

	Description: manages drawing of favbar changes

    Licence:
    Arma Public License Share Alike (APL-SA) - https://www.bistudio.com/community/licenses/arma-public-license-share-alike

    Github:
    https://github.com/EpochModTeam/Epoch/tree/release/Sources/epoch_code/gui/scripts/favBar/epoch_favBar_draw.sqf

	Usage: none
*/
disableSerialization;
private ["_action","_idx","_bidx","_mod","_baritems","_Fav_BannedItems"];
params ["_action","_idx","_bidx","_mod"];
_Fav_BannedItems = ["CfgEpochClient", "Fav_BannedItems", []] call EPOCH_fnc_returnConfigEntryV2;

switch _action do {
	case "load":
	{
		private ["_tmp","_c","_p"];
		rmx_var_favBar_MNone = profileNamespace getVariable ["rmx_var_favBar_MNone",["","","","",""]];
		rmx_var_favBar_MCtrl = profileNamespace getVariable ["rmx_var_favBar_MCtrl",["","","","",""]];
		rmx_var_favBar_MShift = profileNamespace getVariable ["rmx_var_favBar_MShift",["","","","",""]];
		rmx_var_favBar_MAlt = profileNamespace getVariable ["rmx_var_favBar_MAlt",["","","","",""]];
        {
            _baritems = _x;
            {
                if (_x in _Fav_BannedItems) then {
                    _baritems set [_foreachindex,""];
                };
            } foreach _x;
        } foreach [rmx_var_favBar_MNone,rmx_var_favBar_MCtrl,rmx_var_favBar_MShift,rmx_var_favBar_MAlt];
		
		rmx_var_favBar_current = rmx_var_favBar_MNone;
		
		waitUntil {uiSleep 0.1; ctrlShown (["fav_equipped", 1] call epoch_getHUDCtrl)};

		_tmp = ctrlPosition (["fav_pic_bg", 1] call epoch_getHUDCtrl);

		for "_i" from 1 to 5 do {
			_c = (["fav_equipped", _i] call epoch_getHUDCtrl);
			_c ctrlSetText "#(rgb,8,8,3)color(1,1,1,0.7)";
			_p = ctrlPosition _c;
			_p set [2, (_tmp select 2)/10];
			_p set [3, (_tmp select 3)/10];
			_c ctrlSetPosition _p;
			_c ctrlCommit 0;
		};
		
		call epoch_favBar_drawCurrent;
		call epoch_favBar_refresh;
	};
	case "add":
	{
		private ["_type","_isBanned","_isAmmo","_isChemlight","_itemIsWeapon","_itemHasInteraction","_c"];
		if (rmx_var_favBar_Item in _Fav_BannedItems) exitWith {"Item is not allowed in favorites!" call epoch_message; false};
		if (rmx_var_favBar_Item in rmx_var_favBar_current) exitWith {"Item already exists in favorites!" call epoch_message; false}; //if duplicate
		
		_type = (rmx_var_favBar_Item call BIS_fnc_itemType) select 1;
		_isBanned = _type in ["BombLauncher", "Cannon", "GrenadeLauncher", "Launcher", "MissileLauncher", "RocketLauncher", "Magazine", "Mortar", "Shotgun","Rocket","Grenade"];
		_isAmmo = _type == "Bullet" && !(rmx_var_favBar_Item in ["EnergyPack","EnergyPackLg"]); 
		_isChemlight = rmx_var_favBar_Item in ["Chemlight_green","Chemlight_red","Chemlight_yellow","Chemlight_blue"];
		
		//if (_type in ["AccessoryMuzzle","AccessoryPointer","AccessorySights","AccessoryBipod"]) exitWith {"Attachments are not supported at the moment!" call epoch_message; false};
		if (_isBanned || _isAmmo || _isChemlight) exitWith {"Item cannot be added to favorites!" call epoch_message; false}; //Don't allow certain types
		
		_itemIsWeapon = [rmx_var_favBar_Item, "CfgWeapons"] call EPOCH_fnc_isAny;
		_itemHasInteraction = str(missionConfigFile >> "CfgItemInteractions" >> rmx_var_favBar_Item) != "";
		
		if (!_itemIsWeapon && !_itemHasInteraction && rmx_var_favBar_Item == "") exitWith {"Please equip item first and try again!" call epoch_message; false}; //Workaround
		
		rmx_var_favBar_current set [_idx,rmx_var_favBar_Item];
		
		switch EPOCH_modKeys do {
			case [true,false,false]: //shift
			{
				rmx_var_favBar_MShift set [_idx,rmx_var_favBar_Item]; 
				profileNamespace setVariable ["rmx_var_favBar_MShift",rmx_var_favBar_MShift];
				rmx_var_favBar_current = rmx_var_favBar_MShift;
			};
			case [false,true,false]: //Ctrl
			{
				rmx_var_favBar_MCtrl set [_idx,rmx_var_favBar_Item]; 
				profileNamespace setVariable ["rmx_var_favBar_MCtrl",rmx_var_favBar_MCtrl];
				rmx_var_favBar_current = rmx_var_favBar_MCtrl;
			};
			case [false,false,true]: //Alt
			{
				rmx_var_favBar_MAlt set [_idx,rmx_var_favBar_Item]; 
				profileNamespace setVariable ["rmx_var_favBar_MAlt",rmx_var_favBar_MAlt];
				rmx_var_favBar_current = rmx_var_favBar_MAlt;
			};
			default { //Any other combo or no modifier
				rmx_var_favBar_MNone set [_idx,rmx_var_favBar_Item]; 
				profileNamespace setVariable ["rmx_var_favBar_MNone",rmx_var_favBar_MNone];
				rmx_var_favBar_current = rmx_var_favBar_MNone;
			};
		};
		//draw current here
		if !(rmx_var_favBar_Item isEqualTo "") then {
			_c = (["fav_pic", _idx+1] call epoch_getHUDCtrl);
			_c ctrlSetText (rmx_var_favBar_Item call EPOCH_itemPicture);
		};
	};
	case "remove":
	{
		if (_bidx == 1) then { //if right mouse click
			rmx_var_favBar_current set [_idx,""];
			_c = (["fav_pic", _idx+1] call epoch_getHUDCtrl);
			_c ctrlSetText "";
		};
	};
	default {systemChat "fail"};
};

for "_i" from 1 to 5 do {
	(["fav_pic_bg", _i] call epoch_getHUDCtrl) ctrlSetText "x\addons\a3_epoch_code\Data\UI\favbar\fav_bg.paa";
};
true
