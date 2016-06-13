/*
	Author: Aaron Clark - EpochMod.com

    Contributors:

	Description:
    Vehicle Event Handlers to enable saving to DB

    Licence:
    Arma Public License Share Alike (APL-SA) - https://www.bistudio.com/community/licenses/arma-public-license-share-alike

    Github:
    https://github.com/EpochModTeam/Epoch/tree/release/Sources/epoch_server/compile/epoch_server/EPOCH_server_vehicleInit.sqf
*/
_this addMPEventHandler["MPKilled", { _this call EPOCH_server_save_killedVehicle }];
_this addMPEventHandler["MPHit", { EPOCH_saveVehQueue pushBackUnique (_this select 0) }];
_this addEventHandler["Local", { EPOCH_saveVehQueue pushBackUnique (_this select 0) }];
_this addEventHandler["GetOut", { EPOCH_saveVehQueue pushBackUnique (_this select 0) }];
