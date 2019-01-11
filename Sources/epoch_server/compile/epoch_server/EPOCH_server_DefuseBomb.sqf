/*
	Author: He-Man - EpochMod.com

    Contributors:

	Description:
	Defuse server side bombs (triggerd by Clients)

    Licence:
    Arma Public License Share Alike (APL-SA) - https://www.bistudio.com/community/licenses/arma-public-license-share-alike

    Github:
    https://github.com/EpochModTeam/Epoch/tree/release/Sources/epoch_server/compile/epoch_server/EPOCH_server_Defusebomb.sqf

    Example:
    [_bomb,true,player,Epoch_personalToken] remoteexec ["EPOCH_server_DefuseBomb",2];

	Returns:
	NOTHING
*/

params [
    ["_object",objNull,[objNull]],
    ["_value",true,[true]],
    ["_player",objNull,[objNull]],
    ["_token","",[""]]
];
if (isNull _object) exitWith{};
if !([_player,  _token] call EPOCH_server_getPToken) exitWith{};
if (_player distance _object > 20) exitWith{};
if (_value) then {
    'HelicopterExploSmall' createVehicle (position _object);
    deletevehicle _object;
}
else {
    deletevehicle _object;
    _reward = gettext (configfile >> "cfgammo" >> (typeof _object) >> "defaultMagazine");
    if !(_reward isequalto "") then {
        _reward remoteexec ["EPOCH_fnc_addItemOverflow",_player];
        [format ['Sucessfully defused %1 - You have it now in your Inventory',_reward call Epoch_fnc_Itemdisplayname],5] remoteexec ["Epoch_Message",_player];
    };
};