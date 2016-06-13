/*
	Author: Andrew Gregory - EpochMod.com

    Contributors:

	Description:
	Mission configs and dialogs

    Licence:
    Arma Public License Share Alike (APL-SA) - https://www.bistudio.com/community/licenses/arma-public-license-share-alike

    Github:
    https://github.com/EpochModTeam/Epoch/tree/release/Sources/epoch_config/Configs/CfgTraderMissions.hpp
*/

class MissionList{
	traderMissionNames[] = {"Mission - Pikes Peak Express","Mission - Animal Control","Mission - Track a Raider","Mission - VIP Chauffeur","What's the time ?","Who is near by ?","What's New ?","What is your name ?"};
	traderMissionDisabled[] = {};
	traderMissionActiveNames[] = {"Intercept Package","","","VIP Capture"};
	traderMissionLongDesc[] = {"Deliver an important message to another trader.","I need a wild animal bringing back here.","Take control of an UAV and track down a bounty.","Deliver a person safely to another location.","ASk the trader the local time.","Find out information about nearby people.","Ask the trader for any news.","Find out the traders name."};
	traderMissionActiveLongDesc[] = {"Intercept a mission delivery and bring me the message.","","","Capture a VIP being driven."};
};

class traderMissions {

	class MissionDelivery{
	author = "axeman";
	missionName = "Pikes Peak Express.";//Not used

		class welcome{
		condition = "(false)";//no longer used - button triggers mission
		dialogue[] = {"Hi, Can you take this item to another trader town. You will be paid well.","I have an important message to get out, take it to any other trader camp for a reward ?"};
        dialogue2[] = {"I have added the document to your inventory.","It's in your gear. If you don't have enough room try again later."};
		item[] = {"ItemDocumentMission","ItemDocumentMission"};
		action = "";
		};

		class accept{
		condition = "(false)";//Decided in code - change to true to default accept mission.
		dialogue[] = {"Great, now get out of here.. I will keep an eye on you through a drone.","Head toward one of the traders further away. I have a UAV to monitor your progress. Don't let me down !"};
        dialogue2[] = {"You now have an implant that allows me to send you messages.","I will try and help you with messages during your mission if possible."};
		missionDeclined[] = {"Not interested then ? Ok, maybe another time.","Ok, so you have better things to do. I will wait for someone else."};
		crypto[] = {0,0};
		weapon[] = {"",""};
		magazine[] = {"",""};
		item[] = {"",""};
		action = "";
		};

		class inmission1{
		condition = "(count (player nearEntities [[""Epoch_Male_F"",""Epoch_Female_F"",""C_man_hunter_1_F"",""Epoch_Female_Camo_F""], 150]) > 1)";
		dialogue[] = {"Look out, you have other survivors in the area.","Find a place to hide, UAV reports other survivors in your area."};
        dialogue2[] = {"",""};
		action = "";
        frequency = 560;
		};

		class inmission2{
		condition = "(count (player nearEntities [[""Epoch_Sapper_F"",""Alsatian_Random_EPOCH"",""Epoch_cloak_F"",""Fin_random_EPOCH""], 150]) > 0)";
		dialogue[] = {"You have something following you, watch your back..","Keep moving, you have something nearby."};
        dialogue2[] = {"",""};
		action = "";
        frequency = 560;
		};

		class inmission3{
		condition = "(false)";
		dialogue[] = {"",""};
        dialogue2[] = {"",""};
		action = "";
        frequency = 1024;
		};

		class completed{
		condition = "";//handled in code
		dialogue[] = {"Well Done, you made it. Let me see the document.", "So, you made it then, congratulations. Now for the message ?"};
        dialogue2[] = {"Hmm, interesting news, here's your reward, thanks for your assistance.","That is good news, I guess I should pay you now."};
		action[] = {""};
		crypto[] = {100,150};
		weapon[] = {"arifle_MX_SW_Hamr_pointer_F","Hatchet"};
		magazine[] = {"100Rnd_65x39_caseless_mag_Tracer","hatchet_swing"};
		item[] = {"RabbitCarcass_EPOCH","ChickenCarcass_EPOCH"};
		};

        class missioncheck{

            class health{
                dialogue[] = {"You look hurt, I am going to inject some adrenaline using your implant.","Hang in there buddy.. Your implant is about to give you a boost."};
                dialogue2[] = {"",""};
                action = "";
                frequency = 60;
            };

			class characters{
				dialogue[] = {"The drone picks up a mild heat signature nearby, could be a body to loot","Have spotted a prone player near your location, might be worth investigating."};
			};

