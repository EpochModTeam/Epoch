/*
	Author: Aaron Clark - EpochMod.com

    Contributors:

	Description:
	Epoch fishing function

    Licence:
    Arma Public License Share Alike (APL-SA) - https://www.bistudio.com/community/licenses/arma-public-license-share-alike

    Github:
    https://github.com/EpochModTeam/Epoch/tree/release/Sources/epoch_code/compile/EPOCH_fish.sqf
*/
//[[[cog import generate_private_arrays ]]]
private ["_bobber","_castTime","_currentPos","_diffTime","_fish","_fishes","_objects","_randomChance","_randomChanceMax"];
//[[[end]]]

_currentPos = player modelToWorld[0, 5 + (random 5), 0];
if (surfaceIsWater _currentPos) then {

    _objects = lineIntersectsObjs[eyePos player, _currentPos, player, objNull, true, 2];
    if (_objects isEqualTo []) then{

        // Cast bobber and set for cleanup
        _bobber = missionNamespace getVariable ["EPOCH_myBobber", objNull];
        if (isNull _bobber) then {
            _bobber = createVehicle ["Bobber_EPOCH",_currentPos, [], 0, "CAN_COLLIDE"];
            [_bobber] remoteExec ["EPOCH_localCleanup",2];
            _bobber setPosASL _currentPos;
            _bobber setVariable ["EPOCH_bobberTime", diag_tickTime];
            EPOCH_myBobber = _bobber;
        } else {
            if (_bobber distance player > 12) then {
                ["No bobber found within 12m.", 5] call Epoch_message;
            } else {
                _castTime = _bobber getVariable ["EPOCH_bobberTime", diag_tickTime];
                _diffTime = (diag_tickTime - _castTime) / 10;

                if (_diffTime == 0) then {
                    _bobber setVariable ["EPOCH_bobberTime", diag_tickTime];
                } else {

                    // max out chance when fish on line within last 10 seconds
                    if ((diag_tickTime - (_bobber getVariable ["EPOCH_fishOnLine" , 0])) <= 10) then {
                        _diffTime = 100;
                    };

                    // make bobber move and delete
                    _bobber setVelocity [0,-1,-10];
                    _bobber spawn {
                        uiSleep 0.5;
                        deleteVehicle _this;
                    };

                    _randomChanceMax = (100 - _diffTime) max 1 min 99;
                    _randomChance = random 100;

                    if (_randomChance > _randomChanceMax) then {
                        _fishes = ["CfgEpochClient", "fishLoots", ["ItemTuna","ItemSeaBass","ItemSeaBass","ItemSeaBass","ItemTrout","ItemTrout","ItemTrout","ItemTrout","ItemTrout","ItemTrout"]] call EPOCH_fnc_returnConfigEntryV2;
                        _fish = selectRandom _fishes;
                        if (_fish != "") then {
                            _fish call EPOCH_fnc_addItemOverflow;
                            ["Fish Caught", 5] call Epoch_message;
                        };
                    } else {
                        ["Fish Got Away", 5] call Epoch_message;
                    };
                };
            };
        };
    };
};
