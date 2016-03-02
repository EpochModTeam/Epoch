/*
	Author: Aaron Clark - EpochMod.com

    Contributors:

	Description:
    Change owner of NPC

    Licence:
    Arma Public License Share Alike (APL-SA) - https://www.bistudio.com/community/licenses/arma-public-license-share-alike

    Github:
    https://github.com/EpochModTeam/Epoch/tree/master/Sources/epoch_server/compile/epoch_bases/EPOCH_server_changeOwner.sqf
*/
private ["_result","_newOwner"];
params ["_object","_newOwnerObj"];
_newOwner = owner _newOwnerObj;
_result = false;
if (!isNull _object) then {
	if (local _object) then {
		if ((owner _object) != _newOwner) then {
			_result = _object setOwner _newOwner;
			diag_log format["DEBUG CHANGEOWNER: %1 OWNER: %2 PLAYER: %3 RESULT: %4", _object,owner(_object),_newOwner,_result];
		};
	};
};
_result
