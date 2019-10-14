/*

	Author: He-Man - EpochMod.com

    Contributors:

	Description:
	Workaround for delayed positioning for Server side placed items

    Licence:
    Arma Public License Share Alike (APL-SA) - https://www.bistudio.com/community/licenses/arma-public-license-share-alike

	Github:
    https://github.com/EpochModTeam/Epoch/tree/release/Sources/epoch_code/compile/functions/EPOCH_fnc_SetFinalDir.sqf
	
	usage: 
		_array = [];
		{
			_array pushback [_x,[vectordir _x, VectorUp _x]];
		} foreach _objs;
		_array remoteExec ["EPOCH_fnc_SetFinalDir",_player];
*/

uisleep 1;		// Give some time for init Server Side
{
	_x params ["_obj","_dir"];
	if (_dir isEqualType []) then {
		_obj setVectorDirAndUp _dir;
	}
	else {
		_obj setdir _dir;
	};
} foreach _this;
