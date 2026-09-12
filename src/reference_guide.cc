// Reference Guide manifest consumed by fomt-text, not compiled directly.
//
// Adding a one-page book:
//   { "new_book", 137, FOMT_REFERENCE_GUIDE_PAGE_1 },
// creates one directory entry and requires one article source per region:
//   data/text/jp/reference_guide/new_book.cc
//   data/text/us/reference_guide/new_book.cc
// fomt-text derives gReferenceGuide_new_book from this row and the file paths;
// do not add a manual FOMT_REFERENCE_GUIDE_PAGE(...) declaration to an article.
// The row name and article file name are one shared identifier and must match.
//
// A two-page book uses the same text ID for both pages:
//   { "new_book_1", 137, FOMT_REFERENCE_GUIDE_PAGE_1 },
//   { "new_book_2", 137, FOMT_REFERENCE_GUIDE_PAGE_2 },
// The first page enters gReferenceGuideTables[]; the second page is excluded
// from that directory.  PAGE_2 records a physically adjacent, null-terminated
// line-pointer table; it does not by itself add runtime page-turning behavior.
// The generator emits text(new_book_1), text(new_book_2), then
// table(new_book_1), table(new_book_2), preserving the original physical group.
//
// Text ID: this is the selected region's physical article-group sort key, not
// a per-page ID.  It need not be consecutive: a region may omit a localized
// article group, leaving a harmless gap for a group present in another region.
//
// For an exact baseline build, do not omit original rows merely to hide data:
// later bytes would move.  Keep an unsemanticized original page represented
// here until its source is available.
//
// 以下为中文说明：本参考指南清单由 fomt-text 读取，不直接参与 C++ 编译。
//
// 新增单页图书示例：
//   { "new_book", 137, FOMT_REFERENCE_GUIDE_PAGE_1 },
// 会生成一个目录项，并要求每个区域各有一个文章源：
//   data/text/jp/reference_guide/new_book.cc
//   data/text/us/reference_guide/new_book.cc
// fomt-text 会由该行与文件路径自动推导 gReferenceGuide_new_book；文章文件中不应
// 手写 FOMT_REFERENCE_GUIDE_PAGE(...) 声明。该行名称与文章文件名是同一个共享
// 标识，必须完全一致。
//
// 双页图书共用同一个文本 ID：
//   { "new_book_1", 137, FOMT_REFERENCE_GUIDE_PAGE_1 },
//   { "new_book_2", 137, FOMT_REFERENCE_GUIDE_PAGE_2 },
// 第一页会加入 gReferenceGuideTables[]；第二页不进入总目录。PAGE_2 仅表示一个
// 紧接在前页空指针后的独立物理行指针表，本身不会自动添加游戏内翻页行为。生成器会依次输出
// text(new_book_1)、text(new_book_2)、
// table(new_book_1)、table(new_book_2)，保持原始物理组。
//
// 文本 ID：它是所选区域的物理文章组排序键，不是每一页的 ID；无需连续。某区域
// 缺少本地化文章组时留下空号没有影响，可用于其他区域存在的文章组。
//
// 精确基线构建时不可仅为隐藏数据而删除原行，否则后续字节会移动；在拥有源文本前
// 应保留该原始页面记录。

enum FomtReferenceGuidePageType
{
    FOMT_REFERENCE_GUIDE_PAGE_1,
    FOMT_REFERENCE_GUIDE_PAGE_2,
};

struct FomtReferenceGuideBookManifest
{
    char const *name;
    unsigned short text_id;
    FomtReferenceGuidePageType page_type;
};

