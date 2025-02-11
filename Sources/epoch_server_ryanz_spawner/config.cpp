class CfgPatches
{
	class Epoch_RyanZ_Spawner
	{
		requiredVersion = 0.1;
		requiredAddons[] = {};
		units[] = {};
		weapons[] = {};
		magazines[] = {};
		ammo[] = {};
		author[]= {"He-Man"};
	};
};

class CfgFunctions
{
	class Epoch_RyanZ_Spawner
	{
		class main {
			file = "Epoch_RyanZ_Spawner";
			class init {
				preInit = 1;
			};
		};
	};
};

#include "ZedSpawner\Epoch_ZombieSpawnConfig.hpp"
