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
{
    [_x, player, true, _this] call EPOCH_unitSpawn;
} forEach (["CfgEpochClient", "uavAlertUnitSpawnTemplate", ["I_Soldier_EPOCH"]] call EPOCH_fnc_returnConfigEntryV2);
