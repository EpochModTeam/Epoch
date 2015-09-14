private ["_playerPosASL","_abovePlayerPosASL"];
_playerPosASL = visiblePositionASL player;
_abovePlayerPosASL = [_playerPosASL select 0,_playerPosASL select 1,(_playerPosASL select 2) + 10];
//Return:
lineIntersects[_playerPosASL, _abovePlayerPosASL, player]