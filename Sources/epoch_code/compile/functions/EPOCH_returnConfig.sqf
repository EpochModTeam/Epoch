/*
	Author: Aaron Clark - EpochMod.com

    Contributors:

	Description:
	Returns missionConfigFile if exists otherwise uses configFile

    Licence:
    Arma Public License Share Alike (APL-SA) - https://www.bistudio.com/community/licenses/arma-public-license-share-alike

    Github:
    https://github.com/EpochModTeam/Epoch/tree/master/Sources/epoch_code/compile/functions/EPOCH_returnConfig.sqf

    Example:
    _config = 'CfgCrafting' call EPOCH_returnConfig;

    Parameter(s):
		_this: STRING - Config class name

	Returns:
	CONFIG
*/
private["_return", "_config"];
_return = (configfile >> _this);
_config = (getMissionConfig _this);
if (isClass _config) then{
  _return = _config;
};
_return
