/*
	Author: Aaron Clark - EpochMod.com

    Contributors:

	Description:
	Epoch gamemode config for Chernarus_Summer

    Licence:
    Arma Public License Share Alike (APL-SA) - https://www.bistudio.com/community/licenses/arma-public-license-share-alike

    Github:
    https://github.com/EpochModTeam/Epoch/tree/release/Sources/epoch_config/Configs/CfgEpochClient/Chernarus_Summer.hpp
*/
class Chernarus_Summer {
	blockedArea[] = {
			{ { 10203, 1886, 0 }, 430 }, //South Electro
			{ { 6822, 2498, 0 }, 600 }, //Cherno
			{ { 4612, 9670, 0 }, 140 }, //NWAF south barack
			{ { 4907, 10117, 0 }, 250 }, //NWAF NE hangas
			{ { 4707, 10384, 0 }, 200 }, //NWAF north barack
			{ { 4069, 10778, 0 }, 75 }, //NWAF west hangas
			{ { 4553, 10722, 0 }, 150 }, //NWAF NW hangas
			{ { 12279, 9505, 0 }, 350 }, //Berenzino Mid
			{ { 12816, 9816, 0 }, 400 }, //Berenzino SE
			{ { 12991, 10147, 0 }, 375 }, //Berenzino Docs
			{ { 2693, 5138, 0 }, 200 }, //Zeleno
			{ { 11467, 7508, 0 }, 150 }, //Polana Factory
			{ { 13092, 7096, 0 }, 140 } //Solnichniy Factory
	};
	// main config
	TrashClasses[] = { "Trash", "TrashSmall", "TrashVehicle", "PumpkinPatch", "TrashFood", "HempFiber" };
};
