/*
	Author: [Ignatz] He-Man

    Contributors:

	Description:
	Autorun script

    Licence:
    Arma Public License Share Alike (APL-SA) - https://www.bistudio.com/community/licenses/arma-public-license-share-alike

    Github:
    https://github.com/EpochModTeam/Epoch/tree/release/Sources/epoch_code/compile/EPOCH_AutoRun.sqf
*/

private ["_myheight","_nextpos","_newheight"];

// _EPOCH_Autorunspeed is NOT a private variable, it is defined in Masterloop init!

_myheight = (getposasl player) select 2;
_nextpos = player modelToWorld [0,1,0];
_nextpos set [2,0];
_newheight = (atltoasl _nextpos) select 2;
if (surfaceiswater position player || ((getposatl player) select 2) > 0.5) then {
	_newheight = _myheight;		
};
if (_myheight-_newheight > 0.8 || _myheight-_newheight < -0.6) then {
	if (_EPOCH_Autorunspeed != 1) then {
		player playActionnow 'PlayerWalkF';
	}
	else {
		player playAction 'PlayerWalkF';
	};
	_EPOCH_Autorunspeed = 1;
}
else {
	if (_myheight-_newheight > 0.5 || _myheight-_newheight < -0.35) then {
		if (_EPOCH_Autorunspeed != 2) then {
			player playActionnow 'PlayerSlowF';
		}
		else {
			player playAction 'PlayerSlowF';
		};
		_EPOCH_Autorunspeed = 2;
	}
	else {
		if (getFatigue player < 0.8) then {
			if (_EPOCH_Autorunspeed != 3) then {
				player playActionnow 'FastF';
			}
			else {
				player playAction 'FastF';
			};
			_EPOCH_Autorunspeed = 3;
		}
		else {
			if (_EPOCH_Autorunspeed != 2) then {
				player playActionnow 'PlayerSlowF';
			}
			else {
				player playAction 'PlayerSlowF';
			};
			_EPOCH_Autorunspeed = 2;
		};
	};
};
