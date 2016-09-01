/*
	Author: Raimonds Virtoss - EpochMod.com

    Contributors: Aaron Clark

	Description:
	TODO: DESC-TBA

    Licence:
    Arma Public License Share Alike (APL-SA) - https://www.bistudio.com/community/licenses/arma-public-license-share-alike

    Github:
    https://github.com/EpochModTeam/Epoch/tree/release/Sources/epoch_code/gui/scripts/Epoch_secureStorageHandler.sqf
*/
//[[[cog import generate_private_arrays ]]]
private ["_out"];
//[[[end]]]
params [["_in",false]];
_out = switch (typeName _in) do {
	case "STRING":
	{
		if !(isNull dyna_cursorTarget) then {
			dyna_cursorTarget getVariable ["EPOCH_Locked",false]
		};
	};
	case "OBJECT":
	{
		[_in,(_in getVariable ["EPOCH_Locked",false]),player,Epoch_personalToken] remoteExec ["EPOCH_server_lockStorage",2];
		true
	};
	default {false};
};
_out