            class itemlost{
                dialogue[] = {"Looks like you've lost the message, are you giving up on me ?","Don't leave that message lying around, it's essential that it arrives."};
                dialogue2[] = {"If you are thinking about taking the goods and running I would have a re-think.","I wouldn't run out on me now, the last person who tried didn't get very far !"};
                action = "";
            };

            class passed{
                dialogue[] = {"So you're taking over this mission. Deliver this message to another trader for a reward.","New blood eh. This document needs delivering to a trader as soon as possible."};
                dialogue2[] = {"",""};
                action = "hint ""Mission Passed Action..""";
            };

            class abandoned{
                condition = "(player distance _trader > 150)";
                dialogue[] = {"You running out with my gear..Not good, not good at all.","Take the gear and run eh ? You were supposed to be delivering a message !"};
                dialogue2[] = {"There's a price to pay for letting me down. Here it comes.","That's the last time you will cheat a trader. We don't take kindly to traitors."};
                delay = 60;
                action = "";
            };

        };


	};
	class MissionSapper{
	author = "axeman";
	missionName = "Animal Control.";//Not used

		class welcome{
		condition = "(false)";//no longer used - button triggers mission
		dialogue[] = {"I need a loose animal in the area capturing. He is known to be a bit wild","A brave survivor I see.. You need to find me a Sapper."};
        dialogue2[] = {"Go out and start looting, when you attract the attention of a Sapper Lure him to my location, I will do the rest.","Lure a sapper to my location. Hint: You need to get dirty to attract one."};
		item[] = {"",""};
		action = "";
		};

		class accept{
		condition = "(true)";//Decided in code - change to true to default accept mission. i.e. Doesn't require the player to be holding welcome item above e.g.
		dialogue[] = {"Get out there and try and attract a sapper.","On your way then."};
        dialogue2[] = {"I have a UAV patrolling the area. I will keep my eye out for you.","I will be watching. Try not to get too close to that sapper."};
		missionDeclined[] = {""};
		crypto[] = {0,0};
		weapon[] = {"",""};
		magazine[] = {"",""};
		item[] = {"",""};
		action = "";
		};

		class inmission1{
		condition = "((player distance _trader) < 60 && (_sapper distance _trader < 150))";
		dialogue[] = {"You need to get him close to me. I need to see the stitchings of his eyes.","I need him closer if I am to catch him. Come on you are nearly there !"};
        dialogue2[] = {"",""};
		action = "";
        frequency = 240;
		};

		class inmission2{
		condition = "(count (player nearEntities [[""Alsatian_Random_EPOCH"",""Epoch_cloak_F"",""Fin_random_EPOCH"",""Epoch_Male_F"",""Epoch_Female_F""], 250]) > 0)";
		dialogue[] = {"The UAV picked up a heat signature. Could be a person..","There is some.. thing in your area. Watch your back."};
        dialogue2[] = {"",""};
		action = "";
        frequency = 560;
		};

		class inmission3{
		condition = "(count (player nearEntities [[""Epoch_Sapper_F""], 250]) > 0)";
		dialogue[] = {"I think we have a target. The UAV picked up an unusual profile in your area.","Well done, you've found one. Now just lure him back to my location."};
        dialogue2[] = {"",""};
		action = "";
        frequency = 360;
		};

		class completed{
		condition = "";//handled in code
		dialogue[] = {"Well Done, you made it. Get out of the way. I need to cage this animal.", "Great work, let me deal with this guy first."};
        dialogue2[] = {"You've been a great help, here is your reward. Now clear the area as I may release him soon.","I get a good price for these guys. Here is your cut, pleasure doing business."};
		action[] = {""};
		crypto[] = {100,150};
		weapon[] = {"Hatchet","hgun_P07_F"};
		magazine[] = {"hatchet_swing","16Rnd_9x21_Mag"};
		item[] = {"RabbitCarcass_EPOCH","ChickenCarcass_EPOCH"};
		};

        class missioncheck{

            class health{
                dialogue[] = {"You look hurt, I am going to inject some adrenaline using your implant.","Hang in there buddy.. Your implant is about to give you a boost."};
                dialogue2[] = {"",""};
                action = "";
                frequency = 60;
            };

			class characters{
				dialogue[] = {"The drone picks up a mild heat signature nearby, could be a body to loot","Have spotted a prone player near your location, might be worth investigating."};
			};

