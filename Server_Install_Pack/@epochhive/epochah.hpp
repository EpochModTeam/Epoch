// Anti Hack
antihack_Enabled = "true"; // built-in Anti-Hack
antihack_maxTravelDistance = 30; // anti-teleport max travel distance
antihack_TPcenterDistance = 30; // anti-teleport distance from start
antihack_cfgPatchesCheck = "true"; // cfgPatches (AddOn Check)
antihack_PVSPrefix = "EPAH_"; // used to help whitelist pveh variables in BE without BEC and watchdog, leave blank to use no prefix.
antihack_cfgPatchesMode[] = {2}; // 0 == BAN - 1 = LOG, 2 = KICK
antihack_ahInitAuthCfg[] = {0,180}; // 0 == BAN - 1 = LOG, 60 = ban or log if anti hack is not started in 180 seconds
antihack_whitelistedCfgPatches[] = {}; //
antihack_banReason = "EpochMod Autoban";
antihack_kickReason = "EpochMod Autokick";
antihack_banReasons[] = {
	"Mod mismatch, check that the mods you have enabled match server."
};
antihack_banDuration = 5; // Default 5 minute ban. -1 = permanent ban.
antihack_kickReasons[] = {
	"Mod mismatch, check that the mods you have enabled match server."
};
antihack_checkFiles[] = { //script check, leave it blank to disable it
	{"epoch_code\compile\setup\EPOCH_clientInit.sqf", "EPOCH_clientInit"},
	{"epoch_code\compile\EPOCH_onEachFrame.sqf", "EPOCH_onEachFrame"},
	{"epoch_code\compile\setup\EPOCH_masterLoop.sqf", "EPOCH_masterLoop"},
	{"epoch_code\compile\setup\EPOCH_client_rejectPlayer.sqf", "EPOCH_client_rejectPlayer"},
	{"epoch_code\compile\setup\EPOCH_clientRespawn.sqf", "EPOCH_clientRespawn"},
	{"epoch_code\compile\interface_event_handlers\EPOCH_KeyDown.sqf", "EPOCH_KeyDown"}
};
antihack_addActionCheck = "true"; // false to disable addAction checks
adminMenu_Owner[] = {};
adminMenu_OwnerSetting[] = {
	"ESP-PLAYER",
	"ESP-VEHICLE",
	"ESP-LOOT",
	//"OLD-ESP",
	//"OLD-MAP",
	"PLAYER-TELEPORT",
	"MAP-TELEPORT",
	"INFRONT-TELEPORT",
	"MAP-PLAYER",
	"MAP-CORPSE",
	// "MAP-LOOT",
	"MAP-VEHICLE",
	"MAP-AI",
	// "MAP-BASEBUILDING",
	"TARGET-HEAL",
	"TARGET-AMMO",
	"TARGET-KILL",
	"TARGET-CRYPTO",
	"TARGET-VEHICLEREPAIR",
	"VEHICLEFLIP",
	"BANPANNEL",
	"SPAWN-MENU",
	"FREE-CAM",
	"INVISIBLE",
	// "SPAWNLOOT",
	"GODMODE",
	"HEAL",
	"VEHICLEREPAIR"
};

adminMenu_High[] = {};
adminMenu_HighSetting[] = {"PLAYER-TELEPORT","MAP-TELEPORT","TARGET-HEAL","TARGET-AMMO","TARGET-KILL","VEHICLEFLIP","BANPANNEL"};

adminMenu_Low[] = {};
adminMenu_LowSetting[] = {"PLAYER-TELEPORT","MAP-TELEPORT","TARGET-HEAL"};

adminMenu_BanReasons[] = {"Traderzone","Hacking","Glitch","Combat Log"};
adminMenu_cryptoCfg[] = {2500,1000,500,100,50,-1000};
//You can find the Key Codes here: https://community.bistudio.com/wiki/DIK_KeyCodes#F1..15
adminMenu_menuKey = 0x3B;
adminMenu_infrontTeleport = 0x06;

/*
AH CONFIG README

adminMenu_Owner[] = {
	{"STEAMID64","ADMINNAME1"},
	{"STEAMID64","ADMINNAME2"},
	{"STEAMID64","ADMINNAME3"} //<- No comma on the last entry
};
adminMenu_High[] = {
	{"STEAMID64","ADMINNAME4"},
	{"STEAMID64","ADMINNAME5"},
	{"STEAMID64","ADMINNAME6"} //<- No comma on the last entry
};
adminMenu_Low[] = {
	{"STEAMID64","ADMINNAME7"},
	{"STEAMID64","ADMINNAME8"},
	{"STEAMID64","ADMINNAME9"} //<- No comma on the last entry
};

ADMINNAME will be used for the Admin log instead of in-game name.

Available Settings:
"PLAYER-TELEPORT" => Teleport Admin To Player and Player To Admin
"MAP-TELEPORT" => Click on Map to Teleport
"INFRONT-TELEPORT" => Teleport you infront
"FREE-CAM" => Free flying Cam
"INVISIBLE" => Make Playermodel invisible but other player can still hear your steps

"GODMODE" => Godmode for yourself which heal you as well
"HEAL" => Heal yourself
"VEHICLEREPAIR" => Repeair the vehicle you're looking on, or be inside

"MAP-PLAYER" => Player Marker
"MAP-CORPSE" => Corpse (Dead Player etc.) Marker
"MAP-LOOT" => Loot Marker
"MAP-VEHICLE" => Vehicle Marker
"MAP-AI" => AI Marker
"MAP-BASEBUILDING" => Base Building Marker

"ESP-PLAYER" => 3D ESP for Player
"ESP-VEHICLE" => 3D ESP for Vehicles
"ESP-LOOT" => 3D ESP for Loot Objects


"OLD-ESP" => Old 3D ESP
"OLD-MAP" => Old Map Marker

"TARGET-CRYPTO" => Give crypto to target
"TARGET-HEAL" => Heal Target
"TARGET-AMMO" => Give Target Ammo
"TARGET-KILL" => Kill Target
"TARGET-VEHICLEREPAIR" => Repair the Vehicle if target is inside of a vehicle

"VEHICLEFLIP" => Flip Vehicle
"BANPANNEL" => Access to Banpannel
"SPAWNLOOT" => Spawn Loot in Buildings (within 25m)

"SPAWN-MENU" => Access to Spawn Menu

*/
