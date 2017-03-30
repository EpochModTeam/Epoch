/*
	Author: Aaron Clark - EpochMod.com

    Contributors:

	Description:
    For testing callExtension and other DB related updates.

    Licence:
    Arma Public License Share Alike (APL-SA) - https://www.bistudio.com/community/licenses/arma-public-license-share-alike

    Github:
    https://github.com/EpochModTeam/Epoch/tree/release/Sources/epoch_server_core/compile/epoch_hive/fn_server_hiveUnitTest.sqf
*/
_testID = "1234567890";
_payload = "32D1ECB8511569B43A5CC39DF4261CACDA912C798B066EE1E1EE06E2F09D02073C1B3FC638F091D58E7691DA7D0F7E1F01371CB58346572A015F6F93429F3BDC";
_expires = "600"; // 10 minutes
_payload_64k = "";
_startTime = diag_tickTime;
for "_i" from 1 to 512 do
{
    _payload_64k = _payload_64k + _payload;
};
_payload_64k_count = count _payload_64k;
diag_log format["DEBUG UNITTEST INIT: _payload count %1",count _payload, (diag_tickTime-_startTime)];
diag_log format["DEBUG UNITTEST INIT: _payload_64k count %1",_payload_64k_count, (diag_tickTime-_startTime)];

_startTime = diag_tickTime;
_response = "epochserver" callExtension "";
diag_log format ["Epoch UnitTest: version Time: %2 : %1 ", _response, (diag_tickTime-_startTime)];

// server config instanceID
_startTime = diag_tickTime;
_response = "epochserver" callExtension "000";
diag_log format ["Epoch UnitTest: 000 Time: %2 : %1 ", _response, (diag_tickTime-_startTime)];

// time
_startTime = diag_tickTime;
_response = "epochserver" callExtension "510";
diag_log format ["Epoch UnitTest: 510 Time: %2 : %1 ", _response, (diag_tickTime-_startTime)];


// SET
_startTime = diag_tickTime;
_response = ["TEST_DATA", _testID, [_payload]] call EPOCH_fnc_server_hiveSET;
diag_log format ["Epoch UnitTest: EPOCH_fnc_server_hiveSET Time: %2 : %1 ", _response, (diag_tickTime-_startTime)];
// SET 64k
_startTime = diag_tickTime;
_response = ["TEST_DATA_64", _testID, [_payload_64k]] call EPOCH_fnc_server_hiveSET;
diag_log format ["Epoch UnitTest: EPOCH_fnc_server_hiveSET 64k Time: %2 : %1 ", _response, (diag_tickTime-_startTime)];

// SETBIT true
_startTime = diag_tickTime;
_response = ["TEST_BIT_DATA", _testID, 0, 1] call EPOCH_fnc_server_hiveSETBIT;
diag_log format ["Epoch UnitTest: EPOCH_fnc_server_hiveSETBIT Time: %2 : %1 ", _response, (diag_tickTime-_startTime)];
// SETBIT false
_startTime = diag_tickTime;
_response = ["TEST_BIT_DATA", _testID, 1, 0] call EPOCH_fnc_server_hiveSETBIT;
diag_log format ["Epoch UnitTest: EPOCH_fnc_server_hiveSETBIT Time: %2 : %1 ", _response, (diag_tickTime-_startTime)];

// GETBIT true
_startTime = diag_tickTime;
_response = ["TEST_BIT_DATA", _testID, 0] call EPOCH_fnc_server_hiveGETBIT;
_charCheck = true isEqualTo _response;
diag_log format ["Epoch UnitTest: EPOCH_fnc_server_hiveGETBIT Time: %2 : %1 ", ["isOK:",_charCheck], (diag_tickTime-_startTime)];
// GETBIT false
_startTime = diag_tickTime;
_response = ["TEST_BIT_DATA", _testID, 1] call EPOCH_fnc_server_hiveGETBIT;
_charCheck = false isEqualTo _response;
diag_log format ["Epoch UnitTest: EPOCH_fnc_server_hiveGETBIT Time: %2 : %1 ", ["isOK:",_charCheck], (diag_tickTime-_startTime)];

// SETEX
_startTime = diag_tickTime;
_response = ["TEST_EXPIRES_DATA", _testID, _expires, [_payload]] call EPOCH_fnc_server_hiveSETEX;
diag_log format ["Epoch UnitTest: EPOCH_fnc_server_hiveSETEX Time: %2 : %1 ", _response, (diag_tickTime-_startTime)];
// SETEX 64k
_startTime = diag_tickTime;
_response = ["TEST_EXPIRES_DATA_64", _testID, _expires, [_payload_64k]] call EPOCH_fnc_server_hiveSETEX;
diag_log format ["Epoch UnitTest: EPOCH_fnc_server_hiveSETEX 64k Time: %2 : %1 ", _response, (diag_tickTime-_startTime)];

