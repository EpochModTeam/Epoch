# Change Log
All changes for [Arma 3](https://arma3.com/) [Epoch Mod](https://epochmod.com) are listed in this changelog.

## [1.3.0.0] - 2019-xx-xx
### Added
- Several A2 Vehicles ported into Epoch
   - === LandVehicles ===
      - A2_Golf_EPOCH
      - A2_HMMWV_EPOCH
      - A2_HMMWV_load_EPOCH
      - A2_Lada_EPOCH
      - A2_SUV_EPOCH
      - A2_SUV_load_EPOCH
      - A2_SUV_armed_EPOCH (not finished)
      - A2_UAZ_EPOCH
      - A2_UAZ_Open_EPOCH
      - A2_Ural_EPOCH
      - A2_Vodnik_EPOCH
      - A2_Volha_EPOCH
   - === AirVehicles ===
      - a2_mi8_EPOCH
      - a2_ch47f_armed_EPOCH
      - a2_ch47f_armed_plus_EPOCH
      - uh1h_armed_EPOCH
      - uh1h_armed_plus_EPOCH
- A lower Pawnee variant
      - C_Heli_Light_01_armed_EPOCH
      - C_Heli_Light_01_armed_plus_EPOCH
- Several A2 Weapons ported into Epoch
   - a2_ak47s_gold_EPOCH 		Mass: 150
   - a2_AK107_EPOCH				Mass: 200
   - a2_bizon_epoch				Mass: 100
   - a2_dmr_epoch				Mass: 250
   - a2_dmr_epoch_scoped		Mass: 250
   - a2_fnfal_epoch				Mass: 200
   - a2_G36_C_epoch				Mass: 150
   - a2_Mg36_epoch				Mass: 150
   - a2_leeenfield_epoch		Mass: 150
   - a2_m110_epoch				Mass: 150
   - a2_mk16_epoch				Mass: 150
   - a2_mk17_epoch				Mass: 180
   - a2_svd_epoch				Mass: 200
   - a2_VSS_vintorez_epoch 		Mass: 150
   - a2_aks74un_EPOCH			Mass: 150
- Several A2 Backpacks ported into Epoch
   - Assault_Pack_Epoch (CIV Assault Pack): 		Load: 300
   - Patrol_Pack_Epoch (Patrol Pack): 				Load: 300
   - TK_RPG_Backpack_Epoch (RPG Pack): 				Load: 300
   - CZ_VestPouch_Epoch (Vest Pouch): 				Load: 340
   - civil_assault_pack_Epoch (CIV Assault Pack): 	Load: 400
   - S_Gunbag_Epoch (Gunbag): 						Load: 420
   - ALICE_Pack_Epoch (Alice Pack): 				Load: 480
   - US_Backpack_Epoch (Coyote BackPack) : 			Load: 500
   - CZ_Backpack_Epoch (Camo CZ BackPack): 			Load: 520
   - L_Gunbag_Epoch (Large Gunbag): 				Load: 580
- Tablet (E-Pad) - Can be found in Space Menu (DynaMenu)
   - You can simply add "Apps" by a config - https://github.com/EpochModTeam/Epoch/blob/experimental/Sources/epoch_config/Configs/CfgEPad.hpp
   - Default Apps:
      - Enable E-Pad in DynaMenu
      - Show Playermarker on Map (GPS is needed)
      - Show dead Playermarker on Map (GPS on death was needed)
      - Enable / Disable Auto-Earplugs on Vehicle enter
      - Server Infos / Rules / Settings (load predefined html-sites)
      - Switch on / off debug monitor
      - Check, if you are reviveable or not
      - Read some news (random messages)
      - Check for nearby Vehicles (cost 250 Krypto)
      - Check for nearby Players (cost 250 Krypto)
      - Kill yourself (suicide)
- JailWall and JailDoor to Basebuilding items
- Sounds to Door animations for building parts
- Rusty textures for some Vehicles
- Button to search in all configs to spawn items in AdminMenu
- Fix to prevent rope-break while lifting Vehicles
- Removed buildings are no longer logged as "killed", but as removed, if the owner has removed it
- All Plotpoles are now stored in the Variable "EPOCH_Plotpoles" (for Clients and Server)
- Earplugs (Default F4 - Auto-Earplugs on Vehicle enter can be toggled in E-Pad)
- UAV's are now usable by Space-Menu (DynaMenu)
- Configs to disable Door interactions for enhanced movement and ACE Mod
- You can now defuse bombs via Space-Menu (DynaMenu)
- Config to change the max vehicle trade distance to cfgEpochclient.hpp
### Fixed
- Model for SolarCharger was the same as SolarGenerator in Crafting Menu
- If already in a group, you can not join another group
- Position for Traders above water were bugged
- Mosquito behavior was a bit too heavy
### Changed
- Metal Garage model is now better to identify (looked nearly the same as walls)
- Teleporters are now Booths and no interaction is needed to teleport
- SIM / Ghost storages have now own baseClasses - "Buildable_Storage_SIM" / "Buildable_Storage_Ghost"
- RadSuit now also protect against Toxic
- Simplified Weather script Event
- Config for seasonal Trader Clothings

## [1.2.0.0] - 2018-05-24
### Added
- Config in cfgepochclient.hpp to disable needed items for FireOn / BurnBarrelOff / Hook @He-Man
- Missing Config entry "immuneIfStartInBase" in epochconfig.hpp @G-Dog
- Radiation Suits to Loot, Pricing and Itemsort @He-Man
- Config to restrict tilting angle for Vectorbuilding to cfgEpochClient.hpp @He-Man
- Config to disable Fuelsources in PlotPole Range to epochconfig.hpp @He-Man
- Reworked Trader Menu @He-Man
   - Secondary Weapon can now be sold directly from hand
   - Attachments from sold weapons from hand will be put back into your Inventory
   - Weapons in hand are now marked in menu as "in Hand"
- Solar Charger for EnergyPacks - Put an EnergyPack into the Charger and wait... @Helion4, @He-Man
- 4 Hoverboard Vehicles: @Helion4
   - "hoverboard_epoch_1"
   - "hoverboard_epoch_bttf"
   - "hoverboard_epoch_a3"
   - "hoverboard_epoch_cargo"
- Mountainbike "MBK_01_EPOCH" @Helion4
- Helicopter UH1H "uh1h_Epoch" @Helion4
- BaseCam + BaseCam Terminal @Helion4, @He-Man
   - Build Cams at your Base and watch them through the Terminal
- Wooden Stairs with lockable Bars on the top (upgradeable from Wooden Stairs) @Helion4
- Wood and Metal Garage Doors as upgradeable Baseparts @Helion4, @He-Man
- 1/3 Plywood wall directly craftable @Helion4, @He-Man
- You can now wash yourself with a soap in your inventory at water sources (reduce Soiled) @Helion4, @He-Man
- 2 new masks (Thor Helmet "thor_mask_epoch" and Iron Man Mask "iron_mask_epoch") @Helion4
- Search field in Admin spawn window (Admintool) @He-Man
### Fixed
- Mine Rocks / Chop Wood was only possible with Swords after 1.1.0 update. @He-Man
- Alive Toxic Sapper was not toxic @He-Man
- Binocular with "B" was not working, if you are using R3F or AdvSlingLoad @He-Man
- Models for Radiation Suits @Helion4
- Traps were Indestructible by using indestructible "Constructions_static_F" @He-Man
- Hopefully less login issues on BaseSpawn @He-Man
- Kick by using Jet ejector seats @He-Man
- Wrong calculated Bullets in Traders @He-Man
- Locked Vehicles were unlocked after upgrade @He-Man
- Everybody was able to open Hatch on Windows / Doors on foreign Bases @He-Man
- Ban for "RscMenuTeam" commandmenu @He-Man
- Adjusted some SnapPoints for Basebuilding to be more accurate @He-Man
- Advanced Vehicle Repair was broken after last Arma Update (Tank DLC) @He-Man
- Added missing ItemWaterPurificationTablets to pricing @G-Dog
- MultiGun was not working on very large Vehicles (VTOL) @He-Man
- GoldenSeal will no longer disappear when fully grown in a Garden @He-Man
- Items in Subcontainers (Items in BackPacks in Containers) were not saved @He-Man
- Drunk effects were not working correctly @He-Man
- Model / Graphics fix for Cinder Floors @Helion4
- Snapped Walls on Stairs sometimes were not fixed correctly @Helion4
- Quadbike handling was a bit too slippery @Helion4
### Changed
- Reworked Vehicle Load / Save commands for more precise Vehicle Spawn @He-Man
- Made Temp-Vehicles tradable (will not be stored in Trader after selling them) @He-Man
- Wood / Cinder Walls can now snap to each other @He-Man
- Energy from windsources / solarsources is now calculated by wind / overcast @He-Man
- Ammo of crafted Mags are calculated by the left ammo of used Mags (example: EnergyPacks) @He-Man
- Consumed EnergyPacks give only energy calculated by left ammo in the Pack @He-Man
- Moved server "EpochEvents" folder from epoch_server_settings.pbo to epoch_server_events.pbo @DirtySanchez, @vbawol
- Some script optimizations @vbawol
- Vehicle pricing adjustments "import tariffs" @vbawol
- Some now Icons for Dynamenu @Forelle Vierkant

## [1.1.0.0] - 2018-03-15
### Added
- Plant Spawner: vehicle object for sunflower. @Helion4
- MoneyDrop Event: Random Money lump with Mapmarker (like Plants) @He-Man
- Examples for Vehicle upgrades for Server Admins into CfgVehicleUpgrades.hpp @He-Man
- Make Lighter refillable at Fuel-Sources (Gasstations / Vehicles) @He-Man
- Make Trader more configurable in epochconfig.hpp @He-Man
- Added Examples for Batchfiles to control Server Restarts @DirtySanchez
- default pops for "center" marker @vbawol
- More map supports @vbawol
- Lighter is needed to inflame fires @DirtySanchez
- FireExtinguisher is needed to "put our fire" on Burn Barrel @DirtySanchez
- Rope is needed for SlingLoad (get back on release) @DirtySanchez
- R3F compatibility for SlingLoad @DirtySanchez
- Hints while using Vehicle Repair (MultiGun) @He-Man
- Config to completely disable Simulation for BaseParts (if not needed) @He-Man
- Made Radiation configurable by cfgepochclient.hpp @Raymix
- Hints for lock / unlock Vehicles / Storages @He-Man
- Nuisance multiplicator in cfgepochclient.hpp @He-Man
- Reduce rads over time at cost of immunity @Raymix
- Wearable Male & Female wearable full radiation suit @Helion4
- December seasonal items (Santa hat / Snowman) @Helion4
- Autorun function (suggested by Ghostrider) @He-Man
   - Default Key is "W"
   - You can change the key in EPOCH ESC Menu
   - If choosen key is same as "moveforward" (default), you have to 2x tap it, else you only have to 1x tap it
   - If your legs are broken, you get a hint "can not autorun - legs are broken"
   - If the terrain is too steep, you only walk in AutoRun
   - Inside Water, you can not Autorun
- Helper 3D-Icon + Line on the part, where element is snapped on (while Base-Building) @He-Man
- Config in cfgepochclient.hpp to block ATM's in Plotpole range @He-Man
- Power Sword @Helion
### Fixed
- False BE kicks since Arma 3 1.80 update.
- Nightlight now also follow players inside Vehicles @He-Man
- Fixed fault disabled DynamicDebris @morgoth0
- SERVER_VARS (BaseSpawn) was not saved on revive @morgoth0
- Without Advanced Vehicle Repair, Vehicle upgrade was not available @He-Man
- Base Storages could be deleted if near Loot containers were auto-deleted @He-Man
- Some Tarp Loot was spawned under the Floor @He-Man
- Reworked wall check by getting out of Vehicles @He-Man
- Garden Plot had no physical ground @Helion4
- Some Vehicles were missing in EPOCH Admin Spawn Menu @He-Man
### Changed
- RCon Port is now set to 2307 by default since changes in A3 1.78 prevent use of 2306. @vbawol
- SnapPoints for Building objects (especially full / half / quarter Floors) @He-Man
- Some performance tweaks
- Inventory will be opened automatically, if "you found something" @vbawol
- EPOCH Events reworked (Markers will change if players near / event looted) @DirtySanchez
- Traders will no longer refill sold magazines @He-Man
   - Magazines will automatic be repacked in Trader
   - First the trader offers full magazines
   - If no full magazine is available, the Trader offer the last not full magazine
   - Not full magazines are colored: Yellow (nearly full) -> Red (nearly empty)
   - You also get a Tooltip, how much bullets left in magazine
   - The prices are calculated by the left bullets in the magazine
- Increased snap-distance for Foundations (much easier to find snap positions) @He-Man
- Reworked and added EPOCH Vehicle Classes @He-Man
   - Each upgrade increase Speed, Torque, Fuel, Terrainbehaviour, Load and Armor
   - Hatchback >= lvl2 will no longer stuck in forests
   - Added M900 forced without Backseats -> "C_Heli_Light_01_civil_2seat_EPOCH"
   - Added M900 forced with Backseats -> "C_Heli_Light_01_civil_4seat_EPOCH"
   - The Random M900 will also stay available -> "C_Heli_Light_01_civil_EPOCH"
   - Added very low EPOCH variants of VTOL and Xi'an (eventually we have to change them with the next update a bit)
   - Added Door-Animations to some Vehicles by GetIn / GetOut

## [1.0.0.1077] - 2017-11-05
### Added
- Make temp Vehicles Lockable + Lock hints.
- FuelTank to Loot / Crafting / Pricing.
- Missing itemPipe to loot tables.
### Fixed
- Rpt error for community stats.
- CameraView Check moved to master loop.
### Changed
- Make use of traderUniforms config for AI trader classes.
- Adjust the order of marker sets.

## [1.0.0.1074] - 2017-10-30
### Added
- Missing Prices / Itemsorts + Objectinteracts configs.
- Note about a possible crash point on server startup if Redis is not running.
- Hint for Building to move / remove / upgrade.
- Config variable radiationEffectsThreshold to control what level PP effects are seen, (default 10%).
### Fixed
- Fix for radiation post process effects when under 10% irradiated.
- Fix inherits for metal and cinder floor.
- Forced restart is now working properly again.
- Fav Bar now returns "Not enough Space" message if there isn't enough space to store current accessory.
- Fix for Horizontal Barrel Bomb BE kick.
### Changed
- Random attributes now use 2 decimal places instead of rounding.
- Shipwrecks now use safe pos for shipwreck loot containers positions.

## [1.0.0.0] - 2017-10-26
### Added
- Favorites bar. Users can pin (almost) any item to the bar by dragging items from inventory to equip/un-equip (Weapons, attachments, head gear, etc.) or consume (eat, drink, build, etc.) using keyboard mapping without having gear open. Use ESC menu to change the mappings. Server admins, see client_init.sqf for config. @raymix
- Advanced Vehicle Repair System - Repairing your vehicle just got more realistic. Patch a leaky fuel tank with Duct Tape. If you blow a tire you now need to find a Spare. Engine too damaged? grab an engine block to repair it. @Ignatz-Heman
- Repair Items: (ItemDuctTape, SpareTire, EngineParts, EngineBlock, ItemGlass, FuelTank, ItemRotor). @Helion4
- Vehicle Upgrade System - Upgrade your ride by using one of the new vehicle upgrade documents found in the world. @DirtySanchez
- Vector Base Building (uses Arrow keys by default and with SHIFT / ALT you can control the steps). @DirtySanchez & @Ignatz-Heman
- New Base Building Objects: Quarter and Half wood floors @DirtySanchez, Cinder block floor, Cinder wall with a window. Metal and Cinder Towers @Helion4.
- Added the following new buildables (bringing most buildables from A2/Epoch to A3 using standard ARMA models): Burn Barrel, Light Pole, Small (forest and desert) Camo Nets, Large (forest and desert) Camo Nets, Camp Fire, Field Toilet, Scaffolding, Sink (water source), Single and Double Portable Lights, Lifeguard Tower, Sun Shade, Fuel Pump, Small Sandbag Bunker, Short Sandbag Wall, Long Sandbag Wall, Bar Gate and Water Pump, @morgoth0 (Grahame) and @DirtySanchez
- A-frame and Dome tents as insecure storage objects. @morgoth0, @DirtySanchez, @Helion4
- Farming system - craft-able garden plot allows you to grow seeds into mature plants. Models by @Helion4, configs by @DirtySanchez
- Medical items: Adrenaline Shot (adrenaline_epoch), Caffeine Pills (caffeinepills_epoch). Orlistat Pills (orlistat_epoch) by @Helion4 and configs by @DirtySanchez
- Food items: ItemCereals, ItemPowderMilk_F, ItemRiceBox, ItemVitamins. @DirtySanchez
- 84 new Female outfits based on 20 top designs and 4 new pairs of jeans(Blue Patched, Arid Brown, Black/Brown, Black). @DirtySanchez, @ComatoseBadger
- Pricing and loot table additions for 65 additional male uniforms.
- Vehicle Ammo Reloading from Inventory and Vehicle Ammo. @DirtySanchez
- Radiation System with radioactive out of bounds, locations, and random crashed satellites. Model @Helion4
- Digital Geiger Counter - used to detect Radiation levels by pointing at radioactive objects. (Sounds @vbawol, Model @Helion4, and UI + digital font @raymix)
- Radiation meds - pills, creme and injector to reduce radiation effects @Helion4
- Barrel Bomb - large craft-able explosive that can be placed and detonated. @DirtySanchez
- Brown Briefcase that contains 100oz Silver. @DirtySanchez
- Old "Zombie Parts" Bag (ItemBioHazardBag).
- 5 new Halloween masks for October. @Helion4, @DirtySanchez
- Option to drink directly from water sources. @Ignatz-HeMan
- Karma changes for deaths, suicides, PvP(including hero* and bandit* levels), trader kills, revives, trading sales and purchases.
- Custom map markers and icons by @xDrokZ, @DirtySanchez
- Epoch Events 3.0: External pbo based events. see epoch_server_vip_event or epoch_server_debris_event for examples.
- VIP Event - Reveals the map location of a random player that possesses a specific item (default: ItemBriefcaseGold100oz) every X (default: 15) minutes.
- Dynamic Debris: Dynamically spawns vehicle and other debris on the roadways. Scans the roads on startup and uses a random seed generator to determine the locations of debris. Debris is spawned using createSimpleObject for best performance and is made to conform with the uppermost roadway surface.
- Epoch Dev Libs, See https://github.com/EpochModTeam/Epoch/tree/experimental/Tools/DevFrameWork for more info. @raymix
- Md5 hash function and Unit test to the hive. See usage example with EPOCH_fnc_server_hiveMD5 SQF function.
- Dynamic Simulation is now fully enabled. See "CfgDynamicSimulation" for configs. @DirtySanchez
- Conditional loot table options to allow omitting items from loot tables via custom logic.
- Map support for Malden 2035. @morgoth0
- Map support for Chernarus Redux. @xDrokZ and @morgoth0
- Burgers! @Helion4
- New masks - Hockey, Plague, ghostface, skull, witch @Helion4

### Changed
- Mineral nodes can now only be harvested using the sledge hammer.
- Crafting recipes can now have item requirements and Crafting metal bars now require Smelting Tools.
- Player save and login optimized to use get|setUnitLoadout.
- Karma now persists death and moved to community stats.
- CBA extended event handler and zeus curator support for Epoch Vehicles. @DirtySanchez
- Base PlotPole ESP added to Epoch Admin Panel. @SMVampire
- Helper arrow to indicate the door-opening direction for Base Building. @Ignatz-Heman
- Base Building elements can be detached to walk around the Element before saving. @Ignatz-Heman
- Made ServicePoint more configurable @Ignatz-Heman
- Base Building: Replaced 0/90/180/270° direction build mode with "Rotate 90°". @Ignatz-Heman
- Base Building: Max building height now will be checked directly at building element placement. @Ignatz-Heman
- Separated Hunger and Thirst loss values to baseHungerLoss/baseThirstLoss and removed baseHTLoss from CfgEpochClient.
- Hunger and Thirst loss rates are now affected by timeMultiplier.
- Bump to hive version 0.6.0.0, Note: this requires epochserver hive extension updates server side.
- Gas Station Auto-Refuel is now disabled on all maps. Use disableAutoRefuel = false; via epochconfig.hpp to disable. @SMVampire
### Fixed
- Players are given negative rating so that AI will attack properly even if player side is civilian. @morgoth0, @Ignatz-Heman
- Player stats variables are now obfuscated, and hitpoints tracked via the server.
- Bad conversion: bool RPT spam caused by incorrect usage of configClasses. @DirtySanchez
- Snapping issues base building @DirtySanchez
- Sounds not working due to changes to 3dSay command in recent A3 updates. @DirtySanchez
- Spawning at base above Water was not working correctly. @Ignatz-Heman
- One step is higher on stairs, can't run up while crouched. #447 @Helion44
- L85 Elcan optic issues. #678 @Helion44, @DirtySanchez
- Zombie falsely triggers Mission success. @Ignatz-Heman
- Base Building 90° and 270° Snap was broken.
- Sometimes snapped Base Building elements rotated back on save.
- BE kicks since 1.76.

## [0.5.0.0] - 2017-03-17
### Added
- Epoch is leaving alpha and entering beta! All Epoch Asset project sources are now available via our GitHub +LFS and under APL-SA license here: https://github.com/EpochModTeam/EpochCore
- Added Service Point to Rearm, Repair and Refuel. Thanks to @Ignatz-HeMan
- 7 new Keesha camo skins by Craig Hauer aka ComatoseBadger.
- 64-bit database extension support for Windows (EpochServer_x64.dll) and Linux (epochserver_x64.so) servers. Linux support is pending testing.
- Custom event handler and OnEachFrame hooks added. https://github.com/EpochModTeam/Epoch/tree/experimental/Sources/epoch_code/customs Thanks to @Ignatz-HeMan
- Crafting recipe: Mortar (Uses: 12x Rock, 2x dirty water) (Requires: Fire and workbench within 3m). Thanks to @baaljayjay for the suggestion.
- Customizability of units spawned by UAV alert via CfgEpochClient > uavAlertUnitSpawnTemplate. (Default: I_Soldier_EPOCH)
- Toxic Smoke Grenades can now be found in the world.
- Respawn in base feature, each player must interact with Jammer and choose "Make Spawnpoint" to enable.
- Selling to traders with bank debt greater than -50000(default), pays the bank debt back to below the limit instead of the player. Thanks to @Ignatz-HeMan
- 200 player support to all mission files, thanks to increased group limits in Arma 1.68!
- Experimental support for Mad ArmA Mod: https://forums.bistudio.com/forums/topic/200295-mad-arma-mad-max-inspired-mod/
- "MeleeRod" (Fishing Rod) to Crafting Menu (1x Rope,1x Stick,1x Metal Scraps) @Ignatz-HeMan
- Vehicle and Loot tables can be set via epochconfig settings (forcedVehicleSpawnTable, forcedLootSpawnTable) to force specific vehicle or loot tables.
- Install script for Mad Arma mod via Steam workshop in the tools/install folder.
### Changed
- Epoch Message function now supports custom colors. Thanks to @SPKcoding
- Epoch Event: ChangeWeather has been updated to allow for better random control of weather and defaults to bad weather.
- Optimized database SET and SETEX calls in both SQF and C++.
- Optimized database GETRANGE call.
- Optimized NPC Trading and fixed issue if trade failed. Thanks to @Ignatz-HeMan
- Great White Sharks will now spawn if the player is deep enough in the ocean.
- Objects or Players that have been given "Crypto" variable can be accessed via the dynamic menu (Space Bar) for a "Take Crypto" action.
- Air Drops are now triggered via Epoch Events server side every 45m at random, instead of randomly triggered client side.
- To prevent issues with ownership only Group Leader can place a Jammer. jammerGLOnly = 0 in CfgEpochClient to disable. Thanks to @Ignatz-HeMan and @82ndab-Bravo17
- Spawn in base now use player position instead of jammers (reset spawn point to use). @Ignatz-HeMan
- Force "Take Crypto" option on dead bodies. @Ignatz-HeMan
- Added optional Classnames for Service Point Pos.  @Ignatz-HeMan
- Some Cleanups and Script optimization to the service point scripts. @Ignatz-HeMan
- Removed "Alpha" text from debug monitor.
- Add flag to enable database unit test. enableUnitTestOnStart = 1 in epochconfig.hpp to enable
- Delete rest of unused clientside Airdrop Event code.    @Ignatz-HeMan
- further optimized DB call for weather script.
- Re-add missing comments in some config files.
- Numerous other fixes and optimizations.
### Removed
- EpochServer extension calls 100 and 101 as they are no longer needed.
### Fixed
- Crash bug when opening base building upgrade menu since Arma 3 1.68.
- Wrong variable name in EPOCH_clientRevive.sqf. Thanks to @Ignatz-HeMan
- Sometimes getting stuck only walking. Thanks to @Ignatz-HeMan
- Repack of Energy Pack is now possible.
- Toxic Smoke Grenade not making you Toxic thanks to @Ignatz-HeMan
- some missing semicolons in CfgPricing. @SPKcoding
- Joining and leaving a group and optimize with added usage of params. @Ignatz-HeMan
- Group invites from the same Group were not possible until relog. @Ignatz-HeMan
- Heal not working when using SafeZones with VehicleGodmode and only HitPoint is damaged. @Ignatz-HeMan
- fix deleteVehicle BE kick with sharks
- CBA related Battleye kicks with current CBA version.
- Static weather settings not working. @82ndab-Bravo17
- Battleye kicks for CUP weapon and attachment BE kicks.
- Battleye kicks for towing tractor from CUP.
- Fixed / updated and added Trader Missions and ported to run it on Events instead fsm. @Ignatz-HeMan
- Several minor fixes, cleanup, and private array updates.
- Fix for Weaponholder disappearing while adding loot. @Ignatz-HeMan
### Security
- redis-server.exe to latest version: 3.2.100 from: https://github.com/MSOpenTech/redis/releases
- Requires Arma 3 1.68 or higher.

## [0.4.0.0] - 2016-11-02
### Added
- Dynamic and extensible inventory sub menu system for item interaction and crafting options. (Double click item in your inventory)
- Vehicle immunity when a vehicle is left locked inside a player owned base (within jammer range) at server startup. Thanks to @morgoth0 for the feedback!
- Stamina loss when a player jumps.
- Option to pour our gas to get an empty Jerry can and a "Drink" option to poison yourself.
- Option to pour out honey and get an empty jar instead of eating it.
- Example mission file epoch_RyanZed.Tanoa that includes "RyanZombies" in the required addons array.
- EpochServer.dll/so is now statically linked to pcre3 and hredis. On Windows, this means that the pcre3.dll file in the arma 3 root can now be removed. On Linux, we no longer depend on libhredis and libpcre to be installed.
### Changed
- Inventory Armor stats feature now dynamic and no longer forced via config.
- Group menu and group requests options are now found options on the self-action menu. (SPACE BAR)
- Wardrobe mirror now works in single player.
- Jetski and Electric Motorcycle motorcycle in-vehicle HUD now functions in singleplayer or editor.
- Updated Tanoa trade city layout and added ATM's. Thanks to @morgoth0 (aka Grahame on EpochMod.com Forum)
- Players now start with only 30% Hunger and Thirst instead of 100%.
### Fixed
- Increased mass of "Hotwire Kit" (ItemHotwire) magazine item from 2 to 50 to address balance issues. Thanks to PR from @Ignatz-HeMan
- Disposal of Snakes and other animals when inside a protection zone.
- Shark bite attack and effect can now target all players.
- Female ghillie suit transparency issue since Arma update 1.62.
- Fireplace position incorrectly shifted down after lighting the fireplace. Thanks for the report by @Ignatz-HeMan #592
- Increased anti-teleport range that should hopefully allow for proper HALO spawning.
- Typos in Battleye script.txt that caused the filter not to function properly.
- Trailing commas in mission addons array. Thanks to  @SPKcoding (aka $p4rky on EpochMod.com Forum)
- No longer possible to unlock Doors / Gates while using a UAV. Thanks to PR from @Ignatz-HeMan
- Database logging now trims log entries via the LogLimit setting provided in EpochServer.ini. The default is 1000 log records per list.

## [0.3.9.0] - 2016-06-19
### Added
- A big thanks to Isaac, Axeman's chief tester!
- Tanoa map support.
- New Task-based Mission System.
- (Optional) Support for Ryan's Zombies and Demons mod: http://steamcommunity.com/sharedfiles/filedetails/?id=501966277 with custom Epoch implementation.
- New custom variable EPOCH_playerNuisance that increases based on the type of weapon fired and decreases at a rate of 1 per 10 seconds. This is used to track how active a shooter the player is.
- Player option to Morph into a random antagonist (from deathMorphClass) after death. The array 'deathMorphClass' found in CfgEpochClient can be used to specify what antagonists to randomly spawn.
- Player option to detonate body after death. Sacrifice yourself by generating a runaway thermal cascade using the nano bots within your body. Nothing left to revive.
- object loot tables for zombies, sharks, and Dogs.
- looting Dogs for meat (uses placeholder object "goat leg"). Negative Karma given for eating or gutting dogs.
- Improved plant spawner by Redbeard Actual and [VB]AWOL.
- Allow Epoch Events to accept full file path if 4th variable in the EpochEvents array is set to 0. Default is 1.
- Function to effect a players Crypto server side: EPOCH_server_effectCrypto
- New experimental PBO packing tool found in Epoch/Tools/PowerShell/
- Server function to allow remote exec of setVariable on client - Allows client to ask another client to set a local variable, via the server. Server can run same function.
- Epoch AH: Added ability to kick, instead of just log or ban.
### Changed
- Increased loot bias 10% overall and increased loot density for military and other larger buildings.
- new function Epoch_message replaces Epoch_dynamicText.
- Object Interaction and EPOCH_client_bitePlayer settings in now config CfgObjectInteractions. Lootable objects can now affect player stats.
- Moved all Base Building variables to gamemode config CfgBaseBuilding.
- Moved all Item Interaction to new gamemode config CfgItemInteractions.
- Sapper groan or detonate can be triggered by setting a variable on the target or Sapper.
- The server can be asked by a client / server to trigger an antagonist on another client. Antagonist is then run on target PC, independent from caller of the function.
- Epoch Unit Spawn code. Now can be called specifying the target of the antagonist. The antagonist will run on target client PC.
- Sapper defaults tweaked to make them more responsive.
- New Sapper antagonist config options:
reflexSpeed - Set the loop pause. Defaults have been lowered to make Sapper more responsive.
nestChance - A percentage chance, at each Sapper spawn, that he will create a nest.
hideLevel - (Fear Emotion) Set level at which Sapper will go into hiding based on fear of armed players, being shot near etc.
chargeLevel - (Anger Emotion) Set level at which sapper will trigger 'charge the player' mode.
- New UAV Support Troops antagonist config options:
unitTypes - an array of soldier classes to randomly choose from. Custom weapons to-do, use soldiers with default weapon loadout or handle weapons with a custom script.
maxUnitNum - Maximum number of units to spawn per UAV.
minAISkill - Minimum value for any AI skill.
maxAimingAccuracy -> maxGeneral - Set the maximum value for each available AI skill. A random number between minAISkill and the value for each will be set as that skill.
- Changed gamemode to Survival, (might show as unknown gamemode pre 1.62)
- Reworked vehicle load function and made vehicles immune to damage for 120 seconds after startup.
- cfgpatches check now kicks by default with message a message.
- Vehicle persistence texture configs are now found in server settings PBO. https://github.com/EpochModTeam/Epoch/blob/experimental/Sources/epoch_server_settings/configs/CfgEpochVehicles.h
- Use new disableChannels syntax in 1.60 and enable text chat on side chat and not voice. Thanks to @morgoth0 for the heads up! https://github.com/EpochModTeam/Epoch/issues/544
- ForceRestart option should now restart as soon as all players disconnect and server is locked.
- Epoch Events can now self-initialize on server startup (if the third events[] array element is 1). Fixes issue with the weather not changing till first event run.
- Loot position tool: Epoch/Tools/SQF/saveLootPositionsVector.sqf
- World config tool: Epoch/Tools/SQF/getTreesAndTrash.sqf
- Changed name of a3_epoch_server.pbo to epoch_server.pbo. Also changed path from \x\addons\a3_epoch_server to \epoch_server
- Changed name of a3_epoch_server_settings.pbo to epoch_server_settings.pbo.
### Removed
- Epoch AH removed whitelisted variable check system.
- STEAMAPI Vac ban check as it needs to be reworked in the extension.
### Fixed
- To prevent A3 dupe issues Epoch Militia Solders when taking uniforms, they no longer have uniforms.
- To prevent animation glitch with weapon switching on the move and holstering. You now must be standing still to holster your weapon.
- Custom Epoch Gestures not working since 1.60.
- Issue with animals not returning raw meat.
- Getting wet and cold on standing on pier. Thanks to umfufu for the report! http://epochmod.com/forum/topic/41929-getting-10-points-of-wetness/
- Missing texture issues with some base building objects since 0.3.8.
- Take into account trader stored per class vehicle limits when spawning new vehicles.
- Disappearing Mags on login / revive. Thanks to He-Man for the fix: http://epochmod.com/forum/topic/42178-disappearing-mags-on-login-revive-fix/#comment-277194
- CUP mods enabled check logic typo. Thanks to @morgoth0 for the report: https://github.com/EpochModTeam/Epoch/issues/543
- BE kick when player opened stock A3 dialog (Game > Options > Layout).
- BE kick with Spawn Loot admin panel option. Thanks to @jostster for the report: https://github.com/EpochModTeam/Epoch/issues/540
### Security
- RConPort 2306 added to example-beserver.cfg for changes since A3 1.58.
- Removed old .bikey and added new one for 0390.
- Requires Arma 3 1.60 or higher.

## [0.3.8.0] - 2016-03-15
### Added
- FastNights Epoch Event. http://epochmod.com/forum/topic/41949-accelerated-time/?do=findComment&comment=275310
- Install batch for all CUP mods and CBA. https://github.com/EpochModTeam/Epoch/tree/release/Tools/Install
- Split gamemode from main assets, all epoch client gamemode code and configs are now found in the mission file under APL-SA license. https://github.com/EpochModTeam/Epoch
- Support for CUP Vehicles and Weapons.
- Display temperatures in both Fahrenheit and Celsius.
- Fully reworked loot object spawn system.
- Headers added to all gamemode files that include: Author, Description, Github Source link, Usage, and Examples.
- All text based feedback now use new EPOCH_dynamicText function.
- Show current build number on debug monitor.
- Player Karma stat is now effected by Arma 3 rating system via Event Handler. More TBA.
- Players can now harvest Hemp from maps that it grows wild.
- Support for Napf by Momo and ANixon http://steamcommunity.com/sharedfiles/filedetails/?id=635780806.
- Batch files to rebuild server and mission pbo's can be found in Github Root/Tools/Build folder.
- Updated version redis-server.exe to latest build (2.8.2400) and added full Redis config examples.
- limit to number of plant sites that can spawn. Can be controlled with "plantLimit" inside (CfgEpoch >> worldName).
- Support for Eden editor mission files (version 51) and attributes.
- Battleye filter updates for CUP Weapons and CBA.
### Changed
- Trash looting is now done by interaction system only. Hold Space Bar and choose Examine.
- Can now over heat if fatigued and air temperature is greater than 100F or 37C
- Crafting now supports Water sources from 'CfgWorldInteractions' configs.
- Moved Cultist and Sapper permanently to the enemy side.
- Disabled remote sensors on server and client as all AI Epoch is locally controlled. https://community.bistudio.com/wiki/disableRemoteSensors
- Repacked all pbo's to make use of the new 32-bit P3D binarization process. https://dev.arma3.com/post/techrep-00026
- Massive code overhaul to make use of many new SQF commands instead of slower SQF logic.
- Increased the amount of Krypto a player can hold from 25k to 250k.
- Improve loot positions in existing maps and add more missing positions for CUP maps.
- General cleanup and reorganizing of files.
- Moved vehicle spawn limit configs to per map configs found in server settings PBO (CfgEpoch > WorldName > allowedVehiclesList).
- Use BIS_fnc_addStackedEventHandler for onEachFrame, onPlayerConnected, onPlayerDisconnected to increase compatibility with other mods like CBA.
- Lower disconnect timeout to 10 seconds with disconnectTimeout set via config.cfg. https://community.bistudio.com/wiki/server.cfg
- Mission system can now use missionConfigFile configs.
- publicVariableClient calls changed to use remoteExec. This should provide better performance and reliability as PVC's can be unreliable under heavy use and can also bottleneck the games netcode.
- CfgClientFunctions is now able to be overridden via description.ext.
- Fully removed BIS MP init override and added remoteExec BE filter rule for initPlayerServer.sqf usage. (Still must be whitelisted in remoteExec configs to use)
- The function EPOCH_fnc_addItemOverflow now supports spawning items and weapons types given a count.
- Moved the secure storage config variable 'returnOnPack' from cfgvehicles config to CfgBaseBuilding.
- Make use of new getOutMan EH for vehicle epoch anti wall glitch checks.
- Change last few uses of hintSilent to Epoch_dynamicText. Now only the debug monitor uses hintSilent.
- 1.58 Difficulty Overhaul changes to enable 3rd person. Thanks to klinGiii on the forum: http://epochmod.com/forum/index.php?/topic/41922-158-difficulty-overhaul
- Epoch AH reworked displayAddEventHandler checks to use CfgEpochClient configs.
- Increased range for vehicle interactions to fix issues with access to larger vehicles. Thanks to Grahame for the report: http://epochmod.com/forum/index.php?/topic/41894-cannot-unlock-large-vehicles/
- Preloading sapper by spawning one on the map at server start.
- Change to Github markdown for credits and license.
- RConPort 2303 added to example-beserver.cfg for changes since A3 1.58.
- epochAH.hpp updated "antihack_checkFiles" for new file paths.
- Some AI Scripts Mods may not work with disableRemoteSensors enabled. You can disable with "disableRemoteSensors = false;" in CfgEpochClient.
- Defined proper settings in full redis-example.conf
### Removed
- Old BEC plugin as its not needed anymore.
### Fixed
- Temporary direction and angle placement issues when base building.
- Force player to lobby if the player did not tapout after timer runs out.
- Incorrect scope on some magazine items prevented them from showing in the admin spawn menu.
- Reworked player login, fixes issues with players logging in without gear (when one or more players are logging in at the same time, IE. server startup)
- suppress loot spawning at main traders. Thanks to Ghostrider-DbD- for the report. http://epochmod.com/forum/topic/41954-loot-spawning-at-traders/
- BE kick since 1.58 hotfix. http://epochmod.com/forum/topic/41961-rscdebugconsole_watch-battleye-kick/?do=findComment&comment=275456
- Use player object as input for remoteExec instead of owner net ID. http://epochmod.com/forum/topic/41959-be-carefull-with-remoteexec-and-owner/
- Attempt fix issues with temporary angle and rotation issues with base building.
- Check for base kit item is in players inventory before spawning ghost.
- Prevent empty group menu display. Thanks to He-Man! for the fix.
- Group system marked player as "Dead Player" if moderator status was change while player offline. Thanks to He-Man! for the fix.
- Group system invite and kick from group options not working. Thanks to He-Man for the fixes: http://epochmod.com/forum/topic/41893-group-menu-broken-kick-invite-for-admin-not-possible/#comment-275429
- Rewrote deleteVehicle.txt BE filter to correct filter syntax to fix false kicks. Thanks to BetterDeadThanZed for the report http://epochmod.com/forum/index.php?/topic/41933-players-kicked-for-moving-safes/#comment-275297
- Fixed Arma install batch script not closing after update.
- Mission loot payout not working. Thanks to @He-Man for the fix: http://epochmod.com/forum/index.php?/topic/41892-payout-trader-mission-broken/
- Crafting recipe for Vehicle Repair Kit had the wrong part in usedIn array. Thanks to LeBarbare for the report: http://epochmod.com/forum/index.php?/topic/41896-wrong-recipe-place/
- Green Marked traders unable to be accessed. Thanks to @He-Man for the report: http://epochmod.com/forum/index.php?/topic/41887-radom-unexpected-script-failure-with-traders-ai_slot/
- Trailing commas in CfgLootTable.
- Disallow building inside of vehicles.
- Incorrectly enabled CUP vehicles and weapons support if only Core and Maps were enabled.
- remoteExec Battleye kick fixed.
- Player gets stuck waiting for inventory to load.
- Delete base object if over limit.
### Security
- Required Arma 3 version is now 1.58 or higher.
- Removed old .bikey and added new one for 0380.

## [0.3.7.0] - 2016-01-28
### Added
- Drinking a Soda now returns an Empty Soda Can (ItemSodaEmpty).
- Eating a can of food now returns an Empty Tin Can (ItemEmptyTin).
- Repack magazines feature. Simply select a magazine and press the "Repack" button.
- 55 Gallon (210 liters) Fuel Barrel that can be used to refill/siphon vehicles. (Full - ItemBarrelF,Empty - ItemBarrelE).
- Ability to siphon fuel from other fuel sources like gas stations and gas tanks (transportFuel > 0).
- Crafting Burlap (ItemBurlap) from 2x Hemp (ItemKiloHemp) while at a workbench.
- Crafting of Plywood sheets (ItemPlywoodPack) from 3x Wood Log (WoodLog_EPOCH).
- Crafting of Aluminum Bars (ItemAluminumBar) from 6x Empty Soda Cans (ItemSodaEmpty) and one jar of water (water_epoch). Also requires a fire nearby.
- Crafting of Tin Bars (ItemTinBar) from 6x Empty Soda Cans (ItemEmptyTin) and one jar of water (water_epoch). Also requires a fire nearby.
- Copper Bars (ItemCopperBar) that can be crafted from cables (ItemCables) nearby a fire. Cables can also be made from Copper Bars at a workbench.
- Briefcase Full (ItemBriefcaseGold100oz) crafted from ten 10oz Gold bars and an Empty Briefcase (ItemBriefcaseE).
- Crafting of Bars (ItemGoldBar and ItemSilverBar) from Gold (PartOreGold) and Silver (PartOreSilver) Ores.
- Pack/unpack empty backpacks into carryable magazine items.
- Hotwire Kit (ItemHotwire).
- Key Makers Kit (ItemKeyKit).
- Keys in colors: (Black ItemKey,ItemKeyRed,ItemKeyGreen,ItemKeyBlue,ItemKeyYellow).
- Metal Pipes (ItemPipe).
- Documents (Trash,Books,Vehicle Upgrades) (ItemDoc1-8, ItemVehDoc1-4).
- Light Bulb (ItemBulb).
- Newly world spawned vehicles now have randomized damage.
- Setting to control random magazine ammo counts in loot spawner. CfgEpochClient -> randomizeMagazineAmmoCount (default: true)
- Debug box now dynamically spawns with flood lights to help players see inside the box at night.
- CfgEpochClient 'WorldInteractions' config now stores all environmental loot classes and types for all supported maps.
- CUP terrain pack support added: Sahrani, Southern Sahrani, United Sahrani, Porto, Utes, Chernarus, Chernarus Summer, Desert, Takistan, Zargabad, Shapur, Proving Grounds, Bukovina, Bystrica, Takistan Mountains.
### Changed
- Upgrading Wood Stud Wall and Tower to Plywood covered versions requires Plywood (ItemPlywoodPack).
- Debug monitor now shows all custom stats dynamically based on 'customVarsDefaults' config.
- Increased angle that the player is able to aim up.
- Drinking Alcohol increases the new "Alcohol" stat instead of directly affecting blood pressure.
- Crafting Hesco barrier now require 3x Burlap.
- Crafting wood and metal spike traps now also require Sticks and a Hydraulic Jack.
- Change all publicVariableServer calls to use remoteExec calls for better performance.
- Removed support for AIA terrain pack in favor of CUP terrain pack.
- Empty fuel barrel added to large trash and vehicle loot tables.
- Earthquakes with mineral veins spawn chances increased with less players.
- Driver or passengers of a driverless can now control vehicle locks. Also, only the owner can control locks from outside of an occupied vehicle.
- Commented out Halloween masks from loot tables.
- Player positions in database now use Epoch precision position functions.
- New Battleye remoteExec.txt for added remoteExec calls.
- if the 5th array element is true 'telePos' config array can now use world position for teleport pads location.
### Fixed
- Previous patch had incorrectly reduced armor values of the Cultist.
- Male(Female) characters lose vest items after equipping opposite sex's vest.
- Secure storage locking mechanism improvements should prevent any unwanted intrusions.
- Reworked login to prevent getting stuck at "waiting for inventory".
- Prevented death just after revive due still having high blood pressure.
- Incorrectly being able to sell/buy items from a dead trader.
- Snakes now require line of sight to bite player.
- Custom epoch swing animations for Hatchet and sledge now work correctly.
- Boss Sapper incorrectly cleaned up before detonation.
- Admin tools map AI markers not working.
- Static propPos campfires not working on Takistan due to disabled simulation.
- When killed instead of saving blank array delete (object, trader, vehicle) data from database.
### Security
- For CUP, use double quotes around mod for spaces in folder Example: -mod="@Epoch;@CUP Terrains - Core;@CUP Terrains - Maps;"
- Removed old .bikey and added new one for 0370.

## [0.3.6.0] - 2015-12-17
### Added
- Ability to sell Primary weapon from hands and empty backpacks. Thanks to @He-Man
### Changed
- Increased max player load 2x to compensate for the new stamina system in 1.54.
- Increased backpack storage limits to allow carrying long weapons.
- Weapons will now only spawn with a single magazine and a random ammo count.
- Magazines now spawn with a random ammo count.
- Disable simulation of locked storage devices. This also prevents removal of items until device is unlocked/re-simulated.
### Fixed
- New workaround for inventoryOpened and locked storage protection.
- cursorTarget function to only use new Epoch method while underwater. Should help with targeting issues on land.
- Canceling build mode did not remove the ghost object as it should have.
- Updated Epoch armor stats UI system to support new changes since 1.54.
- Changes to default Arma weapon configs to allow long (Lynx, etc) weapons to be stored in backpacks.
- Unable to sell after attempting to sell a temporary vehicle. Thanks to @He-Man
- Updated Hitpoints for all custom Epoch characters, fixes the hitpoint .rpt errors since 1.54.
- Reduce run speed of Sappers since 1.54 update.
- Wood tower "add/remove wall" options are now only available when build mode is enabled.
- Typo in server side AH event handler code and repacked a3_server_settings.pbo.
- Storage was incorrectly set to set damage to 99% instead of 1%.
- Add player objects to remains collector, this should allow for proper corpse cleanup.
### Security
- Removed old .bikey and added new one for 0360.

## [0.3.5.0] - 2015-12-09
### Added
- Metal Floors as upgrade in-place option for wood floors.
- Gender selection screen improvements.
- New interaction system.
- Persistent wood and metal spike traps.
- New custom 3x wide hesco type barrier.
- New custom tank trap.
- Updated version of the Fishing Rod. The reel was too small.
- Documentation on server core framework functions and hive calls.
- muzzle_snds_338_sand to loot and pricing tables.
- Client side master loop is now fully config (CfgMasterLoop) based.
- Ability to fully change default player loadouts via CfgEpochServer configs:
(defaultGoggles, defaultHeadgear, defaultBackpack, defaultVestFemale, defaultVestMale, defaultUniformFemale, defaultUniformMale, itemsInContainers, weaponsInContainers, normalMagazines, weaponsAndItems)
- Server pack Tools folder now contains InstalEpoch.cmd that is an updated version of the command line download Epoch client files download script for steam workshop.
### Changed
- Disable simulation of locked storage devices. This also prevents removal of items until device is unlocked/re-simulated.
- Made wood ramp shorter by about 30% and slightly reduced height of wood towers and stairs.
- Refine ghost preview base building snap checks.
- Players now start with a Quartz radio by default.
- Overhaul of secure storage system to make it faster.
- Increased reverse token check timeout from 90 to 180 seconds.
### Fixed
- Typo in server side AH event handler code and repacked a3_server_settings.pbo.
- Storage was incorrectly set to set damage to 99% instead of 1% to temp force maintenance option after restart.
- Add player objects to remains collector, this should allow for proper corpse cleanup.
- Selection ring now correctly shows damage/decay level of target when build mode is disabled.
- Was unable to use cursorTarget underwater, fixed using new custom made function.
- NPC item trades that cannot fit in the player's inventory will be placed at the feet of the player.
- Not losing Stamina while swimming.
- Removed extra roadway on top of columns.
- Error Zero divisor in client-side master loop.
- .rpt error after gutting animal.
- Dynamic traders did not correctly track the stored vehicle count and limits.
- Force trader data save to save when loading starter items.
- Added private array to all Epoch Event scripts due to feedback.
- Removed forced weather sync on server startup from server init phase so weather changes are now solely dependent on Epoch Events weather script.
- EPOCH_fnc_returnConfigEntry and V2 functions did not use defaults properly.
### Security
- Removed old .bikey and added new one for 0350.

## [0.3.4.0] - 2015-10-14
### Added
- The source code for the a3_epoch_server.pbo is now on the GitHub.
- Fishing Pole and ocean fishing also added crafting recipes to allow cooking fish.
- Workbench storage device added and used as a nearby crafting requirement for most Kit based crafting options.
- New secure storage device: The Epoch Safe.
- Totally new crafting system and UI by Raymix.
- Epoch variant of the unarmed Strider vehicle. (I_MRAP_03_EPOCH)
- Broad Sword Melee weapon that can chop down trees and mine rocks.
- Halloween Clown mask and re-added Wolf/Pumpkin masks to loot tables as well as Meeps Candy.
- New Quiet dog bark and whine.
- Example "Epoch Event" Code to provide an example on how to broadcast a message to all players using BE.
- 'CfgTraderLimits' config can control stock limit per trader per item. Default is 100 per item class per trader.
- storedVehicleLimit variable in CfgEpochServer can now control the total max allowed vehicles on traders. Default limit is 20.
### Changed
- Fixed boats spawning on land and added 3d waypoint to purchased vehicle location.
- Removed debug hint text for 3d rotation of objects as it was not needed.
- Re-enable Move button, this system will stay and be refined in the next few patches.
- Dog text format updated.
- Dog whine, instead of bark, when alerting of other nearby players (When player crouched).
- Dog prey kills now use animal looting system. i.e. Dog will loot dead animals, and other objects then will fetch loot.
- Attached weapon (loot) holder is now dropped if dog finds a new one. Needs update.
- Make dog sounds global and use quieter sounds to alert player once dog is tamed. Untamed dog or when attacking is still loud.
- Add occasional quiet dog whine when other players in the area.
- General Dog timeout tweaks to compensate for Arma Animals 'doing their own thing'
- Reworked secure data storage system to be more reliable. (NOTE: This may cause issues with existing lockboxes spawn on the ground with incorrect orientation.)
- Base building maintain option now also maintains storage devices.
- Moved vehicle spawn config that controls how many vehicles can spawn at different location types to settings pbo. See new vehicleSpawnTypes array in the (WorldName).hpp config.
- Use new sort command instead of BIS_fncSortBy.
- Use new worldSize command as default if maps worldSize setting in CfgEpoch does not exist.
### Fixed
- Dog not taming due to var reset in wrong place / BIS animal update.
- Unable to remove lit fireplace.
- Group members unable to lock a Lockbox or Safe that was placed by the group leader.
- Shadow artifact at top of Jammer.
- Reduce client fps lag when first joining the server by preloading objects before exiting loading screen.
- Being unable to remove a solar generator.
- Angry Pumpkin mask was incorrectly visible in first person.
- Issue with Headless clients being treated as players. @dayzai/Face
- Logging to the database was not working due to missing function.
- Issue when trading vehicles that caused the trader data to save data to the wrong slot.
- Added missing prices for female vests.
- Error Generic error in expression in EPOCH_server_repairVehicle.
### Security
- Removed old .bikey and added new one for 0340.

## [0.3.3.1] - 2015-09-11
### Fixed
- Energy was incorrectly allowed to fall below 0.
- Typo that prevented small vehicle repair kits from working.
- Issue that caused the wrong base building upgrade-in-place option to be selected.
- Targeting issues with trash, snakes, and dead Sappers.
- Three male vests had invisible texture issues.
- Added check for getAllHitPointsDamage returning a blank array when loading buildings.
- Error in rpt when spawning vehicles if no class was selected.
- EAH was banning revived players incorrectly due to token changed check.
### Security
- Removed old .bikey and added new one for 0331.

## [0.3.3.0] - 2015-09-11
### Added
- Basic energy capacity system controls how much power is available based on the type of energy source.
- New upgrade system for Wood Tower, add two lumber packs to add windowed wall.
- 4 new plywood walls as first level base walls.
- Wood Ladder that can be crafted from 4x lumber.
- Wood Tower that can be crafted from a Wood Floor and 4x lumber.
- Solar Generator base item can be crafted from items found in the world. When placed gives passive power within (75m Default).
- New loot/crafting items (Solar Panels, Wire Cables, Battery Box) added to loot tables.
- NightVision now use a static rate of 3 per 10 seconds. This can be changed with 'energyCostNV' variable via CfgEpochClient.
- Max rate of energy gain can be controlled with 'energyRegenMax' variable via CfgEpochClient.
- Max range of energy gain can be controlled with 'energyRange' variable via CfgEpochClient.
- Standard base building upgrade system now supports multiple options and has a basic UI.
### Changed
- Moved client gamemode and CfgFunctions init to mission file.
- Base building upgrade recipes and remove payouts now have dedicated config "CfgBaseBuilding" and code supports over-loading via description.ext.
- Removed base object "Move" in 3d option in favor of a more refined ghost snap mode.
- Server side database functions renamed and now use cfgFunctions via a new pbo "epoch_server_core".
- Increase max payout of Air Drop event loot.
- Make use of new command getAllHitPointsDamage in A3 1.50 to increase the performance of hitpoint data storage.
- Use new A3 command setHitIndex instead of setHitPointDamage so we can use all hitpoints regardless of name.
- Change BIS_fnc_distance2D usage over to distance2D command that was added with A3 1.50 for better performance.
### Removed
- CfgEpochClient removed from description.ext as it can be simply added again from our configs as needed.
### Fixed
- Cultist spawning is now fixed.
- Can now press '2' to disable building snap mode and 1 to re-enable.
- Can now disable base building by pressing Esc or 'gear' menu.
- Normalized snap memory points for wood tower and stairs.
- Loot code for "CfgBuildingLootPos" now uses EPOCH_returnConfig to allow over-loading via description.ext.
- Error in rpt "No geometry and no visual shape" with Poppy and Goldenseal plants models.
- JetSki sinking like a rock since Arma 1.44, fix was to add buoyancy=1 property to GEO lod.
- The angle of snapping was incorrect when building on angles.
- Issue that caused shifting of some base objects after restart.
- Pumpkins on Chernarus incorrectly payout trash loot and now have separate configs for extra trash loot items.
- Color not persisting when picking up corrugated walls.
- Only maintain damaged objects and object health is repaired on maintain.
- CfgEpochClient missionConfigFile version check was incorrectly using configFile.
- Loot object "Blue Tarp" weaponholder proxy position was in the wrong position.
- Reduce base hunger/thirst loss rate by half if players stamina is above 100. Base rate now can be changed with "baseHTLoss" variable in CfgEpochClient.
### Security
- Requires Arma 3 1.50 or higher.
- Removed old .bikey and added new one for 0330.

## [0.3.2.0] - 2015-09-11
### Added
- Please welcome our newest team member SteamPunkGears http://www.twitch.tv/steampunkgears
- New food item Tactical Bacon gives 500 hunger.
- Revamped upgraded wood stair model. @SteamPunkGears
- Armor stats for Uniforms, Vests, and Headgear now visible on inventory GUI.
- Consume and Craft buttons added to inventory GUI, allows quicker action and identification of craftable items.
- New custom wood log model. @SteamPunkGears
- New Medicine Cabinet loot object that spawns mostly medical loot. @SteamPunkGears
- Custom Epoch Client function compiler.
### Changed
- Lowered armor on certain base building objects that had way too much armor.
- Increased hunger and thirst loss a bit and you can now die from prolonged lack of hunger or thirst.
- Tweaked stats UI thresholds so that players will now see notifications sooner. Icons are now colorized and flash when at a critical level.
- version.txt added to client files to aid file mirrors.
### Fixed
- Incorrect class for snake prevented killing snakes and looting them.
- Use init eventhandler to remove local snakes and rabbits on spawning as maps other than Altis or Stratis spawn them randomly.
- Dog brain targeting updates for prey like snakes and chickens.
- AirDrops now have there own loot table with better loot payout.
- Bornholm environmental loot configs had incorrect p3d names. Thanks to Robio!
- Missing price value for M-900 helicopter.
- Swap all references of old Rahim 10Rnd 762x51 to 10Rnd 762x54.
### Security
- Removed old .bikey and added new one for 0320.
- Added //new2 to the top of scripts.txt to enable kicking again.

## [0.3.1.0] - 2015-07-29
### Added
- Epoch version of the M-900 helicopter with all texture variants.
- Crafting of Energy Packs from electronic components, clean water and near a fire.
- Experimental Sapper Migration Event.
- Increased precision of positions stored in database for Bases, Vehicles, and storage.
- More variations of soldier classes and loadouts (from drone detection).
- CfgBuildingLootPos can be now overridden via missionConfig.
- Weather code migrated into an Epoch Event and code moved to settings pbo.
### Changed
- Lower crafting requirement of cinder block wall, from 4 cinder blocks to 2.
- Removed Epoch setWaves sync code as it should no longer be needed after 1.46.
- Female Ghillies armor, weight, storage now match CSAT male variants.
- Female Wetsuits armor, weight, storage now match CSAT male variants.
- Female Camo Clothes armor, weight, storage now match "Guerilla" gear, like "U_OG_Guerilla2_2".
- Increased loot position bias for all buildings from 15 to 25%.
- Enabled Air Drops.
- Added small chance for primary weapons to be found under green military beds.
- Land_Laptop_device_F can now be used as a Bank terminal.
- Config.cfg requiredBuild and hostname for A3 1.48
- Added Bornholm blocked areas to main config and description.ext. Thanks to DarthRogue!
### Fixed
- Typo in esseker.h position only had 2 elements of the needed 3 for setposATL.
- Added checks to make sure you can only P2P trade while not in a vehicle.
- Re-add missing AiA TP and Bornholm loot positions.
- Fixed "no config.bin SmokeShellWhite" error when sapper off gasses.
- Environment sounds had been disabled. Removed enableEnvironment false; from client init.
- Can't chop down tall trees. Converted to 2d Distance check.
- Shipping container doors did not open and threw error. Updated to the 1.48 way of opening doors using functions.
- Shoeboxes added to more building on Takistan and any other maps that use the same building classes.
- Vehicle storage space has been normalized. Thanks to Uro1!
- Missing function compile for helicopter Air Drop.
### Security
- Server pbo is no longer obfuscated.

## [0.3.0.4] - 2015-09-11
### Added
- Support for Esseker map.
- Support for Takistan and loot positions for more AiA TP buildings.
- Support for Australia Terrain Thanks to the communites of http://uk-gaming-zone.co.uk/, http://thewild.zone, http://www.utomnia.com/
- More loot positions for AiA TP buildings and updates to existing positions to add pallets and freezers.
- Female characters now have uniform storage once again.
- Server side config for max player Krypto limits.
- Environmental loot checks recoded and now allow for config via description.ext.
- Drone spawn chances reduced.
- Client spawning Sapper and Drone chance can now be controlled via description.ext.
- Server side version check added to CfgEpochClient.
### Changed
- Reduce payouts on scrap metal farming.
- Disabled Vehicle Simulation Handler by default as it does not seem to be needed anymore. re-enable vehicle simulation handler with simulationHandler = true in epochconfig.hpp.
- lower primary weapon spawn chances.
- Lower Krypto value for metal salvage and scraps.
- Disable moving traders by default again (Needs recoding in fsm)
- Increased weight of Cinder Blocks and Mortar Buckets.
- Revert workaround for 1.46 crash fix requires 1.46 build 131265 or higher.
- telepos array now uses modelToWorld offsets instead of world space positions.
- Increased delay between antagonist spawns to 10 minutes.
- Updated description.ext and mission pbos for new cultist configs.
- Updated windows command line example to show usage of -serverMod
### Removed
- Helicopter air drop event code disabled by default as it needs more work.
### Fixed
- Increase range on proximity checks for gear should help with loot target issues.
- Krypto device will now only drop if player actually had Krypto.
- Added missing backpack B_AssaultPack_blk to loot table and pricing.
- Teleport issues on Stratis or any other map with one or less teleport pad.
- Added prevention of using tactical view.
- Unable to sell new 762x54 150Rnd ammo box.
- Energy, krypto stats shown and mouse auto centers once again when opening inventory.
- Recoil_default error on first use of hatchet.
- Weight added to SR-25 and L85A2 rifles.
- Lower base armor on characters to Arma defaults should fix issues with damage reporting.
- Cultist should now spawn correctly and also has a totally reworked code structure.

## [0.3.0.3] - 2015-05-31
### Added
- Use starter items array if existing trader loads without any items.
- Example of extended BE settings, will need tweaked if used.
- Latest version of redis-server.exe for Windows v2.8.19.1 from https://github.com/MSOpenTech/redis
### Changed
- Passing a 4th param in propsPos (true) will disable simulation (should be used on objects without doors or other animations)
- propsPos config can now take an array with {vectorDir,vectorUp} instead of azimuth to get precise positioning.
- setvariableval.txt updated to filter player object names and changed logging back to kick.
- Forced disable simulation of most props in altis.h.
### Fixed
- Fix possible crash while using Battleye integration under high load (epochserver.dll and epochserver.so updates)
- Force save of building to fix issue with data expiring while in play.

## [0.3.0.2] - 2015-05-02
### Added
- Server side function "EPOCH_serverCommand" can use the following BE commands: shutdown, lock, unlock, message, kick, ban.
- Battleye integration of loadbans and loadevents so (BEC + watchdog) should no longer be required.
- Scripted server restarts now broadcast a message 5 minutes before restart lock the server and message every 1 minute, then kicks everyone with the message "server restarting" before forcing a restart.
- Linux support added.
- Modified Linux start script by BIstudio and Nasdero.
- Major Epoch Anti-Hack updates to make more config based.
- Experimental learning mode to EAH whitelist variable check. Disabled by default as it requires some setup to prevent false positives.
- Battleye integration within the DLL now. (requires battleye IP, port,password in epochserver.ini)
### Changed
- Uniforms now store items again.
- Disabled MD5 check.
- Optimized when writing/reading more than 8K chars to database.
- Traders now move to work and home by default forceStaticTraders = false.
### Removed
- Removed srifle_DMR_03_spotter_F from loots.h as it is missing textures.
### Fixed
- Multiple NPC missions started at the same time caused dupe.
- Typo in killed event handler caused false BE kick.
- Group names may only contain alphanumeric characters - or _.
- Server side trade FSM updated to fix direction issues.
- Marker should now move with trader as they move from work to home.
- Issue with occasional data corruption when saving more than 8k chars.
### Security
- Filter invalid database data input for better security.*
- *pcre3.dll must be installed into the Arma 3 root directory.

## [0.3.0.1] - 2015-03-14
### Added
- Damage level of base building objects now based on expiry time.
- The owner of a Frequency Jammer device can now remove and get full refund of Jammer kit.
- Ability to remove normal storage devices (Shelf and Tipi). Items will be dumped on the ground along with a partial refund of crafting materials.
- Edit or add Trader prices "CfgPricing" via the missionConfigFile. (Documentation link)
- Edit or add Crafting recipes "CfgCrafting" via the missionConfigFile. (Documentation link)
- Antagonists spawn system overhaul with spawn bias system. (Documentation link)
### Changed
- Persistence of damage of Base Building and storage objects removed.
- Balance loot and increased chances for explosives.
- Server settings "CfgEpoch" configs are now split based on the map for better clarity.
- Crypto is now only tracked and stored via the server.
- Moved loot configs to epoch server settings PBO. (Documentation link)
- Chance to spawn sapper every 5 minutes (max of 3 within 800m). Chances increase while in a city and if the player is soiled.
- Chance to spawn drone when player fires weapon (max of 3 within 800m). Chances increase while in a city and are reduced if player uses a silencer.
- Initial Sapper spawn distance increased.
- SR-25 and L85a2 use existing ammo now.
- Increased damage for Speargun x2.
- Updated 3d interact system with new icons (Unknown, Dead Body).
- Marker colors for loot events changed to orange.
- lower default NPC starter items.
### Removed
- Removed developer debug from AH admin.
### Fixed
- UAV drone now spawns correctly at a distance so that it is longer audible on spawn.
- Incorrect text output if trader is at max limit for item.
- rvmat texture path issues with Pink L85A2
- Mission document payout now uses unified loot spawn function.
- Lower example NPC starter items to 50.
- Vehicles didn't spawn in Citys on Bornholm. (Thanks to DarthRogue)
### Security
- Updated example server.cfg for 1.40.

## [0.3.0.0] - 2015-03-11
### Added
- Wood and cinder base objects now show damage state when over 50% damaged.
- Car Jack item added to every fresh spawned vehicle.
- Can now loot a dead UAV Drone and in return get Electronic components.
- Ability to specify starter items for freshly spawned traders via epochconfig.
- New custom epoch weapons: SR-25 and L85A2 (Grenade Launcher and Pink Painted) by Kiory.
- Vehicle lock time is now stored in hive and will persist across server restarts.
- 3d interaction visuals to show you when an action is available.
- New loot bias system with nestable tables and overall loot balance.
- LootMultiplier in epochconfig, (0.5 default, 1 = high loot, 0.1 = low loot).
- Goldenseal plant can be consumed to reduce toxicity.
- Pumpkin food item can be harvested from pumpkin patches on Chernarus and found randomly.
- Dynamic Air Supply Drop Event. Use smoke grenades to signal.
- Trader mission accessed with "Talk" on trader: Pikes Peak Express.
- Ability to eat raw foods but at the risk of toxicity.
- New items (Rock, Stick, and Rope) for crafting and added to trash loot.
- New craftable primitive melee weapons: Crude Hatchet, Wood Club, Maul Hammer.
- Keesha default character now has shoes.
- Crafting of Rope from Hemp.
- Harvest Sticks from a bush using a Hatchet.
- Mining of Iron Ore and Rocks with sledgehammer.
- Removal with refund of Base building items. Respects Jammer Owner and group.
- Most base building items now use a hybrid Static/Physx system with ghost preview on first placement.
- Epoch Events 2.0. All server time based events moved to server settings pbo. Scripts are executed with execVM using a simple timer. New events and timers can be changed via epochconfig.
- New "Boss" Sapper variant with a larger bang.
- Both Sapper variants put off toxic gas if killed without blowing up.
- Player can now select gender after each death.
- Frequency Jammer now required by default to build a base. Can be controlled with desc.ext mission variable: buildingRequireJammer.
- Building limit (default: 100) added to Frequency Jammer. Change with desc.ext mission variable: buildingCountLimit.
- Building Jammer Range (default: 75m). Change with desc.ext mission variable: buildingJammerRange.
- Hive weather control system as well as Static override var WeatherStaticForecast via epochconfig.
- Trader purchased vehicle position can now be controlled with a smoke grenade or a chemlight within 50m of trader.
- Wood foundations can be crafted with 8x lumber.
- Bornholm Support: Custom a2 building classes for loot spawns and mission file and config support from http://urogaming.co.uk/
- Base building objects now persist damage and armor increased substantially.
- Suppress loot spawn within the range of a Frequency Jammer.
- Blocked base building areas for Chernarus.
- Logging of building, storage, and vehicle killed events to hive log. (StorageKilled, VehicleKilled, BuildingKilled)
- Offroad MG Pickup. (Classname: B_G_Offroad_01_armed_EPOCH)
- Server FPS to the debug monitor. (Max: 50, recommend fps are >15 to keep the game stable)
- Chance to spawn Lockbox and Backpacks in lockers or wardrobes.
- Variable when Loadingscreen finish. (EPOCH_loadingScreenDone change from nil to true)
- Base object interact menu (Remove, Move,Upgrade) shown only in build mode after targeting object with Space Bar.
- Admin Tool: Different Map Marker for Vehicles, AI, Player, Loot, Base Building and Dead Player.
- Admin Tool: Different 3D Tools for Player, Vehicles, and Loot.
- Admin Tool: Features: God Mode, Spawn Loot, Teleport In-front.
### Changed
- Toxicity increase from consuming a toxic food item is now random.
- Increased default antagonist spawn chances.
- NPC Trader inventory menu now stacks like items and shows quantity.
- Players are now sent to the lobby after dead, simply press ok to respawn.
- Can now sell and buy uniforms from traders.
- NPC trader data (AI_ITEMS) will now expire in 7 days if no changes are made within that time. Change this with expiresAIdata in epochconfig.
- Added chance to spawn Lockbox and Backpacks in lockers, wardrobes, shipping containers.
- Fireplace recipe changed to require 2 Rocks and 1 Stick to make empty fireplace. Then upgrade with 1 Wood Log to start the fire.
- Player names saved to a separate data set on player connect.
- Deathlog now logs distance and position.
- Sapper's brain reworked.
- Display of personal Crypto balance when opening bank interface.
- Loot Balance: Lowered heavy muzzles count & increased pistol muzzle.
- Increased loot bias for Ferris Wheel and corrected z-height on loot positions.
- Improve Cleanup System on Server.
- Behavior changed on UAV troop support.
- Dog to glitch less, reduced whines and more chance to wander.
### Fixed
- Accuracy and fire rates of custom ported A2 weapons fixed (M107, AKM, M4A3, M16, M14, M249).
- Sharks not spawning off shipwrecks.
- Black icons on admin panel spawn menu.
- Soiled and Wet calculation corrected.
- Pumpkin patches on Chernarus now payout proper loot.
- Traders now only allow one vehicle per trade.
- Alpha transparency issue with empty clone vats.
- Attempt to prevent vehicle damage during server startup.
- Removed fireplace sound for now due to Arma issues with sound cleanup.
- Frequency Jammer can not be built or placed within 3x Jammer radius. (default 225m)
- GUI scale issues with additional button menu (Group Menu, Requests) on inventory.
- Missing sounds on Ruger pistol and removed ability to use silencer.
- Dupe fixes for backpacks, vests, uniforms.
- Player revive did not work even after respawn.
- zasleh1_proxy.p3d error with M4A3.
- Prevent loot objects from spawning under the ground.
- Group kick and mod options did not work.
- Cleanup and removal of unneeded rpt debug logs.
- Removed spoiler button in Welcome Screen.
- Misspelling in debug monitor (crypto).
- Welcome screen will be now displayed only once after a major patch (eg. 0.3/0.4/0.5).
### Security
- Requires Arma version 1.40 or higher.

## [0.2.5.2] - 2014-12-03
### Added
- Started on Basic food crafting: Cooked Meat + Sweet corn + empty cooler equals full hunger; returns empty cooler.
- Crafting of Large Energy packs: 3x small energy pack + Circuit Parts and a nearby fire.
- Basic wild plant spawner: Poppy
- New dynamic event object: Ferris Wheel
- Antagonist chances moved to epochconfig.
- Split server events from weather and added separate timers for each epochconfig.
- Direction labels added to teleport pads.
- Epoch Story: Debug area is now Epoch Cloning facility.
- Started support for all "AiA Terrain Pack" maps, starting with Chernarus.
- Support for Krypto account access from classed ATM and phonebooth objects.
- New loot objects: Tarp covered pallet and freezer chest.
- Tree support for Bornholm.
- Player Krypto accounts now expire after 90 days of inactivity. Can be changed with expiresBank.
- Further enhanced DLL logging.
- Paint stripper & building parts pricing have been added to Traders.
### Changed
- Further optimized sound system.
- Optimize cleanup system for more stable server fps.
- Increased the amount of thirst gained from Drinks/Sodas.
- Increased the amount of hunger gained from Can Food and Cooked Meats.
### Fixed
- Better way to track dead state of player.
- Losing group when logging out while dead.
- Revive statistics were not persisting.
- Removed doppelganger code for now, as it was not working as intended.
- Epoch welcome message encoding issue and fixed Scroll bar.
- Parachutes should now be cleaned up.
- Bug in sound system with Cultist caused error that broke master loop.
- False publicVariable kicks that happen since the ArmA 3 update 1.36. (BattlEye Log shows PLAYER_REJECT_NoResponse)
- False script restriction kicks that happen when player destroy electric wire.

## [0.2.5.1] - 2014-09-11
### Added
- Control sound volume in-game with Ctrl plus - or +.
### Fixed
- Issue that caused admin panel to bug out and close all dialogs.

## [0.2.5.0] - 2014-11-28
### Added
- Custom single seater "Mosquito" Light helicopter.
- Consumables can now give the player multiple attributes on use.
- Honey can now be consumed and an empty jar is returned.
- Empty Food cooler added. To be used with food crafting.
- Metal Scraps added and can be found in many places as well as crafted into Salvage Metal.
- 3 new Soda cans some with unique attributes.
- Player Krypto account added. Accessed by pressing the Inventory key next to a phonebooth or an ATM. Larger the transaction the longer it takes.
- Custom Weapons: AK47, M14, m249, m107, m4a3 ported from Arma 2.
- Camo version of the female wetsuit.
- Female Ghillie Suits Tan, Light Green, Dark Green.
- SteamAPI support added for future features and VAC ban check system.
- In-game Admin Panel cleanup and features added: Spawn Menu, 3D ESP, Map ESP, Basic Admin levels.
### Changed
- Removed all "Take" and "Rearm" actions to prevent taking items from locked vehicles. A new take option will be added soon to allow item access underwater.
- Sledge Hammer damage increased 2x.
- Loot now spawns more readily.
- Loot table tweaks to increase building materials.
- setTimeMultiplier 4x enabled by default. Can be changed with timeMultiplier in epochconfig.
- Shelf, tipi, and Frequency Jammer are now built using the PhysX build mode.
- Combat Logging: Players now leave a Doppelganger behind for 60 seconds after disconnect. This can be changed or disabled in epochconfig.hpp server side.
- Death trigger now spawns shark if player is killed at sea.
- Added Override vars to epochconfig that control object expiry. vehicle, building, storage (7 days), players (30 days).
- Vehicle slots limit now based directly on total of per vehicle counts in allowed vehicles list.
- Reworked backend of NPC trader mechanism to be more accurate and optimized.
- Land vehicles now spawn in cities near roads instead of anywhere on roads.
- Many performance and security changes server side.
- Vehicle save queue system for better performance.
- Seasonal items like Meeps and Halloween masks removed from loot tables.
### Fixed
- UAV's are no longer static and now move like they are supposed to.
- Fully disabled thermal equipment for all vehicles.
- Geometry of walls changed to help reduce glitching.
- Disallow Holster and GetOver action near base walls, to reduce wall glitching.
- Global setdamage event with Communication towers.
### Security
- Reworked server configs. InstanceID is now set in EpochServer.ini and the rest in epochconfig.hpp now found in @EpochHive folder.

## [0.2.0.1] - 2014-10-29
### Added
- Added crafting of Salvage Metal from Iron Ore found at mineral veins.
- Added proper ghost models for TiPi and shelf.
### Changed
- Updated Red Gull Texture and Icon.
- Increased chance to find Mortar Buckets.
- Ctrl+T now used for Trade requests to other players.
### Fixed
- Traders spawning smoke grenades after selling them.
- Just built base objects now use player direction for initial object direction.
- Player logs out while dead will now correctly spawn fresh on login.
- Global setdamage event on powerlines.
- Traders can no longer spawn on top of each other.
- Multiple players could double spawn loot in the same building.
- Can now build Frequency Jammer properly.
- Player rollback after revive and relog.
- Many server side fixes.

## [0.2.0.0] - 2014-09-29
### Added
- Two Halloween masks Pumpkin head and Werewolf.
- Fireplace model.
- Custom Anti-Hack Framework by Skaronator.
- Replacement First Aid Kit double click on the item and use. Heals other players or your self.
- Wooden Ramp/Roof base object can be crafted with 6 lumber packs.
- Three new food items: Snooters and Meeps Candy and Walk N' Sons Soda.
- Electric Motorcycle has been added.
- Car Jack added and has a chance to be found in freshly spawned vehicles.
- New lootable furniture "Shoebox" added.
- Military variant of the bed now spawns in specific military buildings.
- Unisex vest called "side pack". All fresh spawns start with this item.
- Group request menu, Group requests can now be accessed via the "Requests" button in the inventory.
- Player trading now started with the inventory key (Default "I") and accepted with the "T" key.
- Use paint cans to paint corrugated walls and use paint thinner to remove paint.
- Wood stairs upgradable for additional landing area.
- Circuit Parts found in the world to be used for crafting.
- Lockable Cinder And Wood Doors upgrade with Circuit Parts. Ownership is controlled by frequency jammer group owner.
- 9 more radios have been added and can be crafted using gems.
- Many Inventory items now have proper icons instead of placeholder.
- Give player energy if within 75m of a solar tower or wind tower.
- Temp Lockable vehicles each time you lock a vehicle it will remain locked to you or your group for 30 minutes.
- Base building objects get deleted after 7 days. Moving the object or Painting walls extends this for 7 more days.
- Player Character are cleaned up after 30 days inactivity.
### Changed
- "T" key action moved to Inventory Button. Use your inventory key (Default "I") once to smash trash piles and again to open gear.
- Increased storage of all vests by 50% and reduced armor by half.
- Building base objects from inventory kits now instantly forces build mode and consumes item.
- P2p trading now more reliable, however now places traded items at your feet.
- Reduced Dog and snake spawn chances.
- Respawn button disabled.
- Increased Building material spawns on trash piles.
- Increased chances for Tools to spawn on Tool Rack.
- Hunger and Thirst loss rates increased.
- Increased purchase price of Ammo by a total of 100%.
- Reduced Hunter armor levels by 50%.
- Trader "Steal" option removed for now.
- Traders now only wear uniforms that spawn in the world.
### Removed
- Hellcat Helicopter and and Nightstalker scope till balance issues are sorted.
- Uniform storage space and selling of uniforms to traders removed due to dupe issues.
### Fixed
- Mineral veins now spawn at epicenters.
- Geometry changed on cinder wall to prevent phasing though it
- Lockbox can no longer be destroyed while open.
- Dump items on the ground if packed with items in lockbox.
- Overflow items to the ground if player does not have space when trading with another player.
- Added prices for Chainsaw so it is now possible to sell/buy to traders.
- It wasn't possible to snap the foundation to other foundations.
- Group Leader can no longer enter the commander vision.
- false PublicVariable Restriction on server start.
- Night Vision wasn't disabled when the player run out of energy.
- Added prices for Karts so it is now possible to sell/buy to traders.
- Shelf and Tipi storage devices are no longer indestructible and have limited storage space.
- Trader purchased vehicles should now look for a safer place to spawn vehicle within 120m.
- Text output from certain actions now show proper display names instead of classnames.
- Vehicles now persist exact position, angle, and direction so it should result in less damage at spawn.
- Some false BE kicks for base building.
### Security
- new bikey for 0.2 added remove any previous ones.
- Improved backend DLL by Fank

## [0.1.0.3] - 2014-09-25
### Added
- Whitelisting removed.
- carts DLC content added go-karts, helmets, uniforms.
- Snake bite sound.
- Gender Selection.
### Changed
- Dog brain fixes and optimizations.
- Shark brain fixes and optimizations.
- Cultist and Sapper are now looted with Inventory button instead of T.
- lowered group invite distance to only 10m.
- Removed rating and score from debug as they are not currently used.
- Lower Hunter hit point armor levels a bit in an attempt to balance.
- Lowered animal spawn rate.
### Fixed
- Sniper rifle scope attachment issues.
- Further fixes to group invite system.
- Removed leftover debug systemchat text spam from Sapper brain.
- Incorrect model for jerrycan and locker.
- Texture on wardrobe.
- NVG did not disable correctly after running out of energy.
- Reduced global variable spam from p2p trade system.
- Gumby leg bug with jump animation and crtl+w.
- Many other fixes and security changes.

## [0.1.0.2] - 2014-09-13
### Added
- New Dog Brain with many new features. http://epochmod.com/forum/index.php?/topic/17052-dog-brain-0102/
- More event driven chances to spawn antagonists.
- Great White Shark.
- Speargun found only in boats.
- NVG goggles now require Energy to use (5 Energy every 10 sec).
- Alert sound to drones when they spot you.
- AI Soldiers should now attack you even in a vehicle.
### Changed
- Suppress some group leader options by disabling use of 0-9, f1-f12, backspace, and commandmode.
- Code lockout added to Take Krypto code to prevent spam.
- Improved quality of Shipwreck and pelican loots.
- Disabled side chat on all servers, use Quartz radio instead.
- Furniture spawning moved client side for better server performance.
- Added cleanup on furniture, weaponholders, and Krypto devices every 20min if no players within 45m.
- Group System - Invite List is alphabetically sorted.
### Fixed
- Fixed typo that caused storage devices not to save correctly.
- Overhaul of vehicle selling code to prevent issues.
- incorrect scope with ItemKiloHemp.
- Fixed and improved group system.
- Double click action button text had incorrect text for some items like "Vehicle Repair Parts".
- Fixed UI icons disappearing due to conflicting resource layer with dynamic text.
- Added workaround for players not saving due to specific character in player name.
- When first building a base item it will spawn as simulated and start to save.
- Only allow owner or members of group to upgrade-in-place base objects if a Frequency jammer is placed.
- Players can now trade Krypto using P2P trade menu.
- P2P trading now correctly removes weapons from backpacks.
- AI soldiers now spawn with the correct radio, vest, and hat.
- Random traders can no longer occupy the same building.
- Preview of building objects now use proper ghost preview models.
- "Mine" trader city teleport point moved so that protection zone covers area.

## [0.1.0.1] - 2014-09-11
### Added
- Test adding mineral spawns at a 30% chance to earthquakes epicenters.
- Added spawning of semi-secure lockbox storage (shared with your group) (only owner can pack).
- Loot added to Sapper and Cultist (press "T" to loot dead body).
### Changed
- Reduced multi-gun ammo count to 10 from 99.
- Increased crafting requirements on many base items (it was kept low for testing).
- Lower chances to spawn Dogs and lowered animal spawn limit from 6 to 3.
- Shipping containers now have more loot and (building mats & backpacks).
- Removed ammo and weapons from Fridge and stove.
- Increased cultist and Sapper armor levels.
- Try to find a better place to spawn purchased vehicles.
- Player must be local (last driver) to sell a vehicle.
- Increased range for buying and selling vehicles.
- Lowered volume on Dog and Chicken sounds.
- Server side tax rate on NPC trader purchases (currently 10%).
- Manipulating base objects now have varying energy consumption.
- Disable simulation on any ThingX props at Trader cities.
### Fixed
- Incorrect path for snake corpse model.
- Fixed double chickens.
- Frequency jammer (Plot pole) now works for both owner and group members.
- Group invite system.
- Missing alert sound added to Sapper.
- fixed description for .22 Ruger.
- Check for invalid player data and revert to default (fixes some bugged players issues with joining servers).
- fixed AI cleanup on player disconnect.
