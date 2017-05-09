/*
	Author: Andrew Gregory - EpochMod.com

    Contributors: Aaron Clark

	Description:
	Spawn drone function

    Licence:
    Arma Public License Share Alike (APL-SA) - https://www.bistudio.com/community/licenses/arma-public-license-share-alike

    Github:
    https://github.com/EpochModTeam/Epoch/tree/release/Sources/epoch_code/compile/EPOCH_supportCopter.sqf
*/
//[[[cog import generate_private_arrays ]]]
private ["_SpawnTypes","_Spawncounts","_UnitType","_arrUnits","_idx","_maxunitCount","_minunitCount","_unitCount"];
//[[[end]]]
params ["_pos","_copter"];

_arrUnits = getArray (getMissionConfig "CfgEpochUAVSupport" >> "unitTypes");
_minunitCount = getNumber (getMissionConfig "CfgEpochUAVSupport" >> "minUnitNum");
_maxunitCount = getNumber (getMissionConfig "CfgEpochUAVSupport" >> "maxUnitNum");
_unitCount = _minunitCount + round (random (_maxunitCount - _minunitCount));

_SpawnTypes = [];
_Spawncounts = [];
for "_i" from 1 to _unitCount do {
	_UnitType = selectRandom _arrUnits;
	_idx = _SpawnTypes find _UnitType;
	if (_idx == -1) then {
		_SpawnTypes pushback _UnitType;
		_Spawncounts pushback 1;
	}
	else {
		_Spawncounts set [_idx,(_Spawncounts select _idx)+ 1];
	};
};

{
    [_SpawnTypes select _foreachindex, player, true, _x, _this] call EPOCH_unitSpawn;
} forEach _Spawncounts;
