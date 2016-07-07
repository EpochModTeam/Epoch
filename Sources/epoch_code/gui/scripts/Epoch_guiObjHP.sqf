/*
	Author: Raimonds Virtoss - EpochMod.com

    Contributors: Aaron Clark

	Description:
	TODO: DESC-TBA

    Licence:
    Arma Public License Share Alike (APL-SA) - https://www.bistudio.com/community/licenses/arma-public-license-share-alike

    Github:
    https://github.com/EpochModTeam/Epoch/tree/release/Sources/epoch_code/gui/scripts/Epoch_guiObjHP.sqf
*/
private ["_dmg","_hitPoints"];
params [["_obj",objNull, [objNull]],["_mode",0, [0]]];

if (_obj isEqualTo objNull) exitWith {};

_hitPoints = getAllHitPointsDamage _obj;

{
	_dmg = _hitPoints select 2 select _forEachIndex;
	if ((_mode isEqualTo 1) || ((_mode isEqualTo 0) && !(_dmg isEqualTo 0))) then {
		[
			_obj,
			10,
			format ["x\addons\a3_epoch_code\Data\UI\health_parts\%1.paa", floor (_dmg * 10)],
			format ["%1%2",100 - (round (_dmg * 100)),"%"],
			(_obj selectionPosition _x),
			10
		] call epoch_gui3dModelPos;
	};
} forEach (_hitPoints select 1);

true
