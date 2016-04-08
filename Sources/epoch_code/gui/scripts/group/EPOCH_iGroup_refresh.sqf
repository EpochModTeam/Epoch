/*
	Author: Niklas Wagner - EpochMod.com

    Contributors: Aaron Clark

	Description:
	TODO: DESC-TBA

    Licence:
    Arma Public License Share Alike (APL-SA) - https://www.bistudio.com/community/licenses/arma-public-license-share-alike

    Github:
    https://github.com/EpochModTeam/Epoch/tree/master/Sources/epoch_code/gui/group/EPOCH_iGroup_refresh.sqf
*/
private ["_index"];
if !(Epoch_invited_GroupUIDs isEqualTo Epoch_invited_GroupUIDsPrev) then {
	Epoch_invited_GroupUIDsPrev = Epoch_invited_GroupUIDs;
	lbClear 1500;
	{
		_index = lbAdd[1500, _x select 1];
		lbSetData[1500, _index, _x select 0];
	} forEach Epoch_invited_GroupUIDs;
};
