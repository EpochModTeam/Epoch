/*
	Author: Aaron Clark - EpochMod.com

    Contributors:

	Description:
	test code to replace string in word (old)

    Licence:
    Arma Public License Share Alike (APL-SA) - https://www.bistudio.com/community/licenses/arma-public-license-share-alike

    Github:
    https://github.com/EpochModTeam/Epoch/tree/master/Sources/epoch_code/compile/EPOCH_replaceWord.sqf
*/
private["_nextChar2", "_nextChar1", "_nextChar", "_replaceArray", "_STRING", "_needle", "_replace"];
_replaceArray = [];

_STRING = toArray(_this select 0);
_needle = toArray(_this select 1);
_replace = toArray(_this select 2);

{
	if (_x == (_needle select 0)) then {
		_nextChar = _forEachIndex + 1;
		if ((_STRING select _nextChar) == (_needle select 1)) then {
			_nextChar1 = _nextChar + 1;
			if ((_STRING select _nextChar1) == (_needle select 2)) then {
				_nextChar2 = _nextChar1 + 1;

				if ((_STRING select _nextChar2) == (_needle select 3)) then {
					_nextChar3 = _nextChar2 + 1;

					if ((_STRING select _nextChar3) == (_needle select 4)) then {
						_nextChar4 = _nextChar3 + 1;

						if ((_STRING select _nextChar4) == (_needle select 5)) then {
							_replaceArray pushBack[_forEachIndex, _nextChar, _nextChar1, _nextChar2, _nextChar3, _nextChar4];
						};
					};
				};
			};
		};
	};

}forEach _STRING;
{
	for "_i" from 0 to(count _x - 1) do {
		_STRING set[_x select _i, _replace select _i];
	}
}forEach _replaceArray;

toString(_STRING);
