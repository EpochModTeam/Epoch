class cfgFunctions
{
	class A3
	{
		tag = "BIS";
		class Respawn
		{
			file = "A3\functions_f\Respawn";
			class selectRespawnTemplate
			{
				file = "epoch_code\compile\bis_functions\Respawn\fn_selectRespawnTemplate.sqf";
			};
		};
		class functions {
			// BIS_fnc_returnVector
			class returnVector {
				file = "epoch_code\compile\bis_functions\returnVector.sqf";
			};
		};
	};
	class EPOCH
	{
		tag = "EPOCH";
		class functions {
			class returnConfigEntryV2 {
				file = "epoch_code\compile\functions\EPOCH_fn_returnConfigEntryV2.sqf";
			};
			class isAny {
				file = "epoch_code\compile\both\EPOCH_isAny.sqf"
			};
		};
		class Client
		{
			class init
			{
				file = "epoch_code\init\fn_init.sqf";
				preInit = 1;
			};
			class postinit
			{
				file = "epoch_code\init\fn_postinit.sqf";
				postInit = 1;
			};
		};
	};
};
