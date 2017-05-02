/*
	Author: Andrew Gregory - EpochMod.com

    Contributors:

	Description:
	TBA construct (unused)

    Licence:
    Arma Public License Share Alike (APL-SA) - https://www.bistudio.com/community/licenses/arma-public-license-share-alike

    Github:
    https://github.com/EpochModTeam/Epoch/tree/release/Sources/epoch_code/compile/missions/EPOCH_spawn_construct.sqf
*/
private _unit = createAgent ["Construct_F", getPos player, [], 520, "FORM"];
{_unit disableAI _x}forEach["TARGET","AUTOTARGET","FSM"];
[_unit] execFSM "\x\addons\a3_epoch_code\System\Construct_Brain.fsm";
