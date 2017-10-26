/*
	Author: Aaron Clark - EpochMod.com

    Contributors:

	Description:
	Returns Real Time in HH:MM string format

    Licence:
    Arma Public License Share Alike (APL-SA) - https://www.bistudio.com/community/licenses/arma-public-license-share-alike

    Github:
    https://github.com/EpochModTeam/Epoch/tree/release/Sources/epoch_server/compile/epoch_server/EPOCH_server_getRealTime.sqf
*/
// make call to get real time
(parseSimpleArray ('epochserver' callExtension '510')) params ["","","",["_hour",0],["_min",0]];
// fix 0 prefix if lower than 10
if (_min < 10) then {_min = '0'+str _min};
if (_hour < 10) then {_hour = '0'+str _hour};
// output HH:MM format
format ['%1:%2',_hour,_min]
