/*
	Author: Aaron Clark - EpochMod.com

    Contributors:

	Description:
	Antagonist spawn chance decrease function

    Licence:
    Arma Public License Share Alike (APL-SA) - https://www.bistudio.com/community/licenses/arma-public-license-share-alike

    Github:
    https://github.com/EpochModTeam/Epoch/tree/master/Sources/epoch_code/compile/EPOCH_unitSpawnDecrease.sqf
*/
_index = EPOCH_spawnIndex find _this;
if (_index != -1) then{
  EPOCH_playerSpawnArray set[_index, ((EPOCH_playerSpawnArray select _index) - 1) max 0];
};
