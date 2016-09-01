/*
	Author: Aaron Clark - EpochMod.com

    Contributors:

	Description:
	Antagonist spawn chance increase function

    Licence:
    Arma Public License Share Alike (APL-SA) - https://www.bistudio.com/community/licenses/arma-public-license-share-alike

    Github:
    https://github.com/EpochModTeam/Epoch/tree/release/Sources/epoch_code/compile/EPOCH_unitSpawnIncrease.sqf
*/
//[[[cog import generate_private_arrays ]]]
private ["_index"];
//[[[end]]]
params ["_spawnName", ["_increase",1]];
_index = EPOCH_spawnIndex find _spawnName;
if (_index != -1) then{
  EPOCH_playerSpawnArray set[_index, ((EPOCH_playerSpawnArray select _index) + _increase) min (EPOCH_spawnLimits select _index)];
};
