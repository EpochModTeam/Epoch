/*
	Author: Aaron Clark - EpochMod.com

    Contributors:

	Description:
	Player Check

    Licence:
    Arma Public License Share Alike (APL-SA) - https://www.bistudio.com/community/licenses/arma-public-license-share-alike

    Github:
    https://github.com/EpochModTeam/Epoch/tree/release/Sources/epoch_server/compile/epoch_player/EPOCH_server_checkPlayer.sqf
*/
//[[[cog import generate_private_arrays ]]]
private ["_apperance","_arr","_class","_communityStatsArray","_dead","_deadPlayer","_defaultData","_instanceID","_isMale","_medical","_playerUID","_response","_return","_vars"];
//[[[end]]]
params [["_playerObj",objNull]];
if (_playerObj isEqualType objNull) then {
	if (!isNull _playerObj) then {
		_playerUID = getPlayerUID _playerObj;
		if (_playerUID != "") then {

			_response = ["Player", _playerUID] call EPOCH_fnc_server_hiveGETRANGE;

			_dead = false;
			_isMale = true;

			_instanceID = call EPOCH_fn_InstanceID;
			_class = "Epoch_Female_F";

			_arr = [];
			if ((_response select 0) == 1 && (_response select 1) isEqualType []) then {
				_arr = (_response select 1);
			};

			// empty default data format, if "Player" data format is changed update this array!
			_defaultData = [[], [], [], [], [], [], [], [], [], [], "", true];

			// If data does not validate against default or is too short, assume player is new or already dead.
			if !(_arr isEqualTypeParams _defaultData) then {
				_dead = true;
			} else {
				_medical = _arr select 1;
				_apperance = _arr select 2;
				_class = _apperance select 5;
				if (_class == "Epoch_Female_F") then {
					_isMale = false;
				};
				_vars = _arr select 4;
				_medical params ["","","","_damage",["_hitpoints",[0,0,0,0,0,0,0,0,0,0,0]] ];
				_deadPlayer = ["PlayerStats", _playerUID, 0] call EPOCH_fnc_server_hiveGETBIT;
				// check if player is already dead or was critically hit HitHead = 2 or HitBody = 7 and if blood pressure too high.
				if (_deadPlayer || (_damage == 1) || (_hitpoints select 2 == 1) || (_hitpoints select 7 == 1) || (_vars select 12 >= 180)) then {
					_dead = true;
				};
			};

			// check status of community stats to prevent load / save issues
			_communityStatsArray = ["CommunityStats", _playerUID] call EPOCH_fnc_server_hiveGETRANGE;
			if((_communityStatsArray select 1) isEqualTo []) then{
				_return = ["CommunityStats", _playerUID, EPOCH_expiresCommunityStats, [EPOCH_defaultStatVars]] call EPOCH_fnc_server_hiveSETEX;
			};

			/* true => New Char
			   false => load old Char */
			['_checkPlayer_PVC', _dead] remoteExec ['EPOCH_playerLoginInit',_playerObj];

			if (!_dead) then { //Load old Char
				[_playerObj, _isMale] call EPOCH_server_loadPlayer;
			};
		};
	};
};
