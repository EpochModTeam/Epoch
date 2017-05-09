/*
	Author: Aaron Clark - EpochMod.com

    Contributors:

	Description:
	Radio Channel handler

    Licence:
    Arma Public License Share Alike (APL-SA) - https://www.bistudio.com/community/licenses/arma-public-license-share-alike

    Github:
    https://github.com/EpochModTeam/Epoch/tree/release/Sources/epoch_server/compile/epoch_player/EPOCH_server_equippedItem.sqf
*/
//[[[cog import generate_private_arrays ]]]
private ["_channelID","_config","_selectedChannel"];
//[[[end]]]
params ["_class","_status","_player"];

_selectedChannel = EPOCH_customChannels select 0;
_config = (configfile >> "CfgWeapons" >> _class);
if (isClass(_config)) then {
	_channelID = getNumber(_config >> "channelID");
	_selectedChannel = EPOCH_customChannels select _channelID;
};

if (_status) then {
	{_x radioChannelRemove[_player];} ForEach EPOCH_customChannels;
	_selectedChannel radioChannelAdd[_player];
} else {
	{_x radioChannelRemove[_player];} ForEach EPOCH_customChannels;
};
