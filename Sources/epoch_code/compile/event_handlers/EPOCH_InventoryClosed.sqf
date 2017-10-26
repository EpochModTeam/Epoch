/*
	Author: Aaron Clark - EpochMod.com

    Contributors: [Ignatz] He-Man

	Description:
	A3 Epoch InventoryClosed Eventhandler

    Licence:
    Arma Public License Share Alike (APL-SA) - https://www.bistudio.com/community/licenses/arma-public-license-share-alike

    Github:
    https://github.com/EpochModTeam/Epoch/tree/release/Sources/epoch_code/compile/event_handlers/EPOCH_InventoryClosed.sqf
*/
params ["_unit","_container"];
if !(EPOCH_arr_interactedObjs isEqualTo[]) then {
	[EPOCH_arr_interactedObjs] remoteExec['EPOCH_server_save_vehicles', 2];
	EPOCH_arr_interactedObjs = [];
};