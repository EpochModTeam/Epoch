/*[[[cog from arma_config_tools import *; json_to_arma()]]]*/
/*
    @author = "Aaron Clark - https://EpochMod.com";
    @contributors[] = {};
    @description = "Epoch object interaction configs.";
    @licence = "Arma Public License Share Alike (APL-SA) - https://www.bistudio.com/community/licenses/arma-public-license-share-alike";
    @github = "https://github.com/EpochModTeam/Epoch/tree/release/Sources/epoch_config/Configs/CfgObjectInteractions.hpp";
*/
class CfgObjectInteractions
{
    class Default
    {
        interactMode = 0;
        distance = 0;
        toxicChance = 0;
        bleedChance = 0;
        bloodpChance = 0;
        fatigueChance = 0;
        bleedAmount = 0;
        bloodpAmount = 0;
		toxicAmount = 0;
        soundEffect[] = {};
        soundEffectGlobal = 0;
        animationEffect[] = {};
        animationEffectGlobal = 0;
        canSee = "false";
        ppEffect[] = {};
        aliveState = 0;
        interactAttributes[] = {};
    };
    class Land_MPS_EPOCH : Default {};
    class container_epoch : Default {};
    class PlotPole_EPOCH : Default
    {
        interactMode = 1;
    };
    class Tipi_EPOCH : Default
    {
        interactMode = 4;
    };
    class Tipi_SIM_EPOCH : Default
    {
        interactMode = 1;
    };
	class TentA_EPOCH : Default
    {
        interactMode = 4;
    };
    class TentA_SIM_EPOCH : Default
    {
        interactMode = 1;
    };
	class TentDome_EPOCH : Default
	{
		interactMode = 4;
	};
	class TentDome_SIM_EPOCH : Default
	{
		interactMode = 1;
	};
    class StorageShelf_EPOCH : Default
    {
        interactMode = 4;
    };
    class WorkBench_EPOCH : Default
    {
        interactMode = 4;
    };
    class Garden_EPOCH : Default
    {
        interactMode = 4;
    };
    class SolarCharger_EPOCH : Default
    {
        interactMode = 4;
    };
    class SolarChargerXL_EPOCH : Default
    {
        interactMode = 4;
    };
    class FieldToilet_EPOCH : Default
    {
        interactMode = 4;
    };
    class Foundation_EPOCH : Default
    {
        interactMode = 1;
    };
    class WoodFoundation_EPOCH : Default
    {
        interactMode = 1;
    };
    class Sheep_random_EPOCH : Default
    {
        interactMode = 3;
        aliveState = 1;
        interactAttributes[] = {{"Soiled",1}};
    };
    class Goat_random_EPOCH : Default
    {
        interactMode = 3;
        aliveState = 1;
        interactAttributes[] = {{"Soiled",1}};
    };
    class Cock_random_EPOCH : Default
    {
        interactMode = 3;
        aliveState = 1;
        interactAttributes[] = {{"Soiled",1}};
    };
    class Hen_random_EPOCH : Default
    {
        interactMode = 3;
        aliveState = 1;
        interactAttributes[] = {{"Soiled",1}};
    };
    class Rabbit_EPOCH : Default
    {
        interactMode = 3;
        aliveState = 1;
        interactAttributes[] = {{"Soiled",1}};
    };
    class Fin_random_EPOCH : Default
    {
        interactMode = 3;
        aliveState = 1;
        interactAttributes[] = {{"Karma",-100},{"Soiled",1}};
    };
    class Alsatian_Random_EPOCH : Default
    {
        interactMode = 3;
        aliveState = 1;
        interactAttributes[] = {{"Karma",-100},{"Soiled",1}};
    };
    class Epoch_Sapper_F : Default
    {
        interactMode = 3;
        aliveState = 1;
        interactAttributes[] = {{"Toxicity",20,1},{"Soiled",20,1}};
    };
    class Epoch_SapperG_F : Default
    {
        interactMode = 3;
        aliveState = 1;
        interactAttributes[] = {{"Toxicity",50,1},{"Soiled",50,1}};
    };
    class Epoch_SapperB_F : Default
    {
        interactMode = 3;
        aliveState = 1;
        interactAttributes[] = {{"Toxicity",20,1},{"Soiled",20,1}};
    };
    class I_UAV_01_F : Default
    {
        interactMode = 3;
        aliveState = 1;
        interactAttributes[] = {{"Energy",20,1}};
    };
    class Epoch_Female_F : Default
    {
        interactMode = 2;
    };
    class Epoch_Male_F : Default
    {
        interactMode = 2;
    };
    class C_man_1 : Default
    {
        interactMode = 2;
    };
    class SapperHead_SIM_EPOCH : Default
    {
        interactMode = 0;
        interactAttributes[] = {{"Soiled",1}};
    };
    class SapperCorpse_SIM_EPOCH : Default
    {
        interactMode = 0;
        interactAttributes[] = {{"Soiled",1}};
    };
    class Snake_random_EPOCH : Default
    {
        interactMode = 3;
        distance = 3;
        toxicChance = 0.2;
		toxicAmount = 10;
        bloodpChance = 1;
        fatigueChance = 0.5;
        bleedAmount = 30;
        bloodpAmount = 3;
        soundEffect[] = {"snake_bite0"};
        canSee = "!(lineIntersects[eyePos _unit, aimPos _target, _unit, _target])";
        ppEffect[] = {};
        aliveState = 0;
        interactAttributes[] = {{"Toxicity",20,1},{"Soiled",1}};
    };
    class Snake2_random_EPOCH : Default
    {
        interactMode = 3;
        distance = 3;
        toxicChance = 0.1;
		toxicAmount = 10;
        bloodpChance = 1;
        fatigueChance = 0.5;
        bleedAmount = 30;
        bloodpAmount = 3;
        soundEffect[] = {"snake_bite0"};
        canSee = "!(lineIntersects[eyePos _unit, aimPos _target, _unit, _target])";
        ppEffect[] = {};
        aliveState = 0;
        interactAttributes[] = {{"Toxicity",10,1},{"Soiled",1}};
    };
    class GreatWhite_F : Default
    {
        interactMode = 3;
        distance = 6;
        toxicChance = 0;
        bleedChance = 1;
        bloodpChance = 1;
        fatigueChance = 1;
        bleedAmount = 100;
        bloodpAmount = 3;
        canSee = "true";
        ppEffect[] = {};
        aliveState = 1;
        interactAttributes[] = {};
    };
    class SmokeShellCustom : Default
    {
        distance = 6;
        toxicChance = 1;
		toxicAmount = 100;
        bleedChance = 0;
        bloodpChance = 1;
        fatigueChance = 1;
        bleedAmount = 0;
        bloodpAmount = 3;
        canSee = "true";
        ppEffect[] = {};
    };
	class SmokeShellToxic_Ammo : SmokeShellCustom {};
	class SmokeShellToxicSapper : SmokeShellCustom {};
    class Epoch_Cloak_F : Default
    {
        distance = 30;
        toxicChance = 0;
        bloodpChance = 0.9;
        fatigueChance = 0.5;
        bleedAmount = 66;
        bloodpAmount = 3;
        soundEffect[] = {"cultist_nearby"};
        canSee = "!(lineIntersects[eyePos _unit, aimPos _target, _unit, _target])";
        ppEffect[] = {{{"filmGrain",2005,{0.1,-1,0.05,0.05,2,false},1},{"chromAberration",2006,{0.01,0.01,true},5},{"colorCorrections",2007,{1,1,0,{1.5,-1,-1.5,0.5},{5,3.5,-5,-0.5},{-3,5,-5,-0.5}},5},{"radialBlur",2008,{0.02,0.02,0.15,0.15},5}},2,{{},{{0,0,true},5},{{1,1,-0.01,{0.0,0.0,0.0,0.0},{1.5,1,1.2,0.6},{0.199,0.587,0.114,0.2}},5},{{0,0,0,0},5}},5,{}};
        interactMode = 3;
        aliveState = 1;
        interactAttributes[] = {{"Toxicity",20,1},{"Soiled",20,1}};
    };
    class EPOCH_RyanZombie_1 : Default
    {
        distance = 3;
        toxicChance = 0.1;
		toxicAmount = 10;
        bloodpChance = 0.9;
        fatigueChance = 0.4;
        bleedAmount = 30;
        bloodpAmount = 3;
        soundEffect[] = {{"ryanzombies\sounds\attack1.ogg",400},{"ryanzombies\sounds\attack2.ogg",400},{"ryanzombies\sounds\attack3.ogg",400},{"ryanzombies\sounds\attack4.ogg",400},{"ryanzombies\sounds\attack5.ogg",400}};
        soundEffectGlobal = 1;
        animationEffect[] = {"AwopPercMstpSgthWnonDnon_throw"};
        animationEffectGlobal = 1;
        canSee = "!(lineIntersects[eyePos _unit, aimPos _target, _unit, _target])";
        ppEffect[] = {};
        interactMode = 3;
        aliveState = 1;
        interactAttributes[] = {{"Toxicity",5,1},{"Soiled",10,1}};
    };
    class EPOCH_RyanZombie_2 : EPOCH_RyanZombie_1 {};
    class EPOCH_RyanZombie_3 : EPOCH_RyanZombie_1 {};
    class EPOCH_RyanZombie_4 : EPOCH_RyanZombie_1 {};
    class EPOCH_RyanZombie_5 : EPOCH_RyanZombie_1 {};
    class EPOCH_RyanZombie_1_C : EPOCH_RyanZombie_1 {};
    class EPOCH_RyanZombie_2_C : EPOCH_RyanZombie_1 {};
    class EPOCH_RyanZombie_3_C : EPOCH_RyanZombie_1 {};
    class EPOCH_RyanZombie_4_C : EPOCH_RyanZombie_1 {};
    class EPOCH_RyanZombie_5_C : EPOCH_RyanZombie_1 {};
    class EPOCH_RyanZombie_1_Sp : EPOCH_RyanZombie_1 {};
    class EPOCH_RyanZombie_2_Sp : EPOCH_RyanZombie_1 {};
    class EPOCH_RyanZombie_3_Sp : EPOCH_RyanZombie_1 {};
    class EPOCH_RyanZombie_4_Sp : EPOCH_RyanZombie_1 {};
    class EPOCH_RyanZombie_5_Sp : EPOCH_RyanZombie_1 {};
    class EPOCH_RyanZombie_1_B : EPOCH_RyanZombie_1 {};
    class EPOCH_RyanZombie_2_B : EPOCH_RyanZombie_1 {};
    class EPOCH_RyanZombie_3_B : EPOCH_RyanZombie_1 {};
    class EPOCH_RyanZombie_4_B : EPOCH_RyanZombie_1 {};
    class EPOCH_RyanZombie_5_B : EPOCH_RyanZombie_1 {};
    class EPOCH_RyanZombie_1_W : EPOCH_RyanZombie_1 {};
    class EPOCH_RyanZombie_2_W : EPOCH_RyanZombie_1 {};
    class EPOCH_RyanZombie_3_W : EPOCH_RyanZombie_1 {};
    class EPOCH_RyanZombie_4_W : EPOCH_RyanZombie_1 {};
    class EPOCH_RyanZombie_5_W : EPOCH_RyanZombie_1 {};
    class EPOCH_RyanZombie_1_M : EPOCH_RyanZombie_1 {};
    class EPOCH_RyanZombie_2_M : EPOCH_RyanZombie_1 {};
    class EPOCH_RyanZombie_3_M : EPOCH_RyanZombie_1 {};
    class EPOCH_RyanZombie_4_M : EPOCH_RyanZombie_1 {};
    class EPOCH_RyanZombie_5_M : EPOCH_RyanZombie_1 {};
    class EPOCH_RyanZombie_1_S : EPOCH_RyanZombie_1 {};
    class EPOCH_RyanZombie_2_S : EPOCH_RyanZombie_1 {};
    class EPOCH_RyanZombie_3_S : EPOCH_RyanZombie_1 {};
    class EPOCH_RyanZombie_4_S : EPOCH_RyanZombie_1 {};
    class EPOCH_RyanZombie_5_S : EPOCH_RyanZombie_1 {};
	
