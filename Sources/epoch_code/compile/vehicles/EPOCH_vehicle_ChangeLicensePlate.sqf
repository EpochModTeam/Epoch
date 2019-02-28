/*
	Author: He-Man - EpochMod.com

    Contributors:

	Description:
	change license plates from Vehicles

    Licence:
    Arma Public License Share Alike (APL-SA) - https://www.bistudio.com/community/licenses/arma-public-license-share-alike

    Github:
    https://github.com/EpochModTeam/Epoch/tree/release/Sources/epoch_code/compile/vehicles/EPOCH_vehicle_ChangeLicensePlate.sqf
*/

private ["_display","_maintxt","_txt","_bottomtxt","_savebutton"];
params ['_vehicle',['_player',player]];
if (isnull _vehicle) exitwith {};
if (_player distance _vehicle > 10) exitwith {};
if (!alive _vehicle) exitwith {};
if (!local _vehicle) exitwith {
	['Go in as driver first',5] call Epoch_Message;
};
Epoch_PlateVehicle = _vehicle;
createdialog 'EPOCH_SimpleInput';
waituntil {!isnull (finddisplay -1200)};
disableSerialization;
_display = (finddisplay -1200);
_maintxt = _display displayctrl 20;
_txt = _display displayctrl 23;
_bottomtxt = _display displayctrl 22;
_savebutton = _display displayctrl 30;
_maintxt ctrlSetText (format ['Change Licenseplate for %1',(typeof _vehicle) call Epoch_ItemDisplayName]);
_txt ctrlSetText 'New Plate:';
_savebutton buttonSetAction 'if (player distance Epoch_PlateVehicle > 10) exitwith {}; Epoch_PlateVehicle setPlateNumber (ctrlText (finddisplay -1200 displayctrl 21)); closedialog 0; Epoch_PlateVehicle call EPOCH_interact; Epoch_PlateVehicle = nil';
