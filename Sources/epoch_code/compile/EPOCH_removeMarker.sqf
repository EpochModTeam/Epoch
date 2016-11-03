/*
	Author: Andrew Gregory - EpochMod.com

    Contributors:

	Description:
	Create a local marker, with options.

    Licence:
    Arma Public License Share Alike (APL-SA) - https://www.bistudio.com/community/licenses/arma-public-license-share-alike

    Github:
    https://github.com/EpochModTeam/Epoch/tree/release/Sources/epoch_code/compile/EPOCH_removeMarker.sqf

    Example:
    ["markerName"] call EPOCH_removeMarker

    Parameter(s):
		_this select 0: STRING - Marker Name

	Returns:

*/
params [["_mName",""]];
diag_log format["Epoch: ADMIN: Removing marker %1.", _mName];

if(_mName == "")exitWith{};
deleteMarkerLocal _mName;