FomtReferenceGuideBookManifest const gReferenceGuideBooks[] = {
    { "harvest_sprite_minigames", 0, FOMT_REFERENCE_GUIDE_PAGE_1 },
    { "festival_hints", 1, FOMT_REFERENCE_GUIDE_PAGE_1 },
    { "controls", 2, FOMT_REFERENCE_GUIDE_PAGE_1 },
    { "television_controls", 3, FOMT_REFERENCE_GUIDE_PAGE_1 },
    { "message_window_controls", 4, FOMT_REFERENCE_GUIDE_PAGE_1 },
    { "diary_window_controls", 5, FOMT_REFERENCE_GUIDE_PAGE_1 },
    { "town_map_controls", 6, FOMT_REFERENCE_GUIDE_PAGE_1 },
    { "farm_map_controls", 7, FOMT_REFERENCE_GUIDE_PAGE_1 },
    { "tool_and_item_controls_1", 8, FOMT_REFERENCE_GUIDE_PAGE_1 },
#if defined(REGION_US) || defined(REGION_EU)
    { "tool_and_item_controls_2", 8, FOMT_REFERENCE_GUIDE_PAGE_2 },
#endif
    { "raising_crops", 9, FOMT_REFERENCE_GUIDE_PAGE_1 },
    { "seasonal_crops", 10, FOMT_REFERENCE_GUIDE_PAGE_1 },
    { "mines", 11, FOMT_REFERENCE_GUIDE_PAGE_1 },
    { "how_to_cook", 12, FOMT_REFERENCE_GUIDE_PAGE_1 },
    { "stamina_and_fatigue", 13, FOMT_REFERENCE_GUIDE_PAGE_1 },
    { "sell_price", 14, FOMT_REFERENCE_GUIDE_PAGE_1 },
    { "using_tools_1", 15, FOMT_REFERENCE_GUIDE_PAGE_1 },
#if defined(REGION_DE)
    { "using_tools_2", 15, FOMT_REFERENCE_GUIDE_PAGE_2 },
#endif
    { "fishing", 16, FOMT_REFERENCE_GUIDE_PAGE_1 },
    { "animal_care", 17, FOMT_REFERENCE_GUIDE_PAGE_1 },
    { "ngc_awl_profiles_takakura", 18, FOMT_REFERENCE_GUIDE_PAGE_1 },
    { "ngc_awl_profiles_romana", 19, FOMT_REFERENCE_GUIDE_PAGE_1 },
    { "ngc_awl_profiles_lumina", 20, FOMT_REFERENCE_GUIDE_PAGE_1 },
    { "ngc_awl_profiles_sebastian", 21, FOMT_REFERENCE_GUIDE_PAGE_1 },
    { "ngc_awl_profiles_wally", 22, FOMT_REFERENCE_GUIDE_PAGE_1 },
    { "ngc_awl_profiles_chris", 23, FOMT_REFERENCE_GUIDE_PAGE_1 },
    { "ngc_awl_profiles_hugh", 24, FOMT_REFERENCE_GUIDE_PAGE_1 },
    { "ngc_awl_profiles_grant", 25, FOMT_REFERENCE_GUIDE_PAGE_1 },
    { "ngc_awl_profiles_samantha", 26, FOMT_REFERENCE_GUIDE_PAGE_1 },
    { "ngc_awl_profiles_kate", 27, FOMT_REFERENCE_GUIDE_PAGE_1 },
    { "ngc_awl_profiles_galen", 28, FOMT_REFERENCE_GUIDE_PAGE_1 },
    { "ngc_awl_profiles_nina", 29, FOMT_REFERENCE_GUIDE_PAGE_1 },
    { "ngc_awl_profiles_daryl", 30, FOMT_REFERENCE_GUIDE_PAGE_1 },
    { "ngc_awl_profiles_gustafa", 31, FOMT_REFERENCE_GUIDE_PAGE_1 },
    { "ngc_awl_profiles_cody", 32, FOMT_REFERENCE_GUIDE_PAGE_1 },
    { "ngc_awl_profiles_kassey", 33, FOMT_REFERENCE_GUIDE_PAGE_1 },
    { "ngc_awl_profiles_patrick", 34, FOMT_REFERENCE_GUIDE_PAGE_1 },
    { "ngc_awl_profiles_murray", 35, FOMT_REFERENCE_GUIDE_PAGE_1 },
    { "ngc_awl_profiles_tim", 36, FOMT_REFERENCE_GUIDE_PAGE_1 },
    { "ngc_awl_profiles_ruby", 37, FOMT_REFERENCE_GUIDE_PAGE_1 },
    { "ngc_awl_profiles_nami", 38, FOMT_REFERENCE_GUIDE_PAGE_1 },
    { "ngc_awl_profiles_rock", 39, FOMT_REFERENCE_GUIDE_PAGE_1 },
    { "ngc_awl_profiles_griffin", 40, FOMT_REFERENCE_GUIDE_PAGE_1 },
    { "ngc_awl_profiles_muffy", 41, FOMT_REFERENCE_GUIDE_PAGE_1 },
    { "ngc_awl_profiles_carter", 42, FOMT_REFERENCE_GUIDE_PAGE_1 },
    { "ngc_awl_profiles_flora", 43, FOMT_REFERENCE_GUIDE_PAGE_1 },
    { "ngc_awl_profiles_vesta", 44, FOMT_REFERENCE_GUIDE_PAGE_1 },
    { "ngc_awl_profiles_marlin", 45, FOMT_REFERENCE_GUIDE_PAGE_1 },
    { "ngc_awl_profiles_celia", 46, FOMT_REFERENCE_GUIDE_PAGE_1 },
    { "ngc_awl_profiles_hardy", 47, FOMT_REFERENCE_GUIDE_PAGE_1 },
    { "ngc_awl_profiles_van", 48, FOMT_REFERENCE_GUIDE_PAGE_1 },
    { "ngc_awl_profiles_mooky", 49, FOMT_REFERENCE_GUIDE_PAGE_1 },
    { "ngc_awl_profiles_child", 50, FOMT_REFERENCE_GUIDE_PAGE_1 },
    { "ngc_awl_profiles_nak", 51, FOMT_REFERENCE_GUIDE_PAGE_1 },
    { "ngc_awl_profiles_nic", 52, FOMT_REFERENCE_GUIDE_PAGE_1 },
    { "ngc_awl_profiles_flak", 53, FOMT_REFERENCE_GUIDE_PAGE_1 },
    { "ngc_awl_profiles_player", 54, FOMT_REFERENCE_GUIDE_PAGE_1 },
    { "cookbook_1", 55, FOMT_REFERENCE_GUIDE_PAGE_1 },
    { "cookbook_2", 56, FOMT_REFERENCE_GUIDE_PAGE_1 },
    { "cookbook_3", 57, FOMT_REFERENCE_GUIDE_PAGE_1 },
    { "cookbook_4", 58, FOMT_REFERENCE_GUIDE_PAGE_1 },
    { "acquiring_kitchen", 59, FOMT_REFERENCE_GUIDE_PAGE_1 },
    { "harvest_sprite_help", 60, FOMT_REFERENCE_GUIDE_PAGE_1 },
    { "saibara_blacksmith", 61, FOMT_REFERENCE_GUIDE_PAGE_1 },
    { "supermarket", 62, FOMT_REFERENCE_GUIDE_PAGE_1 },
    { "woodcutters_house", 63, FOMT_REFERENCE_GUIDE_PAGE_1 },
    { "clinic", 64, FOMT_REFERENCE_GUIDE_PAGE_1 },
    { "aja_winery", 65, FOMT_REFERENCE_GUIDE_PAGE_1 },
    { "dougs_inn", 66, FOMT_REFERENCE_GUIDE_PAGE_1 },
    { "kai_seaside_lodge", 67, FOMT_REFERENCE_GUIDE_PAGE_1 },
    { "poultry_farm", 68, FOMT_REFERENCE_GUIDE_PAGE_1 },
    { "yodel_farm", 69, FOMT_REFERENCE_GUIDE_PAGE_1 },
    { "wons_shop", 70, FOMT_REFERENCE_GUIDE_PAGE_1 },
    { "vans_shop", 71, FOMT_REFERENCE_GUIDE_PAGE_1 },
    { "record_player_instructions", 72, FOMT_REFERENCE_GUIDE_PAGE_1 },
    { "bath_instructions", 73, FOMT_REFERENCE_GUIDE_PAGE_1 },
    { "vase_instructions", 74, FOMT_REFERENCE_GUIDE_PAGE_1 },
    { "refrigerator", 75, FOMT_REFERENCE_GUIDE_PAGE_1 },
    { "shelf", 76, FOMT_REFERENCE_GUIDE_PAGE_1 },
    { "new_year_card_cliff_first", 79, FOMT_REFERENCE_GUIDE_PAGE_1 },
    { "new_year_card_cliff_second", 80, FOMT_REFERENCE_GUIDE_PAGE_1 },
    { "new_year_card_cliff_and_ann", 81, FOMT_REFERENCE_GUIDE_PAGE_1 },
    { "new_year_card_doctor", 82, FOMT_REFERENCE_GUIDE_PAGE_1 },
    { "new_year_card_doctor_and_elli", 83, FOMT_REFERENCE_GUIDE_PAGE_1 },
    { "new_year_card_mineral_clinic", 84, FOMT_REFERENCE_GUIDE_PAGE_1 },
    { "new_year_card_poultry_farm", 85, FOMT_REFERENCE_GUIDE_PAGE_1 },
    { "new_year_card_poultry_farm_lillia_and_rick", 86, FOMT_REFERENCE_GUIDE_PAGE_1 },
    { "new_year_card_poultry_farm_player_and_popuri", 87, FOMT_REFERENCE_GUIDE_PAGE_1 },
    { "new_year_card_poultry_farm_lillia_rick_and_karen", 88, FOMT_REFERENCE_GUIDE_PAGE_1 },
    { "new_year_card_gray", 89, FOMT_REFERENCE_GUIDE_PAGE_1 },
    { "new_year_card_gray_well_wishes", 90, FOMT_REFERENCE_GUIDE_PAGE_1 },
    { "new_year_card_kai", 91, FOMT_REFERENCE_GUIDE_PAGE_1 },
    { "new_year_card_kai_and_popuri", 92, FOMT_REFERENCE_GUIDE_PAGE_1 },
    { "new_year_card_jeff", 93, FOMT_REFERENCE_GUIDE_PAGE_1 },
    { "new_year_card_saibara", 94, FOMT_REFERENCE_GUIDE_PAGE_1 },
    { "new_year_card_doug", 95, FOMT_REFERENCE_GUIDE_PAGE_1 },
    { "new_year_card_doug_to_player_and_ann", 96, FOMT_REFERENCE_GUIDE_PAGE_1 },
    { "new_year_card_carter", 97, FOMT_REFERENCE_GUIDE_PAGE_1 },
    { "new_year_card_basil_and_anna", 98, FOMT_REFERENCE_GUIDE_PAGE_1 },
    { "new_year_cards_may_and_barley", 99, FOMT_REFERENCE_GUIDE_PAGE_1 },
    { "new_year_card_thomas_and_harris", 100, FOMT_REFERENCE_GUIDE_PAGE_1 },
    { "new_year_card_thomas_and_harris_town_safety", 101, FOMT_REFERENCE_GUIDE_PAGE_1 },
    { "new_year_cards_manna_and_duke", 102, FOMT_REFERENCE_GUIDE_PAGE_1 },
    { "new_year_card_ellen", 103, FOMT_REFERENCE_GUIDE_PAGE_1 },
    { "new_year_card_harvest_sprites", 104, FOMT_REFERENCE_GUIDE_PAGE_1 },
    { "new_year_card_popuri", 105, FOMT_REFERENCE_GUIDE_PAGE_1 },
    { "new_year_card_ann", 106, FOMT_REFERENCE_GUIDE_PAGE_1 },
    { "new_year_card_karen", 107, FOMT_REFERENCE_GUIDE_PAGE_1 },
    { "new_year_card_elli", 108, FOMT_REFERENCE_GUIDE_PAGE_1 },
    { "new_year_card_mary", 109, FOMT_REFERENCE_GUIDE_PAGE_1 },
    { "notice_dougs_inn_store_hours_change", 110, FOMT_REFERENCE_GUIDE_PAGE_1 },
    { "birthday_card_popuri", 111, FOMT_REFERENCE_GUIDE_PAGE_1 },
    { "birthday_card_ann", 112, FOMT_REFERENCE_GUIDE_PAGE_1 },
    { "birthday_card_karen", 113, FOMT_REFERENCE_GUIDE_PAGE_1 },
    { "birthday_card_elli", 114, FOMT_REFERENCE_GUIDE_PAGE_1 },
    { "birthday_card_mary", 115, FOMT_REFERENCE_GUIDE_PAGE_1 },
    { "birthday_card_kai", 116, FOMT_REFERENCE_GUIDE_PAGE_1 },
    { "birthday_card_cliff", 117, FOMT_REFERENCE_GUIDE_PAGE_1 },
    { "birthday_card_doctor", 118, FOMT_REFERENCE_GUIDE_PAGE_1 },
    { "newborn_congratulations_kai_and_popuri", 119, FOMT_REFERENCE_GUIDE_PAGE_1 },
    { "newborn_congratulations_cliff_and_ann_1", 120, FOMT_REFERENCE_GUIDE_PAGE_1 },
#if defined(REGION_DE)
    { "newborn_congratulations_cliff_and_ann_2", 120, FOMT_REFERENCE_GUIDE_PAGE_2 },
#endif
    { "newborn_congratulations_rick_and_karen", 121, FOMT_REFERENCE_GUIDE_PAGE_1 },
    { "newborn_congratulations_doctor_and_elli", 122, FOMT_REFERENCE_GUIDE_PAGE_1 },
    { "newborn_congratulations_mary_and_gray", 123, FOMT_REFERENCE_GUIDE_PAGE_1 },
    { "newborn_congratulations_thomas_and_harris", 124, FOMT_REFERENCE_GUIDE_PAGE_1 },
    { "new_stock_supermarket_strawberry_seeds", 125, FOMT_REFERENCE_GUIDE_PAGE_1 },
    { "new_stock_supermarket_pumpkin_seeds", 126, FOMT_REFERENCE_GUIDE_PAGE_1 },
    { "new_stock_supermarket_spinach_seeds", 127, FOMT_REFERENCE_GUIDE_PAGE_1 },
    { "new_stock_supermarket_blue_feather", 128, FOMT_REFERENCE_GUIDE_PAGE_1 },
    { "new_stock_supermarket_large_rucksack", 129, FOMT_REFERENCE_GUIDE_PAGE_1 },
    { "new_stock_mineral_clinic_bodigizer_xl", 130, FOMT_REFERENCE_GUIDE_PAGE_1 },
    { "new_stock_mineral_clinic_turbojolt_xl", 131, FOMT_REFERENCE_GUIDE_PAGE_1 },
    { "new_stock_saibara_blacksmith_brush", 132, FOMT_REFERENCE_GUIDE_PAGE_1 },
    { "new_stock_saibara_blacksmith_milker", 133, FOMT_REFERENCE_GUIDE_PAGE_1 },
    { "new_stock_saibara_blacksmith_clippers", 134, FOMT_REFERENCE_GUIDE_PAGE_1 },
    { "notice_marys_library_day_off_change", 135, FOMT_REFERENCE_GUIDE_PAGE_1 },
    { "invitation_harvest_sprites_tea_party", 136, FOMT_REFERENCE_GUIDE_PAGE_1 },
    { "staff_credits", 77, FOMT_REFERENCE_GUIDE_PAGE_1 },
    { "useful_controls", 78, FOMT_REFERENCE_GUIDE_PAGE_1 },
};
