/*
	Author: Aaron Clark - EpochMod.com

    Contributors: Skaronator

	Description:
	Building Maintain

    Licence:
    Arma Public License Share Alike (APL-SA) - https://www.bistudio.com/community/licenses/arma-public-license-share-alike

    Github:
    https://github.com/EpochModTeam/Epoch/tree/release/Sources/epoch_server/compile/epoch_bases/EPOCH_server_maintBUILD.sqf

    Example:
    	// Client RE
		[_this, player, _maintainCount, Epoch_personalToken] remoteExec ["EPOCH_server_maintBUILD",2];

    Parameter(s):
		_this select 0: OBJECT - Jammer object
        _this select 1: STRING - Player Object
		_this select 2: STRING - Maintain count
		_this select 3: STRING - Epoch Personal Token

	Returns:
	NOTHING
*/
//[[[cog import generate_private_arrays ]]]
private ["_cIndex","_counter","_current_crypto","_objSlot","_playerCryptoLimit","_playerUID","_storSlot","_vars"];
//[[[end]]]
params [["_object",objNull],"_player","_maintCount",["_token","",[""]] ];

if !([_player, _token] call EPOCH_server_getPToken) exitWith{};
if (isNull _object) exitWith{};
if (_player distance _object > 20) exitWith{};

_playerUID = getPlayerUID _player;
_counter = 0;

if (typeOf _object in (call EPOCH_JammerClasses)) then {

	_objSlot = _object getVariable["BUILD_SLOT", -1];
	if (_objSlot != -1) then {

		// get vars array and current Crypto value
		_cIndex = EPOCH_customVars find "Crypto";
		_vars = _player getVariable["VARS", call EPOCH_defaultVars_SEPXVar];
		_current_crypto = _vars select _cIndex;

		if (_current_crypto >= _maintCount) then {

			// maintain jammer
			_counter = _counter + 1;
			EPOCH_saveBuildQueue pushBackUnique _object;

			if (_maintCount > 0) then {

				// maintain all objects within range
				{
					_storSlot = _x getVariable["STORAGE_SLOT", "ABORT"];
					if (_storSlot != "ABORT") then {
						if ((damage _x) > 0) then {
							_counter = _counter + 1;
							EPOCH_saveStorQueue pushBackUnique _x;
						};
					};
					_objSlot = _x getVariable["BUILD_SLOT", -1];
					if (_objSlot != -1) then{
						if ((damage _x) > 0) then {
							_counter = _counter + 1;
							EPOCH_saveBuildQueue pushBackUnique _x;
						};
					};
					if (_counter > _maintCount) exitWith{};
				} forEach nearestObjects[_object, ["Constructions_static_F","Constructions_foundation_F","Buildable_Storage","Constructions_lockedstatic_F"], call EPOCH_MaxJammerRange];

				// effect crypto
				_playerCryptoLimit = EPOCH_customVarLimits select _cIndex;
				_playerCryptoLimit params ["_playerCryptoLimitMax","_playerCryptoLimitMin"];
				_current_crypto = ((_current_crypto - _counter) min _playerCryptoLimitMax) max _playerCryptoLimitMin;

				_current_crypto remoteExec ['EPOCH_effectCrypto',_player];

				_vars set[_cIndex, _current_crypto];
				_player setVariable["VARS", _vars];

			};
			diag_log format["Epoch: ADMIN: %1 maintained %2 base objects at %3", _playerUID, _counter, getPosATL _object];
		};
	};
};
