/*
	Author: Aaron Clark - EpochMod.com

    Contributors: He-Man

	Description:
	NPC trade filter code

    Licence:
    Arma Public License Share Alike (APL-SA) - https://www.bistudio.com/community/licenses/arma-public-license-share-alike

    Github:
    https://github.com/EpochModTeam/Epoch/tree/release/Sources/epoch_code/traders/EPOCH_NPCTraderMenuFilter.sqf

    Example:
    onLBSelChanged = "_this call EPOCH_NPCTraderMenuFilter";

    Parameter(s):
		_this select 0: CONTROL
        _this select 1: NUMBER - Index ID

	Returns:
	NOTHING
*/
disableSerialization;
//[[[cog import generate_private_arrays ]]]
private ["_aiItems","_bpck","_config","_filterArray","_filterItems","_filterMagazines","_filterVehicle","_filterWeapons","_index","_isPlayerFilter","_item","_itemCount","_itemIcon","_itemName","_itemOfferCount","_items","_name","_offerArray","_picture","_qty","_qtys","_sizeOut","_slot","_type","_vehicles","_wpn"];
//[[[end]]]
params ["_control","_index"];

if !(isNull EPOCH_lastNPCtradeTarget) then {
	_slot = EPOCH_lastNPCtradeTarget getVariable["AI_SLOT", -1];
	_isPlayerFilter = (ctrlIDC _control == 42100);
	if (_slot != -1) then {

		_filterArray = [
			[true,true,true,true], 	  // all
			// [true,false,false,false], // weapons only
			[false,true,false,false], // mags only
			[false,false,true,false], // items only
			[false,false,false,true]  // vehicles only
		];

		//_filterWeapons = ((_filterArray select _index) select 0);
		_filterMagazines = ((_filterArray select _index) select 1);
		_filterItems = ((_filterArray select _index) select 2);
		_filterVehicle = ((_filterArray select _index) select 3);

		if (_isPlayerFilter) then {

			_sizeOut = lbSize 41501;
			_offerArray = [];
			if (_sizeOut > 0) then {
				for "_i" from 0 to (_sizeOut - 1) do {
					_item = lbData [41501, _i];
					_offerArray pushBack _item;
				};
			};

			lbClear 41500;

			if (_filterMagazines) then {
				{
					// make sure this exceeds the item count already offered
					_item = _x;
					_itemCount = {_x == _item} count magazines player;
					_itemOfferCount = {_x == _item} count _offerArray;
					if (_itemCount > _itemOfferCount) then {
						_offerArray pushBack _item;
						_index = lbAdd [41500, _x call EPOCH_itemDisplayName];
						lbSetData [41500, _index, _x];
						lbSetPicture [41500, _index, _x call EPOCH_itemPicture];
					};
				} forEach magazines player;
			};

			/* not used currently
			if (_filterWeapons) then {
			};
			*/

			if (_filterItems) then {
				{
					_item = _x;
					_itemCount = {_x == _item} count items player;
					_itemOfferCount = {_x == _item} count _offerArray;
					if (_itemCount > _itemOfferCount) then {
						_offerArray pushBack _item;
						_index = lbAdd [41500, _x call EPOCH_itemDisplayName];
						lbSetData [41500, _index, _x];
						lbSetPicture [41500, _index, _x call EPOCH_itemPicture];
					};
				} forEach items player;
				if (primaryWeapon player != "") then {
					_wpn = primaryWeapon player;
					_offerArray pushback _wpn;
					_index = lbAdd [41500, _wpn call EPOCH_itemDisplayName];
					lbSetData [41500, _index, _wpn];
					lbSetPicture [41500, _index, _wpn call EPOCH_itemPicture];
				};
				if (count backpackItems player == 0 && count backpackmagazines player == 0 && backpack player != "") then {
					_bpck = Backpack player;
					_offerArray pushback _bpck;
					_index = lbAdd [41500, _bpck call EPOCH_itemDisplayName];
					lbSetData [41500, _index, _bpck];
					lbSetPicture [41500, _index, _bpck call EPOCH_itemPicture];
				};
			};

			if (_filterVehicle) then {
				_vehicles = player nearEntities [["LandVehicle","Ship","Air","Tank"], 30];
				{
					if (local _x) then {
						_type = typeOf _x;
						_itemCount = { typeOf _x == _type } count _vehicles;
						_itemOfferCount = { _x == _type } count _offerArray;
						if (_itemCount > _itemOfferCount) then {
							_offerArray pushBack _type;

							_config = configFile >> "CfgVehicles" >> _type;

							_name = getText(_config >> "displayName");
							_picture = getText(_config >> "picture");

							_index = lbAdd[41500, _name];
							lbSetData[41500, _index, _type];
							lbSetPicture[41500, _index, _picture];
						};
					};
				} forEach _vehicles;
			};

		} else {

			lbClear 41503;

			_sizeOut = lbSize 41502;
			_offerArray = [];
			if (_sizeOut > 0) then {
				for "_i" from 0 to (_sizeOut - 1) do {
					_item = lbData [41502, _i];
					_offerArray pushBack _item;
				};
			};
			_aiItems = EPOCH_lastNPCtradeTarget getVariable["AI_ITEMS", []];
			if ((count _aiItems) == 2) then {
				_items = _aiItems select 0;
				_qtys = _aiItems select 1;
				{

					_item = _x;
					_itemName = "";
					_itemIcon = "";
					if ([_item, "CfgVehicles"] call EPOCH_fnc_isAny) then {
						if (_filterVehicle) then {
							_itemName = getText(configfile >> "CfgVehicles" >> _item >> "DisplayName");
				  			_itemIcon = getText(configfile >> "CfgVehicles" >> _item >> "picture");
						};
					} else {
						if ([_item, "CfgWeapons"] call EPOCH_fnc_isAny) then {
							if (_filterItems) then {
								_itemName = getText(configfile >> "CfgWeapons" >> _item >> "DisplayName");
								_itemIcon = getText(configfile >> "CfgWeapons" >> _item >> "picture");
							};
						} else {
							if ([_item, "CfgMagazines"] call EPOCH_fnc_isAny) then {
								if (_filterMagazines) then {
									_itemName = getText(configfile >> "CfgMagazines" >> _item >> "DisplayName");
									_itemIcon = getText(configfile >> "CfgMagazines" >> _item >> "picture");
								};
							};
						};
					};
					if (_itemName != "") then {

						_qty = ((_qtys select _forEachIndex) - ({_x == _item} count _offerArray));
						if (_qty > 0) then {

							// _offerArray pushBack _item;
							_index = lnbAddRow[41503, ["", str(_qty), _itemName]];
							lnbSetData [41503, [_index,0], _item];
							lnbSetValue [41503, [_index,0], _qty];
							lnbSetPicture [41503, [_index,0], _itemIcon];
						};
					};

				} forEach _items;
			};
		};
	};
} else {
	closeDialog 0;
};
