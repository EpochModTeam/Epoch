/*
	Author: Aaron Clark - EpochMod.com

    Contributors:

	Description:
	Epoch fishing function

    Licence:
    Arma Public License Share Alike (APL-SA) - https://www.bistudio.com/community/licenses/arma-public-license-share-alike

    Github:
    https://github.com/EpochModTeam/Epoch/tree/master/Sources/epoch_code/compile/EPOCH_fish.sqf
*/
private ["_bobber","_diffTime","_dt","_fishes","_fish","_randomChanceMax","_randomChance","_castTime","_nearByBobbers","_nearByBobbersLocal","_objects","_currentPos"];

_currentPos = player modelToWorld[0, 5 + (random 5), 0];
if (surfaceIsWater _currentPos) then {

    _objects = lineIntersectsObjs[eyePos player, _currentPos, player, objNull, true, 2];
    if (_objects isEqualTo []) then{

        _nearByBobbers = nearestObjects [player,["Bobber_EPOCH"],12];
        _nearByBobbersLocal = [];
        {
            if (local _x) then {
                _nearByBobbersLocal pushBack _x
            };
        } forEach _nearByBobbers;

        // Cast bobber and set for cleanup
        if (_nearByBobbersLocal isEqualTo []) then {
            _bobber = createVehicle ["Bobber_EPOCH",_currentPos, [], 0, "CAN_COLLIDE"];
            [_bobber] remoteExec ["EPOCH_localCleanup",2];
            _bobber setPosASL _currentPos;
            _bobber setVariable ["EPOCH_bobberTime", diag_tickTime];
        } else {

            _bobber = _nearByBobbersLocal select 0;
            // Reel in and delete Bobber
            if !(isNull _bobber) then {

                _castTime = _bobber getVariable ["EPOCH_bobberTime", diag_tickTime];
                _diffTime = (diag_tickTime - _castTime) / 10;

                if (_diffTime == 0) then {
                    _bobber setVariable ["EPOCH_bobberTime", diag_tickTime];
                } else {

                    // max out chance when fish on line within last 10 seconds
                    if ((diag_tickTime - (_bobber getVariable ["EPOCH_fishOnLine" , 0])) <= 10) then {
                        _diffTime = 100;
                    };

                    _bobber setVelocity [0,-1,-10];
                    deleteVehicle _bobber;

                    _randomChanceMax = (100 - _diffTime) max 1 min 99;
                    _randomChance = random 100;

                    if (_randomChance > _randomChanceMax) then {
                        // TODO: make payout config based
                        _fishes = ["ItemTuna","ItemSeaBass","ItemSeaBass","ItemSeaBass","ItemTrout","ItemTrout","ItemTrout","ItemTrout","ItemTrout","ItemTrout"];
                        _fish = _fishes param [floor(random(count _fishes)),""];

                        if (_fish != "") then {
                          _fish call EPOCH_fnc_addItemOverflow;
                          ["<t size='1.6' color='#99ffffff'>Fish Caught</t>", 5] call Epoch_dynamicText;
                        };

                    } else {
                        ["<t size='1.6' color='#99ffffff'>Fish Got Away</t>", 5] call Epoch_dynamicText;
                    };
                };
            };
        };
    };
};
