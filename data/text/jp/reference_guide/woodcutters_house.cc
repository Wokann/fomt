#include "reference_guide.hh"

// Reference Guide page 63: Woodcutter's House. Fixed field capacities and
// physical order match the Japanese ROM.

char const gText_ReferenceGuide_WoodcuttersHouse_Title[32] SECTION(".rodata.reference_guide_woodcutters_house_text") =
    "木こりの家　　　　　　　　　";
char const gText_ReferenceGuide_WoodcuttersHouse_Overview_Line01[32] SECTION(".rodata.reference_guide_woodcutters_house_text") =
    "·資材が買える他に、増築をし";
char const gText_ReferenceGuide_WoodcuttersHouse_Overview_Line02[20] SECTION(".rodata.reference_guide_woodcutters_house_text") =
    "　てもらえるお店。";
char const gText_ReferenceGuide_WoodcuttersHouse_StoreHours_Value[24] SECTION(".rodata.reference_guide_woodcutters_house_text") =
    "　午前１１時～午後４時";
char const gText_ReferenceGuide_WoodcuttersHouse_ClosedDay_Value[12] SECTION(".rodata.reference_guide_woodcutters_house_text") =
    "　土曜日";

char const gText_ReferenceGuide_WoodcuttersHouse_Lumber_Title[8] SECTION(".rodata.reference_guide_woodcutters_house_text") =
    "☆資材";
char const gText_ReferenceGuide_WoodcuttersHouse_Lumber_Requirements_Line01[32] SECTION(".rodata.reference_guide_woodcutters_house_text") =
    "·増築してもらうには、お金の";
char const gText_ReferenceGuide_WoodcuttersHouse_Lumber_Requirements_Line02[20] SECTION(".rodata.reference_guide_woodcutters_house_text") =
    "　他にこれが必要。";
char const gText_ReferenceGuide_WoodcuttersHouse_Lumber_Requirements_Line03[32] SECTION(".rodata.reference_guide_woodcutters_house_text") =
    "　必要な資材数は増築の種類に";
char const gText_ReferenceGuide_WoodcuttersHouse_Lumber_Requirements_Line04[20] SECTION(".rodata.reference_guide_woodcutters_house_text") =
    "　よって変わる。";
char const gText_ReferenceGuide_WoodcuttersHouse_Lumber_Delivery_Line01[32] SECTION(".rodata.reference_guide_woodcutters_house_text") =
    "·買ったら直接『資材置き場』";
char const gText_ReferenceGuide_WoodcuttersHouse_Lumber_Delivery_Line02[16] SECTION(".rodata.reference_guide_woodcutters_house_text") =
    "　に送られる。";
char const gText_ReferenceGuide_WoodcuttersHouse_Lumber_Acquisition_Line01[32] SECTION(".rodata.reference_guide_woodcutters_house_text") =
    "ちなみに資材はここで買う以外";
char const gText_ReferenceGuide_WoodcuttersHouse_Lumber_Acquisition_Line02[32] SECTION(".rodata.reference_guide_woodcutters_house_text") =
    "にも、オノで枝や切り株を壊す";
char const gText_ReferenceGuide_WoodcuttersHouse_Lumber_Acquisition_Line03[20] SECTION(".rodata.reference_guide_woodcutters_house_text") =
    "ことで手に入る。";

char const gText_ReferenceGuide_WoodcuttersHouse_Expansions_Title[12] SECTION(".rodata.reference_guide_woodcutters_house_text") =
    "☆増築関係";
char const gText_ReferenceGuide_WoodcuttersHouse_Expansions_Description_Line01[32] SECTION(".rodata.reference_guide_woodcutters_house_text") =
    "·どの場合でも頼むと、次の日";
char const gText_ReferenceGuide_WoodcuttersHouse_Expansions_Description_Line02[24] SECTION(".rodata.reference_guide_woodcutters_house_text") =
    "　から作業を開始する。";
char const gText_ReferenceGuide_WoodcuttersHouse_Expansions_Description_Line03[32] SECTION(".rodata.reference_guide_woodcutters_house_text") =
    "　もちろん増築作業中はゴッツ";
char const gText_ReferenceGuide_WoodcuttersHouse_Expansions_Description_Line04[32] SECTION(".rodata.reference_guide_woodcutters_house_text") =
    "　さんから買い物はできなくな";
char const gText_ReferenceGuide_WoodcuttersHouse_Expansions_Description_Line05[28] SECTION(".rodata.reference_guide_woodcutters_house_text") =
    "　るし、増築も頼めない。";

char const gText_ReferenceGuide_WoodcuttersHouse_HomeExpansion_Title[20] SECTION(".rodata.reference_guide_woodcutters_house_text") =
    "☆自宅を増築する";
