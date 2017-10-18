/*
	Author: Raimonds Virtoss - EpochMod.com

    Contributors:

	Description: Determines which gear slot item goes into

    Licence:
    Arma Public License Share Alike (APL-SA) - https://www.bistudio.com/community/licenses/arma-public-license-share-alike

    Github:
    https://github.com/EpochModTeam/Epoch/tree/release/Sources/epoch_code/compile/inventory/EPOCH_itemTypeSlot.sqf

	Usage: _item call epoch_itemTypeSlot;
	
	Returns: [INT]
					0 - unknown							
					1 - Epoch items	
					2 - Magazines/Ammo
					3 - Primary slot					
					4 - Secondary slot					
					5 - Handgun slot					
					6 - Weapon attachments				
					7 - assigned Items (use assignItem)
					8 - Headgear (assignItem works)
					9 - NVGoggles (assignItem works)
					10 - Binocular (assignItem doesn't work)
					11 - goggles (assignItem works)
					12 - Mines
					13 - Vests
					14 - Uniforms
					15 - Backpack
					16 - smoke shells
					17 - Grenades
					17 - Unsure about these, modify script as required, but don't change existing structure
*/
private ["_item","_cat","_type"];
params [["_item","",[""]]];
if (_item == "") exitWith {false};

(_item call BIS_fnc_itemType) params ["_cat","_type"]; //For missing types go to https://community.bistudio.com/wiki/BIS_fnc_itemType

if (_type == "UnknownMagazine") exitWith {1};
if (_type in ["Bullet","ShotgunShell","Flare"]) exitWith {2}; //Ammo
if (_type in ["MachineGun","AssaultRifle","SniperRifle","Rifle","SubmachineGun"]) exitWith {3}; //Primary Epoch
if (_type == "Throw") exitWith {4}; //secondary epoch
if (_type == "Handgun") exitWith {5}; //handgun epoch
if (_type in ["AccessoryMuzzle","AccessoryPointer","AccessorySights","AccessoryBipod"]) exitWith {6}; //accessories
if (_type in ["Compass","GPS","Map","Radio","Watch"]) exitWith {7}; //assignItem works
if (_type == "Headgear") exitWith {8}; //assignItem works
if (_type == "NVGoggles") exitWith {9}; //assignItem works
if (_type == "Binocular") exitWith {10}; //assignItem doesn't work
if (_type == "Glasses") exitWith {11}; //assignItem doesn't work
if (_cat == "Mine") exitWith {12};
if (_type == "Vest") exitWith {13};
if (_type == "Uniform") exitWith {14};
if (_type == "Backpack") exitWith {15};
if (_type in ["Shell","SmokeShell"]) exitWith {16}; //Smoke shells for GL
if (_type == "Grenade") exitWith {17};

//unsure
if (_type in ["Magazine","Shotgun","FirstAidKit","LaserDesignator","Medikit","MineDetector","Toolkit","VehicleWeapon","Unknown","UnknownEquipment","UnknownWeapon"]) exitWith {18};

0 