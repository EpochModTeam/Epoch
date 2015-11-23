_min = safezoneX + 0.4 * safezoneW;
_max = safezoneX + 0.6 * safezoneW;
_r = linearConversion [_min, _max, _this, 0.2, -1, true];
_r2 = linearConversion [_min, _max, _this, 2, 0.8, true];
_r3 = linearConversion [_min, _max, _this, safezoneX, safezoneX - safezoneW * 0.3, true];

(findDisplay -7 displayCtrl 88801) ctrlSetPosition [_r,1,1.8];
(findDisplay -7 displayCtrl 88802) ctrlSetPosition [_r2,1,1.8];
(findDisplay -7 displayCtrl 88800) ctrlSetPosition [_r3,safezoneY - safezoneH * 0.1];
(findDisplay -7 displayCtrl 88800) ctrlCommit 0;