char const gText_ReferenceGuide_WoodcuttersHouse_HomeExpansion_Description_Line01[28] SECTION(".rodata.reference_guide_woodcutters_house_text") =
    "·増築しないと設置できない";
char const gText_ReferenceGuide_WoodcuttersHouse_HomeExpansion_Description_Line02[32] SECTION(".rodata.reference_guide_woodcutters_house_text") =
    "　家具もある。（冷蔵庫など）";
char const gText_ReferenceGuide_WoodcuttersHouse_HomeExpansion_SecondFloor_Line01[28] SECTION(".rodata.reference_guide_woodcutters_house_text") =
    "·２段階まで増築できる。";
char const gText_ReferenceGuide_WoodcuttersHouse_HomeExpansion_Rebuild_Line01[32] SECTION(".rodata.reference_guide_woodcutters_house_text") =
    "·ちなみに自宅を２回増築した";
char const gText_ReferenceGuide_WoodcuttersHouse_HomeExpansion_Rebuild_Line02[32] SECTION(".rodata.reference_guide_woodcutters_house_text") =
    "　後は「自宅の窓」「犬小屋」";
char const gText_ReferenceGuide_WoodcuttersHouse_HomeExpansion_Rebuild_Line03[32] SECTION(".rodata.reference_guide_woodcutters_house_text") =
    "　「ポスト」の建て替えができ";
char const gText_ReferenceGuide_WoodcuttersHouse_HomeExpansion_Rebuild_Line04[20] SECTION(".rodata.reference_guide_woodcutters_house_text") =
    "　るようになる。";

char const gText_ReferenceGuide_WoodcuttersHouse_ChickenCoopExpansion_Title[20] SECTION(".rodata.reference_guide_woodcutters_house_text") =
    "☆鶏小屋を増築する";
char const gText_ReferenceGuide_WoodcuttersHouse_ChickenCoopExpansion_Capacity_Line01[32] SECTION(".rodata.reference_guide_woodcutters_house_text") =
    "·鶏の飼える数が４羽→８羽に";
char const gText_ReferenceGuide_WoodcuttersHouse_ChickenCoopExpansion_Capacity_Line02[12] SECTION(".rodata.reference_guide_woodcutters_house_text") =
    "　なる。";
char const gText_ReferenceGuide_WoodcuttersHouse_ChickenCoopExpansion_Incubators_Line01[28] SECTION(".rodata.reference_guide_woodcutters_house_text") =
    "·ふか箱も２個に増える。";
char const gText_ReferenceGuide_WoodcuttersHouse_ChickenCoopExpansion_MayonnaiseMaker_Line01[32] SECTION(".rodata.reference_guide_woodcutters_house_text") =
    "·『マヨネーズメーカー』が設";
char const gText_ReferenceGuide_WoodcuttersHouse_ChickenCoopExpansion_MayonnaiseMaker_Line02[24] SECTION(".rodata.reference_guide_woodcutters_house_text") =
    "　置できるようになる。";

char const gText_ReferenceGuide_WoodcuttersHouse_BarnExpansion_Title[24] SECTION(".rodata.reference_guide_woodcutters_house_text") =
    "☆動物小屋を増築する";
char const gText_ReferenceGuide_WoodcuttersHouse_BarnExpansion_Capacity_Line01[32] SECTION(".rodata.reference_guide_woodcutters_house_text") =
    "·牛、羊の飼える合計数が８頭";
char const gText_ReferenceGuide_WoodcuttersHouse_BarnExpansion_Capacity_Line02[20] SECTION(".rodata.reference_guide_woodcutters_house_text") =
    "　→１６頭になる。";
char const gText_ReferenceGuide_WoodcuttersHouse_BarnExpansion_PregnancySpace_Line01[32] SECTION(".rodata.reference_guide_woodcutters_house_text") =
    "·妊娠用のスペースも２個に増";
char const gText_ReferenceGuide_WoodcuttersHouse_BarnExpansion_Makers_Line01[24] SECTION(".rodata.reference_guide_woodcutters_house_text") =
    "·『チーズメーカー』";
char const gText_ReferenceGuide_WoodcuttersHouse_BarnExpansion_Makers_Line02[32] SECTION(".rodata.reference_guide_woodcutters_house_text") =
    "　『毛糸玉メーカー』が設置で";
char const gText_ReferenceGuide_WoodcuttersHouse_BarnExpansion_Makers_Line03[20] SECTION(".rodata.reference_guide_woodcutters_house_text") =
    "　きるようになる。";

char const gText_ReferenceGuide_WoodcuttersHouse_Cottage_Title[16] SECTION(".rodata.reference_guide_woodcutters_house_text") =
    "☆別荘を建てる";
char const gText_ReferenceGuide_WoodcuttersHouse_Cottage_Description_Line01[28] SECTION(".rodata.reference_guide_woodcutters_house_text") =
    "·街の中に別荘を建てる。";
