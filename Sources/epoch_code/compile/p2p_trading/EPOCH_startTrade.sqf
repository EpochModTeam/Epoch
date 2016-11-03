/*
	Author: Aaron Clark - EpochMod.com

    Contributors:

	Description:
	P2P trade start

    Licence:
    Arma Public License Share Alike (APL-SA) - https://www.bistudio.com/community/licenses/arma-public-license-share-alike

    Github:
    https://github.com/EpochModTeam/Epoch/tree/release/Sources/epoch_code/compile/p2p_trading/EPOCH_startTrade.sqf
*/
//[[[cog import generate_private_arrays ]]]
private ["_index"];
//[[[end]]]
closeDialog 0;
if !(createdialog "Trade") exitWith {};

9992 cutRsc["EpochGameUI2", "PLAIN", 2, false];
((uiNamespace getVariable "EPOCH_EpochGameUI2") displayCtrl 21208) ctrlSetText format["%1", EPOCH_playerCrypto];

{lbAdd[2100,_x]} forEach ["All","Magazines","Items"];
// {lbAdd[2100, _x]} forEach["All", "Weapons", "Magazines", "Items"];
{
	if (getNumber(configfile >> "CfgMagazines" >> _x >> "count") == 1) then {
		_index = lbAdd [1500, _x call EPOCH_itemDisplayName];
		lbSetData [1500, _index, _x];
		lbSetPicture [1500, _index, _x call EPOCH_itemPicture];
	};
}forEach magazines player;
/*
{
	_index = lbAdd [1500, _x call EPOCH_itemDisplayName];
	lbSetData [1500, _index, _x];
	lbSetPicture [1500, _index, _x call EPOCH_itemPicture];
}forEach weapons player;
*/
{
	_index = lbAdd [1500, _x call EPOCH_itemDisplayName];
	lbSetData [1500, _index, _x];
	lbSetPicture [1500, _index, _x call EPOCH_itemPicture];
}forEach items player;
player setVariable ["Accept", false, true];
EPOCH_tradeDone = false;
