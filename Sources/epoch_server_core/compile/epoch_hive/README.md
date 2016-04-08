**EPOCH_fnc_server_hiveSET**

Permanent storage of value with given prefix:key

_Uses Hive Call: (**101, 111) or (100, 110)**_

_Input: Key Prefix, Unique Key, Value_

_Returns: Nothing_

```
// get reference to player and get playerUID to use as unique key

_playerUID = getPlayerUID _playerObject;

// Fill your Array with data
_VAL = [damage _playerObject];

// Save value to database with given prefix:key
["PlayerMYCustomKey", _playerUID, _VAL] call EPOCH_fnc_server_hiveSET;

```

**EPOCH_fnc_server_hiveSETEX**

Semi-Permanent storage of value with given prefix:key. This command is very useful at preventing long term data bloat in the database and should be used for storing data that does not need to be stored forever.

_Uses Hive Call: (**101, 121) or (100, 120)**_

_Input: Key Prefix, Unique Key, Expires in # seconds, Value_

_Returns: Nothing_

```
// get reference to player and get playerUID to use as unique key
_playerUID = getPlayerUID _playerObject;

// string (time in seconds) the key should last.
_expires = "2592000";  // 30 days

// Fill your array with data
_VAL = [damage _playerObject];

// Save value to database with given prefix:key and expiration.
["PlayerMYCustomKey", _playerUID, _expires, _VAL] call EPOCH_fnc_server_hiveSETEX;
```

**EPOCH_fnc_server_hiveEXPIRE**

Set a timeout on key. After the timeout has expired, the key will automatically be deleted.

_Uses Hive Call: (**131) or (130)**_

_Input: Key Prefix, Unique Key, Expires in # seconds_

_Returns: Nothing_

```
// get reference to player and get playerUID to use as unique key.
_playerUID = getPlayerUID _playerObject;

// string (time in seconds) the key should last.
_expires = "2592000"; // 30 days

// Set expiration on given prefix:key.
["PlayerMYCustomKey", _playerUID, _expires] call EPOCH_fnc_server_hiveEXPIRE; 
```

**EPOCH_fnc_server_hiveSETBIT**

Permanent storage of bit value with given prefix:key

_Uses Hive Call: **141**_

_Input: Key Prefix, Unique Key, Bit Index, Value_

_Returns: Nothing_

```
// get reference to player and get playerUID to use as unique key
_playerUID = getPlayerUID _playerObject;

// index to get bit value
_index = 0;

// 1 = true, 0 = false
_value = 1;

// Set bit at given index for prefix:key
["PlayerMYCustomBitKey", _playerUID, _index, _value] call EPOCH_fnc_server_hiveSETBIT;
```

**EPOCH_fnc_server_hiveGET**

Made to exceed the character limits of callextension within the dll using extra c++ and sqf logic. The GETRANGE function has proven to be more reliable to use for data sets that are known to exceed 8k chars.

_Uses Hive Call: **200**_

_Input: Key Prefix, Unique Key_

_Returns: Array(Status, Array)_

```
// get reference to player and get playerUID to use as unique key
_playerUID = getPlayerUID _playerObject;

// Get data using prefix:key. "PlayerMYCustomKey" is the prefix and "_playerUID" unique key.
_response = ["PlayerMYCustomKey", _playerUID] call EPOCH_fnc_server_hiveGET;

if ((_response select 0) == 1 && (_response select 1) isEqualType []) then {
   _status = _response select 0;
   _arr = _response select 1;
   // do something with _arr data here
};
```

**EPOCH_fnc_server_hiveGETTTL**

Made to exceed the character limits of callextension within the dll using extra c++ and sqf logic. Also, returns the ttl or expire time in seconds.

_Uses Hive Call: **200, 210**_

_Input: Key Prefix, Unique Key_

_Returns: Array(Status, Array,TTL)_

```
// get reference to player and get playerUID to use as unique key
_playerUID = getPlayerUID _playerObject;

// Get data and ttl using prefix:key. "PlayerMYCustomKey" is the prefix and "_playerUID" unique key.
_response = ["PlayerMYCustomKey", _playerUID] call EPOCH_fnc_server_hiveGETTTL;

if ((_response select 0) == 1 && (_response select 1) isEqualType [] && !((_response select 1) isEqualTo [])) then {
   _status = _response select 0;
   _arr = _response select 1;
   _ttl = _response select 2;

   // do something with data here
}
```

**EPOCH_fnc_server_hiveGETBIT**

Returns the bit value at offset in the string value stored at key.

_Uses Hive Call: **240**_

_Input: Key Prefix, Unique Key, Bit Index_

_Returns: Bool(true|false)_

```
// get reference to player and get playerUID to use as unique key
_playerUID = getPlayerUID _playerObject;

// index to get bit value
_index = 0;

// Get bit value with given index at prefix:key
_return = ["PlayerMYCustomBitKey", _playerUID, _index] call EPOCH_fnc_server_hiveGETBIT;

if (_return) then {
    // do something if true
};
```

**EPOCH_fnc_server_hiveGETRANGE**

Made to exceed the character limits of callextension by using the redis command GETRANGE and sqf logic.

_Uses Hive Call: **220**_

_Input: Key Prefix, Unique Key_

_Returns: Array(Status, Array)_

```
// get reference to player and get playerUID to use as unique key
_playerUID = getPlayerUID _playerObject;

// PlayerMYCustomKey is the prefix and _playerUID unique key
_response = ["PlayerMYCustomKey", _playerUID] call EPOCH_fnc_server_hiveGETRANGE;

if ((_response select 0) == 1 && (_response select 1) isEqualType []) then {
   _status = _response select 0;
   _arr = _response select 1;
   // do something with data here
};
```

**EPOCH_fnc_server_hiveDEL**

Removes the specified key.

_Uses Hive Call: **400**_

_Input: Key Prefix, Unique Key_

_Returns: Nothing_

```
// get reference to player and get playerUID to use as unique key
_playerUID = getPlayerUID _playerObject;

// Remove key
["PlayerMYCustomKey", _playerUID] call EPOCH_fnc_server_hiveDEL;
```

**EPOCH_fnc_server_hiveLog**

Removes the specified key.

_Uses Hive Call: **700**_

_Input: Key Prefix, Message_

_Returns: Nothing_

```
// get reference to player and get playerUID to use as unique key
_playerUID = getPlayerUID _playerObject;

// Log to database, This data can be access via the database and can be found with the key "MyCustomLog-LOG"
['MyCustomLog', format["%1 (%2) at %3", _playerObject, _playerUID, getPosATL _playerObject]] call EPOCH_fnc_server_hiveLog;
```
