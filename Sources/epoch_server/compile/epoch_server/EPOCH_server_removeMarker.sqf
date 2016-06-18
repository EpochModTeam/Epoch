/*
	Author: Andrew Gregory - EpochMod.com

    Contributors:

	Description:
	Delete map marker.

	Parameter(s):
	_this select 0: OBJECT (Player) / ARRAY - Players.
	_this select 1: INTEGER - 0 - Player Only, 1 - Player Group, 2 - Everyone, 3 - Custom Array of players.
	_this select 2: STRING - Marker Name

    Licence:
    Arma Public License Share Alike (APL-SA) - https://www.bistudio.com/community/licenses/arma-public-license-share-alike

    Github:
    https://github.com/EpochModTeam/Epoch/tree/master/Sources/epoch_server/compile/epoch_server/EPOCH_server_deleteMarker.sqf
*/
params [["_trgtObj",[]],["_trgtType",0],["_mrkrName",""]];
diag_log format["Epoch: ADMIN: Deleting marker %1 | %2.", _mrkrName, _trgtObj];


switch _trgtType do {

	case 0: {
		if(isPlayer _trgtObj)then{
			[_mrkrName] remoteExec ['EPOCH_fnc_deleteMarker',_trgtObj];
		};
	};

	case 1: {
		if!(isNull _trgtObj)then{
			{
			[_mrkrName] remoteExec ['EPOCH_fnc_deleteMarker',_x];
			}foreach (units group _trgtObj);
		};
	};
	
	case 2: {
			deleteMarker _mrkrName;
	};
	
	case 3: {
		if(isArray _trgtObj && count _trgtObj > 0)then{
			{
			[_mrkrName] remoteExec ['EPOCH_fnc_deleteMarker',_x];
			}foreach _trgtObj;
		};
	};

	
	default {diag_log format["Epoch: ADMIN: Marker delete failed at %1 called by %2.", _mPos, _trgt];};
};
