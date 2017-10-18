//Author: Raimonds Virtoss / Raymix
class CfgPatches {
	class rmx_sandbox {
		units[] = {};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = {"rmx_init"};
	};
};


class devFunctions {
	debugEnabled = 1; //enables console debug
	class rmx {
		class sandbox {
			file = "x\Addons\rmx_sandbox";
			class variables {recompile = 1; preInit = 1;};
			class sandbox {recompile = 1;};
		};
	};
	
	class A3E {
		tag = "EPOCH";
		file = "x\Addons\rmx_sandbox\epoch";
		class generic {
			file = "x\Addons\rmx_sandbox\epoch";
			//class dragControl {};
			//class dynamicHUD_start {postInit = 1; recompile = 1;};
			//class dynamicHUD_loadSave {recompile = 1;};
			//class dynamicHUD_adjust {recompile = 1;};
			//class getHUDCtrl {};
			class tradeMouseEvents {recompile = 1;};
			class tradeLoad {recompile = 1;};
			class tradeUnLoad {recompile = 1;};
			class tradePopulateLB {recompile = 1;};
			class tradeRefresh {recompile = 1;};
			class tradeMainLoop {recompile = 1;};
		};
	};
	
};

#include "epoch\epoch_configs.hpp"
#include "epoch\Epoch_GUI_rmx.hpp"
#include "epoch\CfgPricing.hpp"