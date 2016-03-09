/*
	Author: Aaron Clark - EpochMod.com

    Contributors:

	Description:
	Server side damage and trash looting

    Licence:
    Arma Public License Share Alike (APL-SA) - https://www.bistudio.com/community/licenses/arma-public-license-share-alike

    Github:
    https://github.com/EpochModTeam/Epoch/tree/master/Sources/epoch_server/compile/epoch_looting/EPOCH_server_destroyTrash.sqf
*/
private["_target", "_eventArray", "_triggerType", "_nearPlayers", "_posWH", "_item", "_config", "_object", "_player", "_payout", "_type"];
params ["_object","_type","_player","_token"];

if (isNull _object) exitWith{};
if !([_player, _token] call EPOCH_server_getPToken) exitWith{};

if (!(_object isKindOf "All")) then {

	if (alive _object) then {

		_config = 'CfgEpochClient' call EPOCH_returnConfig;
		_payout = getArray(_config >> worldname >> "TrashClasses") param [_type, "Trash"];

		_posWH = getPosATL _player;
		_object setdamage 1;

		_item = createVehicle["groundWeaponHolder", _posWH, [], 0.0, "CAN_COLLIDE"];
		_item setPosATL _posWH;

		_config = (configFile >> "CfgMainTable" >> _payout);
		if (isClass _config) then {
			if (random 1 < getNumber(_config >> "chance")) then {
				[_item, _payout] call EPOCH_serverLootObject;
			};
		};

		// TODO move to server config
		if ((random 1) <= EPOCH_antagonistChanceTrash) then {
			_nearPlayers = _posWH nearEntities[["Epoch_Male_F", "Epoch_Female_F"], 50];

			if (!(_nearPlayers isEqualTo[])) then {
				_target = selectRandom _nearPlayers;

				_antagTable = ["Trash", "CfgMainTable", "antagonists"] call EPOCH_weightedArray;

				_antagTableArray = _antagTable select 0;
				if !(_antagTableArray isEqualTo[]) then{

					_weightedArray = _antagTable select 1;
					_weightedArrayCount = _antagTable select 2;

					_triggerType = _antagTableArray select(_weightedArray select floor(random _weightedArrayCount));

					[_target, _triggerType] call EPOCH_server_triggerEvent;
				};
			};
		};
	};
};
true
