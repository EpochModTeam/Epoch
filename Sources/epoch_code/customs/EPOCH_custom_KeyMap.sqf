/*
	Author: Aaron Clark - EpochMod.com

    Contributors: [Ignatz] He-Man

	Description:
	Custom A3 Epoch KeyMap

    Licence:
    Arma Public License Share Alike (APL-SA) - https://www.bistudio.com/community/licenses/arma-public-license-share-alike

    Github:
    https://github.com/EpochModTeam/Epoch/tree/release/Sources/epoch_code/custom/EPOCH_custom_KeyMap.sqf
	
	Description:
	Add your own customable KeyMaps to the Epoch Configuration Menu (ESC-Menu)
	
	usage:
	["Text in ESC-Menu","VariableNameForKey",keycode] for full keycode list see: https://community.bistudio.com/wiki/DIK_KeyCodes
*/

_keyMap = _keyMap + [
/* Example from eXpoch Vector building:
	["Build: Vector LEFT", "eXpoch_keysVectorTiltL", 0xCB],
	["Build: Vector RIGHT", "eXpoch_keysVectorTiltR", 0xCD],
	["Build: Vector AWAY", "eXpoch_keysVectorTiltAwy", 0xC8],
	["Build: Vector TOWARD", "eXpoch_keysVectorTiltTwd", 0xD0],
	["Build: Object SnapTo", "eXpoch_keysVectorSnapToObject", 0x52],
	["Build: Reset Object", "eXpoch_keysVectorResetObject", 0x4C]
*/
]; 