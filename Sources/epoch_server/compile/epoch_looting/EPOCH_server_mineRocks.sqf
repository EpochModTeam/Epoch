/*
	Author: Aaron Clark - EpochMod.com

    Contributors:

	Description:
	Server side rock mining

    Licence:
    Arma Public License Share Alike (APL-SA) - https://www.bistudio.com/community/licenses/arma-public-license-share-alike

    Github:
    https://github.com/EpochModTeam/Epoch/tree/master/Sources/epoch_server/compile/epoch_looting/EPOCH_server_mineRocks.sqf
*/
private["_posWH", "_item", "_nearbyWH", "_rock"];
params ["_object","_index","_player",["_token","",[""]]];
if !([_player, _token] call EPOCH_server_getPToken) exitWith{};

if !(_object isKindOf "All") then {
	if (alive _object) then {

		_posWH = getPosATL _player;
		_posWH set[2, 0];

		// defaults
		_selectedPayout = ["ItemRock", 4];
		// Not Rock
		if (_index >= 0) then {
			_selectedPayout = ["ItemScraps", 2];
			if (_index == 0) then {
				_selectedPayout = ["CinderBlocks", 1];
			};
		} else {
			_lootables = [["PartOre", 2], ["ItemRock", 4]];
			_selectedPayout = selectRandom _lootables;
		};

		_payout = _selectedPayout select 0;
		_payoutQty = _selectedPayout select 1;

		_object setdamage ((damage _object) + (1/_payoutQty)) min 1;

		_nearbyWH = nearestObjects[_posWH, ["groundWeaponHolder"], 2];
		if !(_nearbyWH isEqualTo[]) then {
			_posWH = getPosATL(_nearbyWH select 0);
			(_nearbyWH select 0) addMagazineCargoGlobal[_payout, _payoutQty];
		} else {
			_item = createVehicle["groundWeaponHolder", _posWH, [], 0, "CAN_COLLIDE"];
			_item setPosATL _posWH;
			_item addMagazineCargoGlobal[_payout, _payoutQty];
		};
	};
};
true
