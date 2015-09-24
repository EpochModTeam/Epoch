/*
Building Maintain

Epoch Mod - EpochMod.com
All Rights Reserved.
*/
private["_object", "_plyr", "_maintCount", "_plyrUID", "_counter", "_objSlot", "_objHiveKey", "_buildingJammerRange", "_current_crypto", "_cIndex", "_vars"];

_object = _this select 0;
_plyr = _this select 1;
_maintCount = _this select 2;

if !([_plyr, _this select 3] call EPOCH_server_getPToken) exitWith{};
if (isNull _object) exitWith{};
if (_plyr distance _object > 20) exitWith{};
_config = 'CfgEpochClient' call EPOCH_returnConfig;
_buildingJammerRange = getNumber(_config >> "buildingJammerRange");
if (_buildingJammerRange == 0) then { _buildingJammerRange = 75; };

_plyrUID = getPlayerUID _plyr;
_counter = 0;

if (typeOf _object == "PlotPole_EPOCH") then {
	// maintain pole

	_objSlot = _object getVariable["BUILD_SLOT", -1];
	if (_objSlot != -1) then {

		// get vars array and current Crypto value
		_cIndex = EPOCH_customVars find "Crypto";
		_vars = _plyr getVariable["VARS", [] + EPOCH_defaultVars_SEPXVar];
		_current_crypto = _vars select _cIndex;

		if (_current_crypto >= _maintCount) then {

			// maintain jammer
			_counter = _counter + 1;
			_object call EPOCH_fnc_saveBuilding;

			if (_maintCount > 1) then {
				// maintain all objects within range
				{
					_object = _x;
					_objSlot = _object getVariable["BUILD_SLOT", -1];
					if (_objSlot != -1) then {
						if ((damage _object) > 0) then {
							_counter = _counter + 1;
							_object call EPOCH_fnc_saveBuilding;
						};
					};
					if (_counter >= _maintCount) exitWith{};
				} forEach nearestObjects[_object, ["Constructions_static_F","Constructions_foundation_F"], _buildingJammerRange];

				// effect crypto

				_playerCryptoLimit = [(configFile >> "CfgSecConf" >> "limits"), "playerCrypto", 25000] call EPOCH_fnc_returnConfigEntry;

				_current_crypto = ((_current_crypto - _counter) min _playerCryptoLimit) max 0;
				[["effectCrypto", _current_crypto], (owner _plyr)] call EPOCH_sendPublicVariableClient;
				_vars set[_cIndex, _current_crypto];
				_plyr setVariable["VARS", _vars];

			};
			diag_log format["ADMIN: %1 maintained %2 base objects at %3", _plyrUID, _counter, getPosATL(_this select 0)];
		};

	};

};
