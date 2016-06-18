/*
	Author: Aaron Clark - EpochMod.com

    Contributors:

	Description:
	Epoch handle localized message function

    Licence:
    Arma Public License Share Alike (APL-SA) - https://www.bistudio.com/community/licenses/arma-public-license-share-alike

    Github:
    https://github.com/EpochModTeam/Epoch/tree/release/Sources/epoch_code/compile/EPOCH_handleServerMessage.sqf

    Example:
    [_this select 1, _this select 2] remoteExec ['EPOCH_handleServerMessage',_x];

*/
if (isLocalized (_this select 0)) then{
 [format["%1", format[localize (_this select 0), _this select 1]], 5] call Epoch_message;
};
