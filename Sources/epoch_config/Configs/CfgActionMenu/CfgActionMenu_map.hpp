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
	condition = "dyna_mapPlayerMarkerON && 'ItemGPS' in dyna_assignedItems && !dyna_mapPlayerMarker";
	action = "['PlayerMarker',position player] call EPOCH_fnc_createLocalMarkerSet";
	icon = "x\addons\a3_epoch_community\buttons\gps.paa";
	tooltip = "Toggle ON player marker";
};
class playerMarker_off
{
	condition = "dyna_mapPlayerMarkerON && dyna_mapPlayerMarker";
	action = "['PlayerMarker'] call EPOCH_fnc_deleteLocalMarkerSet";
	icon = "x\addons\a3_epoch_community\buttons\gps.paa";
	tooltip = "Toggle OFF player marker";
};
class deathMarker_on
{
	condition = "dyna_deathMarkerON && dyna_deathMarkerAvail && !dyna_mapDeathMarker";
	action = "['DeathMarker',dyna_deathMarker] call EPOCH_fnc_createLocalMarkerSet";
	icon = "x\addons\a3_epoch_community\icons\skull.paa";
	tooltip = "Toggle ON death marker";
};
class deathMarker_off
{
	condition = "dyna_deathMarkerON && dyna_mapDeathMarker";
	action = "['DeathMarker'] call EPOCH_fnc_deleteLocalMarkerSet";
	icon = "x\addons\a3_epoch_community\icons\skull.paa";
	tooltip = "Toggle OFF death marker";
};
