/*
	Author: Niklas Wagner - EpochMod.com

    Contributors:

	Description:
	Update loading screen message

    Licence:
    Arma Public License Share Alike (APL-SA) - https://www.bistudio.com/community/licenses/arma-public-license-share-alike

    Github:
    https://github.com/EpochModTeam/Epoch/tree/master/Sources/epoch_code/compile/EPOCH_updateLoadingScreen.sqf
*/
disableSerialization;
private ["_display"];
_display = uiNameSpace getVariable ["EPOCH_loadingScreen",displayNull];
if (!isNull _display) then {
  (_display displayCtrl 50) ctrlSetText _this;
};
