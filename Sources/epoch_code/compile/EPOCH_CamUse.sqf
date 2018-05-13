/*
	Author: He-Man

    Contributors:

	Description: BaseCam Script

    Licence:
    Arma Public License Share Alike (APL-SA) - https://www.bistudio.com/community/licenses/arma-public-license-share-alike

    Github:
    https://github.com/EpochModTeam/Epoch/tree/release/Sources/epoch_code/compile/EPOCH_CamUse.sqf
*/

private ["_mycams","_buildingJammerRange","_curcam"];

_mycams = EPOCH_BaseCams select {(_x getVariable["BUILD_OWNER", "-1"]) in [getPlayerUID player, Epoch_my_GroupUID]};
if (["CfgEpochClient", "BaseCamOnlyHome",true] call EPOCH_fnc_returnConfigEntryV2) then {
	_buildingJammerRange = ["CfgEpochClient", "buildingJammerRange",75] call EPOCH_fnc_returnConfigEntryV2;
	_mycams = _mycams select {!(((nearestobjects [_x,["Plotpole_EPOCH"],_buildingJammerRange]) select {(_x getVariable["BUILD_OWNER", "-1"]) in [getPlayerUID player, Epoch_my_GroupUID]}) isequalto [])};
};
if !(_mycams isequalto []) then {
	_curcam = _mycams find Epoch_ActiveCam;
	if (_curcam > -1 && (count _mycams) > (_curcam + 1)) then {
		Epoch_ActiveCam = _mycams select (_curcam + 1);
	}
	else {
		Epoch_ActiveCam = _mycams select 0;
	};
}
else {
	Epoch_ActiveCam = objnull;
};

if !(isnull (finddisplay -1200)) exitwith {};
if (isnull Epoch_ActiveCam) exitwith {
	["No Camera found",5] call Epoch_Message;
};

