/*
	Author: He-Man - EpochMod.com

    Contributors:

	Description: Adds a Slider into the inventory to put Crypto on the Ground

    Licence:
    Arma Public License Share Alike (APL-SA) - https://www.bistudio.com/community/licenses/arma-public-license-share-alike

    Github:
    https://github.com/EpochModTeam/Epoch/tree/release/Sources/epoch_code/compile/inventory/EPOCH_CryptoButtons.sqf

	Usage:
	on opened Inventory: call EPOCH_CryptoButtons

	RETURNS: NOTHING
*/


private ["_display","_ctrl_ground","_ContainerBG","_PlayerBg","_ContainerBgPos","_ctrl_groundPos","_PlayerBgPos","_KryptoButton","_border","_slider1","_KryptoText"];
_display = finddisplay 602;
_ctrl_ground = _display displayCtrl 6321;
_ContainerBG = _display displayCtrl 1001;
_PlayerBg = _display displayCtrl 1002;
_ContainerBgPos = ctrlPosition _ContainerBG; 
_ctrl_groundPos = ctrlPosition _ctrl_ground; 
_PlayerBgPos = ctrlPosition _PlayerBG; 

_KryptoButton = _display ctrlCreate['RSCButton', -1];
_KryptoButton ctrlSetPosition [
	(_PlayerBgPos select 0)+(_PlayerBgPos select 2) + (_ctrl_groundPos select 3)/2,
	(_ContainerBgPos select 1) + (_ctrl_groundPos select 3)*1.5 + (_ctrl_groundPos select 3)/2*0,
	(_ContainerBgPos select 2)/2,
	(_ctrl_groundPos select 3)*1.5
];
_KryptoButton ctrlCommit 0;
_KryptoButton ctrlSetText 'Crypto to Ground';
_KryptoButton ctrlsettextcolor [1,1,0,1];
_KryptoButton ctrlEnable true;
_KryptoButton ctrlSetEventHandler ["ButtonClick","_slider = ((finddisplay 602) displayCtrl 654001);_sliderPos = sliderPosition _slider;_value = round (epoch_playercrypto * (_sliderPos/10)); if (_value > 0 && _value <= Epoch_PlayerCrypto) then {finddisplay 602 closedisplay 0; [player,_value,Epoch_personalToken] remoteexec ['EPOCH_server_PutCrypto',2]};"];
_border = _display ctrlCreate['RscFrame', -1];
_border ctrlSetPosition [
	(_PlayerBgPos select 0)+(_PlayerBgPos select 2) + (_ctrl_groundPos select 3)/2,
	(_ContainerBgPos select 1) + (_ctrl_groundPos select 3)*1.5 + (_ctrl_groundPos select 3)/2*0,
	(_ContainerBgPos select 2)/2,
	(_ctrl_groundPos select 3)*1.5
];
_border ctrlCommit 0;

_slider1 = _display ctrlCreate['RscXSliderH', 654001];
_slider1 ctrlSetPosition [
	(_PlayerBgPos select 0)+(_PlayerBgPos select 2) + (_ctrl_groundPos select 3)/2,
	(_ContainerBgPos select 1) + (_ctrl_groundPos select 3)*1.5*2,
	(_ContainerBgPos select 2)/2,
	(_ctrl_groundPos select 3)*0.75
];
_slider1 ctrlCommit 0;

_KryptoText = _display ctrlCreate['RSCText', 654002];
_KryptoText ctrlSetPosition [
	(_PlayerBgPos select 0)+(_PlayerBgPos select 2) + (_ctrl_groundPos select 3)/2,
	(_ContainerBgPos select 1) + (_ctrl_groundPos select 3)*1.5*2 + (_ctrl_groundPos select 3)*0.75,
	(_ContainerBgPos select 2)/2,
	(_ctrl_groundPos select 3)*0.75
];
_KryptoText ctrlSetBackgroundColor [0,0,0,1];

[] spawn {
	disableSerialization;
	_display = finddisplay 602;
	_slider1 = (_display displayCtrl 654001);
	_KryptoText = (_display displayCtrl 654002);
	_slider1 sliderSetPosition 0;
	while {!isNull _display} do {
		_sliderPos = sliderPosition _slider1;
		_value = round (epoch_playercrypto * (_sliderPos/10));
		_KryptoText ctrlSetText format['Put %1 Crypto',_value];
		_KryptoText ctrlCommit 0;
		uiSleep 0.1;
	};
};
