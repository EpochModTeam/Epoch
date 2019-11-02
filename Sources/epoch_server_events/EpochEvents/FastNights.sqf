params [["_nightmulti",48],["_daymulti",4]];
if (sunOrMoon < 0.99) then { // adjust this lower to change sooner. Note: "0.99 value, the twilight is still quite dark" https://community.bistudio.com/wiki/sunOrMoon
	setTimeMultiplier _nightmulti	// [0.1 ... 120] adjust this value for slower or faster night cycle ( 24 hours will take 0.5 hours )
} else {
	setTimeMultiplier _daymulti		// adjust this value for slower or faster day cycle  ( 24 hours will take 6 hours )
};
