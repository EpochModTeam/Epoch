/*
	Author: Raimonds Virtoss - EpochMod.com

    Contributors: DirtySanchez

	Description:
	Action Menu Map Config

    Licence:
    Arma Public License Share Alike (APL-SA) - https://www.bistudio.com/community/licenses/arma-public-license-share-alike

    Github:
    https://github.com/EpochModTeam/Epoch/tree/release/Sources/epoch_config/Configs/CfgActionMenu/CfgActionMenu_map.hpp
*/

class playerMarker_on
{
	condition = "!EPOCH_PlayerMarkerOn";
	action = "EPOCH_PlayerMarkerOn = true; if !('ItemGPS' in dyna_assignedItems) then {['You need a GPS to see your Position',5] call epoch_message}";
	icon = "x\addons\a3_epoch_community\buttons\gps.paa";
	tooltip = "Toggle ON player marker";
};
class playerMarker_off
{
	condition = "EPOCH_PlayerMarkerOn";
	action = "EPOCH_PlayerMarkerOn = false";
	icon = "x\addons\a3_epoch_community\buttons\gps.paa";
	tooltip = "Toggle OFF player marker";
};
class deathMarker_on
{
	condition = "!EPOCH_DeathMarkerOn";
	action = "EPOCH_DeathMarkerOn = true; if ((profileNameSpace getVariable ['EPOCHLastKnownDeath',[]]) isequalto []) then {['You had no GPS on last death',5] call epoch_message}";
	icon = "x\addons\a3_epoch_community\icons\skull.paa";
	tooltip = "Toggle ON death marker";
};
class deathMarker_off
{
	condition = "EPOCH_DeathMarkerOn";
	action = "EPOCH_DeathMarkerOn = false";
	icon = "x\addons\a3_epoch_community\icons\skull.paa";
	tooltip = "Toggle OFF death marker";
};
