/*
	Author: He-Man - EpochMod.com

	Contributors:

	Description:
	Player Login

	Licence:
	Arma Public License Share Alike (APL-SA) - https://www.bistudio.com/community/licenses/arma-public-license-share-alike

	Github:
	https://github.com/EpochModTeam/Epoch/tree/release/Sources/epoch_server/compile/epoch_player/EPOCH_server_SetUnitLoadout.sqf
*/
//[[[cog import generate_private_arrays ]]]
private ["_type"];
//[[[end]]]

params ["_newPlyr","_loadout"];
				
//	_loadout params ["_primaryarr","_secondaryarr","_handgunarr","_uniformarr","_vestarr","_bpackarr","_HeadGear","_Glasses","_Rangefinderarr","_LinedItemsarr"];
_loadout params ["","","","_uniformarr","_vestarr","_bpackarr","","","",""];
_loadout set [3,[]];
_loadout set [4,[]];
_loadout set [5,[]];
_newPlyr setunitloadout _loadout;
_uniformarr params [["_uniform",""],["_uniformitems",[]]];
_vestarr params [["_vest",""],["_vestitems",[]]];
_bpackarr params [["_bpack",""],["_bpackitems",[]]];
if !(_uniform isequalto "") then {
	_newPlyr forceadduniform _uniform;
};
if !(_vest isequalto "") then {
	_newPlyr addVest _vest;
};
if !(_bpack isequalto "") then {
	_newPlyr addBackpack _bpack;
};
{
	_x params ["_container","_items"];
	if !(isnull _container) then {
		clearitemcargoglobal _container;
		clearbackpackcargoglobal _container;
		clearmagazinecargoglobal _container;
		clearweaponcargoglobal _container;
		{
			if (count _x > 2) then {
				_container addMagazineAmmoCargo _x;
			}
			else {
				if ((_x select 0) isequaltype []) then {
					_x params ["_arr","_cnt"];
					_type = _arr deleteat 0;
					_container addWeaponcargoglobal [_type,_cnt];
					{
						if !(_x isequalto "" || _x isequalto []) then {
							if (_x isequaltype []) then {
								_container addMagazineAmmoCargo [_x select 0,1,_x select 1];
							}
							else {
								_container addItemCargoGlobal [_x,1];
							};
						};
					} foreach _arr;
				}
				else {
					_x params [["_type",""],["_cnt",1]];
					if !(_cnt isequaltype 1) then {
						_cnt = 1;
					};
					if (_type iskindof "Bag_Base") then {
						_container addBackpackCargoGlobal [_type,_cnt];
					}
					else {
						_container addItemCargoGlobal [_type,_cnt];
					};
				};
			};
		} foreach _items;
	};
} foreach [
	[Uniformcontainer _newPlyr, _uniformitems],
	[Vestcontainer _newPlyr, _vestitems],
	[BackpackContainer _newPlyr, _bpackitems]
];
				

true
