/*
	Author: Aaron Clark - EpochMod.com

    Contributors: uro1, Robio

	Description:
	Epoch gamemode config for Bornholm

    Licence:
    Arma Public License Share Alike (APL-SA) - https://www.bistudio.com/community/licenses/arma-public-license-share-alike

    Github:
    https://github.com/EpochModTeam/Epoch/tree/release/Sources/epoch_config/Configs/CfgEpochClient/Bornholm.hpp
*/
class Bornholm {
	blockedArea[] = {
			{ { 1433, 8071, 0 }, 250 }, //Roenne NorthEast
			{ { 1939, 7788, 0 }, 250 }, //Roenne East
			{ { 1553, 7103, 0 }, 400 }, //Roenne South
			{ { 3052, 5412, 0 }, 400 }, //Main Airport
			{ { 3676, 5148, 0 }, 300 }, //Airport addons
			{ { 9547, 5541, 0 }, 600 }, //Aakirkeby
			{ { 17433, 5106, 0 }, 600 }, //Nexoe
			{ { 17989, 9844, 0 }, 600 }, //Svaneke
			{ { 11600, 14723, 0 }, 500 }, //Gudhjem
			{ { 5010, 19132, 0 }, 250 }, //Allinge
			{ { 5291, 12450, 0 }, 450 }, //Klemensker
			{ { 3386, 10088, 0 }, 350 }, //Nyker
			{ { 14560, 5130, 0 }, 300 }, //South Airport
			{ { 148786, 5024, 0 }, 300 }, //South Airport Base
			{ { 12993, 10197, 0 }, 250 }, //Oestermarie
			{ { 13867, 10672, 0 }, 300 }, //East Airport
			{ { 8564, 15015, 0 }, 350 }, //Roe
			{ { 6554, 5866, 0 }, 400 }, //Lobbaek
			{ { 5350, 5724, 0 }, 300 }, //Nylars
			{ { 12438, 2980, 0 }, 400 }, //Pedersker
			{ { 14121, 11331, 0 }, 200 }, //Central Spawn
			{ { 1322, 8733, 0 }, 200 }, //West Spawn
			{ { 15639, 191, 0 }, 200 } //East Spawn
	};
	// main config
	TrashClasses[] = {"Trash","TrashSmall","TrashVehicle","PumpkinPatch","TrashFood"};
};
