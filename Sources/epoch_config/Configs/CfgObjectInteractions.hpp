class CfgObjectInteractions {
    class Default {
        interactMode = 0;
        distance = 0;
    	toxicChance = 0;
    	bleedChance = 0;
    	bloodpChance = 0;
    	fatigueChance = 0;
    	bleedAmount = 0;
    	bloodpAmount = 0;
    	soundEffect[] = {};
    	soundEffectGlobal = -1;
    	animationEffect[] = {};
    	animationEffectGlobal = -1;
    	canSee = "false";
    	ppEffect = 0;
    };
    class Land_MPS_EPOCH : Default {};
    class container_epoch : Default {};
    class PlotPole_EPOCH : Default {
        interactMode = 1;
    };
    class Epoch_Female_F : Default {
        interactMode = 2;
    };
    class Epoch_Male_F : Default {
        interactMode = 2;
    };
    class C_man_1 : Default {
        interactMode = 2;
    };
    class SapperHead_SIM_EPOCH : Default {
        interactMode = 0;
    };
    class SapperCorpse_SIM_EPOCH : Default {
        interactMode = 0;
    };

    class Snake_random_EPOCH : Default {
        distance = 3;
        toxicChance = 0.2;
        bloodpChance = 1;
        fatigueChance = 0.5;
        bleedAmount = 30;
        bloodpAmount = 3;
        soundEffect[] = {"snake_bite0"};
        canSee = "!(lineIntersects[eyePos _unit, aimPos _target, _unit, _target])";
        ppEffect = 0;
    };
    class Snake2_random_EPOCH : Default {
        distance = 3;
        toxicChance = 0.1;
        bloodpChance = 1;
        fatigueChance = 0.5;
        bleedAmount = 30;
        bloodpAmount = 3;
        soundEffect[] = {"snake_bite0"};
        canSee = "!(lineIntersects[eyePos _unit, aimPos _target, _unit, _target])";
        ppEffect = 0;
    };
    class GreatWhite_F : Default {
        distance = 6;
        toxicChance = 0;
        bleedChance = 1;
        bloodpChance = 1;
        fatigueChance = 1;
        bleedAmount = 100;
        bloodpAmount = 3;
        canSee = "true";
        ppEffect = 0;
    };
    class SmokeShellCustom : Default {
        distance = 6;
        toxicChance = 1;
        bleedChance = 0;
        bloodpChance = 1;
        fatigueChance = 1;
        bleedAmount = 0;
        bloodpAmount = 3;
        canSee = "true";
        ppEffect = 0;
    };
    class Epoch_Cloak_F : Default {
        distance = 30;
        toxicChance = 0;
        bloodpChance = 0.9;
        fatigueChance = 0.5;
        bleedAmount = 66;
        bloodpAmount = 3;
        soundEffect[] = {"cultist_nearby"};
        canSee = "!(lineIntersects[eyePos _unit, aimPos _target, _unit, _target])";
        ppEffect = 1;
    };
    class EPOCH_RyanZombie_1 : Default {
        distance = 3;
        toxicChance = 0.1;
        bloodpChance = 0.9;
        fatigueChance = 0.4;
        bleedAmount = 30;
        bloodpAmount = 3;
        soundEffect[] = {{"ryanzombies\sounds\attack1.ogg",400}, {"ryanzombies\sounds\attack2.ogg",400}, {"ryanzombies\sounds\attack3.ogg",400}, {"ryanzombies\sounds\attack4.ogg",400}, {"ryanzombies\sounds\attack5.ogg",400}};
        soundEffectGlobal = 1;
        animationEffect[] = {"AwopPercMstpSgthWnonDnon_throw"};
        animationEffectGlobal = 3;
        canSee = "!(lineIntersects[eyePos _unit, aimPos _target, _unit, _target])";
        ppEffect = 0;
    };
    class EPOCH_RyanZombie_2 : EPOCH_RyanZombie_1 {};
    class EPOCH_RyanZombie_3 : EPOCH_RyanZombie_1 {};
    class EPOCH_RyanZombie_4 : EPOCH_RyanZombie_1 {};
    class EPOCH_RyanZombie_5 : EPOCH_RyanZombie_1 {};
};
