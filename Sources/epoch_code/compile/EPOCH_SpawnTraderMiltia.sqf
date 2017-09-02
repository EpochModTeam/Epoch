/*
	Author: Andrew Gregory - EpochMod.com

    Contributors:

	Description:
	test code to spawn trader milita (unused)

    Licence:
    Arma Public License Share Alike (APL-SA) - https://www.bistudio.com/community/licenses/arma-public-license-share-alike

    Github:
    https://github.com/EpochModTeam/Epoch/tree/release/Sources/epoch_code/compile/EPOCH_SpawnTraderMiltia.sqf
*/
//[[[cog import generate_private_arrays ]]]
private ["_allpositions","_grp","_nrBuilds","_rndHouse","_startPos","_unit"];
//[[[end]]]

_nrBuilds = nearestObjects [player,["house"],50];

_grp = createGroup [RESISTANCE, true];
for "_i" from 1 to 3 step 1 do
{
	_startPos = [];
    while {count _startPos < 1} do {
    	_rndHouse = selectRandom _nrBuilds;
		_allpositions = _rndHouse buildingPos -1;
        if !(_allpositions isEqualTo []) then {
            _startPos = selectRandom  _allpositions;
        };
    };

	_unit = _grp createUnit["B_G_Soldier_F", _startPos, [], 0, "CAN_COLLIDE"];
	_unit addEventHandler ["FiredNear", "group (_this select 0) setVariable[""shotsFired"",[(_this select 1),(_this select 2)]]"];
	_unit addEventHandler ["Killed", "group (_this select 0) setVariable[""killer"",_this select 1]"];
	[_unit] execFSM "\x\addons\a3_epoch_code\System\Trader_Militia.fsm";
};
