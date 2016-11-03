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
params [["_str",""],["_input",""]];
if (isLocalized _str) then{
    [format["%1", format[localize _str, _input]], 5] call Epoch_message;
};
