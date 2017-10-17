/*
	Author: Raimonds Virtoss - EpochMod.com

    Contributors:

	Description:
	Receives array of CONFIGS
	Returns array of items pulled

    Licence:
    Arma Public License Share Alike (APL-SA) - https://www.bistudio.com/community/licenses/arma-public-license-share-alike

    Github:
    https://github.com/EpochModTeam/Epoch/tree/release/Sources/epoch_code/gui/scripts/craftingv2/EPOCH_crafting_getConfig.sqf
*/
//[[[cog import generate_private_arrays ]]]
private ["_Suppressed","_arr","_arrIn","_cCTime","_cDescFull","_cDescShort","_cDisplayName","_cModel","_cName","_cNearbyArr","_cPicture","_cPreviewArr","_cPreviewScale","_cPreviewVector","_cPriority","_cRecipeArr","_cRecipeReturn","_cType","_cUsedInArr","_cfg","_craftCount","_out","_type0","_type1","_type2","_type3"];
//[[[end]]]

_arrIn = _this;
_cfg = 'CfgEpochClient' call EPOCH_returnConfig;
_Suppressed = getarray (_cfg >> "SuppressedCraftingItems");

if !(typeName (_arrIn select 0) isEqualTo "CONFIG") exitWith {[]};

_type0 = []; _type1 = []; _type2 = []; _type3 = []; _out = [];
{
	_cName = configName _x;

	//overrides
	_arr = [_cName,["displayName","picture","descriptionShort","model"]] call epoch_itemData;

	_cDisplayName = if (isText (_x >> "displayName")) then {getText (_x >> "displayName")} else {_arr select 0};
	_cPicture = if (isText (_x >> "picture")) then {getText (_x >> "picture")} else {_arr select 1};
	_cDescShort = if (isText (_x >> "descriptionShort")) then {getText (_x >> "descriptionShort")} else {_arr select 2};
	_cModel = if (isText (_x >> "model")) then {getText (_x >> "model")} else {_arr select 3};

	//Basic cfg data
	_cPriority = getNumber (_x >> "priority");
	_cCTime = getNumber (_x >> "craftTime");
	_cRecipeArr = getArray (_x >> "recipe");
	_cNearbyArr = getArray (_x >> "nearby");
	_cUsedInArr = getArray (_x >> "usedIn");
	_cPreviewArr = getArray (_x >> "previewPosition");
	_cPreviewScale = getNumber (_x >> "previewScale");
	_cPreviewVector = getNumber (_x >> "previewVector");
	_cDescFull = getText (_x >> "descriptionFull");
	_cType = getNumber (_x >> "type");
	_craftCount = getNumber (_x >> "craftCount");
	_cRecipeReturn = getArray (_x >> "recipeReturn");

	if !(_Suppressed isequalto []) then {
		if (_cName in _Suppressed) then {
			_cRecipeArr = [];
		};
		{
			if (_x in _cUsedInArr) then {
				_cUsedInArr = _cUsedInArr - [_x];
			};
		} foreach _Suppressed;
		if (_cRecipeArr isequalto [] && _cUsedInArr isequalto []) then {
			_cPriority = -1;
		};
	};


	switch (_cPriority) do {
		case 0: {_type0 pushBack [_cName,_cDisplayName,_cPicture,_cDescShort,_cModel,_cPriority,_cCTime,_cRecipeArr,_cNearbyArr,_cUsedInArr,_cPreviewArr,_cPreviewScale,_cPreviewVector,_cType,_cDescFull,_craftCount,_cRecipeReturn]};
		case 1: {_type1 pushBack [_cName,_cDisplayName,_cPicture,_cDescShort,_cModel,_cPriority,_cCTime,_cRecipeArr,_cNearbyArr,_cUsedInArr,_cPreviewArr,_cPreviewScale,_cPreviewVector,_cType,_cDescFull,_craftCount,_cRecipeReturn]};
		case 2: {_type2 pushBack [_cName,_cDisplayName,_cPicture,_cDescShort,_cModel,_cPriority,_cCTime,_cRecipeArr,_cNearbyArr,_cUsedInArr,_cPreviewArr,_cPreviewScale,_cPreviewVector,_cType,_cDescFull,_craftCount,_cRecipeReturn]};
		case 3: {_type3 pushBack [_cName,_cDisplayName,_cPicture,_cDescShort,_cModel,_cPriority,_cCTime,_cRecipeArr,_cNearbyArr,_cUsedInArr,_cPreviewArr,_cPreviewScale,_cPreviewVector,_cType,_cDescFull,_craftCount,_cRecipeReturn]};
	};

} forEach _this;

_out append _type0;
_out append _type1;
_out append _type2;
_out append _type3;

_out