            class itemlost{
                dialogue[] = {"Looks like you've lost the message, are you giving up on me ?","Don't leave that message lying around, it's essential that it arrives."};
                dialogue2[] = {"If you are thinking about taking the goods and running I would have a re-think.","I wouldn't run out on me now, the last person who tried didn't get very far !"};
                action = "";
            };

            class passed{
                dialogue[] = {"So you're taking over this mission. Deliver this message to another trader for a reward.","New blood eh. This document needs delivering to a trader as soon as possible."};
                dialogue2[] = {"",""};
                action = "";
            };

            class abandoned{
                condition = "(player distance _trader > 150)";
                dialogue[] = {"You running out with my gear..Not good, not good at all.","Take the gear and run eh ? You were supposed to be delivering a message !"};
                dialogue2[] = {"There's a price to pay for letting me down. Here it comes.","That's the last time you will cheat a trader. We don't take kindly to traitors."};
                delay = 60;
                action = "";
            };

        };


	};

	class MissionUav{
	author = "axeman";
	missionName = "Bounty Hunter.";//Not used

		class welcome{
		condition = "(false)";//no longer used - button triggers mission
		dialogue[] = {"I need to top up my coffers with some bounty. You are going to take control of a UAV and find a target for me.","How are your flying skills ? I need you to fly over nearby towns looking for a bounty."};
        dialogue2[] = {"I am giving you a Terminal Equip yourself with it.","Check your gear for the terminal. Equip yourself with it to start."};
		item[] = {"B_UavTerminal","B_UavTerminal"};
		action = "";
		};

		class accept{
		condition = "(false)";//Decided in code - change to true to default accept mission. i.e. Doesn't require the player to be holding welcome item above e.g.
		dialogue[] = {"Great, you are ready.I am preparing the UAV, it is outside. Once it is ready you can connect to it.","Splendid, you are a natural. Next, you will then need to connect to my UAV. Go look for it, I am preparing it for flight."};
        dialogue2[] = {"Once in control fly it around and get another player in you sights. Find a good spot to hide in during the mission.","Once you have control target another player in the UAV sights. You might want to find a quiet corner to operate from."};
		missionDeclined[] = {"Flying isn't for everyone. Come back when you have had some more practice eh ?","I guess you are just too busy right now. Come back later."};
		crypto[] = {0,0};
		weapon[] = {"",""};
		magazine[] = {"",""};
		item[] = {"",""};
		action = "";
		};

		class inmission1{
		condition = "(count (getPos Epoch_mission_uav nearObjects[""Man"",250]) > 1)";
		dialogue[] = {"I think you have a target in the area. Keep looking !","The UAV is pinging back heat signatures. You are close, keep looking."};
        dialogue2[] = {"",""};
		action = "";
        frequency = 240;
		};

		class inmission2{
		condition = "(false)";
		dialogue[] = {"",""};
        dialogue2[] = {"",""};
		action = "";
        frequency = 560;
		};

		class inmission3{
		condition = "(false)";
		dialogue[] = {"",""};
        dialogue2[] = {"",""};
		action = "";
        frequency = 360;
		};

		class completed{
		condition = "";//handled in code
		dialogue[] = {"That was some nice flying kid. Come back soon.", "Great work, was a pleasure working with you."};
        dialogue2[] = {"Here's an extra reward.  Pick up what you need.","Here is a bit extra for your troubles.."};
		action[] = {""};
		crypto[] = {75,100};
		weapon[] = {"",""};
		magazine[] = {"",""};
		item[] = {"",""};
		};

        class missioncheck{

            class health{
                dialogue[] = {"You look hurt, I am going to inject some adrenaline using your implant.","Hang in there buddy.. Your implant is about to give you a boost."};
                dialogue2[] = {"",""};
                action = "";
                frequency = 60;
            };

			class characters{
				dialogue[] = {"The drone picks up a mild heat signature nearby, could be a body to loot","Have spotted a prone player near your location, might be worth investigating."};
			};

            class itemlost{
                dialogue[] = {"Looks like you've lost the message, are you giving up on me ?","Don't leave that message lying around, it's essential that it arrives."};
                dialogue2[] = {"If you are thinking about taking the goods and running I would have a re-think.","I wouldn't run out on me now, the last person who tried didn't get very far !"};
                action = "";
            };

            class passed{
                dialogue[] = {"So you're taking over this mission. Deliver this message to another trader for a reward.","New blood eh. This document needs delivering to a trader as soon as possible."};
                dialogue2[] = {"",""};
                action = "";
            };

