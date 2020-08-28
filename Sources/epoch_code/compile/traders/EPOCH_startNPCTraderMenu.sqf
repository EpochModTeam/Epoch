/*
	Author: He-Man - Ignatz-Gaming

    Contributors: Raimonds Virtoss

	Description:
	Start the Trader Trading Menu

    Licence:
    Arma Public License Share Alike (APL-SA) - https://www.bistudio.com/community/licenses/arma-public-license-share-alike

    Github:
    https://github.com/EpochModTeam/Epoch/tree/release/Sources/epoch_code/compile/traders/EPOCH_startNPCTraderMenu.sqf
*/

private ["_config","_MainCategoriearray","_target","_slot","_index","_ok","_categorie"];
_config = 'CfgItemSort' call EPOCH_returnConfig;
_MainCategoriearray = getarray (_config >> "MainCategories" >> "Classes");
_target = cursorTarget;
if (alive _target) then {
	_slot = _target getVariable ["AI_SLOT",-1];
	if (_slot != -1) then {
		EPOCH_lastNPCtradeTarget = _target;
		EPOCH_NpcTradePlayerItems = (items player)+(magazinesammo player);
		if (primaryWeapon player != "") then {
			EPOCH_NpcTradePlayerItems pushback [primaryWeapon player,"Hand"];
		};
		if (secondaryWeapon player != "") then {
			EPOCH_NpcTradePlayerItems pushback [secondaryWeapon player,"Hand"];
		};
		if (handgunWeapon player != "") then {
			EPOCH_NpcTradePlayerItems pushback [handgunWeapon player,"Hand"];
		};
		if (count backpackItems player == 0 && count backpackmagazines player == 0 && backpack player != "") then {
			EPOCH_NpcTradePlayerItems pushback backpack player;
		};
		EPOCH_NpcTradeTraderItems = [[],[]];
		{
			_index = _foreachindex;
			{
				(EPOCH_NpcTradeTraderItems select _index) pushback _x;
			} foreach _x
		} foreach (_target getvariable ["AI_Items",[[],[]]]);
		closeDialog 0;
		_ok = createdialog "TradeNPCMenu";
		if (!_ok) exitWith {};
		9992 cutRsc["EpochGameUI2", "PLAIN", 2, false];
		((uiNamespace getVariable "EPOCH_EpochGameUI2") displayCtrl 21208) ctrlSetText format["%1", EPOCH_playerCrypto];
		{
			_categorie = _x select 1;
			lbAdd [42100,_categorie];
			lbAdd [42101,_categorie]
		} forEach _MainCategoriearray;
		if !(primaryweapon player isEqualTo "") then {
			_idx = lbAdd [42101,format ["Fits %1",(primaryweapon player) call EPOCH_itemDisplayName]];
			lbSetColor [42101, _idx, [1, 1, 0, 1]];
		};
		if !(secondaryweapon player isEqualTo "") then {
			_idx = lbAdd [42101,format ["Fits %1",(secondaryweapon player) call EPOCH_itemDisplayName]];
			lbSetColor [42101, _idx, [1, 1, 0, 1]];
		};
		if !(handgunweapon player isEqualTo "") then {
			_idx = lbAdd [42101,format ["Fits %1",(handgunweapon player) call EPOCH_itemDisplayName]];
			lbSetColor [42101, _idx, [1, 1, 0, 1]];
		};
		lbSetCurSel [42100, 0];
		lbSetCurSel [42101, 0];
	};
};
