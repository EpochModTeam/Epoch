/*
	Author: Aaron Clark - EpochMod.com

    Contributors:

	Description:
	Initalize Player

    Licence:
    Arma Public License Share Alike (APL-SA) - https://www.bistudio.com/community/licenses/arma-public-license-share-alike

    Github:
    https://github.com/EpochModTeam/Epoch/tree/release/Sources/epoch_code/init/fn_postinit.sqf
*/
if (isDedicated) then {
	// dedicated server
	call compile preprocessFileLineNumbers "\epoch_server\init\server_init.sqf";
} else {
	if (hasInterface) then {

		if (isMultiplayer) then {
			// start multiplayer game
			call compile preprocessFileLineNumbers "epoch_code\init\client_init.sqf";
		};

		if (isServer) then {
			// listen server host

		} else {
			// all players


		};
	} else {
		// Headless Clients

	};
};
true
