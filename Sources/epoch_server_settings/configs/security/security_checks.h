/*
	Author: Aaron Clark - EpochMod.com

    Contributors:

	Description:
	Epoch Server side securty checks config

    Licence:
    Arma Public License Share Alike (APL-SA) - https://www.bistudio.com/community/licenses/arma-public-license-share-alike

    Github:
    https://github.com/EpochModTeam/Epoch/tree/master/Sources/epoch_server_settngs/configs/securty/security_checks.h
*/
class CfgSecConf
{
    debug = false;

    class limits {
        playerCrypto = 25000;
    };

    class learning {
        mode = false; // true = only trust uids below, false = trust everyone (use only with a passworded server and trusted players)
        trustedUsers[] = {};
    };

    class blacklist {
        badDisplays[] = {-1337,17,19,30,32,45,59,69,71,125,132,155,156,157,162,165,166,167,312,1320,1321,2727,2928,2929,316000};
        animations[] = {"AmovPercMstpSnonWnonDnon_exerciseKata","AmovPercMstpSnonWnonDnon_exercisePushup","GestureSpasm1","GestureSpasm4","GestureNod"};
    };

    class forcedQuality {
        // Configs for forced viewdistances via AH matching A3 presets
        class Standard
        {
            viewDistance = 1600; // Standard Preset = 1600
            viewDistanceObects = 1300; // Standard Preset = 1300
            terrainGrid = 10; // Standard Preset = 25
        };
        class High
        {
            viewDistance = 2200; // High Preset = 2200
            viewDistanceObects = 1800; // High Preset = 1800
			terrainGrid = 10; // High Preset = 12.5
        };
        class VeryHigh
        {
            viewDistance = 3000; // Very High Preset = 3000
            viewDistanceObects = 2600; // Very High Preset = 2600
			terrainGrid = 10; // Very High Preset = 6.25
        };
        class Ultra
        {
            viewDistance = 3800; // Ultra Preset = 3800
            viewDistanceObects = 3200; // Ultra Preset = 3200
			terrainGrid = 10; // Ultra Preset = 3.125
        };
        class Custom
        {
            viewDistance = 2500; // High+
            viewDistanceObects = 2000; // High+
			terrainGrid = 10; // Default in MP: 10
        };
        mode = "Standard";
    };

    class displayAddEventHandler {
        keyDown = "_this call EPOCH_KeyDown;";
        keyUp   = "_this call EPOCH_KeyUp;";
    };

    class addEventHandler {
        checks[] = {"Fired","InventoryClosed","InventoryOpened","Killed","HandleDamage","HandleHeal","Dammaged","Hit","HitPart"};
        Fired           = "_this call EPOCH_fnc_playerFired;";
        InventoryClosed = "if !(EPOCH_arr_interactedObjs isEqualTo[]) then {EPOCH_arr_interactedObjs remoteExec['EPOCH_server_save_vehicles', 2]; EPOCH_arr_interactedObjs = [];};";
        InventoryOpened = "_this spawn EPOCH_initUI;_container = _this select 1;_lockedNear = false;if (_container isKindOf 'GroundWeaponHolder' || _container isKindOf 'WeaponHolderSimulated') then {{if (locked _x in [2, 3] ||_x getVariable['EPOCH_Locked', false]) exitWith {_lockedNear = true}} forEach (player nearSupplies 10);};if (locked _container in [2, 3] || _container getVariable['EPOCH_Locked', false] || _lockedNear) then {[] spawn {disableSerialization;waitUntil {!isNull findDisplay 602};_display = findDisplay 602;_ctrl_cargo = _display displayCtrl 6401;_ctrl_ground = _display displayCtrl 6321;_ctrl_cargo ctrlEnable  false;ctrlSetFocus _ctrl_ground;ctrlActivate _ctrl_ground;};};";
        Killed          = "_this call EPOCH_fnc_playerDeath;";
        HandleDamage    = "";
        HandleHeal      = "";
        Dammaged        = "";
        Hit             = "";
        HitPart         = "";
    };

