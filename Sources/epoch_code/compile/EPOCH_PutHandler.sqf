private ["_femaleVariant","_vest","_class","_config","_woman","_maleVariant"];
_class = _this select 2;
//Radio Check
if (configName(inheritsFrom(configFile >> "CfgWeapons" >> _class)) == "ItemRadio") then {
	if !(_class in(assignedItems player)) then {
		//diag_log "UnEQUPPED RADIO";

		EPOCH_equippedItem_PVS = [_class,false,player];
	};
};