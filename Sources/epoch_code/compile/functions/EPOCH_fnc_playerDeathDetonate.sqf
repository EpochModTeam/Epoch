/*
	Author: Andrew Gregory - EpochMod.com

    Contributors:

	Description:
	Detonate player body.

    Licence:
    Arma Public License Share Alike (APL-SA) - https://www.bistudio.com/community/licenses/arma-public-license-share-alike

    Github:
    https://github.com/EpochModTeam/Epoch/tree/release/Sources/epoch_code/compile/functions/EPOCH_fnc_playerDeathDetonate.sqf

    Example:
    [] call EPOCH_fnc_playerDeathDetonate;

    Parameter(s):

	Returns:
	BOOM
*/
openmap [false,false];
closeDialog 2;
[] spawn{
	// todo: add paricle effect here.

	// random delay of up to 30 seconds,
	uisleep (random 25) + 5;

	[player, Epoch_personalToken] remoteExec ["EPOCH_server_deadPlayerDetonate",2];
	deleteVehicle player;
	player setVariable ["doneBoom", true];

	while {!alive player} do {
	//Handle clean up
		if(player getVariable["doneBoom",false])exitWith{player setVariable ["doneBoom",nil]; uiSleep 5; (findDisplay 46) closeDisplay 0;};
		uiSleep 0.1;
	};
};
