/*
	Author: Aaron Clark - EpochMod.com

    Contributors:

	Description:
	Tells server when a radio is equpped for use with custom radio channels

    Licence:
    Arma Public License Share Alike (APL-SA) - https://www.bistudio.com/community/licenses/arma-public-license-share-alike

    Github:
    https://github.com/EpochModTeam/Epoch/tree/master/Sources/epoch_code/compile/EPOCH_PutHandler.sqf
*/
private ["_femaleVariant","_vest","_class","_config","_woman","_maleVariant"];
_class = _this select 2;
//Radio Check
if (configName(inheritsFrom(configFile >> "CfgWeapons" >> _class)) == "ItemRadio") then {
	if !(_class in(assignedItems player)) then {
		//diag_log "UnEQUPPED RADIO";

		EPOCH_equippedItem_PVS = [_class,false,player];
	};
};
