class ItemHotwire : CA_Magazine { 
    picture = "\x\addons\a3_epoch_assets_1\pictures\equip_hotwire_ca.paa";
    displayName = "$STR_EPOCH_ItemHotwire_displayName"; // Vehicle Hotwire Kit
    scope = 2;
    model = "\x\addons\a3_epoch_assets_1\models\hotwire.p3d";
    descriptionShort = "$STR_EPOCH_ItemHotwire_descriptionShort"; // "; // Used to unlock vehicles.
    count = 1;
    mass = 2;
    interactAction = 2;
    interactText = "USE";
};
class ItemKeyKit : CA_Magazine { 
    picture = "\x\addons\a3_epoch_assets_1\pictures\equip_keykit_ca.paa";
    displayName = "$STR_EPOCH_ItemKeyKit_displayName"; // Key Makers Kit
    scope = 2;
    model = "\x\addons\a3_epoch_assets_1\models\keykit.p3d";
    descriptionShort = "$STR_EPOCH_ItemKeyKit_descriptionShort"; // "; // Used to craft duplicate keys.
    count = 1;
    mass = 2;
    interactAction = 2;
    interactText = "USE";
};
class ItemBarrelF : CA_Magazine { 
    picture = "\x\addons\a3_epoch_assets_1\pictures\equip_oil_drum_model_ca.paa";
    displayName = "$STR_EPOCH_ItemBarrelF_displayName"; // Fuel Barrel (Full)
    scope = 2;
    model = "\x\addons\a3_epoch_assets_1\models\oil_drum_model.p3d";
    descriptionShort = "$STR_EPOCH_ItemBarrelF_descriptionShort"; // "; // 55 gallon fuel barrel.
    count = 1;
    mass = 250;
    interactAction = 4;
    interactText = "FILL";
    interactAttributes[] = {210};
    interactReturnOnUse = "ItemBarrelE";
};
class ItemBarrelE : CA_Magazine { 
    picture = "\x\addons\a3_epoch_assets_1\pictures\equip_oildrum_e_CA.paa";
    displayName = "$STR_EPOCH_ItemBarrelE_displayName"; // Fuel Barrel (Empty)
    scope = 2;
    model = "\x\addons\a3_epoch_assets_1\models\oil_drum_model.p3d";
    descriptionShort = "$STR_EPOCH_ItemBarrelE_descriptionShort"; // "; // Empty 55 gallon fuel barrel.
    count = 1;
    mass = 25;
    interactAction = 5;
    interactText = "SIPHON";
    interactAttributes[] = {210};
    interactReturnOnUse = "ItemBarrelF";
};
class ItemPipe : CA_Magazine { 
    picture = "\x\addons\a3_epoch_assets_1\pictures\equip_pipe_CA.paa";
    displayName = "$STR_EPOCH_ItemPipe_displayName"; // Pipes
    scope = 2;
    model = "\x\addons\a3_epoch_assets_1\models\pipe.p3d";
    descriptionShort = "$STR_EPOCH_ItemPipe_descriptionShort"; // "; // Small pile of metal pipes.
    count = 1;
    mass = 15;
};
class ItemKey : CA_Magazine { 
    picture = "\x\addons\a3_epoch_assets_1\pictures\equip_key_CA.paa";
    displayName = "$STR_EPOCH_ItemKey_displayName"; // Key
    scope = 2;
    model = "\x\addons\a3_epoch_assets_1\models\key.p3d";
    descriptionShort = "$STR_EPOCH_ItemKey_descriptionShort"; // "; // Key used in a lock.
    count = 1;
    mass = 1;
    interactAction = 2;
    interactText = "USE";
};
class ItemKeyBlue : ItemKey { 
    picture = "\x\addons\a3_epoch_assets_1\pictures\equip_key_CA_blue.paa";
    displayName = "$STR_EPOCH_ItemKeyBlue_displayName"; // Key (Blue)
    model = "\x\addons\a3_epoch_assets_1\models\key_blue.p3d";
};
class ItemKeyGreen : ItemKey { 
    picture = "\x\addons\a3_epoch_assets_1\pictures\equip_key_CA_green.paa";
    displayName = "$STR_EPOCH_ItemKeyGreen_displayName"; // Key (Green)
    model = "\x\addons\a3_epoch_assets_1\models\key_green.p3d";
};
class ItemKeyRed : ItemKey { 
    picture = "\x\addons\a3_epoch_assets_1\pictures\equip_key_CA_red.paa";
    displayName = "$STR_EPOCH_ItemKeyRed_displayName"; // Key (Red)
    model = "\x\addons\a3_epoch_assets_1\models\key_red.p3d";
};
class ItemKeyYellow : ItemKey { 
    picture = "\x\addons\a3_epoch_assets_1\pictures\equip_key_CA_yellow.paa";
    displayName = "$STR_EPOCH_ItemKeyYellow_displayName"; // Key (Yellow)
    model = "\x\addons\a3_epoch_assets_1\models\key_yellow.p3d";
};
class ItemDoc1 : CA_Magazine { 
    picture = "\x\addons\a3_epoch_assets_1\pictures\equip_child1_ca.paa";
    displayName = "$STR_EPOCH_ItemDoc1_displayName"; // Book
    scope = 2;
    model = "\x\addons\a3_epoch_assets_1\models\doc_child1.p3d";
    descriptionShort = "$STR_EPOCH_ItemDoc1_descriptionShort"; // "; // Book
    count = 1;
    mass = 1;
    interactAction = -1;
    interactText = "READ";
};
class ItemDoc2 : ItemDoc1 { 
    picture = "\x\addons\a3_epoch_assets_1\pictures\equip_child2_ca.paa";
    displayName = "$STR_EPOCH_ItemDoc2_displayName"; // Book
    scope = 2;
    model = "\x\addons\a3_epoch_assets_1\models\doc_child2.p3d";
};
class ItemDoc3 : ItemDoc1 { 
    picture = "\x\addons\a3_epoch_assets_1\pictures\equip_deaths_ca.paa";
    displayName = "$STR_EPOCH_ItemDoc3_displayName"; // Book
    scope = 2;
    model = "\x\addons\a3_epoch_assets_1\models\doc_deaths.p3d";
};
class ItemDoc4 : ItemDoc1 { 
    picture = "\x\addons\a3_epoch_assets_1\pictures\equip_doc_generic_ca.paa";
    displayName = "$STR_EPOCH_ItemDoc4_displayName"; // Book
    scope = 2;
    model = "\x\addons\a3_epoch_assets_1\models\doc_generic.p3d";
};
class ItemDoc5 : ItemDoc1 { 
    picture = "\x\addons\a3_epoch_assets_1\pictures\equip_doc_letter_ca.paa";
    displayName = "$STR_EPOCH_ItemDoc5_displayName"; // Letter
    scope = 2;
    model = "\x\addons\a3_epoch_assets_1\models\doc_letter.p3d";
};
class ItemDoc6 : ItemDoc1 { 
    picture = "\x\addons\a3_epoch_assets_1\pictures\equip_doc_ramp_ca.paa";
    displayName = "$STR_EPOCH_ItemDoc6_displayName"; // Book
    scope = 2;
    model = "\x\addons\a3_epoch_assets_1\models\doc_ramp.p3d";
};
class ItemDoc7 : ItemDoc1 { 
    picture = "\x\addons\a3_epoch_assets_1\pictures\equip_child2_ca.paa";
    displayName = "$STR_EPOCH_ItemDoc7_displayName"; // Letter
    scope = 2;
    model = "\x\addons\a3_epoch_assets_1\models\doc_trashy1.p3d";
};
class ItemDoc8 : ItemDoc1 { 
    picture = "\x\addons\a3_epoch_assets_1\pictures\equip_child2_ca.paa";
    displayName = "$STR_EPOCH_ItemDoc8_displayName"; // Letter
    scope = 2;
    model = "\x\addons\a3_epoch_assets_1\models\doc_trashy2.p3d";
};
class ItemVehDoc1 : ItemDoc1 { 
    picture = "\x\addons\a3_epoch_assets_1\pictures\equip_docup1_ca.paa";
    displayName = "$STR_EPOCH_ItemVehDoc1_displayName"; // Vehicle Manual I
    scope = 2;
    model = "\x\addons\a3_epoch_assets_1\models\doc_Up1.p3d";
};
class ItemVehDoc2 : ItemDoc1 { 
    picture = "\x\addons\a3_epoch_assets_1\pictures\equip_docup2_ca.paa";
    displayName = "$STR_EPOCH_ItemVehDoc2_displayName"; // Vehicle Manual II
    scope = 2;
    model = "\x\addons\a3_epoch_assets_1\models\doc_Up2.p3d";
};
class ItemVehDoc3 : ItemDoc1 { 
    picture = "\x\addons\a3_epoch_assets_1\pictures\equip_docup3_ca.paa";
    displayName = "$STR_EPOCH_ItemVehDoc3_displayName"; // Vehicle Manual III
    scope = 2;
    model = "\x\addons\a3_epoch_assets_1\models\doc_Up3.p3d";
};
class ItemVehDoc4 : ItemDoc1 { 
    picture = "\x\addons\a3_epoch_assets_1\pictures\equip_docup4_ca.paa";
    displayName = "$STR_EPOCH_ItemVehDoc4_displayName"; // Vehicle Manual IV
    scope = 2;
    model = "\x\addons\a3_epoch_assets_1\models\doc_Up4.p3d";
};
class ItemBulb : CA_Magazine { 
    picture = "\x\addons\a3_epoch_assets_1\pictures\equip_bulb_CA.paa";
    displayName = "$STR_EPOCH_ItemBulb_displayName"; // Light Bulb
    scope = 2;
    model = "\x\addons\a3_epoch_assets_1\models\bulb.p3d";
    descriptionShort = "$STR_EPOCH_ItemBulb_descriptionShort"; // "; // Light Bulb in factory package. Gives off light when powered.
    count = 1;
    mass = 1;
};
class ItemBurlap : CA_Magazine { 
    picture = "\x\addons\a3_epoch_assets_1\pictures\equip_burlap_ca.paa";
    displayName = "$STR_EPOCH_ItemBurlap_displayName"; // Burlap
    scope = 2;
    model = "\x\addons\a3_epoch_assets_1\models\burlap.p3d";
    descriptionShort = "$STR_EPOCH_ItemBurlap_descriptionShort"; // "; // Woven fabric made from plant fibers.
    count = 1;
    mass = 1;
};
class ItemBriefcaseE : CA_Magazine { 
    picture = "\x\addons\a3_epoch_assets_1\pictures\equip_briefcase_E_CA.paa";
    displayName = "$STR_EPOCH_ItemBriefcaseE_displayName"; // Empty Briefcase
    scope = 2;
    model = "\x\addons\a3_epoch_assets_1\models\briefcase.p3d";
    descriptionShort = "$STR_EPOCH_ItemBriefcaseE_descriptionShort"; // "; // A rectangular container, for carrying books and papers.
    count = 1;
    mass = 1;
};
class ItemAluminumBar : CA_Magazine { 
    picture = "\x\addons\a3_epoch_assets_1\pictures\equip_alum_bar_CA.paa";
    displayName = "$STR_EPOCH_ItemAluminumBar_displayName"; // Aluminum Bar (1oz)
    scope = 2;
    model = "\x\addons\a3_epoch_assets_1\models\aluminum_bar.p3d";
    descriptionShort = "$STR_EPOCH_ItemAluminumBar_descriptionShort"; // "; // Aluminum Bar (1oz)
    count = 1;
    mass = 1;
};
class ItemCopperBar : CA_Magazine { 
    picture = "\x\addons\a3_epoch_assets_1\pictures\equip_copper_bar_CA.paa";
    displayName = "$STR_EPOCH_ItemCopperBar_displayName"; // Copper Bar (1oz)
    scope = 2;
    model = "\x\addons\a3_epoch_assets_1\models\copper_bar.p3d";
    descriptionShort = "$STR_EPOCH_ItemCopperBar_descriptionShort"; // "; // Copper Bar (1oz)
    count = 1;
    mass = 1;
};
class ItemTinBar : CA_Magazine { 
    picture = "\x\addons\a3_epoch_assets_1\pictures\equip_tin_bar_CA.paa";
    displayName = "$STR_EPOCH_ItemTinBar_displayName"; // Tin Bar (1oz)
    scope = 2;
    model = "\x\addons\a3_epoch_assets_1\models\tin_bar.p3d";
    descriptionShort = "$STR_EPOCH_ItemTinBar_descriptionShort"; // "; // Tin Bar (1oz)
    count = 1;
    mass = 1;
};
class ItemPlywood : CA_Magazine { 
    picture = "\x\addons\a3_epoch_assets_1\pictures\equip_plywood_CA.paa";
    displayName = "$STR_EPOCH_ItemPlywood_displayName"; // Plywood
    scope = 2;
    model = "\x\addons\a3_epoch_assets_1\models\plywood.p3d";
    descriptionShort = "$STR_EPOCH_ItemPlywood_descriptionShort"; // "; // Plywood Sheets
    count = 1;
    mass = 1;
};
class ItemPlywoodPack : CA_Magazine { 
    picture = "\x\addons\a3_epoch_assets_1\pictures\equip_plywood_pack_CA.paa";
    displayName = "$STR_EPOCH_ItemPlywoodPack_displayName"; // Plywood Pack
    scope = 2;
    model = "\x\addons\a3_epoch_assets_1\models\plywood_pack.p3d";
    descriptionShort = "$STR_EPOCH_ItemPlywoodPack_descriptionShort"; // "; // Stack of Plywood Sheets
    count = 1;
    mass = 1;
};
class ItemComboLock : CA_Magazine { 
    picture = "\x\addons\a3_epoch_assets_1\pictures\equip_combolock_ca.paa";
    displayName = "$STR_EPOCH_ItemComboLock_displayName"; // Combination Lock
    scope = 2;
    model = "\x\addons\a3_epoch_assets_1\models\combo_lock_mag.p3d";
    descriptionShort = "$STR_EPOCH_ItemComboLock_descriptionShort"; // "; // Combination Lock
    count = 1;
    mass = 1;
};
class Item_AssaultPack_cbr : CA_Magazine { 
    picture = "\x\addons\a3_epoch_assets\textures\backpack\gear_packedBag_ca.paa";
    displayName = "$STR_A3_B_AssaultPack_cbr0";
    scope = 2;
    model = "\x\addons\a3_epoch_assets\models\PackedBag.p3d";
    descriptionShort = "$STR_EPOCH_Item_AssaultPack_cbr_descriptionShort"; // "; // Packed Backpack
    count = 1;
    mass = 20;
    interactAction = 14;
    interactText = "UNPACK";
    interactReturnOnUse = "B_AssaultPack_cbr";
};
class Item_AssaultPack_dgtl : CA_Magazine { 
    picture = "\x\addons\a3_epoch_assets\textures\backpack\gear_packedBag_ca.paa";
    displayName = "$STR_A3_B_AssaultPack_dgtl0";
    scope = 2;
    model = "\x\addons\a3_epoch_assets\models\PackedBag.p3d";
    descriptionShort = "$STR_EPOCH_Item_AssaultPack_dgtl_descriptionShort"; // "; // Packed Backpack
    count = 1;
    mass = 20;
    interactAction = 14;
    interactText = "UNPACK";
    interactReturnOnUse = "B_AssaultPack_dgtl";
};
class Item_AssaultPack_khk : CA_Magazine { 
    picture = "\x\addons\a3_epoch_assets\textures\backpack\gear_packedBag_ca.paa";
    displayName = "$STR_A3_B_AssaultPack_khk0";
    scope = 2;
    model = "\x\addons\a3_epoch_assets\models\PackedBag.p3d";
    descriptionShort = "$STR_EPOCH_Item_AssaultPack_khk_descriptionShort"; // "; // Packed Backpack
    count = 1;
    mass = 20;
    interactAction = 14;
    interactText = "UNPACK";
    interactReturnOnUse = "B_AssaultPack_khk";
};
class Item_AssaultPack_mcamo : CA_Magazine { 
    picture = "\x\addons\a3_epoch_assets\textures\backpack\gear_packedBag_ca.paa";
    displayName = "$STR_A3_B_AssaultPack_mcamo0";
    scope = 2;
    model = "\x\addons\a3_epoch_assets\models\PackedBag.p3d";
    descriptionShort = "$STR_EPOCH_Item_AssaultPack_mcamo_descriptionShort"; // "; // Packed Backpack
    count = 1;
    mass = 20;
    interactAction = 14;
    interactText = "UNPACK";
    interactReturnOnUse = "B_AssaultPack_mcamo";
};
class Item_AssaultPack_ocamo : CA_Magazine { 
    picture = "\x\addons\a3_epoch_assets\textures\backpack\gear_packedBag_ca.paa";
    displayName = "$STR_A3_B_AssaultPack_ocamo0";
    scope = 2;
    model = "\x\addons\a3_epoch_assets\models\PackedBag.p3d";
    descriptionShort = "$STR_EPOCH_Item_AssaultPack_ocamo_descriptionShort"; // "; // Packed Backpack
    count = 1;
    mass = 20;
    interactAction = 14;
    interactText = "UNPACK";
    interactReturnOnUse = "B_AssaultPack_ocamo";
};
class Item_AssaultPack_rgr : CA_Magazine { 
    picture = "\x\addons\a3_epoch_assets\textures\backpack\gear_packedBag_ca.paa";
    displayName = "$STR_A3_B_AssaultPack_rgr0";
    scope = 2;
    model = "\x\addons\a3_epoch_assets\models\PackedBag.p3d";
    descriptionShort = "$STR_EPOCH_Item_AssaultPack_rgr_descriptionShort"; // "; // Packed Backpack
    count = 1;
    mass = 20;
    interactAction = 14;
    interactText = "UNPACK";
    interactReturnOnUse = "B_AssaultPack_rgr";
};
class Item_AssaultPack_sgg : CA_Magazine { 
    picture = "\x\addons\a3_epoch_assets\textures\backpack\gear_packedBag_ca.paa";
    displayName = "$STR_A3_B_AssaultPack_sgg0";
    scope = 2;
    model = "\x\addons\a3_epoch_assets\models\PackedBag.p3d";
    descriptionShort = "$STR_EPOCH_Item_AssaultPack_sgg_descriptionShort"; // "; // Packed Backpack
    count = 1;
    mass = 20;
    interactAction = 14;
    interactText = "UNPACK";
    interactReturnOnUse = "B_AssaultPack_sgg";
};
class Item_AssaultPack_blk : CA_Magazine { 
    picture = "\x\addons\a3_epoch_assets\textures\backpack\gear_packedBag_ca.paa";
    displayName = "$STR_A3_B_AssaultPack_blk0";
    scope = 2;
    model = "\x\addons\a3_epoch_assets\models\PackedBag.p3d";
    descriptionShort = "$STR_EPOCH_Item_AssaultPack_blk_descriptionShort"; // "; // Packed Backpack
    count = 1;
    mass = 20;
    interactAction = 14;
    interactText = "UNPACK";
    interactReturnOnUse = "B_AssaultPack_blk";
};
class Item_Carryall_cbr : CA_Magazine { 
    picture = "\x\addons\a3_epoch_assets\textures\backpack\gear_packedBag_ca.paa";
    displayName = "$STR_A3_B_Carryall_cbr0";
    scope = 2;
    model = "\x\addons\a3_epoch_assets\models\PackedBag.p3d";
    descriptionShort = "$STR_EPOCH_Item_Carryall_cbr_descriptionShort"; // "; // Packed Backpack
    count = 1;
    mass = 60;
    interactAction = 14;
    interactText = "UNPACK";
    interactReturnOnUse = "B_Carryall_cbr";
};
class Item_Carryall_khk : CA_Magazine { 
    picture = "\x\addons\a3_epoch_assets\textures\backpack\gear_packedBag_ca.paa";
    displayName = "$STR_A3_B_Carryall_khk0";
    scope = 2;
    model = "\x\addons\a3_epoch_assets\models\PackedBag.p3d";
    descriptionShort = "$STR_EPOCH_Item_Carryall_khk_descriptionShort"; // "; // Packed Backpack
    count = 1;
    mass = 60;
    interactAction = 14;
    interactText = "UNPACK";
    interactReturnOnUse = "B_Carryall_khk";
};
class Item_Carryall_mcamo : CA_Magazine { 
    picture = "\x\addons\a3_epoch_assets\textures\backpack\gear_packedBag_ca.paa";
    displayName = "$STR_A3_B_Carryall_mcamo0";
    scope = 2;
    model = "\x\addons\a3_epoch_assets\models\PackedBag.p3d";
    descriptionShort = "$STR_EPOCH_Item_Carryall_mcamo_descriptionShort"; // "; // Packed Backpack
    count = 1;
    mass = 60;
    interactAction = 14;
    interactText = "UNPACK";
    interactReturnOnUse = "B_Carryall_mcamo";
};
class Item_Carryall_ocamo : CA_Magazine { 
    picture = "\x\addons\a3_epoch_assets\textures\backpack\gear_packedBag_ca.paa";
    displayName = "$STR_A3_B_Carryall_ocamo0";
    scope = 2;
    model = "\x\addons\a3_epoch_assets\models\PackedBag.p3d";
    descriptionShort = "$STR_EPOCH_Item_Carryall_ocamo_descriptionShort"; // "; // Packed Backpack
    count = 1;
    mass = 60;
    interactAction = 14;
    interactText = "UNPACK";
    interactReturnOnUse = "B_Carryall_ocamo";
};
class Item_Carryall_oli : CA_Magazine { 
    picture = "\x\addons\a3_epoch_assets\textures\backpack\gear_packedBag_ca.paa";
    displayName = "$STR_A3_B_Carryall_oli0";
    scope = 2;
    model = "\x\addons\a3_epoch_assets\models\PackedBag.p3d";
    descriptionShort = "$STR_EPOCH_Item_Carryall_oli_descriptionShort"; // "; // Packed Backpack
    count = 1;
    mass = 60;
    interactAction = 14;
    interactText = "UNPACK";
    interactReturnOnUse = "B_Carryall_oli";
};
class Item_Carryall_oucamo : CA_Magazine { 
    picture = "\x\addons\a3_epoch_assets\textures\backpack\gear_packedBag_ca.paa";
    displayName = "$STR_A3_B_Carryall_oucamo0";
    scope = 2;
    model = "\x\addons\a3_epoch_assets\models\PackedBag.p3d";
    descriptionShort = "$STR_EPOCH_Item_Carryall_oucamo_descriptionShort"; // "; // Packed Backpack
    count = 1;
    mass = 60;
    interactAction = 14;
    interactText = "UNPACK";
    interactReturnOnUse = "B_Carryall_oucamo";
};
class Item_FieldPack_blk : CA_Magazine { 
    picture = "\x\addons\a3_epoch_assets\textures\backpack\gear_packedBag_ca.paa";
    displayName = "$STR_A3_B_FieldPack_blk0";
    scope = 2;
    model = "\x\addons\a3_epoch_assets\models\PackedBag.p3d";
    descriptionShort = "$STR_EPOCH_Item_FieldPack_blk_descriptionShort"; // "; // Packed Backpack
    count = 1;
    mass = 30;
    interactAction = 14;
    interactText = "UNPACK";
    interactReturnOnUse = "B_FieldPack_blk";
};
class Item_FieldPack_cbr : CA_Magazine { 
    picture = "\x\addons\a3_epoch_assets\textures\backpack\gear_packedBag_ca.paa";
    displayName = "$STR_A3_B_FieldPack_cbr0";
    scope = 2;
    model = "\x\addons\a3_epoch_assets\models\PackedBag.p3d";
    descriptionShort = "$STR_EPOCH_Item_FieldPack_cbr_descriptionShort"; // "; // Packed Backpack
    count = 1;
    mass = 30;
    interactAction = 14;
    interactText = "UNPACK";
    interactReturnOnUse = "B_FieldPack_cbr";
};
class Item_FieldPack_khk : CA_Magazine { 
    picture = "\x\addons\a3_epoch_assets\textures\backpack\gear_packedBag_ca.paa";
    displayName = "$STR_A3_B_FieldPack_khk0";
    scope = 2;
    model = "\x\addons\a3_epoch_assets\models\PackedBag.p3d";
    descriptionShort = "$STR_EPOCH_Item_FieldPack_khk_descriptionShort"; // "; // Packed Backpack
    count = 1;
    mass = 30;
    interactAction = 14;
    interactText = "UNPACK";
    interactReturnOnUse = "B_FieldPack_khk";
};
class Item_FieldPack_ocamo : CA_Magazine { 
    picture = "\x\addons\a3_epoch_assets\textures\backpack\gear_packedBag_ca.paa";
    displayName = "$STR_A3_B_FieldPack_ocamo0";
    scope = 2;
    model = "\x\addons\a3_epoch_assets\models\PackedBag.p3d";
    descriptionShort = "$STR_EPOCH_Item_FieldPack_ocamo_descriptionShort"; // "; // Packed Backpack
    count = 1;
    mass = 30;
    interactAction = 14;
    interactText = "UNPACK";
    interactReturnOnUse = "B_FieldPack_ocamo";
};
class Item_FieldPack_oli : CA_Magazine { 
    picture = "\x\addons\a3_epoch_assets\textures\backpack\gear_packedBag_ca.paa";
    displayName = "$STR_A3_B_FieldPack_oli0";
    scope = 2;
    model = "\x\addons\a3_epoch_assets\models\PackedBag.p3d";
    descriptionShort = "$STR_EPOCH_Item_FieldPack_oli_descriptionShort"; // "; // Packed Backpack
    count = 1;
    mass = 30;
    interactAction = 14;
    interactText = "UNPACK";
    interactReturnOnUse = "B_FieldPack_oli";
};
class Item_FieldPack_oucamo : CA_Magazine { 
    picture = "\x\addons\a3_epoch_assets\textures\backpack\gear_packedBag_ca.paa";
    displayName = "$STR_A3_B_FieldPack_oucamo0";
    scope = 2;
    model = "\x\addons\a3_epoch_assets\models\PackedBag.p3d";
    descriptionShort = "$STR_EPOCH_Item_FieldPack_oucamo_descriptionShort"; // "; // Packed Backpack
    count = 1;
    mass = 30;
    interactAction = 14;
    interactText = "UNPACK";
    interactReturnOnUse = "B_FieldPack_oucamo";
};
class Item_Kitbag_cbr : CA_Magazine { 
    picture = "\x\addons\a3_epoch_assets\textures\backpack\gear_packedBag_ca.paa";
    displayName = "$STR_A3_B_Kitback_cbr0";
    scope = 2;
    model = "\x\addons\a3_epoch_assets\models\PackedBag.p3d";
    descriptionShort = "$STR_EPOCH_Item_Kitbag_cbr_descriptionShort"; // "; // Packed Backpack
    count = 1;
    mass = 50;
    interactAction = 14;
    interactText = "UNPACK";
    interactReturnOnUse = "B_Kitbag_cbr";
};
class Item_Kitbag_mcamo : CA_Magazine { 
    picture = "\x\addons\a3_epoch_assets\textures\backpack\gear_packedBag_ca.paa";
    displayName = "$STR_A3_B_Kitback_mcamo0";
    scope = 2;
    model = "\x\addons\a3_epoch_assets\models\PackedBag.p3d";
    descriptionShort = "$STR_EPOCH_Item_Kitbag_mcamo_descriptionShort"; // "; // Packed Backpack
    count = 1;
    mass = 50;
    interactAction = 14;
    interactText = "UNPACK";
    interactReturnOnUse = "B_Kitbag_mcamo";
};
class Item_Kitbag_rgr : CA_Magazine { 
    picture = "\x\addons\a3_epoch_assets\textures\backpack\gear_packedBag_ca.paa";
    displayName = "$STR_A3_B_Kitback_rgr0";
    scope = 2;
    model = "\x\addons\a3_epoch_assets\models\PackedBag.p3d";
    descriptionShort = "$STR_EPOCH_Item_Kitbag_rgr_descriptionShort"; // "; // Packed Backpack
    count = 1;
    mass = 50;
    interactAction = 14;
    interactText = "UNPACK";
    interactReturnOnUse = "B_Kitbag_rgr";
};
class Item_Kitbag_sgg : CA_Magazine { 
    picture = "\x\addons\a3_epoch_assets\textures\backpack\gear_packedBag_ca.paa";
    displayName = "$STR_A3_B_Kitback_sgg0";
    scope = 2;
    model = "\x\addons\a3_epoch_assets\models\PackedBag.p3d";
    descriptionShort = "$STR_EPOCH_Item_Kitbag_sgg_descriptionShort"; // "; // Packed Backpack
    count = 1;
    mass = 50;
    interactAction = 14;
    interactText = "UNPACK";
    interactReturnOnUse = "B_Kitbag_sgg";
};
class Item_TacticalPack_blk : CA_Magazine { 
    picture = "\x\addons\a3_epoch_assets\textures\backpack\gear_packedBag_ca.paa";
    displayName = "$STR_A3_B_TacticalPack_blk0";
    scope = 2;
    model = "\x\addons\a3_epoch_assets\models\PackedBag.p3d";
    descriptionShort = "$STR_EPOCH_Item_TacticalPack_blk_descriptionShort"; // "; // Packed Backpack
    count = 1;
    mass = 40;
    interactAction = 14;
    interactText = "UNPACK";
    interactReturnOnUse = "B_TacticalPack_blk";
};
class Item_TacticalPack_mcamo : CA_Magazine { 
    picture = "\x\addons\a3_epoch_assets\textures\backpack\gear_packedBag_ca.paa";
    displayName = "$STR_A3_B_TacticalPack_mcamo0";
    scope = 2;
    model = "\x\addons\a3_epoch_assets\models\PackedBag.p3d";
    descriptionShort = "$STR_EPOCH_Item_TacticalPack_mcamo_descriptionShort"; // "; // Packed Backpack
    count = 1;
    mass = 40;
    interactAction = 14;
    interactText = "UNPACK";
    interactReturnOnUse = "B_TacticalPack_mcamo";
};
class Item_TacticalPack_ocamo : CA_Magazine { 
    picture = "\x\addons\a3_epoch_assets\textures\backpack\gear_packedBag_ca.paa";
    displayName = "$STR_A3_B_TacticalPack_ocamo0";
    scope = 2;
    model = "\x\addons\a3_epoch_assets\models\PackedBag.p3d";
    descriptionShort = "$STR_EPOCH_Item_TacticalPack_ocamo_descriptionShort"; // "; // Packed Backpack
    count = 1;
    mass = 40;
    interactAction = 14;
    interactText = "UNPACK";
    interactReturnOnUse = "B_TacticalPack_ocamo";
};
class Item_TacticalPack_oli : CA_Magazine { 
    picture = "\x\addons\a3_epoch_assets\textures\backpack\gear_packedBag_ca.paa";
    displayName = "$STR_A3_B_TacticalPack_oli0";
    scope = 2;
    model = "\x\addons\a3_epoch_assets\models\PackedBag.p3d";
    descriptionShort = "$STR_EPOCH_Item_TacticalPack_oli_descriptionShort"; // "; // Packed Backpack
    count = 1;
    mass = 40;
    interactAction = 14;
    interactText = "UNPACK";
    interactReturnOnUse = "B_TacticalPack_oli";
};
class Item_TacticalPack_rgr : CA_Magazine { 
    picture = "\x\addons\a3_epoch_assets\textures\backpack\gear_packedBag_ca.paa";
    displayName = "$STR_A3_B_TacticalPack_rgr0";
    scope = 2;
    model = "\x\addons\a3_epoch_assets\models\PackedBag.p3d";
    descriptionShort = "$STR_EPOCH_Item_TacticalPack_rgr_descriptionShort"; // "; // Packed Backpack
    count = 1;
    mass = 40;
    interactAction = 14;
    interactText = "UNPACK";
    interactReturnOnUse = "B_TacticalPack_rgr";
};
class Item_smallbackpack_red : CA_Magazine { 
    picture = "\x\addons\a3_epoch_assets\textures\backpack\gear_packedBag_ca.paa";
    displayName = "$STR_EPOCH_Item_smallbackpack_red_displayName"; // Small Backpack (Red)
    scope = 2;
    model = "\x\addons\a3_epoch_assets\models\PackedBag.p3d";
    descriptionShort = "$STR_EPOCH_Item_smallbackpack_red_descriptionShort"; // "; // Packed Backpack
    count = 1;
    mass = 25;
    interactAction = 14;
    interactText = "UNPACK";
    interactReturnOnUse = "smallbackpack_red_epoch";
};
class Item_smallbackpack_green : CA_Magazine { 
    picture = "\x\addons\a3_epoch_assets\textures\backpack\gear_packedBag_ca.paa";
    displayName = "$STR_EPOCH_Item_smallbackpack_green_displayName"; // Small Backpack (Green)
    scope = 2;
    model = "\x\addons\a3_epoch_assets\models\PackedBag.p3d";
    descriptionShort = "$STR_EPOCH_Item_smallbackpack_green_descriptionShort"; // "; // Packed Backpack
    count = 1;
    mass = 25;
    interactAction = 14;
    interactText = "UNPACK";
    interactReturnOnUse = "smallbackpack_green_epoch";
};
class Item_smallbackpack_teal : CA_Magazine { 
    picture = "\x\addons\a3_epoch_assets\textures\backpack\gear_packedBag_ca.paa";
    displayName = "$STR_EPOCH_Item_smallbackpack_teal_displayName"; // Small Backpack (Teal)
    scope = 2;
    model = "\x\addons\a3_epoch_assets\models\PackedBag.p3d";
    descriptionShort = "$STR_EPOCH_Item_smallbackpack_teal_descriptionShort"; // "; // Packed Backpack
    count = 1;
    mass = 25;
    interactAction = 14;
    interactText = "UNPACK";
    interactReturnOnUse = "smallbackpack_teal_epoch";
};
class Item_smallbackpack_pink : CA_Magazine { 
    picture = "\x\addons\a3_epoch_assets\textures\backpack\gear_packedBag_ca.paa";
    displayName = "$STR_EPOCH_Item_smallbackpack_pink_displayName"; // Small Backpack (Pink)
    scope = 2;
    model = "\x\addons\a3_epoch_assets\models\PackedBag.p3d";
    descriptionShort = "$STR_EPOCH_Item_smallbackpack_pink_descriptionShort"; // "; // Packed Backpack
    count = 1;
    mass = 25;
    interactAction = 14;
    interactText = "UNPACK";
    interactReturnOnUse = "smallbackpack_pink_epoch";
};
