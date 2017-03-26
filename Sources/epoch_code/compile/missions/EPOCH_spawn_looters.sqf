/*
	Author: Andrew Gregory - EpochMod.com

    Contributors:

	Description:
	Spawn looters (unused)

    Licence:
    Arma Public License Share Alike (APL-SA) - https://www.bistudio.com/community/licenses/arma-public-license-share-alike

    Github:
    https://github.com/EpochModTeam/Epoch/tree/release/Sources/epoch_code/compile/missions/EPOCH_spawn_looters.sqf
*/
//[[[cog import generate_private_arrays ]]]
private ["_unit"];
//[[[end]]]
for "_i" from 0 to 4 step 1 do {
	_unit =  createGroup [RESISTANCE, true] createUnit ["Epoch_Female_F", getPos player, [], 400, "CAN_COLLIDE"];
	_unit addBackPack "B_FieldPack_blk";
	_unit addWeapon "Hatchet";
	_unit addMagazine "hatchet_swing";
	{_unit disableAI _x}count["TARGET","AUTOTARGET","FSM"];
	_unit addEventHandler ["FiredNear", "_this select 0 setVariable [""firedNear"",_this select 2]"];
	_unit addEventHandler ["Hit", "_this select 0 setVariable [""looterHit"",true];"]; //setDamage on the client && on Epoch_Female_F !? Not required ! Part of keeping health up on antagonists without custom armour !
	[_unit] execFSM "\x\addons\a3_epoch_code\System\Looter_Brain.fsm";
};
