if (!isNull _this) then {
	EPOCH_lootContainer = [_this,player,Epoch_personalToken];
	publicVariableServer "EPOCH_lootContainer";

	if (typeof _this == "wardrobe_EPOCH") then {
		if !(_this getVariable["MIRROR_SETUP", false]) then {
			_this spawn {
				_this setVariable ["MIRROR_SETUP", true];
				_cam = "camera" camCreate (_this modelToWorld [0,0.25,1.5]); 
				_cam camSetTarget (_this modelToWorld [0,-30,1]);    
				_cam camSetFov 0.3;  
				_cam camCommit 0;  
				"rendertargetwardrobe0" setPiPEffect [0];   
				_cam cameraEffect ["Internal", "FRONT","rendertargetwardrobe0"];   
				_this setObjectTexture [0,"#(argb,512,512,1)r2t(rendertargetwardrobe0,1.0)"];

				waitUntil {
					uiSleep 5;
					(isNull _this) || ((_this distance player) > 20)
				};

				_cam cameraEffect ["terminate","back"];
				camDestroy _cam;
				_this setVariable["MIRROR_SETUP", nil];
				_this setObjectTexture [0,""];
			};
		};
	};
};