/*
	Author: Aaron Clark - EpochMod.com

    Contributors:

	Description:
	Epoch gamemode config for Altis

    Licence:
    Arma Public License Share Alike (APL-SA) - https://www.bistudio.com/community/licenses/arma-public-license-share-alike

    Github:
    https://github.com/EpochModTeam/Epoch/tree/release/Sources/epoch_config/Configs/CfgEpochClient/Altis.hpp
*/

class Altis {
	blockedArea[] = { //[POS],radius
			{ { 16085, 16997, 0 }, 250 }, //South Telos
			{ { 12844, 16714, 0 }, 120 }, //Soldner Base
			{ { 3085, 13184, 0 }, 300 }, //Kavalar Carstel
			{ { 13493, 12013, 0 }, 450 }, //Makrynisi (Island)
			{ { 17439, 13165, 0 }, 165 }, //Pyrgorsk Military
			{ { 20084, 6728, 0 }, 55 }, //West of Selakano
			{ { 25303, 21807, 0 }, 100 } //Sofia
	};
	// Trash config
	TrashClasses[] = { "Trash", "TrashSmall", "TrashVehicle", "PumpkinPatch", "TrashFood", "HempFiber" };
};