	class RyanZombieC_man_1 : EPOCH_RyanZombie_1 {};
	class RyanZombieC_man_polo_1_F : EPOCH_RyanZombie_1 {};
	class RyanZombieC_man_polo_2_F : EPOCH_RyanZombie_1 {};
	class RyanZombieC_man_polo_4_F : EPOCH_RyanZombie_1 {};
	class RyanZombieC_man_polo_5_F : EPOCH_RyanZombie_1 {};
	class RyanZombieC_man_polo_6_F : EPOCH_RyanZombie_1 {};
	class RyanZombieC_man_p_fugitive_F : EPOCH_RyanZombie_1 {};
	class RyanZombieC_man_w_worker_F : EPOCH_RyanZombie_1 {};
	class RyanZombieC_scientist_F : EPOCH_RyanZombie_1 {};
	class RyanZombieC_man_hunter_1_F : EPOCH_RyanZombie_1 {};
	class RyanZombieC_man_pilot_F : EPOCH_RyanZombie_1 {};
	class RyanZombieC_journalist_F : EPOCH_RyanZombie_1 {};
	class RyanZombieC_Orestes : EPOCH_RyanZombie_1 {};
	class RyanZombieC_Nikos : EPOCH_RyanZombie_1 {};
	class RyanZombie15 : EPOCH_RyanZombie_1 {};
	class RyanZombie16 : EPOCH_RyanZombie_1 {};
	class RyanZombie17 : EPOCH_RyanZombie_1 {};
	class RyanZombie18 : EPOCH_RyanZombie_1 {};
	class RyanZombie19 : EPOCH_RyanZombie_1 {};
	class RyanZombie20 : EPOCH_RyanZombie_1 {};
	class RyanZombie21 : EPOCH_RyanZombie_1 {};
	class RyanZombie22 : EPOCH_RyanZombie_1 {};
	class RyanZombie23 : EPOCH_RyanZombie_1 {};
	class RyanZombie24 : EPOCH_RyanZombie_1 {};
	class RyanZombie25 : EPOCH_RyanZombie_1 {};
	class RyanZombie26 : EPOCH_RyanZombie_1 {};
	class RyanZombie27 : EPOCH_RyanZombie_1 {};
	class RyanZombie28 : EPOCH_RyanZombie_1 {};
	class RyanZombie29 : EPOCH_RyanZombie_1 {};
	class RyanZombie30 : EPOCH_RyanZombie_1 {};
	class RyanZombie31 : EPOCH_RyanZombie_1 {};
	class RyanZombie32 : EPOCH_RyanZombie_1 {};
	class RyanZombieC_man_1medium : EPOCH_RyanZombie_1 {};
	class RyanZombieC_man_polo_1_Fmedium : EPOCH_RyanZombie_1 {};
	class RyanZombieC_man_polo_2_Fmedium : EPOCH_RyanZombie_1 {};
	class RyanZombieC_man_polo_4_Fmedium : EPOCH_RyanZombie_1 {};
	class RyanZombieC_man_polo_5_Fmedium : EPOCH_RyanZombie_1 {};
	class RyanZombieC_man_polo_6_Fmedium : EPOCH_RyanZombie_1 {};
	class RyanZombieC_man_p_fugitive_Fmedium : EPOCH_RyanZombie_1 {};
	class RyanZombieC_man_w_worker_Fmedium : EPOCH_RyanZombie_1 {};
	class RyanZombieC_scientist_Fmedium : EPOCH_RyanZombie_1 {};
	class RyanZombieC_man_hunter_1_Fmedium : EPOCH_RyanZombie_1 {};
	class RyanZombieC_man_pilot_Fmedium : EPOCH_RyanZombie_1 {};
	class RyanZombieC_journalist_Fmedium : EPOCH_RyanZombie_1 {};
	class RyanZombieC_Orestesmedium : EPOCH_RyanZombie_1 {};
	class RyanZombieC_Nikosmedium : EPOCH_RyanZombie_1 {};
	class RyanZombie15medium : EPOCH_RyanZombie_1 {};
	class RyanZombie16medium : EPOCH_RyanZombie_1 {};
	class RyanZombie17medium : EPOCH_RyanZombie_1 {};
	class RyanZombie18medium : EPOCH_RyanZombie_1 {};
	class RyanZombie19medium : EPOCH_RyanZombie_1 {};
	class RyanZombie20medium : EPOCH_RyanZombie_1 {};
	class RyanZombie21medium : EPOCH_RyanZombie_1 {};
	class RyanZombie22medium : EPOCH_RyanZombie_1 {};
	class RyanZombie23medium : EPOCH_RyanZombie_1 {};
	class RyanZombie24medium : EPOCH_RyanZombie_1 {};
	class RyanZombie25medium : EPOCH_RyanZombie_1 {};
	class RyanZombie26medium : EPOCH_RyanZombie_1 {};
	class RyanZombie27medium : EPOCH_RyanZombie_1 {};
	class RyanZombie28medium : EPOCH_RyanZombie_1 {};
	class RyanZombie29medium : EPOCH_RyanZombie_1 {};
	class RyanZombie30medium : EPOCH_RyanZombie_1 {};
	class RyanZombie31medium : EPOCH_RyanZombie_1 {};
	class RyanZombie32medium : EPOCH_RyanZombie_1 {};
	class RyanZombieC_man_1slow : EPOCH_RyanZombie_1 {};
	class RyanZombieC_man_polo_1_Fslow : EPOCH_RyanZombie_1 {};
	class RyanZombieC_man_polo_2_Fslow : EPOCH_RyanZombie_1 {};
	class RyanZombieC_man_polo_4_Fslow : EPOCH_RyanZombie_1 {};
	class RyanZombieC_man_polo_5_Fslow : EPOCH_RyanZombie_1 {};
	class RyanZombieC_man_polo_6_Fslow : EPOCH_RyanZombie_1 {};
	class RyanZombieC_man_p_fugitive_Fslow : EPOCH_RyanZombie_1 {};
	class RyanZombieC_man_w_worker_Fslow : EPOCH_RyanZombie_1 {};
	class RyanZombieC_scientist_Fslow : EPOCH_RyanZombie_1 {};
	class RyanZombieC_man_hunter_1_Fslow : EPOCH_RyanZombie_1 {};
	class RyanZombieC_man_pilot_Fslow : EPOCH_RyanZombie_1 {};
	class RyanZombieC_journalist_Fslow : EPOCH_RyanZombie_1 {};
	class RyanZombieC_Orestesslow : EPOCH_RyanZombie_1 {};
	class RyanZombieC_Nikosslow : EPOCH_RyanZombie_1 {};
	class RyanZombie15slow : EPOCH_RyanZombie_1 {};
	class RyanZombie16slow : EPOCH_RyanZombie_1 {};
	class RyanZombie17slow : EPOCH_RyanZombie_1 {};
	class RyanZombie18slow : EPOCH_RyanZombie_1 {};
	class RyanZombie19slow : EPOCH_RyanZombie_1 {};
	class RyanZombie20slow : EPOCH_RyanZombie_1 {};
	class RyanZombie21slow : EPOCH_RyanZombie_1 {};
	class RyanZombie22slow : EPOCH_RyanZombie_1 {};
	class RyanZombie23slow : EPOCH_RyanZombie_1 {};
	class RyanZombie24slow : EPOCH_RyanZombie_1 {};
	class RyanZombie25slow : EPOCH_RyanZombie_1 {};
	class RyanZombie26slow : EPOCH_RyanZombie_1 {};
	class RyanZombie27slow : EPOCH_RyanZombie_1 {};
	class RyanZombie28slow : EPOCH_RyanZombie_1 {};
	class RyanZombie29slow : EPOCH_RyanZombie_1 {};
	class RyanZombie30slow : EPOCH_RyanZombie_1 {};
	class RyanZombie31slow : EPOCH_RyanZombie_1 {};
	class RyanZombie32slow : EPOCH_RyanZombie_1 {};
	class RyanZombieC_man_1Walker : EPOCH_RyanZombie_1 {};
	class RyanZombieC_man_polo_1_FWalker : EPOCH_RyanZombie_1 {};
	class RyanZombieC_man_polo_2_FWalker : EPOCH_RyanZombie_1 {};
	class RyanZombieC_man_polo_4_FWalker : EPOCH_RyanZombie_1 {};
	class RyanZombieC_man_polo_5_FWalker : EPOCH_RyanZombie_1 {};
	class RyanZombieC_man_polo_6_FWalker : EPOCH_RyanZombie_1 {};
	class RyanZombieC_man_p_fugitive_FWalker : EPOCH_RyanZombie_1 {};
	class RyanZombieC_man_w_worker_FWalker : EPOCH_RyanZombie_1 {};
	class RyanZombieC_scientist_FWalker : EPOCH_RyanZombie_1 {};
	class RyanZombieC_man_hunter_1_FWalker : EPOCH_RyanZombie_1 {};
	class RyanZombieC_man_pilot_FWalker : EPOCH_RyanZombie_1 {};
	class RyanZombieC_journalist_FWalker : EPOCH_RyanZombie_1 {};
	class RyanZombieC_OrestesWalker : EPOCH_RyanZombie_1 {};
	class RyanZombieC_NikosWalker : EPOCH_RyanZombie_1 {};
	class RyanZombie15walker : EPOCH_RyanZombie_1 {};
	class RyanZombie16walker : EPOCH_RyanZombie_1 {};
	class RyanZombie17walker : EPOCH_RyanZombie_1 {};
	class RyanZombie18walker : EPOCH_RyanZombie_1 {};
	class RyanZombie19walker : EPOCH_RyanZombie_1 {};
	class RyanZombie20walker : EPOCH_RyanZombie_1 {};
	class RyanZombie21walker : EPOCH_RyanZombie_1 {};
	class RyanZombie22walker : EPOCH_RyanZombie_1 {};
	class RyanZombie23walker : EPOCH_RyanZombie_1 {};
	class RyanZombie24walker : EPOCH_RyanZombie_1 {};
	class RyanZombie25walker : EPOCH_RyanZombie_1 {};
	class RyanZombie26walker : EPOCH_RyanZombie_1 {};
	class RyanZombie27walker : EPOCH_RyanZombie_1 {};
	class RyanZombie28walker : EPOCH_RyanZombie_1 {};
	class RyanZombie29walker : EPOCH_RyanZombie_1 {};
	class RyanZombie30walker : EPOCH_RyanZombie_1 {};
	class RyanZombie31walker : EPOCH_RyanZombie_1 {};
	class RyanZombie32walker : EPOCH_RyanZombie_1 {};
	class RyanZombieSpider1 : EPOCH_RyanZombie_1 {};
	class RyanZombieSpider2 : EPOCH_RyanZombie_1 {};
	class RyanZombieSpider3 : EPOCH_RyanZombie_1 {};
	class RyanZombieSpider4 : EPOCH_RyanZombie_1 {};
	class RyanZombieSpider5 : EPOCH_RyanZombie_1 {};
	class RyanZombieSpider6 : EPOCH_RyanZombie_1 {};
	class RyanZombieSpider7 : EPOCH_RyanZombie_1 {};
	class RyanZombieSpider8 : EPOCH_RyanZombie_1 {};
	class RyanZombieSpider9 : EPOCH_RyanZombie_1 {};
	class RyanZombieSpider10 : EPOCH_RyanZombie_1 {};
	class RyanZombieSpider11 : EPOCH_RyanZombie_1 {};
	class RyanZombieSpider12 : EPOCH_RyanZombie_1 {};
	class RyanZombieSpider13 : EPOCH_RyanZombie_1 {};
	class RyanZombieSpider14 : EPOCH_RyanZombie_1 {};
	class RyanZombieSpider15 : EPOCH_RyanZombie_1 {};
	class RyanZombieSpider16 : EPOCH_RyanZombie_1 {};
	class RyanZombieSpider17 : EPOCH_RyanZombie_1 {};
	class RyanZombieSpider18 : EPOCH_RyanZombie_1 {};
	class RyanZombieSpider19 : EPOCH_RyanZombie_1 {};
	class RyanZombieSpider20 : EPOCH_RyanZombie_1 {};
	class RyanZombieSpider21 : EPOCH_RyanZombie_1 {};
	class RyanZombieSpider22 : EPOCH_RyanZombie_1 {};
	class RyanZombieSpider23 : EPOCH_RyanZombie_1 {};
	class RyanZombieSpider24 : EPOCH_RyanZombie_1 {};
	class RyanZombieSpider25 : EPOCH_RyanZombie_1 {};
	class RyanZombieSpider26 : EPOCH_RyanZombie_1 {};
	class RyanZombieSpider27 : EPOCH_RyanZombie_1 {};
	class RyanZombieSpider28 : EPOCH_RyanZombie_1 {};
	class RyanZombieSpider29 : EPOCH_RyanZombie_1 {};
	class RyanZombieSpider30 : EPOCH_RyanZombie_1 {};
	class RyanZombieSpider31 : EPOCH_RyanZombie_1 {};
	class RyanZombieSpider32 : EPOCH_RyanZombie_1 {};
	class RyanZombieCrawler1 : EPOCH_RyanZombie_1 {};
	class RyanZombieCrawler2 : EPOCH_RyanZombie_1 {};
	class RyanZombieCrawler3 : EPOCH_RyanZombie_1 {};
	class RyanZombieCrawler4 : EPOCH_RyanZombie_1 {};
	class RyanZombieCrawler5 : EPOCH_RyanZombie_1 {};
	class RyanZombieCrawler6 : EPOCH_RyanZombie_1 {};
	class RyanZombieCrawler7 : EPOCH_RyanZombie_1 {};
	class RyanZombieCrawler8 : EPOCH_RyanZombie_1 {};
	class RyanZombieCrawler9 : EPOCH_RyanZombie_1 {};
	class RyanZombieCrawler10 : EPOCH_RyanZombie_1 {};
	class RyanZombieCrawler11 : EPOCH_RyanZombie_1 {};
	class RyanZombieCrawler12 : EPOCH_RyanZombie_1 {};
	class RyanZombieCrawler13 : EPOCH_RyanZombie_1 {};
	class RyanZombieCrawler14 : EPOCH_RyanZombie_1 {};
	class RyanZombieCrawler15 : EPOCH_RyanZombie_1 {};
	class RyanZombieCrawler16 : EPOCH_RyanZombie_1 {};
	class RyanZombieCrawler17 : EPOCH_RyanZombie_1 {};
	class RyanZombieCrawler18 : EPOCH_RyanZombie_1 {};
	class RyanZombieCrawler19 : EPOCH_RyanZombie_1 {};
	class RyanZombieCrawler20 : EPOCH_RyanZombie_1 {};
	class RyanZombieCrawler21 : EPOCH_RyanZombie_1 {};
	class RyanZombieCrawler22 : EPOCH_RyanZombie_1 {};
	class RyanZombieCrawler23 : EPOCH_RyanZombie_1 {};
	class RyanZombieCrawler24 : EPOCH_RyanZombie_1 {};
	class RyanZombieCrawler25 : EPOCH_RyanZombie_1 {};
	class RyanZombieCrawler26 : EPOCH_RyanZombie_1 {};
	class RyanZombieCrawler27 : EPOCH_RyanZombie_1 {};
	class RyanZombieCrawler28 : EPOCH_RyanZombie_1 {};
	class RyanZombieCrawler29 : EPOCH_RyanZombie_1 {};
	class RyanZombieCrawler30 : EPOCH_RyanZombie_1 {};
	class RyanZombieCrawler31 : EPOCH_RyanZombie_1 {};
	class RyanZombieCrawler32 : EPOCH_RyanZombie_1 {};

    class IG_Box_s : Default
    {
        interactMode = 4;
    };
    class IG_Box_l : Default
    {
        interactMode = 4;
    };
};

/*[[[end]]]*/
