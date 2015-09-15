// Open a door with an animated doorhandle.

// _this select 0		object pointer
// _this select 1		door animation
// _this select 2		doorhandle up->down animation
// _this select 3		doorhandle down->up animation

(_this select 0) animate [(_this select 1), 1];
(_this select 0) animate [(_this select 2), 1];
(_this select 0) animate [(_this select 3), 1];