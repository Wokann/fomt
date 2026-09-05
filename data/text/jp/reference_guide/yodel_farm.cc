#include "reference_guide.hh"

// Reference Guide page 69: Yodel Farm. Fixed field capacities and physical
// order match the Japanese ROM.

char const gText_ReferenceGuide_YodelFarm_Title[32] SECTION(".rodata.reference_guide_yodel_farm_text") =
    "ヨーデル牧場　　　　　　　　";
char const gText_ReferenceGuide_YodelFarm_Overview_Line01[32] SECTION(".rodata.reference_guide_yodel_farm_text") =
    "·牛、羊関係の物を買えるお店";
char const gText_ReferenceGuide_YodelFarm_Overview_Line02[32] SECTION(".rodata.reference_guide_yodel_farm_text") =
    "　で、牛、羊を売ることもでき";
char const gText_ReferenceGuide_YodelFarm_StoreHours_Value[24] SECTION(".rodata.reference_guide_yodel_farm_text") =
    "　午前１０時～午後３時";
char const gText_ReferenceGuide_YodelFarm_ClosedDay_Value[12] SECTION(".rodata.reference_guide_yodel_farm_text") =
    "　月曜日";

char const gText_ReferenceGuide_YodelFarm_Fodder_Title[12] SECTION(".rodata.reference_guide_yodel_farm_text") =
    "☆飼い葉";
char const gText_ReferenceGuide_YodelFarm_Fodder_Description_Line01[32] SECTION(".rodata.reference_guide_yodel_farm_text") =
    "·買ったら直接『サイロ』に送";
char const gText_ReferenceGuide_YodelFarm_Fodder_Alternative_Line01[32] SECTION(".rodata.reference_guide_yodel_farm_text") =
    "ちなみに飼い葉はここで買う以";
char const gText_ReferenceGuide_YodelFarm_Fodder_Alternative_Line02[32] SECTION(".rodata.reference_guide_yodel_farm_text") =
    "外にも、牧草を刈ることでも手";
char const gText_ReferenceGuide_YodelFarm_Fodder_Alternative_Line03[12] SECTION(".rodata.reference_guide_yodel_farm_text") =
    "に入る。";

char const gText_ReferenceGuide_YodelFarm_LivestockPurchases_Cow_Title[12] SECTION(".rodata.reference_guide_yodel_farm_text") =
    "☆牛を買う";
char const gText_ReferenceGuide_YodelFarm_LivestockPurchases_Sheep_Title[12] SECTION(".rodata.reference_guide_yodel_farm_text") =
    "☆羊を買う";
char const gText_ReferenceGuide_YodelFarm_LivestockPurchases_Delivery_Line01[32] SECTION(".rodata.reference_guide_yodel_farm_text") =
    "·どっちを買っても直接『動物";
char const gText_ReferenceGuide_YodelFarm_LivestockPurchases_Delivery_Line02[24] SECTION(".rodata.reference_guide_yodel_farm_text") =
    "　小屋』に送られる。";
char const gText_ReferenceGuide_YodelFarm_LivestockPurchases_Quantity_Line01[28] SECTION(".rodata.reference_guide_yodel_farm_text") =
    "　同じ数じゃなくてもいい。";
char const gText_ReferenceGuide_YodelFarm_LivestockPurchases_Quantity_Line02[32] SECTION(".rodata.reference_guide_yodel_farm_text") =
    "　牛のみ、とかでもおっけー。";

char const gText_ReferenceGuide_YodelFarm_CowMiraclePotion_Title[12] SECTION(".rodata.reference_guide_yodel_farm_text") =
    "☆牛のタネ";
char const gText_ReferenceGuide_YodelFarm_CowMiraclePotion_Description_Line01[28] SECTION(".rodata.reference_guide_yodel_farm_text") =
    "·大牛に使うと妊娠する。";
char const gText_ReferenceGuide_YodelFarm_SheepMiraclePotion_Title[12] SECTION(".rodata.reference_guide_yodel_farm_text") =
    "☆羊のタネ";
char const gText_ReferenceGuide_YodelFarm_SheepMiraclePotion_Description_Line01[28] SECTION(".rodata.reference_guide_yodel_farm_text") =
    "·大羊に使うと妊娠する。";
char const gText_ReferenceGuide_YodelFarm_AnimalMedicine_Description_Line02[28] SECTION(".rodata.reference_guide_yodel_farm_text") =
    "　戻せる。鶏にも使える。";

char const gText_ReferenceGuide_YodelFarm_Bell_Title[8] SECTION(".rodata.reference_guide_yodel_farm_text") =
    "☆ベル";
char const gText_ReferenceGuide_YodelFarm_ToolClassification_Line01[32] SECTION(".rodata.reference_guide_yodel_farm_text") =
    "ちなみに、牛のタネ、羊のタネ";
char const gText_ReferenceGuide_YodelFarm_ToolClassification_Line02[32] SECTION(".rodata.reference_guide_yodel_farm_text") =
    "動物の薬、ベルは全部、装備に";
char const gText_ReferenceGuide_YodelFarm_ToolClassification_Line03[12] SECTION(".rodata.reference_guide_yodel_farm_text") =
    "入る道具。";

char const gText_ReferenceGuide_YodelFarm_CowSell_Title[12] SECTION(".rodata.reference_guide_yodel_farm_text") =
    "☆牛を売る";
char const gText_ReferenceGuide_YodelFarm_SheepSell_Title[12] SECTION(".rodata.reference_guide_yodel_farm_text") =
    "☆羊を売る";
char const gText_ReferenceGuide_YodelFarm_LivestockSell_Description_Line01[32] SECTION(".rodata.reference_guide_yodel_farm_text") =
    "·売値は、牛なら牛乳の質が、";
char const gText_ReferenceGuide_YodelFarm_LivestockSell_Description_Line02[32] SECTION(".rodata.reference_guide_yodel_farm_text") =
    "　羊なら羊毛の質が高い物ほど";
char const gText_ReferenceGuide_YodelFarm_LivestockSell_Description_Line03[28] SECTION(".rodata.reference_guide_yodel_farm_text") =
    "　高くで売ることができる。";