            class abandoned{
                condition = "";
                dialogue[] = {"Oh dear, smashing up my gear. Not good at all..","Hmm, do you think those UAVs grown on trees ?"};
                dialogue2[] = {"That's going to cost you, watch your back !","I am not happy about that ! Be more careful next time."};
                delay = 10;
                action = "";
            };

        };


	};


	class MissionDriver{
	author = "axeman";
	missionName = "The Generals Daughter.";

		class welcome{
		condition = "(false)";
		dialogue[] = {"I have an important delivery for you to make. She needs to arrive safely. Let me see if you need a GPS.","Can you drive ? My friend here needs a lift. Drop this person off to the general. I will make sure you have some equipment"};
        dialogue2[] = {"Take the generals daughter to the pick up point. There is a boat waiting so do not hang around.","This VIP must make it to the rendezvous. Wait for coordinates.. and make sure she gets there."};
		item[] = {"itemGPS","itemGPS"};
		action = "";
		};

		class accept{
		condition = "(true)";//Decided in code - change to true to default accept mission. i.e. Doesn't require the player to be holding welcome item above e.g.
		dialogue[] = {"",""};
        dialogue2[] = {"",""};
		missionDeclined[] = {"",""};
		crypto[] = {0,0};
		weapon[] = {"",""};
		magazine[] = {"",""};
		item[] = {"",""};
		action = "";
		};

		class inmission1{
		condition = "(count (player nearEntities [[""Epoch_Male_F"",""Epoch_Female_F"",""C_man_hunter_1_F"",""Epoch_Female_Camo_F""], 150]) > 1)";
		dialogue[] = {"I think I saw someone.. Over there !","Was that a person ? I think there are survivors here."};
        dialogue2[] = {"",""};
		action = "";
		};

		class inmission2{
		condition = "(count (player nearEntities [[""Epoch_Sapper_F"",""Alsatian_Random_EPOCH"",""Epoch_cloak_F"",""Fin_random_EPOCH""], 150]) > 0)";
		dialogue[] = {"I just spotted.. something. It could have been a dog ?","We need to keep moving ! I am sure I just saw some.. thing."};
        dialogue2[] = {"",""};
		action = "";
		};

		class inmission3{
		condition = "(diag_tickTime - _missionTimer > 1200)";
		dialogue[] = {"Are we there yet ? If we take too long the boat will be gone.","Are you lost ? Daddy is not a patient man, can we hurry it up please."};
        dialogue2[] = {"",""};
		action = "_missionTimer = diag_tickTime";
		};

		class completed{
		condition = "";
		dialogue[] = {"The General has sent us to collect his Daughter. Luckily for you she looks in good health.", "Nice work, you delivered her safely.  Thankfully, or the General would not be happy."};
        dialogue2[] = {"Help yourself to supplies from our boat. Hurry, we are leaving shortly.","Our boat is laden with supplies. Take all you can carry as a reward for your good work."};
		action[] = {""};
		crypto[] = {75,100};
		weapon[] = {"arifle_MX_SW_Hamr_pointer_F","speargun_epoch"};
		magazine[] = {"100Rnd_65x39_caseless_mag_Tracer","spear_magazine"};
		item[] = {{"KitTiPi","ItemJade","wolf_mask_epoch","lighter_epoch"},{"KitPlotPole","KitShelf","pkin_mask_epoch","ItemGoldBar"}};
		};

        class missioncheck{

            class health{
                dialogue[] = {"You look hurt, I am not driving myself there.","You are bleeding ! Yuk, don't get blood on my seat."};
                dialogue2[] = {"Stop and find some medical supplies ?","Do you want to try and find a bandage or something ?"};
                action = "";
                frequency = 60;
            };

			class characters{
				dialogue[] = {"",""};
			};

            class gotout{
                dialogue[] = {"Where are you going ?","Are you leaving me here ?"};
                dialogue2[] = {"Don't be long, I will wait here.","The heating is on, I am staying here and keeping warm !"};
                action = "";
            };

            class passed{
                dialogue[] = {"",""};
                dialogue2[] = {"",""};
                action = "";
            };

            class vehlost{
                condition = "";
                dialogue[] = {"Oh dear, that didn't go well. Maybe stop before driving into something next time ?","Nice driving, now what are going to do ?"};
                dialogue2[] = {"You need to find us another vehicle. I am not walking all the way there.","How are we going to get there now? You had best find another vehicle !"};
                delay = 10;
                action = "";
            };

        };


	};

};
