/*
	Author: He-Man - EpochMod.com

	Contributors:

	Description:
	Change PlayerLoadout

	Licence:
	Arma Public License Share Alike (APL-SA) - https://www.bistudio.com/community/licenses/arma-public-license-share-alike

	Github:
    https://github.com/EpochModTeam/Epoch/tree/release/Sources/epoch_code/compile/inventory/EPOCH_SetUnitLoadout.sqf
*/
//[[[cog import generate_private_arrays ]]]
private ["_type","_loadabs"];
//[[[end]]]

params ["_newPlyr","_loadout",["_key",-1000]];
_tmpkey = (missionNamespace getVariable _playerRandomVarKey);
if (isnil "_tmpkey") exitwith {};
if !(_key isEqualTo (missionNamespace getVariable _playerRandomVarKey)) exitwith {};
				
//	_loadout params ["_primaryarr","_secondaryarr","_handgunarr","_uniformarr","_vestarr","_bpackarr","_HeadGear","_Glasses","_Rangefinderarr","_LinedItemsarr"];
_loadout = +_loadout;
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
					_container addWeaponWithAttachmentsCargoGlobal _x;
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

/*
_loadabs = loadabs _newPlyr;
if !(uniform _newPlyr isequalto _uniform && vest _newPlyr isequalto _vest && backpack _newPlyr isequalto _bpack) then {
	diag_log format ["EPOCH Debug: Setunitloadout failed - Unifmorm should: %1 is: %2 - Vest should: %3 is: %4 - Backpack should: %5 is: %6",_uniform,uniform _newPlyr,_vest,vest _newPlyr,_bpack,backpack _newPlyr];
	_loadabs = -1;
};

_loadabs
*/