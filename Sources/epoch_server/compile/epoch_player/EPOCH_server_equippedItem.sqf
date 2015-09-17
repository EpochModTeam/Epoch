/*
Radio handeler

Epoch Mod - EpochMod.com
All Rights Reserved.
*/
private["_channelID", "_selectedChannel", "_class", "_status", "_plyr"];

_class = _this select 0;
_status = _this select 1;
_plyr = _this select 2;

_selectedChannel = EPOCH_customChannels select 0;

if (isClass(configfile >> "CfgWeapons" >> _class)) then {
	_channelID = getNumber(configfile >> "CfgWeapons" >> _class >> "channelID");
	_selectedChannel = EPOCH_customChannels select _channelID;
};

if (_status) then {
	{_x radioChannelRemove[_plyr];} ForEach EPOCH_customChannels;
	_selectedChannel radioChannelAdd[_plyr];
} else {
	{_x radioChannelRemove[_plyr];} ForEach EPOCH_customChannels;
};