/*
	Author: Aaron Clark - EpochMod.com

    Contributors:

	Description:
	Simple misson config override function

    Licence:
    Arma Public License Share Alike (APL-SA) - https://www.bistudio.com/community/licenses/arma-public-license-share-alike

    Github:
    https://github.com/EpochModTeam/Epoch/tree/master/Sources/epoch_server/compile/epoch_server/EPOCH_returnConfig.sqf
*/
private["_return", "_config"];
_return = (configfile >> _this);
_config = (getMissionConfig _this);
if (isClass _config) then{
    _return = _config;
};
_return
