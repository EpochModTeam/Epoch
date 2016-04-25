if (sunOrMoon >= 0.99) then { // adjust this lower to change sooner. Note: "0.99 value, the twilight is still quite dark" https://community.bistudio.com/wiki/sunOrMoon
	setTimeMultiplier 13      // adjust this value for slower or faster night cycle ( 24 hours will take 1 hour )
} else {
	setTimeMultiplier 5      // adjust this value for slower or faster day cycle  ( 12 hours will take 1 hour )
};