// GET
_startTime = diag_tickTime;
_response = ["TEST_DATA", _testID] call EPOCH_fnc_server_hiveGET;
_response params ["_status","_data"];
_charCheck = [_payload] isEqualTo _data;
diag_log format ["Epoch UnitTest: EPOCH_fnc_server_hiveGET Time: %2 : %1 ", ["isOK:",_charCheck], (diag_tickTime-_startTime)];
// GET 64k
_startTime = diag_tickTime;
_response = ["TEST_DATA_64", _testID] call EPOCH_fnc_server_hiveGET;
_response params ["_status","_data"];
_charCheck = [_payload_64k] isEqualTo _data;
diag_log format ["Epoch UnitTest: EPOCH_fnc_server_hiveGET 64k Time: %2 : %1 ", ["isOK:",_charCheck], (diag_tickTime-_startTime)];

// GETRANGE
_startTime = diag_tickTime;
_response = ["TEST_DATA", _testID] call EPOCH_fnc_server_hiveGETRANGE;
_response params ["_status","_data"];
_charCheck = [_payload] isEqualTo _data;
diag_log format ["Epoch UnitTest: EPOCH_fnc_server_hiveGETRANGE Time: %2 : %1 ", ["isOK:",_charCheck], (diag_tickTime-_startTime)];
// GETRANGE 64k
_startTime = diag_tickTime;
_response = ["TEST_DATA_64", _testID] call EPOCH_fnc_server_hiveGETRANGE;
_response params ["_status","_data"];
_charCheck = [_payload_64k] isEqualTo _data;
diag_log format ["Epoch UnitTest: EPOCH_fnc_server_hiveGETRANGE 64k Time: %2 : %1 ", ["isOK:",_charCheck], (diag_tickTime-_startTime)];

// Expire
_startTime = diag_tickTime;
_response = ["TEST_DATA", _testID, _expires] call EPOCH_fnc_server_hiveEXPIRE;
diag_log format ["Epoch UnitTest: EPOCH_fnc_server_hiveEXPIRE Time: %2 : %1 ", _response, (diag_tickTime-_startTime)];

// GETTTL
_startTime = diag_tickTime;
_response = ["TEST_EXPIRES_DATA", _testID] call EPOCH_fnc_server_hiveGETTTL;
_response params ["_status","_data"];
_charCheck = [_payload] isEqualTo _data;
diag_log format ["Epoch UnitTest: EPOCH_fnc_server_hiveGETTTL Time: %2 : %1 ", ["isOK:",_charCheck], (diag_tickTime-_startTime)];

// GETTTL 64k
_startTime = diag_tickTime;
_response = ["TEST_EXPIRES_DATA_64", _testID] call EPOCH_fnc_server_hiveGETTTL;
_response params ["_status","_data"];
_charCheck = [_payload_64k] isEqualTo _data;
diag_log format ["Epoch UnitTest: EPOCH_fnc_server_hiveGETTTL 64k Time: %2 : %1 ", ["isOK:",_charCheck], (diag_tickTime-_startTime)];

// Del
_startTime = diag_tickTime;
_response = ["TEST_DATA", _testID] call EPOCH_fnc_server_hiveDEL;
diag_log format ["Epoch UnitTest: EPOCH_fnc_server_hiveDEL TEST_DATA Time: %2 : %1 ", _response, (diag_tickTime-_startTime)];
_startTime = diag_tickTime;
_response = ["TEST_DATA_64", _testID] call EPOCH_fnc_server_hiveDEL;
diag_log format ["Epoch UnitTest: EPOCH_fnc_server_hiveDEL TEST_DATA_64 Time: %2 : %1 ", _response, (diag_tickTime-_startTime)];
_startTime = diag_tickTime;
_response = ["TEST_EXPIRES_DATA", _testID] call EPOCH_fnc_server_hiveDEL;
diag_log format ["Epoch UnitTest: EPOCH_fnc_server_hiveDEL TEST_EXPIRES_DATA Time: %2 : %1 ", _response, (diag_tickTime-_startTime)];
_startTime = diag_tickTime;
_response = ["TEST_EXPIRES_DATA_64", _testID] call EPOCH_fnc_server_hiveDEL;
diag_log format ["Epoch UnitTest: EPOCH_fnc_server_hiveDEL TEST_EXPIRES_DATA_64 Time: %2 : %1 ", _response, (diag_tickTime-_startTime)];

// HIVELOG
_startTime = diag_tickTime;
_response = ['TEST_LOG', _payload] call EPOCH_fnc_server_hiveLog;
diag_log format ["Epoch UnitTest: EPOCH_fnc_server_hiveLog Time: %2 : %1 ", _response, (diag_tickTime-_startTime)];
_startTime = diag_tickTime;
_response = ['TEST_LOG', _payload_64k] call EPOCH_fnc_server_hiveLog;
diag_log format ["Epoch UnitTest: EPOCH_fnc_server_hiveLog 64k Time: %2 : %1 ", _response, (diag_tickTime-_startTime)];
