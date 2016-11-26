/*
	Author: Aaron Clark - EpochMod.com

    Contributors:

	Description:
	Returns missionConfigFile if exists otherwise uses configFile

    Licence:
    Arma Public License Share Alike (APL-SA) - https://www.bistudio.com/community/licenses/arma-public-license-share-alike

    Github:
    https://github.com/EpochModTeam/Epoch/tree/release/Sources/epoch_code/compile/functions/EPOCH_returnConfig.sqf

    Example:
    [['CfgCrafting', 'item1']] call EPOCH_returnConfigV2;

    Parameter(s):
		_this: ARRAY of STRING/s - Config class name Array

	Returns:
	CONFIG
*/
//[[[cog import generate_private_arrays ]]]
private ["_missionconfig","_return"];
//[[[end]]]
_return = configfile;
_missionconfig = missionConfigFile;
{
    _return = (_return >> _x);
    _missionconfig = (_missionconfig >> _x);
} forEach _this;
if (isClass _missionconfig) then{
    _return = _missionconfig;
};
_return
