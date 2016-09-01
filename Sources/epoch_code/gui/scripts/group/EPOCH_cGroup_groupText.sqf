/*
	Author: Niklas Wagner - EpochMod.com

    Contributors: Aaron Clark

	Description:
	TODO: DESC-TBA

    Licence:
    Arma Public License Share Alike (APL-SA) - https://www.bistudio.com/community/licenses/arma-public-license-share-alike

    Github:
    https://github.com/EpochModTeam/Epoch/tree/release/Sources/epoch_code/gui/group/EPOCH_cGroup_groupText.sqf
*/
disableSerialization;
//[[[cog import generate_private_arrays ]]]
private ["_array","_ctrl"];
//[[[end]]]
_ctrl = (findDisplay -1200) displayCtrl 21;
_array = toArray(ctrlText _ctrl);

if (count _array > 24) then {
	_array resize 24;
};

// remove any disallowed chars in group name "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890 -_"
{
	if !(_x in [97,98,99,100,101,102,103,104,105,106,107,108,109,110,111,112,113,114,115,116,117,118,119,120,121,122,65,66,67,68,69,70,71,72,73,74,75,76,77,78,79,80,81,82,83,84,85,86,87,88,89,90,49,50,51,52,53,54,55,56,57,48,32,45,95]) then {
		_array = _array - [_x];
	};
} forEach _array;

_ctrl ctrlSetText (toString _array);
false
