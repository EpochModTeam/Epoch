/*
	Author: Raimonds Virtoss - EpochMod.com

    Contributors: Aaron Clark

	Description:
	TODO: Make sure to use handle to be able to delete effect later

    Licence:
    Arma Public License Share Alike (APL-SA) - https://www.bistudio.com/community/licenses/arma-public-license-share-alike

    Github:
    https://github.com/EpochModTeam/Epoch/blob/release/Sources/epoch_code/gui/scripts/post_process/EPOCH_postprocessCreate.sqf

	Params:		[Name of PP, Priority]

	Usage:		_handle = ["dynamicBlur",10] call epoch_postProcessCreate;
				_handle = "dynamicBlur" call epoch_postProcessCreate; //not recommended, but ok for tests
*/
private ["_priority","_hndl"];
params [["_effect",""],["_prioIn",0]];

if (_effect isEqualTo "") exitWith {hint "Wrong PPcreate input"; false};
if !(_effect in ["colorCorrections","chromAberration","filmGrain","radialBlur","wetdistortion","dynamicBlur","colorInversion"]) exitWith {hint format ["Wrong effect - %1",_effect]; false};

_priority = switch (_effect) do {
	case "colorCorrections": {1501};
	case "chromAberration": {201};
	case "filmGrain": {2001};
	case "radialBlur": {101};
	case "wetdistortion": {301};
	case "dynamicBlur": {401};
	case "colorInversion": {2501};
};

_hndl = ppEffectCreate [_effect,(_priority + _prioIn)];
_hndl ppEffectEnable false;

_hndl
