_this spawn {
	params ["_Building","_Vehicle",["_Textures",[]]];
	_PaintingCosts = getnumber (missionconfigfile >> "CfgPainting" >> (typeof _Vehicle) >> "PaintingCosts");
	if (EPOCH_playerCrypto < _PaintingCosts) exitWith {
		_line = format ['You need %1 Crypto for Painting', _PaintingCosts];
		[_line,5] call Epoch_message;
	};
	_ok = true;
	_Check1 = {
		_out1 = true;
		if (_Vehicle distance2D _Building > 2.5) exitwith {
			["Park in center of the Garage",5] call Epoch_Message;
			false
		};
		if !((crew _Vehicle) isEqualTo []) exitwith {
			["All passengers have to leave the Vehicle",5] call Epoch_Message;
			false
		};
		{
			_playerPosASL = visiblePositionASL _x;
			_abovePlayerPosASL = [_playerPosASL select 0,_playerPosASL select 1,(_playerPosASL select 2) + 15];
			if (lineIntersects [_playerPosASL, _abovePlayerPosASL, _x]) exitwith {
				["All Players have to leave the Garage",5] call Epoch_Message;
				_out1 = false;
			};	
		} foreach (_Building nearentities ["MAN",(sizeof (typeof _Building))/2]);
		_out1
	};
	_DoorCheck = {
		(_building animationPhase "Lroll_door") < 0.1
	};
	_Animate = {
		_Building animate ["Lroll_door",_this];
		_Building animate ["Uroll_door",_this];
		_Building animate ["door_2",if (_this == 1) then {0} else {1}];
	};
	if !(call _Check1) exitwith {};
	0 call _Animate;
	waituntil {uisleep 0.2; !(call _Check1) || call _DoorCheck};
	if !(call _DoorCheck) exitwith {};
	_smokes = [];
	_smokeclasses = ["SmokeShellOrange","SmokeShellBlue","SmokeShellPurple","SmokeShellRed","SmokeShellGreen","SmokeShellYellow"];
	for "_i" from 0 to 5 do {
		_pos = switch _i do {
			case 0: {[-1.5,2,-0.35]};
			case 1: {[1.5,2,-0.35]};
			case 2: {[-1.5,-2,-0.35]};
			case 3: {[1.5,-2,-0.35]};
			case 4: {[0,0,-0.35]};
			default {[0,0,0]};
		};
		if !(call _DoorCheck) exitwith {};
		_smoke = (_smokeclasses deleteat 0) createVehicle getPosATL _Vehicle;
		_smoke attachTo [_Vehicle,_pos];
		_smokes pushback _smoke;
		uisleep 3.5;
	};
	if !(call _DoorCheck) exitwith {
		["Painting Abort - Someone has opened the Door",5] call Epoch_Message;
		{
			deletevehicle _x;
		} foreach _smokes;
		1 call _Animate;
	};
	if !(_Textures isEqualTo []) then {
		[_vehicle,_PaintingCosts,_Textures,player,Epoch_personalToken] remoteexec ['epoch_server_paintvehicle',2];
	};
	{
		deletevehicle _x;
	} foreach _smokes;
	uisleep 5;
	["Painting finished! Thank you very much...",5] call Epoch_Message;
	1 call _Animate;
};
