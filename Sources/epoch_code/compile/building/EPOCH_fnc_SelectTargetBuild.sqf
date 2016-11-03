/*
	Author: Aaron Clark - EpochMod.com

    Contributors: Raimonds Virtoss

	Description:
	Epoch build select target

    Licence:
    Arma Public License Share Alike (APL-SA) - https://www.bistudio.com/community/licenses/arma-public-license-share-alike

    Github:
    https://github.com/EpochModTeam/Epoch/tree/release/Sources/epoch_code/compile/building/EPOCH_fnc_SelectTargetBuild.sqf

    Example:
    cursorTarget call EPOCH_fnc_SelectTargetBuild;

    Parameter(s):
		_this select 0: OBJECT - Base building object

	Returns:
	BOOL
*/
//[[[cog import generate_private_arrays ]]]
private ["_stability","_targeter"];
//[[[end]]]

if !(isNil "EPOCH_simulSwap_Lock") exitWith{ false };
if !(isNull EPOCH_Target) exitWith{ false };
if (EPOCH_playerEnergy <= 0) exitWith{ ["Need energy", 5] call Epoch_message; false };

params [["_object",objNull]];

EPOCH_buildOption = 2;

if (isNull _object) exitWith{ false };
if ((player distance _object) > 9) exitWith { false };
if (!(_object isKindOf "ThingX") && !(_object isKindOf "Constructions_static_F") && !(_object isKindOf "Constructions_foundation_F")) exitWith{ false };

// check if another player has target
_targeter = _object getVariable["last_targeter", objNull];

if (!isNull _targeter && _targeter != player && (player distance _object > _targeter distance _object)) exitWith{ EPOCH_stabilityTarget = objNull; false };

_stability = _object getVariable["stability", 100];
if (_stability > 0) exitWith{
	if (isNull EPOCH_stabilityTarget) then {
		_object setVariable["last_targeter", player, true];
		EPOCH_stabilityTarget = _object;
	};
};

/*
if (_object isKindOf "Infostand_base_F") then {
	EPOCH_SURVEY pushBackUnique  _object;
};
*/

[_object] spawn EPOCH_simulSwap;

true
