/*
	Author: Andrew Gregory - EpochMod.com

    Contributors:

	Description:
	Create map marker for everyone, group or individual.

	Parameter(s):
	_this select 0: ARRAY - [Target Type 0-Player 1-Group Members 2-All players 3-Multiple custom players, Object(s) - Player, Group, Array of Players or markerName for option 3]
	_this select 1-9: STRING(S) - Marker parameters.

    Licence:
    Arma Public License Share Alike (APL-SA) - https://www.bistudio.com/community/licenses/arma-public-license-share-alike

    Github:
    https://github.com/EpochModTeam/Epoch/tree/master/Sources/epoch_server/compile/epoch_server/EPOCH_server_makeMarker.sqf
*/
//[[[cog import generate_private_arrays ]]]
private ["_mrkr","_mrkrName","_trgtObj","_trgtType"];
//[[[end]]]
params ["_trgt","_mPos",["_mShape","ICON"],["_mType","mil_dot"],["_mText",""],["_mColor","ColorBlack"],["_mSize",[0.7,0.7]],"_mBrush","_mDir","_mAlpha",["_mrkrName",""]];

diag_log format["Epoch: ADMIN: Creating marker at %1 called by %2.", _mPos, _trgt];
if(count _trgt < 2)exitWith{};
_trgtType = _trgt select 0;
_trgtObj = _trgt select 1;
if(_mrkrName == "")then{_mrkrName = str(_trgtObj) + str(diag_tickTime);};

switch _trgtType do {

	case 0: {
		if(isPlayer _trgtObj)then{
			[_trgtObj,_mPos,_mShape,_mType,_mColor,_mSize,_mBrush,_mDir,_mText,_mAlpha,_mrkrName] remoteExec ['EPOCH_makeMarker',_trgtObj];
		};
	};

	case 1: {
		if!(isNull _trgtObj)then{
			{
			[_x,_mPos,_mShape,_mType,_mColor,_mSize,_mBrush,_mDir,_mText,_mAlpha,_mrkrName] remoteExec ['EPOCH_makeMarker',_x];
			}foreach (units group _trgtObj);
		};
	};

	case 2: {
			if(_trgtObj == "")then{_trgtObj=diag_tickTime;};
			_mrkr = createMarker [_mrkrName, _mPos];
			_mrkr setMarkerShape _mShape;
			_mrkr setMarkerType _mType;
			if!(_mText == "")then{_mrkr setMarkerText _mText;};
			_mrkr setMarkerColor _mColor;
			_mrkr setMarkerSize _mSize;
			if!(isNil "_mBrush")then{_mrkr setMarkerBrush _mBrush;};
			if!(isNil "_mDir")then{_mrkr setMarkerDir _mDir;};
			if!(isNil "_mAlpha")then{_mrkr setMarkerAlpha _mAlpha;};
	};

	case 3: {
		if(isArray _trgtObj && count _trgtObj > 0)then{
			{
			[_x,_mPos,_mShape,_mType,_mColor,_mSize,_mBrush,_mDir,_mText,_mAlpha,_mrkrName] remoteExec ['EPOCH_makeMarker',_x];
			}foreach _trgtObj;
		};
	};


	default {diag_log format["Epoch: ADMIN: Marker failed at %1 called by %2.", _mPos, _trgt];};
};
