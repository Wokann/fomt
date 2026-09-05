#include "reference_guide.hh"

// Reference Guide page 64: Mineral Town Clinic. Fixed field capacities and
// physical order match the Japanese ROM.

char const gText_ReferenceGuide_Clinic_Title[32] SECTION(".rodata.reference_guide_clinic_text") =
    "ミネラル医院　　　　　　　　";
char const gText_ReferenceGuide_Clinic_Overview_Medicine_Line01[32] SECTION(".rodata.reference_guide_clinic_text") =
    "·エリィさんに話しかけると薬";
char const gText_ReferenceGuide_Clinic_Overview_Medicine_Line02[16] SECTION(".rodata.reference_guide_clinic_text") =
    "　が買える。";
char const gText_ReferenceGuide_Clinic_Overview_Examination_Line01[32] SECTION(".rodata.reference_guide_clinic_text") =
    "　ドクターに話しかけると診察";
char const gText_ReferenceGuide_Clinic_Overview_Examination_Line02[20] SECTION(".rodata.reference_guide_clinic_text") =
    "　をしてくれる。";
char const gText_ReferenceGuide_Clinic_Overview_Collapse_Line01[32] SECTION(".rodata.reference_guide_clinic_text") =
    "　他に疲労がまんたんになって";
char const gText_ReferenceGuide_Clinic_Overview_Collapse_Line02[32] SECTION(".rodata.reference_guide_clinic_text") =
    "　倒れたときはここに連れてこ";
char const gText_ReferenceGuide_Clinic_Overview_Collapse_Line03[12] SECTION(".rodata.reference_guide_clinic_text") =
    "　られる。";
char const gText_ReferenceGuide_Clinic_StoreHours_Value[24] SECTION(".rodata.reference_guide_clinic_text") =
    "　午前９時～午後４時";
char const gText_ReferenceGuide_Clinic_ClosedDay_Value[12] SECTION(".rodata.reference_guide_clinic_text") =
    "　水曜日";

char const gText_ReferenceGuide_Clinic_StaminaMedicine_Title[16] SECTION(".rodata.reference_guide_clinic_text") =
    "☆ちからでーる";
char const gText_ReferenceGuide_Clinic_StaminaMedicine_Description_Line01[24] SECTION(".rodata.reference_guide_clinic_text") =
    "·体力が回復する薬。";
char const gText_ReferenceGuide_Clinic_FatigueMedicine_Title[16] SECTION(".rodata.reference_guide_clinic_text") =
    "☆つかれとーる";
char const gText_ReferenceGuide_Clinic_FatigueMedicine_Description_Line01[24] SECTION(".rodata.reference_guide_clinic_text") =
    "·疲労が回復する薬。";
char const gText_ReferenceGuide_Clinic_StrongerMedicine_Line01[32] SECTION(".rodata.reference_guide_clinic_text") =
    "·薬の材料になる草を出荷し続";
char const gText_ReferenceGuide_Clinic_StrongerMedicine_Line02[32] SECTION(".rodata.reference_guide_clinic_text") =
    "　けるとさらに強力な薬が売ら";
char const gText_ReferenceGuide_Clinic_StrongerMedicine_Line03[20] SECTION(".rodata.reference_guide_clinic_text") =
    "　れるようになる。";
char const gText_ReferenceGuide_Clinic_Examination_Title[8] SECTION(".rodata.reference_guide_clinic_text") =
    "☆診察";
char const gText_ReferenceGuide_Clinic_Examination_Description_Line01[32] SECTION(".rodata.reference_guide_clinic_text") =
    "·現在の体力と疲労がどれくら";
char const gText_ReferenceGuide_Clinic_Examination_Description_Line02[28] SECTION(".rodata.reference_guide_clinic_text") =
    "　いなのかを教えてくれる。";
