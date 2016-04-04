/*
	Author: Aaron Clark - EpochMod.com

    Contributors:

	Description:
	Server side spawing of shipwreck loots

    Licence:
    Arma Public License Share Alike (APL-SA) - https://www.bistudio.com/community/licenses/arma-public-license-share-alike

    Github:
    https://github.com/EpochModTeam/Epoch/tree/master/Sources/epoch_server/compile/epoch_missions/EPOCH_Server_fillContainer.sqf
*/
private["_player","_container","_clearFirst","_pos","_chance","_weps","_mags","_items"];
params ["_player",["_token","",[""]],["_container",objNull,[objNull]],["_clearFirst",false],["_chance",25],["_pos",getPosATL _player]];

if !([_player,_token]call EPOCH_server_getPToken)exitWith{};

if (isNull _container) then {
	_container = createVehicle ["GroundWeaponHolder", _pos, [], 12, "CAN_COLLIDE"];
	_container setPosATL _pos;
};

if (_clearFirst) then {
	clearWeaponCargoGlobal _container;
	clearItemCargoGlobal _container;
	clearMagazineCargoGlobal  _container;
	clearBackpackCargoGlobal _container;
};

if (_chance > 0) then {
	// TODO add separate loot tables for each payout type
	[_container, "Mission_Payout1"] call EPOCH_serverLootObject;
};
