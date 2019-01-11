/*
	Author: Aaron Clark - EpochMod.com

    Contributors:

	Description:
	Returns the DisplayName of a Vehicle, Weapon, or Magazine.

    Licence:
    Arma Public License Share Alike (APL-SA) - https://www.bistudio.com/community/licenses/arma-public-license-share-alike

    Github:
    https://github.com/EpochModTeam/Epoch/tree/release/Sources/epoch_code/compile/functions/EPOCH_itemDisplayName.sqf

    Example:
    _displayName =  _part call EPOCH_itemDisplayName;

    Parameter(s):
		_this: STRING - Vehicle, Weapon, or Magazine config class name

	Returns:
	STRING
*/
// Changed function name for usage Server and Client side

_this call EPOCH_fnc_itemDisplayName;
