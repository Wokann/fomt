// Reference Guide manifest consumed by fomt-text, not compiled directly.
//
// Adding a book:
//   { "new_book", 138, true },
// creates one directory entry and requires both of these article sources:
//   data/text/jp/reference_guide/new_book.cc
//   data/text/us/reference_guide/new_book.cc
// fomt-text derives gGuidePage_new_book from this row and the file paths; do
// not add a manual FOMT_REFERENCE_GUIDE_PAGE(...) declaration to either file.
// The row name and both file names are one shared identifier and must match.
//
// Directory flag: true adds the page to gReferenceGuideTables[]; false still
// generates an independent page but leaves it out of that master table.
//
// ROM order: rom_order is a unique physical-group sort key in the selected
// region.  It need not be consecutive: a removed row leaves a harmless gap,
// which can later receive a new group.
//
// Auxiliary-group example:
//   { "tool_and_item_controls",            8, true  },
//   { "tool_and_item_controls_additional", 9, false }, // US only
// A false row must follow a true group after rom_order sorting.  The generator
// emits text(tool_and_item_controls), text(..._additional), then
// table(tool_and_item_controls), table(..._additional).  Consecutive false
// rows extend the same pattern.
//
// For an exact baseline build, do not omit original rows merely to hide data:
// later bytes would move.  Keep an unsemanticized original page represented
// here until its source is available.
//
// 以下为中文说明：本参考指南清单由 fomt-text 读取，不直接参与 C++ 编译。
//
// 新增图书示例：
//   { "new_book", 138, true },
// 会生成一个目录项，并要求同时存在以下两个文章源：
//   data/text/jp/reference_guide/new_book.cc
//   data/text/us/reference_guide/new_book.cc
// fomt-text 会由该行与文件路径自动推导 gGuidePage_new_book；两个文件中均不应
// 手写 FOMT_REFERENCE_GUIDE_PAGE(...) 声明。该行名称与两个文件名是同一个共享
// 标识，必须完全一致。
//
// 目录标记：true 会加入 gReferenceGuideTables[]；false 仍会生成独立页面，但
// 不加入该总表。
//
// ROM 顺序：rom_order 是所选区域内唯一的物理组排序键；无需连续。删除行后
// 留下的空号没有影响，之后可用于新的物理组。
//
// 附属组示例：
//   { "tool_and_item_controls",            8, true  },
//   { "tool_and_item_controls_additional", 9, false }, // 仅 US
// false 行必须在 rom_order 排序后跟随 true 组。生成器会输出
// text(tool_and_item_controls)、text(..._additional)，然后输出
// table(tool_and_item_controls)、table(..._additional)。连续 false 行会延续
// 同一排列规则。
//
// 精确基线构建时不可仅为隐藏数据而删除原行，否则后续字节会移动；在拥有源文本前
// 应保留该原始页面记录。

struct FomtReferenceGuideBookManifest
{
    char const *name;
    unsigned short rom_order;
    bool include_in_catalog;
};

