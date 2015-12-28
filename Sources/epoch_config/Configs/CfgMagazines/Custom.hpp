class ItemHotwire : CA_Magazine {
    picture = "\x\addons\a3_epoch_assets_1\pictures\equip_hotwire_ca.paa";
    displayName = "$STR_EPOCH_VehicleHotwireK_19"; // Vehicle Hotwire Kit
    scope = 2;
    model = "\x\addons\a3_epoch_assets_1\models\hotwire.p3d";
    descriptionShort = "$STR_EPOCH_Usedtounlockveh_24"; // Used to unlock vehicles.
    count = 1;
    mass = 2;
    interactAction = 2;
    interactText = "USE";
};
class ItemKeyKit : CA_Magazine {
    picture = "\x\addons\a3_epoch_assets_1\pictures\equip_keykit_ca.paa";
    displayName = "$STR_EPOCH_KeyMakersKit_14"; // Key Makers Kit
    scope = 2;
    model = "\x\addons\a3_epoch_assets_1\models\keykit.p3d";
    descriptionShort = "$STR_EPOCH_Usedtocraftdupl_29"; // Used to craft duplicate keys.
    count = 1;
    mass = 2;
    interactAction = 2;
    interactText = "USE";
};
class ItemBarrelF : CA_Magazine {
    picture = "\x\addons\a3_epoch_assets_1\pictures\equip_oil_drum_model_ca.paa";
    displayName = "$STR_EPOCH_FuelBarrelFull_18"; // Fuel Barrel (Full)
    scope = 2;
    model = "\x\addons\a3_epoch_assets_1\models\oil_drum_model.p3d";
    descriptionShort = "$STR_EPOCH_55gallonfuelbar_22"; // 55 gallon fuel barrel.
    count = 1;
    mass = 25;
    interactAction = 2;
    interactText = "USE";
};
class ItemBarrelE : CA_Magazine {
    picture = "\x\addons\a3_epoch_assets_1\pictures\equip_oildrum_e_CA.paa";
    displayName = "$STR_EPOCH_FuelBarrelEmpty_19"; // Fuel Barrel (Empty)
    scope = 2;
    model = "\x\addons\a3_epoch_assets_1\models\oil_drum_model.p3d";
    descriptionShort = "$STR_EPOCH_Empty55gallonfu_28"; // Empty 55 gallon fuel barrel.
    count = 1;
    mass = 25;
    interactAction = 2;
    interactText = "USE";
};
class ItemPipe : CA_Magazine {
    picture = "\x\addons\a3_epoch_assets_1\pictures\equip_pipe_CA.paa";
    displayName = "$STR_EPOCH_Pipes_5"; // Pipes
    scope = 2;
    model = "\x\addons\a3_epoch_assets_1\models\pipe.p3d";
    descriptionShort = "$STR_EPOCH_Smallpileofmeta_26"; // Small pile of metal pipes.
    count = 1;
    mass = 15;
};
class ItemKey : CA_Magazine {
    picture = "\x\addons\a3_epoch_assets_1\pictures\equip_key_CA.paa";
    displayName = "$STR_EPOCH_Key_3"; // Key
    scope = 2;
    model = "\x\addons\a3_epoch_assets_1\models\key.p3d";
    descriptionShort = "$STR_EPOCH_Keyusedinalock_19"; // Key used in a lock.
    count = 1;
    mass = 1;
    interactAction = 2;
    interactText = "USE";
};
class ItemKeyBlue : ItemKey {
    picture = "\x\addons\a3_epoch_assets_1\pictures\equip_key_CA_blue.paa";
    displayName = "$STR_EPOCH_KeyBlue_10"; // Key (Blue)
    model = "\x\addons\a3_epoch_assets_1\models\key_blue.p3d";
};
class ItemKeyGreen : ItemKey {
    picture = "\x\addons\a3_epoch_assets_1\pictures\equip_key_CA_green.paa";
    displayName = "$STR_EPOCH_KeyGreen_11"; // Key (Green)
    model = "\x\addons\a3_epoch_assets_1\models\key_green.p3d";
};
class ItemKeyRed : ItemKey {
    picture = "\x\addons\a3_epoch_assets_1\pictures\equip_key_CA_red.paa";
    displayName = "$STR_EPOCH_KeyRed_9"; // Key (Red)
    model = "\x\addons\a3_epoch_assets_1\models\key_red.p3d";
};
class ItemKeyYellow : ItemKey {
    picture = "\x\addons\a3_epoch_assets_1\pictures\equip_key_CA_yellow.paa";
    displayName = "$STR_EPOCH_KeyYellow_12"; // Key (Yellow)
    model = "\x\addons\a3_epoch_assets_1\models\key_yellow.p3d";
};
class ItemDoc1 : CA_Magazine {
    picture = "\x\addons\a3_epoch_assets_1\pictures\equip_child1_ca.paa";
    displayName = "$STR_EPOCH_Book_4"; // Book
    scope = 2;
    model = "\x\addons\a3_epoch_assets_1\models\doc_child1.p3d";
    descriptionShort = "$STR_EPOCH_Book_4"; // Book
    count = 1;
    mass = 1;
    interactAction = -1;
    interactText = "READ";
};
class ItemDoc2 : ItemDoc1 {
    picture = "\x\addons\a3_epoch_assets_1\pictures\equip_child2_ca.paa";
    displayName = "$STR_EPOCH_Book_4"; // Book
    scope = 2;
    model = "\x\addons\a3_epoch_assets_1\models\doc_child2.p3d";
};