_mycams spawn {
	private ["_mycams","_display","_AutoCam","_ActiveCam","_campos","_CamFov","_CamDir","_CamDist","_EpochCam","_targetheight","_targetpos","_dirs","_intensity","_sharpness","_h","_oldalpha","_newalpha"];
	_mycams = _this;
	createdialog 'Epoch_CamDialog';
	waituntil {!isnull finddisplay -1200};
	_display = finddisplay -1200;
	(_display displayctrl 1000) ctrlsettext format ["Cam %1",(_mycams find Epoch_ActiveCam) + 1];
	(_display displayctrl 1001) ctrlsetstructuredtext parseText format [
		"<t align='center' color='#FFFF00' size='1'>Controls:</t><br/><br/>Cam Up: %1<br/>Cam Down: %2<br/>Cam Left: %3<br/>Cam Right: %4<br/>Zoom In: %5<br/>Zoom Out: %6<br/><br/>AutoCam: %7<br/>NextCam: %8",
		keyName Epoch_KB_BaseCamUp,keyName Epoch_KB_BaseCamDown,keyName Epoch_KB_BaseCamLeft,keyName Epoch_KB_BaseCamRight,keyName Epoch_KB_BaseCamZoomIn,keyName Epoch_KB_BaseCamZoomOut,keyName Epoch_KB_BaseCamAutoCam,keyName Epoch_KB_BaseCamNextCam
	];
	Epoch_AutoCam = true;
	_AutoCam = Epoch_AutoCam; 
	Epoch_CamAdjust = [0,0,0];
	_ActiveCam = Epoch_ActiveCam;
	_campos = Epoch_ActiveCam getRelPos [0.15,180];
	_campos set [2,(getposatl Epoch_ActiveCam select 2)];
	if (isnil "Epoch_CamFilmGrain") then {
		Epoch_CamFilmGrain = ppEffectCreate ["FilmGrain", 2000 + 25];
	};
	Epoch_CamFilmGrain ppEffectEnable true;
	_intensity = ((player distance Epoch_ActiveCam) / 10000) min 1;
	_sharpness = 1.25 - _intensity;
	Epoch_CamFilmGrain ppEffectAdjust [_intensity,_sharpness,2.01,0.75,1.0,true];
	Epoch_CamFilmGrain ppEffectCommit 0;
	_CamFov = 0.7;
	_CamDir = 0;
	_CamDist = 250;
	_EpochCam = 'camera' camCreate _campos;
	showCinemaBorder true;
	_EpochCam cameraEffect ['internal', 'front'];
	_EpochCam camCommit 0;
	_targetheight = ((getposasl Epoch_ActiveCam) select 2)-50;
	_targetpos = Epoch_ActiveCam getRelPos [_CamDist, 180+_CamDir];
	_targetpos set [2,_targetheight];
	if !(surfaceiswater _targetpos) then {
		_targetpos = ASLtoATL _targetpos;
	};
	_EpochCam camSetTarget _targetpos;
	_EpochCam camCommit 0;
	_dirs = [5,10,15,20,25,30,35,40,45,40,35,30,25,20,15,10,5,0,-5,-10,-15,-20,-25,-30,-35,-40,-45,-40,-35,-30,-25,-20,-15,-10,-5,0];
	while {!isnull _display} do {
		Epoch_CamAdjust params ["_dir","_height","_zoom"];
		_AutoCam = Epoch_AutoCam; 
		if !(_ActiveCam isequalto Epoch_ActiveCam) then {
			_ActiveCam = Epoch_ActiveCam;
			camDestroy _EpochCam;
			_campos = Epoch_ActiveCam getRelPos [0.15,180];
			_campos set [2,(getposatl Epoch_ActiveCam select 2)];
			_CamFov = 0.7;
			_CamDir = 0;
			_EpochCam = 'camera' camCreate _campos;
			showCinemaBorder true;
			_EpochCam cameraEffect ['internal', 'front'];
			_EpochCam camCommit 0;
			_targetheight = ((getposasl Epoch_ActiveCam) select 2)-50;
			_intensity = ((player distance Epoch_ActiveCam) / 10000) min 1;
			_sharpness = 1.25 - _intensity;
			Epoch_CamFilmGrain ppEffectAdjust [_intensity,_sharpness,2.01,0.75,1.0,true];
			Epoch_CamFilmGrain ppEffectCommit 0;
			(_display displayctrl 1000) ctrlsettext format ["Cam %1",(_mycams find Epoch_ActiveCam) + 1];
		};
		if !(Epoch_AutoCam) then {
			_targetheight = ((_targetheight + _height) min 50) max -150;
			_CamDir = ((_CamDir + _dir) max -45) min 45;
			_CamFov = ((_CamFov + _zoom) min 2) max 0.1;
		}
		else {
			_targetheight = ((getposasl Epoch_ActiveCam) select 2)-50;
			_CamFov = 0.7;
			_CamDir = _dirs deleteat 0;
			_dirs pushback _CamDir;
		};
		_targetpos = Epoch_ActiveCam getRelPos [_CamDist, 180+_CamDir];
		_targetpos set [2,_targetheight];
		if !(surfaceiswater _targetpos) then {
			_targetpos = ASLtoATL _targetpos;
		};
		_EpochCam camSetTarget _targetpos;
		_EpochCam camSetFov _CamFov;
		_EpochCam camCommit 0.75;
		Epoch_CamAdjust = [0,0,0];
		waitUntil {camCommitted _EpochCam ||  isnull _display || isnull Epoch_ActiveCam || !(_ActiveCam isequalto Epoch_ActiveCam)};
		if (isnull Epoch_ActiveCam) exitwith {};
	};
	player cameraEffect ['Terminate', 'FRONT'];
	camDestroy _EpochCam;
	_display closedisplay 0;
	Epoch_ActiveCam = objnull;
	Epoch_CamFilmGrain ppEffectEnable false;
};
