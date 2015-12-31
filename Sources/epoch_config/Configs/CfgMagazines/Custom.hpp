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
class ItemDoc3 : ItemDoc1 { 
    picture = "\x\addons\a3_epoch_assets_1\pictures\equip_deaths_ca.paa";
    displayName = "$STR_EPOCH_Book_4"; // Book
    scope = 2;
    model = "\x\addons\a3_epoch_assets_1\models\doc_deaths.p3d";
};
class ItemDoc4 : ItemDoc1 { 
    picture = "\x\addons\a3_epoch_assets_1\pictures\equip_doc_generic_ca.paa";
    displayName = "$STR_EPOCH_Book_4"; // Book
    scope = 2;
    model = "\x\addons\a3_epoch_assets_1\models\doc_generic.p3d";
};
class ItemDoc5 : ItemDoc1 { 
    picture = "\x\addons\a3_epoch_assets_1\pictures\equip_doc_letter_ca.paa";
    displayName = "$STR_EPOCH_Letter_6"; // Letter
    scope = 2;
    model = "\x\addons\a3_epoch_assets_1\models\doc_letter.p3d";
};
class ItemDoc6 : ItemDoc1 { 
    picture = "\x\addons\a3_epoch_assets_1\pictures\equip_doc_ramp_ca.paa";
    displayName = "$STR_EPOCH_Book_4"; // Book
    scope = 2;
    model = "\x\addons\a3_epoch_assets_1\models\doc_ramp.p3d";
};
class ItemDoc7 : ItemDoc1 { 
    picture = "\x\addons\a3_epoch_assets_1\pictures\equip_child2_ca.paa";
    displayName = "$STR_EPOCH_Letter_6"; // Letter
    scope = 2;
    model = "\x\addons\a3_epoch_assets_1\models\doc_trashy1.p3d";
};
class ItemDoc8 : ItemDoc1 { 
    picture = "\x\addons\a3_epoch_assets_1\pictures\equip_child2_ca.paa";
    displayName = "$STR_EPOCH_Letter_6"; // Letter
    scope = 2;
    model = "\x\addons\a3_epoch_assets_1\models\doc_trashy2.p3d";
};
class ItemVehDoc1 : ItemDoc1 { 
    picture = "\x\addons\a3_epoch_assets_1\pictures\equip_docup1_ca.paa";
    displayName = "$STR_EPOCH_VehicleManualI_16"; // Vehicle Manual I
    scope = 2;
    model = "\x\addons\a3_epoch_assets_1\models\doc_Up1.p3d";
};
class ItemVehDoc2 : ItemDoc1 { 
    picture = "\x\addons\a3_epoch_assets_1\pictures\equip_docup2_ca.paa";
    displayName = "$STR_EPOCH_VehicleManualII_17"; // Vehicle Manual II
    scope = 2;
    model = "\x\addons\a3_epoch_assets_1\models\doc_Up2.p3d";
};
class ItemVehDoc3 : ItemDoc1 { 
    picture = "\x\addons\a3_epoch_assets_1\pictures\equip_docup3_ca.paa";
    displayName = "$STR_EPOCH_VehicleManualII_18"; // Vehicle Manual III
    scope = 2;
    model = "\x\addons\a3_epoch_assets_1\models\doc_Up3.p3d";
};
class ItemVehDoc4 : ItemDoc1 { 
    picture = "\x\addons\a3_epoch_assets_1\pictures\equip_docup4_ca.paa";
    displayName = "$STR_EPOCH_VehicleManualII_19"; // Vehicle Manual IIII
    scope = 2;
    model = "\x\addons\a3_epoch_assets_1\models\doc_Up4.p3d";
};
class ItemBulb : CA_Magazine { 
    picture = "\x\addons\a3_epoch_assets_1\pictures\equip_bulb_CA.paa";
    displayName = "$STR_EPOCH_LightBulb_10"; // Light Bulb
    scope = 2;
    model = "\x\addons\a3_epoch_assets_1\models\bulb.p3d";
    descriptionShort = "$STR_EPOCH_LightBulbinfact_60"; // Light Bulb in factory package. Gives off light when powered.
    count = 1;
    mass = 1;
};
class ItemBurlap : CA_Magazine { 
    picture = "\x\addons\a3_epoch_assets_1\pictures\equip_burlap_ca.paa";
    displayName = "$STR_EPOCH_Burlap_6"; // Burlap
    scope = 2;
    model = "\x\addons\a3_epoch_assets_1\models\burlap.p3d";
    descriptionShort = "$STR_EPOCH_Wovenfabricmade_36"; // Woven fabric made from plant fibers.
    count = 1;
    mass = 1;
};
class ItemBriefcaseE : CA_Magazine { 
    picture = "\x\addons\a3_epoch_assets_1\pictures\equip_briefcase_E_CA.paa";
    displayName = "$STR_EPOCH_EmptyBriefcase_15"; // Empty Briefcase
    scope = 2;
    model = "\x\addons\a3_epoch_assets_1\models\briefcase.p3d";
    descriptionShort = "$STR_EPOCH_Arectangularcon_55"; // A rectangular container, for carrying books and papers.
    count = 1;
    mass = 1;
};
class ItemAluminumBar : CA_Magazine { 
    picture = "\x\addons\a3_epoch_assets_1\pictures\equip_alum_bar_CA.paa";
    displayName = "$STR_EPOCH_AluminumBar1oz_18"; // Aluminum Bar (1oz)
    scope = 2;
    model = "\x\addons\a3_epoch_assets_1\models\aluminum_bar.p3d";
    descriptionShort = "$STR_EPOCH_AluminumBar1oz_18"; // Aluminum Bar (1oz)
    count = 1;
    mass = 1;
};
class ItemAluminumBar10oz : CA_Magazine { 
    picture = "\x\addons\a3_epoch_assets_1\pictures\equip_alum_bar_10oz_CA.paa";
    displayName = "$STR_EPOCH_AluminumBar10oz_19"; // Aluminum Bar (10oz)
    scope = 2;
    model = "\x\addons\a3_epoch_assets_1\models\aluminum_bar_10oz.p3d";
    descriptionShort = "$STR_EPOCH_AluminumBar10oz_19"; // Aluminum Bar (10oz)
    count = 1;
    mass = 1;
};
class ItemCopperBar : CA_Magazine { 
    picture = "\x\addons\a3_epoch_assets_1\pictures\equip_copper_bar_CA.paa";
    displayName = "$STR_EPOCH_CopperBar1oz_16"; // Copper Bar (1oz)
    scope = 2;
    model = "\x\addons\a3_epoch_assets_1\models\copper_bar.p3d";
    descriptionShort = "$STR_EPOCH_CopperBar1oz_16"; // Copper Bar (1oz)
    count = 1;
    mass = 1;
};
class ItemCopperBar10oz : CA_Magazine { 
    picture = "\x\addons\a3_epoch_assets_1\pictures\equip_copper_bar_10oz_CA.paa";
    displayName = "$STR_EPOCH_CopperBar10oz_17"; // Copper Bar (10oz)
    scope = 2;
    model = "\x\addons\a3_epoch_assets_1\models\copper_bar_10oz.p3d";
    descriptionShort = "$STR_EPOCH_CopperBar10oz_17"; // Copper Bar (10oz)
    count = 1;
    mass = 1;
};
class ItemTinBar : CA_Magazine { 
    picture = "\x\addons\a3_epoch_assets_1\pictures\equip_tin_bar_CA.paa";
    displayName = "$STR_EPOCH_TinBar1oz_13"; // Tin Bar (1oz)
    scope = 2;
    model = "\x\addons\a3_epoch_assets_1\models\tin_bar.p3d";
    descriptionShort = "$STR_EPOCH_TinBar1oz_13"; // Tin Bar (1oz)
    count = 1;
    mass = 1;
};
class ItemTinBar10oz : CA_Magazine { 
    picture = "\x\addons\a3_epoch_assets_1\pictures\equip_tin_bar_10oz_CA.paa";
    displayName = "$STR_EPOCH_TinBar10oz_14"; // Tin Bar (10oz)
    scope = 2;
    model = "\x\addons\a3_epoch_assets_1\models\tin_bar_10oz.p3d";
    descriptionShort = "$STR_EPOCH_TinBar10oz_14"; // Tin Bar (10oz)
    count = 1;
    mass = 1;
};
class ItemPlywood : CA_Magazine { 
    picture = "\x\addons\a3_epoch_assets_1\pictures\equip_plywood_CA.paa";
    displayName = "$STR_EPOCH_Plywood_7"; // Plywood
    scope = 2;
    model = "\x\addons\a3_epoch_assets_1\models\plywood.p3d";
    descriptionShort = "$STR_EPOCH_PlywoodSheets_14"; // Plywood Sheets
    count = 1;
    mass = 1;
};
class ItemPlywoodPack : CA_Magazine { 
    picture = "\x\addons\a3_epoch_assets_1\pictures\equip_plywood_pack_CA.paa";
    displayName = "$STR_EPOCH_PlywoodPack_12"; // Plywood Pack
    scope = 2;
    model = "\x\addons\a3_epoch_assets_1\models\plywood_pack.p3d";
    descriptionShort = "$STR_EPOCH_StackofPlywoodS_23"; // Stack of Plywood Sheets
    count = 1;
    mass = 1;
};
class ItemComboLock : CA_Magazine { 
    picture = "\x\addons\a3_epoch_assets_1\pictures\equip_combolock_ca.paa";
    displayName = "$STR_EPOCH_CombinationLock_16"; // Combination Lock
    scope = 2;
    model = "\x\addons\a3_epoch_assets_1\models\combo_lock_mag.p3d";
    descriptionShort = "$STR_EPOCH_CombinationLock_16"; // Combination Lock
    count = 1;
    mass = 1;
};
