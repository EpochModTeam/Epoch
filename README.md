Epoch Survival Gamemode for Arma 3
=====

http://epochmod.com

This github is for the latest server files, public bug reports, and feedback related to the Epoch Survival gamemode for Arma 3.

Lastest Stable Server Files:
https://github.com/EpochModTeam/Epoch/releases

License:
=====
Arma Public License Share Alike (APL-SA).
http://www.bistudio.com/community/licenses/arma-public-license-share-alike

Credits:
=====
https://github.com/EpochModTeam/Epoch/blob/release/CREDITS.md

Instructions:
=====
- Server Install: https://epochmod.com/forum/topic/44751-dec2017-arma-3-epochmod-server-installation-and-setup/
- If your wanted Map is currently not supported, use the "epoch._ChangeMe.pbo" and rename it to "epoch.MapName.pbo" to use a fallback config

FAQ:
=====
Starting a FAQ here. Can get expanded later
- How to increase / reduce the Loot?
   - There are 3 files, where you can adjust the Loot:
      - @epochhive\epochconfig.hpp
         - lootmultiplier -> (description is in the config)
	  - missionfile\epoch_config\CfgBuildingLootPos.hpp -> (description is in the config)
	     - EpochLootChance
	     - GroundSpawnChance
		 - MinGroundContainers
		 - MaxGroundContainers
      - @epochhove\addons\epoch_server_settings\configs\CfgMainTable.h -> Change the Loot for each Container / Buildingtype
         - lootMin
         - lootMax
- I have added an item to the loot, but it will not spawn (rpt log say "have no price")
   - You also have to add new items to CfgPricing.hpp and CfgItemSort.hpp within your mission file
- I am running a 3rd parties script, but some functions are not working (e.g. Infistar)
   - We have disabled some commands by default for better security. 
   - Check CfgDisabledCommands.hpp within your missionfile, if there are needed functions disabled (if so, remove it)
- Want to add a function to the DynaMenu / E-Pad
   - For the DynaMenu, check missioonfile\epoch_config\Configs\CfgActionMenu\EXAMPLE.hpp
   - For E-Pad, check the "FullExample" in missioonfile\epoch_config\CfgEPad.hpp