    class variables {
        class whitelist {
            #include "data\custom_vars.h" // whitelisted variables
        };
        badVars[] = {"ESP_map","ESP_mainMap","ESP_adminMap","AntiAntiAntiAntiHax","fnc_usec_damageHandler","fnc_usec_unconscious","VAGINA_secret","yolo","VERSION","life_fnc_handleDamage","EPOCH_spawnVehicle_PVS","CLASS911_Menu","nuke_vars","JJMMEE_INIT_MENU","PLAYERON","PLAYERNEXT2","ALTISLIFEON","LY_Menu","PLAY","LY_SwaggerLikeUs","BIS_fnc_dbg_reminder_value","BIS_fnc_dbg_reminder"};
        nilVars[] = {"EPOCH_antiWallCount","EPOCH_playerEnergy","EPOCH_playerHunger","EPOCH_playerStamina","EPOCH_playerCrypto","EPOCH_target","EPOCH_ESP_TARGETS","EPOCH_ESPMAP_TARGETS","EPOCH_taxRate","EPOCH_ESP_VEHICLEPLAYER","EPOCH_ESP_PLAYER","EPOCH_ESP_VEHICLES"};
    };

    class commandMenu {
        menus[] = {"","RscSelectTeam","RscTeam","RscMoveHigh","#GETIN","#RscStatus","#WATCH0","RscCombatMode","RscMenuReply","RscCallSupport","#CUSTOM_RADIO","#User:BIS_fnc_addCommMenuItem_menu","RscRadio","RscReply","#ACTION","RscMenuFormations","#WATCH","RscGroupRootMenu","RscMainMenu","RscMenuMove","RscWatchDir","RscWatchMoveDir","#User:BIS_Menu_GroupCommunication","RscMenuStatus","RscFormations"};
    };

    // RscDisplay (onload, unload) scanning is automatic and will ensure data matches the server.
    // Using the extra whitelist arrays this check can be extended to allow modifications client side that do not exist server side.
    class displayOnload {
        // Format: {rscDisplayConfigname, extra whitelisted onload data (array of string), extra whitelisted unload data (array of string)}
        // The extra onload whitelist for RscDisplayConfigure is for CBA
        checkDisplays[] = {
            {"RscDisplayMainMap", {}, {}},
            {"RscDisplayGetReady", {}, {}},
            {"RscDisplayInventory", {}, {}},
            {"RscDisplayLoadMission", {}, {}},
            {"RscDisplayInterrupt", {}, {}},
            {"RscDisplayOptionsVideo", {}, {}},
            {"RscDisplayOptions", {}, {}},
            {"RscDisplayAVTerminal", {}, {}},
            {"RscDisplayConfigure", {"{""onLoad"",_this,""RscDisplayConfigure"",'GUI'} call compile preprocessfilelinenumbers ""A3\ui_f\scripts\initDisplay.sqf""; _this call compile preprocessfilelinenumbers ""\x\cba\addons\keybinding\gui\initDisplay.sqf"""}, {}},
            {"RscDisplayConfigureAction", {}, {}},
            {"RscDisplayConfigureControllers", {}, {}},
            {"RscDisplayControlSchemes", {}, {}},
            {"RscDisplayCustomizeController", {}, {}},
            {"RscDisplayDebriefing", {}, {}},
            {"RscDisplayDiary", {}, {}},
            {"RscDisplayGameOptions", {}, {}},
            {"RscDisplayJoystickSchemes", {}, {}},
            {"RscDisplayLoading", {}, {}},
            {"RscDisplayMicSensitivityOptions", {}, {}},
            {"RscDisplayOptionsAudio", {}, {}},
            {"RscDisplayOptionsLayout", {}, {}},
            {"RscDisplayStart", {}, {}},
            {"RscDisplayVehicleMsgBox", {}, {}},
            {"RscDisplayInsertMarker", {}, {}}
        };
    };

	class DebugActive
    {
        systemChat1 = "systemChat str _type;";
        systemChat2 = "systemChat format['SPAWN %1',_spawn];";
        systemChat3 = "systemChat format['Debug-Vehicle: send: 108,%1', _veh];";
        systemChat4 = "systemChat format['Debug-Vehicle: _veh: %1', _veh];";
        systemChat5 = "systemChat format['Debug-Vehicle: _this: %1', _this];";
    };
};