FomtReferenceGuideBookManifest const gReferenceGuideBooks[] = {
    { "harvest_sprite_minigames", 0, true },
    { "festival_hints", 1, true },
    { "controls", 2, true },
    { "television_controls", 3, true },
    { "message_window_controls", 4, true },
    { "diary_window_controls", 5, true },
    { "town_map_controls", 6, true },
    { "farm_map_controls", 7, true },
    { "tool_and_item_controls", 8, true },
#if defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    { "tool_and_item_controls_additional", 9, false },
#endif
    { "raising_crops", 10, true },
    { "seasonal_crops", 11, true },
    { "mines", 12, true },
    { "how_to_cook", 13, true },
    { "stamina_and_fatigue", 14, true },
    { "sell_price", 15, true },
    { "using_tools", 16, true },
    { "fishing", 17, true },
    { "animal_care", 18, true },
    { "ngc_awl_profiles_takakura", 19, true },
    { "ngc_awl_profiles_romana", 20, true },
    { "ngc_awl_profiles_lumina", 21, true },
    { "ngc_awl_profiles_sebastian", 22, true },
    { "ngc_awl_profiles_wally", 23, true },
    { "ngc_awl_profiles_chris", 24, true },
    { "ngc_awl_profiles_hugh", 25, true },
    { "ngc_awl_profiles_grant", 26, true },
    { "ngc_awl_profiles_samantha", 27, true },
    { "ngc_awl_profiles_kate", 28, true },
    { "ngc_awl_profiles_galen", 29, true },
    { "ngc_awl_profiles_nina", 30, true },
    { "ngc_awl_profiles_daryl", 31, true },
    { "ngc_awl_profiles_gustafa", 32, true },
    { "ngc_awl_profiles_cody", 33, true },
    { "ngc_awl_profiles_kassey", 34, true },
    { "ngc_awl_profiles_patrick", 35, true },
    { "ngc_awl_profiles_murray", 36, true },
    { "ngc_awl_profiles_tim", 37, true },
    { "ngc_awl_profiles_ruby", 38, true },
    { "ngc_awl_profiles_nami", 39, true },
    { "ngc_awl_profiles_rock", 40, true },
    { "ngc_awl_profiles_griffin", 41, true },
    { "ngc_awl_profiles_muffy", 42, true },
    { "ngc_awl_profiles_carter", 43, true },
    { "ngc_awl_profiles_flora", 44, true },
    { "ngc_awl_profiles_vesta", 45, true },
    { "ngc_awl_profiles_marlin", 46, true },
    { "ngc_awl_profiles_celia", 47, true },
    { "ngc_awl_profiles_hardy", 48, true },
    { "ngc_awl_profiles_van", 49, true },
    { "ngc_awl_profiles_mooky", 50, true },
    { "ngc_awl_profiles_child", 51, true },
    { "ngc_awl_profiles_nak", 52, true },
    { "ngc_awl_profiles_nic", 53, true },
    { "ngc_awl_profiles_flak", 54, true },
    { "ngc_awl_profiles_player", 55, true },
    { "cookbook_1", 56, true },
    { "cookbook_2", 57, true },
    { "cookbook_3", 58, true },
    { "cookbook_4", 59, true },
    { "acquiring_kitchen", 60, true },
    { "harvest_sprite_help", 61, true },
    { "saibara_blacksmith", 62, true },
    { "supermarket", 63, true },
    { "woodcutters_house", 64, true },
    { "clinic", 65, true },
    { "aja_winery", 66, true },
    { "dougs_inn", 67, true },
    { "kai_seaside_lodge", 68, true },
    { "poultry_farm", 69, true },
    { "yodel_farm", 70, true },
    { "wons_shop", 71, true },
    { "vans_shop", 72, true },
    { "record_player_instructions", 73, true },
    { "bath_instructions", 74, true },
    { "vase_instructions", 75, true },
    { "refrigerator", 76, true },
    { "shelf", 77, true },
    { "new_year_card_cliff_first", 80, true },
    { "new_year_card_cliff_second", 81, true },
    { "new_year_card_cliff_and_ann", 82, true },
    { "new_year_card_doctor", 83, true },
    { "new_year_card_doctor_and_elli", 84, true },
    { "new_year_card_mineral_clinic", 85, true },
    { "new_year_card_poultry_farm", 86, true },
    { "new_year_card_poultry_farm_lillia_and_rick", 87, true },
    { "new_year_card_poultry_farm_player_and_popuri", 88, true },
    { "new_year_card_poultry_farm_lillia_rick_and_karen", 89, true },
    { "new_year_card_gray", 90, true },
    { "new_year_card_gray_well_wishes", 91, true },
    { "new_year_card_kai", 92, true },
    { "new_year_card_kai_and_popuri", 93, true },
    { "new_year_card_jeff", 94, true },
    { "new_year_card_saibara", 95, true },
    { "new_year_card_doug", 96, true },
    { "new_year_card_doug_to_player_and_ann", 97, true },
    { "new_year_card_carter", 98, true },
    { "new_year_card_basil_and_anna", 99, true },
    { "new_year_cards_may_and_barley", 100, true },
    { "new_year_card_thomas_and_harris", 101, true },
    { "new_year_card_thomas_and_harris_town_safety", 102, true },
    { "new_year_cards_manna_and_duke", 103, true },
    { "new_year_card_ellen", 104, true },
    { "new_year_card_harvest_sprites", 105, true },
    { "new_year_card_popuri", 106, true },
    { "new_year_card_ann", 107, true },
    { "new_year_card_karen", 108, true },
    { "new_year_card_elli", 109, true },
    { "new_year_card_mary", 110, true },
    { "notice_dougs_inn_store_hours_change", 111, true },
    { "birthday_card_popuri", 112, true },
    { "birthday_card_ann", 113, true },
    { "birthday_card_karen", 114, true },
    { "birthday_card_elli", 115, true },
    { "birthday_card_mary", 116, true },
    { "birthday_card_kai", 117, true },
    { "birthday_card_cliff", 118, true },
    { "birthday_card_doctor", 119, true },
    { "newborn_congratulations_kai_and_popuri", 120, true },
    { "newborn_congratulations_cliff_and_ann", 121, true },
    { "newborn_congratulations_rick_and_karen", 122, true },
    { "newborn_congratulations_doctor_and_elli", 123, true },
    { "newborn_congratulations_mary_and_gray", 124, true },
    { "newborn_congratulations_thomas_and_harris", 125, true },
    { "new_stock_supermarket_strawberry_seeds", 126, true },
    { "new_stock_supermarket_pumpkin_seeds", 127, true },
    { "new_stock_supermarket_spinach_seeds", 128, true },
    { "new_stock_supermarket_blue_feather", 129, true },
    { "new_stock_supermarket_large_rucksack", 130, true },
    { "new_stock_mineral_clinic_bodigizer_xl", 131, true },
    { "new_stock_mineral_clinic_turbojolt_xl", 132, true },
    { "new_stock_saibara_blacksmith_brush", 133, true },
    { "new_stock_saibara_blacksmith_milker", 134, true },
    { "new_stock_saibara_blacksmith_clippers", 135, true },
    { "notice_marys_library_day_off_change", 136, true },
    { "invitation_harvest_sprites_tea_party", 137, true },
    { "staff_credits", 78, true },
    { "useful_controls", 79, true },
};
