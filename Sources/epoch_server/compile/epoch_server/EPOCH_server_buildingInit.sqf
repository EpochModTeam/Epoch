/*
	Author: Aaron Clark - EpochMod.com

    Contributors:

	Description:
	Adds killed handler to base building.

    Licence:
    Arma Public License Share Alike (APL-SA) - https://www.bistudio.com/community/licenses/arma-public-license-share-alike

    Github:
    https://github.com/EpochModTeam/Epoch/tree/release/Sources/epoch_server/compile/epoch_server/EPOCH_server_buildingInit.sqf
*/
_this addMPEventHandler["MPKilled", { _this call EPOCH_server_save_killedBuilding; }];
