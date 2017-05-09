/*
	Author: Aaron Clark - EpochMod.com

    Contributors:

	Description:
    Handle set damage on sapper bombs sderver side

    Licence:
    Arma Public License Share Alike (APL-SA) - https://www.bistudio.com/community/licenses/arma-public-license-share-alike

    Github:
    https://github.com/EpochModTeam/Epoch/tree/release/Sources/epoch_server/compile/epoch_antagonists/EPOCH_server_handle_sapperObjs.sqf
*/
//[[[cog import generate_private_arrays ]]]
private ["_safeBombs","_safeUnits"];
//[[[end]]]
params [["_bomb",objNull], "_player", ["_token","",[""]], "_unit", ["_killUnit",false]];
if !([_player,_token]call EPOCH_server_getPToken)exitWith{};
_safeUnits = ["Epoch_Sapper_F","Epoch_SapperB_F","Epoch_SapperG_F"];
_safeBombs = ["Sapper_Charge_Ammo","SapperB_Charge_Ammo","SmokeShellToxicSapper"];
if!(isNull _bomb)then{
    if(typeOf _bomb in _safeBombs) then {
        _bomb setDamage 1;
    };
};
if(_killUnit && {!isNull _unit})then{
    if(typeOf _unit in _safeUnits) then {
        _unit setDamage 1;
    };
};
