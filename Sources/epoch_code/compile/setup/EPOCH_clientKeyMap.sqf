/*
	Author: Raimonds Virtoss - EpochMod.com

    Contributors:

	Description:
	Custom Epoch keymap

    Licence:
    Arma Public License Share Alike (APL-SA) - https://www.bistudio.com/community/licenses/arma-public-license-share-alike

    Github:
    https://github.com/EpochModTeam/Epoch/tree/release/Sources/epoch_code/compile/setup/EPOCH_clientKeyMap.sqf

    Example:
    _arr = 2 call EPOCH_clientKeyMap;

    Parameter(s):
		TBA

	Returns:
	Mixed
*/
//[[[cog import generate_private_arrays ]]]
private ["_arr","_keyMap","_return","_s"];
//[[[end]]]
params [["_args",0],["_input",0]];

_keyMap =
[
	//["Name", "Variable name", Default value],
	["Action","EPOCH_keysAction",0x39],
	["Holster Weapon", "EPOCH_keysHolster", 35],
	["Debug Monitor", "EPOCH_keysDebugMon", 41],

	["Volume + (ctrl)","EPOCH_keysVolumeUp",0x0D],
	["Volume - (ctrl)","EPOCH_keysVolumeDown",0x0C],
	["Favorite Bar 1", "EPOCH_keysfav1", 0x02],
	["Favorite Bar 2", "EPOCH_keysfav2", 0x03],
	["Favorite Bar 3", "EPOCH_keysfav3", 0x04],
	["Favorite Bar 4", "EPOCH_keysfav4", 0x05],
	["Favorite Bar 5", "EPOCH_keysfav5", 0x06],
	["Build: Mode 1", "EPOCH_keysBuildMode1", 2],
	// ["Build: Mode 2", "EPOCH_keysBuildMode2", 3],
	// ["Build: Direction", "EPOCH_keysBuildDir", 4],
	// ["Build: Static", "EPOCH_keysBuildStatic", 5],
	["Build: Move UP", "EPOCH_keysBuildMovUp", 0xC9],
	["Build: Move DOWN", "EPOCH_keysBuildMovDn", 0xD1],
	["Build: Move FORWARD", "EPOCH_keysBuildMovFwd", 0xC7],
	["Build: Move BACK", "EPOCH_keysBuildMovBak", 0xCF],
	["Build: Move LEFT", "EPOCH_keysBuildMovL", 0xD2],
	["Build: Move RIGHT", "EPOCH_keysBuildMovR", 0xD3],
	["Build: Rotate LEFT", "EPOCH_keysBuildRotL", 0x12],
	["Build: Rotate RIGHT", "EPOCH_keysBuildRotR", 0x10],
	["Build: Vector LEFT", "eXpoch_keysVectorTiltL", 0xCB],
	["Build: Vector RIGHT", "eXpoch_keysVectorTiltR", 0xCD],
	["Build: Vector AWAY", "eXpoch_keysVectorTiltAwy", 0xC8],
	["Build: Vector TOWARD", "eXpoch_keysVectorTiltTwd", 0xD0],
	["Build: Reset Object", "eXpoch_keysVectorResetObject", 0x4C]
];

_keyMap call EPOCH_custom_KeyMap;

switch (_args) do {
	case 0: //load variables
	{
		{
			call compile format ["%1 = profileNamespace getVariable ['%1', %2]",_x select 1, _x select 2];
		} forEach _keyMap;

		_return = true;
	};

	case 1: //delete all profile namespace variables
	{
		{
			profileNamespace setVariable [_x select 1, nil];
		} forEach _keyMap;

		_return = true;
	};

	case 2: //returns keymap to a caller for processing
	{
		_return = _keyMap;
	};

	case 3: //search by variable name and return element if exists (not tested)
	{
		_return =
		{
			_s = toLower(_x select 1) find toLower _input;
			if (_s > -1) exitWith {_x};
			[]
		} forEach _keyMap;
	};
};

_return
