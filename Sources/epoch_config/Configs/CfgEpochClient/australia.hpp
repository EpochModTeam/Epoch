/*
	Author: Aaron Clark - EpochMod.com

    Contributors:

	Description:
	Epoch gamemode config for australia

    Licence:
    Arma Public License Share Alike (APL-SA) - https://www.bistudio.com/community/licenses/arma-public-license-share-alike

    Github:
    https://github.com/EpochModTeam/Epoch/tree/release/Sources/epoch_config/Configs/CfgEpochClient/australia.hpp
*/

class australia {
	blockedArea[] = {
			{ { 16286.1, 33578.6, 0 }, 650 }, //Darwin
			{ { 28467, 35190.1, 0 }, 150 }, //Weipa
			{ { 32103.5, 29816.8, 0 }, 300 }, //Cairns
			{ { 26754.5, 28028.5, 0 }, 120 }, //Mount Isa
			{ { 22069.6, 25578.4, 0 }, 380 }, //Alice Springs
			{ { 19741.6, 24224.8, 0 }, 420 }, //Pine Gap
			{ { 5201.47, 18284, 0 }, 1100 }, //Perth
			{ { 31122.2, 19938.1, 0 }, 280 }, //Toowoomba
			{ { 38111.5, 19942.4, 0 }, 600 }, //North Brisbane
			{ { 38621.4, 19226.6, 0 }, 410 }, //South Brisbane
			{ { 27702.9, 16997.3, 0 }, 170 }, //Broken Hill
			{ { 20723.4, 12752.9, 0 }, 160 }, //Port Lincoln
			{ { 25072.6, 12705.2, 0 }, 350 }, //Adelaide
			{ { 36505.9, 12877.1, 0 }, 540 }, //North Sydney
			{ { 36469.4, 12133.5, 0 }, 420 }, //South Sydney
			{ { 31070, 10856, 0 }, 750 }, //North Melbourne
			{ { 31205.9, 9721.02, 0 }, 510 }, //South Melbourne
			{ { 35364.5, 8453.59, 0 }, 200 } //Eden
	};
	// main config
	TrashClasses[] = { "Trash", "TrashSmall", "TrashVehicle", "PumpkinPatch", "TrashFood", "HempFiber" };
};
